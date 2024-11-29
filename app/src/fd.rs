use std::{
    collections::{HashMap, HashSet},
    fs::File,
};

use csv::{Reader, ReaderBuilder};
use itertools::Itertools;

use crate::cassandra::database::Keyspace;

#[derive(Debug, Clone)]
pub struct SubsetIterator {
    data: Vec<usize>,
    subset_count: usize,
    current: usize,
}

impl SubsetIterator {
    pub fn new(data: Vec<usize>) -> Self {
        let subset_count = 1 << data.len();
        Self {
            data,
            subset_count,
            current: 1,
        }
    }
}

// make this generic
#[derive(Clone)]
pub struct FunctionalDependency {
    left: HashSet<usize>,
    right: HashSet<usize>,
}

#[derive(Clone)]
pub struct StringFunctionalDependency {
    left: HashSet<String>,
    right: HashSet<String>,
}

impl std::fmt::Display for StringFunctionalDependency {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{:#?}", self)
    }
}

impl std::fmt::Debug for StringFunctionalDependency {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "{} -> {}",
            self.left.iter().join(" "),
            self.right.iter().join(" ")
        )
    }
}

impl std::fmt::Display for FunctionalDependency {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{:#?}", self)
    }
}
impl std::fmt::Debug for FunctionalDependency {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "{} -> {}",
            self.left.iter().join(" "),
            self.right.iter().join(" ")
        )
    }
}

#[derive(Debug, Clone)]
pub struct CassandraDependency<'a> {
    files: &'a HashMap<String, File>,
    keyspace: &'a Keyspace,
    fds: HashMap<String, Vec<FunctionalDependency>>,
}

impl<'a> CassandraDependency<'a> {
    pub(crate) fn new(files: &'a HashMap<String, File>, keyspace: &'a Keyspace) -> Self {
        Self {
            files,
            keyspace,
            fds: HashMap::new(),
        }
    }

    pub(crate) fn stringify_dependencies(
        &self,
    ) -> HashMap<String, Vec<StringFunctionalDependency>> {
        let mut string_deps_map: HashMap<String, Vec<StringFunctionalDependency>> = HashMap::new();
        for (k, v) in self.fds.iter() {
            let mut string_deps = Vec::new();
            let table = self
                .keyspace
                .tables()
                .iter()
                .find(|t| t.name() == k)
                .unwrap();
            for dependency in v.iter() {
                let mut string_dep = StringFunctionalDependency {
                    left: HashSet::new(),
                    right: HashSet::new(),
                };
                dependency.left.iter().for_each(|&item| {
                    string_dep
                        .left
                        .insert(table.columns()[item].name().to_string());
                });
                dependency.right.iter().for_each(|&item| {
                    string_dep
                        .right
                        .insert(table.columns()[item].name().to_string());
                });
                string_deps.push(string_dep);
            }
            string_deps_map.insert(table.name().to_string(), string_deps);
        }
        string_deps_map
    }

    pub(crate) fn fd_count(&self) {
        for (key, value) in self.fds.iter() {
            println!("{} : {}", key, value.len());
        }
    }

    fn calculate_closure(&self, attributes: &HashSet<usize>, table_name: &str) -> HashSet<usize> {
        let mut closure = attributes.clone();
        let empty = Vec::new();
        let fds = self.fds.get(table_name).unwrap_or(&empty);

        let mut r#do = true;
        while r#do {
            r#do = false;
            for fd in fds {
                if fd.left.is_subset(&closure) && !fd.right.is_subset(&closure) {
                    closure.extend(&fd.right);
                    r#do = true;
                }
            }
        }

