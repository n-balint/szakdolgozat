use std::{
    collections::{BTreeSet, HashMap, HashSet},
    fmt::write,
    fs::File,
    ops::{Index, IndexMut},
    path::PathBuf,
};

use csv::{Reader, ReaderBuilder};
use itertools::Itertools;
use ndarray::Array2;

use crate::{
    cassandra::database::Keyspace,
    postgres::database::{ColumnDefinition, ForeignKey, Schema, Table},
};

#[derive(Debug, Clone, Copy, Eq, PartialEq)]
enum DependencyKind {
    Trivial,
    Pruned,
    Yes,
    No,
}

impl std::fmt::Display for DependencyKind {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let c = match self {
            DependencyKind::Trivial => "T",
            DependencyKind::Pruned => "P",
            DependencyKind::Yes => "Y",
            DependencyKind::No => "N",
        };
        write!(f, "{}", c)
    }
}

#[derive(Debug, Clone)]
struct DependencyMatrix {
    lut: HashMap<BTreeSet<usize>, usize>,
    matrix: Array2<Option<DependencyKind>>,
}

impl Index<(BTreeSet<usize>, usize)> for DependencyMatrix {
    type Output = Option<DependencyKind>;

    fn index(&self, index: (BTreeSet<usize>, usize)) -> &Self::Output {
        let (row, col) = (self.lut[&index.0], index.1);
        &self.matrix[[row, col]]
    }
}

impl IndexMut<(BTreeSet<usize>, usize)> for DependencyMatrix {
    fn index_mut(&mut self, index: (BTreeSet<usize>, usize)) -> &mut Self::Output {
        let (row, col) = (self.lut[&index.0], index.1);
        &mut self.matrix[[row, col]]
    }
}

impl DependencyMatrix {
    fn new(attribute_count: usize) -> Self {
        let matrix = Array2::from_elem((1 << attribute_count, attribute_count), None);
        let mut lut = HashMap::new();

        let indeces = (0..attribute_count).collect();
        for (row, subset) in SubsetIterator::new(indeces).enumerate() {
            lut.insert(subset, row);
        }
        Self { lut, matrix }
    }

    fn set_dependency(&mut self, lhs: &BTreeSet<usize>, rhs: usize, value: DependencyKind) {
        let row = self.lut[lhs];
        self.matrix[[row, rhs]] = Some(value);
    }

    fn dependency(&self, lhs: &BTreeSet<usize>, rhs: usize) -> Option<DependencyKind> {
        let row = self.lut[lhs];
        self.matrix[[row, rhs]]
    }

    /// Splits the old matrix into two matrices where the left one has the `remove` fields removed
    /// and the right has fields `remove` + `add_to_new`. DependencyKind::Yes and
    /// DependencyKind::No and DependencyKind::Trivial are the only moved values.
    fn split(&self, remove: &[usize], add_to_new: &[usize]) -> (Self, Self) {
        println!("TO REMOVE: {:#?}", remove);
        println!("TO ADD TO NEW: {:#?}", add_to_new);
        let original_attribute_count = self.matrix.shape()[1];
        println!("original attribute count: {}", original_attribute_count);
        let trimmed_attribute_count = original_attribute_count - remove.len();
        println!("trimmed attribute count: {}", trimmed_attribute_count);
        let new_attribute_count = remove.len() + add_to_new.len();
        println!("new attribute count: {}", new_attribute_count);

        let trimmed_columns = (0..original_attribute_count)
            .filter(|c| !remove.contains(c))
            .collect::<Vec<_>>();
        println!("trimmed columns: {:#?}", trimmed_columns);

        let mut new_columns = Vec::with_capacity(new_attribute_count);
        new_columns.extend_from_slice(add_to_new);
        new_columns.extend_from_slice(remove);

        println!("new columns: {:#?}", new_columns);

        let mut trimmed_matrix = DependencyMatrix::new(trimmed_attribute_count);
        let mut new_matrix = DependencyMatrix::new(new_attribute_count);

        for (original_subset, &original_row) in self.lut.iter() {
            let trimmed_subset = original_subset
                .iter()
                .filter_map(|&attribute| {
                    trimmed_columns
                        .iter()
                        .position(|&column| column == attribute)
                })
                .collect::<BTreeSet<_>>();

            let new_subset = original_subset
                .iter()
                .filter_map(|&attribute| new_columns.iter().position(|&column| column == attribute))
                .collect::<BTreeSet<_>>();
            if trimmed_subset.is_empty() || new_subset.is_empty() {
                continue;
            }
            let trimmed_row = trimmed_matrix.lut[&trimmed_subset];
            let new_row = new_matrix.lut[&new_subset];

            for (new_column, &original_column) in trimmed_columns.iter().enumerate() {
                if let Some(dependency) = self.matrix[[original_row, original_column]] {
                    match dependency {
                        DependencyKind::Yes | DependencyKind::No | DependencyKind::Trivial => {
                            trimmed_matrix.matrix[[trimmed_row, new_column]] = Some(dependency);
                        }
                        _ => {}
                    }
                }
            }

            for (new_column, &original_column) in new_columns.iter().enumerate() {
                if let Some(dependency) = self.matrix[[original_row, original_column]] {
                    match dependency {
                        DependencyKind::Yes | DependencyKind::No | DependencyKind::Trivial => {
                            new_matrix.matrix[[new_row, new_column]] = Some(dependency);
                        }
                        _ => {}
                    }
                }
            }
        }
        trimmed_matrix.print_dependencies();
        new_matrix.print_dependencies();
        (trimmed_matrix, new_matrix)
    }

