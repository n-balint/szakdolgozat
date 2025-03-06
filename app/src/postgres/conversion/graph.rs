use std::collections::HashSet;

#[derive(Debug, Clone)]
pub struct Node<T: Send + Sync + 'static> {
    data: T,
}

impl<T: Send + Sync + 'static> Node<T> {
    pub fn new(data: T) -> Self {
        Self { data }
    }

    pub fn data(&self) -> &T {
        &self.data
    }
}

#[derive(Debug, Clone)]
pub struct Graph<T: Send + Sync + 'static> {
    nodes: Vec<Node<T>>,
    matrix: Vec<Vec<bool>>,
}

impl<T: Send + Sync + 'static> Graph<T> {
    pub fn new(size: usize) -> Self {
        Graph {
            nodes: Vec::new(),
            matrix: vec![vec![false; size]; size],
        }
    }

    pub fn add_node(&mut self, node: Node<T>) {
        self.nodes.push(node)
    }

    pub fn add_edge(&mut self, src: usize, dest: usize) {
        self.matrix[src][dest] = true;
    }

    pub fn check_edge(&self, src: usize, dest: usize) -> bool {
        self.matrix[src][dest]
    }

    pub fn node(&self, idx: usize) -> &Node<T> {
        &self.nodes[idx]
    }

    pub fn neighbors(&self, idx: usize) -> Vec<usize> {
        self.matrix[idx]
            .iter()
            .enumerate()
            .filter_map(
                |(i, &is_connected)| {
                    if is_connected {
                        Some(i)
                    } else {
                        None
                    }
                },
            )
            .collect()
    }
    pub fn dfs(&self, start: usize) -> Vec<&Node<T>> {
        let mut visited = HashSet::new();
        let mut stack = Vec::new();
        let mut result = Vec::new();

        stack.push(start);
        visited.insert(start);

        while let Some(node_idx) = stack.pop() {
            result.push(self.node(node_idx));
            for neighbor in self.neighbors(node_idx) {
                if !visited.contains(&neighbor) {
                    visited.insert(neighbor);
                    stack.push(neighbor);
                }
            }
        }

        result
    }
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn test_dfs() {
        let mut graph = Graph::new(8);
        graph.add_node(Node::new("felhasznalo")); // 0
        graph.add_node(Node::new("helyszin")); // 1
        graph.add_node(Node::new("kategoria")); // 2
        graph.add_node(Node::new("kep")); // 3
        graph.add_node(Node::new("megjegyzes")); // 4
        graph.add_node(Node::new("tartozik")); // 5
        graph.add_node(Node::new("ertekeles")); // 6
        graph.add_node(Node::new("palyazat")); // 7

        graph.add_edge(0, 1);
        graph.add_edge(0, 2);
        graph.add_edge(3, 0);
        graph.add_edge(3, 1);
        graph.add_edge(3, 7);
        graph.add_edge(4, 0);
        graph.add_edge(4, 3);
        graph.add_edge(5, 3);
        graph.add_edge(5, 2);
        graph.add_edge(6, 0);
        graph.add_edge(6, 3);
        graph.add_edge(7, 3);

        for node in graph.dfs(3) {
            println!("{}", node.data())
        }
    }
}
