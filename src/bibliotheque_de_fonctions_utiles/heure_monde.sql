-- Création de la table table_des_decalages_horaires --
CREATE TABLE IF NOT EXISTS table_des_decalages_horaires(
	id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
	nom_de_la_timezone VARCHAR(100) NOT NULL,
	decalage_par_rapport_a_UTC INTEGER NOT NULL
);

-- Insertion des décalages horaires relatives à chaque timezone --

-- États fédérés de Micronésie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Pohnpei", 39600);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Ponape", 39600);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Chuuk", 36000);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Kosrae", 39600);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Yap", 36000);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Truk", 36000);

-- République des Seychelles --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Indian/Mahe", 14400);

-- État indépendant de Papouasie-Nouvelle-Guinée --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Bougainville", 39600);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Port_Moresby", 36000);

-- République des Palaos --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Palau", 32400);

-- îles Mariannes du Nord --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Saipan", 36000);

-- Porto Rico --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Puerto_Rico", -14400);

-- République de Turquie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Europe/Istanbul", 10800);

-- République de Biélorussie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Europe/Minsk", 10800);

-- Fédération de Russie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Anadyr", 43200);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Kamchatka", 43200);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Ust-Nera", 36000);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Vladivostok", 36000);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Europe/Ulyanovsk", 14400);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Europe/Saratov", 14400);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Europe/Samara", 14400);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Europe/Astrakhan", 14400);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Europe/Volgograd", 14400);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Europe/Moscow", 10800);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Europe/Kirov", 10800);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Europe/Kaliningrad", 7200);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Yekaterinburg", 18000);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Yakutsk", 32400);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Khandyga", 32400);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Chita", 32400);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Tomsk", 25200);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Barnaul", 25200);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Novosibirsk", 25200);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Novokuznetsk", 25200);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Krasnoyarsk", 25200);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Srednekolymsk", 39600);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Sakhalin", 39600);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Magadan", 39600);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Omsk", 21600);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Irkutsk", 28800);

-- République d'Arménie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Yerevan", 14400);

-- République de Géorgie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Tbilisi", 14400);

-- République d'Azerbaïdjan --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Baku", 14400);

-- Empire du Japon -- 
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Tokyo", 32400);
