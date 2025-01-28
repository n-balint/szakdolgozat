use crate::cassandra::types::PrimitiveType as CPType;
use crate::cassandra::types::Type as Ctype;

use super::database::Table;

#[derive(Debug, Clone)]
pub enum Type {
    Simple(PrimitiveType),
    Composite(String),
    Array(PrimitiveType),
    Enum(String),
}

impl TryFrom<&str> for Type {
    type Error = String;
    fn try_from(value: &str) -> Result<Self, Self::Error> {
        let value = value.trim();
        match value {
            "bigint" => Ok(Type::Simple(PrimitiveType::Bigint)),
            "bigserial" => Ok(Type::Simple(PrimitiveType::Bigserial)),
            "bit" => Ok(Type::Simple(PrimitiveType::Bit(0))),
            "bit varying" => Ok(Type::Simple(PrimitiveType::BitVarying(0))),
            "boolean" => Ok(Type::Simple(PrimitiveType::Boolean)),
            "box" => Ok(Type::Simple(PrimitiveType::Box)),
            "bytea" => Ok(Type::Simple(PrimitiveType::Bytea)),
            "character" | "char" => Ok(Type::Simple(PrimitiveType::Character(0))),
            "character varying" | "varchar" => Ok(Type::Simple(PrimitiveType::CharacterVarying(0))),
            "cidr" => Ok(Type::Simple(PrimitiveType::Cidr)),
            "circle" => Ok(Type::Simple(PrimitiveType::Circle)),
            "date" => Ok(Type::Simple(PrimitiveType::Date)),
            "double precision" => Ok(Type::Simple(PrimitiveType::DoublePrecision)),
            "inet" => Ok(Type::Simple(PrimitiveType::Inet)),
            "integer" | "int" => Ok(Type::Simple(PrimitiveType::Integer)),
            "interval" => Ok(Type::Simple(PrimitiveType::Interval)),
            "json" => Ok(Type::Simple(PrimitiveType::Json)),
            "jsonb" => Ok(Type::Simple(PrimitiveType::Jsonb)),
            "line" => Ok(Type::Simple(PrimitiveType::Line)),
            "lseg" => Ok(Type::Simple(PrimitiveType::LSeg)),
            "macaddr" => Ok(Type::Simple(PrimitiveType::Macaddr)),
            "macaddr8" => Ok(Type::Simple(PrimitiveType::Macaddr8)),
            "money" => Ok(Type::Simple(PrimitiveType::Money)),
            "numeric" | "decimal" => Ok(Type::Simple(PrimitiveType::Numeric(0, 0))),
            "path" => Ok(Type::Simple(PrimitiveType::Path)),
            "point" => Ok(Type::Simple(PrimitiveType::Point)),
            "polygon" => Ok(Type::Simple(PrimitiveType::Polygon)),
            "real" => Ok(Type::Simple(PrimitiveType::Real)),
            "smallint" | "int2" => Ok(Type::Simple(PrimitiveType::Smallint)),
            "smallserial" | "serial2" => Ok(Type::Simple(PrimitiveType::Smallserial)),
            "text" => Ok(Type::Simple(PrimitiveType::Text)),
            "time" => Ok(Type::Simple(PrimitiveType::Time)),
            "time with timezone" | "timetz" => Ok(Type::Simple(PrimitiveType::TimeWithTimezone)),
            "timestamp" => Ok(Type::Simple(PrimitiveType::Timestamp)),
            "timestamp without time zone" | "timestamptz" => {
                Ok(Type::Simple(PrimitiveType::TimestampWithTimezone))
            }
            "tsquery" => Ok(Type::Simple(PrimitiveType::TsQuery)),
            "tsvector" => Ok(Type::Simple(PrimitiveType::TsVector)),
            "txid_snapshot" => Ok(Type::Simple(PrimitiveType::TxIdSnapshot)),
            "uuid" => Ok(Type::Simple(PrimitiveType::Uuid)),
            "xml" => Ok(Type::Simple(PrimitiveType::Xml)),
            _ => Err(value.to_string()),
        }
    }
}

#[derive(Debug, Clone)]
pub struct CompositeField {
    name: String,
    r#type: Type,
}

impl CompositeField {
    pub fn new(name: String, type_: Type) -> Self {
        Self {
            name,
            r#type: type_,
        }
    }

    pub fn name(&self) -> &str {
        &self.name
    }

    pub fn r#type(&self) -> &Type {
        &self.r#type
    }
}

#[derive(Debug, Clone, Copy)]
pub enum PrimitiveType {
    Bigint,
    Bigserial,
    Bit(usize),
    BitVarying(usize),
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
