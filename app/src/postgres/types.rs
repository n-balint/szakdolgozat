use crate::cassandra;

#[derive(Debug, Clone)]
pub enum Type {
    Simple,
    Enum(Vec<String>),
    Pseudo,
    Array(PrimitiveType),
    Range(PrimitiveType),
    Multirange(PrimitiveType),
    Domain(PrimitiveType),
    Composite(Vec<CompositeField>),
}

#[derive(Debug, Clone)]
pub struct CompositeField {
    name: String,
    r#type: Type,
}

#[derive(Debug, Clone, Copy)]
pub enum PrimitiveType {
    Bigint,
    Bigserial,
    Bit,
    BitVarying,
    Boolean,
    Box,
    Bytea,
    Character(usize),
    CharacterVarying(usize),
    Cidr,
    Circle,
    Date,
    DoublePrecision,
    Inet,
    Integer,
    Interval,
    Json,
    Jsonb,
    Line,
    LSeg,
    Macaddr,
    Macaddr8,
    Money,
    Numeric(usize, usize),
    Path,
    PgLen,
    PgSnapshot,
    Point,
    Polygon,
    Real,
    Smallint,
    Smallserial,
    Serial,
    Text,
    Time,
    TimeWithTimezone,
    Timestamp,
    TimestampWithTimezone,
    TsQuery,
    TsVector,
    TxIdSnapshot,
    Uuid,
    Xml,
}

impl From<cassandra::types::PrimitiveType> for PrimitiveType {
    fn from(value: cassandra::types::PrimitiveType) -> Self {
        match value {
            cassandra::types::PrimitiveType::Ascii => PrimitiveType::Text,
            cassandra::types::PrimitiveType::Bigint => PrimitiveType::Bigint,
            cassandra::types::PrimitiveType::Blob => PrimitiveType::Bytea,
            cassandra::types::PrimitiveType::Boolean => PrimitiveType::Boolean,
            cassandra::types::PrimitiveType::Counter => PrimitiveType::Serial,
            cassandra::types::PrimitiveType::Date => PrimitiveType::Date,
            cassandra::types::PrimitiveType::Decimal => PrimitiveType::Numeric(0, 0),
            cassandra::types::PrimitiveType::Double => PrimitiveType::DoublePrecision,
            cassandra::types::PrimitiveType::Duration => PrimitiveType::Interval,
            cassandra::types::PrimitiveType::Float => PrimitiveType::Real,
            cassandra::types::PrimitiveType::Inet => PrimitiveType::Inet,
            cassandra::types::PrimitiveType::Int => PrimitiveType::Integer,
            cassandra::types::PrimitiveType::Smallint => PrimitiveType::Smallint,
            cassandra::types::PrimitiveType::Text => PrimitiveType::Text,
            cassandra::types::PrimitiveType::Time => PrimitiveType::Time,
            cassandra::types::PrimitiveType::Timestamp => PrimitiveType::Timestamp,
            cassandra::types::PrimitiveType::TimeUuid => PrimitiveType::Uuid,
            cassandra::types::PrimitiveType::Tinyint => PrimitiveType::Smallint,
            cassandra::types::PrimitiveType::Uuid => PrimitiveType::Uuid,
            cassandra::types::PrimitiveType::Varchar => PrimitiveType::CharacterVarying(0),
            cassandra::types::PrimitiveType::Varint => PrimitiveType::Numeric(0, 0),
        }
    }
}
