-- Création de la table table_des_decalages_horaires --
CREATE TABLE IF NOT EXISTS table_des_decalages_horaires(
	id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
	nom_de_la_timezone VARCHAR(100) NOT NULL,
	decalage_par_rapport_a_UTC INTEGER NOT NULL,
	indicateur_d_application_de_l_heure_d_ete INTEGER NOT NULL
);

-- Insertion des décalages horaires relatives à chaque timezone --

-- États-Unis mexicains --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Mexico_City", -21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Monterrey", -21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Cancun", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Chihuahua", -25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Hermosillo", -25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Mazatlan", -25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Ojinaga", -25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Tijuana", -28800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Merida", -21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Matamoros", -21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Bahia_Banderas", -21600, 0);

-- Royaume du Maroc --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Casablanca", 3600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/El_Aaiun", 3600, 0);

-- République de Cuba --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Havana", -18000, 0);

-- République d'Haïti --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Port-au-Prince", -18000, 0);

-- Commonwealth des Bahamas --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Nassau", -18000, 0);

-- État de Palestine --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Hebron", 7200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Gaza", 7200, 0);

-- République fédérative du Brésil --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Campo_Grande", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Cuiaba", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Sao_Paulo", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Araguaina", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Bahia", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Belem", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Fortaleza", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Maceio", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Recife", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Santarem", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Boa_Vista", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Manaus", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Porto_Velho", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Eirunepe", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Rio_Branco", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Noronha", -7200, 0);

-- Royaume hachémite de Jordanie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Amman", 7200, 0);

-- République libanaise --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Beirut", 7200, 0);

-- État d'Israël --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Jerusalem", 7200, 0);

-- République des Fidji --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Fiji", 43200, 0);

-- République islamique d'Iran --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Tehran", 12600, 0);

-- République arabe syrienne --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Damascus", 7200, 0);

-- République du Paraguay --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Asuncion", -14400, 0);

-- État indépendant des Samoa --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Apia", 46800, 0);

-- République du Chili --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Santiago", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Easter", -21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Punta_Arenas", -10800, 0);

-- États-Unis d'Amérique --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/New_York", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Los_Angeles", -28800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Juneau", -32400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Yakutat", -32400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Menominee", -21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Chicago", -21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Boise", -25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Denver", -25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Anchorage", -32400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Detroit", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Metlakatla", -32400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Sitka", -32400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Nome", -32400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Adak", -36000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Kentucky/Louisville", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Kentucky/Monticello", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Indiana/Winamac", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Indiana/Vincennes", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Indiana/Vevay", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Indiana/Petersburg", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Indiana/Marengo", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Indiana/Indianapolis", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/North_Dakota/New_Salem", -21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/North_Dakota/Center", -21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/North_Dakota/Beulah", -21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Indiana/Tell_City", -21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Indiana/Knox", -21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Phoenix", -25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Honolulu", -36000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Johnston", -36000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Midway", -39600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Wake", 43200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Guam", 36000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Pago_Pago", -39600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/St_Thomas", -14400, 0);

-- Dominion du Canada --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Toronto", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Pangnirtung", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Thunder_Bay", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Nipigon", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Iqaluit", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Winnipeg", -21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Resolute", -21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Rankin_Inlet", -21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Rainy_River", -21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Whitehorse", -28800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Vancouver", -28800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Dawson", -28800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/St_Johns", -12600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Moncton", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Halifax", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Goose_Bay", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Glace_Bay", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Inuvik", -25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Edmonton", -25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Cambridge_Bay", -25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Yellowknife", -25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Atikokan", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Swift_Current", -21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Regina", -21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Blanc-Sablon", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Fort_Nelson", -25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Dawson_Creek", -25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Creston", -25200, 0);

-- Nouvelle-Zélande --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Auckland", 43200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Chatham", 45900, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Fakaofo", 46800, 0);

