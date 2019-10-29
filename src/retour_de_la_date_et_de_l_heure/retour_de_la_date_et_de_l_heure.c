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

	Voici le principe de l'algorithme:

        1) On calcule le temps courant UTC sous forme de timestamp (c'est-à-dire le nombre de secondes écoulées depuis le 1er janvier 1970 à minuit UTC précise),

        2) On applique le changement d'heure pour le fuseau horaire quelconque si celui-ci applique l'heure d'été,

        3) On calcule le temps courant en additionnant le temps UTC par le décalage horaire (en secondes) par rapport à l'UTC pour le fuseau horaire quelconque

        4) Le temps courant pour le fuseau horaire quelconque est affiché.
*/
char* retour_de_l_heure_et_de_la_date_pour_un_fuseau_horaire_determine_et_connu(char* nom_du_fuseau_horaire)
{

	/* Définition de la variable temps_utc et initialisation de celle-ci au temps utc sous forme de timestamp */
        time_t temps_utc = retour_du_temps_utc_sous_forme_de_timestamp();

	/* République française */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Paris"...
	if(strcmp(nom_du_fuseau_horaire,"Europe/Paris") == 0)
	{
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Paris", temps_utc);

		//
		time_t heure_de_paris = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Paris");

		//L'heure et la date de Paris en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_paris, "Europe/Paris");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Cayenne"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Cayenne") == 0)
	{
		//
		time_t heure_de_cayenne = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Cayenne");

		//L'heure et la date de Cayenne en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_cayenne, "Cayenne");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Indian/Reunion"...
	else if(strcmp(nom_du_fuseau_horaire,"Indian/Reunion") == 0)
	{
		//
		time_t heure_de_la_reunion = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Indian/Reunion");

		//L'heure et la date de la Reunion en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_la_reunion, "La Reunion");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Guadeloupe"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Guadeloupe") == 0)
	{
		//
		time_t heure_de_la_guadeloupe = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Guadeloupe");

		//L'heure et la date de la Guadeloupe en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_la_guadeloupe, "La guadeloupe");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Pacific/Noumea"...
	else if(strcmp(nom_du_fuseau_horaire,"Pacific/Noumea") == 0)
	{
		//
		time_t heure_de_noumea = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Noumea");

		//L'heure et la date de Nouméa en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_noumea, "Nouméa");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Indian/Mayotte"...
	else if(strcmp(nom_du_fuseau_horaire,"Indian/Mayotte") == 0)
	{
		//
		time_t heure_de_mayotte = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Indian/Mayotte");

		//L'heure et la date de Mayotte en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_mayotte, "Mayotte");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Indian/Kerguelen"...
	else if(strcmp(nom_du_fuseau_horaire,"Indian/Kerguelen") == 0)
	{
		//
		time_t heure_des_iles_kerguelen = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Indian/Kerguelen");

		//L'heure et la date des îles Kerguelen en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_des_iles_kerguelen, "îles Kerguelen");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Pacific/Tahiti"...
	else if(strcmp(nom_du_fuseau_horaire,"Pacific/Tahiti") == 0)
	{
		//
		time_t heure_de_tahiti = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Tahiti");

		//L'heure et la date pour Tahiti en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_tahiti, "Pacific/Tahiti");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Pacific/Gambier"...
	else if(strcmp(nom_du_fuseau_horaire,"Pacific/Gambier") == 0)
	{
		//
		time_t heure_de_gambier = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Gambier");

		//L'heure et la date pour Gambier en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_gambier, "Pacific/Gambier");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Pacific/Marquesas"...
	else if(strcmp(nom_du_fuseau_horaire,"Pacific/Marquesas") == 0)
	{
		//
		time_t heure_a_marquesas = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Marquesas");

		//L'heure et la date pour Marquesas en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_marquesas, "Pacific/Marquesas");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Miquelon"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Miquelon") == 0)
	{
		//
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Miquelon", temps_utc);

		//
		time_t heure_de_miquelon = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Miquelon");

		//L'heure et la date pour Miquelon en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_miquelon, "America/Miquelon");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/St_Barthelemy"...
	else if(strcmp(nom_du_fuseau_horaire,"America/St_Barthelemy") == 0)
	{
		//
		time_t heure_de_st_barthelemy = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/St_Barthelemy");

		//L'heure et la date pour St Barthelemy en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_st_barthelemy, "America/St_Barthelemy");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Martinique"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Martinique") == 0)
	{
		//
		time_t heure_de_la_martinique = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Martinique");
	
		//L'heure et la date pour la Martinique en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_la_martinique, "America/Martinique");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Pacific/Wallis"...
	else if(strcmp(nom_du_fuseau_horaire,"Pacific/Wallis") == 0)
	{
		//
		time_t heure_de_wallis = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Wallis");

		//L'heure et la date pour Wallis et Futuna en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_wallis, "Pacific/Wallis");
	}

	/* République fédérale d'Allemagne */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Berlin"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Berlin") == 0)
	{
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Berlin", temps_utc);

		//
		time_t heure_de_berlin = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Berlin");

		//L'heure et la date de Berlin en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_berlin, "Europe/Berlin");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Busingen"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Busingen") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Busingen", temps_utc);

                //
                time_t heure_de_busingen = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Busingen");

                //L'heure et la date de Busingen en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_de_busingen, "Europe/Busingen");
        }

	/* République italienne */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Rome"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Rome") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Rome", temps_utc);

                //
                time_t heure_de_rome = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Rome");

                //L'heure et la date de Rome en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_de_rome, "Europe/Rome");
        }

	/* République de Saint-Marin */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Saint_Marin"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/San_Marino") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/San_Marino", temps_utc);

                //
                time_t heure_a_saint_marin = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/San_Marino");

                //L'heure et la date de Saint Marin en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_saint_marin, "Europe/San_Marino");
        }

	/* État de la Cité du Vatican */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Vatican"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Vatican") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Vatican", temps_utc);

                //
                time_t heure_du_vatican = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Vatican");

                //L'heure et la date de Vatican en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_du_vatican, "Europe/Vatican");
        }

	/* Principauté de Monaco */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Monaco"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Monaco") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Monaco", temps_utc);

                //
                time_t heure_a_monaco = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Monaco");

                //L'heure et la date de Monaco en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_monaco, "Europe/Monaco");
        }

	/* Grand-Duché de Luxembourg */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Luxembourg"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Luxembourg") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Luxembourg", temps_utc);

                //
                time_t heure_au_luxembourg = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Luxembourg");

                //L'heure et la date de Luxembourg en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_au_luxembourg, "Europe/Luxembourg");
        }

	/* Royaume de Belgique */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Bruxelles"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Brussels") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Brussels", temps_utc);

                //
                time_t heure_a_bruxelles = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Brussels");

                //L'heure et la date de Bruxelles en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_bruxelles, "Europe/Brussels");
        }

	/* République de Finlande */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Helsinki"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Helsinki") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Helsinki", temps_utc);

                //
                time_t heure_a_helsinki = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Helsinki");

                //L'heure et la date de Helsinki en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_helsinki, "Europe/Helsinki");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Mariehamn"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Mariehamn") == 0)
	{
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Mariehamn", temps_utc);

		//
		time_t heure_a_mariehamn = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Mariehamn");

		//L'heure et la date de Mariehamn en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_mariehamn, "Europe/Mariehamn");
	}

	/* Royaume de Suède */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Stockholm"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Stockholm") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Stockholm", temps_utc);

                //
                time_t heure_a_stockholm = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Stockholm");

                //L'heure et la date de Helsinki en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_stockholm, "Europe/Stockholm");
        }

	/* Royaume de Norvège */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Oslo"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Oslo") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Oslo", temps_utc);

                //
                time_t heure_a_oslo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Oslo");

                //L'heure et la date de Oslo en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_oslo, "Europe/Oslo");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Longyearbyen"...
        else if(strcmp(nom_du_fuseau_horaire,"Arctic/Longyearbyen") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Arctic/Longyearbyen", temps_utc);

                //
                time_t heure_a_longyearbyen = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Arctic/Longyearbyen");

                //L'heure et la date de Longyearbyen en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_longyearbyen, "Arctic/Longyearbyen");
        }

	/* République d'Islande */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Reykjavik"...
        else if(strcmp(nom_du_fuseau_horaire,"Atlantic/Reykjavik") == 0)
        {
                //
                time_t heure_a_reykjavik = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Atlantic/Reykjavik");

                //L'heure et la date de Reykjavik en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_reykjavik, "Atlantic/Reykjavik");
        }

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Vilnius"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Vilnius") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Vilnius", temps_utc);

                //
                time_t heure_a_vilnius = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Vilnius");

                //L'heure et la date de Vilnius en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_vilnius, "Europe/Vilnius");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Riga"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Riga") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Riga", temps_utc);

                //
                time_t heure_a_riga = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Riga");

                //L'heure et la date de Riga en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_riga, "Europe/Riga");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Tallinn"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Tallinn") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Tallinn", temps_utc);

                //
                time_t heure_a_tallinn = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Tallinn");

                //L'heure et la date de Tallinn en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_tallinn, "Europe/Tallinn");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Varsovie"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Warsaw") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Warsaw", temps_utc);

                //
                time_t heure_a_varsovie = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Warsaw");

                //L'heure et la date de Varsovie en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_varsovie, "Europe/Warsaw");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Athènes"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Athens") == 0)
	{
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Athens", temps_utc);

		//Calcul de l'heure et de la date à Athènes et stockage de celui-ci dans la variable heure_d_athenes
		time_t heure_d_athenes = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Athens");

		//L'heure et la date d'Athènes en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_d_athenes, "Europe/Athens");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Los_Angeles"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Los_Angeles") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Los_Angeles", temps_utc);

		//Calcul de l'heure et de la date à Los Angeles et stockage de celui-ci dans la variable heure_los_angeles
		time_t heure_los_angeles = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Los_Angeles");

		//L'heure et la date de Los Angeles en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_los_angeles, "America/Los Angeles");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "New_York"...
	else if(strcmp(nom_du_fuseau_horaire,"America/New_York") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord   
                application_du_changement_d_heure_pour_l_amerique_du_nord("America/New_York", temps_utc);

		//Calcul de l'heure et de la date à New York et stockage de celui-ci dans la variable heure_de_nyc
                time_t heure_de_nyc = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/New_York");

		//L'heure et la date de New York City en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_nyc, "America/New_York");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Ottawa"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Toronto") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
                application_du_changement_d_heure_pour_l_amerique_du_nord("America/Toronto", temps_utc);

		//Calcul de l'heure et de la date à Ottawa et stockage de celui-ci dans la variable heure_d_ottawa
                time_t heure_de_toronto = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Toronto");

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
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Chisinau", temps_utc);

                //Calcul de l'heure et de la date à Chisinau et stockage de celui-ci dans la variable heure_a_chisinau
                time_t heure_a_chisinau = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Chisinau");

                //L'heure et la date de Chisinau en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_chisinau, "Europe/Chisinau");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Minsk"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Minsk") == 0)
        {
                //Calcul de l'heure et de la date à Minsk et stockage de celui-ci dans la variable heure_a_minsk
                time_t heure_a_minsk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Minsk");;

                //L'heure et la date de Minsk en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_minsk, "Europe/Minsk");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Kiev"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Kiev") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Kiev", temps_utc);

                //Calcul de l'heure et de la date à Kiev et stockage de celui-ci dans la variable heure_a_kiev
                time_t heure_a_kiev = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Kiev");

                //L'heure et la date de Kiev en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_kiev, "Europe/Kiev");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Uzhgorod"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Uzhgorod") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Uzhgorod", temps_utc);

                //Calcul de l'heure et de la date à Uzhgorod et stockage de celui-ci dans la variable heure_a_uzhgorod
                time_t heure_a_uzhgorod = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Uzhgorod");

                //L'heure et la date de Uzhgorod en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_uzhgorod, "Europe/Uzhgorod");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Zaporozhye"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Zaporozhye") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Zaporozhye", temps_utc);

                //Calcul de l'heure et de la date à Zaporozhye et stockage de celui-ci dans la variable heure_a_zaporozhye
                time_t heure_a_zaporozhye = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Zaporozhye");

                //L'heure et la date de Uzhgorod en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_zaporozhye, "Europe/Zaporozhye");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Moscou"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Moscow") == 0)
        {
		//Calcul de l'heure et de la date à Moscou et stockage de celui-ci dans la variable heure_moscou
                time_t heure_moscou = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Moscow");

		//L'heure et la date de Moscou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_moscou, "Moscou");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Vladivostok"...
        else if(strcmp(nom_du_fuseau_horaire,"Asia/Vladivostok") == 0)
        {
		//Calcul de l'heure et de la date à Vladivostok et stockage de celui-ci dans la variable heure_vladivostok
                time_t heure_vladivostok = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Vladivostok");

		//L'heure et la date de Vladivostok en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_vladivostok, "Vladivostok");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Auckland"...
	else if(strcmp(nom_du_fuseau_horaire,"Pacific/Auckland") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour la Nouvelle Zélande
        	application_du_changement_d_heure_pour_la_nouvelle_zelande("Pacific/Auckland", temps_utc);

		//Calcul de l'heure et de la date à Auckland et stockage de celui-ci dans la variable heure_a_auckland
                time_t heure_a_auckland = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Auckland");

		//L'heure et la date d'Auckland en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_auckland, "Auckland");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Sydney"...
        else if(strcmp(nom_du_fuseau_horaire,"Australia/Sydney") == 0)
        {
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Australie
		application_du_changement_d_heure_pour_l_australie("Australia/Sydney", temps_utc);

		//Calcul de l'heure et de la date à Sydney et stockage de celui-ci dans la variable heure_a_sydney
                time_t heure_a_sydney = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Sydney");

		//L'heure et la date de Sydney en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_sydney, "Sydney");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Santiago"...
        else if(strcmp(nom_du_fuseau_horaire,"America/Santiago") == 0)
        {
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour le Chili
		application_du_changement_d_heure_pour_le_chili("America/Santiago", temps_utc);

		//Calcul de l'heure et de la date à Santiago du Chili et stockage de celui-ci dans la variable heure_santiago_chili
                time_t heure_santiago_chili = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Santiago");

		//L'heure et la date de Santiago du Chili en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_santiago_chili, "Santiago du Chili");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Punta_Arenas"...
	else if(strcmp(nom_du_fuseau_horaire,"Punta_Arenas") == 0)
	{
		//Calcul de l'heure et de la date à Punta Arenas et stockage de celui-ci dans la variable heure_a_punta_arenas
		time_t heure_a_punta_arenas = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Punta_Arenas");

		//L'heure et la date de Punta Arenas en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_punta_arenas, "Punta Arenas");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Easter"...
	else if(strcmp(nom_du_fuseau_horaire,"Pacific/Easter") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour le Chili
		application_du_changement_d_heure_pour_le_chili("Pacific/Easter", temps_utc);

		//Calcul de l'heure et de la date sur l'île de Pâques et stockage de celui-ci dans la variable heure_
                time_t heure_ile_de_paques = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Easter");;

		//L'heure et la date sur l'île de Pâcques en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_ile_de_paques, "Ile de Pâques");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Johannesburg"...
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Johannesburg") == 0)
        {
		//Calcul de l'heure et de la date à Johannesburg et stockage de celui-ci dans la variable heure_johannesburg
                time_t heure_johannesburg = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Johannesburg");

		//L'heure et la date de Johannesburg en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_johannesburg, "Johannesburg");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Khartoum"...
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Khartoum") == 0)
	{
		//Calcul de l'heure et de la date à Khartoum et stockage de celui-ci dans la variable heure_a_khartoum
		time_t heure_a_khartoum = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Khartoum");

		//L'heure et la date de Khartoum en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_khartoum, "Khartoum");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Djouba"...
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Juba") == 0)
	{
		//Calcul de l'heure et de la date à Djouba et stockage de celui-ci dans la variable heure_a_djouba
		time_t heure_a_djouba = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Juba");

		//L'heure et la date de Djouba en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_djouba, "Djouba");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Alger"...
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Algiers") == 0)
	{
		//Calcul de l'heure et de la date à Alger et stockage de celui-ci dans la variable heure_a_alger
                time_t heure_a_alger = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Algiers");

		//L'heure et la date d'Alger en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_alger, "Africa/Algiers");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Nairobi"...
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Nairobi") == 0)
	{
		//Calcul de l'heure et de la date à Nairobi et stockage de celui-ci dans la variable heure_a_nairobi
                time_t heure_a_nairobi = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Nairobi");

		//L'heure et la date de Nairobi en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_nairobi, "Africa/Nairobi");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Dar_es_Salam"...
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Dar_es_Salaam") == 0)
	{
		//Calcul de l'heure et de la date à Dar es Salem et stockage de celui-ci dans la variable heure_a_dar_es_salam
                time_t heure_a_dar_es_salam = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Dar_es_Salaam");

		//L'heure et la date de Dar es Salam en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_dar_es_salam, "Africa/Dar_es_Salaam");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Buenos_Aires"...
        else if(strcmp(nom_du_fuseau_horaire,"America/Argentina/Buenos_Aires") == 0)
        {
		//Calcul de l'heure et de la date à Buenos Aires et stockage de celui-ci dans la variable heure_buenos_aires
                time_t heure_buenos_aires = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Argentina/Buenos_Aires");

		//L'heure et la date de Buenos Aires en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_buenos_aires, "America/Argentina/Buenos_Aires");
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
	else if(strcmp(nom_du_fuseau_horaire,"America/Bogota") == 0)
	{
		//Calcul de l'heure et de la date à Bogota et stockage de celui-ci dans la variable heure_a_bogota
                time_t heure_a_bogota = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Bogota");;

		//L'heure et la date de Bogota en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_bogota, "America/Bogota");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Caracas"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Caracas") == 0)
	{
		//Calcul de l'heure et de la date à Caracas et stockage de celui-ci dans la variable heure_caracas
                time_t heure_a_caracas = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Caracas");

		//L'heure et la date de Caracas en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_caracas, "America/Caracas");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Guayaquil"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Guayaquil") == 0)
	{
		//Calcul de l'heure et de la date à Guayaquil et stockage de celui-ci dans la variable heure_a_guayaquil
                time_t heure_a_guayaquil = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Guayaquil");

		//L'heure et la date de Guayaquil en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_guayaquil, "America/Guayaquil");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Galapagos"...
	else if(strcmp(nom_du_fuseau_horaire,"Pacific/Galapagos") == 0)
	{
		//Calcul de l'heure et de la date à Galapagos et stockage de celui-ci dans la variable heure_a_galapagos
                time_t heure_a_galapagos = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Galapagos");

		//L'heure et la date de Galapagos en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_galapagos, "Pacific/Galapagos");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "La Paz"...
	else if(strcmp(nom_du_fuseau_horaire,"America/La_Paz") == 0)
	{
		//Calcul de l'heure et de la date à La Paz et stockage de celui-ci dans la variable heure_a_la_paz
                time_t heure_a_la_paz = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/La_Paz");

		//L'heure et la date de La Paz en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_la_paz, "America/La_Paz");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Antananarivo"...
        else if(strcmp(nom_du_fuseau_horaire,"Indian/Antananarivo") == 0)
        {
		//Calcul de l'heure et de la date à Antananarivo et stockage de celui-ci dans la variable heure_antananarivo
                time_t heure_antananarivo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Indian/Antananarivo");;

		//L'heure et la date de Antananarivo en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_antananarivo, "Indian/Antananarivo");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Windhoek"...
        else if(strcmp(nom_du_fuseau_horaire,"Africa/Windhoek") == 0)
        {
		//Calcul de l'heure et de la date à Windhoek et stockage de celui-ci dans la variable heure_windhoek
                time_t heure_windhoek = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Windhoek");

		//L'heure et la date de Windhoek en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_windhoek, "Africa/Windhoek");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Lima"...
        else if(strcmp(nom_du_fuseau_horaire,"America/Lima") == 0)
        {
		//Calcul de l'heure et de la date à Lima et stockage de celui-ci dans la variable heure_lima
                time_t heure_lima = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Lima");

		//L'heure et la date de Lima en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_lima, "America/Lima");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Bangkok"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Bangkok") == 0)
	{
		//Calcul de l'heure et de la date à Bangkok et stockage de celui-ci dans la variable heure_a_bangkok
		time_t heure_a_bangkok = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Bangkok");

		//L'heure et la date de Bangkok Ville en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_bangkok, "Asia/Bangkok");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Ho_Chi_Minh"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Ho_Chi_Minh") == 0)
	{
		//Calcul de l'heure et de la date à Hô Chi Minh Ville et stockage de celui-ci dans la variable heure_a_ho_chi_minh_ville
                time_t heure_a_ho_chi_minh_ville = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Ho_Chi_Minh");

		//L'heure et la date de Hô Chi Minh Ville en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_ho_chi_minh_ville, "Asia/Ho_Chi_Minh");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Pyongyang"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Pyongyang") == 0)
	{
		//Calcul de l'heure et de la date à Pyongyang et stockage de celui-ci dans la variable heure_pyongyang
                time_t heure_pyongyang = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Pyongyang");

		//L'heure et la date de Pyongyang en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_pyongyang, "Asia/Pyongyang");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Seoul"...
        else if(strcmp(nom_du_fuseau_horaire,"Asia/Seoul") == 0)
        {
		//Calcul de l'heure et de la date à Seoul et stockage de celui-ci dans la variable heure_seoul
                time_t heure_seoul = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Seoul");

		//L'heure et la date de Seoul en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_seoul, "Seoul");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Tokyo"...
        else if(strcmp(nom_du_fuseau_horaire,"Asia/Tokyo") == 0)
        {
		//Calcul de l'heure et de la date à Tokyo et stockage de celui-ci dans la variable heure_tokyo
                time_t heure_tokyo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Tokyo");

		//L'heure et la date de Tokyo en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_tokyo, "Asia/Tokyo");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Pekin"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Shanghai") == 0)
        {
		//Calcul de l'heure et de la date à Pekin et stockage de celui-ci dans la variable heure_pekin
                time_t heure_pekin = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Shanghai");

		//L'heure et la date de Pekin en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_pekin, "Asia/Shanghai");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Manille"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Manila") == 0)
	{
		//Calcul de l'heure et de la date à Manille et stockage de celui-ci dans la variable heure_a_manille
                time_t heure_a_manille = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Manila");

		//L'heure et la date de Manille en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_manille, "Asia/Manila");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Urumqi"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Urumqi") == 0)
	{
		//Calcul de l'heure et de la date à Urumqi et stockage de celui-ci dans la variable heure_a_urumqi
                time_t heure_a_urumqi = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Urumqi");

		//L'heure et la date d'Urumqi en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_urumqi, "Asia/Urumqi");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Kaliningrad"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Kaliningrad") == 0)
	{
		//Calcul de l'heure et de la date à Kaliningrad et stockage de celui-ci dans la variable heure_kaliningrad
                time_t heure_kaliningrad = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Kaliningrad");

		//L'heure et la date de Kaliningrad en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_kaliningrad, "Europe/Kaliningrad");
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
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Cairo") == 0)
	{
		//Calcul de l'heure et de la date au Caire et stockage de celui-ci dans la variable heure_le_caire
                time_t heure_le_caire = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Cairo");

		//L'heure et la date au Caire en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_le_caire, "Africa/Cairo");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Aden"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Aden") == 0)
	{
		//Calcul de l'heure et de la date à Aden et stockage de celui-ci dans la variable heure_a_aden
                time_t heure_a_aden = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Aden");

		//L'heure et la date à Aden en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_aden, "Asia/Aden");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Koweit"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Kuwait") == 0)
	{
		//Calcul de l'heure et de la date au Koweit et stockage de celui-ci dans la variable heure_au_koweit
                time_t heure_au_koweit = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Kuwait");

		//L'heure et la date au Koweit en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_koweit, "Asia/Kuwait");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Addis-Abeba"...
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Addis_Ababa") == 0)
	{
		//Calcul de l'heure et de la date à Addis-Abeba et stockage de celui-ci dans la variable heure_a_addis-abeba
                time_t heure_addis_abeba = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Addis_Ababa");

		//L'heure et la date à Addis-Abeba en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_addis_abeba, "Africa/Addis_Ababa");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Brazzaville"...
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Brazzaville") == 0)
	{
		//Calcul de l'heure et de la date à Brazzaville et stockage de celui-ci dans la variable heure_a_brazzaville
                time_t heure_a_brazzaville = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Brazzaville");

		//L'heure et la date à Brazzaville en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_brazzaville, "Africa/Brazzaville");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Kinshasa"...
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Kinshasa") == 0)
	{
		//Calcul de l'heure et de la date à Kinshasa et stockage de celui-ci dans la variable heure_a_kinshasa
                time_t heure_a_kinshasa = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Kinshasa");

		//L'heure et la date à Kinshasa en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_kinshasa, "Africa/Kinshasa");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Lubumbashi"...
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Lubumbashi") == 0)
	{
		//Calcul de l'heure et de la date à Lubumbashi et stockage de celui-ci dans la variable heure_a_lubumbashi
                time_t heure_a_lubumbashi = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Lubumbashi");

		//L'heure et la date à Lubumbashi en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_lubumbashi, "Africa/Lubumbashi");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Riyad"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Riyadh") == 0)
	{
		//Calcul de l'heure et de la date à Riyad et stockage de celui-ci dans la variable heure_a_riyad
                time_t heure_a_riyad = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Riyadh");

		//L'heure et la date à Riyad en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_riyad, "Asia/Riyadh");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Bahrein"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Bahrain") == 0)
	{
		//Calcul de l'heure et de la date au Bahrein et stockage de celui-ci dans la variable heure_au_bahrein
                time_t heure_au_bahrein = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Bahrain");

		//L'heure et la date au Bahrein en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_bahrein, "Asia/Bahrain");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Dubai"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Dubai") == 0)
	{
		//Calcul de l'heure et de la date à Dubai et stockage de celui-ci dans la variable heure_a_dubai
                time_t heure_a_dubai = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Dubai");

		//L'heure et la date à Dubai en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_dubai, "Asia/Dubai");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Mascate"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Muscat") == 0)
	{
		//Calcul de l'heure et de la date à Mascate et stockage de celui-ci dans la variable heure_a_mascate
                time_t heure_a_mascate = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Muscat");

		//L'heure et la date à Mascate en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_mascate, "Asia/Muscat");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Qatar"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Qatar") == 0)
	{
		//Calcul de l'heure et de la date au Qatar et stockage de celui-ci dans la variable heure_au_qatar
                time_t heure_au_qatar = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Qatar");

		//L'heure et la date au Qatar en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_qatar, "Asia/Qatar");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Zurich"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Zurich") == 0)
	{
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Zurich", temps_utc);

		//Calcul de l'heure et de la date à Zurich et stockage de celui-ci dans la variable heure_zurich
                time_t heure_zurich = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Zurich");

		//L'heure et la date à Zurich en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_zurich, "Europe/Zurich");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Andorre"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Andorra") == 0)
	{
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Andorra", temps_utc);

		//Calcul de l'heure et de la date à Andorre et stockage de celui-ci dans la variable heure_andorre
                time_t heure_andorre = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Andorra");

		//L'heure et la date à Andorre en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_andorre, "Europe/Andorra");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Vaduz"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Vaduz") == 0)
	{
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Vaduz", temps_utc);

		//Calcul de l'heure et de la date à Vaduz et stockage de celui-ci dans la variable heure_vaduz
                time_t heure_vaduz = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Vaduz");

		//L'heure et la date à Vaduz en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_vaduz, "Europe/Vaduz");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Malte"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Malta") == 0)
	{
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Malta", temps_utc);

		//Calcul de l'heure et de la date à Malte et stockage de celui-ci dans la variable heure_malte
                time_t heure_malte = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Malta");

		//L'heure et la date à Malte en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_malte, "Europe/Malta");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Djibouti"...
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Djibouti") == 0)
	{
		//Calcul de l'heure et de la date à Djibouti et stockage de celui-ci dans la variable heure_djibouti
                time_t heure_djibouti = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Djibouti");

		//L'heure et la date à Djibouti en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_djibouti, "Africa/Djibouti");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Lusaka"...
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Lusaka") == 0)
	{
		//Calcul de l'heure et de la date à Lusaka et stockage de celui-ci dans la variable heure_lusaka
                time_t heure_lusaka = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Lusaka");

		//L'heure et la date à Lusaka en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_lusaka, "Africa/Lusaka");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Tripoli"...
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Tripoli") == 0)
	{
		//Calcul de l'heure et de la date à Tripoli et stockage de celui-ci dans la variable heure_tripoli
                time_t heure_tripoli = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Tripoli");

		//L'heure et la date à Tripoli en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_tripoli, "Africa/Tripoli");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asmara"...
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Asmara") == 0)
	{
		//Calcul de l'heure et de la date à Asmara et stockage de celui-ci dans la variable heure_a_asmara
                time_t heure_a_asmara = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Asmara");

		//L'heure et la date à Asmara en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_asmara, "Africa/Asmara");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Harare"...
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Harare") == 0)
	{
		//Calcul de l'heure et de la date à Harare et stockage de celui-ci dans la variable heure_harare
                time_t heure_harare = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Harare");

		//L'heure et la date à Harare en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_harare, "Africa/Harare");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Managua"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Managua") == 0)
	{
		//Calcul de l'heure et de la date à Managua et stockage de celui-ci dans la variable heure_managua
                time_t heure_managua = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Managua");

		//L'heure et la date à Managua en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_managua, "America/Managua");
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
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Kathmandu") == 0)
	{
		//Calcul de l'heure et de la date à Katmandou et stockage de celui-ci dans la variable heure_a_katmandou
                time_t heure_a_katmandou = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Kathmandu");

		//L'heure et la date à Katmandou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_katmandou, "Asia/Kathmandu");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Kaboul"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Kabul") == 0)
	{
		//Calcul de l'heure et de la date à Kaboul et stockage de celui-ci dans la variable heure_a_kaboul
                time_t heure_a_kaboul = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Kabul");

		//L'heure et la date à Kaboul en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_kaboul, "Asia/Kabul");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Singapour"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Singapore") == 0)
	{
		//Calcul de l'heure et de la date à Singapour et stockage de celui-ci dans la variable heure_a_singapour
                time_t heure_a_singapour = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Singapore");

		//L'heure et la date à Singapour en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_singapour, "Asia/Singapore");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Hong_Kong"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Hong_Kong") == 0)
	{
		//Calcul de l'heure et de la date à Hong Kong et stockage de celui-ci dans la variable heure_a_hong_kong
                time_t heure_a_hong_kong = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Hong_Kong");

		//L'heure et la date à Hong Kong en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_hong_kong, "Asia/Hong_Kong");
	}
	//Sinon...
	else
	{
		//
		return "Erreur: Le fuseau horaire entré en paramétre est inconnue...pour le moment.";
	}
}
