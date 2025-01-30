use std::{
    collections::{BTreeSet, HashMap, HashSet},
    fmt::write,
    fs::File,
    path::PathBuf,
};

use csv::{Reader, ReaderBuilder};
use itertools::Itertools;
use ndarray::Array2;

use crate::{
    cassandra::database::Keyspace,
    postgres::database::{ColumnDefinition, Schema, Table},
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
    partial_dependencies: HashMap<String, Vec<(BTreeSet<usize>, usize)>>,
    transitive_dependencies: HashMap<String, Vec<(BTreeSet<usize>, usize)>>,
}

impl DependencyInference {
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
            partial_dependencies: HashMap::new(),
            transitive_dependencies: HashMap::new(),
        }
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
                        if dependency_matrix.matrix[[row, rhs]].is_some_and(|x| {
                            x == DependencyKind::Yes || x == DependencyKind::Trivial
                        }) && closure.insert(rhs)
                        {
                            added = true;
                        }
                    }
                }
            }
        }

        closure
    }

    pub fn find_candidate_keys_bf(&self, table_name: &str) -> Vec<BTreeSet<usize>> {
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

    pub fn is_in_2nf(&mut self) -> bool {
        let mut partial_dependencies: HashMap<String, Vec<(BTreeSet<usize>, usize)>> =
            HashMap::new();
        for table_name in self.schema.tables().iter().map(|t| t.name()) {
            let candidate_keys = self.find_candidate_keys_bf(table_name);
            let dependency_matrix = &self.fds[table_name];

            let all_attributes = (0..dependency_matrix.matrix.shape()[1]).collect::<BTreeSet<_>>();

            let prime_attributes = candidate_keys
                .iter()
                .flatten()
                .copied()
                .collect::<BTreeSet<_>>();

            let non_prime_attributes = all_attributes
                .difference(&prime_attributes)
                .collect::<BTreeSet<_>>();

            for (lhs, &row) in dependency_matrix.lut.iter() {
                if lhs.len() > 1 {
                    for &&rhs in non_prime_attributes.iter() {
                        if let Some(DependencyKind::Yes) = dependency_matrix.matrix[[row, rhs]] {
                            for candidate_key in candidate_keys.iter() {
                                if lhs.is_subset(candidate_key) && lhs.len() < candidate_key.len() {
                                    partial_dependencies
                                        .entry(table_name.to_string())
                                        .or_default()
                                        .push((lhs.clone(), rhs));
                                }
                            }
                        }
                    }
                }
            }
        }
        self.partial_dependencies = partial_dependencies;
        self.partial_dependencies.is_empty()
    }

    pub fn convert_to_2nf(&mut self) {
        // Take the partial dependencies, fetch the column definitions for each
        // Create a new table with the original's primary key (also implement to check if the
        // original primary key is actually minimal)
        // Make a set from these columns
        // add them to the table
        // add the primary key to the table with a foreign key link
        // set the columns to backlink to the original
        todo!()
    }

    pub fn is_in_3nf(&mut self) -> bool {
        let mut transitive_dependencies: HashMap<String, Vec<(BTreeSet<usize>, usize)>> =
            HashMap::new();

        for table_name in self.schema.tables().iter().map(|t| t.name()) {
            let candidate_keys = self.find_candidate_keys_bf(table_name);
            let dependency_matrix = &self.fds[table_name];

            let all_attributes = (0..dependency_matrix.matrix.shape()[1]).collect::<BTreeSet<_>>();

            let prime_attributes = candidate_keys
                .iter()
                .flatten()
                .copied()
                .collect::<BTreeSet<_>>();

            let non_prime_attributes = all_attributes
                .difference(&prime_attributes)
                .copied()
                .collect::<BTreeSet<_>>();

            for (lhs, &row) in dependency_matrix.lut.iter() {
                if lhs.len() == 1 && prime_attributes.contains(lhs.iter().next().unwrap()) {
                    continue;
                }

                for &rhs in &non_prime_attributes {
                    if let Some(DependencyKind::Yes) = dependency_matrix.matrix[[row, rhs]] {
                        let closure = self.calculate_closure(lhs, table_name);
                        if !closure.contains(&rhs) {
                            continue;
                        }

                        let is_superkey = candidate_keys.iter().any(|k| lhs.is_superset(k));
                        if !is_superkey {
                            transitive_dependencies
                                .entry(table_name.to_string())
                                .or_default()
                                .push((lhs.clone(), rhs));
                        }
                    }
                }
            }
        }

        self.transitive_dependencies = transitive_dependencies;
        println!("{:#?}", self.transitive_dependencies);
        self.transitive_dependencies.is_empty()
    }

    pub fn convert_to_3nf(&mut self) {
        // Take the transitive dependencies, fetch the column definitions for each
        // Create a new table with the original's primary key (also implement to check if the
        // original primary key is actually minimal)
        // Make a set from these columns
        // add them to the table
        // add the primary key to the table with a foreign key link
        // set the columns to backlink to the original
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
