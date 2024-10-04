CREATE SCHEMA kepalbumok;
SET search_path TO kepalbumok;
CREATE TABLE Helyszin (
    telepules VARCHAR(255) NOT NULL,
    megye VARCHAR(255) NOT NULL,
    orszag VARCHAR(255) NOT NULL,
    PRIMARY KEY (megye, telepules)
);
CREATE TABLE Kategoria (
    kategoria_id SERIAL PRIMARY KEY,
    nev VARCHAR(63) NOT NULL UNIQUE
);
CREATE TABLE Felhasznalo (
    email VARCHAR(255) NOT NULL PRIMARY KEY,
    nev VARCHAR(63) NOT NULL UNIQUE,
    jelszo VARCHAR(72) NOT NULL,
    szerepkor VARCHAR(20) NOT NULL,
    megye VARCHAR(255),
    telepules VARCHAR(255),
    kategoria_id INT,
    profil_ertekeles INT DEFAULT 0,
    FOREIGN KEY (megye, telepules) REFERENCES Helyszin (megye, telepules) ON DELETE
    SET NULL,
        FOREIGN KEY (kategoria_id) REFERENCES Kategoria (kategoria_id) ON DELETE
    SET NULL,
        CONSTRAINT szerepkor_c CHECK (szerepkor IN ('USER', 'ADMIN'))
);
CREATE TABLE Palyazat (
    palyazat_id SERIAL PRIMARY KEY,
    cim VARCHAR(127) NOT NULL,
    hatarido DATE NOT NULL,
    kep_id INT
);
CREATE TABLE Kep (
    kep_id SERIAL PRIMARY KEY,
    cim VARCHAR(255) NOT NULL,
    eleresi_ut CHAR(36) NOT NULL UNIQUE,
    email VARCHAR(255) NOT NULL,
    telepules VARCHAR(255) NOT NULL,
    megye VARCHAR(255) NOT NULL,
    datum TIMESTAMP NOT NULL,
    palyazat_id INT,
    FOREIGN KEY (megye, telepules) REFERENCES Helyszin (megye, telepules) ON DELETE
    SET NULL,
        FOREIGN KEY (email) REFERENCES Felhasznalo (email) ON DELETE
    SET NULL
);
ALTER TABLE Kep
ADD FOREIGN KEY (palyazat_id) REFERENCES Palyazat (palyazat_id) ON DELETE
SET NULL;
ALTER TABLE Palyazat
ADD FOREIGN KEY (kep_id) REFERENCES Kep (kep_id) ON DELETE CASCADE;
CREATE TABLE Megjegyzes (
    megjegyzes_id SERIAL PRIMARY KEY,
    datum TIMESTAMP NOT NULL,
    tartalom VARCHAR(511) NOT NULL,
    email VARCHAR(255) NOT NULL,
    kep_id INT NOT NULL,
    FOREIGN KEY (email) REFERENCES Felhasznalo (email) ON DELETE
    SET NULL,
        FOREIGN KEY (kep_id) REFERENCES Kep (kep_id) ON DELETE CASCADE
);
CREATE TABLE Tartozik (
    kep_id INT NOT NULL,
    kategoria_id INT NOT NULL,
    FOREIGN KEY (kep_id) REFERENCES Kep (kep_id) ON DELETE CASCADE,
    FOREIGN KEY (kategoria_id) REFERENCES Kategoria (kategoria_id) ON DELETE CASCADE
);
CREATE TABLE Ertekeles (
    ertekeles_id SERIAL PRIMARY KEY,
    pontszam SMALLINT NOT NULL,
    email VARCHAR(255) NOT NULL,
    kep_id INT NOT NULL,
    FOREIGN KEY (email) REFERENCES Felhasznalo (email) ON DELETE CASCADE,
    FOREIGN KEY (kep_id) REFERENCES Kep (kep_id) ON DELETE CASCADE,
    CONSTRAINT pontszam_c CHECK (pontszam IN (-1, 1))
);
-- DROP TABLE Ertekeles CASCADE;
-- DROP TABLE Felhasznalo CASCADE;
-- DROP TABLE Helyszin CASCADE;
-- DROP TABLE Kategoria CASCADE;
-- DROP TABLE Kep CASCADE;
-- DROP TABLE Megjegyzes CASCADE;
-- DROP TABLE Megjegyzes_bkp CASCADE;
-- DROP TABLE Palyazat CASCADE;
-- DROP TABLE Tartozik CASCADE;
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Debrecen', 'Hajdú-Bihar', 'Magyarország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES (
        'Miskolc',
        'Borsod-Abaúj-Zemplén',
        'Magyarország'
    );
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Szeged', 'Csongrád', 'Magyarország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Pécs', 'Baranya', 'Magyarország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Győr', 'Győr-Moson-Sopron', 'Magyarország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Székesfehérvár', 'Fejér', 'Magyarország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Szombathely', 'Vas', 'Magyarország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Kecskemét', 'Bács-Kiskun', 'Magyarország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES (
        'Nyíregyháza',
        'Szabolcs-Szatmár-Bereg',
        'Magyarország'
    );
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Eger', 'Heves', 'Magyarország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Pilis', 'Pest', 'Magyarország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Cegléd', 'Pest', 'Magyarország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Budapest', 'Pest', 'Magyarország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Siófok', 'Somogy', 'Magyarország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Misurina', 'Belluno', 'Olaszország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Baja', 'Bács-Kiskun', 'Magyarország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Veszprém', 'Veszprém', 'Magyarország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Szekszárd', 'Tolna', 'Magyarország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Dunaújváros', 'Fejér', 'Magyarország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Tatabánya', 'Komárom-Esztergom', 'Magyarország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Esztergom', 'Komárom-Esztergom', 'Magyarország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Berlin', 'Berlin', 'Németország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('London', 'London', 'Egyesült Királyság');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('New York', 'New York', 'Egyesült Államok');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Párizs', 'Île-de-France', 'Franciaország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Róma', 'Lazio', 'Olaszország');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Peking', 'Peking', 'Kína');
INSERT INTO Helyszin (telepules, megye, orszag)
VALUES ('Moszkva', 'Moszkva', 'Oroszország');
INSERT INTO Kategoria (nev)
VALUES ('Természetkép');
INSERT INTO Kategoria (nev)
VALUES ('Portré');
INSERT INTO Kategoria (nev)
VALUES ('Absztrakt');
INSERT INTO Kategoria (nev)
VALUES ('Étel');
INSERT INTO Kategoria (nev)
VALUES ('Fikció');
INSERT INTO Kategoria (nev)
VALUES ('Építészet');
INSERT INTO Kategoria (nev)
VALUES ('Szépművészet');
INSERT INTO Kategoria (nev)
VALUES ('Állat');
INSERT INTO Kategoria (nev)
VALUES ('Divat');
INSERT INTO Kategoria (nev)
VALUES ('Járművek');
INSERT INTO Kategoria (nev)
VALUES ('Történelem');
INSERT INTO Kategoria (nev)
VALUES ('Utazás');
INSERT INTO Kategoria (nev)
VALUES ('Fantázia');
INSERT INTO Kategoria (nev)
VALUES ('Makro');
INSERT INTO Kategoria (nev)
VALUES ('Városi');
INSERT INTO Kategoria (nev)
VALUES ('Sport');
INSERT INTO Felhasznalo (
        email,
        nev,
        jelszo,
        szerepkor,
        megye,
        telepules,
        kategoria_id
    )
