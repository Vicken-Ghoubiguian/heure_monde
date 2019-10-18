/* Inclusion des bibliothéques standards du C utilisées dans cette bibliothéque-ci */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Inclusion des bibliothéques internes à l'API */
#include "retour_de_la_date_et_de_l_heure.h"
#include "../application_des_decalages_horaires/application_des_decalages_horaires.h"
#include "../affichage_de_l_horloge/affichage_de_l_horloge.h"
#include "../fonctions_d_affichage_et_de_renvoie_de_l_heure_et_de_la_date/fonctions_d_affichage_et_de_renvoie_de_l_heure_et_de_la_date.h"
#include "../bibliotheque_de_fonctions_utiles/bibliotheque_de_fonctions_utiles.h"

//Cette fonction calcule puis retourne l'heure courant et la date courante pour un fuseau horaire déterminé et connu passé en paramétre sous forme d'une chaine de caractéres
/*
	Explication du calcul:

	Prenons un fuseau horaire quelconque noté zone_quelquonque/fuseau_horaire_quelquonque.

	Définissons, pour le fuseau horaire zone_quelquonque/fuseau_horaire_quelquonque, les régles suivantes:

	-> Sur le fuseau zone_quelquonque/fuseau_horaire_quelquonque: UTC+03:00 (heure d'hiver),

	-> Sur le fuseau zone_quelquonque/fuseau_horaire_quelquonque: UTC+04:00 (heure d'été).

	UTC étant la notation officielle pour "Universel Temps Coordonné": échelle de temps adoptée comme base du temps civil international par la majorité des pays du globe (wikipedia).

	Donc:

	-> heure_pour_fuseau_horaire_quelquonque = temps_utc_courant_en_temps_reel + (nombre_de_minutes_de_decalage_entre_l_utc_et_le_fuseau_horaire_quelquonque * nombre_de_secondes_dans_une_minute) + ((nombre_d_heure_de_decalage_entre_l_utc_et_le_fuseau_horaire_quelquonque * nombre_de_secondes_dans_une_heure) + (application_du_changement_d_heure_pour_le_fuseau_horaire_quelquonque * nombre_de_secondes_dans_une_heure))

	Avec:

	-> nombre_de_secondes_dans_une_heure = 3600 (une heure étant composée de 3600 secondes),

	-> nombre_de_secondes_dans_une_minute = 60 (une minute étant composée de 60 secondes).

	application_du_changement_d_heure_pour_le_fuseau_horaire_quelquonque est une fonction qui applique, pour le fuseau zone_quelquonque/fuseau_horaire_quelquonque, le changement d'heure (d'hiver à été et réciproquement) selon les régles établies par le pays, ou la zone géographique, dans lequel est situé le fuseau zone_quelquonque/fuseau_horaire_quelquonque.
*/
char* retour_de_l_heure_et_de_la_date_pour_un_fuseau_horaire_determine_et_connu(char* nom_du_fuseau_horaire)
{

	/* Définition de la variable temps_utc et initialisation de celle-ci au temps utc sous forme de timestamp */
        time_t temps_utc = retour_du_temps_utc_sous_forme_de_timestamp();

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Paris"...
	if(strcmp(nom_du_fuseau_horaire,"Europe/Paris") == 0)
	{

		//
		time_t heure_de_paris = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

		//L'heure et la date de Paris en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_paris, "Europe/Paris");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Berlin"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Berlin") == 0)
	{
		//
		time_t heure_de_berlin = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

		//L'heure et la date de Berlin en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_berlin, "Europe/Berlin");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Busingen"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Busingen") == 0)
        {
                //
                time_t heure_de_busingen = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

                //L'heure et la date de Busingen en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_de_busingen, "Europe/Busingen");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Rome"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Rome") == 0)
        {
                //
                time_t heure_de_rome = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

                //L'heure et la date de Rome en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_de_rome, "Europe/Rome");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Saint_Marin"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/San_Marino") == 0)
        {
                //
                time_t heure_a_saint_marin = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

                //L'heure et la date de Saint Marin en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_saint_marin, "Europe/San_Marino");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Vatican"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Vatican") == 0)
        {
                //
                time_t heure_du_vatican = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

                //L'heure et la date de Vatican en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_du_vatican, "Europe/Vatican");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Monaco"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Monaco") == 0)
        {
                //
                time_t heure_a_monaco = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

                //L'heure et la date de Monaco en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_monaco, "Europe/Monaco");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Luxembourg"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Luxembourg") == 0)
        {
                //
                time_t heure_au_luxembourg = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

                //L'heure et la date de Luxembourg en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_au_luxembourg, "Europe/Luxembourg");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Bruxelles"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Brussels") == 0)
        {
                //
                time_t heure_a_bruxelles = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

                //L'heure et la date de Bruxelles en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_bruxelles, "Europe/Brussels");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Helsinki"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Helsinki") == 0)
        {
                //
                time_t heure_a_helsinki = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

                //L'heure et la date de Helsinki en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_helsinki, "Europe/Helsinki");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Stockholm"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Stockholm") == 0)
        {
                //
                time_t heure_a_stockholm = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

                //L'heure et la date de Helsinki en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_stockholm, "Europe/Stockholm");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Oslo"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Oslo") == 0)
        {
                //
                time_t heure_a_oslo = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

                //L'heure et la date de Oslo en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_oslo, "Europe/Oslo");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Longyearbyen"...
        else if(strcmp(nom_du_fuseau_horaire,"Arctic/Longyearbyen") == 0)
        {
                //
                time_t heure_a_longyearbyen = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

                //L'heure et la date de Longyearbyen en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_longyearbyen, "Arctic/Longyearbyen");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Reykjavik"...
        else if(strcmp(nom_du_fuseau_horaire,"Atlantic/Reykjavik") == 0)
        {
                //
                time_t heure_a_reykjavik = temps_utc;

                //L'heure et la date de Reykjavik en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_reykjavik, "Atlantic/Reykjavik");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Vilnius"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Vilnius") == 0)
        {
                //
                time_t heure_a_vilnius = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

                //L'heure et la date de Vilnius en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_vilnius, "Europe/Vilnius");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Riga"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Riga") == 0)
        {
                //
                time_t heure_a_riga = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

                //L'heure et la date de Riga en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_riga, "Europe/Riga");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Tallinn"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Tallinn") == 0)
        {
                //
                time_t heure_a_tallinn = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

                //L'heure et la date de Tallinn en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_tallinn, "Europe/Tallinn");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Varsovie"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Warsaw") == 0)
        {
                //
                time_t heure_a_varsovie = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

                //L'heure et la date de Varsovie en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_varsovie, "Europe/Warsaw");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Athènes"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Athens") == 0)
	{
		//Calcul de l'heure et de la date à Athènes et stockage de celui-ci dans la variable heure_d_athenes
		time_t heure_d_athenes = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

		//L'heure et la date d'Athènes en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_d_athenes, "Europe/Athens");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Los_Angeles"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Los_Angeles") == 0)
	{
		//Calcul de l'heure et de la date à Los Angeles et stockage de celui-ci dans la variable heure_los_angeles
		time_t heure_los_angeles = temps_utc - ((8 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600));

		//L'heure et la date de Los Angeles en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_los_angeles, "America/Los Angeles");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "New_York"...
	else if(strcmp(nom_du_fuseau_horaire,"America/New_York") == 0)
	{
		//Calcul de l'heure et de la date à New York et stockage de celui-ci dans la variable heure_de_nyc
                time_t heure_de_nyc = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600));

		//L'heure et la date de New York City en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_nyc, "America/New_York");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Ottawa"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Toronto") == 0)
	{
		//Calcul de l'heure et de la date à Ottawa et stockage de celui-ci dans la variable heure_d_ottawa
                time_t heure_de_toronto = temps_utc - ((5 * 3600) - (application_du_changement_d_heure_pour_l_amerique_du_nord(temps_utc) * 3600));

		//L'heure et la date de Ottawa en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_toronto, "America/Toronto");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Phoenix"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Phoenix") == 0)
	{
		//Calcul de l'heure et de la date à Phoenix et stockage de celui-ci dans la variable heure_de_phoenix
                time_t heure_de_phoenix = temps_utc - (7 * 3600); //Phoenix

		//L'heure et la date de Phoenix en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_phoenix, "America/Phoenix");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Londres"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/London") == 0)
        {
		//Calcul de l'heure et de la date à Londres et stockage de celui-ci dans la variable heure_de_londres
                //time_t heure_de_londres = temps_utc + (application_du_changement_d_heure_pour_la_grande_bretagne(temps_utc) * 3600);

		//L'heure et la date de Londres en temps réel est retournée
		//return calcul_et_renvoie_horaire(heure_de_londres, "Europe/London");
		return "";
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Chisinau"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Chisinau") == 0)
        {
                //Calcul de l'heure et de la date à Chisinau et stockage de celui-ci dans la variable heure_a_chisinau
                time_t heure_a_chisinau = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

                //L'heure et la date de Chisinau en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_chisinau, "Europe/Chisinau");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Minsk"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Minsk") == 0)
        {
                //Calcul de l'heure et de la date à Minsk et stockage de celui-ci dans la variable heure_a_minsk
                time_t heure_a_minsk = temps_utc + (3 * 3600);

                //L'heure et la date de Minsk en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_minsk, "Europe/Minsk");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Kiev"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Kiev") == 0)
        {
                //Calcul de l'heure et de la date à Kiev et stockage de celui-ci dans la variable heure_a_kiev
                time_t heure_a_kiev = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

                //L'heure et la date de Kiev en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_kiev, "Europe/Kiev");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Uzhgorod"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Uzhgorod") == 0)
        {
                //Calcul de l'heure et de la date à Uzhgorod et stockage de celui-ci dans la variable heure_a_uzhgorod
                time_t heure_a_uzhgorod = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

                //L'heure et la date de Uzhgorod en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_uzhgorod, "Europe/Uzhgorod");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Zaporozhye"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Zaporozhye") == 0)
        {
                //Calcul de l'heure et de la date à Zaporozhye et stockage de celui-ci dans la variable heure_a_zaporozhye
                time_t heure_a_zaporozhye = temps_utc + (2 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

                //L'heure et la date de Uzhgorod en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_zaporozhye, "Europe/Zaporozhye");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Moscou"...
        else if(strcmp(nom_du_fuseau_horaire,"Moscou") == 0)
        {
		//Calcul de l'heure et de la date à Moscou et stockage de celui-ci dans la variable heure_moscou
                time_t heure_moscou = temps_utc + (3 * 3600);

		//L'heure et la date de Moscou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_moscou, "Moscou");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Vladivostok"...
        else if(strcmp(nom_du_fuseau_horaire,"Vladivostok") == 0)
        {
		//Calcul de l'heure et de la date à Vladivostok et stockage de celui-ci dans la variable heure_vladivostok
                time_t heure_vladivostok = temps_utc + (10 * 3600);

		//L'heure et la date de Vladivostok en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_vladivostok, "Vladivostok");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Auckland"...
	else if(strcmp(nom_du_fuseau_horaire,"Auckland") == 0)
	{
		//Calcul de l'heure et de la date à Auckland et stockage de celui-ci dans la variable heure_a_auckland
                //time_t heure_a_auckland = temps_utc + ((13 * 3600) - (application_du_changement_d_heure_pour_la_nouvelle_zelande(temps_utc) * 3600));

		//L'heure et la date d'Auckland en temps réel est retournée
		//return calcul_et_renvoie_horaire(heure_a_auckland, "Auckland");
		return "";
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Sydney"...
        else if(strcmp(nom_du_fuseau_horaire,"Sydney") == 0)
        {
		//Calcul de l'heure et de la date à Sydney et stockage de celui-ci dans la variable heure_a_sydney
                //time_t heure_a_sydney = temps_utc + ((11 * 3600) - (application_du_changement_d_heure_pour_l_australie(temps_utc) * 3600));

		//L'heure et la date de Sydney en temps réel est retournée
		//return calcul_et_renvoie_horaire(heure_a_sydney, "Sydney");
		return "";
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Santiago"...
        else if(strcmp(nom_du_fuseau_horaire,"Santiago") == 0)
        {
		//Calcul de l'heure et de la date à Santiago du Chili et stockage de celui-ci dans la variable heure_santiago_chili
                //time_t heure_santiago_chili = temps_utc - ((4 * 3600) - (application_du_changement_d_heure_pour_le_chili(temps_utc)  * 3600));

		//L'heure et la date de Santiago du Chili en temps réel est retournée
		//return calcul_et_renvoie_horaire(heure_santiago_chili, "Santiago du Chili");
		return "";
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Punta_Arenas"...
	else if(strcmp(nom_du_fuseau_horaire,"Punta_Arenas") == 0)
	{
		//Calcul de l'heure et de la date à Punta Arenas et stockage de celui-ci dans la variable heure_a_punta_arenas
		//time_t heure_a_punta_arenas = temps_utc - (3 * 3600);

		//L'heure et la date de Punta Arenas en temps réel est retournée
		//return calcul_et_renvoie_horaire(heure_a_punta_arenas, "Punta Arenas");
		return "";
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Easter"...
	else if(strcmp(nom_du_fuseau_horaire,"Easter") == 0)
	{
		//Calcul de l'heure et de la date sur l'île de Pâques et stockage de celui-ci dans la variable heure_
                //time_t heure_ile_de_paques = temps_utc - ((6 * 3600)  - (application_du_changement_d_heure_pour_le_chili(temps_utc) * 3600));

		//L'heure et la date sur l'île de Pâcques en temps réel est retournée
		//return calcul_et_renvoie_horaire(heure_ile_de_paques, "Ile de Pâques");

		return "";
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Johannesburg"...
	else if(strcmp(nom_du_fuseau_horaire,"Johannesburg") == 0)
        {
		//Calcul de l'heure et de la date à Johannesburg et stockage de celui-ci dans la variable heure_johannesburg
                time_t heure_johannesburg = temps_utc + (2 * 3600);

		//L'heure et la date de Johannesburg en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_johannesburg, "Johannesburg");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Khartoum"...
	else if(strcmp(nom_du_fuseau_horaire,"Khartoum") == 0)
	{
		//Calcul de l'heure et de la date à Khartoum et stockage de celui-ci dans la variable heure_a_khartoum
		time_t heure_a_khartoum = temps_utc + (2 * 3600);

		//L'heure et la date de Khartoum en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_khartoum, "Khartoum");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Djouba"...
	else if(strcmp(nom_du_fuseau_horaire,"Djouba") == 0)
	{
		//Calcul de l'heure et de la date à Djouba et stockage de celui-ci dans la variable heure_a_djouba
		time_t heure_a_djouba = temps_utc + (3 * 3600);

		//L'heure et la date de Djouba en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_djouba, "Djouba");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Alger"...
	else if(strcmp(nom_du_fuseau_horaire,"Alger") == 0)
	{
		//Calcul de l'heure et de la date à Alger et stockage de celui-ci dans la variable heure_a_alger
                time_t heure_a_alger = temps_utc + (1 * 3600);

		//L'heure et la date d'Alger en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_alger, "Alger");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Nairobi"...
	else if(strcmp(nom_du_fuseau_horaire,"Nairobi") == 0)
	{
		//Calcul de l'heure et de la date à Nairobi et stockage de celui-ci dans la variable heure_a_nairobi
                time_t heure_a_nairobi = temps_utc + (3 * 3600);

		//L'heure et la date de Nairobi en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_nairobi, "Nairobi");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Dar_es_Salam"...
	else if(strcmp(nom_du_fuseau_horaire,"Dar_es_Salam") == 0)
	{
		//Calcul de l'heure et de la date à Dar es Salem et stockage de celui-ci dans la variable heure_a_dar_es_salam
                time_t heure_a_dar_es_salam = temps_utc + (3 * 3600);

		//L'heure et la date de Dar es Salam en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_dar_es_salam, "Dar es Salam");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Buenos_Aires"...
        else if(strcmp(nom_du_fuseau_horaire,"Buenos_Aires") == 0)
        {
		//Calcul de l'heure et de la date à Buenos Aires et stockage de celui-ci dans la variable heure_buenos_aires
                time_t heure_buenos_aires = temps_utc - (3 * 3600);

		//L'heure et la date de Buenos Aires en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_buenos_aires, "Buenos Aires");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Guatemala"...
	else if(strcmp(nom_du_fuseau_horaire,"Guatemala") == 0)
	{
		//Calcul de l'heure et de la date au Guatemala et stockage de celui-ci dans la variable heure_au_guatemala
                time_t heure_au_guatemala = temps_utc - (6 * 3600);

		//L'heure et la date au Guatemala en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_guatemala, "Guatemala");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Costa_Rica"...
	else if(strcmp(nom_du_fuseau_horaire,"Costa_Rica") == 0)
	{
		//Calcul de l'heure et de la date au Costa Rica et stockage de celui-ci dans la variable heure_au_costa_rica
                time_t heure_au_costa_rica = temps_utc - (6 * 3600);

		//L'heure et la date du Costa Rica en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_costa_rica, "Costa Rica");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Tegucigalpa"...
	else if(strcmp(nom_du_fuseau_horaire,"Tegucigalpa") == 0)
	{
		//Calcul de l'heure et de la date à Tegucigalpa et stockage de celui-ci dans la variable heure_au_honduras
                time_t heure_au_honduras = temps_utc - (6 * 3600);

		//L'heure et la date du Honduras en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_honduras, "Tegucigalpa");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Panama"...
	else if(strcmp(nom_du_fuseau_horaire,"Panama") == 0)
	{
		//Calcul de l'heure et de la date au Panama et stockage de celui-ci dans la variable heure_au_panama
                time_t heure_au_panama = temps_utc - (5 * 3600);

		//L'heure et la date au Panama en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_panama, "Panama");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "El_Salvador"...
	else if(strcmp(nom_du_fuseau_horaire,"El_Salvador") == 0)
	{
		//Calcul de l'heure et de la date au Panama et stockage de celui-ci dans la variable heure_d_el_salvador
                time_t heure_d_el_salvador = temps_utc - (6 * 3600);

		//L'heure et la date a El Salvador en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_d_el_salvador, "El Salvador");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale au "Belize"...
	else if(strcmp(nom_du_fuseau_horaire,"Belize") == 0)
	{
		//Calcul de l'heure et de la date au Belize et stockage de celui-ci dans la variable heure_au_belize
                time_t heure_au_belize = temps_utc - (6 * 3600);

		//L'heure et la date au Belize en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_belize, "Belize");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Bogota"...
	else if(strcmp(nom_du_fuseau_horaire,"Bogota") == 0)
	{
		//Calcul de l'heure et de la date à Bogota et stockage de celui-ci dans la variable heure_a_bogota
                time_t heure_a_bogota = temps_utc - (5 * 3600);

		//L'heure et la date de Bogota en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_bogota, "Bogota");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Caracas"...
	else if(strcmp(nom_du_fuseau_horaire,"Caracas") == 0)
	{
		//Calcul de l'heure et de la date à Caracas et stockage de celui-ci dans la variable heure_caracas
                time_t heure_a_caracas = temps_utc - (4 * 3600);

		//L'heure et la date de Caracas en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_caracas, "Caracas");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Guayaquil"...
	else if(strcmp(nom_du_fuseau_horaire,"Guayaquil") == 0)
	{
		//Calcul de l'heure et de la date à Guayaquil et stockage de celui-ci dans la variable heure_a_guayaquil
                time_t heure_a_guayaquil = temps_utc - (5 * 3600);

		//L'heure et la date de Guayaquil en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_guayaquil, "Guayaquil");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Galapagos"...
	else if(strcmp(nom_du_fuseau_horaire,"Galapagos") == 0)
	{
		//Calcul de l'heure et de la date à Galapagos et stockage de celui-ci dans la variable heure_a_galapagos
                time_t heure_a_galapagos = temps_utc - (6 * 3600);

		//L'heure et la date de Galapagos en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_galapagos, "Galapagos");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "La Paz"...
	else if(strcmp(nom_du_fuseau_horaire,"La_Paz") == 0)
	{
		//Calcul de l'heure et de la date à La Paz et stockage de celui-ci dans la variable heure_a_la_paz
                time_t heure_a_la_paz = temps_utc - (4 * 3600);

		//L'heure et la date de La Paz en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_la_paz, "La Paz");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Antananarivo"...
        else if(strcmp(nom_du_fuseau_horaire,"Antananarivo") == 0)
        {
		//Calcul de l'heure et de la date à Antananarivo et stockage de celui-ci dans la variable heure_antananarivo
                time_t heure_antananarivo = temps_utc + (3 * 3600);

		//L'heure et la date de Antananarivo en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_antananarivo, "Antananarivo");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Windhoek"...
        else if(strcmp(nom_du_fuseau_horaire,"Windhoek") == 0)
        {
		//Calcul de l'heure et de la date à Windhoek et stockage de celui-ci dans la variable heure_windhoek
                time_t heure_windhoek = temps_utc + (2 * 3600);

		//L'heure et la date de Windhoek en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_windhoek, "Windhoek");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Lima"...
        else if(strcmp(nom_du_fuseau_horaire,"Lima") == 0)
        {
		//Calcul de l'heure et de la date à Lima et stockage de celui-ci dans la variable heure_lima
                time_t heure_lima = temps_utc - (5 * 3600);

		//L'heure et la date de Lima en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_lima, "Lima");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Bangkok"...
	else if(strcmp(nom_du_fuseau_horaire,"Bangkok") == 0)
	{
		//Calcul de l'heure et de la date à Bangkok et stockage de celui-ci dans la variable heure_a_bangkok
		time_t heure_a_bangkok = temps_utc + (7 * 3600);

		//L'heure et la date de Bangkok Ville en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_bangkok, "Bangkok");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Ho_Chi_Minh"...
	else if(strcmp(nom_du_fuseau_horaire,"Ho_Chi_Minh") == 0)
	{
		//Calcul de l'heure et de la date à Hô Chi Minh Ville et stockage de celui-ci dans la variable heure_a_ho_chi_minh_ville
                time_t heure_a_ho_chi_minh_ville = temps_utc + (7 * 3600);

		//L'heure et la date de Hô Chi Minh Ville en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_ho_chi_minh_ville, "Hô Chi Minh Ville");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Pyongyang"...
	else if(strcmp(nom_du_fuseau_horaire,"Pyongyang") == 0)
	{
		//Calcul de l'heure et de la date à Pyongyang et stockage de celui-ci dans la variable heure_pyongyang
                time_t heure_pyongyang = temps_utc + (9 * 3600);

		//L'heure et la date de Pyongyang en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_pyongyang, "Pyongyang");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Seoul"...
        else if(strcmp(nom_du_fuseau_horaire,"Seoul") == 0)
        {
		//Calcul de l'heure et de la date à Seoul et stockage de celui-ci dans la variable heure_seoul
                time_t heure_seoul = temps_utc + (9 * 3600);

		//L'heure et la date de Seoul en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_seoul, "Seoul");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Tokyo"...
        else if(strcmp(nom_du_fuseau_horaire,"Tokyo") == 0)
        {
		//Calcul de l'heure et de la date à Tokyo et stockage de celui-ci dans la variable heure_tokyo
                time_t heure_tokyo = temps_utc + (9 * 3600);

		//L'heure et la date de Tokyo en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_tokyo, "Tokyo");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Pekin"...
	else if(strcmp(nom_du_fuseau_horaire,"Pekin") == 0)
        {
		//Calcul de l'heure et de la date à Pekin et stockage de celui-ci dans la variable heure_pekin
                time_t heure_pekin = temps_utc + (8 * 3600);

		//L'heure et la date de Pekin en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_pekin, "Pekin");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Manille"...
	else if(strcmp(nom_du_fuseau_horaire,"Manille") == 0)
	{
		//Calcul de l'heure et de la date à Manille et stockage de celui-ci dans la variable heure_a_manille
                time_t heure_a_manille = temps_utc + (8 * 3600);

		//L'heure et la date de Manille en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_manille, "Manille");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Urumqi"...
	else if(strcmp(nom_du_fuseau_horaire,"Urumqi") == 0)
	{
		//Calcul de l'heure et de la date à Urumqi et stockage de celui-ci dans la variable heure_a_urumqi
                time_t heure_a_urumqi = temps_utc + (6 * 3600);

		//L'heure et la date d'Urumqi en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_urumqi, "Urumqi");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Kaliningrad"...
	else if(strcmp(nom_du_fuseau_horaire,"Kaliningrad") == 0)
	{
		//Calcul de l'heure et de la date à Kaliningrad et stockage de celui-ci dans la variable heure_kaliningrad
                time_t heure_kaliningrad = temps_utc + (2 * 3600);

		//L'heure et la date de Kaliningrad en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_kaliningrad, "Kaliningrad");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Samara"...
	else if(strcmp(nom_du_fuseau_horaire,"Samara") == 0)
	{
		//Calcul de l'heure et de la date à Samara et stockage de celui-ci dans la variable heure_kaliningrad
                time_t heure_samara = temps_utc + (4 * 3600);

		//L'heure et la date de Samara en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_samara, "Samara");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Volgograd"...
	else if(strcmp(nom_du_fuseau_horaire,"Volgograd") == 0)
	{
		//Calcul de l'heure et de la date à Samara et stockage de celui-ci dans la variable heure_volgograd
                time_t heure_volgograd = temps_utc + (4 * 3600);

		//L'heure et la date de Volgograd en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_volgograd, "Volgograd");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Saratov"...
	else if(strcmp(nom_du_fuseau_horaire,"Saratov") == 0)
	{
		//Calcul de l'heure et de la date à Saratov et stockage de celui-ci dans la variable heure_saratov
                time_t heure_saratov = temps_utc + (4 * 3600);

		//L'heure et la date de Saratov en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_saratov, "Saratov");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Oulianovsk"...
        else if(strcmp(nom_du_fuseau_horaire,"Oulianovsk") == 0)
	{
		//Calcul de l'heure et de la date à Oulianovsk et stockage de celui-ci dans la variable heure_oulianovsk
                time_t heure_oulianovsk = temps_utc + (4 * 3600);

		//L'heure et la date de Saratov en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_oulianovsk, "Oulianovsk");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Astrakhan"...
	else if(strcmp(nom_du_fuseau_horaire,"Astrakhan") == 0)
	{
		//Calcul de l'heure et de la date à Astrakhan et stockage de celui-ci dans la variable heure_astrakhan
                time_t heure_astrakhan = temps_utc + (4 * 3600);

		//L'heure et la date d'Astrakhan en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_astrakhan, "Astrakhan");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Anadyr"...
	else if(strcmp(nom_du_fuseau_horaire,"Anadyr") == 0)
	{
		//Calcul de l'heure et de la date à Anadyr et stockage de celui-ci dans la variable heure_anadyr
                time_t heure_anadyr = temps_utc + (12 * 3600);

		//L'heure et la date d'Anadyr en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_anadyr, "Anadyr");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Sakhalin"...
	else if(strcmp(nom_du_fuseau_horaire,"Sakhalin") == 0)
	{
		//Calcul de l'heure et de la date à Sakhalin et stockage de celui-ci dans la variable heure_sakhalin
                time_t heure_sakhalin = temps_utc + (11 * 3600);

		//L'heure et la date de Sakhalin en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_sakhalin, "Sakhalin");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Omsk"...
	else if(strcmp(nom_du_fuseau_horaire,"Omsk") == 0)
	{
		//Calcul de l'heure et de la date à Omsk et stockage de celui-ci dans la variable heure_omsk
                time_t heure_omsk = temps_utc + (6 * 3600);

		//L'heure et la date d'Omsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_omsk, "Omsk");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Tchita"...
	else if(strcmp(nom_du_fuseau_horaire,"Tchita") == 0)
	{
		//Calcul de l'heure et de la date à Tchita et stockage de celui-ci dans la variable heure_tchita
                time_t heure_tchita = temps_utc + (9 * 3600);

		//L'heure et la date de Tchita en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_tchita, "Tchita");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Tomsk"...
	else if(strcmp(nom_du_fuseau_horaire,"Tomsk") == 0)
	{
		//Calcul de l'heure et de la date à Tomsk et stockage de celui-ci dans la variable heure_tomsk
                time_t heure_tomsk = temps_utc + (7 * 3600);

		//L'heure et la date de Tomsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_tomsk, "Tomsk");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Barnaoul"...
	else if(strcmp(nom_du_fuseau_horaire,"Barnaoul") == 0)
	{
		//Calcul de l'heure et de la date à Barnaoul et stockage de celui-ci dans la variable heure_barnaoul
                time_t heure_barnaoul = temps_utc + (7 * 3600);

		//L'heure et la date de Barnaoul en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_barnaoul, "Barnaoul");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Magadan"...
	else if(strcmp(nom_du_fuseau_horaire,"Magadan") == 0)
	{
		//Calcul de l'heure et de la date à Magadan et stockage de celui-ci dans la variable heure_magadan
                time_t heure_magadan = temps_utc + (11 * 3600);

		//L'heure et la date de Magadan en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_magadan, "Magadan");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Iekaterinbourg"...
	else if(strcmp(nom_du_fuseau_horaire,"Iekaterinbourg") == 0)
	{
		//Calcul de l'heure et de la date à Iekaterinbourg et stockage de celui-ci dans la variable heure_iekaterinbourg
                time_t heure_iekaterinbourg = temps_utc + (5 * 3600);

		//L'heure et la date d'Iekaterinbourg en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_iekaterinbourg, "Iekaterinbourg");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Yakoutsk"...
	else if(strcmp(nom_du_fuseau_horaire,"Yakoutsk") == 0)
	{
		//Calcul de l'heure et de la date à Yakoutsk et stockage de celui-ci dans la variable heure_yakoutsk
                time_t heure_yakoutsk = temps_utc + (9 * 3600);

		//L'heure et la date d'Yakoutsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_yakoutsk, "Yakoutsk");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Irkoutsk"...
	else if(strcmp(nom_du_fuseau_horaire,"Irkoutsk") == 0)
	{
		//Calcul de l'heure et de la date à Irkoutsk et stockage de celui-ci dans la variable heure_irkoutsk
                time_t heure_irkoutsk = temps_utc + (8 * 3600);

		//L'heure et la date d'Irkoutsk en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_irkoutsk, "Irkoutsk");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Khandyga"...
	else if(strcmp(nom_du_fuseau_horaire,"Khandyga") == 0)
	{
		//Calcul de l'heure et de la date à Khandyga et stockage de celui-ci dans la variable heure_khandyga
               	time_t heure_khandyga = temps_utc + (9 * 3600);

		//L'heure et la date de Khandyga en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_khandyga, "Khandyga");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Novokouznetsk"...
	else if(strcmp(nom_du_fuseau_horaire,"Novokouznetsk") == 0)
	{
		//Calcul de l'heure et de la date à Novokouznetsk et stockage de celui-ci dans la variable heure_novokouznetsk
                time_t heure_novokouznetsk = temps_utc + (7 * 3600);

		//L'heure et la date de Novokouznetsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_novokouznetsk, "Novokouznetsk");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Nobossibirsk"...
	else if(strcmp(nom_du_fuseau_horaire,"Nobossibirsk") == 0)
	{
		//Calcul de l'heure et de la date à Nobossibirsk et stockage de celui-ci dans la variable heure_nobossibirsk
                time_t heure_nobossibirsk = temps_utc + (7 * 3600);

		//L'heure et la date de Nobossibirsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_nobossibirsk, "Nobossibirsk");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Krasnoyarsk"...
	else if(strcmp(nom_du_fuseau_horaire,"Krasnoyarsk") == 0)
	{
		//Calcul de l'heure et de la date à Krasnoyarsk et stockage de celui-ci dans la variable heure_krasnoyarsk
                time_t heure_krasnoyarsk = temps_utc + (7 * 3600);

		//L'heure et la date de Krasnoyarsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_krasnoyarsk, "Krasnoyarsk");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Oust-Nera"...
	else if(strcmp(nom_du_fuseau_horaire,"Oust-Nera") == 0)
	{
		//Calcul de l'heure et de la date à Oust-Nera et stockage de celui-ci dans la variable heure_oust_nera
                time_t heure_oust_nera = temps_utc + (10 * 3600);

		//L'heure et la date d'Oust-Nera en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_oust_nera, "Oust-Nera");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Srednekolymsk"...
	else if(strcmp(nom_du_fuseau_horaire,"Srednekolymsk") == 0)
	{
		//Calcul de l'heure et de la date à Srednekolymsk et stockage de celui-ci dans la variable heure_srednekolymsk
                time_t heure_srednekolymsk = temps_utc + (11 * 3600);

		//L'heure et la date de Srednekolymsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_srednekolymsk, "Srednekolymsk");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Le_Caire"...
	else if(strcmp(nom_du_fuseau_horaire,"Le_Caire") == 0)
	{
		//Calcul de l'heure et de la date au Caire et stockage de celui-ci dans la variable heure_le_caire
                time_t heure_le_caire = temps_utc + (2 * 3600);

		//L'heure et la date au Caire en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_le_caire, "Le Caire");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Aden"...
	else if(strcmp(nom_du_fuseau_horaire,"Aden") == 0)
	{
		//Calcul de l'heure et de la date à Aden et stockage de celui-ci dans la variable heure_a_aden
                time_t heure_a_aden = temps_utc + (3 * 3600);

		//L'heure et la date à Aden en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_aden, "Aden");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Koweit"...
	else if(strcmp(nom_du_fuseau_horaire,"Koweit") == 0)
	{
		//Calcul de l'heure et de la date au Koweit et stockage de celui-ci dans la variable heure_au_koweit
                time_t heure_au_koweit = temps_utc + (3 * 3600);

		//L'heure et la date au Koweit en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_koweit, "Koweit");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Addis-Abeba"...
	else if(strcmp(nom_du_fuseau_horaire,"Addis-Abeba") == 0)
	{
		//Calcul de l'heure et de la date à Addis-Abeba et stockage de celui-ci dans la variable heure_a_addis-abeba
                time_t heure_addis_abeba = temps_utc + (3  * 3600);

		//L'heure et la date à Addis-Abeba en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_addis_abeba, "Addis-Abeba");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Brazzaville"...
	else if(strcmp(nom_du_fuseau_horaire,"Brazzaville") == 0)
	{
		//Calcul de l'heure et de la date à Brazzaville et stockage de celui-ci dans la variable heure_a_brazzaville
                time_t heure_a_brazzaville = temps_utc + (1 * 3600);

		//L'heure et la date à Brazzaville en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_brazzaville, "Brazzaville");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Kinshasa"...
	else if(strcmp(nom_du_fuseau_horaire,"Kinshasa") == 0)
	{
		//Calcul de l'heure et de la date à Kinshasa et stockage de celui-ci dans la variable heure_a_kinshasa
                time_t heure_a_kinshasa = temps_utc + (1 * 3600);

		//L'heure et la date à Kinshasa en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_kinshasa, "Kinshasa");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Lubumbashi"...
	else if(strcmp(nom_du_fuseau_horaire,"Lubumbashi") == 0)
	{
		//Calcul de l'heure et de la date à Lubumbashi et stockage de celui-ci dans la variable heure_a_lubumbashi
                time_t heure_a_lubumbashi = temps_utc + (2 * 3600);

		//L'heure et la date à Lubumbashi en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_lubumbashi, "Lubumbashi");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Riyad"...
	else if(strcmp(nom_du_fuseau_horaire,"Riyad") == 0)
	{
		//Calcul de l'heure et de la date à Riyad et stockage de celui-ci dans la variable heure_a_riyad
                time_t heure_a_riyad = temps_utc + (3 * 3600);

		//L'heure et la date à Riyad en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_riyad, "Riyad");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Bahrein"...
	else if(strcmp(nom_du_fuseau_horaire,"Bahrein") == 0)
	{
		//Calcul de l'heure et de la date au Bahrein et stockage de celui-ci dans la variable heure_au_bahrein
                time_t heure_au_bahrein = temps_utc + (3 * 3600);

		//L'heure et la date au Bahrein en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_bahrein, "Bahrein");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Dubai"...
	else if(strcmp(nom_du_fuseau_horaire,"Dubai") == 0)
	{
		//Calcul de l'heure et de la date à Dubai et stockage de celui-ci dans la variable heure_a_dubai
                time_t heure_a_dubai = temps_utc + (4 * 3600);

		//L'heure et la date à Dubai en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_dubai, "Dubai");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Mascate"...
	else if(strcmp(nom_du_fuseau_horaire,"Mascate") == 0)
	{
		//Calcul de l'heure et de la date à Mascate et stockage de celui-ci dans la variable heure_a_mascate
                time_t heure_a_mascate = temps_utc + (4 * 3600);

		//L'heure et la date à Mascate en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_mascate, "Mascate");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Qatar"...
	else if(strcmp(nom_du_fuseau_horaire,"Qatar") == 0)
	{
		//Calcul de l'heure et de la date au Qatar et stockage de celui-ci dans la variable heure_au_qatar
                time_t heure_au_qatar = temps_utc + (3 * 3600);

		//L'heure et la date au Qatar en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_qatar, "Qatar");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Zurich"...
	else if(strcmp(nom_du_fuseau_horaire,"Zurich") == 0)
	{
		//Calcul de l'heure et de la date à Zurich et stockage de celui-ci dans la variable heure_zurich
                time_t heure_zurich = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

		//L'heure et la date à Zurich en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_zurich, "Zurich");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Andorre"...
	else if(strcmp(nom_du_fuseau_horaire,"Andorre") == 0)
	{
		//Calcul de l'heure et de la date à Andorre et stockage de celui-ci dans la variable heure_andorre
                time_t heure_andorre = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

		//L'heure et la date à Andorre en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_andorre, "Andorre");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Vaduz"...
	else if(strcmp(nom_du_fuseau_horaire,"Vaduz") == 0)
	{
		//Calcul de l'heure et de la date à Vaduz et stockage de celui-ci dans la variable heure_vaduz
                time_t heure_vaduz = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

		//L'heure et la date à Vaduz en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_vaduz, "Vaduz");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Malte"...
	else if(strcmp(nom_du_fuseau_horaire,"Malte") == 0)
	{
		//Calcul de l'heure et de la date à Malte et stockage de celui-ci dans la variable heure_malte
                time_t heure_malte = temps_utc + (1 * 3600) + (application_du_changement_d_heure_pour_l_europe_continentale(temps_utc) * 3600);

		//L'heure et la date à Malte en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_malte, "Malte");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Djibouti"...
	else if(strcmp(nom_du_fuseau_horaire,"Djibouti") == 0)
	{
		//Calcul de l'heure et de la date à Djibouti et stockage de celui-ci dans la variable heure_djibouti
                time_t heure_djibouti = temps_utc + (3 * 3600);

		//L'heure et la date à Djibouti en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_djibouti, "Djibouti");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Lusaka"...
	else if(strcmp(nom_du_fuseau_horaire,"Lusaka") == 0)
	{
		//Calcul de l'heure et de la date à Lusaka et stockage de celui-ci dans la variable heure_lusaka
                time_t heure_lusaka = temps_utc + (2 * 3600);

		//L'heure et la date à Lusaka en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_lusaka, "Lusaka");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Tripoli"...
	else if(strcmp(nom_du_fuseau_horaire,"Tripoli") == 0)
	{
		//Calcul de l'heure et de la date à Tripoli et stockage de celui-ci dans la variable heure_tripoli
                time_t heure_tripoli = temps_utc + (2 * 3600);

		//L'heure et la date à Tripoli en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_tripoli, "Tripoli");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asmara"...
	else if(strcmp(nom_du_fuseau_horaire,"Asmara") == 0)
	{
		//Calcul de l'heure et de la date à Asmara et stockage de celui-ci dans la variable heure_a_asmara
                time_t heure_a_asmara = temps_utc + (3 * 3600);

		//L'heure et la date à Asmara en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_asmara, "Asmara");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Harare"...
	else if(strcmp(nom_du_fuseau_horaire,"Harare") == 0)
	{
		//Calcul de l'heure et de la date à Harare et stockage de celui-ci dans la variable heure_harare
                time_t heure_harare = temps_utc + (2 * 3600);

		//L'heure et la date à Harare en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_harare, "Harare");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Managua"...
	else if(strcmp(nom_du_fuseau_horaire,"Managua") == 0)
	{
		//Calcul de l'heure et de la date à Managua et stockage de celui-ci dans la variable heure_managua
                time_t heure_managua = temps_utc - (6 * 3600);

		//L'heure et la date à Managua en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_managua, "Managua");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Brunei"...
	else if(strcmp(nom_du_fuseau_horaire,"Brunei") == 0)
	{
		//Calcul de l'heure et de la date à Brunei et stockage de celui-ci dans la variable heure_brunei
                time_t heure_brunei = temps_utc + (8 * 3600);

		//L'heure et la date à Brunei en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_brunei, "Brunei");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Erevan"...
	else if(strcmp(nom_du_fuseau_horaire,"Erevan") == 0)
	{
		//Calcul de l'heure et de la date à Erevan et stockage de celui-ci dans la variable heure_erevan
                time_t heure_erevan = temps_utc + (4 * 3600);

		//L'heure et la date à Erevan en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_erevan, "Erevan");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Tbilissi"...
	else if(strcmp(nom_du_fuseau_horaire,"Tbilissi") == 0)
	{
		//Calcul de l'heure et de la date à Tbilissi et stockage de celui-ci dans la variable heure_a_tbilissi
		time_t heure_a_tbilissi = temps_utc + (4 * 3600);

		//L'heure et la date à Tbilissi en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_tbilissi, "Tbilissi");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Bakou"...
	else if(strcmp(nom_du_fuseau_horaire,"Bakou") == 0)
	{
		//Calcul de l'heure et de la date à Bakou et stockage de celui-ci dans la variable heure_a_bakou
		time_t heure_a_bakou = temps_utc + (4 * 3600);

		//L'heure et la date à Bakou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_bakou, "Bakou");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Mogadiscio"...
	else if(strcmp(nom_du_fuseau_horaire,"Mogadiscio") == 0)
	{
		//Calcul de l'heure et de la date à Mogadiscio et stockage de celui-ci dans la variable heure_a_mogadiscio
		time_t heure_a_mogadiscio = temps_utc + (3 * 3600);

		//L'heure et la date à Mogadiscio en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_mogadiscio, "Mogadiscio");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Hovd"...
	else if(strcmp(nom_du_fuseau_horaire,"Hovd") == 0)
	{
		//Calcul de l'heure et de la date à Hovd et stockage de celui-ci dans la variable heure_a_hovd
                time_t heure_a_hovd = temps_utc + (7 * 3600);

		//L'heure et la date à Hovd en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_hovd, "Hovd");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Tapei"...
	else if(strcmp(nom_du_fuseau_horaire,"Tapei") == 0)
	{
		//Calcul de l'heure et de la date à Tapei et stockage de celui-ci dans la variable heure_a_tapei
                time_t heure_a_tapei = temps_utc + (8 * 3600);

		//L'heure et la date à Tapei en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_tapei, "Tapei");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Macao"...
	else if(strcmp(nom_du_fuseau_horaire,"Macao") == 0)
	{
		//Calcul de l'heure et de la date à Macao et stockage de celui-ci dans la variable heure_a_macao
                time_t heure_a_macao = temps_utc + (8 * 3600);

		//L'heure et la date à Macao en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_macao, "Macao");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Tachkent"...
	else if(strcmp(nom_du_fuseau_horaire,"Tachkent") == 0)
	{
		//Calcul de l'heure et de la date à Tachkent et stockage de celui-ci dans la variable heure_a_tachkent
                time_t heure_a_tachkent = temps_utc + (5 * 3600);

		//L'heure et la date à Tachkent en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_tachkent, "Tachkent");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Samarkand"...
        else if(strcmp(nom_du_fuseau_horaire,"Samarkand") == 0)
        {
                //Calcul de l'heure et de la date à Samarkand et stockage de celui-ci dans la variable heure_a_samarkand
                time_t heure_a_samarkand = temps_utc + (5 * 3600);

                //L'heure et la date à Samarkand en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_samarkand, "Samarkand");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Dushanbe"...
	else if(strcmp(nom_du_fuseau_horaire,"Dushanbe") == 0)
	{
		//Calcul de l'heure et de la date à Douchanbé et stockage de celui-ci dans la variable heure_a_douchanbe
                time_t heure_a_douchanbe = temps_utc + (5 * 3600);

		//L'heure et la date à Douchanbé en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_douchanbe, "Dushanbe");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Thimphou"...
	else if(strcmp(nom_du_fuseau_horaire,"Thimphou") == 0)
	{
		//Calcul de l'heure et de la date à Thimphou et stockage de celui-ci dans la variable heure_a_thimphou
                time_t heure_a_thimphou = temps_utc + (6 * 3600);

		//L'heure et la date à Thimphou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_thimphou, "Bhoutan");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Bichkek"...
	else if(strcmp(nom_du_fuseau_horaire,"Bichkek") == 0)
	{
		//Calcul de l'heure et de la date à Bichkek et stockage de celui-ci dans la variable heure_a_bichkek
                time_t heure_a_bichkek = temps_utc + (6 * 3600);

		//L'heure et la date à Bichkek en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_bichkek, "Bichkek");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Katmandou"...
	else if(strcmp(nom_du_fuseau_horaire,"Katmandou") == 0)
	{
		//Calcul de l'heure et de la date à Katmandou et stockage de celui-ci dans la variable heure_a_katmandou
                time_t heure_a_katmandou = temps_utc + (45 * 60) + (5 * 3600);

		//L'heure et la date à Katmandou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_katmandou, "Katmandou");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Kaboul"...
	else if(strcmp(nom_du_fuseau_horaire,"Kaboul") == 0)
	{
		//Calcul de l'heure et de la date à Kaboul et stockage de celui-ci dans la variable heure_a_kaboul
                time_t heure_a_kaboul = temps_utc + (30 * 60) + (4 * 3600);

		//L'heure et la date à Kaboul en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_kaboul, "Kaboul");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Singapour"...
	else if(strcmp(nom_du_fuseau_horaire,"Singapour") == 0)
	{
		//Calcul de l'heure et de la date à Singapour et stockage de celui-ci dans la variable heure_a_singapour
                time_t heure_a_singapour = temps_utc + (8 * 3600);

		//L'heure et la date à Singapour en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_singapour, "Singapour");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Hong_Kong"...
	else if(strcmp(nom_du_fuseau_horaire,"Hong_Kong") == 0)
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
		return "Erreur: Le fuseau horaire entré en paramétre est inconnue...pour le moment.";
	}
}
