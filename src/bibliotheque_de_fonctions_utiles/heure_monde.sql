-- Création de la table table_des_decalages_horaires --
CREATE TABLE IF NOT EXISTS table_des_decalages_horaires(
	id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
	nom_de_la_timezone VARCHAR(100) NOT NULL,
	decalage_par_rapport_a_UTC INTEGER NOT NULL
);

-- Insertion des décalages horaires relatives à chaque timezone --

-- République populaire du Bangladesh --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Dhaka", 21600);

-- République islamique du Pakistan --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Karachi", 18000);

-- Émirats arabes unis --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Dubai", 14400);

-- Sultanat d'Oman --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Muscat", 14400);

-- État du Koweït --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Kuwait", 10800);

-- Royaume de Bahreïn --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Bahrain", 10800);

-- République d'Irak --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Baghdad", 10800);

-- État du Qatar --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Qatar", 10800);

-- République du Yémen --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Aden", 10800);

-- Royaume d'Arabie saoudite --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Asia/Riyadh", 10800);

-- République du Botswana --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Gaborone", 7200);

-- Royaume du Lesotho --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Maseru", 7200);

-- Royaume d'Eswatini --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Mbabane", 7200);

-- République de Maurice --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Indian/Mauritius", 14400);

-- République des Maldives --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Indian/Maldives", 18000);

-- Union des Comores --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Indian/Comoro", 10800);

-- République du Mozambique --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Maputo", 7200);

-- République du Soudan --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Khartoum", 7200);

-- République du Soudan du Sud --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Juba", 10800);

-- République algérienne démocratique et populaire --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Algiers", 3600);

-- République du Honduras --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Tegucigalpa", -21600);

-- République du Guatemala --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Guatemala", -21600);

-- République du Costa Rica --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Costa_Rica", -21600);

-- Belize --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Belize", -21600);

-- République du Salvador --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/El_Salvador", -21600);

-- République du Nicaragua --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Managua", -21600);

-- Sainte-Lucie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/St_Lucia", -14400);

-- Saint-Vincent-et-les-Grenadines --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/St_Vincent", -14400);

-- République dominicaine --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Santo_Domingo", -14400);

-- Fédération de Saint-Christophe-et-Niévès, Saint-Christophe-et-Nevis --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/St_Kitts", -14400);

-- République du Suriname --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Paramaribo", -10800);

-- République coopérative du Guyana --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Guyana", -14400);

-- République de Trinité-et-Tobago --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Port_of_Spain", -14400);

-- Jamaïque --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("America/Jamaica", -18000);

-- République de Namibie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Windhoek", 7200);

-- République d'Afrique du Sud --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Johannesburg", 7200);

-- État de Libye --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Tripoli", 7200);

-- État d'Érythrée --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Asmara", 10800);

-- République gabonaise --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Libreville", 3600);

-- République démocratique fédérale d’Éthiopie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Addis_Ababa", 10800);

-- République fédérale de Somalie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Mogadishu", 10800);

-- République du Bénin --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Porto-Novo", 3600);

-- République du Cameroun --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Douala", 3600);

-- République de Guinée équatoriale --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Malabo", 3600);

-- République fédérale du Nigeria --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Lagos", 3600);

-- République démocratique du Congo --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Kinshasa", 3600);
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Lubumbashi", 7200);

-- République unie de Tanzanie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Dar_es_Salaam", 10800);

-- République du Kenya --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Nairobi", 10800);

-- République d'Ouganda --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Kampala", 10800);

-- République centrafricaine --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Bangui", 3600);

-- République tunisienne --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Tunis", 3600);

-- République du Cap-Vert --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Atlantic/Cape_Verde", -3600);

-- République arabe d'Égypte --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Cairo", 7200);

-- République de Zimbabwe --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Harare", 7200);

-- République de Zambie --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Lusaka", 7200);

-- République du Burundi --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Bujumbura", 7200);

-- République du Malawi --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Blantyre", 7200);

-- République du Tchad --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Ndjamena", 3600);

-- République du Niger --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Niamey", 3600);

-- République du Rwanda --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Kigali", 7200);

-- République de Djibouti --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Djibouti", 10800);

-- République du Congo --
INSERT INTO table_des_decalages_horaires(nom_de_la_timezone, decalage_par_rapport_a_UTC) VALUES("Africa/Brazzaville", 3600);

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