-- Commonwealth d'Australie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Australia/Sydney", 36000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Australia/Currie", 36000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Australia/Hobart", 36000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Australia/Melbourne", 36000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Australia/Adelaide", 34200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Australia/Broken_Hill", 34200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Antarctica/Macquarie", 39600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Australia/Darwin", 34200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Australia/Brisbane", 36000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Australia/Lindeman", 36000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Australia/Eucla", 31500, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Australia/Perth", 28800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Indian/Cocos", 23400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Indian/Christmas", 25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Norfolk", 39600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Australia/Lord_Howe", 37800, 0);

-- Royaume-Uni de Grande-Bretagne et d'Irlande du Nord --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Atlantic/Bermuda", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Grand_Turk", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/London", 0, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Isle_of_Man", 0, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Jersey", 0, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Guernsey", 0, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Tortola", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Atlantic/Stanley", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Anguilla", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Atlantic/South_Georgia", -7200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Cayman", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Montserrat", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Pitcairn", -28800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Indian/Chagos", 21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Gibraltar", 3600, 0);

-- Antarctique --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Antarctica/Casey", 28800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Antarctica/Davis", 25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Antarctica/DumontDUrville", 36000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Antarctica/Mawson", 18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Antarctica/Palmer", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Antarctica/Rothera", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Antarctica/Syowa", 10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Antarctica/Vostok", 21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Antarctica/Troll", 0, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Antarctica/McMurdo", 43200, 0);

-- Royaume des Pays-Bas --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Amsterdam", 3600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Aruba", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Kralendijk", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Curacao", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Lower_Princes", -14400, 0);

-- République française --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Miquelon", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Paris", 3600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Cayenne", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Indian/Reunion", 14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Guadeloupe", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Noumea", 39600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Indian/Mayotte", 10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Indian/Kerguelen", 18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Tahiti", -36000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Gambier", -32400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Marquesas", -34200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/St_Barthelemy", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Martinique", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Wallis", 43200, 0);

-- République fédérale d'Allemagne --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Berlin", 3600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Busingen", 3600, 0);

-- Principauté de Monaco --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Monaco", 3600, 0);

-- Royaume d'Espagne --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Madrid", 3600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Ceuta", 3600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Atlantic/Canary", 0, 0);

-- République portugaise --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Lisbon", 0, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Atlantic/Madeira", 0, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Atlantic/Azores", -3600, 0);

-- Grand-Duché de Luxembourg --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Luxembourg", 3600, 0);

-- Royaume de Belgique --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Brussels", 3600, 0);

-- Royaume de Danemark --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Thule", -14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Copenhagen", 3600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Atlantic/Faroe", 0, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Godthab", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Scoresbysund", -3600, 0);

-- Royaume de Norvège --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Oslo", 3600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Arctic/Longyearbyen", 3600, 0);

-- Royaume de Suède --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Stockholm", 3600, 0);

-- République de Finlande --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Helsinki", 7200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Mariehamn", 7200, 0);

-- République de Pologne --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Warsaw", 3600, 0);

-- République de Lituanie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Vilnius", 7200, 0);

-- République de Lettonie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Riga", 7200, 0);

-- République d’Estonie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Tallinn", 7200, 0);

-- République italienne --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Rome", 3600, 0);

-- État de la Cité du Vatican --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Vatican", 3600, 0);

-- République de Saint-Marin --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/San_Marino", 3600, 0);

-- République d'Autriche --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Vienna", 3600, 0);

-- Hongrie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Budapest", 3600, 0);

-- République tchèque --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Prague", 3600, 0);

-- République slovaque --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Bratislava", 3600, 0);

-- Roumanie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Bucharest", 7200, 0);

-- République de Bulgarie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Sofia", 7200, 0);

-- République de Macédoine du Nord --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Skopje", 3600, 0);

-- République de Slovénie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Ljubljana", 3600, 0);

-- République de Croatie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Zagreb", 3600, 0);

-- Bosnie-Herzégovine --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Sarajevo", 3600, 0);

-- Monténégro --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Podgorica", 3600, 0);