VALUES (
        'vjanos@gmail.com',
        'Valaki János',
        '$2a$12$hZmSO/jllVwjcYXJmukqGee5N1tYUnGdTbPbwiTX201wJd2ZOlacu',
        'USER',
        'Pest',
        'Budapest',
        NULL
    );
INSERT INTO Felhasznalo (
        email,
        nev,
        jelszo,
        szerepkor,
        megye,
        telepules,
        kategoria_id
    )
VALUES (
        'mvsandor@gmail.com',
        'Másvalaki Sándor',
        '$2a$12$oRYypAlI6napQuISkQN6ieYwQYq2ztB37eOllTWa7e7lY.2TaWr7m',
        'USER',
        'Csongrád',
        'Szeged',
        NULL
    );
INSERT INTO Felhasznalo (
        email,
        nev,
        jelszo,
        szerepkor,
        megye,
        telepules,
        kategoria_id
    )
VALUES (
        'mmmarta@gmail.com',
        'Megintmás Márta',
        '$2a$12$KJgRGYRGIWSQhrAg5p2Lou7cV6dojGki72JPX0nR1fbC6iSeosbKO',
        'USER',
        'Baranya',
        'Pécs',
        NULL
    );
INSERT INTO Felhasznalo (
        email,
        nev,
        jelszo,
        szerepkor,
        megye,
        telepules,
        kategoria_id
    )
