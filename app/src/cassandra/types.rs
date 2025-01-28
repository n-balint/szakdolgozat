use crate::postgres::types::{PrimitiveType as PostgresPrimitve, Type as PType};

#[derive(Debug, Clone, Copy, Hash, PartialEq, Eq)]
pub enum PrimitiveType {
    Ascii,
    Bigint,
    Blob,
    Boolean,
    Counter,
    Date,
    Decimal,
    Double,
    Duration,
    Float,
    Inet,
    Int,
    Smallint,
    Text,
    Time,
    Timestamp,
    TimeUuid,
    Tinyint,
    Uuid,
    Varchar,
    Varint,
}

impl From<PostgresPrimitve> for PrimitiveType {
    fn from(value: PostgresPrimitve) -> Self {
        match value {
            PostgresPrimitve::Bigint => Self::Bigint,
            PostgresPrimitve::Bigserial => Self::Bigint,
            PostgresPrimitve::Bit(_) => Self::Text,
            PostgresPrimitve::BitVarying(_) => Self::Text,
            PostgresPrimitve::Boolean => Self::Boolean,
            PostgresPrimitve::Box => Self::Text,
            PostgresPrimitve::Bytea => Self::Blob,
            PostgresPrimitve::Character(_) => Self::Text,
            PostgresPrimitve::CharacterVarying(_) => Self::Text,
            PostgresPrimitve::Cidr => Self::Inet,
            PostgresPrimitve::Circle => Self::Text,
            PostgresPrimitve::Date => Self::Date,
            PostgresPrimitve::DoublePrecision => Self::Double,
            PostgresPrimitve::Inet => Self::Inet,
            PostgresPrimitve::Integer => Self::Int,
            PostgresPrimitve::Interval => Self::Duration,
            PostgresPrimitve::Json => Self::Text,
            PostgresPrimitve::Jsonb => Self::Text,
            PostgresPrimitve::Line => Self::Text,
            PostgresPrimitve::LSeg => Self::Text,
            PostgresPrimitve::Macaddr => Self::Text,
            PostgresPrimitve::Macaddr8 => Self::Text,
            PostgresPrimitve::Money => Self::Decimal,
            PostgresPrimitve::Numeric(_, _) => Self::Decimal,
            PostgresPrimitve::Path => Self::Text,
            PostgresPrimitve::PgLen => Self::Text,
            PostgresPrimitve::PgSnapshot => Self::Text,
            PostgresPrimitve::Point => Self::Text,
            PostgresPrimitve::Polygon => Self::Text,
            PostgresPrimitve::Real => Self::Float,
            PostgresPrimitve::Smallint => Self::Smallint,
            PostgresPrimitve::Smallserial => Self::Smallint,
            PostgresPrimitve::Serial => Self::Int,
            PostgresPrimitve::Text => Self::Text,
            PostgresPrimitve::Time => Self::Time,
            PostgresPrimitve::TimeWithTimezone => Self::Time,
            PostgresPrimitve::Timestamp => Self::Timestamp,
            PostgresPrimitve::TimestampWithTimezone => Self::Timestamp,
            PostgresPrimitve::TsQuery => Self::Text,
            PostgresPrimitve::TsVector => Self::Text,
            PostgresPrimitve::TxIdSnapshot => Self::Text,
            PostgresPrimitve::Uuid => Self::Uuid,
            PostgresPrimitve::Xml => Self::Text,
        }
    }
}

impl From<PType> for Type {
    fn from(value: PType) -> Self {
        match value {
            PType::Simple(primitive_type) => Self::Primitive(primitive_type.into()),
            PType::Composite(name) => Self::Udt {
                frozen: false,
                name,
                keyspace: "".to_string(),
            },
            PType::Array(primitive_type) => Self::Collection {
                frozen: false,
                r#type: CollectionType::List(Box::new(Type::Primitive(primitive_type.into()))),
            },
            PType::Enum(_) => Self::Primitive(PrimitiveType::Text),
        }
    }
}

#[derive(Debug, Clone, Hash, PartialEq, Eq)]
pub enum CollectionType {
    List(Box<Type>),
    Map(Box<Type>, Box<Type>),
    Set(Box<Type>),
}

#[derive(Debug, Clone, Hash, PartialEq, Eq)]
pub enum Type {
    Primitive(PrimitiveType),
    Collection {
        frozen: bool,
        r#type: CollectionType,
    },
    Tuple(Vec<Type>),
    Udt {
        frozen: bool,
        name: String,
        keyspace: String,
    },
}

impl TryFrom<&str> for PrimitiveType {
    type Error = ();
    fn try_from(value: &str) -> Result<Self, Self::Error> {
        match &value.to_uppercase()[..] {
            "ASCII" => Ok(Self::Ascii),
            "BIGINT" => Ok(Self::Bigint),
            "BLOB" => Ok(Self::Blob),
            "BOOLEAN" => Ok(Self::Boolean),
            "COUNTER" => Ok(Self::Counter),
            "DATE" => Ok(Self::Date),
            "DECIMAL" => Ok(Self::Decimal),
            "DOUBLE" => Ok(Self::Double),
            "DURATION" => Ok(Self::Duration),
            "FLOAT" => Ok(Self::Float),
            "INET" => Ok(Self::Inet),
            "INT" => Ok(Self::Int),
            "SMALLINT" => Ok(Self::Smallint),
            "TEXT" => Ok(Self::Text),
            "TIME" => Ok(Self::Time),
            "TIMESTAMP" => Ok(Self::Timestamp),
            "TIMEUUID" => Ok(Self::TimeUuid),
            "TINYINT" => Ok(Self::Tinyint),
            "UUID" => Ok(Self::Uuid),
            "VARCHAR" => Ok(Self::Varchar),
            "VARINT" => Ok(Self::Varint),
            _ => Err(()),
        }
    }
}

impl std::fmt::Display for PrimitiveType {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", format!("{:?}", self).to_uppercase())
    }
}

impl std::fmt::Display for CollectionType {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "{}",
            Type::Collection {
                frozen: false,
                r#type: self.clone()
            }
        )
    }
}

impl std::fmt::Display for Type {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Self::Primitive(x) => write!(f, "{}", x),
            Self::Tuple(x) => {
                let list = x
                    .iter()
                    .map(|elem| format!("{}", elem))
                    .collect::<Vec<_>>()
                    .join(",");

                write!(f, "tuple<{}>", list)
            }
            Self::Udt {
                frozen,
                name,
                keyspace,
                ..
            } => match frozen {
                true => write!(f, "frozen<{}.{}>", keyspace, name),
                false => write!(f, "{}.{}", keyspace, name),
            },
            Self::Collection { frozen, r#type } => match frozen {
                true => match r#type {
                    CollectionType::Map(k, v) => {
                        write!(f, "frozen<map<{}, {}>>", k, v)
                    }
                    CollectionType::Set(item) => {
                        write!(f, "frozen<set<{}>>", item)
                    }
                    CollectionType::List(item) => {
                        write!(f, "frozen<list<{}>>", item)
                    }
                },
                false => match r#type {
                    CollectionType::Map(k, v) => {
                        write!(f, "map<{}, {}>", k, v)
                    }
                    CollectionType::Set(item) => {
                        write!(f, "set<{}>", item)
                    }
                    CollectionType::List(item) => {
                        write!(f, "list<{}>", item)
                    }
                },
            },
        }
    }
}