-- République de Serbie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Belgrade", 3600, 0);

-- République d'Albanie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Tirane", 3600, 0);

-- Ukraine --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Kiev", 7200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Uzhgorod", 7200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Zaporozhye", 7200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Simferopol", 10800, 0);

-- Confédération suisse --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Zurich", 3600, 0);

-- République de Malte --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Malta", 3600, 0);

-- Principauté d'Andorre --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Andorra", 3600, 0);

-- Principauté de Liechtenstein --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Vaduz", 3600, 0);

-- République hellénique --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Athens", 7200, 0);

-- République de Chypre --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Nicosia", 7200, 0);

-- République d'Irlande --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Dublin", 0, 0);

-- République de Moldavie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Chisinau", 7200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Tiraspol", 7200, 0);

-- République du Kazakhstan --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Almaty", 21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Qostanay", 21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Aqtau", 18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Aqtobe", 18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Atyrau", 18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Oral", 18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Qyzylorda", 18000, 0);

-- République islamique d'Afghanistan --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Kabul", 16200, 0);

-- République démocratique fédérale du Népal --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Kathmandu", 20700, 0);

-- Royaume de Thaïlande --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Bangkok", 25200, 0);

-- République socialiste du Viêt Nam --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Ho_Chi_Minh", 25200, 0);

-- République du Tadjikistan --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Dushanbe", 18000, 0);

-- République kirghize --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Bishkek", 21600, 0);

-- République d'Ouzbékistan --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Tashkent", 18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Samarkand", 18000, 0);

-- République de l'Inde --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Kolkata", 19800, 0);

-- République démocratique socialiste du Sri Lanka --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Colombo", 19800, 0);

-- République populaire du Bangladesh --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Dhaka", 21600, 0);

-- République islamique du Pakistan --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Karachi", 18000, 0);

-- Émirats arabes unis --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Dubai", 14400, 0);

-- Sultanat d'Oman --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Muscat", 14400, 0);

-- État du Koweït --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Kuwait", 10800, 0);

-- Royaume de Bahreïn --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Bahrain", 10800, 0);

-- République d'Irak --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Baghdad", 10800, 0);

-- État du Qatar --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Qatar", 10800, 0);

-- République du Yémen --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Aden", 10800, 0);

-- Royaume d'Arabie saoudite --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Riyadh", 10800, 0);

-- République du Botswana --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Gaborone", 7200, 0);

-- Royaume du Lesotho --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Maseru", 7200, 0);

-- Royaume d'Eswatini --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Mbabane", 7200, 0);

-- République de Maurice --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Indian/Mauritius", 14400, 0);

-- République des Maldives --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Indian/Maldives", 18000, 0);

-- Union des Comores --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Indian/Comoro", 10800, 0);

-- République du Mozambique --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Maputo", 7200, 0);

-- République du Soudan --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Khartoum", 7200, 0);

-- République du Soudan du Sud --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Juba", 10800, 0);

-- République algérienne démocratique et populaire --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Algiers", 3600, 0);

-- République du Honduras --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Tegucigalpa", -21600, 0);

-- République du Guatemala --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Guatemala", -21600, 0);

-- République du Costa Rica --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Costa_Rica", -21600, 0);

-- Belize --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Belize", -21600, 0);

-- République du Salvador --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/El_Salvador", -21600, 0);

-- République du Nicaragua --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Managua", -21600, 0);

-- Sainte-Lucie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/St_Lucia", -14400, 0);

-- Saint-Vincent-et-les-Grenadines --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/St_Vincent", -14400, 0);

-- République dominicaine --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Santo_Domingo", -14400, 0);

-- Fédération de Saint-Christophe-et-Niévès, Saint-Christophe-et-Nevis --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/St_Kitts", -14400, 0);

-- République du Suriname --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Paramaribo", -10800, 0);

-- République coopérative du Guyana --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Guyana", -14400, 0);

-- République de Trinité-et-Tobago --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Port_of_Spain", -14400, 0);

