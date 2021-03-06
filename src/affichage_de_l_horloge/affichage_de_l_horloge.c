/* Inclusion des bibliothéques standards du C utilisées dans cette bibliothéque-ci */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Inclusion des bibliothéques internes à l'API */
#include "../application_des_decalages_horaires/application_des_decalages_horaires.h"
#include "affichage_de_l_horloge.h"
#include "../fonctions_d_affichage_et_de_renvoie_de_l_heure_et_de_la_date/fonctions_d_affichage_et_de_renvoie_de_l_heure_et_de_la_date.h"
#include "../bibliotheque_de_fonctions_utiles/bibliotheque_de_fonctions_utiles.h"

//Fonction qui affiche l'heure courante et la date courante en temps réel sur tous les fuseaux horaires du monde entier en simultané
/*
	Explication du calcul:

	Prenons un fuseau horaire quelconque noté zone_quelquonque/fuseau_horaire_quelquonque.

	Définissons, pour le fuseau horaire zone_quelquonque/fuseau_horaire_quelquonque, les régles suivantes:

	-> Sur le fuseau zone_quelquonque/fuseau_horaire_quelquonque: UTC+03:00 (heure d'hiver),

	-> Sur le fuseau zone_quelquonque/fuseau_horaire_quelquonque: UTC+04:00 (heure d'été).

	UTC étant la notation officielle pour "Universel Temps Coordonné": échelle de temps adoptée comme base du temps civil international par la majorité des pays du globe (wikipedia).

	Voici le principe de l'algorithme:

	1) On calcule le temps courant UTC sous forme de timestamp (c'est-à-dire le nombre de secondes écoulées depuis le 1er janvier 1970 à minuit UTC précise),

	2) On applique le changement d'heure pour le fuseau horaire quelconque si celui-ci applique l'heure d'été,

	3) On calcule le temps courant en additionnant le temps UTC par le décalage horaire (en secondes) par rapport à l'UTC pour le fuseau horaire quelconque

	4) Le temps courant pour le fuseau horaire quelconque est affiché.
*/
void affichage_de_l_horloge()
{

	/* Définition de la variable temps_utc et initialisation de celle-ci au temps utc sous forme de timestamp */
	time_t temps_utc = retour_du_temps_utc_sous_forme_de_timestamp();

	/* Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Europe continentale */
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Paris", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Monaco", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Madrid", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Africa/Ceuta", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Atlantic/Canary", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Luxembourg", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Brussels", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Lisbon", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Atlantic/Azores", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Atlantic/Madeira", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Amsterdam", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Berlin", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Busingen", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Oslo", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Arctic/Longyearbyen", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Stockholm", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Helsinki", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Mariehamn", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Copenhagen", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Atlantic/Faroe", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("America/Godthab", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("America/Scoresbysund", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Warsaw", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Vilnius", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Riga", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Tallinn", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Rome", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Vatican", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/San_Marino", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Vienna", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Budapest", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Prague", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Bratislava", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Bucharest", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Sofia", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Skopje", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Ljubljana", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Zagreb", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Sarajevo", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Podgorica", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Belgrade", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Tirane", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Kiev", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Uzhgorod", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Zaporozhye", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Zurich", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Malta", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Andorra", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Vaduz", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Athens", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Asia/Nicosia", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Dublin", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Chisinau", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Tiraspol", temps_utc);
	application_du_changement_d_heure_pour_l_europe_continentale("Europe/Gibraltar", temps_utc);

	/* Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour la base antarctique de Troll */
	application_du_changement_d_heure_pour_la_base_antarctique_de_troll(temps_utc);

	/* Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Île Lord Howe */
	application_du_changement_d_heure_pour_le_cas_particulier_de_lord_howe(temps_utc);

	/* Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour la Nouvelle-Zélande */
	application_du_changement_d_heure_pour_la_nouvelle_zelande("Pacific/Auckland", temps_utc);
	application_du_changement_d_heure_pour_la_nouvelle_zelande("Pacific/Chatham", temps_utc);
	application_du_changement_d_heure_pour_la_nouvelle_zelande("Antarctica/McMurdo", temps_utc);

	/* Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour le Chili */
	application_du_changement_d_heure_pour_le_chili("America/Santiago", temps_utc);
	application_du_changement_d_heure_pour_le_chili("Pacific/Easter", temps_utc);

	/* Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour les Samoa */
	application_du_changement_d_heure_pour_les_samoa(temps_utc);

	/* Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour le Paraguay */
	application_du_changement_d_heure_pour_le_paraguay(temps_utc);

	/* Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour la Syrie */
	application_du_changement_d_heure_pour_la_syrie(temps_utc);

	/* Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Iran */
	application_du_changement_d_heure_pour_l_iran(temps_utc);

	/* Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour les Fidji */
	application_du_changement_d_heure_pour_les_fidji(temps_utc);

	/* Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Australie */
	application_du_changement_d_heure_pour_l_australie("Australia/Sydney", temps_utc);
	application_du_changement_d_heure_pour_l_australie("Australia/Currie", temps_utc);
	application_du_changement_d_heure_pour_l_australie("Australia/Hobart", temps_utc);
	application_du_changement_d_heure_pour_l_australie("Australia/Melbourne", temps_utc);
	application_du_changement_d_heure_pour_l_australie("Australia/Adelaide", temps_utc);
	application_du_changement_d_heure_pour_l_australie("Australia/Broken_Hill", temps_utc);
	application_du_changement_d_heure_pour_l_australie("Pacific/Norfolk", temps_utc);

	/* Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour Israël */
	application_du_changement_d_heure_pour_israel(temps_utc);

	/* Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour le Liban */
	application_du_changement_d_heure_pour_le_liban(temps_utc);

	/* Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour la Jordanie */
	application_du_changement_d_heure_pour_la_jordanie(temps_utc);

	/* Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour le Brésil */
	application_du_changement_d_heure_pour_le_bresil("America/Sao_Paulo", temps_utc);
	application_du_changement_d_heure_pour_le_bresil("America/Cuiaba", temps_utc);
	application_du_changement_d_heure_pour_le_bresil("America/Campo_Grande", temps_utc);

	/* Vérification de l'application de l'heure d'été ou non pour la Palestine */
	application_du_changement_d_heure_pour_la_palestine("Asia/Hebron", temps_utc);
	application_du_changement_d_heure_pour_la_palestine("Asia/Gaza", temps_utc);

	/* Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour la Grande-Bretagne */
	application_du_changement_d_heure_pour_la_grande_bretagne("Europe/London", temps_utc);
	application_du_changement_d_heure_pour_la_grande_bretagne("Europe/Isle_of_Man", temps_utc);
	application_du_changement_d_heure_pour_la_grande_bretagne("Europe/Jersey", temps_utc);
	application_du_changement_d_heure_pour_la_grande_bretagne("Europe/Guernsey", temps_utc);

	/* Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord */
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Miquelon", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Thule", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Nassau", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Port-au-Prince", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Havana", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("Atlantic/Bermuda", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Grand_Turk", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Toronto", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Pangnirtung", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Thunder_Bay", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Nipigon", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Iqaluit", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Winnipeg", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Resolute", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Rankin_Inlet", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Rainy_River", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Whitehorse", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Vancouver", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Dawson", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/St_Johns", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Moncton", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Halifax", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Goose_Bay", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Glace_Bay", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Inuvik", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Edmonton", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Cambridge_Bay", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Yellowknife", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/New_York", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Los_Angeles", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Juneau", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Yakutat", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Menominee", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Chicago", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Boise", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Denver", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Anchorage", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Detroit", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Metlakatla", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Sitka", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Nome", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Adak", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Kentucky/Louisville", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Kentucky/Monticello", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Indiana/Winamac", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Indiana/Vincennes", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Indiana/Vevay", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Indiana/Petersburg", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Indiana/Marengo", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Indiana/Indianapolis", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/North_Dakota/New_Salem", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/North_Dakota/Center", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/North_Dakota/Beulah", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Indiana/Tell_City", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Indiana/Knox", temps_utc);

	/* Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord */
	application_du_changement_d_heure_pour_le_mexique("America/Mexico_City", temps_utc);
	application_du_changement_d_heure_pour_le_mexique("America/Monterrey", temps_utc);
	application_du_changement_d_heure_pour_le_mexique("America/Chihuahua", temps_utc);
	application_du_changement_d_heure_pour_le_mexique("America/Mazatlan", temps_utc);
	application_du_changement_d_heure_pour_le_mexique("America/Merida", temps_utc);
	application_du_changement_d_heure_pour_le_mexique("America/Bahia_Banderas", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Ojinaga", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Tijuana", temps_utc);
	application_du_changement_d_heure_pour_l_amerique_du_nord("America/Matamoros", temps_utc);

	/* Calcul des horaires de différents villes du monde et affectation de la valeur calculée à une variable correspondante */

	/* République française */
	time_t heure_de_paris = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Paris"); //Paris
	time_t heure_de_cayenne = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Cayenne"); //Cayenne
	time_t heure_de_la_reunion = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Indian/Reunion"); //La Reunion
	time_t heure_de_la_guadeloupe = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Guadeloupe"); //Guadeloupe
	time_t heure_de_noumea = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Noumea"); //Nouméa
	time_t heure_de_mayotte = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Indian/Mayotte"); //Mayotte
	time_t heure_des_iles_kerguelen = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Indian/Kerguelen"); //îles Kerguelen
	time_t heure_de_tahiti = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Tahiti"); //Tahiti
	time_t heure_de_gambier = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Gambier"); //Gambier
	time_t heure_a_marquesas = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Marquesas"); //îles Marquises
	time_t heure_de_miquelon = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Miquelon"); //Miquelon
	time_t heure_de_st_barthelemy = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/St_Barthelemy"); //St Barthélemy
	time_t heure_de_la_martinique = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Martinique"); //La Martinique
	time_t heure_de_wallis = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Wallis"); //Wallis et Futuna

	/* Principauté de Monaco */
	time_t heure_a_monaco = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Monaco"); //Monaco

	/* Royaume d'Espagne */
	time_t heure_a_madrid = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Madrid"); //Madrid
	time_t heure_a_ceuta = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Ceuta"); //Ceuta
	time_t heure_aux_iles_canaries = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Atlantic/Canary"); //îles Canaries

	/* République portugaise */
	time_t heure_a_lisbonne = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Lisbon"); //Lisbonne
	time_t heure_aux_acores = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Atlantic/Azores"); //Açores
	time_t heure_a_madere = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Atlantic/Madeira"); //Madère

	/* Grand-Duché de Luxembourg */
	time_t heure_au_luxembourg = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Luxembourg"); //Luxembourg

	/* Royaume de Belgique */
	time_t heure_a_bruxelles = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Brussels"); //Bruxelles

	/* Royaume des Pays-Bas */
	time_t heure_d_amsterdam = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Amsterdam"); //Amsterdam
	time_t heure_d_aruba = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Aruba"); //Aruba
	time_t heure_de_kralendijk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Kralendijk"); //Kralendijk
	time_t heure_de_curacao = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Curacao"); //Curaçao
	time_t heure_a_lower_princes = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Lower_Princes"); //Lower Princes

	/* République fédérale d'Allemagne */
	time_t heure_de_berlin = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Berlin"); //Berlin
	time_t heure_de_busingen = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Busingen"); //Busingen

	/* Royaume de Danemark */
	time_t heure_a_copenhague = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Copenhagen"); //Copenhague
	time_t heure_aux_iles_feroes = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Atlantic/Faroe"); // Iles Féroé
	time_t heure_a_scoresbysund = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Scoresbysund"); //Scoresbysund
	time_t heure_a_godthab = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Godthab"); //Godthab
	time_t heure_a_thule = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Thule"); //Thule
	time_t heure_a_danmarkshavn = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Danmarkshavn"); //Danmarkshavn

	/* Royaume de Norvège */
	time_t heure_a_oslo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Oslo"); //Oslo
	time_t heure_a_longyearbyen = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Arctic/Longyearbyen"); //Longyearbyen

	/* Royaume de Suède */
	time_t heure_a_stockholm = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Stockholm"); //Stockholm

	/* République de Finlande */
	time_t heure_a_helsinki = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Helsinki"); //Helsinki
	time_t heure_a_mariehamn = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Mariehamn"); //Mariehamn

	/* République d'Islande */
	time_t heure_a_reykjavik = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Atlantic/Reykjavik"); //Reykjavik

	/* République de Pologne */
	time_t heure_a_varsovie = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Warsaw"); //Varsovie

	/* République de Lituanie */
	time_t heure_a_vilnius = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Vilnius"); //Vilnius

	/* République de Lettonie */
	time_t heure_a_riga = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Riga"); //Riga

	/* République d’Estonie */
	time_t heure_a_tallinn = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Tallinn"); //Tallinn

	/* République italienne */
	time_t heure_de_rome = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Rome"); //Rome

	/* État de la Cité du Vatican */
	time_t heure_du_vatican = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Vatican"); //Vatican

	/* République de Saint-Marin */
	time_t heure_a_saint_marin = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/San_Marino"); //Saint-Marin

	/* République d'Autriche */
	time_t heure_de_vienne = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Vienna"); //Vienne

	/* Hongrie */
	time_t heure_a_budapest = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Budapest"); //Budapest

	/* République tchèque */
	time_t heure_a_prague = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Prague"); //Prague

	/* République slovaque */
	time_t heure_a_bratislava = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Bratislava"); //Bratislava

	/* Roumanie */
	time_t heure_a_bucarest = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Bucharest"); //Bucarest

	/* République de Bulgarie */
	time_t heure_a_sofia = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Sofia"); //Sofia

	/* République de Macédoine du Nord */
	time_t heure_a_skopje = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Skopje"); //Skopje

	/* République de Slovénie */
	time_t heure_a_ljubljana = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Ljubljana"); //Ljubljana

	/* République de Croatie */
	time_t heure_a_zagreb = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Zagreb"); //Zagreb

	/* Bosnie-Herzégovine */
	time_t heure_a_sarajevo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Sarajevo"); //Sarajevo

	/* Monténégro */
	time_t heure_a_podgorica = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Podgorica"); //Podgorica

	/* République de Serbie */
	time_t heure_a_belgrade = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Belgrade"); //Belgrade

	/* République d'Albanie */
	time_t heure_a_tirane = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Tirane"); //Tirane

	/* République de Biélorussie */
	time_t heure_a_minsk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Minsk"); //Minsk

	/* Ukraine */
	time_t heure_a_kiev = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Kiev"); //Kiev
	time_t heure_a_uzhgorod = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Uzhgorod"); //Uzhgorod
	time_t heure_a_zaporozhye = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Zaporozhye"); //Zaporozhye
	time_t heure_a_simferopol = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Simferopol"); //Simferopol

	/* République de Moldavie */
	time_t heure_a_chisinau = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Chisinau"); //Chisinau
	time_t heure_a_tiraspol = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Tiraspol"); //Tiraspol

	/* Commonwealth des Bahamas */
	time_t heure_a_nassau = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Nassau"); //Nassau

	/* République du Suriname */
	time_t heure_a_paramaribo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Paramaribo"); //Paramaribo

	/* République coopérative du Guyana */
	time_t heure_a_guyana = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Guyana"); //Guyana

	/* République de Trinité-et-Tobago */
	time_t heure_a_port_d_espagne = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Port_of_Spain"); //Port d'Espagne

	/* Jamaïque */
	time_t heure_en_jamaique = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Jamaica"); //Jamaique

	/* Fédération de Saint-Christophe-et-Niévès, Saint-Christophe-et-Nevis */
	time_t heure_a_st_kitt = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/St_Kitts"); //St kitt

	/* Saint-Vincent-et-les-Grenadines */
	time_t heure_a_st_vincent = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/St_Vincent"); //Saint-Vincent

	/* Sainte-Lucie */
	time_t heure_a_sainte_lucie = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/St_Lucia"); //Sainte-Lucie

	/* République dominicaine */
	time_t heure_a_st_domingue = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Santo_Domingo"); //St Domingue

	/* République d'Haïti */
	time_t heure_a_port_au_prince = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Port-au-Prince"); //Port-au-Prince

	/* République de Cuba */
	time_t heure_a_la_havane = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Havana"); //La Havane

	/* Antarctique */
	time_t heure_pour_la_base_antarctique_de_casey = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/Casey"); //Base antarctique de Casey
	time_t heure_pour_la_base_antarctique_de_davis = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/Davis"); //Base antarctique de Davis
	time_t heure_pour_la_base_antarctique_de_dumontdurville = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/DumontDUrville"); //Base antarctique de Dumont-d'Urville
	time_t heure_pour_la_base_antarctique_de_mawson = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/Mawson"); //Base antarctique de Mawson
	time_t heure_pour_la_base_antarctique_de_mcmurdo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/McMurdo"); //Base antarctique de McMurdo 
	time_t heure_pour_la_base_antarctique_de_palmer = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/Palmer"); //Base antarctique de Palmer
	time_t heure_pour_la_base_antarctique_de_rothera = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/Rothera"); //Base antarctique de Rothera
	time_t heure_pour_la_base_antarctique_de_syowa = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/Syowa"); //Base antarctique de Syowa	
	time_t heure_pour_la_base_antarctique_de_vostok = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/Vostok"); //Base antarctique de Vostok
	time_t heure_pour_la_base_antarctique_de_troll = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/Troll"); //Base antarctique de Troll

	/* États-Unis d'Amérique */
        time_t heure_los_angeles = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Los_Angeles"); //Los Angeles
        time_t heure_de_nyc = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/New_York"); //New York City
        time_t heure_de_phoenix = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Phoenix"); //Phoenix
	time_t heure_a_honolulu = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Honolulu"); //Honolulu
	time_t heure_a_johnston = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Johnston"); //Johnston
	time_t heure_a_juneau = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Juneau"); //Juneau
	time_t heure_a_yakutat = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Yakutat"); //Yakutat
	time_t heure_a_menominee = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Menominee"); //Menominee
	time_t heure_a_chicago = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Chicago"); //Chicago
	time_t heure_a_boise = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Boise"); //Boise
	time_t heure_a_denver = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Denver"); //Denvers
	time_t heure_a_anchorage = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Anchorage"); //Anchorage
	time_t heure_a_detroit = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Detroit"); //Detroit
	time_t heure_a_metlakatla = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Metlakatla"); //Metlakatla
	time_t heure_a_sitka = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Sitka"); //Sitka
	time_t heure_a_nome = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Nome"); //Nome
	time_t heure_a_adak = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Adak"); //Adak
	time_t heure_a_kentucky_louiseville = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Kentucky/Louisville"); //Kentucky Louiseville
	time_t heure_a_kentucky_monticello = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Kentucky/Monticello"); //Kentucky Monticello
	time_t heure_a_indiana_winamac = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Indiana/Winamac"); //Indiana Winamac
	time_t heure_a_indiana_vincennes = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Indiana/Vincennes"); //Indiana Vincennes
	time_t heure_a_indiana_vevay = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Indiana/Vevay"); //Indiana Vevay
	time_t heure_a_indiana_petersburg = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Indiana/Petersburg"); //Indiana Petersburg
	time_t heure_a_indiana_marengo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Indiana/Marengo"); //Indiana Marengo
	time_t heure_a_indiana_indianapolis = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Indiana/Indianapolis"); //Indiana Indianapolis
	time_t heure_a_north_dakota_new_salem = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/North_Dakota/New_Salem"); //North Dakota New Salem
	time_t heure_a_north_dakota_center = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/North_Dakota/Center"); //North Dakota Center
	time_t heure_a_north_dakota_beulah = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/North_Dakota/Beulah"); //North Dakota Beulah
	time_t heure_a_indiana_tell_city = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Indiana/Tell_City"); //Indiana Tell City
	time_t heure_a_indiana_knox = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Indiana/Knox"); //Indiana Knox
	time_t heure_a_st_thomas = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/St_Thomas"); //îles Vierges des États-Unis
	time_t heure_a_pago_pago = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Pago_Pago"); //Samoa américaines
	time_t heure_a_guam = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Guam"); //Guam
	time_t heure_a_wake = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Wake"); //Wake
	time_t heure_a_midway = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Midway"); //Midway + Îles mineures éloignées des États-Unis

	/* Dominion du Canada */
	time_t heure_de_toronto = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Toronto"); //Toronto
	time_t heure_d_atikokan = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Atikokan"); //Atikokan
	time_t heure_de_pangnirtung = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Pangnirtung"); //Pangnirtung
	time_t heure_de_thunder_bay = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Thunder_Bay"); //Thunder Bay
	time_t heure_de_nipigon = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Nipigon"); //Nipigon
	time_t heure_d_iqaluit = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Iqaluit"); //Iqaluit
	time_t heure_de_winnipeg = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Winnipeg"); //Winnipeg
	time_t heure_de_swift_current = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Swift_Current"); //Swift Current
	time_t heure_de_resolute = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Resolute"); //Resolute
	time_t heure_de_regina = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Regina"); //Regina
	time_t heure_de_rankin_inlet = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Rankin_Inlet"); //Rankin Inlet
	time_t heure_de_rainy_river = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Rainy_River"); //Rainy River
	time_t heure_de_whitehorse = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Whitehorse"); //Whitehorse
	time_t heure_de_vancouver = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Vancouver"); //Vancouver
	time_t heure_de_dawson = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Dawson"); //Dawson
	time_t heure_de_st_johns = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/St_Johns"); //St Johns
	time_t heure_de_blanc_sablon = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Blanc-Sablon"); //Blanc-Sablon
	time_t heure_de_moncton = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Moncton"); //Moncton
	time_t heure_d_halifax = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Halifax"); //Halifax
	time_t heure_de_goose_bay = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Goose_Bay"); //Goose Bay
	time_t heure_de_glace_bay = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Glace_Bay"); //Glace Bay
	time_t heure_d_inuvik = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Inuvik"); //Inuvik
	time_t heure_de_fort_nelson = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Fort_Nelson"); //Fort Nelson
	time_t heure_d_edmonton = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Edmonton"); //Edmonton
	time_t heure_de_dawson_creek = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Dawson_Creek"); //Dawson Creek
	time_t heure_de_creston = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Creston"); //Creston
	time_t heure_de_cambridge_bay = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Cambridge_Bay"); //Cambridge Bay
	time_t heure_d_yellowknife = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Yellowknife"); //Yellowknife

	/* États-Unis mexicains */
	time_t heure_de_mexico_city = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Mexico_City"); //Mexico City
	time_t heure_de_monterrey = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Monterrey"); //Monterrey
	time_t heure_de_cancun = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Cancun"); //Cancun
	time_t heure_de_chihuahua = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Chihuahua"); //Chihuahua
	time_t heure_de_hermosillo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Hermosillo"); //Hermosillo
	time_t heure_de_mazatlan = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Mazatlan"); //Mazatlan
	time_t heure_d_ojinaga = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Ojinaga"); //Ojinaga
	time_t heure_de_tijuana = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Tijuana"); //Tijuana
	time_t heure_de_merida = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Merida"); //Merida
	time_t heure_de_matamoros = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Matamoros"); //Matamoros
	time_t heure_de_bahia_banderas = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Bahia_Banderas"); //Bahia Banderas

	/* République du Nicaragua */
	time_t heure_managua = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Managua"); //Managua

	/* République du Salvador */
	time_t heure_d_el_salvador = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/El_Salvador"); //Salvador

	/* Belize */
	time_t heure_au_belize = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Belize"); //Belize

	/* République du Costa Rica */
	time_t heure_au_costa_rica = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Costa_Rica"); //Costa Rica

	/* République du Honduras */
	time_t heure_au_honduras = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Tegucigalpa"); //Tegucigalpa

	/* République du Guatemala */
	time_t heure_au_guatemala = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Guatemala"); //Guatemala

	/* Confédération suisse */
	time_t heure_zurich = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Zurich"); //Zurich

	/* République de Malte */
	time_t heure_malte = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Malta"); //Malte

	/* Principauté d'Andorre */
	time_t heure_andorre = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Andorra"); //Andorre

	/* Principauté de Liechtenstein */
	time_t heure_vaduz = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Vaduz"); //Vaduz

	/* République hellénique */
	time_t heure_d_athenes = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Athens"); //Athènes

	/* République de Chypre */
	time_t heure_de_nicosia = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Nicosia"); //Nicosie

	/* Royaume-Uni de Grande-Bretagne et d'Irlande du Nord */
	time_t heure_de_londres = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/London"); //Londres
	time_t heure_aux_bermudes = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Atlantic/Bermuda"); //Bermudes
	time_t heure_a_grand_turk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Grand_Turk"); //Grand Turk
	time_t heure_a_tortola = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Tortola"); //Tortola
	time_t heure_a_st_helena = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Atlantic/St_Helena"); //St Hélène
	time_t heure_a_stanley = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Atlantic/Stanley"); //Stanley
	time_t heure_a_gibraltar = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Gibraltar"); //Gibraltar
	time_t heure_a_anguilla = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Anguilla"); //Anguilla
	time_t heure_a_south_georgia = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Atlantic/South_Georgia"); //Géorgie du Sud-et-les îles Sandwich du Sud
	time_t heure_a_cayman = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Cayman"); //Îles Caïmans
	time_t heure_a_montserrat = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Montserrat"); //Montserrat
	time_t heure_a_pitcairn = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Pitcairn"); //Îles Pitcairn
	time_t heure_a_chagos = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Indian/Chagos"); //Territoire britannique de l'océan Indien

	/* République d'Irlande */
	time_t heure_a_dublin = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Dublin"); //Dublin

	/* île de Man */
	time_t heure_a_l_ile_de_man = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Isle_of_Man"); //Île de Man

	/* Jersey */
	time_t heure_a_jersey = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Jersey"); //Jersey

	/* Guernsey */
	time_t heure_a_gernsey = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Guernsey"); //Guernsey	

	/* Niue */
	time_t heure_de_niue = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Niue"); //Niue

	/* Commonwealth d'Australie */
        time_t heure_a_sydney = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Sydney"); //Sydney
	time_t heure_a_macquarie = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/Macquarie"); //Macquarie
	time_t heure_a_adelaide = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Adelaide"); //Adelaide
	time_t heure_a_broken_hill = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Broken_Hill"); //Broken Hill
	time_t heure_a_darwin = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Darwin"); //Darwin
	time_t heure_a_brisbane = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Brisbane"); //Brisbane
	time_t heure_a_currie = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Currie"); //Currie
	time_t heure_a_hobart = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Hobart"); //Hobart
	time_t heure_a_lindeman = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Lindeman"); //Lindeman
	time_t heure_a_melbourne = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Melbourne"); //Melbourne
	time_t heure_a_eucla = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Eucla"); //Eucla
	time_t heure_a_lord_howe = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Lord_Howe"); //Lord Howe
	time_t heure_a_perth = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Perth"); //Perth
	time_t heure_aux_cocos = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Indian/Cocos"); //Cocos
	time_t heure_a_l_ile_christmas = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Indian/Christmas"); //Christmas
	time_t heure_a_l_ile_norfolk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Norfolk"); //Île Norfolk

	/* République des Fidji */
	time_t heure_aux_fidji = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Fiji"); //Fidji

	/* État indépendant des Samoa */
	time_t heure_a_apia = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Apia");

	/* République fédérative du Brésil */
	time_t heure_a_sao_paulo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Sao_Paulo"); //Sao Paulo
	time_t heure_a_araguaina = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Araguaina"); //Araguaina
	time_t heure_a_bahia = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Bahia"); //Bahia
	time_t heure_a_belem = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Belem"); //Belem
	time_t heure_a_fortaleza = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Fortaleza"); //Fortaleza
	time_t heure_a_maceio = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Maceio"); //Maceio
	time_t heure_a_recife = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Recife"); //Recife
	time_t heure_a_santarem = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Santarem"); //Santarem
	time_t heure_a_boa_vista = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Boa_Vista"); //Boa Vista
	time_t heure_a_campo_grande = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Campo_Grande"); //Campo Grande
	time_t heure_a_cuiaba = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Cuiaba"); //Cuiaba
	time_t heure_a_manaus = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Manaus"); //Manaus
	time_t heure_a_porto_velho = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Porto_Velho"); //Porto Velho
	time_t heure_a_eirunepe = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Eirunepe"); //Eirunepe
	time_t heure_a_rio_branco = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Rio_Branco"); //Rio Branco
	time_t heure_a_noronha = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Noronha"); //Noronha

	/* République du Chili */
        time_t heure_santiago_chili = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Santiago"); //Santiago du Chili
	time_t heure_a_punta_arenas = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Punta_Arenas"); //Punta Arenas
	time_t heure_ile_de_paques = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Easter"); //Ile de Pâques

	/* République du Paraguay */
	time_t heure_a_asuncion = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Asuncion"); //Asuncion

	/* Royaume du Maroc */
	time_t heure_a_casablanca = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Casablanca"); //Casablanca
	time_t heure_a_laayoune = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/El_Aaiun"); //Laayoune

	/* République algérienne démocratique et populaire */
	time_t heure_a_alger = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Algiers"); //Alger

	/* République du Soudan */
	time_t heure_a_khartoum = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Khartoum"); //Khartoum

	/* République du Soudan du Sud */
	time_t heure_a_djouba = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Juba"); //Djouba

	/* République du Mozambique */
	time_t heure_a_maputo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Maputo"); //Maputo

	/* Union des Comores */
	time_t heure_aux_comores = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Indian/Comoro"); //Comores

	/* République des Maldives */
	time_t heure_aux_maldives = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Indian/Maldives"); //Maldives

	/* République de Maurice */
	time_t heure_a_maurice = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Indian/Mauritius"); //Maurice

	/* Royaume du Lesotho */
	time_t heure_a_maseru = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Maseru"); //Maseru

	/* Royaume d'Eswatini */
	time_t heure_a_mbabane = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Mbabane"); //Mbabane

	/* République du Botswana */
	time_t heure_a_gaborone = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Gaborone"); //Gaborone

	/* République de Namibie */
	time_t heure_windhoek = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Windhoek"); //Windhoek

	/* République d'Afrique du Sud */
        time_t heure_johannesburg = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Johannesburg"); //Johannesburg

	/* État de Libye */
	time_t heure_tripoli = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Tripoli"); //Tripoli

	/* État d'Érythrée */
	time_t heure_a_asmara = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Asmara"); //Asmara

	/* République fédérale de Somalie */
	time_t heure_a_mogadiscio = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Mogadishu"); //Mogadiscio

	/* République démocratique fédérale d’Éthiopie */
	time_t heure_addis_abeba = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Addis_Ababa"); //Addis-Abeba

	/* République gabonaise */
	time_t heure_a_libreville = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Libreville"); //Libreville

	/* République du Cameroun */
	time_t heure_a_douala = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Douala"); //Douala

	/* République de Guinée équatoriale */
	time_t heure_a_malabo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Malabo"); //Malabo

	/* République fédérale du Nigeria */
	time_t heure_a_lagos = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Lagos"); //Lagos

	/* République du Bénin */
	time_t heure_a_porto_novo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Porto-Novo"); //Porto-Novo

	/* République togolaise */
	time_t heure_a_lome = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Lome"); //Lome

	/* République du Ghana */
	time_t heure_a_accra = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Accra"); //Accra

	/* République de Djibouti */
	time_t heure_djibouti = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Djibouti"); //Djibouti

	/* République du Congo */
	time_t heure_a_brazzaville = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Brazzaville"); //Brazzaville

	/* République démocratique du Congo */
	time_t heure_a_kinshasa = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Kinshasa"); //Kinshasa
	time_t heure_a_lubumbashi = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Lubumbashi"); //Lubumbashi

	/* République unie de Tanzanie */
	time_t heure_a_dar_es_salam = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Dar_es_Salaam"); //Dar_es_Salam

	/* République du Kenya */
	time_t heure_a_nairobi = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Nairobi"); //Nairobi

	/* République d'Ouganda */
	time_t heure_a_kampala = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Kampala"); //Kampala

	/* République centrafricaine */
	time_t heure_a_bangui = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Bangui"); //Bangui

	/* République du Mali */
	time_t heure_a_bamako = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Bamako"); //Bamako

	/* République islamique de Mauritanie */
	time_t heure_a_nouakchott = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Nouakchott"); //Nouakchott

	/* République de Côte d'Ivoire */
	time_t heure_a_abidjan = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Abidjan"); //Abidjan

	/* République de Guinée */
	time_t heure_a_conakry = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Conakry"); //Conakry

	/* République de Sierra Leone */
	time_t heure_a_freetown = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Freetown"); //Freetown

	/* République du Liberia */
	time_t heure_a_morovia = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Monrovia"); //Morovia

	/* République du Burundi */
	time_t heure_a_bujumbura = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Bujumbura"); //Bujumbura

	/* République du Malawi */
	time_t heure_a_blantyre = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Blantyre"); //Blantyre

	/* République du Sénégal */
	time_t heure_a_dakar = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Dakar"); //Dakar

	/* République de Zambie */
	time_t heure_lusaka = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Lusaka"); //Lusaka

	/* Burkina Faso */
	time_t heure_a_ouagadougou = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Ouagadougou"); //Ouagadougou

	/* République tunisienne */
	time_t heure_a_tunis = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Tunis"); //Tunis

	/* République du Cap-Vert */
	time_t heure_au_cap_vert = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Atlantic/Cape_Verde"); //Cap-Vert

	/* République de Gambie */
	time_t heure_a_banjul = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Banjul"); //Banjul

	/* République démocratique de Sao Tomé-et-Principe */
	time_t heure_a_sao_tome = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Sao_Tome"); //Sao Tome

	/* République de Guinée-Bissau */
	time_t heure_a_bissau = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Bissau"); //Bissau

	/* République du Tchad */
	time_t heure_a_ndjamena = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Ndjamena"); //Ndjamena

	/* République du Rwanda */
	time_t heure_a_kigali = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Kigali"); //Kigali

	/* République du Niger */
	time_t heure_a_niamey = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Niamey"); //Niamey

	/* République arabe d'Égypte */
	time_t heure_le_caire = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Cairo"); //Le Caire

	/* République de Zimbabwe */
	time_t heure_harare = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Harare"); //Harare

	/* Nouvelle-Zélande */
	time_t heure_a_auckland = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Auckland"); //Auckland
	time_t heure_a_chatham = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Chatham"); //île Chatham
	time_t heure_a_fakaofo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Fakaofo"); //Fakaofo

	/* îles Cook */
	time_t heure_a_rarotonga = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Rarotonga"); //Rarotonga

	/* Royaume de Tonga */
	time_t heure_a_togatapu = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Tongatapu"); //Togatapu

	/* République des Îles Marshall */
	time_t heure_a_majuro = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Majuro"); //Majuro
	time_t heure_a_kwajalein = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Kwajalein"); //Kwajalein

	/* République de Vanuatu */
	time_t heure_a_efate = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Efate"); //Efate

	/* État des Tuvalu */
	time_t heure_a_funafuti = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Funafuti"); //Funafuti

	/* République de Nauru */
	time_t heure_de_nauru = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Nauru"); //Nauru

	/* République des Kiribati */
	time_t heure_a_tarawa = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Tarawa"); //Tarawa
	time_t heure_a_kiritimati = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Kiritimati"); //Kiritimati
	time_t heure_a_enderbury = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Enderbury"); //Enderbury

	/* République du Panama */
	time_t heure_au_panama = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Panama"); //Panama

	/* République argentine */
        time_t heure_buenos_aires = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Argentina/Buenos_Aires"); //Buenos Aires
	time_t heure_a_catamarca = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Argentina/Catamarca"); //Catamarca
	time_t heure_a_cordoba = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Argentina/Cordoba"); //Cordoba
	time_t heure_a_jujuy = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Argentina/Jujuy"); //Jujuy
	time_t heure_a_la_rioja = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Argentina/La_Rioja"); //La Rioja
	time_t heure_a_mendoza = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Argentina/Mendoza"); //Mendoza
	time_t heure_a_rio_gallegos = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Argentina/Rio_Gallegos"); //Rio Gallegos
	time_t heure_a_salta = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Argentina/Salta"); //Salta
	time_t heure_a_san_juan = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Argentina/San_Juan"); //San Juan
	time_t heure_a_san_luis = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Argentina/San_Luis"); //San Luis
	time_t heure_a_tucuman = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Argentina/Tucuman"); //Tucuman
	time_t heure_a_ushuaia = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Argentina/Ushuaia"); //Ushuaia

	/* République orientale de l'Uruguay */
	time_t heure_a_montevideo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Montevideo"); //Montevideo

	/* République bolivarienne du Venezuela */
	time_t heure_a_caracas = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Caracas"); //Caracas

	/* République de l'Équateur */
	time_t heure_a_guayaquil = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Guayaquil"); //Guayaquil
	time_t heure_a_galapagos = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Galapagos"); //Galapagos

	/* État plurinational de Bolivie */
	time_t heure_a_la_paz = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/La_Paz"); //La Paz

	/* République de Madagascar */
        time_t heure_antananarivo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Indian/Antananarivo"); //Antananarivo

	/* République du Pérou */
        time_t heure_lima = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Lima"); //Lima

	/* République de Colombie */
	time_t heure_a_bogota = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Bogota"); //Bogota

	/* République arabe syrienne */
	time_t heure_a_damas = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Damascus"); //Damas

	/* État d'Israël */
	time_t heure_a_jerusalem = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Jerusalem"); //Jerusalem

	/* État de Palestine */
	time_t heure_a_gaza = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Gaza"); //Gaza
	time_t heure_a_hebron = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Hebron"); //Hebron

	/* Royaume hachémite de Jordanie */
	time_t heure_a_amman = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Amman"); //Amman

	/* République libanaise */
	time_t heure_a_beyrouth = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Beirut"); //Beyrouth

	/* République d'Irak */
	time_t heure_a_baghdad = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Baghdad"); //Baghdad

	/* République islamique d'Iran */
	time_t heure_a_teheran = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Tehran"); //Téhéran

	/* État du Qatar */
	time_t heure_au_qatar = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Qatar"); //Qatar

	/* République du Yémen */
	time_t heure_a_aden = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Aden"); //Aden

	/* Royaume d'Arabie saoudite */
	time_t heure_a_riyad = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Riyadh"); //Riyad

	/* Sultanat d'Oman */
	time_t heure_a_mascate = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Muscat"); //Mascate

	/* Émirats arabes unis */
	time_t heure_a_dubai = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Dubai"); //Dubai

	/* Royaume de Bahreïn */
	time_t heure_au_bahrein = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Bahrain"); //Bahrein

	/* État du Koweït */
	time_t heure_au_koweit = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Kuwait"); //Koweit

	/* République islamique du Pakistan */
	time_t heure_a_karachi = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Karachi"); //Karachi

	/* République de l'Inde */
	time_t heure_a_calcutta = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Kolkata"); //Calcutta

	/* République démocratique socialiste du Sri Lanka */
	time_t heure_a_colombo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Colombo"); //Colombo

	/* République populaire du Bangladesh */
	time_t heure_a_dacca = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Dhaka");

	/* République du Kazakhstan */
	time_t heure_a_almaty = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Almaty"); //Almaty
	time_t heure_a_qostanay = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Qostanay"); //Qostanay
	time_t heure_a_aktaou = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Aqtau"); //Aktaou
	time_t heure_a_aktioube = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Aqtobe"); //Aktioubé
	time_t heure_a_atyrau = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Atyrau"); //Atyrau
	time_t heure_a_oural = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Oral"); //Oural
	time_t heure_a_qyzylorda = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Qyzylorda"); //Qyzylorda

	/* République d'Ouzbékistan */
	time_t heure_a_tachkent = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Tashkent"); //Tachkent
	time_t heure_a_samarkand = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Samarkand"); //Samarkand

	/* République du Tadjikistan */
	time_t heure_a_douchanbe = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Dushanbe"); //Douchanbé

	/* République kirghize */
	time_t heure_a_bichkek = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Bishkek"); //Bichkek

	/* République démocratique fédérale du Népal */
	time_t heure_a_katmandou = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Kathmandu"); //Katmandou

	/* République islamique d'Afghanistan */
	time_t heure_a_kaboul = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Kabul"); //Kaboul

	/* Royaume de Thaïlande */
	time_t heure_a_bangkok = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Bangkok"); //Bangkok

	/* République socialiste du Viêt Nam */
	time_t heure_a_ho_chi_minh_ville = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Ho_Chi_Minh"); //Hô Chi Minh Ville

	/* République populaire démocratique de Corée */
	time_t heure_pyongyang = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Pyongyang"); //Pyongyang

	/* République de Corée */
        time_t heure_seoul = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Seoul"); //Seoul

	/* Empire du Japon */
	time_t heure_tokyo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Tokyo"); //Tokyo

	/* Royaume du Bhoutan */
	time_t heure_a_thimphou = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Thimphu"); //Thimphou

	/* République populaire de Chine */
        time_t heure_shanghai = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Shanghai"); //Shanghai
	time_t heure_a_urumqi = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Urumqi"); //Urumqi

	/* Région administrative spéciale de Macao de la République populaire de Chine */
	time_t heure_a_macao = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Macau"); //Macao

	/* Région administrative spéciale de Hong Kong de la République populaire de Chine */
	time_t heure_a_hong_kong = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Hong_Kong"); //Hong Kong

	/* République démocratique populaire lao */
	time_t heure_a_vientiane = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Vientiane"); //Vientiane

	/* Royaume du Cambodge */
	time_t heure_a_phnom_penh = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Phnom_Penh"); //Phnom Penh

	/* République de l'Union du Myanmar */
	time_t heure_a_yagon = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Yangon"); //Yangon

	/* République démocratique du Timor oriental */
	time_t heure_a_dili = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Dili"); //Dili

	/* Negara Brunei Darussalam */
	time_t heure_brunei = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Brunei"); //Brunei

	/* Mongolie */
	time_t heure_a_choibalsan = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Choibalsan"); //Choibalsan
	time_t heure_a_ulaanbaatar = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Ulaanbaatar"); //Ulaanbaatar
	time_t heure_a_hovd = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Hovd"); //Hovd

	/* République de Chine (Taiwan) */
	time_t heure_a_tapei = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Taipei"); //Tapei

	/* République des Philippines */
	time_t heure_a_manille = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Manila"); //Manille

	/* République de Singapour */
	time_t heure_a_singapour = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Singapore"); //Singapour

	/* Îles Salomon */
	time_t heure_a_guadalcanal = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Guadalcanal"); //Guadalcanal

	/* Fédération de Malaisie */
	time_t heure_a_kuala_lumpur = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Kuala_Lumpur"); //Kuala Lumpur
	time_t heure_a_kuching = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Kuching"); //Kuching

	/* République d'Indonésie */
	time_t heure_a_jakarta = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Jakarta"); //Jakarta
	time_t heure_a_pontianak = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Pontianak"); //Pontianak
	time_t heure_a_jayapura = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Jayapura"); //Jayapura
	time_t heure_a_makassar = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Makassar"); //Makassar

	/* République des Seychelles */
	time_t heure_a_mahe = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Indian/Mahe"); //Mahe

	/* État indépendant de Papouasie-Nouvelle-Guinée */
	time_t heure_a_bougainville = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Bougainville"); //Bougainville
	time_t heure_a_port_moresby = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Port_Moresby"); //Port Moresby

	/* États fédérés de Micronésie */
	time_t heure_a_pohnpei = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Pohnpei"); //Pohnpei
	time_t heure_a_ponape = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Ponape"); //Ponape
	time_t heure_a_chuuk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Chuuk"); //Chuuk
	time_t heure_a_truk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Truk"); //Truk
	time_t heure_a_yap = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Yap"); //Yap
	time_t heure_a_kosrae = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Kosrae"); //kosrae

	/* République des Palaos */
	time_t heure_de_palau = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Palau"); //Palau

	/* îles Mariannes du Nord */
	time_t heure_a_saipan = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Saipan"); //Saipan

	/* Porto Rico */
	time_t heure_a_porto_rico = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Puerto_Rico"); //Porto Rico

	/* République de Turquie */
	time_t heure_a_istanbul = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Istanbul"); //Istanbul

	/* Fédération de Russie */
	time_t heure_moscou = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Moscow"); //Moscou
        time_t heure_vladivostok = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Vladivostok"); //Vladivostok
	time_t heure_kaliningrad = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Kaliningrad"); //Kaliningrad
	time_t heure_samara = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Samara"); //Samara
	time_t heure_volgograd = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Volgograd"); //Volgograd
	time_t heure_saratov = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Saratov"); //Saratov
	time_t heure_oulianovsk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Ulyanovsk"); //Oulianovsk
	time_t heure_astrakhan = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Astrakhan"); //Astrakhan
	time_t heure_anadyr = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Anadyr"); //Anadyr
	time_t heure_sakhalin = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Sakhalin"); //Sakhalin
	time_t heure_omsk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Omsk"); //Omsk
	time_t heure_tchita = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Chita"); //Tchita
	time_t heure_tomsk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Tomsk"); //Tomsk
	time_t heure_barnaoul = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Barnaul"); //Barnaoul
	time_t heure_magadan = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Magadan"); //Magadan
	time_t heure_iekaterinbourg = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Yekaterinburg"); //Iekaterinbourg
	time_t heure_yakoutsk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Yakutsk"); //Yakoutsk
	time_t heure_irkoutsk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Irkutsk"); //Irkoutsk
	time_t heure_khandyga = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Khandyga"); //Khandyga
	time_t heure_novokouznetsk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Novokuznetsk"); //Novokouznetsk
	time_t heure_nobossibirsk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Novosibirsk"); //Nobossibirsk
	time_t heure_krasnoyarsk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Krasnoyarsk"); //Krasnoyarsk
	time_t heure_oust_nera = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Ust-Nera"); //Oust-Nera
	time_t heure_srednekolymsk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Srednekolymsk"); //Srednekolymsk

	/* République d'Arménie */
	time_t heure_erevan = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Yerevan"); //Erevan

	/* Géorgie */
	time_t heure_a_tbilissi = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Tbilisi"); //Tbilissi

	/* République d'Azerbaïdjan */
	time_t heure_a_bakou = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Baku"); //Bakou

	/*Affichage des différents horiares calculés à coté des villes correspondantes*/

        printf("\n");
	printf("République française:\n");
        calcul_et_affichage_horaire(heure_de_paris, "Paris");
	calcul_et_affichage_horaire(heure_de_cayenne, "Cayenne");
	calcul_et_affichage_horaire(heure_de_la_reunion, "La Reunion");
	calcul_et_affichage_horaire(heure_de_la_guadeloupe, "La guadeloupe");
	calcul_et_affichage_horaire(heure_de_noumea, "Nouméa");
	calcul_et_affichage_horaire(heure_de_mayotte, "Mayotte");
	calcul_et_affichage_horaire(heure_des_iles_kerguelen, "îles Kerguelen");
	calcul_et_affichage_horaire(heure_de_tahiti, "Tahiti");
	calcul_et_affichage_horaire(heure_a_marquesas, "îles Marquises");
	calcul_et_affichage_horaire(heure_de_gambier, "Gambier");
	calcul_et_affichage_horaire(heure_de_miquelon, "Miquelon");
	calcul_et_affichage_horaire(heure_de_st_barthelemy, "St Barthélemy");
	calcul_et_affichage_horaire(heure_de_la_martinique, "Martinique");
	calcul_et_affichage_horaire(heure_de_wallis, "Wallis");
	calcul_et_affichage_horaire(heure_a_lower_princes, "Saint-Martin");

	printf("\n");
	printf("Principauté de Monaco:\n");
	calcul_et_affichage_horaire(heure_a_monaco, "Monaco");

	printf("\n");
	printf("Royaume d'Espagne:\n");
	calcul_et_affichage_horaire(heure_a_madrid, "Madrid");
	calcul_et_affichage_horaire(heure_a_ceuta, "Ceuta");
	calcul_et_affichage_horaire(heure_aux_iles_canaries, "îles Canaries");

	printf("\n");
	printf("République portugaise:\n");
	calcul_et_affichage_horaire(heure_a_lisbonne, "Lisbonne");
	calcul_et_affichage_horaire(heure_aux_acores, "Açores");
	calcul_et_affichage_horaire(heure_a_madere, "Madère");

	printf("\n");
	printf("Grand-Duché de Luxembourg:\n");
	calcul_et_affichage_horaire(heure_au_luxembourg, "Luxembourg");

	printf("\n");
	printf("Royaume de Belgique:\n");
	calcul_et_affichage_horaire(heure_a_bruxelles, "Bruxelles");

	printf("\n");
	printf("Royaume des Pays-Bas:\n");
	calcul_et_affichage_horaire(heure_d_amsterdam, "Amsterdam");
	calcul_et_affichage_horaire(heure_d_aruba, "Aruba");
	calcul_et_affichage_horaire(heure_de_kralendijk, "Kralendijk");
	calcul_et_affichage_horaire(heure_de_curacao, "Curacao");
	calcul_et_affichage_horaire(heure_a_lower_princes, "Sint Maarten");

	printf("\n");
	printf("République fédérale d'Allemagne:\n");
	calcul_et_affichage_horaire(heure_de_berlin, "Berlin");
	calcul_et_affichage_horaire(heure_de_busingen, "Busingen");

	printf("\n");
	printf("Royaume du Danemark:\n");
	calcul_et_affichage_horaire(heure_a_copenhague, "Copenhague");
	calcul_et_affichage_horaire(heure_aux_iles_feroes, "Iles Féroé");
	calcul_et_affichage_horaire(heure_a_scoresbysund, "Scoresbysund");
	calcul_et_affichage_horaire(heure_a_godthab, "Godthab");
	calcul_et_affichage_horaire(heure_a_thule, "Thule");
	calcul_et_affichage_horaire(heure_a_danmarkshavn, "Danmarkshavn");

	printf("\n");
	printf("Royaume de Norvège:\n");
	calcul_et_affichage_horaire(heure_a_oslo, "Oslo");
	calcul_et_affichage_horaire(heure_a_longyearbyen, "Longyearbyen");

	printf("\n");
	printf("Royaume de Suède:\n");
	calcul_et_affichage_horaire(heure_a_stockholm, "Stockholm");

	printf("\n");
	printf("République de Finlande:\n");
	calcul_et_affichage_horaire(heure_a_helsinki, "Helsinki");
	calcul_et_affichage_horaire(heure_a_mariehamn, "Mariehamn");

	printf("\n");
	printf("République d'Islande:\n");
	calcul_et_affichage_horaire(heure_a_reykjavik, "Reykjavik");

	printf("\n");
	printf("République de Pologne:\n");
	calcul_et_affichage_horaire(heure_a_varsovie, "Varsovie");

	printf("\n");
	printf("République de Lituanie:\n");
	calcul_et_affichage_horaire(heure_a_vilnius, "Vilnius");

	printf("\n");
	printf("République de Lettonie:\n");
	calcul_et_affichage_horaire(heure_a_riga, "Riga");

	printf("\n");
	printf("République d’Estonie:\n");
	calcul_et_affichage_horaire(heure_a_tallinn, "Tallinn");

	printf("\n");
	printf("République italienne:\n");
	calcul_et_affichage_horaire(heure_de_rome, "Rome");

	printf("\n");
	printf("État de la Cité du Vatican:\n");
	calcul_et_affichage_horaire(heure_du_vatican, "Vatican");

	printf("\n");
	printf("République de Saint-Marin:\n");
	calcul_et_affichage_horaire(heure_a_saint_marin, "Saint-Marin");

	printf("\n");
	printf("République d'Autriche:\n");
	calcul_et_affichage_horaire(heure_de_vienne, "Vienne");

	printf("\n");
	printf("Hongrie:\n");
	calcul_et_affichage_horaire(heure_a_budapest, "Budapest");

	printf("\n");
	printf("République tchèque:\n");
	calcul_et_affichage_horaire(heure_a_prague, "Prague");

	printf("\n");
	printf("République slovaque:\n");
	calcul_et_affichage_horaire(heure_a_bratislava, "Bratislava");

	printf("\n");
	printf("République de Biélorussie:\n");
	calcul_et_affichage_horaire(heure_a_minsk, "Minsk");

	printf("\n");
	printf("Ukraine:\n");
	calcul_et_affichage_horaire(heure_a_kiev, "Kiev");
	calcul_et_affichage_horaire(heure_a_uzhgorod, "Uzhgorod");
	calcul_et_affichage_horaire(heure_a_zaporozhye, "Zaporozhye");
	calcul_et_affichage_horaire(heure_a_simferopol, "Simferopol");

	printf("\n");
	printf("République de Moldavie:\n");
	calcul_et_affichage_horaire(heure_a_chisinau, "Chisinau");
	calcul_et_affichage_horaire(heure_a_tiraspol, "Tiraspol");

	printf("\n");
	printf("Confédération suisse:\n");
	calcul_et_affichage_horaire(heure_zurich, "Zurich");

	printf("\n");
	printf("Principauté d'Andorre:\n");
	calcul_et_affichage_horaire(heure_andorre, "Andorre");

	printf("\n");
	printf("République de Malte:\n");
	calcul_et_affichage_horaire(heure_malte, "Malte");

	printf("\n");
	printf("Principauté de Liechtenstein:\n");
	calcul_et_affichage_horaire(heure_vaduz, "Vaduz");

	printf("\n");
	printf("Roumanie:\n");
	calcul_et_affichage_horaire(heure_a_bucarest, "Bucarest");

	printf("\n");
	printf("République de Bulgarie:\n");
	calcul_et_affichage_horaire(heure_a_sofia, "Sofia");

	printf("\n");
	printf("République de Macédoine du Nord:\n");
	calcul_et_affichage_horaire(heure_a_skopje, "Skopje");

	printf("\n");
	printf("République de Slovénie:\n");
	calcul_et_affichage_horaire(heure_a_ljubljana, "Ljubljana");

	printf("\n");
	printf("République de Croatie:\n");
	calcul_et_affichage_horaire(heure_a_zagreb, "Zagreb");

	printf("\n");
	printf("Bosnie-Herzégovine:\n");
	calcul_et_affichage_horaire(heure_a_sarajevo, "Sarajevo");

	printf("\n");
	printf("Monténégro:\n");
	calcul_et_affichage_horaire(heure_a_podgorica, "Podgorica");

	printf("\n");
	printf("République de Serbie:\n");
	calcul_et_affichage_horaire(heure_a_belgrade, "Belgrade");

	printf("\n");
	printf("République d'Albanie:\n");
	calcul_et_affichage_horaire(heure_a_tirane, "Tirane");

	printf("\n");
	printf("République hellénique:\n");
	calcul_et_affichage_horaire(heure_d_athenes, "Athènes");

	printf("\n");
	printf("République de Chypre:\n");
	calcul_et_affichage_horaire(heure_de_nicosia, "Nicosie");

	printf("\n");
	printf("Commonwealth des Bahamas:\n");
	calcul_et_affichage_horaire(heure_a_nassau, "Nassau");

	printf("\n");
	printf("République du Suriname:\n");
	calcul_et_affichage_horaire(heure_a_paramaribo, "Paramaribo");

	printf("\n");
	printf("République coopérative du Guyana:\n");
	calcul_et_affichage_horaire(heure_a_guyana, "Guyana");

	printf("\n");
	printf("République de Trinité-et-Tobago:\n");
	calcul_et_affichage_horaire(heure_a_port_d_espagne, "Port d'Espagne");

	printf("\n");
	printf("République de Cuba:\n");
	calcul_et_affichage_horaire(heure_a_la_havane, "La Havane");

	printf("\n");
	printf("Jamaïque:\n");
	calcul_et_affichage_horaire(heure_en_jamaique, "Jamaique");

	printf("\n");
	printf("Fédération de Saint-Christophe-et-Niévès, Saint-Christophe-et-Nevis:\n");
	calcul_et_affichage_horaire(heure_a_st_kitt, "St kitt");

	printf("\n");
	printf("Saint-Vincent-et-les-Grenadines:\n");
	calcul_et_affichage_horaire(heure_a_st_vincent, "Saint-Vincent");

	printf("\n");
	printf("Sainte-Lucie:\n");
	calcul_et_affichage_horaire(heure_a_sainte_lucie, "Sainte-Lucie");

	printf("\n");
	printf("République dominicaine:\n");
	calcul_et_affichage_horaire(heure_a_st_domingue, "St Domingue");

	printf("\n");
	printf("République d'Haïti:\n");
	calcul_et_affichage_horaire(heure_a_port_au_prince, "Port-au-Prince");

	printf("\n");
	printf("États-Unis d'Amérique:\n");
        calcul_et_affichage_horaire(heure_los_angeles, "Los Angeles");
        calcul_et_affichage_horaire(heure_de_nyc, "New York City");
        calcul_et_affichage_horaire(heure_de_phoenix, "Phoenix");
	calcul_et_affichage_horaire(heure_a_honolulu, "Honolulu");
	calcul_et_affichage_horaire(heure_a_johnston, "Johnston");
	calcul_et_affichage_horaire(heure_a_juneau, "Juneau");
	calcul_et_affichage_horaire(heure_a_yakutat, "Yakutat");
	calcul_et_affichage_horaire(heure_a_menominee, "Menominee");
	calcul_et_affichage_horaire(heure_a_chicago, "Chicago");
	calcul_et_affichage_horaire(heure_a_boise, "Boise");
	calcul_et_affichage_horaire(heure_a_denver, "Denver");
	calcul_et_affichage_horaire(heure_a_anchorage, "Anchorage");
	calcul_et_affichage_horaire(heure_a_detroit, "Detroit");
	calcul_et_affichage_horaire(heure_a_metlakatla, "Metlakatla");
	calcul_et_affichage_horaire(heure_a_sitka, "Sikta");
	calcul_et_affichage_horaire(heure_a_nome, "Nome");
	calcul_et_affichage_horaire(heure_a_adak, "Adak");
	calcul_et_affichage_horaire(heure_a_kentucky_louiseville, "Louiseville");
	calcul_et_affichage_horaire(heure_a_kentucky_monticello, "Monticello");
	calcul_et_affichage_horaire(heure_a_indiana_winamac, "winamac");
	calcul_et_affichage_horaire(heure_a_indiana_vincennes, "Vincennes");
	calcul_et_affichage_horaire(heure_a_indiana_vevay, "Vevay");
	calcul_et_affichage_horaire(heure_a_indiana_petersburg, "Petersburg");
	calcul_et_affichage_horaire(heure_a_indiana_marengo, "Marengo");
	calcul_et_affichage_horaire(heure_a_indiana_indianapolis, "Indianapolis");
	calcul_et_affichage_horaire(heure_a_north_dakota_new_salem, "New Salem");
	calcul_et_affichage_horaire(heure_a_north_dakota_center, "Center");
	calcul_et_affichage_horaire(heure_a_north_dakota_beulah, "Beulah");
	calcul_et_affichage_horaire(heure_a_indiana_tell_city, "Tell City");
	calcul_et_affichage_horaire(heure_a_indiana_knox, "Knox");
	calcul_et_affichage_horaire(heure_a_st_thomas, "îles Vierges des États-Unis");
	calcul_et_affichage_horaire(heure_a_pago_pago, "Samoa américaines");
	calcul_et_affichage_horaire(heure_a_guam, "Guam");
	calcul_et_affichage_horaire(heure_a_wake, "Wake");
	calcul_et_affichage_horaire(heure_a_midway, "Îles mineures éloignées des États-Unis");

	printf("\n");
	printf("Dominion du Canada:\n");
	calcul_et_affichage_horaire(heure_de_toronto, "Toronto");
	calcul_et_affichage_horaire(heure_d_atikokan, "Atikokan");
	calcul_et_affichage_horaire(heure_de_pangnirtung, "Pangnirtung");
	calcul_et_affichage_horaire(heure_de_thunder_bay, "Thunder Bay");
	calcul_et_affichage_horaire(heure_de_nipigon, "Nipigon");
	calcul_et_affichage_horaire(heure_d_iqaluit, "Iqaluit");
	calcul_et_affichage_horaire(heure_de_winnipeg, "Winnipeg");
	calcul_et_affichage_horaire(heure_de_swift_current, "Swift Current");
	calcul_et_affichage_horaire(heure_de_resolute, "Resolute");
	calcul_et_affichage_horaire(heure_de_regina, "Regina");
	calcul_et_affichage_horaire(heure_de_rankin_inlet, "Rankin Inlet");
	calcul_et_affichage_horaire(heure_de_rainy_river, "Rainy River");
	calcul_et_affichage_horaire(heure_de_whitehorse, "Whitehorse");
	calcul_et_affichage_horaire(heure_de_vancouver, "Vancouver");
	calcul_et_affichage_horaire(heure_de_dawson, "Dawson");
	calcul_et_affichage_horaire(heure_de_st_johns, "St Johns");
	calcul_et_affichage_horaire(heure_de_blanc_sablon, "Blanc Sablon");
	calcul_et_affichage_horaire(heure_de_moncton, "Moncton");
	calcul_et_affichage_horaire(heure_d_halifax, "Halifax");
	calcul_et_affichage_horaire(heure_de_goose_bay, "Goose Bay");
	calcul_et_affichage_horaire(heure_de_glace_bay, "Glace Bay");
	calcul_et_affichage_horaire(heure_d_inuvik, "Inuvik");
	calcul_et_affichage_horaire(heure_de_fort_nelson, "Fort Nelson");
	calcul_et_affichage_horaire(heure_d_edmonton, "Edmonton");
	calcul_et_affichage_horaire(heure_de_dawson_creek, "Dawson Creek");
	calcul_et_affichage_horaire(heure_de_creston, "Creston");
	calcul_et_affichage_horaire(heure_de_cambridge_bay, "Cambridge Bay");
	calcul_et_affichage_horaire(heure_d_yellowknife, "Yellowknife");

	printf("\n");
	calcul_et_affichage_horaire(heure_de_mexico_city, "Mexico City");
	calcul_et_affichage_horaire(heure_de_monterrey, "Monterrey");
	calcul_et_affichage_horaire(heure_de_cancun, "Cancun");
	calcul_et_affichage_horaire(heure_de_chihuahua, "Chihuahua");
	calcul_et_affichage_horaire(heure_de_hermosillo, "Hermosillo");
	calcul_et_affichage_horaire(heure_de_mazatlan, "Mazatlan");
	calcul_et_affichage_horaire(heure_d_ojinaga, "Ojinaga");
	calcul_et_affichage_horaire(heure_de_tijuana, "Tijuana");
	calcul_et_affichage_horaire(heure_de_merida, "Merida");
	calcul_et_affichage_horaire(heure_de_matamoros, "Matamoros");
	calcul_et_affichage_horaire(heure_de_bahia_banderas, "Bahia Banderas");

	printf("\n");
	printf("République du Guatemala:\n");
	calcul_et_affichage_horaire(heure_au_guatemala, "Guatemala");

	printf("\n");
	printf("République du Salvador:\n");
	calcul_et_affichage_horaire(heure_d_el_salvador, "El Salvador");

	printf("\n");
	printf("République du Honduras:\n");
	calcul_et_affichage_horaire(heure_au_honduras, "Tegucigalpa");

	printf("\n");
	printf("Belize:\n");
	calcul_et_affichage_horaire(heure_au_belize, "Belize");

	printf("\n");
	printf("République du Nicaragua:\n");
	calcul_et_affichage_horaire(heure_managua, "Managua");

	printf("\n");
	printf("République du Costa Rica:\n");
	calcul_et_affichage_horaire(heure_au_costa_rica, "Costa Rica");

	printf("\n");
	printf("Royaume-Uni de Grande-Bretagne et d'Irlande du Nord:\n");
	calcul_et_affichage_horaire(heure_de_londres, "Londres");
	calcul_et_affichage_horaire(heure_aux_bermudes, "Bermudes");
	calcul_et_affichage_horaire(heure_a_grand_turk, "Grand Turk");
	calcul_et_affichage_horaire(heure_a_tortola, "Tortola");
	calcul_et_affichage_horaire(heure_a_st_helena, "St Hélène");
	calcul_et_affichage_horaire(heure_a_st_helena, "Île de l'Ascension");
	calcul_et_affichage_horaire(heure_a_st_helena, "Tristan da Cunha");
	calcul_et_affichage_horaire(heure_a_stanley, "Îles Malouines");
	calcul_et_affichage_horaire(heure_a_gibraltar, "Gibraltar");
	calcul_et_affichage_horaire(heure_a_anguilla, "Anguilla");
	calcul_et_affichage_horaire(heure_a_south_georgia, "Géorgie du Sud-et-les îles Sandwich du Sud");
	calcul_et_affichage_horaire(heure_a_cayman, "Îles Caïmans");
	calcul_et_affichage_horaire(heure_a_montserrat, "Montserrat");
	calcul_et_affichage_horaire(heure_d_athenes, "Akrotiri et Dhekelia");
	calcul_et_affichage_horaire(heure_a_chagos, "Territoire britannique de l'océan Indien");

	printf("\n");
	printf("République d'Irlande:\n");
	calcul_et_affichage_horaire(heure_a_dublin, "Dublin");

	printf("\n");
	printf("île de Man:\n");
	calcul_et_affichage_horaire(heure_a_l_ile_de_man, "Île de Man");

	printf("\n");
	printf("Jersey:\n");
	calcul_et_affichage_horaire(heure_a_jersey, "Jersey");

	printf("\n");
	printf("Guernsey:\n");
	calcul_et_affichage_horaire(heure_a_gernsey, "Guernsey");

	printf("\n");
	printf("Commonwealth d'Australie:\n");
        calcul_et_affichage_horaire(heure_a_sydney, "Sydney");
	calcul_et_affichage_horaire(heure_a_macquarie, "Macquarie");
	calcul_et_affichage_horaire(heure_a_adelaide, "Adelaide");
	calcul_et_affichage_horaire(heure_a_broken_hill, "Broken Hill");
	calcul_et_affichage_horaire(heure_a_darwin, "Darwin");
	calcul_et_affichage_horaire(heure_a_brisbane, "Brisbane");
	calcul_et_affichage_horaire(heure_a_currie, "Currie");
	calcul_et_affichage_horaire(heure_a_hobart, "Hobart");
	calcul_et_affichage_horaire(heure_a_lindeman, "Lindeman");
	calcul_et_affichage_horaire(heure_a_melbourne, "Melbourne");
	calcul_et_affichage_horaire(heure_a_eucla, "Eucla");
	calcul_et_affichage_horaire(heure_a_lord_howe, "Lord Howe");
	calcul_et_affichage_horaire(heure_a_perth, "Perth");
	calcul_et_affichage_horaire(heure_aux_cocos, "Cocos");
	calcul_et_affichage_horaire(heure_a_l_ile_christmas, "îles Christmas");
	calcul_et_affichage_horaire(heure_a_l_ile_norfolk, "îles Norfolk");

	printf("\n");
	printf("République des Fidji:\n");
	calcul_et_affichage_horaire(heure_aux_fidji, "Fidji");

	printf("\n");
	printf("État indépendant des Samoa:\n");
	calcul_et_affichage_horaire(heure_a_apia, "Apia");

	printf("\n");
	printf("Nouvelle-Zélande:\n");
	calcul_et_affichage_horaire(heure_a_auckland, "Auckland");
	calcul_et_affichage_horaire(heure_a_chatham, "Ile Chatham");
	calcul_et_affichage_horaire(heure_a_fakaofo, "Fakaofo");

	printf("\n");
	printf("îles Cook:\n");
	calcul_et_affichage_horaire(heure_a_rarotonga, "Rarotonga");

	printf("\n");
	printf("Royaume de Tonga:\n");
	calcul_et_affichage_horaire(heure_a_togatapu, "Togatapu");

	printf("\n");
	printf("République des Îles Marshall:\n");
	calcul_et_affichage_horaire(heure_a_majuro, "Majuro");
	calcul_et_affichage_horaire(heure_a_kwajalein, "Kwajalein");

	printf("\n");
	printf("Niue:\n");
	calcul_et_affichage_horaire(heure_de_niue, "Niue");

	printf("\n");
	printf("République de Vanuatu:\n");
	calcul_et_affichage_horaire(heure_a_efate, "Efate");

	printf("\n");
	printf("République islamique du Pakistan:\n");
	calcul_et_affichage_horaire(heure_a_karachi, "Karachi");

	printf("\n");
	printf("République démocratique socialiste du Sri Lanka:\n");
	calcul_et_affichage_horaire(heure_a_colombo, "Colombo");

	printf("\n");
	printf("République des Kiribati:\n");
	calcul_et_affichage_horaire(heure_a_tarawa, "Tarawa");
	calcul_et_affichage_horaire(heure_a_kiritimati, "Kiritimati");
	calcul_et_affichage_horaire(heure_a_enderbury, "Enderbury");

	printf("\n");
	printf("État des Tuvalu:\n");
	calcul_et_affichage_horaire(heure_a_funafuti, "Funafuti");

	printf("\n");
	printf("République de Nauru:\n");
	calcul_et_affichage_horaire(heure_de_nauru, "Nauru");

	printf("\n");
	printf("République fédérative du Brésil:\n");
	calcul_et_affichage_horaire(heure_a_sao_paulo, "Sao Paulo");
	calcul_et_affichage_horaire(heure_a_araguaina, "Araguaina");
	calcul_et_affichage_horaire(heure_a_bahia, "Bahia");
	calcul_et_affichage_horaire(heure_a_belem, "Belem");
	calcul_et_affichage_horaire(heure_a_fortaleza, "Fortaleza");
	calcul_et_affichage_horaire(heure_a_maceio, "Maceio");
	calcul_et_affichage_horaire(heure_a_recife, "Recife");
	calcul_et_affichage_horaire(heure_a_santarem, "Santarem");
	calcul_et_affichage_horaire(heure_a_boa_vista, "Boa Vista");
	calcul_et_affichage_horaire(heure_a_campo_grande, "Campo Grande");
	calcul_et_affichage_horaire(heure_a_cuiaba, "Cuiaba");
	calcul_et_affichage_horaire(heure_a_manaus, "Manaus");
	calcul_et_affichage_horaire(heure_a_porto_velho, "Porto Velho");
	calcul_et_affichage_horaire(heure_a_eirunepe, "Eirunepe");
	calcul_et_affichage_horaire(heure_a_rio_branco, "Rio Branco");
	calcul_et_affichage_horaire(heure_a_noronha, "Noronha");

	printf("\n");
	printf("République du Chili:\n");
        calcul_et_affichage_horaire(heure_santiago_chili, "Santiago du Chili");
	calcul_et_affichage_horaire(heure_a_punta_arenas, "Punta Arenas");
	calcul_et_affichage_horaire(heure_ile_de_paques, "Ile de Pâques");

	printf("\n");
	printf("République du Paraguay:\n");
	calcul_et_affichage_horaire(heure_a_asuncion, "Asuncion");

	printf("\n");
	printf("Royaume du Maroc:\n");
	calcul_et_affichage_horaire(heure_a_casablanca, "Casablanca");
	calcul_et_affichage_horaire(heure_a_laayoune, "Laayoune");

	printf("\n");
	printf("République algérienne démocratique et populaire:\n");
	calcul_et_affichage_horaire(heure_a_alger, "Alger");

	printf("\n");
	printf("République du Soudan:\n");
	calcul_et_affichage_horaire(heure_a_khartoum, "Khartoum");

	printf("\n");
	printf("République du Soudan du Sud:\n");
	calcul_et_affichage_horaire(heure_a_djouba, "Djouba");

	printf("\n");
	printf("République d'Afrique du Sud:\n");
        calcul_et_affichage_horaire(heure_johannesburg, "Johannesburg");

	printf("\n");
	printf("République du Panama:\n");
	calcul_et_affichage_horaire(heure_au_panama, "Panama");

	printf("\n");
	printf("République argentine:\n");
        calcul_et_affichage_horaire(heure_buenos_aires, "Buenos Aires");
	calcul_et_affichage_horaire(heure_a_catamarca, "Catamarca");
	calcul_et_affichage_horaire(heure_a_cordoba, "Cordoba");
	calcul_et_affichage_horaire(heure_a_jujuy, "Jujuy");
	calcul_et_affichage_horaire(heure_a_la_rioja, "La Rioja");
	calcul_et_affichage_horaire(heure_a_mendoza, "Mendoza");
	calcul_et_affichage_horaire(heure_a_rio_gallegos, "Rio Gallegos");
	calcul_et_affichage_horaire(heure_a_salta, "Salta");
	calcul_et_affichage_horaire(heure_a_san_juan, "San Juan");
	calcul_et_affichage_horaire(heure_a_san_luis, "San Luis");
	calcul_et_affichage_horaire(heure_a_tucuman, "Tucuman");
	calcul_et_affichage_horaire(heure_a_ushuaia, "Ushuaia");

	printf("\n");
	printf("République orientale de l'Uruguay:\n");
	calcul_et_affichage_horaire(heure_a_montevideo, "Montivideo");

	printf("\n");
	printf("République bolivarienne du Venezuela:\n");
	calcul_et_affichage_horaire(heure_a_caracas, "Caracas");

	printf("\n");
	printf("République de l'Équateur:\n");
	calcul_et_affichage_horaire(heure_a_guayaquil, "Guayaquil");
	calcul_et_affichage_horaire(heure_a_galapagos, "Galapagos");

	printf("\n");
	printf("République de Colombie:\n");
	calcul_et_affichage_horaire(heure_a_bogota, "Bogota");

	printf("\n");
	printf("État plurinational de Bolivie:\n");
	calcul_et_affichage_horaire(heure_a_la_paz, "La Paz");

	printf("\n");
	printf("République de Madagascar:\n");
        calcul_et_affichage_horaire(heure_antananarivo, "Antananarivo");

	printf("\n");
	printf("République du Congo:\n");
	calcul_et_affichage_horaire(heure_a_brazzaville, "Brazzaville");

	printf("\n");
	printf("République démocratique du Congo:\n");
	calcul_et_affichage_horaire(heure_a_kinshasa, "Kinshasa");
	calcul_et_affichage_horaire(heure_a_lubumbashi, "Lubumbashi");

	printf("\n");
	printf("République de Namibie:\n");
        calcul_et_affichage_horaire(heure_windhoek, "Windhoek");

	printf("\n");
	printf("République du Mozambique:\n");
	calcul_et_affichage_horaire(heure_a_maputo, "Maputo");

	printf("\n");
	printf("Union des Comores:\n");
	calcul_et_affichage_horaire(heure_aux_comores, "Comores");

	printf("\n");
	printf("République des Maldives:\n");
	calcul_et_affichage_horaire(heure_aux_maldives, "Maldives");

	printf("\n");
	printf("République de Maurice:\n");
	calcul_et_affichage_horaire(heure_a_maurice, "Maurice");

	printf("\n");
	printf("Royaume du Lesotho:\n");
	calcul_et_affichage_horaire(heure_a_maseru, "Maseru");

	printf("\n");
	printf("Royaume d'Eswatini:\n");
	calcul_et_affichage_horaire(heure_a_mbabane, "Mbabane");

	printf("\n");
	printf("République du Botswana:\n");
	calcul_et_affichage_horaire(heure_a_gaborone, "Gaborone");

	printf("\n");
	printf("État de Libye:\n");
	calcul_et_affichage_horaire(heure_tripoli, "Tripoli");

	printf("\n");
	printf("République arabe d'Égypte:\n");
	calcul_et_affichage_horaire(heure_le_caire, "Le Caire");

	printf("\n");
	printf("République d'Irak:\n");
	calcul_et_affichage_horaire(heure_a_baghdad, "Baghdad");

	printf("\n");
	printf("République islamique d'Iran:\n");
	calcul_et_affichage_horaire(heure_a_teheran, "Téhéran");

	printf("\n");
	printf("République arabe syrienne:\n");
	calcul_et_affichage_horaire(heure_a_damas, "Damas");

	printf("\n");
	printf("État d'Israël:\n");
	calcul_et_affichage_horaire(heure_a_jerusalem, "Jerusalem");

	printf("\n");
	printf("État de Palestine:\n");
	calcul_et_affichage_horaire(heure_a_gaza, "Gaza");
	calcul_et_affichage_horaire(heure_a_hebron, "Hebron");

	printf("\n");
	printf("Royaume hachémite de Jordanie:\n");
	calcul_et_affichage_horaire(heure_a_amman, "Amman");

	printf("\n");
	printf("République libanaise:\n");
	calcul_et_affichage_horaire(heure_a_beyrouth, "Beyrouth");

	printf("\n");
	printf("Royaume d'Arabie saoudite:\n");
	calcul_et_affichage_horaire(heure_a_riyad, "Riyad");

	printf("\n");
	printf("État du Qatar:\n");
	calcul_et_affichage_horaire(heure_au_qatar, "Qatar");

	printf("\n");
	printf("Émirats arabes unis:\n");
	calcul_et_affichage_horaire(heure_a_dubai, "Dubai");

	printf("\n");
	printf("République du Yémen:\n");
	calcul_et_affichage_horaire(heure_a_aden, "Aden");

	printf("\n");
	printf("Sultanat d'Oman:\n");
	calcul_et_affichage_horaire(heure_a_mascate, "Mascate");

	printf("\n");
	printf("Royaume de Bahreïn:\n");
	calcul_et_affichage_horaire(heure_au_bahrein, "Bahrein");

	printf("\n");
	printf("État du Koweït:\n");
	calcul_et_affichage_horaire(heure_au_koweit, "Koweit");

	printf("\n");
	printf("République démocratique fédérale d’Éthiopie:\n");
	calcul_et_affichage_horaire(heure_addis_abeba, "Addis-Abeba");

	printf("\n");
	printf("République gabonaise:\n");
	calcul_et_affichage_horaire(heure_a_libreville, "Libreville");

	printf("\n");
	printf("République du Cameroun:\n");
	calcul_et_affichage_horaire(heure_a_douala, "Douala");

	printf("\n");
	printf("République de Guinée équatoriale:\n");
	calcul_et_affichage_horaire(heure_a_malabo, "Malabo");

	printf("\n");
	printf("République fédérale du Nigeria:\n");
	calcul_et_affichage_horaire(heure_a_lagos, "Lagos");

	printf("\n");
	printf("République du Bénin:\n");
	calcul_et_affichage_horaire(heure_a_porto_novo, "Porto-Novo");

	printf("\n");
	printf("République togolaise:\n");
	calcul_et_affichage_horaire(heure_a_lome, "Lome");

	printf("\n");
	printf("République du Ghana:\n");
	calcul_et_affichage_horaire(heure_a_accra, "Accra");

	printf("\n");
	printf("République fédérale de Somalie:\n");
	calcul_et_affichage_horaire(heure_a_mogadiscio, "Mogadiscio");

	printf("\n");
	printf("État d'Érythrée:\n");
	calcul_et_affichage_horaire(heure_a_asmara, "Asmara");

	printf("\n");
	printf("République de Djibouti:\n");
	calcul_et_affichage_horaire(heure_djibouti, "Djibouti");

	printf("\n");
	printf("République du Kenya:\n");
	calcul_et_affichage_horaire(heure_a_nairobi, "Nairobi");

	printf("\n");
	printf("République d'Ouganda:\n");
	calcul_et_affichage_horaire(heure_a_kampala, "Kampala");

	printf("\n");
	printf("République centrafricaine:\n");
	calcul_et_affichage_horaire(heure_a_bangui, "Bangui");

	printf("\n");
	printf("République du Mali:\n");
	calcul_et_affichage_horaire(heure_a_bamako, "Bamako");

	printf("\n");
	printf("République islamique de Mauritanie:\n");
	calcul_et_affichage_horaire(heure_a_nouakchott, "Nouakchott");

	printf("\n");
	printf("République de Côte d'Ivoire:\n");
	calcul_et_affichage_horaire(heure_a_abidjan, "Abidjan");

	printf("\n");
	printf("République de Guinée:\n");
	calcul_et_affichage_horaire(heure_a_conakry, "Conakry");

	printf("\n");
	printf("République de Sierra Leone:\n");
	calcul_et_affichage_horaire(heure_a_freetown, "Freetown");

	printf("\n");
	printf("République du Liberia:\n");
	calcul_et_affichage_horaire(heure_a_morovia, "Morovia");

	printf("\n");
	printf("République du Burundi:\n");
	calcul_et_affichage_horaire(heure_a_bujumbura, "Bujumbura");

	printf("\n");
	printf("République du Malawi:\n");
	calcul_et_affichage_horaire(heure_a_blantyre, "Blantyre");

	printf("\n");
	printf("République du Sénégal:\n");
	calcul_et_affichage_horaire(heure_a_dakar, "Dakar");

	printf("\n");
	printf("République de Guinée-Bissau:\n");
	calcul_et_affichage_horaire(heure_a_bissau, "Bissau");

	printf("\n");
	printf("République du Tchad:\n");
	calcul_et_affichage_horaire(heure_a_ndjamena, "Ndjamena");

	printf("\n");
	printf("République de Gambie:\n");
	calcul_et_affichage_horaire(heure_a_banjul, "Banjul");

	printf("\n");
	printf("République démocratique de Sao Tomé-et-Principe:\n");
	calcul_et_affichage_horaire(heure_a_sao_tome, "Sao Tomé");

	printf("\n");
	printf("République du Rwanda:\n");
	calcul_et_affichage_horaire(heure_a_kigali, "Kigali");

	printf("\n");
	printf("République unie de Tanzanie:\n");
	calcul_et_affichage_horaire(heure_a_dar_es_salam, "Dar es Salam");

	printf("\n");
	printf("République de Zambie:\n");
	calcul_et_affichage_horaire(heure_lusaka, "Lusaka");

	printf("\n");
	printf("République de Zimbabwe:\n");
	calcul_et_affichage_horaire(heure_harare, "Harare");

	printf("\n");
	printf("République du Pérou:\n");
        calcul_et_affichage_horaire(heure_lima, "Lima");

	printf("\n");
	printf("République de l'Inde:\n");
	calcul_et_affichage_horaire(heure_a_calcutta, "Calcutta");

	printf("\n");
	printf("République populaire du Bangladesh:\n");
	calcul_et_affichage_horaire(heure_a_dacca, "Dacca");

	printf("\n");
	printf("République du Kazakhstan:\n");
	calcul_et_affichage_horaire(heure_a_almaty, "Almaty");
	calcul_et_affichage_horaire(heure_a_qostanay, "Qostanay");
	calcul_et_affichage_horaire(heure_a_aktaou, "Aktaou");
	calcul_et_affichage_horaire(heure_a_aktioube, "Aktioube");
	calcul_et_affichage_horaire(heure_a_atyrau, "Atyrau");
	calcul_et_affichage_horaire(heure_a_oural, "Oural");
	calcul_et_affichage_horaire(heure_a_qyzylorda, "Qyzylorda");

	printf("\n");
	printf("République d'Ouzbékistan:\n");
	calcul_et_affichage_horaire(heure_a_tachkent, "Tachkent");
	calcul_et_affichage_horaire(heure_a_samarkand, "Samarkand");

	printf("\n");
	printf("République du Tadjikistan:\n");
	calcul_et_affichage_horaire(heure_a_douchanbe, "Dushanbe");

	printf("\n");
	printf("République kirghize:\n");
	calcul_et_affichage_horaire(heure_a_bichkek, "Bichkek");

	printf("\n");
	printf("République démocratique fédérale du Népal:\n");
	calcul_et_affichage_horaire(heure_a_katmandou, "Katmandou");

	printf("\n");
        printf("République islamique d'Afghanistan:\n");
        calcul_et_affichage_horaire(heure_a_kaboul, "Kaboul");

	printf("\n");
	printf("Royaume de Thaïlande:\n");
	calcul_et_affichage_horaire(heure_a_bangkok, "Bangkok");

	printf("\n");
	printf("République socialiste du Viêt Nam:\n");
	calcul_et_affichage_horaire(heure_a_ho_chi_minh_ville, "Hô Chi Minh Ville");

	printf("\n");
	printf("République populaire démocratique de Corée:\n");
	calcul_et_affichage_horaire(heure_pyongyang, "Pyongyang");

	printf("\n");
	printf("République de Corée:\n");
        calcul_et_affichage_horaire(heure_seoul, "Seoul");

	printf("\n");
	printf("Empire du Japon:\n");
        calcul_et_affichage_horaire(heure_tokyo, "Tokyo");

	printf("\n");
	printf("Negara Brunei Darussalam:\n");
	calcul_et_affichage_horaire(heure_brunei, "Brunei");

	printf("\n");
	printf("République populaire de Chine:\n");
        calcul_et_affichage_horaire(heure_shanghai, "Shanghai");
	calcul_et_affichage_horaire(heure_a_urumqi, "Urumqi");

	printf("\n");
	printf("République de Chine (Taiwan):\n");
	calcul_et_affichage_horaire(heure_a_tapei, "Tapei");

	printf("\n");
	printf("Région administrative spéciale de Macao de la République populaire de Chine:\n");
	calcul_et_affichage_horaire(heure_a_macao, "Macao");

	printf("\n");
	printf("Région administrative spéciale de Hong Kong de la République populaire de Chine:\n");
	calcul_et_affichage_horaire(heure_a_hong_kong, "Hong Kong");

	printf("\n");
	printf("République des Philippines:\n");
	calcul_et_affichage_horaire(heure_a_manille, "Manille");

	printf("\n");
	printf("République de Singapour:\n");
	calcul_et_affichage_horaire(heure_a_singapour, "Singapour");

	printf("\n");
	printf("République démocratique populaire lao:\n");
	calcul_et_affichage_horaire(heure_a_vientiane, "Vientiane");

	printf("\n");
	printf("Royaume du Cambodge:\n");
	calcul_et_affichage_horaire(heure_a_phnom_penh, "Phnom Penh");

	printf("\n");
	printf("République de l'Union du Myanmar:\n");
	calcul_et_affichage_horaire(heure_a_yagon, "Yagon");

	printf("\n");
	printf("République démocratique du Timor oriental:\n");
	calcul_et_affichage_horaire(heure_a_dili, "Dili");

	printf("\n");
	printf("Îles Salomon:\n");
	calcul_et_affichage_horaire(heure_a_guadalcanal, "Guadalcanal");

	printf("\n");
	printf("Malaisie:\n");
	calcul_et_affichage_horaire(heure_a_kuala_lumpur, "Kuala Lumpur");
	calcul_et_affichage_horaire(heure_a_kuching, "Kuching");

	printf("\n");
	printf("République d'Indonésie:\n");
	calcul_et_affichage_horaire(heure_a_jakarta, "Jakarta");
	calcul_et_affichage_horaire(heure_a_pontianak, "Pontianak");
	calcul_et_affichage_horaire(heure_a_jayapura, "Jayapura");
	calcul_et_affichage_horaire(heure_a_makassar, "Makassar");

	printf("\n");
	printf("République des Seychelles:\n");
	calcul_et_affichage_horaire(heure_a_mahe, "Mahe");

	printf("\n");
	printf("État indépendant de Papouasie-Nouvelle-Guinée:\n");
	calcul_et_affichage_horaire(heure_a_bougainville, "Bougainville");
	calcul_et_affichage_horaire(heure_a_port_moresby, "Port Moresby");

	printf("\n");
	printf("États fédérés de Micronésie:\n");
	calcul_et_affichage_horaire(heure_a_pohnpei, "Pohnpei");
	calcul_et_affichage_horaire(heure_a_ponape, "Ponape");
	calcul_et_affichage_horaire(heure_a_chuuk, "Chuuk");
	calcul_et_affichage_horaire(heure_a_truk, "Truk");
	calcul_et_affichage_horaire(heure_a_yap, "Yap");
	calcul_et_affichage_horaire(heure_a_kosrae, "Kosrae");

	printf("\n");
	printf("République des Palaos:\n");
	calcul_et_affichage_horaire(heure_de_palau, "Palau");

	printf("\n");
	printf("îles Mariannes du Nord:\n");
	calcul_et_affichage_horaire(heure_a_saipan, "Saipan");

	printf("\n");
	printf("Porto Rico:\n");
	calcul_et_affichage_horaire(heure_a_porto_rico, "Porto Rico");

	printf("\n");
	printf("Royaume du Bhoutan:\n");
	calcul_et_affichage_horaire(heure_a_thimphou, "Thimphou");

	printf("\n");
	printf("République de Turquie:\n");
	calcul_et_affichage_horaire(heure_a_istanbul, "Istanbul");

	printf("\n");
	printf("Fédération de Russie:\n");
	calcul_et_affichage_horaire(heure_moscou, "Moscou");
        calcul_et_affichage_horaire(heure_vladivostok, "Vladivostok");
	calcul_et_affichage_horaire(heure_kaliningrad, "Kaliningrad");
	calcul_et_affichage_horaire(heure_samara, "Samara");
	calcul_et_affichage_horaire(heure_volgograd, "Volgograd");
	calcul_et_affichage_horaire(heure_saratov, "Saratov");
	calcul_et_affichage_horaire(heure_oulianovsk, "Oulianovsk");
	calcul_et_affichage_horaire(heure_astrakhan, "Astrakhan");
	calcul_et_affichage_horaire(heure_anadyr, "Anadyr");
	calcul_et_affichage_horaire(heure_sakhalin, "Sakhalin");
	calcul_et_affichage_horaire(heure_omsk, "Omsk");
	calcul_et_affichage_horaire(heure_tchita, "Tchita");
	calcul_et_affichage_horaire(heure_tomsk, "Tomsk");
	calcul_et_affichage_horaire(heure_barnaoul, "Barnaoul");
	calcul_et_affichage_horaire(heure_magadan, "Magadan");
	calcul_et_affichage_horaire(heure_iekaterinbourg, "Iekaterinbourg");
	calcul_et_affichage_horaire(heure_yakoutsk, "Yakoutsk");
	calcul_et_affichage_horaire(heure_irkoutsk, "Irkoutsk");
	calcul_et_affichage_horaire(heure_khandyga, "Khandyga");
	calcul_et_affichage_horaire(heure_novokouznetsk, "Novokouznetsk");
	calcul_et_affichage_horaire(heure_nobossibirsk, "Nobossibirsk");
	calcul_et_affichage_horaire(heure_krasnoyarsk, "Krasnoyarsk");
	calcul_et_affichage_horaire(heure_oust_nera, "Oust-Nera");
	calcul_et_affichage_horaire(heure_srednekolymsk, "Srednekolymsk");

	printf("\n");
	printf("République d'Arménie:\n");
	calcul_et_affichage_horaire(heure_erevan, "Erevan");

	printf("\n");
	printf("Géorgie:\n");
	calcul_et_affichage_horaire(heure_a_tbilissi, "Tbilissi");

	printf("\n");
	printf("République d'Azerbaïdjan:\n");
	calcul_et_affichage_horaire(heure_a_bakou, "Bakou");

	printf("\n");
	printf("Mongolie:\n");
	calcul_et_affichage_horaire(heure_a_choibalsan, "Choibalsan");
	calcul_et_affichage_horaire(heure_a_ulaanbaatar, "Ulaanbaatar");
	calcul_et_affichage_horaire(heure_a_hovd, "Hovd");

	printf("\n");
	printf("Antarctique:\n");
	calcul_et_affichage_horaire(heure_pour_la_base_antarctique_de_casey, "Base antarctique de Casey");
	calcul_et_affichage_horaire(heure_pour_la_base_antarctique_de_davis, "Base antarctique de Davis");
	calcul_et_affichage_horaire(heure_pour_la_base_antarctique_de_dumontdurville, "Base antarctique de Dumont-d'Urville");
	calcul_et_affichage_horaire(heure_pour_la_base_antarctique_de_mawson, "Base antarctique de Mawson");
	calcul_et_affichage_horaire(heure_pour_la_base_antarctique_de_mcmurdo, "Base antarctique de McMurdo");
	calcul_et_affichage_horaire(heure_pour_la_base_antarctique_de_palmer, "Base antarctique de Palmer");
	calcul_et_affichage_horaire(heure_pour_la_base_antarctique_de_rothera, "Base antarctique de Rothera");
	calcul_et_affichage_horaire(heure_pour_la_base_antarctique_de_syowa, "Base antarctique de Syowa");
	calcul_et_affichage_horaire(heure_pour_la_base_antarctique_de_vostok, "Base antarctique de Vostok");
	calcul_et_affichage_horaire(heure_pour_la_base_antarctique_de_troll, "Base antarctique de Troll");

	printf("\n");
}