    fn print_dependencies(&self) {
        let mut subsets = self.lut.iter().collect::<Vec<_>>();
        subsets.sort_by_key(|&(_, row)| *row);
        for (subset, &row) in subsets.iter() {
            for col in 0..self.matrix.shape()[1] {
                if let Some(DependencyKind::Yes) = self.matrix[[row, col]] {
                    let subset_string = subset
                        .iter()
                        .map(ToString::to_string)
                        .collect::<Vec<_>>()
                        .join(",");

                    println!("{{{}}} -> {}", subset_string, col);
                }
            }
        }
    }
}

impl std::fmt::Display for DependencyMatrix {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let mut subsets = self.lut.iter().collect::<Vec<_>>();
        subsets.sort_by_key(|&(_, row)| *row);
        write!(f, "     ")?;

        for col in 0..self.matrix.shape()[1] {
            write!(f, "{:^3}", col)?;
        }
        writeln!(f)?;

        for (subset, &row) in subsets.iter() {
            let subset_string = subset
                .iter()
                .map(|x| x.to_string())
                .collect::<Vec<_>>()
                .join(",");
            write!(f, "{{{:^3}}}", subset_string)?;

            for col in 0..self.matrix.shape()[1] {
                let cell = match self.matrix[[row, col]] {
                    Some(DependencyKind::Yes) => " Y ",
                    Some(DependencyKind::No) => " N ",
                    Some(DependencyKind::Pruned) => " P ",
                    Some(DependencyKind::Trivial) => " T ",
                    None => " X ",
                };
                write!(f, "{:^3}", cell)?;
            }
            writeln!(f)?;
        }

        Ok(())
    }
}

#[derive(Debug, Clone)]
pub struct SubsetIterator {
    data: Vec<usize>,
    current_size: usize,
    current_indeces: Vec<usize>,
}

impl SubsetIterator {
    pub fn new(data: Vec<usize>) -> Self {
        Self {
            data,
            current_size: 0,
            current_indeces: Vec::new(),
        }
    }

    fn initialize_indeces(&mut self, size: usize) {
        self.current_indeces = (0..size).collect();
    }

    fn increment_indeces(&mut self) -> bool {
        let n = self.data.len();
        let k = self.current_indeces.len();

        for i in (0..k).rev() {
            if self.current_indeces[i] != i + n - k {
                self.current_indeces[i] += 1;
                for j in i + 1..k {
                    self.current_indeces[j] = self.current_indeces[j - 1] + 1;
                }
                return true;
            }
        }
        false
    }
}

impl Iterator for SubsetIterator {
    type Item = BTreeSet<usize>;

    fn next(&mut self) -> Option<Self::Item> {
        if self.current_size > self.data.len() {
            return None;
        }
        if self.current_indeces.is_empty() && self.current_size == 0 {
            self.current_size = 1;
            self.initialize_indeces(1);
        }
        if self.current_indeces.is_empty() {
            self.initialize_indeces(self.current_size);
        }

        let subset = self
            .current_indeces
            .iter()
            .map(|&x| self.data[x])
            .collect::<BTreeSet<_>>();

        if !self.increment_indeces() {
            self.current_size += 1;
            self.current_indeces.clear();
        }

        Some(subset)
    }
}