-- Jamaïque --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Jamaica", -18000, 0);

-- République de Namibie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Windhoek", 7200, 0);

-- République d'Afrique du Sud --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Johannesburg", 7200, 0);

-- État de Libye --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Tripoli", 7200, 0);

-- État d'Érythrée --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Asmara", 10800, 0);

-- République gabonaise --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Libreville", 3600, 0);

-- République démocratique fédérale d’Éthiopie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Addis_Ababa", 10800, 0);

-- République fédérale de Somalie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Mogadishu", 10800, 0);

-- République du Bénin --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Porto-Novo", 3600, 0);

-- République du Cameroun --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Douala", 3600, 0);

-- République de Guinée équatoriale --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Malabo", 3600, 0);

-- République fédérale du Nigeria --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Lagos", 3600, 0);

-- République démocratique du Congo --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Kinshasa", 3600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Lubumbashi", 7200, 0);

-- République unie de Tanzanie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Dar_es_Salaam", 10800, 0);

-- République du Kenya --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Nairobi", 10800, 0);

-- République d'Ouganda --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Kampala", 10800, 0);

-- République centrafricaine --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Bangui", 3600, 0);

-- République tunisienne --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Tunis", 3600, 0);

-- République du Cap-Vert --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Atlantic/Cape_Verde", -3600, 0);

-- République arabe d'Égypte --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Cairo", 7200, 0);

-- République de Zimbabwe --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Harare", 7200, 0);

-- République de Zambie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Lusaka", 7200, 0);

-- République du Burundi --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Bujumbura", 7200, 0);

-- République du Malawi --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Blantyre", 7200, 0);

-- République du Tchad --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Ndjamena", 3600, 0);

-- République du Niger --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Niamey", 3600, 0);

-- République du Rwanda --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Kigali", 7200, 0);

-- République de Djibouti --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Djibouti", 10800, 0);

-- République du Congo --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Brazzaville", 3600, 0);

-- République d'Indonésie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Jakarta", 25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Pontianak", 25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Jayapura", 32400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Makassar", 28800, 0);

-- Fédération de Malaisie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Kuala_Lumpur", 28800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Kuching", 28800, 0);

-- Îles Salomon --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Guadalcanal", 39600, 0);

-- République de Singapour --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Singapore", 28800, 0);

-- République des Philippines --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Manila", 28800, 0);

-- République de Chine (Taiwan) --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Taipei", 28800, 0);

-- Mongolie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Choibalsan", 28800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Ulaanbaatar", 28800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Hovd", 25200, 0);

-- Negara Brunei Darussalam --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Brunei", 28800, 0);

-- République démocratique du Timor oriental --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Dili", 32400, 0);

-- République de l'Union du Myanmar --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Yangon", 23400, 0);

-- Royaume du Cambodge --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Phnom_Penh", 25200, 0);

-- République démocratique populaire lao --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Vientiane", 25200, 0);

-- Région administrative spéciale de Hong Kong de la République populaire de Chine --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Hong_Kong", 28800, 0);

-- Région administrative spéciale de Macao de la République populaire de Chine --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Macau", 28800, 0);

-- République de Corée --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Seoul", 32400, 0);

-- République populaire démocratique de Corée --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Pyongyang", 32400, 0);

-- Royaume du Bhoutan --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Thimphu", 21600, 0);

-- République populaire de Chine --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Shanghai", 28800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Urumqi", 21600, 0);

-- Groenland --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Danmarkshavn", 0, 0);

-- République d'Islande --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Atlantic/Reykjavik", 0, 0);

-- Royaume-Uni de Grande-Bretagne et d'Irlande du Nord --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Atlantic/St_Helena", 0, 0);

-- République togolaise --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Lome", 0, 0);

-- République du Ghana --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Accra", 0, 0);

-- République du Mali --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Bamako", 0, 0);

-- République islamique de Mauritanie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Nouakchott", 0, 0);

