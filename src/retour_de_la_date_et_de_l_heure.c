#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "application_des_decalages_horaires.h"
#include "affichage_de_l_horloge.h"
#include "fonctions_d_affichage_et_de_renvoie_de_l_heure_et_de_la_date.h"
#include "bibliotheque_de_fonctions_utiles.h"

//Cette fonction calcule puis retourne l'heure et la date pour une ville déterminée et connue passée en paramétre sous forme d'une chaine de caractères
char* retour_de_l_heure_et_de_la_date_pour_une_ville_determinee_et_connue(char* nom_de_la_ville)
{

	/* Définition de la variable temps_utc et initialisation de celle-ci au temps utc sous forme de timestamp */
        time_t temps_utc = retour_du_temps_utc_sous_forme_de_timestamp();

	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Paris"...
	if(strcmp(nom_de_la_ville,"Paris") == 0)
	{

		//
		time_t heure_de_paris = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

		//L'heure et la date de Paris en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_paris, "Paris");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Athènes"...
	else if(strcmp(nom_de_la_ville,"Athènes") == 0)
	{
		//Calcul de l'heure et de la date à Athènes et stockage de celui-ci dans la variable heure_d_athenes
		time_t heure_d_athenes = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

		//L'heure et la date d'Athènes en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_d_athenes, "Athènes");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Los Angeles"...
	else if(strcmp(nom_de_la_ville,"Los Angeles") == 0)
	{
		//Calcul de l'heure et de la date à Los Angeles et stockage de celui-ci dans la variable heure_los_angeles
		time_t heure_los_angeles = temps_utc - ((8 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600));

		//L'heure et la date de Los Angeles en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_los_angeles, "Los Angeles");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "New York City"...
	else if(strcmp(nom_de_la_ville,"New York City") == 0)
	{
		//Calcul de l'heure et de la date à New York et stockage de celui-ci dans la variable heure_de_nyc
                time_t heure_de_nyc = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600));

		//L'heure et la date de New York City en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_nyc, "New York City");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Ottawa"...
	else if(strcmp(nom_de_la_ville,"Ottawa") == 0)
	{
		//Calcul de l'heure et de la date à Ottawa et stockage de celui-ci dans la variable heure_d_ottawa
                time_t heure_d_ottawa = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600));

		//L'heure et la date de Ottawa en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_d_ottawa, "Ottawa");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Phoenix"...
	else if(strcmp(nom_de_la_ville,"Phoenix") == 0)
	{
		//Calcul de l'heure et de la date à Phoenix et stockage de celui-ci dans la variable heure_de_phoenix
                time_t heure_de_phoenix = temps_utc - (7 * 3600); //Phoenix

		//L'heure et la date de Phoenix en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_phoenix, "Phoenix");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Londres"...
	else if(strcmp(nom_de_la_ville,"Londres") == 0)
        {
		//Calcul de l'heure et de la date à Londres et stockage de celui-ci dans la variable heure_de_londres
                time_t heure_de_londres = temps_utc + (application_du_changement_d_heure_pour_la_grande_bretagne(temps_utc) * 3600);

		//L'heure et la date de Londres en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_londres, "Londres");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Moscou"...
        else if(strcmp(nom_de_la_ville,"Moscou") == 0)
        {
		//Calcul de l'heure et de la date à Moscou et stockage de celui-ci dans la variable heure_moscou
                time_t heure_moscou = temps_utc + (3 * 3600);

		//L'heure et la date de Moscou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_moscou, "Moscou");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Vladivostok"...
        else if(strcmp(nom_de_la_ville,"Vladivostok") == 0)
        {
		//Calcul de l'heure et de la date à Vladivostok et stockage de celui-ci dans la variable heure_vladivostok
                time_t heure_vladivostok = temps_utc + (10 * 3600);

		//L'heure et la date de Vladivostok en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_vladivostok, "Vladivostok");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Auckland"...
	else if(strcmp(nom_de_la_ville,"Auckland") == 0)
	{
		//Calcul de l'heure et de la date à Auckland et stockage de celui-ci dans la variable heure_a_auckland
                time_t heure_a_auckland = temps_utc + ((13 * 3600) - (application_du_changement_d_heure_pour_la_nouvelle_zelande(temps_utc) * 3600));

		//L'heure et la date d'Auckland en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_auckland, "Auckland");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Sydney"...
        else if(strcmp(nom_de_la_ville,"Sydney") == 0)
        {
		//Calcul de l'heure et de la date à Sydney et stockage de celui-ci dans la variable heure_a_sydney
                time_t heure_a_sydney = temps_utc + ((11 * 3600) - (application_du_changement_d_heure_pour_l_australie(temps_utc) * 3600));

		//L'heure et la date de Sydney en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_sydney, "Sydney");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Santiago"...
        else if(strcmp(nom_de_la_ville,"Santiago") == 0)
        {
		//Calcul de l'heure et de la date à Santiago du Chili et stockage de celui-ci dans la variable heure_santiago_chili
                time_t heure_santiago_chili = temps_utc - ((4 * 3600) - (application_du_changement_d_heure_pour_le_chili(temps_utc)  * 3600));

		//L'heure et la date de Santiago du Chili en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_santiago_chili, "Santiago du Chili");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Punta_Arenas"...
	else if(strcmp(nom_de_la_ville,"Punta_Arenas") == 0)
	{
		//Calcul de l'heure et de la date à Punta Arenas et stockage de celui-ci dans la variable heure_a_punta_arenas
		time_t heure_a_punta_arenas = temps_utc - (3 * 3600);

		//L'heure et la date de Punta Arenas en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_punta_arenas, "Punta Arenas");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Easter"...
	else if(strcmp(nom_de_la_ville,"Easter") == 0)
	{
		//Calcul de l'heure et de la date sur l'île de Pâques et stockage de celui-ci dans la variable heure_
                time_t heure_ile_de_paques = temps_utc - ((6 * 3600)  - (application_du_changement_d_heure_pour_le_chili(temps_utc) * 3600));

		//L'heure et la date sur l'île de Pâcques en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_ile_de_paques, "Ile de Pâques");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Johannesburg"...
	else if(strcmp(nom_de_la_ville,"Johannesburg") == 0)
        {
		//Calcul de l'heure et de la date à Johannesburg et stockage de celui-ci dans la variable heure_johannesburg
                time_t heure_johannesburg = temps_utc + (2 * 3600);

		//L'heure et la date de Johannesburg en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_johannesburg, "Johannesburg");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Khartoum"...
	else if(strcmp(nom_de_la_ville,"Khartoum") == 0)
	{
		//Calcul de l'heure et de la date à Khartoum et stockage de celui-ci dans la variable heure_a_khartoum
		time_t heure_a_khartoum = temps_utc + (2 * 3600);

		//L'heure et la date de Khartoum en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_khartoum, "Khartoum");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Djouba"...
	else if(strcmp(nom_de_la_ville,"Djouba") == 0)
	{
		//Calcul de l'heure et de la date à Djouba et stockage de celui-ci dans la variable heure_a_djouba
		time_t heure_a_djouba = temps_utc + (3 * 3600);

		//L'heure et la date de Djouba en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_djouba, "Djouba");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Alger"...
	else if(strcmp(nom_de_la_ville,"Alger") == 0)
	{
		//Calcul de l'heure et de la date à Alger et stockage de celui-ci dans la variable heure_a_alger
                time_t heure_a_alger = temps_utc + (1 * 3600);

		//L'heure et la date d'Alger en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_alger, "Alger");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Nairobi"...
	else if(strcmp(nom_de_la_ville,"Nairobi") == 0)
	{
		//Calcul de l'heure et de la date à Nairobi et stockage de celui-ci dans la variable heure_a_nairobi
                time_t heure_a_nairobi = temps_utc + (3 * 3600);

		//L'heure et la date de Nairobi en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_nairobi, "Nairobi");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Dar_es_Salam"...
	else if(strcmp(nom_de_la_ville,"Dar_es_Salam") == 0)
	{
		//Calcul de l'heure et de la date à Dar es Salem et stockage de celui-ci dans la variable heure_a_dar_es_salam
                time_t heure_a_dar_es_salam = temps_utc + (3 * 3600);

		//L'heure et la date de Dar es Salam en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_dar_es_salam, "Dar es Salam");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Buenos_Aires"...
        else if(strcmp(nom_de_la_ville,"Buenos_Aires") == 0)
        {
		//Calcul de l'heure et de la date à Buenos Aires et stockage de celui-ci dans la variable heure_buenos_aires
                time_t heure_buenos_aires = temps_utc - (3 * 3600);

		//L'heure et la date de Buenos Aires en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_buenos_aires, "Buenos Aires");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Guatemala"...
	else if(strcmp(nom_de_la_ville,"Guatemala") == 0)
	{
		//Calcul de l'heure et de la date au Guatemala et stockage de celui-ci dans la variable heure_au_guatemala
                time_t heure_au_guatemala = temps_utc - (6 * 3600);

		//L'heure et la date au Guatemala en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_guatemala, "Guatemala");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Costa_Rica"...
	else if(strcmp(nom_de_la_ville,"Costa_Rica") == 0)
	{
		//Calcul de l'heure et de la date au Costa Rica et stockage de celui-ci dans la variable heure_au_costa_rica
                time_t heure_au_costa_rica = temps_utc - (6 * 3600);

		//L'heure et la date du Costa Rica en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_costa_rica, "Costa Rica");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tegucigalpa"...
	else if(strcmp(nom_de_la_ville,"Tegucigalpa") == 0)
	{
		//Calcul de l'heure et de la date à Tegucigalpa et stockage de celui-ci dans la variable heure_au_honduras
                time_t heure_au_honduras = temps_utc - (6 * 3600);

		//L'heure et la date du Honduras en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_honduras, "Tegucigalpa");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Panama"...
	else if(strcmp(nom_de_la_ville,"Panama") == 0)
	{
		//Calcul de l'heure et de la date au Panama et stockage de celui-ci dans la variable heure_au_panama
                time_t heure_au_panama = temps_utc - (5 * 3600);

		//L'heure et la date au Panama en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_panama, "Panama");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "El_Salvador"...
	else if(strcmp(nom_de_la_ville,"El_Salvador") == 0)
	{
		//Calcul de l'heure et de la date au Panama et stockage de celui-ci dans la variable heure_d_el_salvador
                time_t heure_d_el_salvador = temps_utc - (6 * 3600);

		//L'heure et la date a El Salvador en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_d_el_salvador, "El Salvador");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale au "Belize"...
	else if(strcmp(nom_de_la_ville,"Belize") == 0)
	{
		//Calcul de l'heure et de la date au Belize et stockage de celui-ci dans la variable heure_au_belize
                time_t heure_au_belize = temps_utc - (6 * 3600);

		//L'heure et la date au Belize en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_belize, "Belize");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Bogota"...
	else if(strcmp(nom_de_la_ville,"Bogota") == 0)
	{
		//Calcul de l'heure et de la date à Bogota et stockage de celui-ci dans la variable heure_a_bogota
                time_t heure_a_bogota = temps_utc - (5 * 3600);

		//L'heure et la date de Bogota en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_bogota, "Bogota");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Caracas"...
	else if(strcmp(nom_de_la_ville,"Caracas") == 0)
	{
		//Calcul de l'heure et de la date à Caracas et stockage de celui-ci dans la variable heure_caracas
                time_t heure_a_caracas = temps_utc - (4 * 3600);

		//L'heure et la date de Caracas en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_caracas, "Caracas");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Guayaquil"...
	else if(strcmp(nom_de_la_ville,"Guayaquil") == 0)
	{
		//Calcul de l'heure et de la date à Guayaquil et stockage de celui-ci dans la variable heure_a_guayaquil
                time_t heure_a_guayaquil = temps_utc - (5 * 3600);

		//L'heure et la date de Guayaquil en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_guayaquil, "Guayaquil");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Galapagos"...
	else if(strcmp(nom_de_la_ville,"Galapagos") == 0)
	{
		//Calcul de l'heure et de la date à Galapagos et stockage de celui-ci dans la variable heure_a_galapagos
                time_t heure_a_galapagos = temps_utc - (6 * 3600);

		//L'heure et la date de Galapagos en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_galapagos, "Galapagos");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "La Paz"...
	else if(strcmp(nom_de_la_ville,"La_Paz") == 0)
	{
		//Calcul de l'heure et de la date à La Paz et stockage de celui-ci dans la variable heure_a_la_paz
                time_t heure_a_la_paz = temps_utc - (4 * 3600);

		//L'heure et la date de La Paz en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_la_paz, "La Paz");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Antananarivo"...
        else if(strcmp(nom_de_la_ville,"Antananarivo") == 0)
        {
		//Calcul de l'heure et de la date à Antananarivo et stockage de celui-ci dans la variable heure_antananarivo
                time_t heure_antananarivo = temps_utc + (3 * 3600);

		//L'heure et la date de Antananarivo en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_antananarivo, "Antananarivo");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Windhoek"...
        else if(strcmp(nom_de_la_ville,"Windhoek") == 0)
        {
		//Calcul de l'heure et de la date à Windhoek et stockage de celui-ci dans la variable heure_windhoek
                time_t heure_windhoek = temps_utc + (2 * 3600);

		//L'heure et la date de Windhoek en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_windhoek, "Windhoek");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Lima"...
        else if(strcmp(nom_de_la_ville,"Lima") == 0)
        {
		//Calcul de l'heure et de la date à Lima et stockage de celui-ci dans la variable heure_lima
                time_t heure_lima = temps_utc - (5 * 3600);

		//L'heure et la date de Lima en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_lima, "Lima");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Bangkok"...
	else if(strcmp(nom_de_la_ville,"Bangkok") == 0)
	{
		//Calcul de l'heure et de la date à Bangkok et stockage de celui-ci dans la variable heure_a_bangkok
		time_t heure_a_bangkok = temps_utc + (7 * 3600);

		//L'heure et la date de Bangkok Ville en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_bangkok, "Bangkok");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Hô Chi Minh Ville"...
	else if(strcmp(nom_de_la_ville,"Ho_Chi_Minh") == 0)
	{
		//Calcul de l'heure et de la date à Hô Chi Minh Ville et stockage de celui-ci dans la variable heure_a_ho_chi_minh_ville
                time_t heure_a_ho_chi_minh_ville = temps_utc + (7 * 3600);

		//L'heure et la date de Hô Chi Minh Ville en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_ho_chi_minh_ville, "Hô Chi Minh Ville");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Pyongyang"...
	else if(strcmp(nom_de_la_ville,"Pyongyang") == 0)
	{
		//Calcul de l'heure et de la date à Pyongyang et stockage de celui-ci dans la variable heure_pyongyang
                time_t heure_pyongyang = temps_utc + (9 * 3600);

		//L'heure et la date de Pyongyang en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_pyongyang, "Pyongyang");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Seoul"...
        else if(strcmp(nom_de_la_ville,"Seoul") == 0)
        {
		//Calcul de l'heure et de la date à Seoul et stockage de celui-ci dans la variable heure_seoul
                time_t heure_seoul = temps_utc + (9 * 3600);

		//L'heure et la date de Seoul en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_seoul, "Seoul");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tokyo"...
        else if(strcmp(nom_de_la_ville,"Tokyo") == 0)
        {
		//Calcul de l'heure et de la date à Tokyo et stockage de celui-ci dans la variable heure_tokyo
                time_t heure_tokyo = temps_utc + (9 * 3600);

		//L'heure et la date de Tokyo en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_tokyo, "Tokyo");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Pekin"...
	else if(strcmp(nom_de_la_ville,"Pekin") == 0)
        {
		//Calcul de l'heure et de la date à Pekin et stockage de celui-ci dans la variable heure_pekin
                time_t heure_pekin = temps_utc + (8 * 3600);

		//L'heure et la date de Pekin en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_pekin, "Pekin");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Manille"...
	else if(strcmp(nom_de_la_ville,"Manille") == 0)
	{
		//Calcul de l'heure et de la date à Manille et stockage de celui-ci dans la variable heure_a_manille
                time_t heure_a_manille = temps_utc + (8 * 3600);

		//L'heure et la date de Manille en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_manille, "Manille");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Urumqi"...
	else if(strcmp(nom_de_la_ville,"Urumqi") == 0)
	{
		//Calcul de l'heure et de la date à Urumqi et stockage de celui-ci dans la variable heure_a_urumqi
                time_t heure_a_urumqi = temps_utc + (6 * 3600);

		//L'heure et la date d'Urumqi en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_urumqi, "Urumqi");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Kaliningrad"...
	else if(strcmp(nom_de_la_ville,"Kaliningrad") == 0)
	{
		//Calcul de l'heure et de la date à Kaliningrad et stockage de celui-ci dans la variable heure_kaliningrad
                time_t heure_kaliningrad = temps_utc + (2 * 3600);

		//L'heure et la date de Kaliningrad en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_kaliningrad, "Kaliningrad");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Samara"...
	else if(strcmp(nom_de_la_ville,"Samara") == 0)
	{
		//Calcul de l'heure et de la date à Samara et stockage de celui-ci dans la variable heure_kaliningrad
                time_t heure_samara = temps_utc + (4 * 3600);

		//L'heure et la date de Samara en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_samara, "Samara");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Volgograd"...
	else if(strcmp(nom_de_la_ville,"Volgograd") == 0)
	{
		//Calcul de l'heure et de la date à Samara et stockage de celui-ci dans la variable heure_volgograd
                time_t heure_volgograd = temps_utc + (4 * 3600);

		//L'heure et la date de Volgograd en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_volgograd, "Volgograd");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Saratov"...
	else if(strcmp(nom_de_la_ville,"Saratov") == 0)
	{
		//Calcul de l'heure et de la date à Saratov et stockage de celui-ci dans la variable heure_saratov
                time_t heure_saratov = temps_utc + (4 * 3600);

		//L'heure et la date de Saratov en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_saratov, "Saratov");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Oulianovsk"...
        else if(strcmp(nom_de_la_ville,"Oulianovsk") == 0)
	{
		//Calcul de l'heure et de la date à Oulianovsk et stockage de celui-ci dans la variable heure_oulianovsk
                time_t heure_oulianovsk = temps_utc + (4 * 3600);

		//L'heure et la date de Saratov en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_oulianovsk, "Oulianovsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Astrakhan"...
	else if(strcmp(nom_de_la_ville,"Astrakhan") == 0)
	{
		//Calcul de l'heure et de la date à Astrakhan et stockage de celui-ci dans la variable heure_astrakhan
                time_t heure_astrakhan = temps_utc + (4 * 3600);

		//L'heure et la date d'Astrakhan en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_astrakhan, "Astrakhan");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Anadyr"...
	else if(strcmp(nom_de_la_ville,"Anadyr") == 0)
	{
		//Calcul de l'heure et de la date à Anadyr et stockage de celui-ci dans la variable heure_anadyr
                time_t heure_anadyr = temps_utc + (12 * 3600);

		//L'heure et la date d'Anadyr en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_anadyr, "Anadyr");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Sakhalin"...
	else if(strcmp(nom_de_la_ville,"Sakhalin") == 0)
	{
		//Calcul de l'heure et de la date à Sakhalin et stockage de celui-ci dans la variable heure_sakhalin
                time_t heure_sakhalin = temps_utc + (11 * 3600);

		//L'heure et la date de Sakhalin en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_sakhalin, "Sakhalin");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Omsk"...
	else if(strcmp(nom_de_la_ville,"Omsk") == 0)
	{
		//Calcul de l'heure et de la date à Omsk et stockage de celui-ci dans la variable heure_omsk
                time_t heure_omsk = temps_utc + (6 * 3600);

		//L'heure et la date d'Omsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_omsk, "Omsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tchita"...
	else if(strcmp(nom_de_la_ville,"Tchita") == 0)
	{
		//Calcul de l'heure et de la date à Tchita et stockage de celui-ci dans la variable heure_tchita
                time_t heure_tchita = temps_utc + (9 * 3600);

		//L'heure et la date de Tchita en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_tchita, "Tchita");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tomsk"...
	else if(strcmp(nom_de_la_ville,"Tomsk") == 0)
	{
		//Calcul de l'heure et de la date à Tomsk et stockage de celui-ci dans la variable heure_tomsk
                time_t heure_tomsk = temps_utc + (7 * 3600);

		//L'heure et la date de Tomsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_tomsk, "Tomsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Barnaoul"...
	else if(strcmp(nom_de_la_ville,"Barnaoul") == 0)
	{
		//Calcul de l'heure et de la date à Barnaoul et stockage de celui-ci dans la variable heure_barnaoul
                time_t heure_barnaoul = temps_utc + (7 * 3600);

		//L'heure et la date de Barnaoul en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_barnaoul, "Barnaoul");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Magadan"...
	else if(strcmp(nom_de_la_ville,"Magadan") == 0)
	{
		//Calcul de l'heure et de la date à Magadan et stockage de celui-ci dans la variable heure_magadan
                time_t heure_magadan = temps_utc + (11 * 3600);

		//L'heure et la date de Magadan en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_magadan, "Magadan");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Iekaterinbourg"...
	else if(strcmp(nom_de_la_ville,"Iekaterinbourg") == 0)
	{
		//Calcul de l'heure et de la date à Iekaterinbourg et stockage de celui-ci dans la variable heure_iekaterinbourg
                time_t heure_iekaterinbourg = temps_utc + (5 * 3600);

		//L'heure et la date d'Iekaterinbourg en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_iekaterinbourg, "Iekaterinbourg");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Yakoutsk"...
	else if(strcmp(nom_de_la_ville,"Yakoutsk") == 0)
	{
		//Calcul de l'heure et de la date à Yakoutsk et stockage de celui-ci dans la variable heure_yakoutsk
                time_t heure_yakoutsk = temps_utc + (9 * 3600);

		//L'heure et la date d'Yakoutsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_yakoutsk, "Yakoutsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Irkoutsk"...
	else if(strcmp(nom_de_la_ville,"Irkoutsk") == 0)
	{
		//Calcul de l'heure et de la date à Irkoutsk et stockage de celui-ci dans la variable heure_irkoutsk
                time_t heure_irkoutsk = temps_utc + (8 * 3600);

		//L'heure et la date d'Irkoutsk en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_irkoutsk, "Irkoutsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Khandyga"...
	else if(strcmp(nom_de_la_ville,"Khandyga") == 0)
	{
		//Calcul de l'heure et de la date à Khandyga et stockage de celui-ci dans la variable heure_khandyga
               	time_t heure_khandyga = temps_utc + (9 * 3600);

		//L'heure et la date de Khandyga en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_khandyga, "Khandyga");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Novokouznetsk"...
	else if(strcmp(nom_de_la_ville,"Novokouznetsk") == 0)
	{
		//Calcul de l'heure et de la date à Novokouznetsk et stockage de celui-ci dans la variable heure_novokouznetsk
                time_t heure_novokouznetsk = temps_utc + (7 * 3600);

		//L'heure et la date de Novokouznetsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_novokouznetsk, "Novokouznetsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Nobossibirsk"...
	else if(strcmp(nom_de_la_ville,"Nobossibirsk") == 0)
	{
		//Calcul de l'heure et de la date à Nobossibirsk et stockage de celui-ci dans la variable heure_nobossibirsk
                time_t heure_nobossibirsk = temps_utc + (7 * 3600);

		//L'heure et la date de Nobossibirsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_nobossibirsk, "Nobossibirsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Krasnoyarsk"...
	else if(strcmp(nom_de_la_ville,"Krasnoyarsk") == 0)
	{
		//Calcul de l'heure et de la date à Krasnoyarsk et stockage de celui-ci dans la variable heure_krasnoyarsk
                time_t heure_krasnoyarsk = temps_utc + (7 * 3600);

		//L'heure et la date de Krasnoyarsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_krasnoyarsk, "Krasnoyarsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Oust-Nera"...
	else if(strcmp(nom_de_la_ville,"Oust-Nera") == 0)
	{
		//Calcul de l'heure et de la date à Oust-Nera et stockage de celui-ci dans la variable heure_oust_nera
                time_t heure_oust_nera = temps_utc + (10 * 3600);

		//L'heure et la date d'Oust-Nera en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_oust_nera, "Oust-Nera");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Srednekolymsk"...
	else if(strcmp(nom_de_la_ville,"Srednekolymsk") == 0)
	{
		//Calcul de l'heure et de la date à Srednekolymsk et stockage de celui-ci dans la variable heure_srednekolymsk
                time_t heure_srednekolymsk = temps_utc + (11 * 3600);

		//L'heure et la date de Srednekolymsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_srednekolymsk, "Srednekolymsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Le_Caire"...
	else if(strcmp(nom_de_la_ville,"Le_Caire") == 0)
	{
		//Calcul de l'heure et de la date au Caire et stockage de celui-ci dans la variable heure_le_caire
                time_t heure_le_caire = temps_utc + (2 * 3600);

		//L'heure et la date au Caire en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_le_caire, "Le Caire");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Aden"...
	else if(strcmp(nom_de_la_ville,"Aden") == 0)
	{
		//Calcul de l'heure et de la date à Aden et stockage de celui-ci dans la variable heure_a_aden
                time_t heure_a_aden = temps_utc + (3 * 3600);

		//L'heure et la date à Aden en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_aden, "Aden");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Koweit"...
	else if(strcmp(nom_de_la_ville,"Koweit") == 0)
	{
		//Calcul de l'heure et de la date au Koweit et stockage de celui-ci dans la variable heure_au_koweit
                time_t heure_au_koweit = temps_utc + (3 * 3600);

		//L'heure et la date au Koweit en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_koweit, "Koweit");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Addis-Abeba"...
	else if(strcmp(nom_de_la_ville,"Addis-Abeba") == 0)
	{
		//Calcul de l'heure et de la date à Addis-Abeba et stockage de celui-ci dans la variable heure_a_addis-abeba
                time_t heure_addis_abeba = temps_utc + (3  * 3600);

		//L'heure et la date à Addis-Abeba en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_addis_abeba, "Addis-Abeba");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Brazzaville"...
	else if(strcmp(nom_de_la_ville,"Brazzaville") == 0)
	{
		//Calcul de l'heure et de la date à Brazzaville et stockage de celui-ci dans la variable heure_a_brazzaville
                time_t heure_a_brazzaville = temps_utc + (1 * 3600);

		//L'heure et la date à Brazzaville en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_brazzaville, "Brazzaville");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Kinshasa"...
	else if(strcmp(nom_de_la_ville,"Kinshasa") == 0)
	{
		//Calcul de l'heure et de la date à Kinshasa et stockage de celui-ci dans la variable heure_a_kinshasa
                time_t heure_a_kinshasa = temps_utc + (1 * 3600);

		//L'heure et la date à Kinshasa en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_kinshasa, "Kinshasa");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Lubumbashi"...
	else if(strcmp(nom_de_la_ville,"Lubumbashi") == 0)
	{
		//Calcul de l'heure et de la date à Lubumbashi et stockage de celui-ci dans la variable heure_a_lubumbashi
                time_t heure_a_lubumbashi = temps_utc + (2 * 3600);

		//L'heure et la date à Lubumbashi en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_lubumbashi, "Lubumbashi");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Riyad"...
	else if(strcmp(nom_de_la_ville,"Riyad") == 0)
	{
		//Calcul de l'heure et de la date à Riyad et stockage de celui-ci dans la variable heure_a_riyad
                time_t heure_a_riyad = temps_utc + (3 * 3600);

		//L'heure et la date à Riyad en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_riyad, "Riyad");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Bahrein"...
	else if(strcmp(nom_de_la_ville,"Bahrein") == 0)
	{
		//Calcul de l'heure et de la date au Bahrein et stockage de celui-ci dans la variable heure_au_bahrein
                time_t heure_au_bahrein = temps_utc + (3 * 3600);

		//L'heure et la date au Bahrein en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_bahrein, "Bahrein");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Dubai"...
	else if(strcmp(nom_de_la_ville,"Dubai") == 0)
	{
		//Calcul de l'heure et de la date à Dubai et stockage de celui-ci dans la variable heure_a_dubai
                time_t heure_a_dubai = temps_utc + (4 * 3600);

		//L'heure et la date à Dubai en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_dubai, "Dubai");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Mascate"...
	else if(strcmp(nom_de_la_ville,"Mascate") == 0)
	{
		//Calcul de l'heure et de la date à Mascate et stockage de celui-ci dans la variable heure_a_mascate
                time_t heure_a_mascate = temps_utc + (4 * 3600);

		//L'heure et la date à Mascate en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_mascate, "Mascate");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Qatar"...
	else if(strcmp(nom_de_la_ville,"Qatar") == 0)
	{
		//Calcul de l'heure et de la date au Qatar et stockage de celui-ci dans la variable heure_au_qatar
                time_t heure_au_qatar = temps_utc + (3 * 3600);

		//L'heure et la date au Qatar en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_qatar, "Qatar");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Zurich"...
	else if(strcmp(nom_de_la_ville,"Zurich") == 0)
	{
		//Calcul de l'heure et de la date à Zurich et stockage de celui-ci dans la variable heure_zurich
                time_t heure_zurich = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

		//L'heure et la date à Zurich en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_zurich, "Zurich");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Andorre"...
	else if(strcmp(nom_de_la_ville,"Andorre") == 0)
	{
		//Calcul de l'heure et de la date à Andorre et stockage de celui-ci dans la variable heure_andorre
                time_t heure_andorre = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

		//L'heure et la date à Andorre en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_andorre, "Andorre");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Vaduz"...
	else if(strcmp(nom_de_la_ville,"Vaduz") == 0)
	{
		//Calcul de l'heure et de la date à Vaduz et stockage de celui-ci dans la variable heure_vaduz
                time_t heure_vaduz = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

		//L'heure et la date à Vaduz en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_vaduz, "Vaduz");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Malte"...
	else if(strcmp(nom_de_la_ville,"Malte") == 0)
	{
		//Calcul de l'heure et de la date à Malte et stockage de celui-ci dans la variable heure_malte
                time_t heure_malte = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

		//L'heure et la date à Malte en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_malte, "Malte");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Djibouti"...
	else if(strcmp(nom_de_la_ville,"Djibouti") == 0)
	{
		//Calcul de l'heure et de la date à Djibouti et stockage de celui-ci dans la variable heure_djibouti
                time_t heure_djibouti = temps_utc + (3 * 3600);

		//L'heure et la date à Djibouti en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_djibouti, "Djibouti");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Lusaka"...
	else if(strcmp(nom_de_la_ville,"Lusaka") == 0)
	{
		//Calcul de l'heure et de la date à Lusaka et stockage de celui-ci dans la variable heure_lusaka
                time_t heure_lusaka = temps_utc + (2 * 3600);

		//L'heure et la date à Lusaka en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_lusaka, "Lusaka");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tripoli"...
	else if(strcmp(nom_de_la_ville,"Tripoli") == 0)
	{
		//Calcul de l'heure et de la date à Tripoli et stockage de celui-ci dans la variable heure_tripoli
                time_t heure_tripoli = temps_utc + (2 * 3600);

		//L'heure et la date à Tripoli en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_tripoli, "Tripoli");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Asmara"...
	else if(strcmp(nom_de_la_ville,"Asmara") == 0)
	{
		//Calcul de l'heure et de la date à Asmara et stockage de celui-ci dans la variable heure_a_asmara
                time_t heure_a_asmara = temps_utc + (3 * 3600);

		//L'heure et la date à Asmara en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_asmara, "Asmara");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Harare"...
	else if(strcmp(nom_de_la_ville,"Harare") == 0)
	{
		//Calcul de l'heure et de la date à Harare et stockage de celui-ci dans la variable heure_harare
                time_t heure_harare = temps_utc + (2 * 3600);

		//L'heure et la date à Harare en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_harare, "Harare");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Managua"...
	else if(strcmp(nom_de_la_ville,"Managua") == 0)
	{
		//Calcul de l'heure et de la date à Managua et stockage de celui-ci dans la variable heure_managua
                time_t heure_managua = temps_utc - (6 * 3600);

		//L'heure et la date à Managua en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_managua, "Managua");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Brunei"...
	else if(strcmp(nom_de_la_ville,"Brunei") == 0)
	{
		//Calcul de l'heure et de la date à Brunei et stockage de celui-ci dans la variable heure_brunei
                time_t heure_brunei = temps_utc + (8 * 3600);

		//L'heure et la date à Brunei en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_brunei, "Brunei");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Erevan"...
	else if(strcmp(nom_de_la_ville,"Erevan") == 0)
	{
		//Calcul de l'heure et de la date à Erevan et stockage de celui-ci dans la variable heure_erevan
                time_t heure_erevan = temps_utc + (4 * 3600);

		//L'heure et la date à Erevan en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_erevan, "Erevan");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tbilissi"...
	else if(strcmp(nom_de_la_ville,"Tbilissi") == 0)
	{
		//Calcul de l'heure et de la date à Tbilissi et stockage de celui-ci dans la variable heure_a_tbilissi
		time_t heure_a_tbilissi = temps_utc + (4 * 3600);

		//L'heure et la date à Tbilissi en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_tbilissi, "Tbilissi");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Bakou"...
	else if(strcmp(nom_de_la_ville,"Bakou") == 0)
	{
		//Calcul de l'heure et de la date à Bakou et stockage de celui-ci dans la variable heure_a_bakou
		time_t heure_a_bakou = temps_utc + (4 * 3600);

		//L'heure et la date à Bakou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_bakou, "Bakou");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Mogadiscio"...
	else if(strcmp(nom_de_la_ville,"Mogadiscio") == 0)
	{
		//Calcul de l'heure et de la date à Mogadiscio et stockage de celui-ci dans la variable heure_a_mogadiscio
		time_t heure_a_mogadiscio = temps_utc + (3 * 3600);

		//L'heure et la date à Mogadiscio en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_mogadiscio, "Mogadiscio");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Hovd"...
	else if(strcmp(nom_de_la_ville,"Hovd") == 0)
	{
		//Calcul de l'heure et de la date à Hovd et stockage de celui-ci dans la variable heure_a_hovd
                time_t heure_a_hovd = temps_utc + (7 * 3600);

		//L'heure et la date à Hovd en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_hovd, "Hovd");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tapei"...
	else if(strcmp(nom_de_la_ville,"Tapei") == 0)
	{
		//Calcul de l'heure et de la date à Tapei et stockage de celui-ci dans la variable heure_a_tapei
                time_t heure_a_tapei = temps_utc + (8 * 3600);

		//L'heure et la date à Tapei en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_tapei, "Tapei");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Macao"...
	else if(strcmp(nom_de_la_ville,"Macao") == 0)
	{
		//Calcul de l'heure et de la date à Macao et stockage de celui-ci dans la variable heure_a_macao
                time_t heure_a_macao = temps_utc + (8 * 3600);

		//L'heure et la date à Macao en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_macao, "Macao");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tachkent"...
	else if(strcmp(nom_de_la_ville,"Tachkent") == 0)
	{
		//Calcul de l'heure et de la date à Tachkent et stockage de celui-ci dans la variable heure_a_tachkent
                time_t heure_a_tachkent = temps_utc + (5 * 3600);

		//L'heure et la date à Tachkent en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_tachkent, "Tachkent");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Samarkand"...
        else if(strcmp(nom_de_la_ville,"Samarkand") == 0)
        {
                //Calcul de l'heure et de la date à Samarkand et stockage de celui-ci dans la variable heure_a_samarkand
                time_t heure_a_samarkand = temps_utc + (5 * 3600);

                //L'heure et la date à Samarkand en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_samarkand, "Samarkand");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Dushanbe"...
	else if(strcmp(nom_de_la_ville,"Dushanbe") == 0)
	{
		//Calcul de l'heure et de la date à Douchanbé et stockage de celui-ci dans la variable heure_a_douchanbe
                time_t heure_a_douchanbe = temps_utc + (5 * 3600);

		//L'heure et la date à Douchanbé en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_douchanbe, "Dushanbe");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Thimphou"...
	else if(strcmp(nom_de_la_ville,"Thimphou") == 0)
	{
		//Calcul de l'heure et de la date à Thimphou et stockage de celui-ci dans la variable heure_a_thimphou
                time_t heure_a_thimphou = temps_utc + (6 * 3600);

		//L'heure et la date à Thimphou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_thimphou, "Bhoutan");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Bichkek"...
	else if(strcmp(nom_de_la_ville,"Bichkek") == 0)
	{
		//Calcul de l'heure et de la date à Bichkek et stockage de celui-ci dans la variable heure_a_bichkek
                time_t heure_a_bichkek = temps_utc + (6 * 3600);

		//L'heure et la date à Bichkek en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_bichkek, "Bichkek");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Katmandou"...
	else if(strcmp(nom_de_la_ville,"Katmandou") == 0)
	{
		//Calcul de l'heure et de la date à Katmandou et stockage de celui-ci dans la variable heure_a_katmandou
                time_t heure_a_katmandou = temps_utc + (45 * 60) + (5 * 3600);

		//L'heure et la date à Katmandou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_katmandou, "Katmandou");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Kaboul"...
	else if(strcmp(nom_de_la_ville,"Kaboul") == 0)
	{
		//Calcul de l'heure et de la date à Kaboul et stockage de celui-ci dans la variable heure_a_kaboul
                time_t heure_a_kaboul = temps_utc + (30 * 60) + (4 * 3600);

		//L'heure et la date à Kaboul en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_kaboul, "Kaboul");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Singapour"...
	else if(strcmp(nom_de_la_ville,"Singapour") == 0)
	{
		//Calcul de l'heure et de la date à Singapour et stockage de celui-ci dans la variable heure_a_singapour
                time_t heure_a_singapour = temps_utc + (8 * 3600);

		//L'heure et la date à Singapour en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_singapour, "Singapour");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Hong_Kong"...
	else if(strcmp(nom_de_la_ville,"Hong_Kong") == 0)
	{
		//Calcul de l'heure et de la date à Hong Kong et stockage de celui-ci dans la variable heure_a_hong_kong
                time_t heure_a_hong_kong = temps_utc + (8 * 3600);

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
