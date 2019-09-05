-- Création de la table table_des_decalages_horaires --
CREATE TABLE IF NOT EXISTS table_des_decalages_horaires(
	id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
	nom_de_la_timezone VARCHAR(100) NOT NULL,
	decalage_par_rapport_a_UTC INTEGER NOT NULL
);

-- Insertion des décalages horaires relatives à chaque timezone --

-- République de Biélorussie --
INSERT INTO table_des_decalages_horaires VALUES("Europe/Minsk", 10800);

-- Fédération de Russie --
INSERT INTO table_des_decalages_horaires VALUES("Asia/Anadyr", 43200);
INSERT INTO table_des_decalages_horaires VALUES("Asia/Kamchatka", 43200);
INSERT INTO table_des_decalages_horaires VALUES("Asia/Ust-Nera", 36000);
INSERT INTO table_des_decalages_horaires VALUES("Asia/Vladivostok", 36000);
INSERT INTO table_des_decalages_horaires VALUES("Europe/Ulyanovsk", 14400);
INSERT INTO table_des_decalages_horaires VALUES("Europe/Saratov", 14400);
INSERT INTO table_des_decalages_horaires VALUES("Europe/Samara", 14400);
INSERT INTO table_des_decalages_horaires VALUES("Europe/Astrakhan", 14400);
INSERT INTO table_des_decalages_horaires VALUES("Europe/Volgograd", 14400);
INSERT INTO table_des_decalages_horaires VALUES("Europe/Moscow", 10800);
INSERT INTO table_des_decalages_horaires VALUES("Europe/Kirov", 10800);
INSERT INTO table_des_decalages_horaires VALUES("Europe/Kaliningrad", 7200);
INSERT INTO table_des_decalages_horaires VALUES("Asia/Yekaterinburg", 18000);
INSERT INTO table_des_decalages_horaires VALUES("Asia/Yakutsk", 32400);
INSERT INTO table_des_decalages_horaires VALUES("Asia/Khandyga", 32400);
INSERT INTO table_des_decalages_horaires VALUES("Asia/Chita", 32400);
INSERT INTO table_des_decalages_horaires VALUES("Asia/Tomsk", 25200);
INSERT INTO table_des_decalages_horaires VALUES("Asia/Barnaul", 25200);
INSERT INTO table_des_decalages_horaires VALUES("Asia/Novosibirsk", 25200);
INSERT INTO table_des_decalages_horaires VALUES("Asia/Novokuznetsk", 25200);
INSERT INTO table_des_decalages_horaires VALUES("Asia/Krasnoyarsk", 25200);
INSERT INTO table_des_decalages_horaires VALUES("Asia/Srednekolymsk", 39600);
INSERT INTO table_des_decalages_horaires VALUES("Asia/Sakhalin", 39600);
INSERT INTO table_des_decalages_horaires VALUES("Asia/Magadan", 39600);
INSERT INTO table_des_decalages_horaires VALUES("Asia/Omsk", 21600);
INSERT INTO table_des_decalages_horaires VALUES("Asia/Irkutsk", 28800);

-- Empire du Japon -- 
INSERT INTO table_des_decalages_horaires VALUES("Asia/Tokyo", 32400);