        closure
    }

    fn generate_candidate_keys(&self, table_name: &str) -> Vec<Vec<usize>> {
        let mut candidate_keys = Vec::new();

        let table = self
            .keyspace
            .tables()
            .iter()
            .find(|t| t.name() == table_name)
            .unwrap();

        let attributes = (0..table.columns().len()).collect::<HashSet<_>>();

        for size in 1..=table.columns().len() {
            for subset in attributes.iter().combinations(size) {
                let subset = subset.into_iter().copied().collect();
                let closure = self.calculate_closure(&subset, table_name);

                if closure == attributes
                    && !candidate_keys
                        .iter()
                        .any(|key: &Vec<usize>| key.iter().all(|attr| subset.contains(attr)))
                {
                    candidate_keys.push(subset.into_iter().collect());
                }
            }
        }

        candidate_keys
    }

    fn is_in_2nf(&self, table_name: &str, candidate_keys: &[Vec<usize>]) -> bool {
        if candidate_keys.iter().any(|key| key.len() == 1) {
            return true;
        }

        let table = self
            .keyspace
            .tables()
            .iter()
            .find(|t| t.name() == table_name)
            .unwrap();

        let prime_attributes = candidate_keys
            .iter()
            .flat_map(|key| key.iter())
            .copied()
            .collect::<HashSet<_>>();

        let empty = Vec::new();
        let fds = self.fds.get(table_name).unwrap_or(&empty);

        for fd in fds.iter() {
            if candidate_keys.iter().any(|key| {
                let key = key.iter().copied().collect::<HashSet<_>>();
                fd.left.is_subset(&key) && fd.left == key
            }) && fd
                .right
                .iter()
                .any(|attribute| !prime_attributes.contains(attribute))
            {
                return false;
            }
        }
        true
    }

    fn is_in_3nf(&self, table_name: &str, candidate_keys: &[Vec<usize>]) -> bool {
        if !self.is_in_2nf(table_name, candidate_keys) {
            return false;
        }
        let table = self
            .keyspace
            .tables()
            .iter()
            .find(|t| t.name() == table_name)
            .unwrap();

        let all_attributes = (0..table.columns().len()).collect::<HashSet<_>>();

        let prime_attributes = candidate_keys
            .iter()
            .flat_map(|key| key.iter())
            .copied()
            .collect::<HashSet<_>>();

        let secondary_attributes = all_attributes
            .difference(&prime_attributes)
            .copied()
            .collect::<HashSet<_>>();

        if secondary_attributes.is_empty() {
            return true;
        }

        false
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
                for rhs in &column_indices {
                    if subset.contains(rhs) {
                        continue;
                    }
                    reader.seek(start_position.clone()).unwrap();
                    if self.is_functional_dependency(&mut reader, &subset, *rhs) {
                        let left = subset.clone();
                        let mut right = HashSet::new();
                        right.insert(*rhs);

                        match self.fds.get_mut(table.name()) {
                            Some(value) => {
                                value.push(FunctionalDependency { left, right });
                            }
                            None => {
                                self.fds.insert(
                                    table.name().to_string(),
                                    vec![FunctionalDependency { left, right }],
                                );
                            }
                        }
                    }
                }
            }
        }
    }

    fn is_functional_dependency(
        &self,
        reader: &mut Reader<File>,
        lhs_indeces: &HashSet<usize>,
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

impl Iterator for SubsetIterator {
    type Item = HashSet<usize>;

    fn next(&mut self) -> Option<Self::Item> {
        if self.current >= self.subset_count {
            return None;
        }

        let mut subset = HashSet::new();
        for (i, v) in self.data.iter().enumerate() {
            if (self.current >> i) & 1 == 1 {
                subset.insert(*v);
            }
        }

        self.current += 1;
        Some(subset)
    }
}

#[cfg(test)]
mod test {
    use super::*;
    use crate::cassandra::database::{ColumnDefinition, Keyspace, Replication, Strategy, Table};

    #[test]
    fn example_candidate_key() {
        let mut keyspace = Keyspace::new(
            "example".to_string(),
            Replication::new(Strategy::Simple("1".to_string()), false),
        );
        let mut columns = Vec::new();
        columns.push(ColumnDefinition::new(
            "rendszam".to_string(),
            crate::cassandra::types::Type::Primitive(crate::cassandra::types::PrimitiveType::Blob),
        ));
        columns.push(ColumnDefinition::new(
            "gepkocsi_t".to_string(),
            crate::cassandra::types::Type::Primitive(crate::cassandra::types::PrimitiveType::Blob),
        ));
        columns.push(ColumnDefinition::new(
            "muszaki_l".to_string(),
            crate::cassandra::types::Type::Primitive(crate::cassandra::types::PrimitiveType::Blob),
        ));
        columns.push(ColumnDefinition::new(
            "sofor_n".to_string(),
            crate::cassandra::types::Type::Primitive(crate::cassandra::types::PrimitiveType::Blob),
        ));
        columns.push(ColumnDefinition::new(
            "sofor_l".to_string(),
            crate::cassandra::types::Type::Primitive(crate::cassandra::types::PrimitiveType::Blob),
        ));
        columns.push(ColumnDefinition::new(
            "sofor_t".to_string(),
            crate::cassandra::types::Type::Primitive(crate::cassandra::types::PrimitiveType::Blob),
        ));
        columns.push(ColumnDefinition::new(
            "indulasi_i".to_string(),
            crate::cassandra::types::Type::Primitive(crate::cassandra::types::PrimitiveType::Blob),
        ));
        columns.push(ColumnDefinition::new(
            "indulasi_c".to_string(),
            crate::cassandra::types::Type::Primitive(crate::cassandra::types::PrimitiveType::Blob),
        ));
        columns.push(ColumnDefinition::new(
            "megtett_km".to_string(),
            crate::cassandra::types::Type::Primitive(crate::cassandra::types::PrimitiveType::Blob),
        ));
        let table = Table::new("Fuvar".to_string(), columns);
        let files = HashMap::new();
        let mut fds = HashMap::new();
        let mut fd_vec = Vec::new();
        keyspace.set_tables(vec![table]);
        fd_vec.push(FunctionalDependency {
            left: HashSet::from([0]),
            right: HashSet::from([1, 2, 3, 4, 5]),
        });
        fd_vec.push(FunctionalDependency {
            left: HashSet::from([0, 6]),
            right: HashSet::from([7, 8]),
        });
        fd_vec.push(FunctionalDependency {
            left: HashSet::from([5]),
            right: HashSet::from([3, 4, 0]),
        });
        fds.insert("Fuvar".to_string(), fd_vec);
        let cassandra_deps = CassandraDependency {
            files: &files,
            keyspace: &keyspace,
            fds,
        };

        let c = cassandra_deps.generate_candidate_keys("Fuvar");

        assert_eq!(c.len(), 2);
        assert!(c.contains(&vec![5, 6]) || c.contains(&vec![6, 5]));
        assert!(c.contains(&vec![0, 6]) || c.contains(&vec![6, 0]));
        assert!(!cassandra_deps.is_in_2nf("Fuvar", &c));
    }
}
