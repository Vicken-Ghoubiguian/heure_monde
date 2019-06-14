#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "application_des_decalages_horaires.h"
#include "affichage_de_l_horloge.h"
#include "fonctions_d_affichage_et_de_renvoie_de_l_heure_et_de_la_date.h"

//Cette fonction calcule puis retourne l'heure et la date pour une ville déterminée et connue passée en paramétre sous forme d'une chaine de caractères
char* retour_de_l_heure_et_de_la_date_pour_une_ville_determinee_et_connue(time_t temps_courant, char* nom_de_la_ville)
{

	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Paris"...
	if(strcmp(nom_de_la_ville,"Paris") == 0)
	{

		//L'heure et la date de Paris en temps réel est retournée
		return calcul_et_renvoie_horaire(temps_courant, "Paris");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Athènes"...
	else if(strcmp(nom_de_la_ville,"Athènes") == 0)
	{
		//Calcul de l'heure et de la date à Athènes et stockage de celui-ci dans la variable heure_d_athenes
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_athenes = temps_heure_d_athenes - (décallage_entre_paris_et_athenes_en_temps_reel * 3600)
		time_t heure_d_athenes = temps_courant + 3600;

		//L'heure et la date d'Athènes en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_d_athenes, "Athènes");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Los Angeles"...
	else if(strcmp(nom_de_la_ville,"Los Angeles") == 0)
	{
		//Calcul de l'heure et de la date à Los Angeles et stockage de celui-ci dans la variable heure_los_angeles
		//Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_los_angeles = temps_heure_de_paris - (décallage_entre_paris_et_los_angeles_en_temps_reel * 3600)
		time_t heure_los_angeles = temps_courant - ((9 - calcul_du_decalage_avec_l_amerique_du_nord(temps_courant)) * 3600);

		//L'heure et la date de Los Angeles en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_los_angeles, "Los Angeles");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "New York City"...
	else if(strcmp(nom_de_la_ville,"New York City") == 0)
	{
		//Calcul de l'heure et de la date à New York et stockage de celui-ci dans la variable heure_de_nyc
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_new_york_city = temps_heure_de_paris - (décallage_entre_paris_et_new_york_city_en_temps_reel * 3600)
		time_t heure_de_nyc = temps_courant - ((6 - calcul_du_decalage_avec_l_amerique_du_nord(temps_courant)) * 3600);

		//L'heure et la date de New York City en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_nyc, "New York City");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Ottawa"...
	else if(strcmp(nom_de_la_ville,"Ottawa") == 0)
	{
		//Calcul de l'heure et de la date à Ottawa et stockage de celui-ci dans la variable heure_d_ottawa
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_ottawa = temps_heure_de_paris - (décallage_entre_paris_et_ottawa_en_temps_reel * 3600)
		time_t heure_d_ottawa = temps_courant - ((6 - calcul_du_decalage_avec_l_amerique_du_nord(temps_courant)) * 3600);

		//L'heure et la date de Ottawa en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_d_ottawa, "Ottawa");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Phoenix"...
	else if(strcmp(nom_de_la_ville,"Phoenix") == 0)
	{
		//Calcul de l'heure et de la date à Phoenix et stockage de celui-ci dans la variable heure_de_phoenix
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_phoenix = temps_heure_de_paris - (décallage_entre_paris_et_phoenix_en_temps_reel * 3600)
		time_t heure_de_phoenix = temps_courant - ((9 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Phoenix en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_phoenix, "Phoenix");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Londres"...
	else if(strcmp(nom_de_la_ville,"Londres") == 0)
        {
		//Calcul de l'heure et de la date à Londres et stockage de celui-ci dans la variable heure_de_londres
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_londres = temps_heure_de_paris - (décallage_entre_paris_et_londres_en_temps_reel * 3600)
		time_t heure_de_londres = temps_courant - ((1 - calcul_du_decallage_avec_la_grande_bretagne(temps_courant)) * 3600);

		//L'heure et la date de Londres en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_londres, "Londres");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Moscou"...
        else if(strcmp(nom_de_la_ville,"Moscou") == 0)
        {
		//Calcul de l'heure et de la date à Moscou et stockage de celui-ci dans la variable heure_moscou
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_moscou = temps_heure_de_paris - (décallage_entre_paris_et_moscou_en_temps_reel * 3600)
		time_t heure_moscou = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Moscou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_moscou, "Moscou");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Vladivostok"...
        else if(strcmp(nom_de_la_ville,"Vladivostok") == 0)
        {
		//Calcul de l'heure et de la date à Vladivostok et stockage de celui-ci dans la variable heure_vladivostok
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_vladivostok = temps_heure_de_paris - (décallage_entre_paris_et_vladivostok_en_temps_reel * 3600)
		time_t heure_vladivostok = temps_courant + ((8 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Vladivostok en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_vladivostok, "Vladivostok");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Auckland"...
	else if(strcmp(nom_de_la_ville,"Auckland") == 0)
	{
		//Calcul de l'heure et de la date à Auckland et stockage de celui-ci dans la variable heure_a_auckland
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_auckland = temps_heure_de_paris - (décallage_entre_paris_et_auckland_en_temps_reel * 3600)
		time_t heure_a_auckland = temps_courant + ((12 -  calcul_du_decalage_avec_auckland(temps_courant)) * 3600);

		//L'heure et la date d'Auckland en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_auckland, "Auckland");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Sydney"...
        else if(strcmp(nom_de_la_ville,"Sydney") == 0)
        {
		//Calcul de l'heure et de la date à Sydney et stockage de celui-ci dans la variable heure_a_sydney
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_sydney = temps_heure_de_paris - (décallage_entre_paris_et_sydney_en_temps_reel * 3600)
		time_t heure_a_sydney = temps_courant + ((10 - calcul_du_decalage_avec_l_australie(temps_courant)) * 3600);

		//L'heure et la date de Sydney en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_sydney, "Sydney");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Santiago du Chili"...
        else if(strcmp(nom_de_la_ville,"Santiago du Chili") == 0)
        {
		//Calcul de l'heure et de la date à Santiago du Chili et stockage de celui-ci dans la variable heure_santiago_chili
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_santiago_du_chili = temps_heure_de_paris - (décallage_entre_paris_et_santiago_du_chili_en_temps_reel * 3600)
		time_t heure_santiago_chili = temps_courant - ((6 - calcul_du_decalage_avec_le_chili(temps_courant)) * 3600);

		//L'heure et la date de Santiago du Chili en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_santiago_chili, "Santiago du Chili");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Punta Arenas"...
	else if(strcmp(nom_de_la_ville,"Punta Arenas") == 0)
	{
		//Calcul de l'heure et de la date à Punta Arenas et stockage de celui-ci dans la variable heure_a_punta_arenas
		//Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_punta_arenas = temps_heure_de_paris - (décallage_entre_paris_et_punta_arenas_en_temps_reel * 3600)
		time_t heure_a_punta_arenas = temps_courant - ((5 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Punta Arenas en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_punta_arenas, "Punta Arenas");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Ile de Pâques"...
	else if(strcmp(nom_de_la_ville,"Ile de Pâques") == 0)
	{
		//Calcul de l'heure et de la date sur l'île de Pâques et stockage de celui-ci dans la variable heure_
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_sur_l_île_de_Pâques = temps_heure_de_paris - (décallage_entre_paris_et_l_île_de_Pâques_en_temps_reel * 3600)
		time_t heure_ile_de_paques = temps_courant - ((8 - calcul_du_decalage_avec_le_chili(temps_courant)) * 3600);

		//L'heure et la date sur l'île de Pâcques en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_ile_de_paques, "Ile de Pâques");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Johannesburg"...
	else if(strcmp(nom_de_la_ville,"Johannesburg") == 0)
        {
		//Calcul de l'heure et de la date à Johannesburg et stockage de celui-ci dans la variable heure_johannesburg
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_johannesburg = temps_heure_de_paris - (décallage_entre_paris_et_johannesburg_en_temps_reel * 3600)
		time_t heure_johannesburg = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Johannesburg en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_johannesburg, "Johannesburg");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Khartoum"...
	else if(strcmp(nom_de_la_ville,"Khartoum") == 0)
	{
		//Calcul de l'heure et de la date à Khartoum et stockage de celui-ci dans la variable heure_a_khartoum
		//Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_khartoum = temps_heure_de_paris - (décallage_entre_paris_et_khartoum_en_temps_reel * 3600)
		time_t heure_a_khartoum = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Khartoum en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_khartoum, "Khartoum");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Djouba"...
	else if(strcmp(nom_de_la_ville,"Djouba") == 0)
	{
		//Calcul de l'heure et de la date à Djouba et stockage de celui-ci dans la variable heure_a_djouba
		//Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_djouba = temps_heure_de_paris - (décallage_entre_paris_et_khartoum_en_temps_reel * 3600)
		time_t heure_a_djouba = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Djouba en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_djouba, "Djouba");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Alger"...
	else if(strcmp(nom_de_la_ville,"Alger") == 0)
	{
		//Calcul de l'heure et de la date à Alger et stockage de celui-ci dans la variable heure_a_alger
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_alger = temps_heure_de_paris - (décallage_entre_paris_et_alger_en_temps_reel * 3600)
		time_t heure_a_alger = temps_courant - ((1 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date d'Alger en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_alger, "Alger");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Nairobi"...
	else if(strcmp(nom_de_la_ville,"Nairobi") == 0)
	{
		//Calcul de l'heure et de la date à Nairobi et stockage de celui-ci dans la variable heure_a_dar_es_salam
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_nairobi = temps_heure_de_paris - (décallage_entre_paris_et_nairobi_en_temps_reel * 3600)
		time_t heure_a_nairobi = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Nairobi en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_nairobi, "Nairobi");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Dar es Salam"...
	else if(strcmp(nom_de_la_ville,"Dar es Salam") == 0)
	{
		//Calcul de l'heure et de la date à Dar es Salem et stockage de celui-ci dans la variable heure_a_dar_es_salam
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_dar_es_salam = temps_heure_de_paris - (décallage_entre_paris_et_dar_es_salam_en_temps_reel * 3600)
		time_t heure_a_dar_es_salam = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Dar es Salam en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_dar_es_salam, "Dar es Salam");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Buenos Aires"...
        else if(strcmp(nom_de_la_ville,"Buenos Aires") == 0)
        {
		//Calcul de l'heure et de la date à Buenos Aires et stockage de celui-ci dans la variable heure_buenos_aires
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_buenos_aires = temps_heure_de_paris - (décallage_entre_paris_et_buenos_aires_en_temps_reel * 3600)
		time_t heure_buenos_aires = temps_courant - ((5 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Buenos Aires en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_buenos_aires, "Buenos Aires");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Guatemala"...
	else if(strcmp(nom_de_la_ville,"Guatemala") == 0)
	{
		//Calcul de l'heure et de la date au Guatemala et stockage de celui-ci dans la variable heure_au_guatemala
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_au_guatemala = temps_heure_de_paris - (décallage_entre_paris_et_le_guatemala_en_temps_reel * 3600)
		time_t heure_au_guatemala = temps_courant - ((8 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date au Guatemala en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_guatemala, "Guatemala");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Costa Rica"...
	else if(strcmp(nom_de_la_ville,"Costa Rica") == 0)
	{
		//Calcul de l'heure et de la date au Costa Rica et stockage de celui-ci dans la variable heure_buenos_aires
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_au_costa_rica = temps_heure_de_paris - (décallage_entre_paris_et_le_costa_rica_en_temps_reel * 3600)
		time_t heure_au_costa_rica = temps_courant - ((8 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date du Costa Rica en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_costa_rica, "Costa Rica");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tegucigalpa"...
	else if(strcmp(nom_de_la_ville,"Tegucigalpa") == 0)
	{
		//Calcul de l'heure et de la date à Tegucigalpa et stockage de celui-ci dans la variable heure_au_honduras
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_au_honduras = temps_heure_de_paris - (décallage_entre_paris_et_au_honduras_en_temps_reel * 3600)
		time_t heure_au_honduras = temps_courant - ((8 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date du Honduras en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_honduras, "Tegucigalpa");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Panama"...
	else if(strcmp(nom_de_la_ville,"Panama") == 0)
	{
		//Calcul de l'heure et de la date au Panama et stockage de celui-ci dans la variable heure_au_panama
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_au_panama = temps_heure_de_paris - (décallage_entre_paris_et_le_panama_en_temps_reel * 3600)
		time_t heure_au_panama = temps_courant - ((7 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date au Panama en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_panama, "Panama");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "El Salvador"...
	else if(strcmp(nom_de_la_ville,"El Salvador") == 0)
	{
		//Calcul de l'heure et de la date au Panama et stockage de celui-ci dans la variable heure_d_el_salvador
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_el_salvador = temps_heure_de_paris - (décallage_entre_paris_et_el_salvador * 3600)
		time_t heure_d_el_salvador = temps_courant - ((8 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date a El Salvador en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_d_el_salvador, "El Salvador");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale au "Belize"...
	else if(strcmp(nom_de_la_ville,"Belize") == 0)
	{
		//Calcul de l'heure et de la date au Belize et stockage de celui-ci dans la variable heure_au_belize
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_au_belize = temps_heure_de_paris - (décallage_entre_paris_et_le_belize_en_temps_reel * 3600)
		time_t heure_au_belize = temps_courant - ((8 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date au Belize en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_belize, "Belize");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Bogota"...
	else if(strcmp(nom_de_la_ville,"Bogota") == 0)
	{
		//Calcul de l'heure et de la date à Bogota et stockage de celui-ci dans la variable heure_bogota
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_bogota = temps_heure_de_paris - (décallage_entre_paris_et_bogota_en_temps_reel * 3600)
		time_t heure_a_bogota = temps_courant - ((7 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Bogota en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_bogota, "Bogota");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Caracas"...
	else if(strcmp(nom_de_la_ville,"Caracas") == 0)
	{
		//Calcul de l'heure et de la date à Caracas et stockage de celui-ci dans la variable heure_caracas
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_caracas = temps_heure_de_paris - (décallage_entre_paris_et_caracas_en_temps_reel * 3600)
		time_t heure_a_caracas = temps_courant - ((6 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Caracas en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_caracas, "Caracas");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Guayaquil"...
	else if(strcmp(nom_de_la_ville,"Guayaquil") == 0)
	{
		//Calcul de l'heure et de la date à Guayaquil et stockage de celui-ci dans la variable heure_a_guayaquil
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_guayaquil = temps_heure_de_paris - (décallage_entre_paris_et_guayaquil_en_temps_reel * 3600)
		time_t heure_a_guayaquil = temps_courant - ((7 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Guayaquil en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_guayaquil, "Guayaquil");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Galapagos"...
	else if(strcmp(nom_de_la_ville,"Galapagos") == 0)
	{
		//Calcul de l'heure et de la date à Galapagos et stockage de celui-ci dans la variable heure_a_galapagos
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_galapagos = temps_heure_de_paris - (décallage_entre_paris_et_galapagos_en_temps_reel * 3600)
		time_t heure_a_galapagos = temps_courant - ((8 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Galapagos en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_galapagos, "Galapagos");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "La Paz"...
	else if(strcmp(nom_de_la_ville,"La Paz") == 0)
	{
		//Calcul de l'heure et de la date à La Paz et stockage de celui-ci dans la variable heure_a_la_paz
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_la_paz = temps_heure_de_paris - (décallage_entre_paris_et_la_paz_en_temps_reel * 3600)
		time_t heure_a_la_paz = temps_courant - ((6 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de La Paz en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_la_paz, "La Paz");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Antananarivo"...
        else if(strcmp(nom_de_la_ville,"Antananarivo") == 0)
        {
		//Calcul de l'heure et de la date à Antananarivo et stockage de celui-ci dans la variable heure_antananarivo
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_antananarivo = temps_heure_de_paris - (décallage_entre_paris_et_antananarivo_en_temps_reel * 3600)
		time_t heure_antananarivo = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Antananarivo en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_antananarivo, "Antananarivo");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Windhoek"...
        else if(strcmp(nom_de_la_ville,"Windhoek") == 0)
        {
		//Calcul de l'heure et de la date à Windhoek et stockage de celui-ci dans la variable heure_windhoek
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_windhoek = temps_heure_de_paris - (décallage_entre_paris_et_windhoek_en_temps_reel * 3600)
		time_t heure_windhoek = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Windhoek en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_windhoek, "Windhoek");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Lima"...
        else if(strcmp(nom_de_la_ville,"Lima") == 0)
        {
		//Calcul de l'heure et de la date à Lima et stockage de celui-ci dans la variable heure_lima
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_lima = temps_heure_de_paris - (décallage_entre_paris_et_lima_en_temps_reel * 3600)
		time_t heure_lima = temps_courant - ((7 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Lima en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_lima, "Lima");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Bangkok"...
	else if(strcmp(nom_de_la_ville,"Bangkok") == 0)
	{
		//Calcul de l'heure et de la date à Bangkok et stockage de celui-ci dans la variable heure_a_bangkok
		//Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_bangkok = temps_heure_de_paris - (décallage_entre_paris_et_bangkok_en_temps_reel * 3600)
		time_t heure_a_bangkok = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Bangkok Ville en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_bangkok, "Bangkok");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Hô Chi Minh Ville"...
	else if(strcmp(nom_de_la_ville,"Hô Chi Minh Ville") == 0)
	{
		//Calcul de l'heure et de la date à Hô Chi Minh Ville et stockage de celui-ci dans la variable heure_a_ho_chi_minh_ville
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_ho_chi_minh_ville = temps_heure_de_paris - (décallage_entre_paris_et_ho_chi_minh_ville_en_temps_reel * 3600)
		time_t heure_a_ho_chi_minh_ville = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Hô Chi Minh Ville en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_ho_chi_minh_ville, "Hô Chi Minh Ville");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Pyongyang"...
	else if(strcmp(nom_de_la_ville,"Pyongyang") == 0)
	{
		//Calcul de l'heure et de la date à Pyongyang et stockage de celui-ci dans la variable heure_pyongyang
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_pyongyang = temps_heure_de_paris - (décallage_entre_paris_et_pyongyang_en_temps_reel * 3600)
		time_t heure_pyongyang = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Pyongyang en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_pyongyang, "Pyongyang");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Seoul"...
        else if(strcmp(nom_de_la_ville,"Seoul") == 0)
        {
		//Calcul de l'heure et de la date à Seoul et stockage de celui-ci dans la variable heure_seoul
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_seoul = temps_heure_de_paris - (décallage_entre_paris_et_seoul_en_temps_reel * 3600)
		time_t heure_seoul = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Seoul en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_seoul, "Seoul");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tokyo"...
        else if(strcmp(nom_de_la_ville,"Tokyo") == 0)
        {
		//Calcul de l'heure et de la date à Tokyo et stockage de celui-ci dans la variable heure_tokyo
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_tokyo = temps_heure_de_paris - (décallage_entre_paris_et_tokyo_en_temps_reel * 3600)
		time_t heure_tokyo = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Tokyo en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_tokyo, "Tokyo");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Pekin"...
	else if(strcmp(nom_de_la_ville,"Pekin") == 0)
        {
		//Calcul de l'heure et de la date à Pekin et stockage de celui-ci dans la variable heure_pekin
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_pekin = temps_heure_de_paris - (décallage_entre_paris_et_pekin_en_temps_reel * 3600)
		time_t heure_pekin = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Pekin en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_pekin, "Pekin");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Manille"...
	else if(strcmp(nom_de_la_ville,"Manille") == 0)
	{
		//Calcul de l'heure et de la date à Manille et stockage de celui-ci dans la variable heure_a_manille
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_manille = temps_heure_de_paris - (décallage_entre_paris_et_manille_en_temps_reel * 3600)
		time_t heure_a_manille = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Manille en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_manille, "Manille");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Urumqi"...
	else if(strcmp(nom_de_la_ville,"Urumqi") == 0)
	{
		//Calcul de l'heure et de la date à Urumqi et stockage de celui-ci dans la variable heure_a_urumqi
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_urumqi = temps_heure_de_paris - (décallage_entre_paris_et_urumqi_en_temps_reel * 3600)
		time_t heure_a_urumqi = temps_courant + ((4 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date d'Urumqi en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_urumqi, "Urumqi");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Kaliningrad"...
	else if(strcmp(nom_de_la_ville,"Kaliningrad") == 0)
	{
		//Calcul de l'heure et de la date à Kaliningrad et stockage de celui-ci dans la variable heure_kaliningrad
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_kaliningrad = temps_heure_de_paris + (décallage_entre_paris_et_kaliningrad_en_temps_reel * 3600)
		time_t heure_kaliningrad = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Kaliningrad en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_kaliningrad, "Kaliningrad");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Samara"...
	else if(strcmp(nom_de_la_ville,"Samara") == 0)
	{
		//Calcul de l'heure et de la date à Samara et stockage de celui-ci dans la variable heure_kaliningrad
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_samara = temps_heure_de_paris + (décallage_entre_paris_et_samara_en_temps_reel * 3600)
		time_t heure_samara = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Samara en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_samara, "Samara");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Volgograd"...
	else if(strcmp(nom_de_la_ville,"Volgograd") == 0)
	{
		//Calcul de l'heure et de la date à Samara et stockage de celui-ci dans la variable heure_volgograd
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_volgograd = temps_heure_de_paris + (décallage_entre_paris_et_volgograd_en_temps_reel * 3600)
		time_t heure_volgograd = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Volgograd en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_volgograd, "Volgograd");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Saratov"...
	else if(strcmp(nom_de_la_ville,"Saratov") == 0)
	{
		//Calcul de l'heure et de la date à Saratov et stockage de celui-ci dans la variable heure_saratov
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_saratov = temps_heure_de_paris + (décallage_entre_paris_et_saratov_en_temps_reel * 3600)
		time_t heure_saratov = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Saratov en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_saratov, "Saratov");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Oulianovsk"...
        else if(strcmp(nom_de_la_ville,"Oulianovsk") == 0)
	{
		//Calcul de l'heure et de la date à Oulianovsk et stockage de celui-ci dans la variable heure_oulianovsk
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_oulianovsk = temps_heure_de_paris + (décallage_entre_paris_et_oulianovsk_en_temps_reel * 3600)
		time_t heure_oulianovsk = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Saratov en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_oulianovsk, "Oulianovsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Astrakhan"...
	else if(strcmp(nom_de_la_ville,"Astrakhan") == 0)
	{
		//Calcul de l'heure et de la date à Astrakhan et stockage de celui-ci dans la variable heure_astrakhan
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_astrakhan = temps_heure_de_paris + (décallage_entre_paris_et_astrakhan_en_temps_reel * 3600)
		time_t heure_astrakhan = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date d'Astrakhan en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_astrakhan, "Astrakhan");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Anadyr"...
	else if(strcmp(nom_de_la_ville,"Anadyr") == 0)
	{
		//Calcul de l'heure et de la date à Anadyr et stockage de celui-ci dans la variable heure_anadyr
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_anadyr = temps_heure_de_paris + (décallage_entre_paris_et_anadyr_en_temps_reel * 3600)
		time_t heure_anadyr = temps_courant + ((10 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date d'Anadyr en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_anadyr, "Anadyr");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Sakhalin"...
	else if(strcmp(nom_de_la_ville,"Sakhalin") == 0)
	{
		//Calcul de l'heure et de la date à Sakhalin et stockage de celui-ci dans la variable heure_sakhalin
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_sakhalin = temps_heure_de_paris + (décallage_entre_paris_et_sakhalin_en_temps_reel * 3600)
		time_t heure_sakhalin = temps_courant + ((9 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Sakhalin en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_sakhalin, "Sakhalin");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Omsk"...
	else if(strcmp(nom_de_la_ville,"Omsk") == 0)
	{
		//Calcul de l'heure et de la date à Omsk et stockage de celui-ci dans la variable heure_omsk
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_omsk = temps_heure_de_paris + (décallage_entre_paris_et_omsk_en_temps_reel * 3600)
		time_t heure_omsk = temps_courant + ((4 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date d'Omsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_omsk, "Omsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tchita"...
	else if(strcmp(nom_de_la_ville,"Tchita") == 0)
	{
		//Calcul de l'heure et de la date à Tchita et stockage de celui-ci dans la variable heure_tchita
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_tchita = temps_heure_de_paris + (décallage_entre_paris_et_tchita_en_temps_reel * 3600)
		time_t heure_tchita = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Tchita en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_tchita, "Tchita");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tomsk"...
	else if(strcmp(nom_de_la_ville,"Tomsk") == 0)
	{
		//Calcul de l'heure et de la date à Tomsk et stockage de celui-ci dans la variable heure_tomsk
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_tomsk = temps_heure_de_paris + (décallage_entre_paris_et_tomsk_en_temps_reel * 3600)
		time_t heure_tomsk = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Tomsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_tomsk, "Tomsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Barnaoul"...
	else if(strcmp(nom_de_la_ville,"Barnaoul") == 0)
	{
		//Calcul de l'heure et de la date à Barnaoul et stockage de celui-ci dans la variable heure_barnaoul
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_barnaoul = temps_heure_de_paris + (décallage_entre_paris_et_barnaoul_en_temps_reel * 3600)
                time_t heure_barnaoul = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Barnaoul en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_barnaoul, "Barnaoul");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Magadan"...
	else if(strcmp(nom_de_la_ville,"Magadan") == 0)
	{
		//Calcul de l'heure et de la date à Magadan et stockage de celui-ci dans la variable heure_magadan
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_magadan = temps_heure_de_paris + (décallage_entre_paris_et_magadan_en_temps_reel * 3600)
		time_t heure_magadan = temps_courant + ((9 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Magadan en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_magadan, "Magadan");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Iekaterinbourg"...
	else if(strcmp(nom_de_la_ville,"Iekaterinbourg") == 0)
	{
		//Calcul de l'heure et de la date à Iekaterinbourg et stockage de celui-ci dans la variable heure_iekaterinbourg
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_iekaterinbourg = temps_heure_de_paris + (décallage_entre_paris_et_iekaterinbourg_en_temps_reel * 3600)
		time_t heure_iekaterinbourg = temps_courant + ((3 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date d'Iekaterinbourg en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_iekaterinbourg, "Iekaterinbourg");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Yakoutsk"...
	else if(strcmp(nom_de_la_ville,"Yakoutsk") == 0)
	{
		//Calcul de l'heure et de la date à Yakoutsk et stockage de celui-ci dans la variable heure_yakoutsk
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_yakoutsk = temps_heure_de_paris + (décallage_entre_paris_et_yakoutsk_en_temps_reel * 3600)
		time_t heure_yakoutsk = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date d'Yakoutsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_yakoutsk, "Yakoutsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Irkoutsk"...
	else if(strcmp(nom_de_la_ville,"Irkoutsk") == 0)
	{
		//Calcul de l'heure et de la date à Irkoutsk et stockage de celui-ci dans la variable heure_irkoutsk
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_irkoutsk = temps_heure_de_paris + (décallage_entre_paris_et_irkoutsk_en_temps_reel * 3600)
		time_t heure_irkoutsk = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date d'Irkoutsk en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_irkoutsk, "Irkoutsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Khandyga"...
	else if(strcmp(nom_de_la_ville,"Khandyga") == 0)
	{
		//Calcul de l'heure et de la date à Khandyga et stockage de celui-ci dans la variable heure_khandyga
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_khandyga = temps_heure_de_paris + (décallage_entre_paris_et_khandyga_en_temps_reel * 3600)
		time_t heure_khandyga = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Khandyga en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_khandyga, "Khandyga");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Novokouznetsk"...
	else if(strcmp(nom_de_la_ville,"Novokouznetsk") == 0)
	{
		//Calcul de l'heure et de la date à Novokouznetsk et stockage de celui-ci dans la variable heure_novokouznetsk
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_Novokouznetsk = temps_heure_de_paris + (décallage_entre_paris_et_novokouznetsk_en_temps_reel * 3600)
		time_t heure_novokouznetsk = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Novokouznetsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_novokouznetsk, "Novokouznetsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Nobossibirsk"...
	else if(strcmp(nom_de_la_ville,"Nobossibirsk") == 0)
	{
		//Calcul de l'heure et de la date à Nobossibirsk et stockage de celui-ci dans la variable heure_nobossibirsk
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_Nobossibirsk = temps_heure_de_paris + (décallage_entre_paris_et_nobossibirsk_en_temps_reel * 3600)
		time_t heure_nobossibirsk = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Nobossibirsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_nobossibirsk, "Nobossibirsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Krasnoyarsk"...
	else if(strcmp(nom_de_la_ville,"Krasnoyarsk") == 0)
	{
		//Calcul de l'heure et de la date à Krasnoyarsk et stockage de celui-ci dans la variable heure_krasnoyarsk
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_Krasnoyarsk = temps_heure_de_paris + (décallage_entre_paris_et_krasnoyarsk_en_temps_reel * 3600)
		time_t heure_krasnoyarsk = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Krasnoyarsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_krasnoyarsk, "Krasnoyarsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Oust-Nera"...
	else if(strcmp(nom_de_la_ville,"Oust-Nera") == 0)
	{
		//Calcul de l'heure et de la date à Oust-Nera et stockage de celui-ci dans la variable heure_oust_nera
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_oust-nera = temps_heure_de_paris + (décallage_entre_paris_et_oust-nera_en_temps_reel * 3600)
		time_t heure_oust_nera = temps_courant + ((8 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date d'Oust-Nera en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_oust_nera, "Oust-Nera");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Srednekolymsk"...
	else if(strcmp(nom_de_la_ville,"Srednekolymsk") == 0)
	{
		//Calcul de l'heure et de la date à Srednekolymsk et stockage de celui-ci dans la variable heure_srednekolymsk
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_srednekolymsk = temps_heure_de_paris + (décallage_entre_paris_et_srednekolymsk_en_temps_reel * 3600)
		time_t heure_srednekolymsk = temps_courant + ((9 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Srednekolymsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_srednekolymsk, "Srednekolymsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Le Caire"...
	else if(strcmp(nom_de_la_ville,"Le Caire") == 0)
	{
		//Calcul de l'heure et de la date au Caire et stockage de celui-ci dans la variable heure_le_caire
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_au_caire = temps_heure_de_paris + (décallage_entre_paris_et_le_caire_en_temps_reel * 3600)
		time_t heure_le_caire = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date au Caire en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_le_caire, "Le Caire");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Aden"...
	else if(strcmp(nom_de_la_ville,"Aden") == 0)
	{
		//Calcul de l'heure et de la date à Aden et stockage de celui-ci dans la variable heure_a_aden
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_aden = temps_heure_de_paris + (décallage_entre_paris_et_aden_en_temps_reel * 3600)
		time_t heure_a_aden = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Aden en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_aden, "Aden");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Koweit"...
	else if(strcmp(nom_de_la_ville,"Koweit") == 0)
	{
		//Calcul de l'heure et de la date au Koweit et stockage de celui-ci dans la variable heure_au_koweit
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_au_koweit = temps_heure_de_paris + (décallage_entre_paris_et_le_koweit_en_temps_reel * 3600)
		time_t heure_au_koweit = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date au Koweit en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_koweit, "Koweit");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Addis-Abeba"...
	else if(strcmp(nom_de_la_ville,"Addis-Abeba") == 0)
	{
		//Calcul de l'heure et de la date à Addis-Abeba et stockage de celui-ci dans la variable heure_le_caire
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_addis-abeba = temps_heure_de_paris + (décallage_entre_paris_et_addis-abeba_en_temps_reel * 3600)
		time_t heure_addis_abeba = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Addis-Abeba en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_addis_abeba, "Addis-Abeba");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Brazzaville"...
	else if(strcmp(nom_de_la_ville,"Brazzaville") == 0)
	{
		//Calcul de l'heure et de la date à Brazzaville et stockage de celui-ci dans la variable heure_a_brazzaville
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_brazzaville = temps_heure_de_paris + (décallage_entre_paris_et_brazzaville_en_temps_reel * 3600)
		time_t heure_a_brazzaville = temps_courant - ((1 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Brazzaville en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_brazzaville, "Brazzaville");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Kinshasa"...
	else if(strcmp(nom_de_la_ville,"Kinshasa") == 0)
	{
		//Calcul de l'heure et de la date à Kinshasa et stockage de celui-ci dans la variable heure_a_kinshasa
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_kinshasa = temps_heure_de_paris + (décallage_entre_paris_et_kinshasa_en_temps_reel * 3600)
		time_t heure_a_kinshasa = temps_courant - ((1 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Kinshasa en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_kinshasa, "Kinshasa");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Lubumbashi"...
	else if(strcmp(nom_de_la_ville,"Lubumbashi") == 0)
	{
		//Calcul de l'heure et de la date à Lubumbashi et stockage de celui-ci dans la variable heure_a_lubumbashi
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_lubumbashi = temps_heure_de_paris + (décallage_entre_paris_et_lubumbashi_en_temps_reel * 3600)
		time_t heure_a_lubumbashi = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Lubumbashi en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_lubumbashi, "Lubumbashi");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Riyad"...
	else if(strcmp(nom_de_la_ville,"Riyad") == 0)
	{
		//Calcul de l'heure et de la date à Riyad et stockage de celui-ci dans la variable heure_a_riyad
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_riyad = temps_heure_de_paris + (décallage_entre_paris_et_riyad_en_temps_reel * 3600)
		time_t heure_a_riyad = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Riyad en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_riyad, "Riyad");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Bahrein"...
	else if(strcmp(nom_de_la_ville,"Bahrein") == 0)
	{
		//Calcul de l'heure et de la date au Bahrein et stockage de celui-ci dans la variable heure_au_bahrein
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_au_bahrein = temps_heure_de_paris + (décallage_entre_paris_et_le_bahrein_en_temps_reel * 3600)
		time_t heure_au_bahrein = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date au Bahrein en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_bahrein, "Bahrein");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Dubai"...
	else if(strcmp(nom_de_la_ville,"Dubai") == 0)
	{
		//Calcul de l'heure et de la date à Dubai et stockage de celui-ci dans la variable heure_a_dubai
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_dubai = temps_heure_de_paris + (décallage_entre_paris_et_dubai_en_temps_reel * 3600)
		time_t heure_a_dubai = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Dubai en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_dubai, "Dubai");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Mascat"...
	else if(strcmp(nom_de_la_ville,"Mascate") == 0)
	{
		//Calcul de l'heure et de la date à Mascate et stockage de celui-ci dans la variable heure_a_mascate
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_mascate = temps_heure_de_paris + (décallage_entre_paris_et_mascate_en_temps_reel * 3600)
		time_t heure_a_mascate = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Mascate en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_mascate, "Mascate");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Qatar"...
	else if(strcmp(nom_de_la_ville,"Qatar") == 0)
	{
		//Calcul de l'heure et de la date au Qatar et stockage de celui-ci dans la variable heure_au_qatar
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_au_qatar = temps_heure_de_paris + (décallage_entre_paris_et_le_qatar_en_temps_reel * 3600)
		time_t heure_au_qatar = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date au Qatar en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_qatar, "Qatar");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Zurich"...
	else if(strcmp(nom_de_la_ville,"Zurich") == 0)
	{
		//Calcul de l'heure et de la date à Zurich et stockage de celui-ci dans la variable heure_zurich
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_zurich = temps_heure_de_paris + (décallage_entre_paris_et_zurich_en_temps_reel * 3600)
		time_t heure_zurich = temps_courant;

		//L'heure et la date à Zurich en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_zurich, "Zurich");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Andorre"...
	else if(strcmp(nom_de_la_ville,"Andorre") == 0)
	{
		//Calcul de l'heure et de la date à Andorre et stockage de celui-ci dans la variable heure_andorre
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_andorre = temps_heure_de_paris + (décallage_entre_paris_et_andorre_en_temps_reel * 3600)
		time_t heure_andorre = temps_courant;

		//L'heure et la date à Andorre en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_andorre, "Andorre");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Vaduz"...
	else if(strcmp(nom_de_la_ville,"Vaduz") == 0)
	{
		//Calcul de l'heure et de la date à Vaduz et stockage de celui-ci dans la variable heure_vaduz
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_vaduz = temps_heure_de_paris + (décallage_entre_paris_et_vaduz_en_temps_reel * 3600)
		time_t heure_vaduz = temps_courant;

		//L'heure et la date à Vaduz en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_vaduz, "Vaduz");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Malte"...
	else if(strcmp(nom_de_la_ville,"Malte") == 0)
	{
		//Calcul de l'heure et de la date à Malte et stockage de celui-ci dans la variable heure_malte
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_malte = temps_heure_de_paris + (décallage_entre_paris_et_malte_en_temps_reel * 3600)
		time_t heure_malte = temps_courant;

		//L'heure et la date à Malte en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_malte, "Malte");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Djibouti"...
	else if(strcmp(nom_de_la_ville,"Djibouti") == 0)
	{
		//Calcul de l'heure et de la date à Djibouti et stockage de celui-ci dans la variable heure_djibouti
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_djibouti = temps_heure_de_paris + (décallage_entre_paris_et_djibouti_en_temps_reel * 3600)
		time_t heure_djibouti = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Djibouti en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_djibouti, "Djibouti");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Lusaka"...
	else if(strcmp(nom_de_la_ville,"Lusaka") == 0)
	{
		//Calcul de l'heure et de la date à Lusaka et stockage de celui-ci dans la variable heure_lusaka
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_lusaka = temps_heure_de_paris + (décallage_entre_paris_et_lusaka_en_temps_reel * 3600)
		time_t heure_lusaka = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Lusaka en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_lusaka, "Lusaka");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tripoli"...
	else if(strcmp(nom_de_la_ville,"Tripoli") == 0)
	{
		//Calcul de l'heure et de la date à Tripoli et stockage de celui-ci dans la variable heure_tripoli
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_tripoli = temps_heure_de_paris + (décallage_entre_paris_et_tripoli_en_temps_reel * 3600)
		time_t heure_tripoli = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Tripoli en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_tripoli, "Tripoli");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Asmara"...
	else if(strcmp(nom_de_la_ville,"Asmara") == 0)
	{
		//Calcul de l'heure et de la date à Asmara et stockage de celui-ci dans la variable heure_a_asmara
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_asmara = temps_heure_de_paris + (décallage_entre_paris_et_asmara_en_temps_reel * 3600)
		time_t heure_a_asmara = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Asmara en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_asmara, "Asmara");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Harare"...
	else if(strcmp(nom_de_la_ville,"Harare") == 0)
	{
		//Calcul de l'heure et de la date à Harare et stockage de celui-ci dans la variable heure_harare
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_harare = temps_heure_de_paris + (décallage_entre_paris_et_harare_en_temps_reel * 3600)
		time_t heure_harare = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Harare en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_harare, "Harare");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Managua"...
	else if(strcmp(nom_de_la_ville,"Managua") == 0)
	{
		//Calcul de l'heure et de la date à Managua et stockage de celui-ci dans la variable heure_managua
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_managua = temps_heure_de_paris + (décallage_entre_paris_et_managua_en_temps_reel * 3600)
		time_t heure_managua = temps_courant - ((8 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Managua en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_managua, "Managua");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Brunei"...
	else if(strcmp(nom_de_la_ville,"Brunei") == 0)
	{
		//Calcul de l'heure et de la date à Brunei et stockage de celui-ci dans la variable heure_brunei
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_brunei = temps_heure_de_paris + (décallage_entre_paris_et_brunei_en_temps_reel * 3600)
		time_t heure_brunei = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Brunei en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_brunei, "Brunei");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Erevan"...
	else if(strcmp(nom_de_la_ville,"Erevan") == 0)
	{
		//Calcul de l'heure et de la date à Erevan et stockage de celui-ci dans la variable heure_erevan
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_erevan = temps_heure_de_paris + (décallage_entre_paris_et_erevan_en_temps_reel * 3600)
		time_t heure_erevan = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Erevan en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_erevan, "Erevan");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tbilissi"...
	else if(strcmp(nom_de_la_ville,"Tbilissi") == 0)
	{
		//Calcul de l'heure et de la date à Tbilissi et stockage de celui-ci dans la variable heure_a_tbilissi
		//Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_tbilissi = temps_heure_de_paris + (décallage_entre_paris_et_tbilissi_en_temps_reel * 3600)
		time_t heure_a_tbilissi = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Tbilissi en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_tbilissi, "Tbilissi");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Bakou"...
	else if(strcmp(nom_de_la_ville,"Bakou") == 0)
	{
		//Calcul de l'heure et de la date à Tbilissi et stockage de celui-ci dans la variable heure_a_bakou
		//Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_bakou = temps_heure_de_paris + (décallage_entre_paris_et_tbilissi_en_temps_reel * 3600)
		time_t heure_a_bakou = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Bakou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_bakou, "Bakou");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Mogadiscio"...
	else if(strcmp(nom_de_la_ville,"Mogadiscio") == 0)
	{
		//Calcul de l'heure et de la date à Erevan et stockage de celui-ci dans la variable heure_a_mogadiscio
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_mogadiscio = temps_heure_de_paris + (décallage_entre_paris_et_mogadiscio_en_temps_reel * 3600)
		time_t heure_a_mogadiscio = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Mogadiscio en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_mogadiscio, "Mogadiscio");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Hovd"...
	else if(strcmp(nom_de_la_ville,"Hovd") == 0)
	{
		//Calcul de l'heure et de la date à Hovd et stockage de celui-ci dans la variable heure_a_hovd
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_hovd = temps_heure_de_paris + (décallage_entre_paris_et_hovd_en_temps_reel * 3600)
		time_t heure_a_hovd = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Hovd en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_hovd, "Hovd");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tapei"...
	else if(strcmp(nom_de_la_ville,"Tapei") == 0)
	{
		//Calcul de l'heure et de la date à Tapei et stockage de celui-ci dans la variable heure_a_tapei
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_tapei = temps_heure_de_paris + (décallage_entre_paris_et_tapei_en_temps_reel * 3600)
		time_t heure_a_tapei = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Tapei en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_tapei, "Tapei");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Macao"...
	else if(strcmp(nom_de_la_ville,"Macao") == 0)
	{
		//Calcul de l'heure et de la date à Macao et stockage de celui-ci dans la variable heure_a_macao
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_macao = temps_heure_de_paris + (décallage_entre_paris_et_macao_en_temps_reel * 3600)
		time_t heure_a_macao = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Macao en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_macao, "Macao");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tachkent"...
	else if(strcmp(nom_de_la_ville,"Tachkent") == 0)
	{
		//Calcul de l'heure et de la date à Tachkent et stockage de celui-ci dans la variable heure_a_tachkent
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_tachkent = temps_heure_de_tachkent + (décallage_entre_paris_et_tachkent_en_temps_reel * 3600)
		time_t heure_a_tachkent = temps_courant + ((3 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Tachkent en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_tachkent, "Tachkent");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Samarkand"...
        else if(strcmp(nom_de_la_ville,"Samarkand") == 0)
        {
                //Calcul de l'heure et de la date à Samarkand et stockage de celui-ci dans la variable heure_a_samarkand
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_samarkand = temps_heure_de_samarkand + (décallage_entre_paris_et_samarkand_en_temps_reel * 3600)
                time_t heure_a_samarkand = temps_courant + ((3 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

                //L'heure et la date à Samarkand en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_samarkand, "Samarkand");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Dushanbe"...
	else if(strcmp(nom_de_la_ville,"Dushanbe") == 0)
	{
		//Calcul de l'heure et de la date à Douchanbé et stockage de celui-ci dans la variable heure_a_douchanbe
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_douchanbe = temps_heure_de_douchanbe + (décallage_entre_paris_et_douchanbe_en_temps_reel * 3600)
		time_t heure_a_douchanbe = temps_courant + ((3 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Douchanbé en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_douchanbe, "Dushanbe");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Thimphou"...
	else if(strcmp(nom_de_la_ville,"Thimphou") == 0)
	{
		//Calcul de l'heure et de la date à Thimphou et stockage de celui-ci dans la variable heure_a_thimphou
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_thimphou = temps_heure_de_thimphou + (décallage_entre_paris_et_thimphou_en_temps_reel * 3600)
		time_t heure_a_thimphou = temps_courant + ((4 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Thimphou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_thimphou, "Bhoutan");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Bichkek"...
	else if(strcmp(nom_de_la_ville,"Bichkek") == 0)
	{
		//Calcul de l'heure et de la date à Bichkek et stockage de celui-ci dans la variable heure_a_bichkek
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_bichkek = temps_heure_de_bichkek + (décallage_entre_paris_et_bichkek_en_temps_reel * 3600)
		time_t heure_a_bichkek = temps_courant + ((4 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Bichkek en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_bichkek, "Bichkek");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Katmandou"...
	else if(strcmp(nom_de_la_ville,"Katmandou") == 0)
	{
		//Calcul de l'heure et de la date à Katmandou et stockage de celui-ci dans la variable heure_a_katmandou
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_katmandou = temps_heure_de_paris + (nombre_de_minutes_supplemantaires_pour_calculer_l_heure_a_Katmandou) + (décallage_entre_paris_et_katmandou_en_temps_reel * 3600)
		time_t heure_a_katmandou = temps_courant + (45 * 60) + ((3 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Katmandou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_katmandou, "Katmandou");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Kaboul"...
	else if(strcmp(nom_de_la_ville,"Kaboul") == 0)
	{
		//Calcul de l'heure et de la date à Kaboul et stockage de celui-ci dans la variable heure_a_kaboul
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_kaboul = temps_heure_de_paris + (nombre_de_minutes_supplemantaires_pour_calculer_l_heure_a_Kaboul) + (décallage_entre_paris_et_kaboul_en_temps_reel * 3600)
		time_t heure_a_kaboul = temps_courant + (30 * 60) + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Kaboul en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_kaboul, "Kaboul");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Singapour"...
	else if(strcmp(nom_de_la_ville,"Singapour") == 0)
	{
		//Calcul de l'heure et de la date à Singapour et stockage de celui-ci dans la variable heure_a_singapour
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_singapour = temps_heure_de_paris + (décallage_entre_paris_et_singapour_en_temps_reel * 3600)
		time_t heure_a_singapour = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Singapour en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_singapour, "Singapour");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Hong Kong"...
	else if(strcmp(nom_de_la_ville,"Hong Kong") == 0)
	{
		//Calcul de l'heure et de la date à Hong Kong et stockage de celui-ci dans la variable heure_a_hong_kong
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_hong_kong = temps_heure_de_paris + (décallage_entre_paris_et_hong_kong_en_temps_reel * 3600)
		time_t heure_a_hong_kong = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Hong Kong en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_hong_kong, "Hong Kong");
	}
	//Sinon...
	else
	{
		//
		return "Erreur: Le nom de la ville entré en paramétre est inconnue...pour le moment.";
	}
}