VALUES (
        'nmtdmarton@gmail.com',
        'Nemtudom Márton',
        '$2a$12$/xJNgIn1rcrtPcuxnqbireh6k7uWsLHPb5Oo7LsHx.9YlX6CoQJN2',
        'USER',
        'Pest',
        'Cegléd',
        NULL
    );
INSERT INTO Felhasznalo (
        email,
        nev,
        jelszo,
        szerepkor,
        megye,
        telepules,
        kategoria_id
    )
VALUES (
        'teszte@gmail.com',
        'Teszt Elek',
        '$2a$12$L7vXe9EGeYOna6R3ls5jIOj.AupnlxBlxZbVq9WLNFmHanZLiM05W',
        'USER',
        'Hajdú-Bihar',
        'Debrecen',
        NULL
    );
INSERT INTO Felhasznalo (
        email,
        nev,
        jelszo,
        szerepkor,
        megye,
        telepules,
        kategoria_id
    )
VALUES (
        'admina@gmail.com',
        'Admin Andor',
        '$2a$12$5IIav1ue2LwKsjgmWxvFiO4aguKp2CWyYy62D31t20lGrLcM3mNe6',
        'ADMIN',
        'Pest',
        'Budapest',
        NULL
    );
INSERT INTO Felhasznalo (
        email,
        nev,
        jelszo,
        szerepkor,
        megye,
        telepules,
        kategoria_id
    )
VALUES (
        'adminb@gmail.com',
        'Teszt Béla',
        '$2a$12$dSzQjh90Voo3.Qd9sBVLF.omXJMLDvG8yNB7oqIWrtn4eEozpeY/G',
        'ADMIN',
        'Fejér',
        'Székesfehérvár',
        NULL
    );
INSERT INTO Felhasznalo (
        email,
        nev,
        jelszo,
        szerepkor,
        megye,
        telepules,
        kategoria_id
    )
VALUES (
        'kbela@gmail.com',
        'Kovács Béla',
        '$2a$14$TpRTzP67M/.VtstiFp.JQejqIwTxnVuKa3irLxH2xdc8pxVLUbKYi',
        'USER',
        'Pest',
        'Budapest',
        NULL
    );
INSERT INTO Felhasznalo (
        email,
        nev,
        jelszo,
        szerepkor,
        megye,
        telepules,
        kategoria_id
    )
VALUES (
        'npeter@gmail.com',
        'Nagy Péter',
        '$2a$14$zjduGelQr5svkjYX8tOAe.uzu7VsIdOKKb37uJS4LvVcPjFwxeX1u',
        'USER',
        'Hajdú-Bihar',
        'Debrecen',
        NULL
    );
INSERT INTO Felhasznalo (
        email,
        nev,
        jelszo,
        szerepkor,
        megye,
        telepules,
        kategoria_id
    )
VALUES (
        'kanna@gmail.com',
        'Kis Anna',
        '$2a$14$7TPHnSJH5MxNznGLXOcy/eRXh3N62mfe5id48bNpmwCRnPHMiE8P6',
        'USER',
        'Csongrád',
        'Szeged',
        NULL
    );
INSERT INTO Felhasznalo (
        email,
        nev,
        jelszo,
        szerepkor,
        megye,
        telepules,
        kategoria_id
    )
VALUES (
        'ngabor@gmail.com',
        'Nagy Gábor',
        '$2a$14$nrWs71asK/GiA0a9V1.bYebFpzyejSwC.9oOq/l1..CxLm.3w4dqW',
        'USER',
        'Baranya',
        'Pécs',
        NULL
    );
INSERT INTO Felhasznalo (
        email,
        nev,
        jelszo,
        szerepkor,
        megye,
        telepules,
        kategoria_id
    )