#[derive(Debug, Clone)]
pub struct DependencyInference {
    schema: Schema,
    fds: HashMap<String, DependencyMatrix>,
    folder: PathBuf,
}

impl DependencyInference {
    pub(crate) fn move_schema(self) -> Schema {
        self.schema
    }
    pub(crate) fn new(schema: Schema, folder: PathBuf) -> Self {
        let mut fds = HashMap::new();
        for table in schema.tables().iter() {
            let matrix = DependencyMatrix::new(table.columns().len());
            fds.insert(table.name().to_string(), matrix);
        }
        Self {
            schema,
            fds,
            folder,
        }
    }

    pub(crate) fn verify_and_set_primary_keys(&mut self) {
        let mut tables_with_invalid_keys = HashMap::new();
        for (table_name, _) in self.fds.iter() {
            let table = self
                .schema
                .tables()
                .iter()
                .find(|table| table.name() == table_name)
                .expect("Logic_error");

            let primary_keys = table.primary_keys();
            let primary_key_indeces = primary_keys
                .iter()
                .map(|column_name| {
                    table
                        .columns()
                        .iter()
                        .position(|column| column.name() == column_name)
                        .expect("Logic error.")
                })
                .collect::<BTreeSet<_>>();
            let candidate_keys = self.find_candidate_keys(table_name);
            let mut is_valid_key = false;
            for candidate_key in candidate_keys.iter() {
                if candidate_key == &primary_key_indeces {
                    is_valid_key = true;
                }
            }
            if !is_valid_key {
                tables_with_invalid_keys.insert(table_name, candidate_keys[0].clone());
            }
        }
        for (table_name, key_indeces) in tables_with_invalid_keys {
            let table = self
                .schema
                .tables_mut()
                .iter_mut()
                .find(|table| table.name() == table_name)
                .expect("Logic error.");

            table.primary_keys_mut().drain(..);
            for i in key_indeces {
                table.add_primary_key(table.columns()[i].name().to_string());
            }
        }
    }

    fn decompose(
        &mut self,
        decomposition_data: &HashMap<String, HashMap<BTreeSet<usize>, BTreeSet<usize>>>,
    ) -> Result<(), anyhow::Error> {
        println!("entering decompose with: {:#?}", decomposition_data);
        for (table_name, conflict) in decomposition_data.iter() {
            let all_removed = conflict
                .iter()
                .flat_map(|(_, rhs)| rhs)
                .copied()
                .collect::<Vec<_>>();

            let original_table = self
                .schema
                .tables_mut()
                .iter_mut()
                .find(|table| table.name() == table_name)
                .expect("Logic error");

            let table_clone = original_table.clone();

            let dependency_matrix = &self.fds[table_name].clone();
            let primary_key = table_clone
                .primary_keys()
                .iter()
                .map(|key| {
                    table_clone
                        .columns()
                        .iter()
                        .position(|column| column.name() == key)
                        .expect("Logic error.")
                })
                .collect::<BTreeSet<_>>();

            let (trimmed_matrix, _) = dependency_matrix.split(&all_removed, &[]);
            let mut trimmed_table = table_clone.clone();
            let updated_columns = remove_elements_stable(trimmed_table.columns(), &all_removed);
            *trimmed_table.columns_mut() = updated_columns;
            *original_table = trimmed_table;

            for (lhs, rhs) in conflict.iter() {
                let lhs_vec = lhs.iter().copied().collect_vec();
                let rhs_vec = rhs.iter().copied().collect_vec();
                assert!(lhs_vec
                    .iter()
                    .copied()
                    .collect::<BTreeSet<_>>()
                    .is_subset(&primary_key));
                let keys_indeces = primary_key.iter().copied().collect_vec();

                let (_, new_matrix) = dependency_matrix.split(&rhs_vec, &keys_indeces);
                let mut new_table =
                    Table::new(format!("{}_{}", table_name, lhs_vec.iter().join("_")));
                let mut columns = Vec::new();
                for key_index in keys_indeces {
                    new_table.add_column(table_clone.columns()[key_index].clone());
                    new_table.add_primary_key(table_clone.columns()[key_index].name().to_string());
                    columns.push(table_clone.columns()[key_index].name().to_string());
                }
                for i in rhs_vec {
                    new_table.add_column(table_clone.columns()[i].clone());
                }
                new_table.add_foreign_key(ForeignKey::new(
                    self.schema.name().to_string(),
                    self.schema.name().to_string(),
                    columns.clone(),
                    table_name.to_string(),
                    columns,
                ));
                self.fds.insert(new_table.name().to_string(), new_matrix);
                self.schema.add_table(new_table);
            }
            *self.fds.get_mut(table_name).expect("Logic error.") = trimmed_matrix;
        }

        Ok(())
    }

