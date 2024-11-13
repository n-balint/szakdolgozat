use std::{collections::HashMap, error::Error, fs::File, path::PathBuf};

use csv::Reader;

use crate::cassandra::database::Keyspace;

#[derive(Debug, Clone)]
pub struct SubsetIterator {
    data: Vec<u32>,
    subset_count: usize,
    current: usize,
}

impl SubsetIterator {
    pub fn new(data: Vec<u32>) -> Self {
        let subset_count = 1 << data.len();
        Self {
            data,
            subset_count,
            current: 1,
        }
    }
}

impl Iterator for SubsetIterator {
    type Item = Vec<u32>;

    fn next(&mut self) -> Option<Self::Item> {
        if self.current >= self.subset_count {
            return None;
        }

        let mut subset = Vec::new();
        for (i, v) in self.data.iter().enumerate() {
            if (self.current >> i) & 1 == 1 {
                subset.push(*v);
            }
        }

        self.current += 1;
        Some(subset)
    }
}

#[cfg(test)]
mod test {
    use super::*;
    #[test]
    fn subset_iter_0() {
        let i = SubsetIterator::new(Vec::new()).collect::<Vec<_>>();
        assert_eq!(i.len(), 0);
    }
    #[test]
    fn subset_iter_1() {
        let i = SubsetIterator::new(vec![1]).collect::<Vec<_>>();
        assert_eq!(i.len(), 1);
        assert!(i.contains(&vec![1]));
    }
    #[test]
    fn subset_iter_2() {
        let i = SubsetIterator::new(vec![2, 3]).collect::<Vec<_>>();
        assert_eq!(i.len(), 3);
        assert!(i.contains(&vec![2]));
        assert!(i.contains(&vec![3]));
        assert!(i.contains(&vec![2, 3]));
    }
    #[test]
    fn subset_iter_4() {
        let i = SubsetIterator::new(vec![0, 1, 2, 3]).collect::<Vec<_>>();
        assert_eq!(i.len(), 15);
        assert!(i.contains(&vec![0]));
        assert!(i.contains(&vec![1]));
        assert!(i.contains(&vec![2]));
        assert!(i.contains(&vec![3]));
        assert!(i.contains(&vec![0, 1]));
        assert!(i.contains(&vec![0, 2]));
        assert!(i.contains(&vec![0, 3]));
        assert!(i.contains(&vec![1, 2]));
        assert!(i.contains(&vec![1, 3]));
        assert!(i.contains(&vec![2, 3]));
        assert!(i.contains(&vec![0, 1, 2]));
        assert!(i.contains(&vec![0, 1, 3]));
        assert!(i.contains(&vec![0, 2, 3]));
        assert!(i.contains(&vec![1, 2, 3]));
        assert!(i.contains(&vec![0, 1, 2, 3]));
    }
}
