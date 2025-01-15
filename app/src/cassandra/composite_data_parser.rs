use std::collections::HashMap;

/// Parses composite cassandra datatypes (maps, lists, tuples, sets, user defined types).
pub struct CompositeDataParser {}

/// Works like trim_matches but only removes the first and last occurance of the character.
fn trim_single_trailing(string: &str, pattern: char) -> &str {
    let mut start = 0;
    let mut end = string.len();

    if let Some(first) = string.chars().next() {
        if first == pattern {
            start = first.len_utf8();
        }
    }

    if let Some(last) = string.chars().rev().next() {
        if last == pattern {
            end -= last.len_utf8();
        }
    }

    &string[start..end]
}

impl CompositeDataParser {
    /// Parses a cassandra tuple literal.
    /// `tuple_literal::= '(' term( ',' term )* ')'`
    pub fn parse_tuple_literal<'a>(&self, string: &'a str) -> Vec<&'a str> {
        let trimmed = string.trim().trim_matches(['(', ')']);
        if trimmed.is_empty() {
            return Vec::new();
        }

        trimmed
            .split(',')
            .map(|s| trim_single_trailing(s.trim(), '\''))
            .collect()
    }

    /// Parses a cassandra map literal.
    /// `map_literal::= '\{' [ term ':' term (',' term : term)* ] '}'`
    pub fn parse_map_literal<'a>(&self, string: &'a str) -> Vec<(&'a str, &'a str)> {
        let trimmed = string.trim().trim_matches(['{', '}']);
        if trimmed.is_empty() {
            return Vec::new();
        }
        trimmed
            .split(',')
            .filter_map(|kv| {
                let key_value_pair = kv
                    .splitn(2, ':')
                    .map(|s| trim_single_trailing(s.trim(), '\''))
                    .collect::<Vec<&str>>();
                if key_value_pair.len() == 2 {
                    Some((key_value_pair[0], key_value_pair[1]))
                } else {
                    None
                }
            })
            .collect()
    }

    /// Parses a cassandra set literal.
    /// `set_literal::= '\{' [ term (',' term)* ] '}'`
    pub fn parse_set_literal<'a>(&self, string: &'a str) -> Vec<&'a str> {
        let trimmed = string.trim().trim_matches(['{', '}']);
        if trimmed.is_empty() {
            return Vec::new();
        }
        trimmed
            .split(',')
            .map(|s| trim_single_trailing(s.trim(), '\''))
            .collect()
    }

    /// Parses a cassadnra udt literal.
    /// `udt_literal::= '{' identifier ':' term ( ',' identifier ':' term)* '}'`
    pub fn parse_udt_literal<'a>(&self, string: &'a str) -> HashMap<&'a str, &'a str> {
        let trimmed = string.trim_matches(['{', '}']);
        let mut udt_map = HashMap::new();
        if trimmed.is_empty() {
            return udt_map;
        }
        for entry in trimmed.split(',') {
            if let Some((field_name, value)) = entry.split_once(':') {
                udt_map.insert(
                    trim_single_trailing(field_name.trim(), '\''),
                    trim_single_trailing(value.trim(), '\''),
                );
            }
        }

        udt_map
    }

    /// Parses a cassandra list literal.
    /// `list_literal::= '[' [ term (',' term)* ] ']'`
    pub fn parse_list_literal<'a>(&self, string: &'a str) -> Vec<&'a str> {
        let trimmed = string.trim_matches(['[', ']']);
        if trimmed.is_empty() {
            return Vec::new();
        }
        trimmed
            .split(',')
            .map(|s| trim_single_trailing(s.trim(), '\''))
            .collect()
    }

    pub fn new() -> Self {
        Self {}
    }
}

#[cfg(test)]
mod test {
    use super::*;
    #[test]
    fn parse_tuple_test() {
        let parser = CompositeDataParser::new();
        let input = r#"(    'valami'  , '"valami3' ,'''valami34' ) "#;
        let tuple = parser.parse_tuple_literal(input);
        assert!(tuple.contains(&"valami"));
        assert!(tuple.contains(&"\"valami3"));
        assert!(tuple.contains(&"''valami34"));
    }

    #[test]
    fn parse_map_test() {}

    #[test]
    fn parse_list_test() {
        let parser = CompositeDataParser::new();
        let input = r#"['name', '"name"', 'name''']"#;
        let list = parser.parse_list_literal(input);
        assert!(list.contains(&"name"));
        assert!(list.contains(&"\"name\""));
        assert!(list.contains(&"name''"))
    }

    #[test]
    fn parse_set_test() {}

    #[test]
    fn parse_udt_test() {}
}
