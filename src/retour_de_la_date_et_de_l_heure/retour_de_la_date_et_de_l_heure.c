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

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Paris"...
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

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Berlin"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Berlin") == 0)
	{
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Berlin", temps_utc);

		//
		time_t heure_de_berlin = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Berlin");

		//L'heure et la date de Berlin en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_berlin, "Europe/Berlin");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Busingen"...
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

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Rome"...
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

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/San_Marino"...
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

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Vatican"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Vatican") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Vatican", temps_utc);

                //
                time_t heure_du_vatican = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Vatican");

                //L'heure et la date de Vatican en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_du_vatican, "Europe/Vatican");
        }

	/* Royaume d'Espagne */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Madrid"
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Madrid") == 0)
	{
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Madrid", temps_utc);

		//
		time_t heure_a_madrid = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Madrid");

		//L'heure et la date de Madrid en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_madrid, "Europe/Madrid");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Africa/Ceuta"
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Ceuta") == 0)
	{
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Africa/Ceuta", temps_utc);

		//
		time_t heure_a_ceuta = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Ceuta");

		//L'heure et la date de Ceuta en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_ceuta, "Africa/Ceuta");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Atlantic/Canary"
	else if(strcmp(nom_du_fuseau_horaire,"Atlantic/Canary") == 0)
	{
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Atlantic/Canary", temps_utc);

		//
		time_t heure_aux_iles_canaries = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Atlantic/Canary");

		//L'heure et la date des îles Canaries en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_aux_iles_canaries, "Atlantic/Canary");
	}

	/* Principauté de Monaco */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Monaco"...
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

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Luxembourg"...
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

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Brussels"...
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

	/* Royaume de Danemark */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Copenhagen"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Copenhagen") == 0)
	{
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Copenhagen", temps_utc);

		//
		time_t heure_a_copenhague = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Copenhagen");

		//L'heure et la date de Copenhague en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_copenhague, "Europe/Copenhagen");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Atlantic/Faroe"...
	else if(strcmp(nom_du_fuseau_horaire,"Atlantic/Faroe") == 0)
	{
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Atlantic/Faroe", temps_utc);

		//
		time_t heure_aux_iles_feroes = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Atlantic/Faroe");

		//L'heure et la date des Iles Féroé en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_aux_iles_feroes, "Atlantic/Faroe");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Scoresbysund"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Scoresbysund") == 0)
	{
		//
		application_du_changement_d_heure_pour_l_europe_continentale("America/Scoresbysund", temps_utc);

		//
		time_t heure_a_scoresbysund = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Scoresbysund");

		//L'heure et la date de Scoresbysund en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_scoresbysund, "America/Scoresbysund");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Godthab"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Godthab") == 0)
	{
		//
		application_du_changement_d_heure_pour_l_europe_continentale("America/Godthab", temps_utc);

		//
		time_t heure_a_godthab = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Godthab");

		//L'heure et la date de Godthab en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_godthab, "America/Godthab");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Thule"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Thule") == 0)
	{
		//
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Thule", temps_utc);

		//
		time_t heure_a_thule = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Thule");

		//L'heure et la date de Thule en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_thule, "America/Thule");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Danmarkshavn"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Danmarkshavn") == 0)
	{
		//
		time_t heure_a_danmarkshavn = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Danmarkshavn");

		//L'heure et la date de Danmarkshavn en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_danmarkshavn, "America/Danmarkshavn");
	}

	/* Royaume de Suède */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Stockholm"...
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

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Oslo"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Oslo") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Oslo", temps_utc);

                //
                time_t heure_a_oslo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Oslo");

                //L'heure et la date de Oslo en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_oslo, "Europe/Oslo");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Arctic/Longyearbyen"...
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

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Atlantic/Reykjavik"...
        else if(strcmp(nom_du_fuseau_horaire,"Atlantic/Reykjavik") == 0)
        {
                //
                time_t heure_a_reykjavik = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Atlantic/Reykjavik");

                //L'heure et la date de Reykjavik en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_reykjavik, "Atlantic/Reykjavik");
        }

	/* République de Lituanie */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Vilnius"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Vilnius") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Vilnius", temps_utc);

                //
                time_t heure_a_vilnius = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Vilnius");

                //L'heure et la date de Vilnius en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_vilnius, "Europe/Vilnius");
        }

	/* République de Lettonie */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Riga"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Riga") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Riga", temps_utc);

                //
                time_t heure_a_riga = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Riga");

                //L'heure et la date de Riga en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_riga, "Europe/Riga");
        }

	/* République d’Estonie */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Tallinn"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Tallinn") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Tallinn", temps_utc);

                //
                time_t heure_a_tallinn = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Tallinn");

                //L'heure et la date de Tallinn en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_tallinn, "Europe/Tallinn");
        }

	/* République de Pologne */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Warsaw"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Warsaw") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Warsaw", temps_utc);

                //
                time_t heure_a_varsovie = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Warsaw");

                //L'heure et la date de Varsovie en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_varsovie, "Europe/Warsaw");
        }

	/* République hellénique */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Athens"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Athens") == 0)
	{
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Athens", temps_utc);

		//Calcul de l'heure et de la date à Athènes et stockage de celui-ci dans la variable heure_d_athenes
		time_t heure_d_athenes = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Athens");

		//L'heure et la date d'Athènes en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_d_athenes, "Europe/Athens");
	}

	/* République de Turquie */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Istanbul"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Istanbul") == 0)
	{
		//Calcul de l'heure et de la date à Istanbul et stockage de celui-ci dans la variable heure_a_istanbul
		time_t heure_a_istanbul = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Istanbul");

		//L'heure et la date d'Istanbul en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_istanbul, "Europe/Istanbul");
	}

	/* République d'Arménie */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Yerevan"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Yerevan") == 0)
	{
		//Calcul de l'heure et de la date à Erevan et stockage de celui-ci dans la variable heure_erevan
		time_t heure_erevan = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Yerevan");

		//L'heure et la date de Erevan en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_erevan, "Asia/Yerevan");
	}

	/* Géorgie */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Tbilisi"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Tbilisi") == 0)
	{
		//Calcul de l'heure et de la date à Tbilisi et stockage de celui-ci dans la variable heure_a_tbilissi
		time_t heure_a_tbilissi = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Tbilisi");
		
		//L'heure et la date de Tbilissi en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_tbilissi, "Asia/Tbilisi");
	}

	/* République d'Azerbaïdjan */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Baku"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Baku") == 0)
        {
		//Calcul de l'heure et de la date à Bakou et stockage de celui-ci dans la variable heure_a_bakou
		time_t heure_a_bakou = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Baku");

		//L'heure et la date de Bakou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_bakou, "Asia/Baku");
	}

	/* République islamique d'Iran */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Tehran"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Tehran") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Iran
		application_du_changement_d_heure_pour_l_iran(temps_utc);

		//Calcul de l'heure et de la date à Téhéran et stockage de celui-ci dans la variable heure_a_teheran
		time_t heure_a_teheran = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Tehran");

		//L'heure et la date de Téhéran en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_teheran, "Asia/Tehran");
	}

	/* Antarctique */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Antarctica/Casey"...
	else if(strcmp(nom_du_fuseau_horaire,"Antarctica/Casey") == 0)
	{
		//Calcul de l'heure et de la date à la base antarctique de Casey et stockage de celui-ci dans la variable heure_pour_la_base_antarctique_de_casey
		time_t heure_pour_la_base_antarctique_de_casey = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/Casey");

		//L'heure et la date de la date à la base antarctique de Casey en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_pour_la_base_antarctique_de_casey, "Antarctica/Casey");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Antarctica/Davis"...
	else if(strcmp(nom_du_fuseau_horaire,"Antarctica/Davis") == 0)
	{
		//Calcul de l'heure et de la date à la base antarctique de Davis et stockage de celui-ci dans la variable heure_pour_la_base_antarctique_de_davis
		time_t heure_pour_la_base_antarctique_de_davis = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/Davis");

		//L'heure et la date de la date à la base antarctique de Davis en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_pour_la_base_antarctique_de_davis, "Antarctica/Davis");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Antarctica/DumontDUrville"...
	else if(strcmp(nom_du_fuseau_horaire,"Antarctica/DumontDUrville") == 0)
	{
		//Calcul de l'heure et de la date à la base antarctique de DumontDUrville et stockage de celui-ci dans la variable heure_pour_la_base_antarctique_de_dumontdurville
		time_t heure_pour_la_base_antarctique_de_dumontdurville = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/DumontDUrville");

		//L'heure et la date de la date à la base antarctique de DumontDUrville en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_pour_la_base_antarctique_de_dumontdurville, "Antarctica/DumontDUrville");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Antarctica/Mawson"...
	else if(strcmp(nom_du_fuseau_horaire,"Antarctica/Mawson") == 0)
	{
		//Calcul de l'heure et de la date à la base antarctique de Mawson et stockage de celui-ci dans la variable heure_pour_la_base_antarctique_de_mawson
		time_t heure_pour_la_base_antarctique_de_mawson = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/Mawson");

		//L'heure et la date de la date à la base antarctique de Mawson en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_pour_la_base_antarctique_de_mawson, "Antarctica/Mawson");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Antarctica/McMurdo"...
	else if(strcmp(nom_du_fuseau_horaire,"Antarctica/McMurdo") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour la Nouvelle-Zélande
		application_du_changement_d_heure_pour_la_nouvelle_zelande("Antarctica/McMurdo", temps_utc);

		//Calcul de l'heure et de la date à la base antarctique de McMurdo et stockage de celui-ci dans la variable heure_pour_la_base_antarctique_de_mcmurdo
		time_t heure_pour_la_base_antarctique_de_mcmurdo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/McMurdo");

		//L'heure et la date de la date à la base antarctique de McMurdo en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_pour_la_base_antarctique_de_mcmurdo, "Antarctica/McMurdo");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Antarctica/Palmer"...
	else if(strcmp(nom_du_fuseau_horaire,"Antarctica/Palmer") == 0)
	{
		//Calcul de l'heure et de la date à la base antarctique de Palmer et stockage de celui-ci dans la variable heure_pour_la_base_antarctique_de_palmer
		time_t heure_pour_la_base_antarctique_de_palmer = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/Palmer");

		//L'heure et la date de la date à la base antarctique de Palmer en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_pour_la_base_antarctique_de_palmer, "Antarctica/Palmer");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Antarctica/Rothera"...
	else if(strcmp(nom_du_fuseau_horaire,"Antarctica/Rothera") == 0)
	{
		//Calcul de l'heure et de la date à la base antarctique de Rothera et stockage de celui-ci dans la variable heure_pour_la_base_antarctique_de_rothera
		time_t heure_pour_la_base_antarctique_de_rothera = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/Rothera");

		//L'heure et la date de la date à la base antarctique de Rothera en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_pour_la_base_antarctique_de_rothera, "Antarctica/Rothera");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Antarctica/Syowa"...
	else if(strcmp(nom_du_fuseau_horaire,"Antarctica/Syowa") == 0)
	{
		//Calcul de l'heure et de la date à la base antarctique de Syowa et stockage de celui-ci dans la variable heure_pour_la_base_antarctique_de_syowa
		time_t heure_pour_la_base_antarctique_de_syowa = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/Syowa");

		//L'heure et la date de la date à la base antarctique de Syowa en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_pour_la_base_antarctique_de_syowa, "Antarctica/Syowa");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Antarctica/Vostok"...
	else if(strcmp(nom_du_fuseau_horaire,"Antarctica/Vostok") == 0)
	{
		//Calcul de l'heure et de la date à la base antarctique de Vostok et stockage de celui-ci dans la variable heure_pour_la_base_antarctique_de_vostok
		time_t heure_pour_la_base_antarctique_de_vostok = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/Vostok");

		//L'heure et la date de la date à la base antarctique de Vostok en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_pour_la_base_antarctique_de_vostok, "Antarctica/Vostok");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Antarctica/Troll"...
	else if(strcmp(nom_du_fuseau_horaire,"Antarctica/Troll") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour la base antarctique de Troll
		application_du_changement_d_heure_pour_la_base_antarctique_de_troll(temps_utc);

		//Calcul de l'heure et de la date à la base antarctique de Troll et stockage de celui-ci dans la variable heure_pour_la_base_antarctique_de_troll
		time_t heure_pour_la_base_antarctique_de_troll = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/Troll");

		//L'heure et la date de la date à la base antarctique de Troll en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_pour_la_base_antarctique_de_troll, "Antarctica/Troll");
	}

	/* République de Cuba */
	
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Havana"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Havana") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Havana", temps_utc);

		//Calcul de l'heure et de la date à La Havane et stockage de celui-ci dans la variable heure_a_la_havane
		time_t heure_a_la_havane = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Havana");

		//L'heure et la date de La Havane en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_la_havane, "America/Havana");
	}	

	/* États-Unis d'Amérique */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Los_Angeles"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Los_Angeles") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Los_Angeles", temps_utc);

		//Calcul de l'heure et de la date à Los Angeles et stockage de celui-ci dans la variable heure_los_angeles
		time_t heure_los_angeles = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Los_Angeles");

		//L'heure et la date de Los Angeles en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_los_angeles, "America/Los Angeles");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/New_York"...
	else if(strcmp(nom_du_fuseau_horaire,"America/New_York") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord   
                application_du_changement_d_heure_pour_l_amerique_du_nord("America/New_York", temps_utc);

		//Calcul de l'heure et de la date à New York et stockage de celui-ci dans la variable heure_de_nyc
                time_t heure_de_nyc = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/New_York");

		//L'heure et la date de New York City en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_nyc, "America/New_York");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Phoenix"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Phoenix") == 0)
	{
		//Calcul de l'heure et de la date à Phoenix et stockage de celui-ci dans la variable heure_de_phoenix
                time_t heure_de_phoenix = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Phoenix");

		//L'heure et la date de Phoenix en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_phoenix, "America/Phoenix");
	}

	/* Dominion du Canada */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Toronto"...
        else if(strcmp(nom_du_fuseau_horaire,"America/Toronto") == 0)
        {
                //Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
                application_du_changement_d_heure_pour_l_amerique_du_nord("America/Toronto", temps_utc);

                //Calcul de l'heure et de la date à Ottawa et stockage de celui-ci dans la variable heure_d_ottawa
                time_t heure_de_toronto = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Toronto");

                //L'heure et la date de Ottawa en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_de_toronto, "America/Toronto");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Atikokan"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Atikokan") == 0)
	{
		//Calcul de l'heure et de la date à Atikokan et stockage de celui-ci dans la variable heure_d_atikokan
                time_t heure_d_atikokan = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Atikokan");

                //L'heure et la date d'Atikokan en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_d_atikokan, "America/Atikokan");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Pangnirtung"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Pangnirtung") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Pangnirtung", temps_utc);

		//Calcul de l'heure et de la date à Pangnirtung et stockage de celui-ci dans la variable heure_de_pangnirtung
		time_t heure_de_pangnirtung = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Pangnirtung");

		//L'heure et la date de Pangnirtung en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_pangnirtung, "America/Pangnirtung");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Thunder_Bay"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Thunder_Bay") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Thunder_Bay", temps_utc);

		//Calcul de l'heure et de la date à Thunder_Bay et stockage de celui-ci dans la variable heure_de_thunder_bay
		time_t heure_de_thunder_bay = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Thunder_Bay");

		//L'heure et la date de Thunder_Bay en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_thunder_bay, "America/Thunder_Bay");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Nipigon"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Nipigon") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Nipigon", temps_utc);

		//Calcul de l'heure et de la date à Nipigon et stockage de celui-ci dans la variable heure_de_nipigon
		time_t heure_de_nipigon = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Nipigon");

		//L'heure et la date de Nipigon en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_nipigon, "America/Nipigon");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Iqaluit"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Iqaluit") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Iqaluit", temps_utc);

		//Calcul de l'heure et de la date à Iqaluit et stockage de celui-ci dans la variable heure_d_iqaluit
		time_t heure_d_iqaluit = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Iqaluit");

		//L'heure et la date d'Iqaluit en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_d_iqaluit, "America/Iqaluit");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Winnipeg"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Winnipeg") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Winnipeg", temps_utc);

		//Calcul de l'heure et de la date à Winnipeg et stockage de celui-ci dans la variable heure_de_winnipeg
		time_t heure_de_winnipeg = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Winnipeg");

		//L'heure et la date de Winnipeg en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_winnipeg, "America/Winnipeg");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Swift_Current"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Swift_Current") == 0)
	{
		//Calcul de l'heure et de la date à Swift Current et stockage de celui-ci dans la variable heure_de_swift_current
		time_t heure_de_swift_current = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Swift_Current");

		//L'heure et la date de Swift Current en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_swift_current, "America/Swift_Current");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Resolute"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Resolute") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Resolute", temps_utc);

		//Calcul de l'heure et de la date à Resolute et stockage de celui-ci dans la variable heure_de_resolute
		time_t heure_de_resolute = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Resolute");

		//L'heure et la date de Resolute en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_resolute, "America/Resolute");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Regina"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Regina") == 0)
	{
		//Calcul de l'heure et de la date à Regina et stockage de celui-ci dans la variable heure_de_regina
		time_t heure_de_regina = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Regina");

		//L'heure et la date de Regina en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_regina, "America/Regina");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Rankin_Inlet"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Rankin_Inlet") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Rankin_Inlet", temps_utc);

		//Calcul de l'heure et de la date à Rankin Inlet et stockage de celui-ci dans la variable heure_de_rankin_inlet
		time_t heure_de_rankin_inlet = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Rankin_Inlet");

		//L'heure et la date de Rankin Inlet en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_rankin_inlet, "America/Rankin_Inlet");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Rainy_River"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Rainy_River") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Rainy_River", temps_utc);

		//Calcul de l'heure et de la date à Rainy River et stockage de celui-ci dans la variable heure_de_rainy_river
		time_t heure_de_rainy_river = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Rainy_River");

		//L'heure et la date de Rainy river en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_rainy_river, "America/Rainy_River");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Whitehorse"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Whitehorse") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Whitehorse", temps_utc);

		//Calcul de l'heure et de la date à Whitehorse et stockage de celui-ci dans la variable heure_de_whitehorse
		time_t heure_de_whitehorse = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Whitehorse");

		//L'heure et la date de Whitehorse en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_whitehorse, "America/Whitehorse");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Vancouver"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Vancouver") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Vancouver", temps_utc);

		//Calcul de l'heure et de la date à Vancouver et stockage de celui-ci dans la variable heure_de_vancouver
		time_t heure_de_vancouver = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Vancouver");

		//L'heure et la date de Vancouver en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_vancouver, "America/Vancouver");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Dawson"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Dawson") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Dawson", temps_utc);

		//Calcul de l'heure et de la date à Dawson et stockage de celui-ci dans la variable heure_de_dawson
		time_t heure_de_dawson = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Dawson");

		//L'heure et la date de Dawson en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_dawson, "America/Dawson");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/St_Johns"...
	else if(strcmp(nom_du_fuseau_horaire,"America/St_Johns") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/St_Johns", temps_utc);

		//Calcul de l'heure et de la date à St Johns et stockage de celui-ci dans la variable heure_de_st_johns
		time_t heure_de_st_johns = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/St_Johns");

		//L'heure et la date de St Johns en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_st_johns, "America/St_Johns");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Blanc-Sablon"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Blanc-Sablon") == 0)
	{
		//Calcul de l'heure et de la date à Blanc Sablon et stockage de celui-ci dans la variable heure_de_blanc_sablon
		time_t heure_de_blanc_sablon = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Blanc-Sablon");

		//L'heure et la date de Blanc Sablon en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_blanc_sablon, "America/Blanc-Sablon");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Moncton"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Moncton") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Moncton", temps_utc);

		//Calcul de l'heure et de la date à Moncton et stockage de celui-ci dans la variable heure_de_moncton
		time_t heure_de_moncton = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Moncton");

		//L'heure et la date de Moncton en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_moncton, "America/Moncton");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Halifax"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Halifax") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Halifax", temps_utc);

		//Calcul de l'heure et de la date à Halifax et stockage de celui-ci dans la variable heure_d_halifax
		time_t heure_d_halifax = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Halifax");

		//L'heure et la date de Halifax en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_d_halifax, "America/Halifax");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Goose_Bay"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Goose_Bay") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Goose_Bay", temps_utc);

		//Calcul de l'heure et de la date à Goose Bay et stockage de celui-ci dans la variable heure_de_goose_bay
		time_t heure_de_goose_bay = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Goose_Bay");

		//L'heure et la date de Goose Bay en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_goose_bay, "America/Goose_Bay");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Glace_Bay"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Glace_Bay") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Glace_Bay", temps_utc);

		//Calcul de l'heure et de la date à Glace Bay et stockage de celui-ci dans la variable heure_de_glace_bay
		time_t heure_de_glace_bay = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Glace_Bay");

		//L'heure et la date de Glace Bay en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_glace_bay, "America/Glace_Bay");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Inuvik"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Inuvik") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Inuvik", temps_utc);

		//Calcul de l'heure et de la date à Inuvik et stockage de celui-ci dans la variable heure_d_inuvik
		time_t heure_d_inuvik = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Inuvik");

		//L'heure et la date d'Inuvik en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_d_inuvik, "America/Inuvik");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Fort_Nelson"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Fort_Nelson") == 0)
	{
		//Calcul de l'heure et de la date à Fort Nelson et stockage de celui-ci dans la variable heure_de_fort_nelson
		time_t heure_de_fort_nelson = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Fort_Nelson");

		//L'heure et la date de Fort_Nelson en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_fort_nelson, "America/Fort_Nelson");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Edmonton"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Edmonton") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Edmonton", temps_utc);

		//Calcul de l'heure et de la date à Edmonton et stockage de celui-ci dans la variable heure_d_edmonton
		time_t heure_d_edmonton = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Edmonton");

		//L'heure et la date d'Edmonton en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_d_edmonton, "America/Edmonton");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Dawson_Creek"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Dawson_Creek") == 0)
	{
		//Calcul de l'heure et de la date à Dawson Creek et stockage de celui-ci dans la variable heure_de_dawson_creek
		time_t heure_de_dawson_creek = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Dawson_Creek");

		//L'heure et la date de Dawson Creek en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_dawson_creek, "America/Dawson_Creek");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Creston"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Creston") == 0)
	{
		//Calcul de l'heure et de la date à Creston et stockage de celui-ci dans la variable heure_de_creston
		time_t heure_de_creston = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Creston");

		//L'heure et la date de Creston en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_creston, "America/Creston");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Cambridge_Bay"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Cambridge_Bay") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Cambridge_Bay", temps_utc);

		//Calcul de l'heure et de la date à Cambridge Bay et stockage de celui-ci dans la variable heure_de_cambridge_bay
		time_t heure_de_cambridge_bay = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Cambridge_Bay");

		//L'heure et la date de Cambridge Bay en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_cambridge_bay, "America/Cambridge_Bay");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Yellowknife"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Yellowknife") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Amérique du Nord
		application_du_changement_d_heure_pour_l_amerique_du_nord("America/Yellowknife", temps_utc);

		//Calcul de l'heure et de la date à Yellowknife et stockage de celui-ci dans la variable heure_d_yellowknife
		time_t heure_d_yellowknife = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Yellowknife");

		//L'heure et la date de Yellowknife en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_d_yellowknife, "America/Yellowknife");
	}

	/* Royaume-Uni de Grande-Bretagne et d'Irlande du Nord */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/London"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/London") == 0)
        {
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour la Grande-Bretagne
		application_du_changement_d_heure_pour_la_grande_bretagne("Europe/London", temps_utc);

		//Calcul de l'heure et de la date à Londres et stockage de celui-ci dans la variable heure_de_londres
                time_t heure_de_londres = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/London");

		//L'heure et la date de Londres en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_londres, "Europe/London");
        }

	/* République de Moldavie */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Chisinau"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Chisinau") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Chisinau", temps_utc);

                //Calcul de l'heure et de la date à Chisinau et stockage de celui-ci dans la variable heure_a_chisinau
                time_t heure_a_chisinau = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Chisinau");

                //L'heure et la date de Chisinau en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_chisinau, "Europe/Chisinau");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Tiraspol"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Tiraspol") == 0)
	{
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Tiraspol", temps_utc);

		//
		time_t heure_a_tiraspol = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Tiraspol");

		//L'heure et la date de Tiraspol en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_tiraspol, "Europe/Tiraspol");
	}

	/* République de Biélorussie */
	
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Minsk"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Minsk") == 0)
        {
                //Calcul de l'heure et de la date à Minsk et stockage de celui-ci dans la variable heure_a_minsk
                time_t heure_a_minsk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Minsk");;

                //L'heure et la date de Minsk en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_minsk, "Europe/Minsk");
        }

	/* Ukraine */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Kiev"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Kiev") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Kiev", temps_utc);

                //Calcul de l'heure et de la date à Kiev et stockage de celui-ci dans la variable heure_a_kiev
                time_t heure_a_kiev = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Kiev");

                //L'heure et la date de Kiev en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_kiev, "Europe/Kiev");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Uzhgorod"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Uzhgorod") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Uzhgorod", temps_utc);

                //Calcul de l'heure et de la date à Uzhgorod et stockage de celui-ci dans la variable heure_a_uzhgorod
                time_t heure_a_uzhgorod = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Uzhgorod");

                //L'heure et la date de Uzhgorod en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_uzhgorod, "Europe/Uzhgorod");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Zaporozhye"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Zaporozhye") == 0)
        {
		//
		application_du_changement_d_heure_pour_l_europe_continentale("Europe/Zaporozhye", temps_utc);

                //Calcul de l'heure et de la date à Zaporozhye et stockage de celui-ci dans la variable heure_a_zaporozhye
                time_t heure_a_zaporozhye = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Zaporozhye");

                //L'heure et la date de Zaporozhye en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_zaporozhye, "Europe/Zaporozhye");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Simferopol"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Simferopol") == 0)
	{
		//
		time_t heure_a_simferopol = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Simferopol");

		//L'heure et la date de Simferopol en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_simferopol, "Europe/Simferopol");
	}
	
	/* Fédération de Russie */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Moscow"...
        else if(strcmp(nom_du_fuseau_horaire,"Europe/Moscow") == 0)
        {
		//Calcul de l'heure et de la date à Moscou et stockage de celui-ci dans la variable heure_moscou
                time_t heure_moscou = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Moscow");

		//L'heure et la date de Moscou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_moscou, "Europe/Moscow");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Vladivostok"...
        else if(strcmp(nom_du_fuseau_horaire,"Asia/Vladivostok") == 0)
        {
		//Calcul de l'heure et de la date à Vladivostok et stockage de celui-ci dans la variable heure_vladivostok
                time_t heure_vladivostok = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Vladivostok");

		//L'heure et la date de Vladivostok en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_vladivostok, "Asia/Vladivostok");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Kaliningrad"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Kaliningrad") == 0)
	{
		//Calcul de l'heure et de la date à Kaliningrad et stockage de celui-ci dans la variable heure_kaliningrad
		time_t heure_kaliningrad = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Kaliningrad");

		//L'heure et la date de Kaliningrad en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_kaliningrad, "Europe/Kaliningrad");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Samara"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Samara") == 0)
	{
		//Calcul de l'heure et de la date à Samara et stockage de celui-ci dans la variable heure_samara
		time_t heure_samara = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Samara");

		//L'heure et la date de Samara en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_samara, "Europe/Samara");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Volgograd"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Volgograd") == 0)
	{
		//Calcul de l'heure et de la date à Volgograd et stockage de celui-ci dans la variable heure_volgograd
		time_t heure_volgograd = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Volgograd");

		//L'heure et la date de Volgograd en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_volgograd, "Europe/Volgograd");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Saratov"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Saratov") == 0)
	{
		//Calcul de l'heure et de la date à Saratov et stockage de celui-ci dans la variable heure_saratov
		time_t heure_saratov = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Saratov");

		//L'heure et la date de Saratov en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_saratov, "Europe/Saratov");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Ulyanovsk"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Ulyanovsk") == 0)
	{
		//Calcul de l'heure et de la date à Oulianovsk et stockage de celui-ci dans la variable heure_oulianovsk
		time_t heure_oulianovsk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Ulyanovsk");

		//L'heure et la date d'Oulianovsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_oulianovsk, "Europe/Ulyanovsk");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Europe/Astrakhan"...
	else if(strcmp(nom_du_fuseau_horaire,"Europe/Astrakhan") == 0)
	{
		//Calcul de l'heure et de la date à Astrakhan et stockage de celui-ci dans la variable heure_astrakhan
		time_t heure_astrakhan = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Europe/Astrakhan");

		//L'heure et la date d'Astrakhan en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_astrakhan, "Europe/Astrakhan");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Anadyr"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Anadyr") == 0)
	{
		//Calcul de l'heure et de la date à Anadyr et stockage de celui-ci dans la variable heure_anadyr
		time_t heure_anadyr = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Anadyr");

		//L'heure et la date d'Anadyr en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_anadyr, "Asia/Anadyr");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Sakhalin"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Sakhalin") == 0)
	{
		//Calcul de l'heure et de la date à Sakhalin et stockage de celui-ci dans la variable heure_sakhalin
		time_t heure_sakhalin = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Sakhalin");

		//L'heure et la date de Sakhalin en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_sakhalin, "Asia/Sakhalin");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Omsk"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Omsk") == 0)
	{
		//Calcul de l'heure et de la date à Omsk et stockage de celui-ci dans la variable heure_omsk
		time_t heure_omsk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Omsk");

		//L'heure et la date d'Omsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_omsk, "Asia/Omsk");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Chita"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Chita") == 0)
	{
		//Calcul de l'heure et de la date à Omsk et stockage de celui-ci dans la variable heure_tchita
		time_t heure_tchita = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Chita");

		//L'heure et la date de Tchita en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_tchita, "Asia/Chita");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Tomsk"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Tomsk") == 0)
	{
		//Calcul de l'heure et de la date à Tomsk et stockage de celui-ci dans la variable heure_tomsk
		time_t heure_tomsk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Tomsk");

		//L'heure et la date de Tomsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_tomsk, "Asia/Tomsk");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Barnaul"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Barnaul") == 0)
	{
		//Calcul de l'heure et de la date à Barnaoul et stockage de celui-ci dans la variable heure_barnaoul
		time_t heure_barnaoul = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Barnaul");

		//L'heure et la date de Barnaoul en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_barnaoul, "Asia/Barnaul");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Magadan"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Magadan") == 0)
	{
		//Calcul de l'heure et de la date à Magadan et stockage de celui-ci dans la variable heure_magadan
		time_t heure_magadan = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Magadan");

		//L'heure et la date de Magadan en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_magadan, "Asia/Magadan");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Yekaterinburg"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Yekaterinburg") == 0)
	{
		//Calcul de l'heure et de la date à Iekaterinbourg et stockage de celui-ci dans la variable heure_iekaterinbourg
		time_t heure_iekaterinbourg = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Yekaterinburg");

		//L'heure et la date de Iekaterinbourg en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_iekaterinbourg, "Asia/Yekaterinburg");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Yakutsk"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Yakutsk") == 0)
	{
		//Calcul de l'heure et de la date à Yakoutsk et stockage de celui-ci dans la variable heure_yakoutsk
		time_t heure_yakoutsk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Yakutsk");

		//L'heure et la date de Yakoutsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_yakoutsk, "Asia/Yakutsk");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Irkutsk"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Irkutsk") == 0)
	{
		//Calcul de l'heure et de la date à Irkoutsk et stockage de celui-ci dans la variable heure_irkoutsk
		time_t heure_irkoutsk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Irkutsk");

		//L'heure et la date de Irkoutsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_irkoutsk, "Asia/Irkutsk");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Khandyga"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Khandyga") == 0)
	{
		//Calcul de l'heure et de la date à Khandyga et stockage de celui-ci dans la variable heure_khandyga
		time_t heure_khandyga = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Khandyga");

		//L'heure et la date de Khandyga en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_khandyga, "Asia/Khandyga");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Novokuznetsk"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Novokuznetsk") == 0)
	{
		//Calcul de l'heure et de la date à Novokuznetsk et stockage de celui-ci dans la variable heure_novokouznetsk
		time_t heure_novokouznetsk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Novokuznetsk");

		//L'heure et la date de Novokuznetsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_novokouznetsk, "Asia/Novokuznetsk");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Novosibirsk"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Novosibirsk") == 0)
	{
		//Calcul de l'heure et de la date à Novosibirsk et stockage de celui-ci dans la variable heure_nobossibirsk
		time_t heure_nobossibirsk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Novosibirsk");

		//L'heure et la date de Novosibirsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_nobossibirsk, "Asia/Novosibirsk");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Krasnoyarsk"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Krasnoyarsk") == 0)
	{
		//Calcul de l'heure et de la date à Krasnoyarsk et stockage de celui-ci dans la variable heure_krasnoyarsk
		time_t heure_krasnoyarsk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Krasnoyarsk");

		//L'heure et la date de Krasnoyarsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_krasnoyarsk, "Asia/Krasnoyarsk");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Ust-Nera"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Ust-Nera") == 0)
	{
		//Calcul de l'heure et de la date à Oust-Nera et stockage de celui-ci dans la variable heure_oust_nera
                time_t heure_oust_nera = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Ust-Nera");

		//L'heure et la date de Oust-Nera en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_oust_nera, "Asia/Ust-Nera");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Srednekolymsk"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Srednekolymsk") == 0)
	{
		//Calcul de l'heure et de la date à Srednekolymsk et stockage de celui-ci dans la variable heure_srednekolymsk
		time_t heure_srednekolymsk = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Srednekolymsk");

		//L'heure et la date de Srednekolymsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_srednekolymsk, "Asia/Srednekolymsk");
	}

	/* Nouvelle-Zélande */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Pacific/Auckland"...
	else if(strcmp(nom_du_fuseau_horaire,"Pacific/Auckland") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour la Nouvelle-Zélande
        	application_du_changement_d_heure_pour_la_nouvelle_zelande("Pacific/Auckland", temps_utc);

		//Calcul de l'heure et de la date à Auckland et stockage de celui-ci dans la variable heure_a_auckland
                time_t heure_a_auckland = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Auckland");

		//L'heure et la date d'Auckland en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_auckland, "Pacific/Auckland");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Pacific/Chatham"...
	else if(strcmp(nom_du_fuseau_horaire,"Pacific/Chatham") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour la Nouvelle-Zélande
		application_du_changement_d_heure_pour_la_nouvelle_zelande("Pacific/Chatham", temps_utc);

		//Calcul de l'heure et de la date à l'île Chatham et stockage de celui-ci dans la variable heure_a_chatham
		time_t heure_a_chatham = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Chatham");

		//L'heure et la date de l'île Chatham en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_chatham, "Pacific/Chatham");
	}

	/* État des Tuvalu */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Pacific/Funafuti"...
	else if(strcmp(nom_du_fuseau_horaire,"Pacific/Funafuti") == 0)
	{
		//Calcul de l'heure et de la date aux Tuvalu et stockage de celui-ci dans la variable heure_a_funafuti
		time_t heure_a_funafuti = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Funafuti");

		//L'heure et la date des Tuvalu en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_funafuti, "Pacific/Funafuti");
	}

	/* République des Fidji */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Pacific/Fiji"...
	else if(strcmp(nom_du_fuseau_horaire,"Pacific/Fiji") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour les Fidji
		application_du_changement_d_heure_pour_les_fidji(temps_utc);

		//Calcul de l'heure et de la date aux Fidji et stockage de celui-ci dans la variable heure_aux_fidji
		time_t heure_aux_fidji = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Fiji");

		//L'heure et la date des Fidji en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_aux_fidji, "Pacific/Fiji");
	}

	/* Royaume de Tonga */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Pacific/Tongatapu"...
	else if(strcmp(nom_du_fuseau_horaire,"Pacific/Tongatapu") == 0)
	{
		//Calcul de l'heure et de la date aux Tonga et stockage de celui-ci dans la variable heure_a_togatapu
		time_t heure_a_togatapu = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Tongatapu");

		//L'heure et la date des Tonga en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_togatapu, "Pacific/Tongatapu");
	}

	/* État indépendant des Samoa */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Pacific/Apia"...
	else if(strcmp(nom_du_fuseau_horaire,"Pacific/Apia") == 0)
	{
		//Calcul de l'heure et de la date aux Samoa et stockage de celui-ci dans la variable heure_a_apia
		time_t heure_a_apia = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Apia");

		//L'heure et la date des Samoa en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_apia, "Pacific/Apia");
	}

	/* Commonwealth d'Australie */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Australia/Sydney"...
        else if(strcmp(nom_du_fuseau_horaire,"Australia/Sydney") == 0)
        {
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Australie
		application_du_changement_d_heure_pour_l_australie("Australia/Sydney", temps_utc);

		//Calcul de l'heure et de la date à Sydney et stockage de celui-ci dans la variable heure_a_sydney
                time_t heure_a_sydney = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Sydney");

		//L'heure et la date de Sydney en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_sydney, "Sydney");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Australia/Adelaide"...
	else if(strcmp(nom_du_fuseau_horaire,"Australia/Adelaide") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Australie 
		application_du_changement_d_heure_pour_l_australie("Australia/Adelaide", temps_utc);

		//Calcul de l'heure et de la date à Adelaide et stockage de celui-ci dans la variable heure_a_adelaide
		time_t heure_a_adelaide = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Adelaide");

		//L'heure et la date d'Adelaide en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_adelaide, "Australia/Adelaide");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Australia/Broken_Hill"...
	else if(strcmp(nom_du_fuseau_horaire,"Australia/Broken_Hill") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Australie
		application_du_changement_d_heure_pour_l_australie("Australia/Broken_Hill", temps_utc);

		//Calcul de l'heure et de la date à Broken Hill et stockage de celui-ci dans la variable heure_a_broken_hill
		time_t heure_a_broken_hill = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Broken_Hill");

		//L'heure et la date de Broken Hill en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_broken_hill, "Australia/Broken_Hill");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Australia/Darwin"...
	else if(strcmp(nom_du_fuseau_horaire,"Australia/Darwin") == 0)
	{
		//Calcul de l'heure et de la date à Darwin et stockage de celui-ci dans la variable heure_a_darwin
		time_t heure_a_darwin = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Darwin");

		//L'heure et la date de Darwin en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_darwin, "Australia/Darwin");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Australia/Brisbane"...
	else if(strcmp(nom_du_fuseau_horaire,"Australia/Brisbane") == 0)
	{
		//Calcul de l'heure et de la date à Brisbane et stockage de celui-ci dans la variable heure_a_brisbane
		time_t heure_a_brisbane = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Brisbane");

		//L'heure et la date de Brisbane en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_brisbane, "Australia/Brisbane");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Australia/Currie"...
	else if(strcmp(nom_du_fuseau_horaire,"Australia/Currie") == 0)
	{
		//Calcul de l'heure et de la date à Currie et stockage de celui-ci dans la variable heure_a_curie
		time_t heure_a_currie = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Currie");

		//L'heure et la date de Currie en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_currie, "Australia/Currie");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Australia/Hobart"...
	else if(strcmp(nom_du_fuseau_horaire,"Australia/Hobart") == 0)
	{
		//Vérification de l'application de l'heure d'été ou non, puis application ou non de ce dernier, pour l'Australie
		application_du_changement_d_heure_pour_l_australie("Australia/Hobart", temps_utc);

		//Calcul de l'heure et de la date à Hobart et stockage de celui-ci dans la variable heure_a_hobart
		time_t heure_a_hobart = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Hobart");

		//L'heure et la date de Hobart en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_hobart, "Australia/Hobart");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Australia/Lindeman"...
	else if(strcmp(nom_du_fuseau_horaire,"Australia/Lindeman") == 0)
	{
		//Calcul de l'heure et de la date à Lindeman et stockage de celui-ci dans la variable heure_a_lindeman
		time_t heure_a_lindeman = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Lindeman");

		//L'heure et la date de Lindeman en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_lindeman, "Australia/Lindeman");
	}

	/* République du Chili */

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

	/* République d'Afrique du Sud */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Johannesburg"...
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Johannesburg") == 0)
        {
		//Calcul de l'heure et de la date à Johannesburg et stockage de celui-ci dans la variable heure_johannesburg
                time_t heure_johannesburg = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Johannesburg");

		//L'heure et la date de Johannesburg en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_johannesburg, "Johannesburg");
        }

	/* République du Soudan */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Khartoum"...
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Khartoum") == 0)
	{
		//Calcul de l'heure et de la date à Khartoum et stockage de celui-ci dans la variable heure_a_khartoum
		time_t heure_a_khartoum = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Khartoum");

		//L'heure et la date de Khartoum en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_khartoum, "Khartoum");
	}

	/* République du Soudan du Sud */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Djouba"...
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Juba") == 0)
	{
		//Calcul de l'heure et de la date à Djouba et stockage de celui-ci dans la variable heure_a_djouba
		time_t heure_a_djouba = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Juba");

		//L'heure et la date de Djouba en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_djouba, "Djouba");
	}

	/* République algérienne démocratique et populaire */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Alger"...
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Algiers") == 0)
	{
		//Calcul de l'heure et de la date à Alger et stockage de celui-ci dans la variable heure_a_alger
                time_t heure_a_alger = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Algiers");

		//L'heure et la date d'Alger en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_alger, "Africa/Algiers");
	}

	/* République du Kenya */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Nairobi"...
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Nairobi") == 0)
	{
		//Calcul de l'heure et de la date à Nairobi et stockage de celui-ci dans la variable heure_a_nairobi
                time_t heure_a_nairobi = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Nairobi");

		//L'heure et la date de Nairobi en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_nairobi, "Africa/Nairobi");
	}

	/* République unie de Tanzanie */

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
                time_t heure_au_guatemala = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Guatemala");

		//L'heure et la date au Guatemala en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_guatemala, "Guatemala");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Costa_Rica"...
	else if(strcmp(nom_du_fuseau_horaire,"Costa_Rica") == 0)
	{
		//Calcul de l'heure et de la date au Costa Rica et stockage de celui-ci dans la variable heure_au_costa_rica
                time_t heure_au_costa_rica = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Costa_Rica");

		//L'heure et la date du Costa Rica en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_costa_rica, "Costa Rica");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Tegucigalpa"...
	else if(strcmp(nom_du_fuseau_horaire,"Tegucigalpa") == 0)
	{
		//Calcul de l'heure et de la date à Tegucigalpa et stockage de celui-ci dans la variable heure_au_honduras
                time_t heure_au_honduras = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Tegucigalpa");

		//L'heure et la date du Honduras en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_honduras, "Tegucigalpa");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Panama"...
	else if(strcmp(nom_du_fuseau_horaire,"Panama") == 0)
	{
		//Calcul de l'heure et de la date au Panama et stockage de celui-ci dans la variable heure_au_panama
                time_t heure_au_panama = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Panama");

		//L'heure et la date au Panama en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_panama, "Panama");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "El_Salvador"...
	else if(strcmp(nom_du_fuseau_horaire,"El_Salvador") == 0)
	{
		//Calcul de l'heure et de la date au Panama et stockage de celui-ci dans la variable heure_d_el_salvador
                time_t heure_d_el_salvador = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/El_Salvador");

		//L'heure et la date a El Salvador en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_d_el_salvador, "El Salvador");
	}

	/* Belize */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale au "America/Belize"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Belize") == 0)
	{
		//Calcul de l'heure et de la date au Belize et stockage de celui-ci dans la variable heure_au_belize
                time_t heure_au_belize = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Belize");

		//L'heure et la date au Belize en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_belize, "America/Belize");
	}

	/* République de Colombie */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Bogota"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Bogota") == 0)
	{
		//Calcul de l'heure et de la date à Bogota et stockage de celui-ci dans la variable heure_a_bogota
                time_t heure_a_bogota = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Bogota");;

		//L'heure et la date de Bogota en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_bogota, "America/Bogota");
	}

	/* République bolivarienne du Venezuela */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Caracas"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Caracas") == 0)
	{
		//Calcul de l'heure et de la date à Caracas et stockage de celui-ci dans la variable heure_caracas
                time_t heure_a_caracas = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Caracas");

		//L'heure et la date de Caracas en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_caracas, "America/Caracas");
	}

	/* République de l'Équateur */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Guayaquil"...
	else if(strcmp(nom_du_fuseau_horaire,"America/Guayaquil") == 0)
	{
		//Calcul de l'heure et de la date à Guayaquil et stockage de celui-ci dans la variable heure_a_guayaquil
                time_t heure_a_guayaquil = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Guayaquil");

		//L'heure et la date de Guayaquil en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_guayaquil, "America/Guayaquil");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Pacific/Galapagos"...
	else if(strcmp(nom_du_fuseau_horaire,"Pacific/Galapagos") == 0)
	{
		//Calcul de l'heure et de la date à Galapagos et stockage de celui-ci dans la variable heure_a_galapagos
                time_t heure_a_galapagos = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Galapagos");

		//L'heure et la date de Galapagos en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_galapagos, "Pacific/Galapagos");
	}

	/* État plurinational de Bolivie */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/La_Paz"...
	else if(strcmp(nom_du_fuseau_horaire,"America/La_Paz") == 0)
	{
		//Calcul de l'heure et de la date à La Paz et stockage de celui-ci dans la variable heure_a_la_paz
                time_t heure_a_la_paz = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/La_Paz");

		//L'heure et la date de La Paz en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_la_paz, "America/La_Paz");
	}

	/* République de Madagascar */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Indian/Antananarivo"...
        else if(strcmp(nom_du_fuseau_horaire,"Indian/Antananarivo") == 0)
        {
		//Calcul de l'heure et de la date à Antananarivo et stockage de celui-ci dans la variable heure_antananarivo
                time_t heure_antananarivo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Indian/Antananarivo");;

		//L'heure et la date de Antananarivo en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_antananarivo, "Indian/Antananarivo");
        }

	/* République de Namibie */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Africa/Windhoek"...
        else if(strcmp(nom_du_fuseau_horaire,"Africa/Windhoek") == 0)
        {
		//Calcul de l'heure et de la date à Windhoek et stockage de celui-ci dans la variable heure_windhoek
                time_t heure_windhoek = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Windhoek");

		//L'heure et la date de Windhoek en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_windhoek, "Africa/Windhoek");
        }

	/* République du Pérou */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "America/Lima"...
        else if(strcmp(nom_du_fuseau_horaire,"America/Lima") == 0)
        {
		//Calcul de l'heure et de la date à Lima et stockage de celui-ci dans la variable heure_lima
                time_t heure_lima = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Lima");

		//L'heure et la date de Lima en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_lima, "America/Lima");
        }

	/* Royaume de Thaïlande */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Bangkok"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Bangkok") == 0)
	{
		//Calcul de l'heure et de la date à Bangkok et stockage de celui-ci dans la variable heure_a_bangkok
		time_t heure_a_bangkok = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Bangkok");

		//L'heure et la date de Bangkok Ville en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_bangkok, "Asia/Bangkok");
	}

	/* République socialiste du Viêt Nam */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Ho_Chi_Minh"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Ho_Chi_Minh") == 0)
	{
		//Calcul de l'heure et de la date à Hô Chi Minh Ville et stockage de celui-ci dans la variable heure_a_ho_chi_minh_ville
                time_t heure_a_ho_chi_minh_ville = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Ho_Chi_Minh");

		//L'heure et la date de Hô Chi Minh Ville en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_ho_chi_minh_ville, "Asia/Ho_Chi_Minh");
	}

	/* République populaire démocratique de Corée */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Pyongyang"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Pyongyang") == 0)
	{
		//Calcul de l'heure et de la date à Pyongyang et stockage de celui-ci dans la variable heure_pyongyang
                time_t heure_pyongyang = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Pyongyang");

		//L'heure et la date de Pyongyang en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_pyongyang, "Asia/Pyongyang");
	}

	/* République de Corée */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Seoul"...
        else if(strcmp(nom_du_fuseau_horaire,"Asia/Seoul") == 0)
        {
		//Calcul de l'heure et de la date à Seoul et stockage de celui-ci dans la variable heure_seoul
                time_t heure_seoul = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Seoul");

		//L'heure et la date de Seoul en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_seoul, "Seoul");
        }

	/* Empire du Japon */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Tokyo"...
        else if(strcmp(nom_du_fuseau_horaire,"Asia/Tokyo") == 0)
        {
		//Calcul de l'heure et de la date à Tokyo et stockage de celui-ci dans la variable heure_tokyo
                time_t heure_tokyo = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Tokyo");

		//L'heure et la date de Tokyo en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_tokyo, "Asia/Tokyo");
        }

	/* République populaire de Chine */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Shanghai"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Shanghai") == 0)
        {
		//Calcul de l'heure et de la date à Shanghai et stockage de celui-ci dans la variable heure_shanghai
                time_t heure_shanghai = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Shanghai");

		//L'heure et la date de Shanghai en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_shanghai, "Asia/Shanghai");
        }
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Urumqi"...
        else if(strcmp(nom_du_fuseau_horaire,"Asia/Urumqi") == 0)
        {
                //Calcul de l'heure et de la date à Urumqi et stockage de celui-ci dans la variable heure_a_urumqi
                time_t heure_a_urumqi = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Urumqi");

                //L'heure et la date d'Urumqi en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_urumqi, "Asia/Urumqi");
        }

	/* République des Philippines */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Manila"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Manila") == 0)
	{
		//Calcul de l'heure et de la date à Manille et stockage de celui-ci dans la variable heure_a_manille
                time_t heure_a_manille = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Manila");

		//L'heure et la date de Manille en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_manille, "Asia/Manila");
	}
	
	/* République arabe d'Égypte */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Africa/Cairo"...
	else if(strcmp(nom_du_fuseau_horaire,"Africa/Cairo") == 0)
	{
		//Calcul de l'heure et de la date au Caire et stockage de celui-ci dans la variable heure_le_caire
                time_t heure_le_caire = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Cairo");

		//L'heure et la date au Caire en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_le_caire, "Africa/Cairo");
	}

	/* République du Yémen */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Aden"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Aden") == 0)
	{
		//Calcul de l'heure et de la date à Aden et stockage de celui-ci dans la variable heure_a_aden
                time_t heure_a_aden = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Aden");

		//L'heure et la date à Aden en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_aden, "Asia/Aden");
	}

	/* État du Koweït */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Kuwait"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Kuwait") == 0)
	{
		//Calcul de l'heure et de la date au Koweit et stockage de celui-ci dans la variable heure_au_koweit
                time_t heure_au_koweit = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Kuwait");

		//L'heure et la date au Koweit en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_koweit, "Asia/Kuwait");
	}

	/* République démocratique fédérale d’Éthiopie */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Africa/Addis_Ababa"...
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

	/* Negara Brunei Darussalam */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Brunei"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Brunei") == 0)
	{
		//Calcul de l'heure et de la date à Brunei et stockage de celui-ci dans la variable heure_brunei
                time_t heure_brunei = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Brunei");

		//L'heure et la date à Brunei en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_brunei, "Asia/Brunei");
	}

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Erevan"...
	else if(strcmp(nom_du_fuseau_horaire,"Erevan") == 0)
	{
		//Calcul de l'heure et de la date à Erevan et stockage de celui-ci dans la variable heure_erevan
                time_t heure_erevan = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Yerevan");

		//L'heure et la date à Erevan en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_erevan, "Erevan");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Tbilissi"...
	else if(strcmp(nom_du_fuseau_horaire,"Tbilissi") == 0)
	{
		//Calcul de l'heure et de la date à Tbilissi et stockage de celui-ci dans la variable heure_a_tbilissi
		time_t heure_a_tbilissi = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Tbilisi");

		//L'heure et la date à Tbilissi en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_tbilissi, "Tbilissi");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Bakou"...
	else if(strcmp(nom_du_fuseau_horaire,"Bakou") == 0)
	{
		//Calcul de l'heure et de la date à Bakou et stockage de celui-ci dans la variable heure_a_bakou
		time_t heure_a_bakou = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Baku");

		//L'heure et la date à Bakou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_bakou, "Bakou");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Mogadiscio"...
	else if(strcmp(nom_du_fuseau_horaire,"Mogadiscio") == 0)
	{
		//Calcul de l'heure et de la date à Mogadiscio et stockage de celui-ci dans la variable heure_a_mogadiscio
		time_t heure_a_mogadiscio = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Africa/Mogadishu");

		//L'heure et la date à Mogadiscio en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_mogadiscio, "Mogadiscio");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Hovd"...
	else if(strcmp(nom_du_fuseau_horaire,"Hovd") == 0)
	{
		//Calcul de l'heure et de la date à Hovd et stockage de celui-ci dans la variable heure_a_hovd
                time_t heure_a_hovd = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Hovd");

		//L'heure et la date à Hovd en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_hovd, "Hovd");
	}

	/* République de Chine (Taiwan) */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Taipei"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Taipei") == 0)
	{
		//Calcul de l'heure et de la date à Tapei et stockage de celui-ci dans la variable heure_a_tapei
                time_t heure_a_tapei = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Taipei");

		//L'heure et la date à Tapei en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_tapei, "Asia/Taipei");
	}

	/* Région administrative spéciale de Macao de la République populaire de Chine */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Macau"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Macau") == 0)
	{
		//Calcul de l'heure et de la date à Macao et stockage de celui-ci dans la variable heure_a_macao
                time_t heure_a_macao = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Macau");

		//L'heure et la date à Macao en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_macao, "Asia/Macau");
	}

	/* République d'Ouzbékistan */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Tashkent"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Tashkent") == 0)
	{
		//Calcul de l'heure et de la date à Tachkent et stockage de celui-ci dans la variable heure_a_tachkent
                time_t heure_a_tachkent = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Tashkent");

		//L'heure et la date à Tachkent en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_tachkent, "Tachkent");
	}
	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Samarkand"...
        else if(strcmp(nom_du_fuseau_horaire,"Asia/Samarkand") == 0)
        {
                //Calcul de l'heure et de la date à Samarkand et stockage de celui-ci dans la variable heure_a_samarkand
                time_t heure_a_samarkand = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Samarkand");

                //L'heure et la date à Samarkand en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_samarkand, "Asia/Samarkand");
        }

	/* République du Tadjikistan */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Dushanbe"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Dushanbe") == 0)
	{
		//Calcul de l'heure et de la date à Douchanbé et stockage de celui-ci dans la variable heure_a_douchanbe
                time_t heure_a_douchanbe = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Dushanbe");

		//L'heure et la date à Douchanbé en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_douchanbe, "Asia/Dushanbe");
	}

	/* Royaume du Bhoutan */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Thimphu"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Thimphu") == 0)
	{
		//Calcul de l'heure et de la date à Thimphou et stockage de celui-ci dans la variable heure_a_thimphou
              	time_t heure_a_thimphou = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Thimphu");

		//L'heure et la date à Thimphou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_thimphou, "Asia/Thimphu");
	}

	/* République kirghize */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Bishkek"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Bishkek") == 0)
	{
		//Calcul de l'heure et de la date à Bichkek et stockage de celui-ci dans la variable heure_a_bichkek
                time_t heure_a_bichkek = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Bishkek");

		//L'heure et la date à Bichkek en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_bichkek, "Asia/Bishkek");
	}

	/* République démocratique fédérale du Népal */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Kathmandu"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Kathmandu") == 0)
	{
		//Calcul de l'heure et de la date à Katmandou et stockage de celui-ci dans la variable heure_a_katmandou
                time_t heure_a_katmandou = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Kathmandu");

		//L'heure et la date à Katmandou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_katmandou, "Asia/Kathmandu");
	}

	/* République islamique d'Afghanistan */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Kabul"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Kabul") == 0)
	{
		//Calcul de l'heure et de la date à Kaboul et stockage de celui-ci dans la variable heure_a_kaboul
                time_t heure_a_kaboul = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Kabul");

		//L'heure et la date à Kaboul en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_kaboul, "Asia/Kabul");
	}

	/* République de Singapour */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Singapore"...
	else if(strcmp(nom_du_fuseau_horaire,"Asia/Singapore") == 0)
	{
		//Calcul de l'heure et de la date à Singapour et stockage de celui-ci dans la variable heure_a_singapour
                time_t heure_a_singapour = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Singapore");

		//L'heure et la date à Singapour en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_singapour, "Asia/Singapore");
	}

	/* Région administrative spéciale de Hong Kong de la République populaire de Chine */

	//Si la valeur contenue dans la chaine de caractéres nom_du_fuseau_horaire est égale à "Asia/Hong_Kong"...
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
