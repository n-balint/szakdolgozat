use std::{
    collections::{BTreeSet, HashMap, HashSet},
    fmt::write,
    fs::File,
};

use csv::{Reader, ReaderBuilder};
use itertools::Itertools;
use ndarray::Array2;

use crate::cassandra::database::Keyspace;

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
    //inverse_lut: HashMap<usize, BTreeSet<usize>>,
    matrix: Array2<Option<DependencyKind>>,
}

impl DependencyMatrix {
    fn new(attribute_count: usize) -> Self {
        let matrix = Array2::from_elem((1 << attribute_count, attribute_count), None);
        let mut lut = HashMap::new();
        //let mut inverse_lut = HashMap::new();

        let indeces = (0..attribute_count).collect();
        for (row, subset) in SubsetIterator::new(indeces).enumerate() {
            lut.insert(subset, row);
        }
        //for (k, &v) in lut.iter() {
        //    inverse_lut.insert(v, k.clone());
        //}
        Self {
            lut,
            //    inverse_lut,
            matrix,
        }
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
pub struct CassandraDependency<'a> {
    files: &'a HashMap<String, File>,
    keyspace: &'a Keyspace,
    fds: HashMap<String, DependencyMatrix>,
}

impl<'a> std::fmt::Display for CassandraDependency<'a> {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        for (name, matrix) in self.fds.iter() {
            writeln!(f, "{}", name)?;
            write!(f, "{}", matrix)?;
        }
        Ok(())
    }
}

impl<'a> CassandraDependency<'a> {
    pub(crate) fn new(files: &'a HashMap<String, File>, keyspace: &'a Keyspace) -> Self {
        let mut fds = HashMap::new();
        for table in keyspace.tables().iter() {
            let matrix = DependencyMatrix::new(table.columns().len());
            fds.insert(table.name().to_string(), matrix);
        }
        println!("{:#?}", fds);
        Self {
            files,
            keyspace,
            fds,
        }
    }

    pub fn print_dependencies(&self) {
        for (name, matrix) in self.fds.iter() {
            println!("{}", name);
            matrix.print_dependencies();
        }
    }

    fn find_candidate_keys_from_table() {
        todo!()
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

    pub(crate) fn extract_dependencies(&mut self) {
        for table in self.keyspace.tables().iter() {
            let mut reader = ReaderBuilder::new()
                .has_headers(true)
                .quote(b'\"')
                .escape(Some(b'\\'))
                .from_reader(self.files[table.name()].try_clone().unwrap());

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
}
