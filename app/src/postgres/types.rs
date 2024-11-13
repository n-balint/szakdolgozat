use crate::cassandra::types::PrimitiveType as CPType;
use crate::cassandra::types::Type as Ctype;

use super::database::Table;

#[derive(Debug, Clone)]
pub enum Type {
    Simple(PrimitiveType),
    Composite(String),
    Array {
        dimension: usize,
        length: Option<Vec<usize>>,
        r#type: Box<Type>,
    },
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

impl From<CPType> for PrimitiveType {
    fn from(value: CPType) -> Self {
        match value {
            CPType::Ascii => PrimitiveType::Text,
            CPType::Bigint => PrimitiveType::Bigint,
            CPType::Blob => PrimitiveType::Bytea,
            CPType::Boolean => PrimitiveType::Boolean,
            CPType::Counter => PrimitiveType::Serial,
            CPType::Date => PrimitiveType::Date,
            CPType::Decimal => PrimitiveType::Numeric(0, 0),
            CPType::Double => PrimitiveType::DoublePrecision,
            CPType::Duration => PrimitiveType::Interval,
            CPType::Float => PrimitiveType::Real,
            CPType::Inet => PrimitiveType::Inet,
            CPType::Int => PrimitiveType::Integer,
            CPType::Smallint => PrimitiveType::Smallint,
            CPType::Text => PrimitiveType::Text,
            CPType::Time => PrimitiveType::Time,
            CPType::Timestamp => PrimitiveType::Timestamp,
            CPType::TimeUuid => PrimitiveType::Uuid,
            CPType::Tinyint => PrimitiveType::Smallint,
            CPType::Uuid => PrimitiveType::Uuid,
            CPType::Varchar => PrimitiveType::CharacterVarying(0),
            CPType::Varint => PrimitiveType::Numeric(0, 0),
        }
    }
}

impl TryFrom<Ctype> for Type {
    type Error = ();
    fn try_from(value: Ctype) -> Result<Self, Self::Error> {
        match value {
            Ctype::Primitive(primitive_type) => Ok(Type::Simple(primitive_type.into())),
            Ctype::Collection { .. } | Ctype::Tuple(_) | Ctype::Udt { .. } => Err(()),
        }
    }
}