    fn calculate_closure(&self, attributes: &BTreeSet<usize>, table_name: &str) -> BTreeSet<usize> {
        let mut closure = attributes.clone();
        let dependency_matrix = &self.fds[table_name];

        let mut added = true;

        while added {
            added = false;
            for (lhs, &row) in dependency_matrix.lut.iter() {
                if lhs.is_subset(&closure) {
                    for rhs in 0..dependency_matrix.matrix.shape()[1] {
                        if dependency_matrix.matrix[[row, rhs]]
                            .is_some_and(|x| x == DependencyKind::Yes)
                            && closure.insert(rhs)
                        {
                            added = true;
                        }
                    }
                }
            }
        }

        closure
    }

    pub fn find_candidate_keys(&self, table_name: &str) -> Vec<BTreeSet<usize>> {
        let attribute_count = self.fds[table_name].matrix.shape()[1];
        let attributes = (0..attribute_count).collect::<BTreeSet<_>>();

        let mut candidate_keys: Vec<BTreeSet<usize>> = Vec::new();

        for subset in SubsetIterator::new(attributes.iter().cloned().collect()) {
            let closure = self.calculate_closure(&subset, table_name);
            if closure == attributes && candidate_keys.iter().all(|key| !key.is_subset(&subset)) {
                candidate_keys.push(subset);
            }
        }

        candidate_keys
    }

    pub(crate) fn extract_dependencies(&mut self) {
        for table in self.schema.tables().iter() {
            let mut reader = ReaderBuilder::new()
                .has_headers(true)
                .quote(b'\"')
                .escape(Some(b'\"'))
                .from_path(self.folder.join(format!("{}.IR", table.name())))
                .unwrap();

            let start_position = reader.position().clone();
            let column_indices: Vec<usize> = (0..table.columns().len()).collect();

            for subset in SubsetIterator::new(column_indices.clone()) {
                for &rhs in &column_indices {
                    if subset.contains(&rhs) {
                        self.fds.get_mut(table.name()).unwrap().set_dependency(
                            &subset,
                            rhs,
                            DependencyKind::Trivial,
                        );
                        continue;
                    }
                    reader.seek(start_position.clone()).unwrap();

                    let closure = self.calculate_closure(&subset, table.name());
                    if closure.contains(&rhs) {
                        self.fds.get_mut(table.name()).unwrap().set_dependency(
                            &subset,
                            rhs,
                            DependencyKind::Pruned,
                        );
                        continue;
                    }

                    if self.is_functional_dependency(&mut reader, &subset, rhs) {
                        self.fds.get_mut(table.name()).unwrap().set_dependency(
                            &subset,
                            rhs,
                            DependencyKind::Yes,
                        );
                    } else {
                        self.fds.get_mut(table.name()).unwrap().set_dependency(
                            &subset,
                            rhs,
                            DependencyKind::No,
                        );
                    }
                }
            }
        }
    }

    fn is_functional_dependency(
        &self,
        reader: &mut Reader<File>,
        lhs_indeces: &BTreeSet<usize>,
        rhs_index: usize,
    ) -> bool {
        let mut mapping = HashMap::new();

        for result in reader.records() {
            let record = result.unwrap();
            let lhs_values = lhs_indeces
                .iter()
                .map(|&index| record[index].to_string())
                .collect::<Vec<String>>();

            let rhs_value = record[rhs_index].to_string();

            if let Some(existing_rhs) = mapping.get(&lhs_values) {
                if existing_rhs != &rhs_value {
                    return false;
                }
            } else {
                mapping.insert(lhs_values, rhs_value);
            }
        }
        true
    }

    pub fn print_dependencies(&self) {
        for (name, matrix) in self.fds.iter() {
            println!("{}", name);
            matrix.print_dependencies();
        }
    }

