#[derive(Debug, Clone, Copy)]
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

#[derive(Debug, Clone)]
pub enum CollectionType {
    List(Box<Type>),
    Map(Box<Type>, Box<Type>),
    Set(Box<Type>),
}

#[derive(Debug, Clone)]
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
