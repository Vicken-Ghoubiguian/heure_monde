#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*#include <string.h>*/
#include "application_des_decalages_horaires.h"
#include "affichage_de_l_horloge.h"

//Cette fonction permet de calculer et d'afficher les horaires d'une ville passée en paramétre
void calcul_et_affichage_horaire(time_t temps, char* ville)
{
	//Declaration des variables
	struct tm *horaire = localtime(&temps);
	char* jour_semaine;
	char* mois;
	char heure_a_convertir_en_str[5];
	char minute_a_convertir_en_str[5];
	char seconde_a_convertir_en_str[5];
	char jour_dans_le_mois_a_convertir_en_str[5];

	//Definition du mois en court en fonction du champs tm_mon de la structure tm
	switch(horaire->tm_mon)
	{
		case 0: mois = "Janvier"; break;
		case 1: mois = "Fevrier"; break;
		case 2: mois = "Mars"; break;
		case 3: mois = "Avril"; break;
		case 4: mois = "Mai"; break;
		case 5: mois = "Juin"; break;
		case 6: mois = "Juillet"; break;
		case 7: mois = "Aout"; break;
		case 8: mois = "Septembre"; break;
		case 9: mois = "Octobre"; break;
		case 10: mois = "Novembre"; break;
		case 11: mois = "Decembre"; break;
	}

	//Definition du jour de la semaine en fonction du champs tm_wday de la structure tm
	switch(horaire->tm_wday)
	{
		case 0: jour_semaine = "Dimanche"; break;
		case 1: jour_semaine = "Lundi"; break;
		case 2: jour_semaine = "Mardi"; break;
		case 3: jour_semaine = "Mercredi"; break;
		case 4: jour_semaine = "Jeudi"; break;
		case 5: jour_semaine = "Vendredi"; break;
		case 6: jour_semaine = "Samedi"; break;
	}

	//
	if(horaire->tm_hour < 10)
	{
		//
		sprintf(heure_a_convertir_en_str, "%02d", horaire->tm_hour);
	}
	//Sinon...
	else
	{
		//
		sprintf(heure_a_convertir_en_str, "%d", horaire->tm_hour);
	}

	//
	if(horaire->tm_min < 10)
	{
		//
		sprintf(minute_a_convertir_en_str, "%02d", horaire->tm_min);
	}
	//Sinon...
	else
	{
		//
		sprintf(minute_a_convertir_en_str, "%d", horaire->tm_min);
	}

	//
	if(horaire->tm_sec < 10)
	{
		//
		sprintf(seconde_a_convertir_en_str, "%02d", horaire->tm_sec);
	}
	//Sinon...
	else
	{
		//
		sprintf(seconde_a_convertir_en_str, "%d", horaire->tm_sec);
	}

	//
	if(horaire->tm_mday < 10)
	{
		//
		sprintf(jour_dans_le_mois_a_convertir_en_str, "%02d", horaire->tm_mday);
	}
	//Sinon...
	else
	{
		//
		sprintf(jour_dans_le_mois_a_convertir_en_str, "%d", horaire->tm_mday);
	}

	//Affichage de l'horaire
	printf("%s : %s:%s:%s - %s %s %s %d.\n",
		ville, heure_a_convertir_en_str, minute_a_convertir_en_str, seconde_a_convertir_en_str,
		jour_semaine, jour_dans_le_mois_a_convertir_en_str, mois, horaire->tm_year + 1900);
}