VALUES (
        'keszter@gmail.com',
        'Kis Eszter',
        '$2a$14$eh5fblKNsHhdoaxlqVZ2bub/loLU0U2jNXanEH62MCEzwaiyID0gO',
        'USER',
        'Borsod-Abaúj-Zemplén',
        'Miskolc',
        NULL
    );
INSERT INTO Felhasznalo (
        email,
        nev,
        jelszo,
        szerepkor,
        megye,
        telepules,
        kategoria_id
    )
VALUES (
        'njanos@gmail.com',
        'Nagy János',
        '$2a$14$W3VldHdsmmLijd2MF2ik.OntucTbAoqIwy4pSNIAOlbL8mxvFIyyG',
        'USER',
        'Győr-Moson-Sopron',
        'Győr',
        NULL
    );
INSERT INTO Kep (cim, eleresi_ut, email, telepules, megye, datum)
VALUES (
        'Egy francia nemes',
        '6457d72c-05a7-4a04-b3e9-7c6ed964f0ff',
        'vjanos@gmail.com',
        'Budapest',
        'Pest',
        CURRENT_TIMESTAMP
    );
INSERT INTO Kep (cim, eleresi_ut, email, telepules, megye, datum)
VALUES (
        'Téli séta',
        '3f3db642-0a90-40f0-92fc-3659b7cb6f90',
        'mvsandor@gmail.com',
        'Pilis',
        'Pest',
        CURRENT_TIMESTAMP
    );
INSERT INTO Kep (cim, eleresi_ut, email, telepules, megye, datum)
VALUES (
        'ADnD szabálykönyv',
        'efaaff29-ed72-491c-b91f-8ea2ae3dafbf',
        'teszte@gmail.com',
        'Debrecen',
        'Hajdú-Bihar',
        CURRENT_TIMESTAMP
    );
INSERT INTO Kep (cim, eleresi_ut, email, telepules, megye, datum)
VALUES (
        'Egy helyi templom',
        '8f55f998-34ac-4edc-8f33-b3b5d3d3d129',
        'mmmarta@gmail.com',
        'Pécs',
        'Baranya',
        CURRENT_TIMESTAMP
    );
INSERT INTO Kep (cim, eleresi_ut, email, telepules, megye, datum)
VALUES (
        'Ballagási torta',
        'ca1cf606-752b-4f3a-8a96-68737ce6fecb',
        'kanna@gmail.com',
        'Siófok',
        'Somogy',
        CURRENT_TIMESTAMP
    );
INSERT INTO Kep (cim, eleresi_ut, email, telepules, megye, datum)
VALUES (
        'Balatoni nyár',
        'f5070146-0300-4d90-9f21-a06166e5d5d8',
        'keszter@gmail.com',
        'Siófok',
        'Somogy',
        CURRENT_TIMESTAMP
    );
INSERT INTO Kep (cim, eleresi_ut, email, telepules, megye, datum)
VALUES (
        'Szegedu új zsinagóga',
        'c25f4e67-ac64-4175-b470-56f18c26b4f3',
        'npeter@gmail.com',
        'Szeged',
        'Csongrád',
        CURRENT_TIMESTAMP
    );
INSERT INTO Kep (cim, eleresi_ut, email, telepules, megye, datum)
VALUES (
        'Kutyus',
        '262fb830-f34c-43a1-90ac-240dbcf88161',
        'kbela@gmail.com',
        'Siófok',
        'Somogy',
        CURRENT_TIMESTAMP
    );
INSERT INTO Kep (cim, eleresi_ut, email, telepules, megye, datum)
VALUES (
        'Tre Cime Di Laverdo',
        'f94035d1-d29a-4672-b08f-23d5e2013d7a',
        'njanos@gmail.com',
        'Misurina',
        'Belluno',
        CURRENT_TIMESTAMP
    );
INSERT INTO Kep (cim, eleresi_ut, email, telepules, megye, datum)
VALUES (
        'Vizslatámadás',
        'b1022687-4856-4698-8345-a7d99c8f5722',
        'kanna@gmail.com',
        'Kecskemét',
        'Bács-Kiskun',
        CURRENT_TIMESTAMP
    );
