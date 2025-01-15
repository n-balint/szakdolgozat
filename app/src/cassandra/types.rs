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
