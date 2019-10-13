/* Inclusion des bibliothéques standards du C utilisées dans cette bibliothéque-ci */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Inclusion des bibliothéques internes à l'API */
#include "../calcul_des_passages_heure_d_ete_heure_d_hiver_et_reciproquement/calcul_des_passages_heure_d_ete_heure_d_hiver_et_reciproquement.h"
#include "../bibliotheque_de_fonctions_utiles/bibliotheque_de_fonctions_utiles.h"
#include "application_des_decalages_horaires.h"

//Cette fonction permet d'appliquer le changement d'heure pour les Fidji
void application_du_changement_d_heure_pour_les_fidji(time_t temps_utc)
{
	//On calcul le temps courant hypothétique pour la timezone correspondante aux Fidji
        time_t temps_courant_pour_la_timezone_donnee = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Fiji");

        //On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
        time_t ete = date_du_premier_jour_de_la_semaine_donne_du_mois_donne(temps_courant_pour_la_timezone_donnee, 3, 0, 10);
	time_t hiver = date_du_changement_d_heure_d_hiver_pour_les_fidji(temps_courant_pour_la_timezone_donnee);

        //
        if(hiver <= temps_courant_pour_la_timezone_donnee && temps_courant_pour_la_timezone_donnee < ete)
        {
                //L'indicateur d'application de l'heure d'été est mis à 0 (l'heure d'été n'est pas en vigueur pour le moment)
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete("Pacific/Fiji", 0);
        }
        //Sinon...
        else
        {
                //L'indicateur d'application de l'heure d'été est mis à 1 (l'heure d'été est en vigueur pour le moment)
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete("Asia/Tehran", 3600);
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour le Brésil
int application_du_changement_d_heure_pour_le_bresil(time_t temps_courant)
{
        //On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
        time_t ete = date_du_premier_jour_de_la_semaine_donne_du_mois_donne(temps_courant, 3, 0, 10);
        time_t hiver = date_du_n_ieme_jour_de_la_semaine_donne_du_mois_donne(temps_courant, 3, 3, 0, 1);

        //
        if(hiver <= temps_courant && temps_courant < ete)
        {
                //On retourne 0
                return 0;
        }
        //Sinon...
        else
        {
                //On retourne 1
                return 1;
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour la Syrie
void application_du_changement_d_heure_pour_la_syrie(time_t temps_utc)
{
	//On calcul le temps courant hypothétique pour la timezone correspondante à la Syrie
        time_t temps_courant_pour_la_timezone_donnee = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Damascus");

	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
        time_t ete = date_du_dernier_jour_de_la_semaine_donne_du_mois_donne(temps_courant_pour_la_timezone_donnee, 2, 5, 2);
        time_t hiver = date_du_dernier_jour_de_la_semaine_donne_du_mois_donne(temps_courant_pour_la_timezone_donnee, 3, 5, 9);

	//
        if(temps_courant_pour_la_timezone_donnee >= ete && temps_courant_pour_la_timezone_donnee <= hiver)
        {
                //L'indicateur d'application de l'heure d'été est mis à 1 (l'heure d'été est en vigueur pour le moment)
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete("Asia/Damascus", 3600);
        }
        //Sinon...
        else
        {
                //L'indicateur d'application de l'heure d'été est mis à 0 (l'heure d'été n'est pas en vigueur pour le moment)
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete("Asia/Damascus", 0);
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour la Palestine
int application_du_changement_d_heure_pour_la_palestine(time_t temps_courant)
{
        //On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
        time_t ete = date_du_dernier_jour_de_la_semaine_donne_du_mois_donne(temps_courant, 1, 6, 2);
        time_t hiver = date_du_dernier_jour_de_la_semaine_donne_du_mois_donne(temps_courant, 1, 6, 9);

        //
        if(temps_courant >= ete && temps_courant <= hiver)
        {
                //On retourne 1
                return 1;
        }
        //Sinon...
        else
        {
                //On retourne 0
                return 0;
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour Israel
int application_du_changement_d_heure_pour_israel(time_t temps_courant)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
        time_t ete = date_du_dernier_jour_de_la_semaine_donne_du_mois_donne(temps_courant, 2, 5, 2);
        time_t hiver = date_du_dernier_jour_de_la_semaine_donne_du_mois_donne(temps_courant, 3, 0, 9);

        //
        if(temps_courant >= ete && temps_courant <= hiver)
        {
                //On retourne 1
                return 1;
        }
        //Sinon...
        else
        {
                //On retourne 0
                return 0;
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour le Liban
int application_du_changement_d_heure_pour_le_liban(time_t temps_courant)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
        time_t ete = date_du_dernier_jour_de_la_semaine_donne_du_mois_donne(temps_courant, 2, 0, 2);
        time_t hiver = date_du_dernier_jour_de_la_semaine_donne_du_mois_donne(temps_courant, 3, 0, 9);

	//
	if(temps_courant >= ete && temps_courant <= hiver)
        {
                //On retourne 1
                return 1;
        }
        //Sinon...
        else
        {
                //On retourne 0
                return 0;
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour l'Iran
void application_du_changement_d_heure_pour_l_iran(time_t temps_utc)
{
	//On calcul le temps courant hypothétique pour la timezone correspondante à l'Iran
        time_t temps_courant_pour_la_timezone_donnee = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Asia/Tehran");

	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
        time_t ete = date_du_changement_d_heure_d_ete_pour_l_iran(temps_courant_pour_la_timezone_donnee);
        time_t hiver = date_du_changement_d_heure_d_hiver_pour_l_iran(temps_courant_pour_la_timezone_donnee);

        //
        if(temps_courant_pour_la_timezone_donnee >= ete && temps_courant_pour_la_timezone_donnee <= hiver)
        {
                //L'indicateur d'application de l'heure d'été est mis à 1 (l'heure d'été est en vigueur pour le moment)
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete("Asia/Tehran", 3600);
        }
        //Sinon...
        else
        {
                //L'indicateur d'application de l'heure d'été est mis à 0 (l'heure d'été n'est pas en vigueur pour le moment)
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete("Asia/Tehran", 0);
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour la Jordanie
int application_du_changement_d_heure_pour_la_jordanie(time_t temps_courant)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
	time_t ete = date_du_changement_d_heure_d_hiver_pour_la_jordanie(temps_courant);
	time_t hiver = date_du_dernier_jour_de_la_semaine_donne_du_mois_donne(temps_courant, 3, 5, 9);

	//
        if(temps_courant >= ete && temps_courant <= hiver)
        {
                //On retourne 1
                return 1;
        }
        //Sinon...
        else
        {
                //On retourne 0
                return 0;
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour le Paraguay
void application_du_changement_d_heure_pour_le_paraguay(time_t temps_utc)
{
	//On calcul le temps courant hypothétique pour la timezone correspondante au Paraguay
	time_t temps_courant_pour_la_timezone_donnee = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("America/Asuncion");

	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
        time_t ete = date_du_premier_jour_de_la_semaine_donne_du_mois_donne(temps_courant_pour_la_timezone_donnee, 0, 0, 9);
        time_t hiver = date_du_n_ieme_jour_de_la_semaine_donne_du_mois_donne(temps_courant_pour_la_timezone_donnee, 4, 0, 0, 2);

        //
        if(hiver <= temps_courant_pour_la_timezone_donnee && temps_courant_pour_la_timezone_donnee < ete)
        {
               	//L'indicateur d'application de l'heure d'été est mis à 0 (l'heure d'été n'est pas en vigueur pour le moment)
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete("America/Asuncion", 0);
        }
        //Sinon...
        else
        {
                //L'indicateur d'application de l'heure d'été est mis à 1 (l'heure d'été est en vigueur pour le moment)
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete("America/Asuncion", 3600);
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour la base antarctique de Troll
void application_du_changement_d_heure_pour_la_base_antarctique_de_troll(time_t temps_utc)
{
	//On calcul le temps courant hypothétique pour la timezone correspondante à la base antarctique de Troll
	time_t temps_courant_pour_la_timezone_donnee = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Antarctica/Troll");

	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
	time_t ete = date_du_dernier_jour_de_la_semaine_donne_du_mois_donne(temps_courant_pour_la_timezone_donnee, 1, 0, 2);
	time_t hiver = date_du_dernier_jour_de_la_semaine_donne_du_mois_donne(temps_courant_pour_la_timezone_donnee, 3, 0, 9);

	//
	if(temps_courant_pour_la_timezone_donnee >= ete && temps_courant_pour_la_timezone_donnee <= hiver)
	{
		//L'indicateur d'application de l'heure d'été est mis à 2 (l'heure d'été est en vigueur pour le moment)
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete("Antarctica/Troll", 7200);
	}
	//Sinon...
	else
	{
		//L'indicateur d'application de l'heure d'été est mis à 0 (l'heure d'été n'est pas en vigueur pour le moment)
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete("Antarctica/Troll", 0);
	}
}

//Cette fonction permet d'appliquer le changement d'heure pour les Samoa
void application_du_changement_d_heure_pour_les_samoa(time_t temps_utc)
{
	//On calcul le temps courant hypothétique pour la timezone correspondante aux Samoa
        time_t temps_courant_pour_la_timezone_donnee = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Pacific/Apia");

	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
	time_t ete = date_du_dernier_jour_de_la_semaine_donne_du_mois_donne(temps_courant_pour_la_timezone_donnee, 4, 0, 8);
	time_t hiver = date_du_premier_jour_de_la_semaine_donne_du_mois_donne(temps_courant_pour_la_timezone_donnee, 3, 0, 3);

	//
        if(hiver <= temps_courant_pour_la_timezone_donnee && temps_courant_pour_la_timezone_donnee < ete)
        {
                //L'indicateur d'application de l'heure d'été est mis à 0 (l'heure d'été n'est pas en vigueur pour le moment)
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete("Pacific/Apia", 0);
        }
        //Sinon...
        else
        {
                //L'indicateur d'application de l'heure d'été est mis à 1 (l'heure d'été est en vigueur pour le moment)
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete("Pacific/Apia", 3600);
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour l'Australie
void application_du_changement_d_heure_pour_l_australie(char* nom_de_la_timezone, time_t temps_utc)
{
	//On calcul le temps courant hypothétique pour la timezone donnée
        time_t temps_courant_pour_la_timezone_donnee = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee(nom_de_la_timezone);

	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
	time_t ete = date_du_premier_jour_de_la_semaine_donne_du_mois_donne(temps_courant_pour_la_timezone_donnee, 2, 0, 9);
	time_t hiver = date_du_premier_jour_de_la_semaine_donne_du_mois_donne(temps_courant_pour_la_timezone_donnee, 3, 0, 3);

	//
	if(hiver <= temps_courant_pour_la_timezone_donnee && temps_courant_pour_la_timezone_donnee < ete)
	{
		//L'indicateur d'application de l'heure d'été est mis à 0 (l'heure d'été n'est pas en vigueur pour le moment)
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete(nom_de_la_timezone, 0);
	}
	//Sinon...
	else
	{
		//L'indicateur d'application de l'heure d'été est mis à 1 (l'heure d'été est en vigueur pour le moment)
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete(nom_de_la_timezone, 3600);
	}
}

//Cette fonction permet d'appliquer le changement d'heure pour l'île Lord Howe
void application_du_changement_d_heure_pour_le_cas_particulier_de_lord_howe(time_t temps_utc)
{
	//On calcul le temps courant hypothétique pour la timezone correspondante à l'île Lord Howe
	time_t temps_courant_pour_la_timezone_donnee = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee("Australia/Lord_Howe");

	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
        time_t ete = date_du_premier_jour_de_la_semaine_donne_du_mois_donne(temps_courant_pour_la_timezone_donnee, 2, 0, 9);
        time_t hiver = date_du_premier_jour_de_la_semaine_donne_du_mois_donne(temps_courant_pour_la_timezone_donnee, 3, 0, 2);

        //
        if(hiver <= temps_courant_pour_la_timezone_donnee && temps_courant_pour_la_timezone_donnee < ete)
        {
		//L'indicateur d'application de l'heure d'été est mis à 0
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete("Australia/Lord_Howe", 0);
        }
        //Sinon...
        else
        {
                //L'indicateur d'application de l'heure d'été est mis à 1800
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete("Australia/Lord_Howe", 1800);
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour la Nouvelle Zelande
void application_du_changement_d_heure_pour_la_nouvelle_zelande(char* nom_de_la_timezone, time_t temps_utc)
{
	//On calcul le temps courant hypothétique pour la timezone donnée
        time_t temps_courant_pour_la_timezone_donnee = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee(nom_de_la_timezone);

	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
	time_t ete = date_du_dernier_jour_de_la_semaine_donne_du_mois_donne(temps_courant_pour_la_timezone_donnee, 2, 0, 8);
	time_t hiver = date_du_premier_jour_de_la_semaine_donne_du_mois_donne(temps_courant_pour_la_timezone_donnee, 3, 0, 3);

	//
	if(hiver <= temps_courant_pour_la_timezone_donnee && temps_courant_pour_la_timezone_donnee < ete)
	{
		//L'indicateur d'application de l'heure d'été est mis à 0 (l'heure d'été n'est pas en vigueur pour le moment)
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete(nom_de_la_timezone, 0);
	}
	//Sinon...
	else
	{
		//L'indicateur d'application de l'heure d'été est mis à 1 (l'heure d'été est en vigueur pour le moment)
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete(nom_de_la_timezone, 3600);
	}
}

//Cette fonction permet d'appliquer le changement d'heure pour le Chili
void application_du_changement_d_heure_pour_le_chili(char* nom_de_la_timezone, time_t temps_utc)
{
	//On calcul le temps courant hypothétique pour la timezone donnée
        time_t temps_courant_pour_la_timezone_donnee = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee(nom_de_la_timezone);

	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
	time_t ete = date_du_changement_d_heure_d_ete_pour_le_chili(temps_courant_pour_la_timezone_donnee);
	time_t hiver = date_du_n_ieme_jour_de_la_semaine_donne_du_mois_donne(temps_courant_pour_la_timezone_donnee, 2, 2, 0, 3);

	//
        if(hiver <= temps_courant_pour_la_timezone_donnee && temps_courant_pour_la_timezone_donnee < ete)
        {
                //L'indicateur d'application de l'heure d'été est mis à 0 (l'heure d'été n'est pas en vigueur pour le moment)
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete(nom_de_la_timezone, 0);
        }
        //Sinon...
        else
        {
                //L'indicateur d'application de l'heure d'été est mis à 1 (l'heure d'été est en vigueur pour le moment)
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete(nom_de_la_timezone, 3600);
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour l'Amérique du Nord
int application_du_changement_d_heure_pour_l_amerique_du_nord(time_t temps_courant)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
	time_t ete = date_du_n_ieme_jour_de_la_semaine_donne_du_mois_donne(temps_courant, 2, 2, 0, 2);
	time_t hiver = date_du_premier_jour_de_la_semaine_donne_du_mois_donne(temps_courant, 2, 0, 10);

	//
	if(temps_courant >= ete && temps_courant <= hiver)
	{
		//On retourne 1
		return 1;
	}
	//Sinon...
	else
	{
		//On retourne 0
		return 0;
	}
}

//Cette fonction permet d'appliquer le changement d'heure pour la Grande Bretagne
int application_du_changement_d_heure_pour_la_grande_bretagne(time_t temps_courant)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
	time_t ete = date_du_dernier_jour_de_la_semaine_donne_du_mois_donne(temps_courant, 1, 0, 2);
	time_t hiver = date_du_dernier_jour_de_la_semaine_donne_du_mois_donne(temps_courant, 2, 0, 9);

	//
	if(temps_courant >= ete && temps_courant <= hiver)
	{
		//On retourne 1
		return 1;
	}
	//Sinon...
	else
	{
		//On retourne 0
		return 0;
	}
}

//Cette fonction permet d'appliquer le changement d'heure pour l'Europe continentale
int application_du_changement_d_heure_pour_l_europe_continentale(time_t temps_courant)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
	time_t ete = date_du_dernier_jour_de_la_semaine_donne_du_mois_donne(temps_courant, 3, 0, 2);
	time_t hiver = date_du_dernier_jour_de_la_semaine_donne_du_mois_donne(temps_courant, 2, 0, 9);

	//
	if(temps_courant >= ete && temps_courant <= hiver)
	{
		//On retourne 1
		return 1;
	}
	//Sinon...
	else
	{
		//On retourne 0
		return 0;
	}
}

//Cette fonction permet d'appliquer le changement d'heure pour l'Europe continentale
void application_du_changement_d_heure_pour_l_europe_continentale_R(char* nom_de_la_timezone, time_t temps_utc)
{
	//On calcul le temps courant hypothétique pour la timezone donnée
	time_t temps_courant_pour_la_timezone_donnee = temps_utc + recuperation_du_decalage_horaire_pour_une_timezone_donnee(nom_de_la_timezone);

	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
	time_t ete = date_du_dernier_jour_de_la_semaine_donne_du_mois_donne(temps_courant_pour_la_timezone_donnee, 3, 0, 2);
        time_t hiver = date_du_dernier_jour_de_la_semaine_donne_du_mois_donne(temps_courant_pour_la_timezone_donnee, 2, 0, 9);

	//
	if(temps_courant_pour_la_timezone_donnee >= ete && temps_courant_pour_la_timezone_donnee <= hiver)
        {
                //L'indicateur d'application de l'heure d'été est mis à 1 (l'heure d'été est en vigueur pour le moment)
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete(nom_de_la_timezone, 3600);
        }
        //Sinon...
        else
        {
                //L'indicateur d'application de l'heure d'été est mis à 0 (l'heure d'été n'est pas en vigueur pour le moment)
                mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete(nom_de_la_timezone, 0);
        }
}