INSERT INTO Kep (cim, eleresi_ut, email, telepules, megye, datum)
VALUES (
        'Berlin városa',
        '9b5e3336-83f2-42ee-8397-fe1ee6206fc2',
        'npeter@gmail.com',
        'Berlin',
        'Berlin',
        CURRENT_TIMESTAMP
    );
INSERT INTO Kep (cim, eleresi_ut, email, telepules, megye, datum)
VALUES (
        'London és a Big Ben',
        'bc274d62-1982-47aa-aa1a-6a1b9c034e7c',
        'vjanos@gmail.com',
        'London',
        'London',
        CURRENT_TIMESTAMP
    );
INSERT INTO Kep (cim, eleresi_ut, email, telepules, megye, datum)
VALUES (
        'New York-i fények este',
        '790a4d1d-dc5b-4f93-bba6-fcbeb3bbe8bb',
        'mmmarta@gmail.com',
        'New York',
        'New York',
        CURRENT_TIMESTAMP
    );
INSERT INTO Kep (cim, eleresi_ut, email, telepules, megye, datum)
VALUES (
        'Az Eiffel-torony',
        '5c9549d9-9118-46d9-add4-0bfcd4f4e0c6',
        'adminb@gmail.com',
        'Párizs',
        'Île-de-France',
        CURRENT_TIMESTAMP
    );
INSERT INTO Kep (cim, eleresi_ut, email, telepules, megye, datum)
VALUES (
        'Római Kolosszeum',
        'ba674396-ba5d-49f3-a1ba-9cd64f78e388',
        'admina@gmail.com',
        'Róma',
        'Lazio',
        CURRENT_TIMESTAMP
    );
INSERT INTO Kep (cim, eleresi_ut, email, telepules, megye, datum)
VALUES (
        'Peking városa este',
        '22f1bc36-0998-44c9-8895-2007ca2943af',
        'teszte@gmail.com',
        'Peking',
        'Peking',
        CURRENT_TIMESTAMP
    );
INSERT INTO Kep (cim, eleresi_ut, email, telepules, megye, datum)
VALUES (
        'Moszkva napnyugtakor',
        '17a02d6b-447a-44e2-8266-11291fbe4835',
        'keszter@gmail.com',
        'Moszkva',
        'Moszkva',
        CURRENT_TIMESTAMP
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Ez nagyon jó.',
        'vjanos@gmail.com',
        1
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Nagyon tetszik!',
        'mvsandor@gmail.com',
        1
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Imádom!',
        'mmmarta@gmail.com',
        2
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Szuper!',
        'nmtdmarton@gmail.com',
        4
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Láttam jobbat is.',
        'teszte@gmail.com',
        2
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Imádom!',
        'nmtdmarton@gmail.com',
        3
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'WOW!',
        'mmmarta@gmail.com',
        4
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Nagyon szép!',
        'mvsandor@gmail.com',
        5
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Csodálatos kép!',
        'kanna@gmail.com',
        6
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Remek fotó!',
        'ngabor@gmail.com',
        7
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Aranyos!',
        'njanos@gmail.com',
        8
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Fantasztikus látvány!',
        'ngabor@gmail.com',
        9
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Cuki!',
        'ngabor@gmail.com',
        10
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Nagyon szép!',
        'vjanos@gmail.com',
        1
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Imádom!',
        'mvsandor@gmail.com',
        1
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Fantasztikus!',
        'mmmarta@gmail.com',
        2
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Csodálatos!',
        'nmtdmarton@gmail.com',
        4
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Nagyon jó munka!',
        'teszte@gmail.com',
        2
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Szép munka!',
        'nmtdmarton@gmail.com',
        3
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Elképesztő!',
        'mmmarta@gmail.com',
        4
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Nagyon tetszik a kompozíció!',
        'mvsandor@gmail.com',
        5
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Nagyon szép!',
        'kanna@gmail.com',
        6
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Fantasztikus!',
        'ngabor@gmail.com',
        7
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Aranyos kép!',
        'njanos@gmail.com',
        8
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Egy csodálatos pillanat!',
        'ngabor@gmail.com',
        9
    );
