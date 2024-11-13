CREATE KEYSPACE dolgozoi_adatok WITH replication = {'class': 'SimpleStrategy', 'replication_factor': '1'};

CREATE TABLE dolgozoi_adatok.nyilvantartas (
    nev TEXT PRIMARY KEY,
    adoszam INT,
    cim TEXT,
    osztalykod INT,
    osztalynev TEXT,
    vez_adoszam INT,
);