//Fonction de test pour les calculs d'horaires mises au point dans le fichier heure_monde.c
void affichage_de_l_horloge(time_t temps_courant)
{
	/*Calcul des horaires de différents villes du monde et affectation de la valeur calculée à une variable correspondante*/

	/* États-Unis d'Amérique */
        time_t heure_los_angeles = temps_courant - ((9 - calcul_du_decalage_avec_l_amerique_du_nord(temps_courant)) * 3600); //Los Angeles
        time_t heure_de_nyc = temps_courant - ((6 - calcul_du_decalage_avec_l_amerique_du_nord(temps_courant)) * 3600); //New York City
        time_t heure_d_ottawa = temps_courant - ((6 - calcul_du_decalage_avec_l_amerique_du_nord(temps_courant)) * 3600); //Ottawa
        time_t heure_de_phoenix = temps_courant - ((9 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Phoenix

	/* République du Nicaragua */
	time_t heure_managua = temps_courant - ((8 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Managua

	/* République du Salvador */
	time_t heure_d_el_salvador = temps_courant - ((8 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Salvador

	/* Belize */
	time_t heure_au_belize = temps_courant - ((8 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Belize

	/* République du Costa Rica */
	time_t heure_au_costa_rica = temps_courant - ((8 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Costa Rica

	/* République du Honduras */
	time_t heure_au_honduras = temps_courant - ((8 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Tegucigalpa

	/* République du Guatemala */
	time_t heure_au_guatemala = temps_courant - ((8 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Guatemala

	/* Confédération suisse */
	time_t heure_zurich = temps_courant; //Zurich

	/* République de Malte */
	time_t heure_malte = temps_courant; //Malte

	/* Principauté d'Andorre */
	time_t heure_andorre = temps_courant; //Andorre

	/* Principauté de Liechtenstein */
	time_t heure_vaduz = temps_courant; //Vaduz

	/* République hellénique */
	time_t heure_d_athenes = temps_courant + 3600; //Athènes

	/* Royaume-Uni de Grande-Bretagne et d'Irlande du Nord */
	time_t heure_de_londres = temps_courant - ((1 - calcul_du_decallage_avec_la_grande_bretagne(temps_courant)) * 3600); //Londres

	/* Commonwealth d'Australie */
        time_t heure_a_sydney = temps_courant + ((10 - calcul_du_decalage_avec_l_australie(temps_courant)) * 3600); //Sydney

	/* République du Chili */
        time_t heure_santiago_chili = temps_courant - ((6 - calcul_du_decalage_avec_le_chili(temps_courant)) * 3600); //Santiago du Chili
	time_t heure_a_puntas_arenas = temps_courant - ((5 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Puntas Arenas
	time_t heure_ile_de_paques = temps_courant - ((8 - calcul_du_decalage_avec_le_chili(temps_courant)) * 3600); //Ile de Pâques

	/* République algérienne démocratique et populaire */
	time_t heure_a_alger = temps_courant - ((1 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Alger

	/* République du Soudan */
	time_t heure_a_khartoum = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Khartoum

	/* République du Soudan du Sud */
	time_t heure_a_djouba = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Djouba

	/* République d'Afrique du Sud */
        time_t heure_johannesburg = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Johannesburg

	/* République de Namibie */
        time_t heure_windhoek = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Windhoek

	/* État de Libye */
	time_t heure_tripoli = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Tripoli

	/* État d'Érythrée */
	time_t heure_a_asmara = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Asmara

	/* République fédérale de Somalie */
	time_t heure_a_mogadiscio = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Mogadiscio

	/* République démocratique fédérale d’Éthiopie */
	time_t heure_addis_abeba = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Addis-Abeba

	/* République de Djibouti */
	time_t heure_djibouti = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Djibouti

	/* République du Congo */
	time_t heure_a_brazzaville = temps_courant - ((1 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Brazzaville

	/* République démocratique du Congo */
	time_t heure_a_kinshasa = temps_courant - ((1 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Kinshasa
	time_t heure_a_lubumbashi = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Lubumbashi

	/* République unie de Tanzanie */
	time_t heure_a_dar_es_salam = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Dar_es_Salam

	/* République du Kenya */
	time_t heure_a_nairobi = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Nairobi

	/* République de Zambie */
	time_t heure_lusaka = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Lusaka

	/* République arabe d'Égypte */
	time_t heure_le_caire = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Le Caire

	/* République de Zimbabwe */
	time_t heure_harare = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Harare

	/* Nouvelle-Zélande */
	time_t heure_a_auckland = temps_courant + ((12 -  calcul_du_decalage_avec_auckland(temps_courant)) * 3600); //Auckland

	/* République du Panama */
	time_t heure_au_panama = temps_courant - ((7 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Panama

	/* République argentine */
        time_t heure_buenos_aires = temps_courant - ((5 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Buenos Aires

	/* République bolivarienne du Venezuela */
	time_t heure_a_caracas = temps_courant - ((6 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Caracas

	/* République de l'Équateur */
	time_t heure_a_guayaquil = temps_courant - ((7 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Guayaquil
	time_t heure_a_galapagos = temps_courant - ((8 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Galapagos

	/* État plurinational de Bolivie */
	time_t heure_a_la_paz = temps_courant - ((6 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //La Paz

	/* République de Madagascar */
        time_t heure_antananarivo = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Antananarivo

	/* République du Pérou */
        time_t heure_lima = temps_courant - ((7 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Lima

	/* République de Colombie */
	time_t heure_a_bogota = temps_courant - ((7 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Bogota

	/* État du Qatar */
	time_t heure_au_qatar = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Qatar

	/* République du Yémen */
	time_t heure_a_aden = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Aden

	/* Royaume d'Arabie saoudite */
	time_t heure_a_riyad = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Riyad

	/* Sultanat d'Oman */
	time_t heure_a_mascate = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Mascate

	/* Émirats arabes unis */
	time_t heure_a_dubai = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Dubai

	/* Royaume de Bahreïn */
	time_t heure_au_bahrein = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Bahrein

	/* État du Koweït */
	time_t heure_au_koweit = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Koweit

	/* République d'Ouzbékistan */
	time_t heure_a_tachkent = temps_courant + ((3 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Tachkent
	time_t heure_a_samarkand = temps_courant + ((3 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Samarkand

	/* République du Tadjikistan */
	time_t heure_a_douchanbe = temps_courant + ((3 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Douchanbé

	/* République kirghize */
	time_t heure_a_bichkek = temps_courant + ((4 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Bichkek

	/* République démocratique fédérale du Népal */
	time_t heure_a_katmandou = temps_courant + (45 * 60) + ((3 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Katmandou

	/* République islamique d'Afghanistan */
	time_t heure_a_kaboul = temps_courant + (30 * 60) + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Kaboul

	/* Royaume de Thaïlande */
	time_t heure_a_bangkok = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Bangkok

	/* République socialiste du Viêt Nam */
	time_t heure_a_ho_chi_minh_ville = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Hô Chi Minh Ville

	/* République populaire démocratique de Corée */
	time_t heure_pyongyang = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Pyongyang

	/* République de Corée */
        time_t heure_seoul = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Seoul

	/* Empire du Japon */
        time_t heure_tokyo = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Tokyo

	/* Royaume du Bhoutan */
	time_t heure_a_thimphou = temps_courant + ((4 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Thimphou

	/* République populaire de Chine */
        time_t heure_pekin = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Pekin
	time_t heure_a_urumqi = temps_courant + ((4 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Urumqi

	/* Région administrative spéciale de Macao de la République populaire de Chine */
	time_t heure_a_macao = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Macao

	/* Région administrative spéciale de Hong Kong de la République populaire de Chine */
	time_t heure_a_hong_kong = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Hong Kong

	/* Negara Brunei Darussalam */
	time_t heure_brunei = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Brunei

	/* Mongolie */
	time_t heure_a_hovd = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Hovd

	/* République de Chine (Taiwan) */
	time_t heure_a_tapei = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Tapei

	/* République des Philippines */
	time_t heure_a_manille = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Manille

	/* République de Singapour */
	time_t heure_a_singapour = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Singapour

	/* Fédération de Russie */
	time_t heure_moscou = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Moscou
        time_t heure_vladivostok = temps_courant + ((8 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Vladivostok
	time_t heure_kaliningrad = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Kaliningrad
	time_t heure_samara = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Samara
	time_t heure_volgograd = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Volgograd
	time_t heure_saratov = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Saratov
	time_t heure_oulianovsk = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Oulianovsk
	time_t heure_astrakhan = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Astrakhan
	time_t heure_anadyr = temps_courant + ((10 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Anadyr
	time_t heure_sakhalin = temps_courant + ((9 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Sakhalin
	time_t heure_omsk = temps_courant + ((4 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Omsk
	time_t heure_tchita = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Tchita
	time_t heure_tomsk = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Tomsk
	time_t heure_barnaoul = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Barnaoul
	time_t heure_magadan = temps_courant + ((9 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Magadan
	time_t heure_iekaterinbourg = temps_courant + ((3 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Iekaterinbourg
	time_t heure_yakoutsk = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Yakoutsk
	time_t heure_irkoutsk = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Irkoutsk
	time_t heure_khandyga = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Khandyga
	time_t heure_novokouznetsk = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Novokouznetsk
	time_t heure_nobossibirsk = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Nobossibirsk
	time_t heure_krasnoyarsk = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Krasnoyarsk
	time_t heure_oust_nera = temps_courant + ((8 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Oust-Nera
	time_t heure_srednekolymsk = temps_courant + ((9 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Srednekolymsk

	/* République d'Arménie */
	time_t heure_erevan = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Erevan

	/*Affichage des différents horiares calculés à coté des villes correspondantes*/

        printf("\n");
	printf("République française:\n");
        calcul_et_affichage_horaire(temps_courant, "Paris");

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
	printf("République hellénique:\n");
	calcul_et_affichage_horaire(heure_d_athenes, "Athènes");

	printf("\n");
	printf("États-Unis d'Amérique:\n");
        calcul_et_affichage_horaire(heure_los_angeles, "Los Angeles");
        calcul_et_affichage_horaire(heure_de_nyc, "New York City");
        calcul_et_affichage_horaire(heure_d_ottawa, "Ottawa");
        calcul_et_affichage_horaire(heure_de_phoenix, "Phoenix");

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

	printf("\n");
	printf("Commonwealth d'Australie:\n");
        calcul_et_affichage_horaire(heure_a_sydney, "Sydney");

	printf("\n");
	printf("Nouvelle-Zélande:\n");
	calcul_et_affichage_horaire(heure_a_auckland, "Auckland");

	printf("\n");
	printf("République du Chili:\n");
        calcul_et_affichage_horaire(heure_santiago_chili, "Santiago du Chili");
	calcul_et_affichage_horaire(heure_a_puntas_arenas, "Puntas Arenas");
	calcul_et_affichage_horaire(heure_ile_de_paques, "Ile de Pâques");

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
	printf("État de Libye:\n");
	calcul_et_affichage_horaire(heure_tripoli, "Tripoli");

	printf("\n");
	printf("République arabe d'Égypte:\n");
	calcul_et_affichage_horaire(heure_le_caire, "Le Caire");

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
        calcul_et_affichage_horaire(heure_pekin, "Pekin");
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
	printf("Royaume du Bhoutan:\n");
	calcul_et_affichage_horaire(heure_a_thimphou, "Thimphou");

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
	printf("Mongolie:\n");
	calcul_et_affichage_horaire(heure_a_hovd, "Hovd");

	printf("\n");
}