INSERT INTO Megjegyzes (datum, tartalom, email, kep_id)
VALUES (
        CURRENT_TIMESTAMP,
        'Nagyon cuki!',
        'ngabor@gmail.com',
        10
    );
INSERT INTO Tartozik (kep_id, kategoria_id)
VALUES (1, 7);
INSERT INTO Tartozik (kep_id, kategoria_id)
VALUES (2, 1);
INSERT INTO Tartozik (kep_id, kategoria_id)
VALUES (3, 5);
INSERT INTO Tartozik (kep_id, kategoria_id)
VALUES (4, 6);
INSERT INTO Tartozik (kep_id, kategoria_id)
VALUES (5, 4);
INSERT INTO Tartozik (kep_id, kategoria_id)
VALUES (6, 1);
INSERT INTO Tartozik (kep_id, kategoria_id)
VALUES (7, 6);
INSERT INTO Tartozik (kep_id, kategoria_id)
VALUES (8, 8);
INSERT INTO Tartozik (kep_id, kategoria_id)
VALUES (9, 1);
INSERT INTO Tartozik (kep_id, kategoria_id)
VALUES (10, 8);
INSERT INTO Ertekeles (pontszam, email, kep_id)
VALUES (1, 'mmmarta@gmail.com', 1);
INSERT INTO Ertekeles (pontszam, email, kep_id)
VALUES (1, 'mvsandor@gmail.com', 2);
INSERT INTO Ertekeles (pontszam, email, kep_id)
VALUES (1, 'nmtdmarton@gmail.com', 1);
INSERT INTO Ertekeles (pontszam, email, kep_id)
VALUES (-1, 'admina@gmail.com', 3);
INSERT INTO Ertekeles (pontszam, email, kep_id)
VALUES (-1, 'adminb@gmail.com', 4);
INSERT INTO Ertekeles (pontszam, email, kep_id)
VALUES (1, 'mvsandor@gmail.com', 5);
INSERT INTO Ertekeles (pontszam, email, kep_id)
VALUES (1, 'kanna@gmail.com', 6);
INSERT INTO Ertekeles (pontszam, email, kep_id)
VALUES (1, 'ngabor@gmail.com', 7);
INSERT INTO Ertekeles (pontszam, email, kep_id)
VALUES (1, 'kanna@gmail.com', 8);
INSERT INTO Ertekeles (pontszam, email, kep_id)
VALUES (1, 'njanos@gmail.com', 9);
INSERT INTO Ertekeles (pontszam, email, kep_id)
VALUES (1, 'kanna@gmail.com', 10);
INSERT INTO Ertekeles (pontszam, email, kep_id)
VALUES (1, 'mvsandor@gmail.com', 1);
INSERT INTO Ertekeles (pontszam, email, kep_id)
VALUES (1, 'mmmarta@gmail.com', 2);
INSERT INTO Ertekeles (pontszam, email, kep_id)
VALUES (-1, 'vjanos@gmail.com', 3);
INSERT INTO Ertekeles (pontszam, email, kep_id)
VALUES (-1, 'vjanos@gmail.com', 4);
INSERT INTO Ertekeles (pontszam, email, kep_id)
VALUES (1, 'nmtdmarton@gmail.com', 5);
INSERT INTO Ertekeles (pontszam, email, kep_id)
VALUES (-1, 'mvsandor@gmail.com', 6);
INSERT INTO Ertekeles (pontszam, email, kep_id)
VALUES (1, 'teszte@gmail.com', 7);
INSERT INTO Ertekeles (pontszam, email, kep_id)
VALUES (-1, 'teszte@gmail.com', 8);
INSERT INTO Ertekeles (pontszam, email, kep_id)
VALUES (1, 'admina@gmail.com', 9);
INSERT INTO Ertekeles (pontszam, email, kep_id)
VALUES (1, 'adminb@gmail.com', 10);
INSERT INTO Palyazat (cim, hatarido, kep_id)
VALUES (
        'Legjobb természetkép',
        TO_DATE('2024-12-31', 'YYYY-MM-DD'),
        NULL
    );
INSERT INTO Palyazat (cim, hatarido, kep_id)
VALUES (
        'Legjobb portré',
        TO_DATE('2024-10-11', 'YYYY-MM-DD'),
        NULL
    );