    pub fn convert_to_2nf(&mut self) {
        let mut non_2nf_tables = HashMap::new();
        let mut decomposition_data = HashMap::new();
        for (table_name, dependency_matrix) in self.fds.iter() {
            let mut non_2nf_fds = Vec::new();
            let candidate_keys = self.find_candidate_keys(table_name);
            println!("Candidate keys: {:#?}", candidate_keys);
            let prime_attributes = candidate_keys
                .iter()
                .flatten()
                .copied()
                .collect::<BTreeSet<_>>();
            let attributes = (0..dependency_matrix.matrix.shape()[1]).collect::<BTreeSet<_>>();
            let non_prime_attributes = attributes
                .difference(&prime_attributes)
                .copied()
                .collect::<BTreeSet<_>>();

            for non_prime_attribute in non_prime_attributes.iter().copied() {
                for key in candidate_keys.iter() {
                    let subset_iter = SubsetIterator::new(key.iter().copied().collect::<Vec<_>>());
                    for partial_key in subset_iter.into_iter() {
                        if partial_key == *key {
                            continue;
                        }
                        let closure = self.calculate_closure(&partial_key, table_name);
                        if closure.contains(&non_prime_attribute) {
                            non_2nf_fds.push((partial_key.clone(), non_prime_attribute));
                            break;
                        }
                    }
                }
            }
            non_2nf_tables.insert(table_name.clone(), non_2nf_fds);
            println!("Conflicts: {:#?}", non_2nf_tables);
        }
        for (table_name, conflicts) in non_2nf_tables.iter() {
            let mut grouped_conflict = HashMap::new();
            for (lhs, rhs) in conflicts.iter() {
                grouped_conflict
                    .entry(lhs.clone())
                    .or_insert_with(|| BTreeSet::from_iter(vec![*rhs]))
                    .insert(*rhs);
            }
            decomposition_data.insert(table_name.clone(), grouped_conflict);
        }
        println!("dec data: {:#?}", decomposition_data);
        let mut empty = true;
        for (_, conflict) in decomposition_data.iter() {
            if !conflict.is_empty() {
                empty = false;
            }
        }
        if empty {
            return;
        }
        self.decompose(&decomposition_data)
            .expect("Might fail idk.");
    }

    pub fn convert_to_3nf(&mut self) {
        let mut conflicts = HashMap::new();
        let mut decomposition_data = HashMap::new();
        for (table_name, dependency_matrix) in self.fds.iter() {
            println!("Checking table: {table_name}");
            let mut non_3nf_fds = Vec::new();
            let candidate_keys = self.find_candidate_keys(table_name);
            println!("candidate keys: {:#?}", candidate_keys);
            let prime_attributes = candidate_keys
                .iter()
                .flatten()
                .copied()
                .collect::<BTreeSet<_>>();
            println!("prime attributes: {:#?}", prime_attributes);
            let attributes = (0..dependency_matrix.matrix.shape()[1]).collect::<BTreeSet<_>>();
            let non_prime_attributes = attributes
                .difference(&prime_attributes)
                .copied()
                .collect::<BTreeSet<_>>();
            println!("non prime attributes: {:#?}", non_prime_attributes);

            for (lhs, _row) in dependency_matrix.lut.iter() {
                for rhs in attributes.iter().copied() {
                    let mut is_trivial = false;
                    let mut is_superkey = false;
                    let mut is_prime_attribute = false;
                    if dependency_matrix[(lhs.clone(), rhs)] == Some(DependencyKind::Trivial) {
                        is_trivial = true;
                    }
                    if self.calculate_closure(lhs, table_name) == attributes {
                        is_superkey = true;
                    }
                    if !lhs.contains(&rhs) {
                        is_prime_attribute = prime_attributes.contains(&rhs);
                    }

                    if !(is_trivial || is_superkey || is_prime_attribute)
                        && dependency_matrix[(lhs.clone(), rhs)] == Some(DependencyKind::Yes)
                    {
                        non_3nf_fds.push((lhs.clone(), rhs));
                    }
                }
            }
            conflicts.insert(table_name.clone(), non_3nf_fds);
        }
        println!("Confilcts: {:#?}", conflicts);
        for (table_name, conflicts) in conflicts.iter() {
            let mut grouped_conflict = HashMap::new();
            for (lhs, rhs) in conflicts.iter() {
                grouped_conflict
                    .entry(lhs.clone())
                    .or_insert_with(|| BTreeSet::from_iter(vec![*rhs]))
                    .insert(*rhs);
            }
            decomposition_data.insert(table_name.clone(), grouped_conflict);
        }
        println!("dec data: {:#?}", decomposition_data);
        let mut empty = true;
        for (_, conflict) in decomposition_data.iter() {
            if !conflict.is_empty() {
                empty = false;
            }
        }
        if empty {
            return;
        }
        self.decompose(&decomposition_data)
            .expect("Might fail idk.");
    }
}

