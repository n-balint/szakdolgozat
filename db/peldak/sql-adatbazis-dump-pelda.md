# Egy postgres dump

Használt parancs: `pg_dump -U $USERNAME > $OUTFILE`

Kimenet:
```sql
--
-- PostgreSQL database dump
--

-- Dumped from database version 16.4 (Debian 16.4-1.pgdg120+1)
-- Dumped by pg_dump version 16.3

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: kepalbumok; Type: SCHEMA; Schema: -; Owner: example
--

CREATE SCHEMA kepalbumok;


ALTER SCHEMA kepalbumok OWNER TO example;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: ertekeles; Type: TABLE; Schema: kepalbumok; Owner: example
--

CREATE TABLE kepalbumok.ertekeles (
    ertekeles_id integer NOT NULL,
    pontszam smallint NOT NULL,
    email character varying(255) NOT NULL,
    kep_id integer NOT NULL,
    CONSTRAINT pontszam_c CHECK ((pontszam = ANY (ARRAY['-1'::integer, 1])))
);


ALTER TABLE kepalbumok.ertekeles OWNER TO example;

--
-- Name: ertekeles_ertekeles_id_seq; Type: SEQUENCE; Schema: kepalbumok; Owner: example
--

CREATE SEQUENCE kepalbumok.ertekeles_ertekeles_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE kepalbumok.ertekeles_ertekeles_id_seq OWNER TO example;

--
-- Name: ertekeles_ertekeles_id_seq; Type: SEQUENCE OWNED BY; Schema: kepalbumok; Owner: example
--

ALTER SEQUENCE kepalbumok.ertekeles_ertekeles_id_seq OWNED BY kepalbumok.ertekeles.ertekeles_id;


--
-- Name: felhasznalo; Type: TABLE; Schema: kepalbumok; Owner: example
--

CREATE TABLE kepalbumok.felhasznalo (
    email character varying(255) NOT NULL,
    nev character varying(63) NOT NULL,
    jelszo character varying(72) NOT NULL,
    szerepkor character varying(20) NOT NULL,
    megye character varying(255),
    telepules character varying(255),
    kategoria_id integer,
    profil_ertekeles integer DEFAULT 0,
    CONSTRAINT szerepkor_c CHECK (((szerepkor)::text = ANY ((ARRAY['USER'::character varying, 'ADMIN'::character varying])::text[])))
);


ALTER TABLE kepalbumok.felhasznalo OWNER TO example;

--
-- Name: helyszin; Type: TABLE; Schema: kepalbumok; Owner: example
--

CREATE TABLE kepalbumok.helyszin (
    telepules character varying(255) NOT NULL,
    megye character varying(255) NOT NULL,
    orszag character varying(255) NOT NULL
);


ALTER TABLE kepalbumok.helyszin OWNER TO example;

--
-- Name: kategoria; Type: TABLE; Schema: kepalbumok; Owner: example
--

CREATE TABLE kepalbumok.kategoria (
    kategoria_id integer NOT NULL,
    nev character varying(63) NOT NULL
);


ALTER TABLE kepalbumok.kategoria OWNER TO example;

--
-- Name: kategoria_kategoria_id_seq; Type: SEQUENCE; Schema: kepalbumok; Owner: example
--

CREATE SEQUENCE kepalbumok.kategoria_kategoria_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE kepalbumok.kategoria_kategoria_id_seq OWNER TO example;

--
-- Name: kategoria_kategoria_id_seq; Type: SEQUENCE OWNED BY; Schema: kepalbumok; Owner: example
--

ALTER SEQUENCE kepalbumok.kategoria_kategoria_id_seq OWNED BY kepalbumok.kategoria.kategoria_id;


--
-- Name: kep; Type: TABLE; Schema: kepalbumok; Owner: example
--

CREATE TABLE kepalbumok.kep (
    kep_id integer NOT NULL,
    cim character varying(255) NOT NULL,
    eleresi_ut character(36) NOT NULL,
    email character varying(255) NOT NULL,
    telepules character varying(255) NOT NULL,
    megye character varying(255) NOT NULL,
    datum timestamp without time zone NOT NULL,
    palyazat_id integer
);


ALTER TABLE kepalbumok.kep OWNER TO example;

--
-- Name: kep_kep_id_seq; Type: SEQUENCE; Schema: kepalbumok; Owner: example
--

CREATE SEQUENCE kepalbumok.kep_kep_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE kepalbumok.kep_kep_id_seq OWNER TO example;

--
-- Name: kep_kep_id_seq; Type: SEQUENCE OWNED BY; Schema: kepalbumok; Owner: example
--

ALTER SEQUENCE kepalbumok.kep_kep_id_seq OWNED BY kepalbumok.kep.kep_id;


--
-- Name: megjegyzes; Type: TABLE; Schema: kepalbumok; Owner: example
--

CREATE TABLE kepalbumok.megjegyzes (
    megjegyzes_id integer NOT NULL,
    datum timestamp without time zone NOT NULL,
    tartalom character varying(511) NOT NULL,
    email character varying(255) NOT NULL,
    kep_id integer NOT NULL
);


ALTER TABLE kepalbumok.megjegyzes OWNER TO example;

--
-- Name: megjegyzes_megjegyzes_id_seq; Type: SEQUENCE; Schema: kepalbumok; Owner: example
--

CREATE SEQUENCE kepalbumok.megjegyzes_megjegyzes_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE kepalbumok.megjegyzes_megjegyzes_id_seq OWNER TO example;

--
-- Name: megjegyzes_megjegyzes_id_seq; Type: SEQUENCE OWNED BY; Schema: kepalbumok; Owner: example
--

ALTER SEQUENCE kepalbumok.megjegyzes_megjegyzes_id_seq OWNED BY kepalbumok.megjegyzes.megjegyzes_id;


--
-- Name: palyazat; Type: TABLE; Schema: kepalbumok; Owner: example
--

CREATE TABLE kepalbumok.palyazat (
    palyazat_id integer NOT NULL,
    cim character varying(127) NOT NULL,
    hatarido date NOT NULL,
    kep_id integer
);


ALTER TABLE kepalbumok.palyazat OWNER TO example;

--
-- Name: palyazat_palyazat_id_seq; Type: SEQUENCE; Schema: kepalbumok; Owner: example
--

CREATE SEQUENCE kepalbumok.palyazat_palyazat_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE kepalbumok.palyazat_palyazat_id_seq OWNER TO example;

--
-- Name: palyazat_palyazat_id_seq; Type: SEQUENCE OWNED BY; Schema: kepalbumok; Owner: example
--

ALTER SEQUENCE kepalbumok.palyazat_palyazat_id_seq OWNED BY kepalbumok.palyazat.palyazat_id;


--
-- Name: tartozik; Type: TABLE; Schema: kepalbumok; Owner: example
--

CREATE TABLE kepalbumok.tartozik (
    kep_id integer NOT NULL,
    kategoria_id integer NOT NULL
);


ALTER TABLE kepalbumok.tartozik OWNER TO example;

--
-- Name: ertekeles ertekeles_id; Type: DEFAULT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.ertekeles ALTER COLUMN ertekeles_id SET DEFAULT nextval('kepalbumok.ertekeles_ertekeles_id_seq'::regclass);


--
-- Name: kategoria kategoria_id; Type: DEFAULT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.kategoria ALTER COLUMN kategoria_id SET DEFAULT nextval('kepalbumok.kategoria_kategoria_id_seq'::regclass);


--
-- Name: kep kep_id; Type: DEFAULT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.kep ALTER COLUMN kep_id SET DEFAULT nextval('kepalbumok.kep_kep_id_seq'::regclass);


--
-- Name: megjegyzes megjegyzes_id; Type: DEFAULT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.megjegyzes ALTER COLUMN megjegyzes_id SET DEFAULT nextval('kepalbumok.megjegyzes_megjegyzes_id_seq'::regclass);


--
-- Name: palyazat palyazat_id; Type: DEFAULT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.palyazat ALTER COLUMN palyazat_id SET DEFAULT nextval('kepalbumok.palyazat_palyazat_id_seq'::regclass);


--
-- Data for Name: ertekeles; Type: TABLE DATA; Schema: kepalbumok; Owner: example
--

COPY kepalbumok.ertekeles (ertekeles_id, pontszam, email, kep_id) FROM stdin;
1	1	mmmarta@gmail.com	1
2	1	mvsandor@gmail.com	2
3	1	nmtdmarton@gmail.com	1
4	-1	admina@gmail.com	3
5	-1	adminb@gmail.com	4
6	1	mvsandor@gmail.com	5
7	1	kanna@gmail.com	6
8	1	ngabor@gmail.com	7
9	1	kanna@gmail.com	8
10	1	njanos@gmail.com	9
11	1	kanna@gmail.com	10
12	1	mvsandor@gmail.com	1
13	1	mmmarta@gmail.com	2
14	-1	vjanos@gmail.com	3
15	-1	vjanos@gmail.com	4
16	1	nmtdmarton@gmail.com	5
17	-1	mvsandor@gmail.com	6
18	1	teszte@gmail.com	7
19	-1	teszte@gmail.com	8
20	1	admina@gmail.com	9
21	1	adminb@gmail.com	10
\.


--
-- Data for Name: felhasznalo; Type: TABLE DATA; Schema: kepalbumok; Owner: example
--

COPY kepalbumok.felhasznalo (email, nev, jelszo, szerepkor, megye, telepules, kategoria_id, profil_ertekeles) FROM stdin;
vjanos@gmail.com	Valaki János	$2a$12$hZmSO/jllVwjcYXJmukqGee5N1tYUnGdTbPbwiTX201wJd2ZOlacu	USER	Pest	Budapest	\N	0
mvsandor@gmail.com	Másvalaki Sándor	$2a$12$oRYypAlI6napQuISkQN6ieYwQYq2ztB37eOllTWa7e7lY.2TaWr7m	USER	Csongrád	Szeged	\N	0
mmmarta@gmail.com	Megintmás Márta	$2a$12$KJgRGYRGIWSQhrAg5p2Lou7cV6dojGki72JPX0nR1fbC6iSeosbKO	USER	Baranya	Pécs	\N	0
nmtdmarton@gmail.com	Nemtudom Márton	$2a$12$/xJNgIn1rcrtPcuxnqbireh6k7uWsLHPb5Oo7LsHx.9YlX6CoQJN2	USER	Pest	Cegléd	\N	0
teszte@gmail.com	Teszt Elek	$2a$12$L7vXe9EGeYOna6R3ls5jIOj.AupnlxBlxZbVq9WLNFmHanZLiM05W	USER	Hajdú-Bihar	Debrecen	\N	0
admina@gmail.com	Admin Andor	$2a$12$5IIav1ue2LwKsjgmWxvFiO4aguKp2CWyYy62D31t20lGrLcM3mNe6	ADMIN	Pest	Budapest	\N	0
adminb@gmail.com	Teszt Béla	$2a$12$dSzQjh90Voo3.Qd9sBVLF.omXJMLDvG8yNB7oqIWrtn4eEozpeY/G	ADMIN	Fejér	Székesfehérvár	\N	0
kbela@gmail.com	Kovács Béla	$2a$14$TpRTzP67M/.VtstiFp.JQejqIwTxnVuKa3irLxH2xdc8pxVLUbKYi	USER	Pest	Budapest	\N	0
npeter@gmail.com	Nagy Péter	$2a$14$zjduGelQr5svkjYX8tOAe.uzu7VsIdOKKb37uJS4LvVcPjFwxeX1u	USER	Hajdú-Bihar	Debrecen	\N	0
kanna@gmail.com	Kis Anna	$2a$14$7TPHnSJH5MxNznGLXOcy/eRXh3N62mfe5id48bNpmwCRnPHMiE8P6	USER	Csongrád	Szeged	\N	0
ngabor@gmail.com	Nagy Gábor	$2a$14$nrWs71asK/GiA0a9V1.bYebFpzyejSwC.9oOq/l1..CxLm.3w4dqW	USER	Baranya	Pécs	\N	0
keszter@gmail.com	Kis Eszter	$2a$14$eh5fblKNsHhdoaxlqVZ2bub/loLU0U2jNXanEH62MCEzwaiyID0gO	USER	Borsod-Abaúj-Zemplén	Miskolc	\N	0
njanos@gmail.com	Nagy János	$2a$14$W3VldHdsmmLijd2MF2ik.OntucTbAoqIwy4pSNIAOlbL8mxvFIyyG	USER	Győr-Moson-Sopron	Győr	\N	0
\.


--
-- Data for Name: helyszin; Type: TABLE DATA; Schema: kepalbumok; Owner: example
--

COPY kepalbumok.helyszin (telepules, megye, orszag) FROM stdin;
Debrecen	Hajdú-Bihar	Magyarország
Miskolc	Borsod-Abaúj-Zemplén	Magyarország
Szeged	Csongrád	Magyarország
Pécs	Baranya	Magyarország
Győr	Győr-Moson-Sopron	Magyarország
Székesfehérvár	Fejér	Magyarország
Szombathely	Vas	Magyarország
Kecskemét	Bács-Kiskun	Magyarország
Nyíregyháza	Szabolcs-Szatmár-Bereg	Magyarország
Eger	Heves	Magyarország
Pilis	Pest	Magyarország
Cegléd	Pest	Magyarország
Budapest	Pest	Magyarország
Siófok	Somogy	Magyarország
Misurina	Belluno	Olaszország
Baja	Bács-Kiskun	Magyarország
Veszprém	Veszprém	Magyarország
Szekszárd	Tolna	Magyarország
Dunaújváros	Fejér	Magyarország
Tatabánya	Komárom-Esztergom	Magyarország
Esztergom	Komárom-Esztergom	Magyarország
Berlin	Berlin	Németország
London	London	Egyesült Királyság
New York	New York	Egyesült Államok
Párizs	Île-de-France	Franciaország
Róma	Lazio	Olaszország
Peking	Peking	Kína
Moszkva	Moszkva	Oroszország
\.


--
-- Data for Name: kategoria; Type: TABLE DATA; Schema: kepalbumok; Owner: example
--

COPY kepalbumok.kategoria (kategoria_id, nev) FROM stdin;
1	Természetkép
2	Portré
3	Absztrakt
4	Étel
5	Fikció
6	Építészet
7	Szépművészet
8	Állat
9	Divat
10	Járművek
11	Történelem
12	Utazás
13	Fantázia
14	Makro
15	Városi
16	Sport
\.


--
-- Data for Name: kep; Type: TABLE DATA; Schema: kepalbumok; Owner: example
--

COPY kepalbumok.kep (kep_id, cim, eleresi_ut, email, telepules, megye, datum, palyazat_id) FROM stdin;
1	Egy francia nemes	6457d72c-05a7-4a04-b3e9-7c6ed964f0ff	vjanos@gmail.com	Budapest	Pest	2024-10-04 05:39:59.380414	\N
2	Téli séta	3f3db642-0a90-40f0-92fc-3659b7cb6f90	mvsandor@gmail.com	Pilis	Pest	2024-10-04 05:39:59.380414	\N
3	ADnD szabálykönyv	efaaff29-ed72-491c-b91f-8ea2ae3dafbf	teszte@gmail.com	Debrecen	Hajdú-Bihar	2024-10-04 05:39:59.380414	\N
4	Egy helyi templom	8f55f998-34ac-4edc-8f33-b3b5d3d3d129	mmmarta@gmail.com	Pécs	Baranya	2024-10-04 05:39:59.380414	\N
5	Ballagási torta	ca1cf606-752b-4f3a-8a96-68737ce6fecb	kanna@gmail.com	Siófok	Somogy	2024-10-04 05:39:59.380414	\N
6	Balatoni nyár	f5070146-0300-4d90-9f21-a06166e5d5d8	keszter@gmail.com	Siófok	Somogy	2024-10-04 05:39:59.380414	\N
7	Szegedu új zsinagóga	c25f4e67-ac64-4175-b470-56f18c26b4f3	npeter@gmail.com	Szeged	Csongrád	2024-10-04 05:39:59.380414	\N
8	Kutyus	262fb830-f34c-43a1-90ac-240dbcf88161	kbela@gmail.com	Siófok	Somogy	2024-10-04 05:39:59.380414	\N
9	Tre Cime Di Laverdo	f94035d1-d29a-4672-b08f-23d5e2013d7a	njanos@gmail.com	Misurina	Belluno	2024-10-04 05:39:59.380414	\N
10	Vizslatámadás	b1022687-4856-4698-8345-a7d99c8f5722	kanna@gmail.com	Kecskemét	Bács-Kiskun	2024-10-04 05:39:59.380414	\N
11	Berlin városa	9b5e3336-83f2-42ee-8397-fe1ee6206fc2	npeter@gmail.com	Berlin	Berlin	2024-10-04 05:39:59.380414	\N
12	London és a Big Ben	bc274d62-1982-47aa-aa1a-6a1b9c034e7c	vjanos@gmail.com	London	London	2024-10-04 05:39:59.380414	\N
13	New York-i fények este	790a4d1d-dc5b-4f93-bba6-fcbeb3bbe8bb	mmmarta@gmail.com	New York	New York	2024-10-04 05:39:59.380414	\N
14	Az Eiffel-torony	5c9549d9-9118-46d9-add4-0bfcd4f4e0c6	adminb@gmail.com	Párizs	Île-de-France	2024-10-04 05:39:59.380414	\N
15	Római Kolosszeum	ba674396-ba5d-49f3-a1ba-9cd64f78e388	admina@gmail.com	Róma	Lazio	2024-10-04 05:39:59.380414	\N
16	Peking városa este	22f1bc36-0998-44c9-8895-2007ca2943af	teszte@gmail.com	Peking	Peking	2024-10-04 05:39:59.380414	\N
17	Moszkva napnyugtakor	17a02d6b-447a-44e2-8266-11291fbe4835	keszter@gmail.com	Moszkva	Moszkva	2024-10-04 05:39:59.380414	\N
\.


--
-- Data for Name: megjegyzes; Type: TABLE DATA; Schema: kepalbumok; Owner: example
--

COPY kepalbumok.megjegyzes (megjegyzes_id, datum, tartalom, email, kep_id) FROM stdin;
1	2024-10-04 05:39:59.380414	Ez nagyon jó.	vjanos@gmail.com	1
2	2024-10-04 05:39:59.380414	Nagyon tetszik!	mvsandor@gmail.com	1
3	2024-10-04 05:39:59.380414	Imádom!	mmmarta@gmail.com	2
4	2024-10-04 05:39:59.380414	Szuper!	nmtdmarton@gmail.com	4
5	2024-10-04 05:39:59.380414	Láttam jobbat is.	teszte@gmail.com	2
6	2024-10-04 05:39:59.380414	Imádom!	nmtdmarton@gmail.com	3
7	2024-10-04 05:39:59.380414	WOW!	mmmarta@gmail.com	4
8	2024-10-04 05:39:59.380414	Nagyon szép!	mvsandor@gmail.com	5
9	2024-10-04 05:39:59.380414	Csodálatos kép!	kanna@gmail.com	6
10	2024-10-04 05:39:59.380414	Remek fotó!	ngabor@gmail.com	7
11	2024-10-04 05:39:59.380414	Aranyos!	njanos@gmail.com	8
12	2024-10-04 05:39:59.380414	Fantasztikus látvány!	ngabor@gmail.com	9
13	2024-10-04 05:39:59.380414	Cuki!	ngabor@gmail.com	10
14	2024-10-04 05:39:59.380414	Nagyon szép!	vjanos@gmail.com	1
15	2024-10-04 05:39:59.380414	Imádom!	mvsandor@gmail.com	1
16	2024-10-04 05:39:59.380414	Fantasztikus!	mmmarta@gmail.com	2
17	2024-10-04 05:39:59.380414	Csodálatos!	nmtdmarton@gmail.com	4
18	2024-10-04 05:39:59.380414	Nagyon jó munka!	teszte@gmail.com	2
19	2024-10-04 05:39:59.380414	Szép munka!	nmtdmarton@gmail.com	3
20	2024-10-04 05:39:59.380414	Elképesztő!	mmmarta@gmail.com	4
21	2024-10-04 05:39:59.380414	Nagyon tetszik a kompozíció!	mvsandor@gmail.com	5
22	2024-10-04 05:39:59.380414	Nagyon szép!	kanna@gmail.com	6
23	2024-10-04 05:39:59.380414	Fantasztikus!	ngabor@gmail.com	7
24	2024-10-04 05:39:59.380414	Aranyos kép!	njanos@gmail.com	8
25	2024-10-04 05:39:59.380414	Egy csodálatos pillanat!	ngabor@gmail.com	9
26	2024-10-04 05:39:59.380414	Nagyon cuki!	ngabor@gmail.com	10
\.


--
-- Data for Name: palyazat; Type: TABLE DATA; Schema: kepalbumok; Owner: example
--

COPY kepalbumok.palyazat (palyazat_id, cim, hatarido, kep_id) FROM stdin;
1	Legjobb természetkép	2024-12-31	\N
2	Legjobb portré	2024-10-11	\N
3	Legjobb absztrakt kép	2024-05-07	\N
4	Legjobban kinéző étel	2024-06-07	\N
5	Legjobb fiktív tartalmat ábrázoló kép	2025-11-19	\N
6	Legjobb építészeti kép	2024-09-28	\N
7	Legjobb városi pillanatok	2024-10-28	\N
8	Kulturális örökségünk	2024-10-18	\N
9	Legjobb makró fotó	2024-07-15	\N
10	Legjobb fekete-fehér kép	2024-08-20	\N
11	Legjobb állatportré	2024-09-05	\N
12	Legjobb street photography	2024-11-10	\N
13	Legjobb tájkép	2024-12-05	\N
14	Legjobb divatfotó	2024-07-25	\N
15	Legjobb sportfotó	2024-08-30	\N
16	Legjobb ételfotó	2024-09-15	\N
17	Legjobb utcai művészet fotója	2024-11-20	\N
18	Legjobb naplemente kép	2024-12-10	\N
19	A legcukibb kisállat	2024-08-08	\N
20	A legdivatosabb ruhadarab	2024-10-11	\N
21	Egy darab történelem	2024-06-09	\N
\.


--
-- Data for Name: tartozik; Type: TABLE DATA; Schema: kepalbumok; Owner: example
--

COPY kepalbumok.tartozik (kep_id, kategoria_id) FROM stdin;
1	7
2	1
3	5
4	6
5	4
6	1
7	6
8	8
9	1
10	8
\.


--
-- Name: ertekeles_ertekeles_id_seq; Type: SEQUENCE SET; Schema: kepalbumok; Owner: example
--

SELECT pg_catalog.setval('kepalbumok.ertekeles_ertekeles_id_seq', 21, true);


--
-- Name: kategoria_kategoria_id_seq; Type: SEQUENCE SET; Schema: kepalbumok; Owner: example
--

SELECT pg_catalog.setval('kepalbumok.kategoria_kategoria_id_seq', 16, true);


--
-- Name: kep_kep_id_seq; Type: SEQUENCE SET; Schema: kepalbumok; Owner: example
--

SELECT pg_catalog.setval('kepalbumok.kep_kep_id_seq', 17, true);


--
-- Name: megjegyzes_megjegyzes_id_seq; Type: SEQUENCE SET; Schema: kepalbumok; Owner: example
--

SELECT pg_catalog.setval('kepalbumok.megjegyzes_megjegyzes_id_seq', 26, true);


--
-- Name: palyazat_palyazat_id_seq; Type: SEQUENCE SET; Schema: kepalbumok; Owner: example
--

SELECT pg_catalog.setval('kepalbumok.palyazat_palyazat_id_seq', 21, true);


--
-- Name: ertekeles ertekeles_pkey; Type: CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.ertekeles
    ADD CONSTRAINT ertekeles_pkey PRIMARY KEY (ertekeles_id);


--
-- Name: felhasznalo felhasznalo_nev_key; Type: CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.felhasznalo
    ADD CONSTRAINT felhasznalo_nev_key UNIQUE (nev);


--
-- Name: felhasznalo felhasznalo_pkey; Type: CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.felhasznalo
    ADD CONSTRAINT felhasznalo_pkey PRIMARY KEY (email);


--
-- Name: helyszin helyszin_pkey; Type: CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.helyszin
    ADD CONSTRAINT helyszin_pkey PRIMARY KEY (megye, telepules);


--
-- Name: kategoria kategoria_nev_key; Type: CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.kategoria
    ADD CONSTRAINT kategoria_nev_key UNIQUE (nev);


--
-- Name: kategoria kategoria_pkey; Type: CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.kategoria
    ADD CONSTRAINT kategoria_pkey PRIMARY KEY (kategoria_id);


--
-- Name: kep kep_eleresi_ut_key; Type: CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.kep
    ADD CONSTRAINT kep_eleresi_ut_key UNIQUE (eleresi_ut);


--
-- Name: kep kep_pkey; Type: CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.kep
    ADD CONSTRAINT kep_pkey PRIMARY KEY (kep_id);


--
-- Name: megjegyzes megjegyzes_pkey; Type: CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.megjegyzes
    ADD CONSTRAINT megjegyzes_pkey PRIMARY KEY (megjegyzes_id);


--
-- Name: palyazat palyazat_pkey; Type: CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.palyazat
    ADD CONSTRAINT palyazat_pkey PRIMARY KEY (palyazat_id);


--
-- Name: ertekeles ertekeles_email_fkey; Type: FK CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.ertekeles
    ADD CONSTRAINT ertekeles_email_fkey FOREIGN KEY (email) REFERENCES kepalbumok.felhasznalo(email) ON DELETE CASCADE;


--
-- Name: ertekeles ertekeles_kep_id_fkey; Type: FK CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.ertekeles
    ADD CONSTRAINT ertekeles_kep_id_fkey FOREIGN KEY (kep_id) REFERENCES kepalbumok.kep(kep_id) ON DELETE CASCADE;


--
-- Name: felhasznalo felhasznalo_kategoria_id_fkey; Type: FK CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.felhasznalo
    ADD CONSTRAINT felhasznalo_kategoria_id_fkey FOREIGN KEY (kategoria_id) REFERENCES kepalbumok.kategoria(kategoria_id) ON DELETE SET NULL;


--
-- Name: felhasznalo felhasznalo_megye_telepules_fkey; Type: FK CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.felhasznalo
    ADD CONSTRAINT felhasznalo_megye_telepules_fkey FOREIGN KEY (megye, telepules) REFERENCES kepalbumok.helyszin(megye, telepules) ON DELETE SET NULL;


--
-- Name: kep kep_email_fkey; Type: FK CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.kep
    ADD CONSTRAINT kep_email_fkey FOREIGN KEY (email) REFERENCES kepalbumok.felhasznalo(email) ON DELETE SET NULL;


--
-- Name: kep kep_megye_telepules_fkey; Type: FK CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.kep
    ADD CONSTRAINT kep_megye_telepules_fkey FOREIGN KEY (megye, telepules) REFERENCES kepalbumok.helyszin(megye, telepules) ON DELETE SET NULL;


--
-- Name: kep kep_palyazat_id_fkey; Type: FK CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.kep
    ADD CONSTRAINT kep_palyazat_id_fkey FOREIGN KEY (palyazat_id) REFERENCES kepalbumok.palyazat(palyazat_id) ON DELETE SET NULL;


--
-- Name: megjegyzes megjegyzes_email_fkey; Type: FK CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.megjegyzes
    ADD CONSTRAINT megjegyzes_email_fkey FOREIGN KEY (email) REFERENCES kepalbumok.felhasznalo(email) ON DELETE SET NULL;


--
-- Name: megjegyzes megjegyzes_kep_id_fkey; Type: FK CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.megjegyzes
    ADD CONSTRAINT megjegyzes_kep_id_fkey FOREIGN KEY (kep_id) REFERENCES kepalbumok.kep(kep_id) ON DELETE CASCADE;


--
-- Name: palyazat palyazat_kep_id_fkey; Type: FK CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.palyazat
    ADD CONSTRAINT palyazat_kep_id_fkey FOREIGN KEY (kep_id) REFERENCES kepalbumok.kep(kep_id) ON DELETE CASCADE;


--
-- Name: tartozik tartozik_kategoria_id_fkey; Type: FK CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.tartozik
    ADD CONSTRAINT tartozik_kategoria_id_fkey FOREIGN KEY (kategoria_id) REFERENCES kepalbumok.kategoria(kategoria_id) ON DELETE CASCADE;


--
-- Name: tartozik tartozik_kep_id_fkey; Type: FK CONSTRAINT; Schema: kepalbumok; Owner: example
--

ALTER TABLE ONLY kepalbumok.tartozik
    ADD CONSTRAINT tartozik_kep_id_fkey FOREIGN KEY (kep_id) REFERENCES kepalbumok.kep(kep_id) ON DELETE CASCADE;


--
-- PostgreSQL database dump complete
--
```