INSERT INTO Palyazat (cim, hatarido, kep_id)
VALUES (
        'Legjobb absztrakt kép',
        TO_DATE('2024-05-07', 'YYYY-MM-DD'),
        NULL
    );
INSERT INTO Palyazat (cim, hatarido, kep_id)
VALUES (
        'Legjobban kinéző étel',
        TO_DATE('2024-06-07', 'YYYY-MM-DD'),
        NULL
    );
INSERT INTO Palyazat (cim, hatarido, kep_id)
VALUES (
        'Legjobb fiktív tartalmat ábrázoló kép',
        TO_DATE('2025-11-19', 'YYYY-MM-DD'),
        NULL
    );
INSERT INTO Palyazat (cim, hatarido, kep_id)
VALUES (
        'Legjobb építészeti kép',
        TO_DATE('2024-09-28', 'YYYY-MM-DD'),
        NULL
    );
INSERT INTO Palyazat (cim, hatarido, kep_id)
VALUES (
        'Legjobb városi pillanatok',
        TO_DATE('2024-10-28', 'YYYY-MM-DD'),
        NULL
    );
INSERT INTO Palyazat (cim, hatarido, kep_id)
VALUES (
        'Kulturális örökségünk',
        TO_DATE('2024-10-18', 'YYYY-MM-DD'),
        NULL
    );
INSERT INTO Palyazat (cim, hatarido, kep_id)
VALUES (
        'Legjobb makró fotó',
        TO_DATE('2024-07-15', 'YYYY-MM-DD'),
        NULL
    );
INSERT INTO Palyazat (cim, hatarido, kep_id)
VALUES (
        'Legjobb fekete-fehér kép',
        TO_DATE('2024-08-20', 'YYYY-MM-DD'),
        NULL
    );
INSERT INTO Palyazat (cim, hatarido, kep_id)
VALUES (
        'Legjobb állatportré',
        TO_DATE('2024-09-05', 'YYYY-MM-DD'),
        NULL
    );
INSERT INTO Palyazat (cim, hatarido, kep_id)
VALUES (
        'Legjobb street photography',
        TO_DATE('2024-11-10', 'YYYY-MM-DD'),
        NULL
    );
INSERT INTO Palyazat (cim, hatarido, kep_id)
VALUES (
        'Legjobb tájkép',
        TO_DATE('2024-12-05', 'YYYY-MM-DD'),
        NULL
    );
INSERT INTO Palyazat (cim, hatarido, kep_id)
VALUES (
        'Legjobb divatfotó',
        TO_DATE('2024-07-25', 'YYYY-MM-DD'),
        NULL
    );
INSERT INTO Palyazat (cim, hatarido, kep_id)
VALUES (
        'Legjobb sportfotó',
        TO_DATE('2024-08-30', 'YYYY-MM-DD'),
        NULL
    );
INSERT INTO Palyazat (cim, hatarido, kep_id)
VALUES (
        'Legjobb ételfotó',
        TO_DATE('2024-09-15', 'YYYY-MM-DD'),
        NULL
    );
INSERT INTO Palyazat (cim, hatarido, kep_id)
VALUES (
        'Legjobb utcai művészet fotója',
        TO_DATE('2024-11-20', 'YYYY-MM-DD'),
        NULL
    );
INSERT INTO Palyazat (cim, hatarido, kep_id)
VALUES (
        'Legjobb naplemente kép',
        TO_DATE('2024-12-10', 'YYYY-MM-DD'),
        NULL
    );
INSERT INTO Palyazat (cim, hatarido, kep_id)
VALUES (
        'A legcukibb kisállat',
        TO_DATE('2024-08-08', 'YYYY-MM-DD'),
        NULL
    );
INSERT INTO Palyazat (cim, hatarido, kep_id)
VALUES (
        'A legdivatosabb ruhadarab',
        TO_DATE('2024-10-11', 'YYYY-MM-DD'),
        NULL
    );
INSERT INTO Palyazat (cim, hatarido, kep_id)
VALUES (
        'Egy darab történelem',
        TO_DATE('2024-06-09', 'YYYY-MM-DD'),
        NULL
    );