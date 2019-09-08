-- Création de la table table_des_decalages_horaires --
CREATE TABLE IF NOT EXISTS table_des_decalages_horaires(
	id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
	nom_de_la_timezone VARCHAR(100) NOT NULL,
	decalage_par_rapport_a_UTC INTEGER NOT NULL
);

-- Insertion des décalages horaires relatives à chaque timezone --

-- République d'Indonésie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Jakarta", 25200);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Pontianak", 25200);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Jayapura", 32400);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Makassar", 28800);

-- Fédération de Malaisie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Kuala_Lumpur", 28800);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Kuching", 28800);

-- Îles Salomon --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Guadalcanal", 39600);

-- République de Singapour --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Singapore", 28800);

-- République des Philippines --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Manila", 28800);

-- République de Chine (Taiwan) --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Taipei", 28800);

-- Mongolie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Choibalsan", 28800);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Ulaanbaatar", 28800);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Hovd", 25200);

-- Negara Brunei Darussalam --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Brunei", 28800);

-- République démocratique du Timor oriental --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Dili", 32400);

-- République de l'Union du Myanmar --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Yangon", 23400);

-- Royaume du Cambodge --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Phnom_Penh", 25200);

-- République démocratique populaire lao --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Vientiane", 25200);

-- Région administrative spéciale de Hong Kong de la République populaire de Chine --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Hong_Kong", 28800);

-- Région administrative spéciale de Macao de la République populaire de Chine --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Macau", 28800);

-- République de Corée --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Seoul", 32400);

-- République populaire démocratique de Corée --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Pyongyang", 32400);

-- Royaume du Bhoutan --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Thimphu", 21600);

-- République populaire de Chine --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Shanghai", 28800);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Urumqi", 21600);

-- Groenland --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Danmarkshavn", 0);

-- République d'Islande --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Atlantic/Reykjavik", 0);

-- Royaume-Uni de Grande-Bretagne et d'Irlande du Nord --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Atlantic/St_Helena", 0);

-- République togolaise --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Lome", 0);

-- République du Ghana --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Accra", 0);

-- République du Mali --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Bamako", 0);

-- République islamique de Mauritanie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Nouakchott", 0);

-- République de Côte d'Ivoire --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Abidjan", 0);

-- République de Guinée --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Conakry", 0);

-- République de Sierra Leone --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Freetown", 0);

-- République du Liberia --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Monrovia", 0);

-- République du Sénégal --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Dakar", 0);

-- Burkina Faso --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Ouagadougou", 0);

-- République de Gambie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Banjul", 0);

-- République démocratique de Sao Tomé-et-Principe --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Sao_Tome", 0);

-- République de Guinée-Bissau --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Bissau", 0);

-- Niue --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Niue", -39600);

-- République argentine --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Argentina/Buenos_Aires", -10800);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Argentina/Catamarca", -10800);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Argentina/Cordoba", -10800);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Argentina/Jujuy", -10800);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Argentina/La_Rioja", -10800);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Argentina/Mendoza", -10800);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Argentina/Rio_Gallegos", -10800);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Argentina/Salta", -10800);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Argentina/San_Juan", -10800);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Argentina/San_Luis", -10800);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Argentina/Tucuman", -10800);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Argentina/Ushuaia", -10800);

-- République orientale de l'Uruguay --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Montevideo", -10800);

-- République bolivarienne du Venezuela --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Caracas", -14400);

-- État plurinational de Bolivie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/La_Paz", -14400);

-- République de l'Équateur --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Guayaquil", -18000);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Galapagos", -21600);

-- République du Panama --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Panama", -18000);

-- République des Kiribati --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Enderbury", 46800);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Kiritimati", 50400); 
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Tarawa", 43200);

-- République de Nauru --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Nauru", 43200);

-- État des Tuvalu --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Funafuti", 43200);

-- République de Vanuatu --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Efate", 39600);

-- Royaume de Tonga --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Tongatapu", 46800);

-- République de Madagascar --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Indian/Antananarivo", 10800);

-- République du Pérou --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Lima", -18000);

-- République de Colombie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Bogota", -18000);

-- îles Cook --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Rarotonga", -36000);

-- République des Îles Marshall --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Majuro", 43200);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Pacific/Kwajalein", 43200);

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