-- République de Côte d'Ivoire --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Abidjan", 0, 0);

-- République de Guinée --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Conakry", 0, 0);

-- République de Sierra Leone --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Freetown", 0, 0);

-- République du Liberia --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Monrovia", 0, 0);

-- République du Sénégal --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Dakar", 0, 0);

-- Burkina Faso --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Ouagadougou", 0, 0);

-- République de Gambie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Banjul", 0, 0);

-- République démocratique de Sao Tomé-et-Principe --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Sao_Tome", 0, 0);

-- République de Guinée-Bissau --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Africa/Bissau", 0, 0);

-- Niue --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Niue", -39600, 0);

-- République argentine --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Argentina/Buenos_Aires", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Argentina/Catamarca", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Argentina/Cordoba", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Argentina/Jujuy", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Argentina/La_Rioja", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Argentina/Mendoza", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Argentina/Rio_Gallegos", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Argentina/Salta", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Argentina/San_Juan", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Argentina/San_Luis", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Argentina/Tucuman", -10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Argentina/Ushuaia", -10800, 0);

-- République orientale de l'Uruguay --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Montevideo", -10800, 0);

-- République bolivarienne du Venezuela --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Caracas", -14400, 0);

-- État plurinational de Bolivie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/La_Paz", -14400, 0);

-- République de l'Équateur --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Guayaquil", -18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Galapagos", -21600, 0);

-- République du Panama --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Panama", -18000, 0);

-- République des Kiribati --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Enderbury", 46800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Kiritimati", 50400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Tarawa", 43200, 0);

-- République de Nauru --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Nauru", 43200, 0);

-- État des Tuvalu --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Funafuti", 43200, 0);

-- République de Vanuatu --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Efate", 39600, 0);

-- Royaume de Tonga --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Tongatapu", 46800, 0);

-- République de Madagascar --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Indian/Antananarivo", 10800, 0);

-- République du Pérou --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Lima", -18000, 0);

-- République de Colombie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Bogota", -18000, 0);

-- îles Cook --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Rarotonga", -36000, 0);

-- République des Îles Marshall --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Majuro", 43200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Kwajalein", 43200, 0);

-- États fédérés de Micronésie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Pohnpei", 39600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Ponape", 39600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Chuuk", 36000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Kosrae", 39600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Yap", 36000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Truk", 36000, 0);

-- République des Seychelles --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Indian/Mahe", 14400, 0);

-- État indépendant de Papouasie-Nouvelle-Guinée --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Bougainville", 39600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Port_Moresby", 36000, 0);

-- République des Palaos --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Palau", 32400, 0);

-- îles Mariannes du Nord --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Pacific/Saipan", 36000, 0);

-- Porto Rico --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("America/Puerto_Rico", -14400, 0);

-- République de Turquie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Istanbul", 10800, 0);

-- République de Biélorussie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Minsk", 10800, 0);

-- Fédération de Russie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Anadyr", 43200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Kamchatka", 43200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Ust-Nera", 36000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Vladivostok", 36000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Ulyanovsk", 14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Saratov", 14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Samara", 14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Astrakhan", 14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Volgograd", 14400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Moscow", 10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Kirov", 10800, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Europe/Kaliningrad", 7200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Yekaterinburg", 18000, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Yakutsk", 32400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Khandyga", 32400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Chita", 32400, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Tomsk", 25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Barnaul", 25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Novosibirsk", 25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Novokuznetsk", 25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Krasnoyarsk", 25200, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Srednekolymsk", 39600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Sakhalin", 39600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Magadan", 39600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Omsk", 21600, 0);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Irkutsk", 28800, 0);

-- République d'Arménie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Yerevan", 14400, 0);

-- République de Géorgie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Tbilisi", 14400, 0);

-- République d'Azerbaïdjan --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Baku", 14400, 0);

-- Empire du Japon -- 
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC, indicateur_d_application_de_l_heure_d_ete) VALUES("Asia/Tokyo", 32400, 0);