impl std::fmt::Display for DependencyInference {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        for (name, matrix) in self.fds.iter() {
            writeln!(f, "{}", name)?;
            write!(f, "{}", matrix)?;
        }
        Ok(())
    }
}

fn remove_elements_stable<T: Clone>(from: &[T], indeces: &[usize]) -> Vec<T> {
    let mut removed = Vec::new();
    for (idx, element) in from.iter().enumerate() {
        if !indeces.contains(&idx) {
            removed.push(element.clone());
        }
    }
    removed
}

#[cfg(test)]
mod test {
    use crate::postgres::types::{PrimitiveType, Type};

    use super::*;

    #[test]
    fn test_2nf() {
        let mut schema = Schema::new("test_schema".to_string());
        let mut table = Table::new("test_table".to_string());
        let column_names = ["a", "b", "c", "d", "e", "f", "g", "h"];
        for column_name in column_names {
            let column_definition =
                ColumnDefinition::new(column_name.to_string(), Type::Simple(PrimitiveType::Text));
            table.add_column(column_definition);
        }
        schema.add_table(table);
        let mut fd_matrix = DependencyMatrix::new(column_names.len());
        fd_matrix.set_dependency(&BTreeSet::from_iter(vec![2]), 5, DependencyKind::Yes);
        fd_matrix.set_dependency(&BTreeSet::from_iter(vec![2]), 7, DependencyKind::Yes);
        fd_matrix.set_dependency(&BTreeSet::from_iter(vec![1]), 3, DependencyKind::Yes);
        fd_matrix.set_dependency(&BTreeSet::from_iter(vec![5]), 6, DependencyKind::Yes);
        let mut fds = HashMap::new();
        fds.insert("test_table".to_string(), fd_matrix);
        let mut dependency_inference = DependencyInference {
            schema,
            fds,
            folder: PathBuf::new(),
        };
        dependency_inference.verify_and_set_primary_keys();
        dependency_inference.convert_to_2nf();
        println!("{:#?}", dependency_inference.schema);
        for fd in dependency_inference.fds {
            println!("{}", fd.0);
            fd.1.print_dependencies()
        }
        panic!();
    }

    /*#[test]
    fn test_3nf() {
        let mut fds = HashMap::new();
        let mut schema = Schema::new("test_schema".to_string());

        let mut r1 = Table::new("r1".to_string());
        let column_names = ["a", "b", "c", "e"];
        for column_name in column_names {
            let column_definition =
                ColumnDefinition::new(column_name.to_string(), Type::Simple(PrimitiveType::Text));
            r1.add_column(column_definition);
        }
        schema.add_table(r1);
        let fd_matrix = DependencyMatrix::new(column_names.len());
        fds.insert("r1".to_string(), fd_matrix);

        let mut r2 = Table::new("r2".to_string());
        let column_names = ["c", "f", "g", "h"];
        for column_name in column_names {
            let column_definition =
                ColumnDefinition::new(column_name.to_string(), Type::Simple(PrimitiveType::Text));
            r2.add_column(column_definition);
        }
        schema.add_table(r2);
        let mut fd_matrix = DependencyMatrix::new(column_names.len());
        fd_matrix.set_dependency(&BTreeSet::from_iter(vec![0]), 1, DependencyKind::Yes);
        fd_matrix.set_dependency(&BTreeSet::from_iter(vec![0]), 3, DependencyKind::Yes);
        fd_matrix.set_dependency(&BTreeSet::from_iter(vec![1]), 2, DependencyKind::Yes);
        fds.insert("r2".to_string(), fd_matrix);

        let mut r3 = Table::new("r3".to_string());
        let column_names = ["b", "d"];
        for column_name in column_names {
            let column_definition =
                ColumnDefinition::new(column_name.to_string(), Type::Simple(PrimitiveType::Text));
            r3.add_column(column_definition);
        }
        let mut fd_matrix = DependencyMatrix::new(column_names.len());
        fd_matrix.set_dependency(&BTreeSet::from_iter(vec![0]), 1, DependencyKind::Yes);
        fds.insert("r3".to_string(), fd_matrix);
        schema.add_table(r3);
        let mut dependency_inference = DependencyInference {
            schema,
            fds,
            folder: PathBuf::new(),
        };
        dependency_inference.convert_to_3nf();
    }*/
}
