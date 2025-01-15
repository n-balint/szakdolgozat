pub trait Query {
    fn to_query_string(&self) -> String;
}
