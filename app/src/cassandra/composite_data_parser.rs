use std::collections::HashMap;

/// Parses composite cassandra datatypes (maps, lists, tuples, sets, user defined types).
pub struct CompositeDataParser {}

/// Splits input on sep but not inside ''.
/// Example: "['key', 'value', "pa,ir"]" -> ["'key'", "'value'", "pa,ir"]
/// Normal split fn: "['key', 'value', "pa,ir"]" -> ["'key'", "'value'", "pa", "ir"]
fn quote_aware_split(input: &str, sep: char) -> Vec<&str> {
    let mut result = Vec::new();
    let mut quoted = false;
    let mut start = 0;

    for (i, c) in input.char_indices() {
        match c {
            '\'' if !quoted => {
                quoted = true;
            }
            '\'' if quoted => {
                quoted = false;
            }
            _ if c == sep && !quoted => {
                result.push(input[start..i].trim());
                start = i + 1;
            }
            _ => {}
        }
    }

    if start < input.len() {
        result.push(&input[start..]);
    }

    result
}

/// Works like trim_matches but only removes the first and last occurance of the character.
fn trim_single_trailing(string: &str, pattern: char) -> &str {
    let mut start = 0;
    let mut end = string.len();

    if let Some(first) = string.chars().next() {
        if first == pattern {
            start = first.len_utf8();
        }
    }

    if let Some(last) = string.chars().next_back() {
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

        quote_aware_split(trimmed, ',')
            .into_iter()
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
        quote_aware_split(trimmed, ',')
            .into_iter()
            .filter_map(|kv| {
                let key_value_pair = quote_aware_split(kv, ':')
                    .into_iter()
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
        quote_aware_split(trimmed, ',')
            .into_iter()
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
        for entry in quote_aware_split(trimmed, ',') {
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

        quote_aware_split(trimmed, ',')
            .into_iter()
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
    fn parse_map_test() {
        let parser = CompositeDataParser::new();
        let input = r#"{'key': 3, 'other_key' : 4}"#;
        let map = parser.parse_map_literal(input);
        assert!(map.contains(&("key", "3")));
        assert!(map.contains(&("other_key", "4")));
    }

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
    fn parse_set_test() {
        let parser = CompositeDataParser::new();
        let input = r#"{'first, second', 'third'}"#;
        let set = parser.parse_set_literal(input);
        assert!(set.contains(&"first, second"));
        assert!(set.contains(&"third"));
    }

    #[test]
    fn parse_udt_test() {
        let parser = CompositeDataParser::new();
        let input = r#"{name: 'simple name', null_value: }"#;
        let input2 = r#"{some: 7, val: , date: '2025-01-11'}"#;
        let map = parser.parse_udt_literal(input);
        println!("map: {:#?}", map);
        let map2 = parser.parse_udt_literal(input2);
        println!("map2: {:#?}", map2);
        assert!(map.contains_key(&"name"));
        assert_eq!(map["name"], "simple name");
        assert!(map.contains_key(&"null_value"));
        assert_eq!(map["null_value"], "");

        assert!(map2.contains_key(&"some"));
        assert_eq!(map2["some"], "7");
        assert!(map2.contains_key(&"val"));
        assert_eq!(map2["val"], "");
        assert!(map2.contains_key(&"date"));
        assert_eq!(map2["date"], "2025-01-11");
    }
}
