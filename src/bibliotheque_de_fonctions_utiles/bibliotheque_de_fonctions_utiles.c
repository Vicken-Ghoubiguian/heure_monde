/* Inclusion des bibliothéques standards du C utilisées dans cette bibliothéque-ci */
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

/* Inclusion des bibliothéques internes à l'API */
#include "bibliotheque_de_fonctions_utiles.h"

//Cette fonction renvoie l'année en cours à partir du temps local de la machine d'execution
int retour_de_l_annee_en_cours()
{

	//Déclaration de la variable temps_local_sous_forme_de_struct_tm: Cette variable contiendra le temps local (heure et date) sous forme de struct tm
        struct tm *temps_local_sous_forme_de_struct_tm;

	//
	int annee_en_cours;

        //Déclaration et initialisation de la variable temps_actuel_sous_forme_de_timestamp: Cette variable contient le temps actuel (heure et date) sous forme de timestamp
        time_t temps_local_sous_forme_de_timestamp = time(NULL);

	//
        temps_local_sous_forme_de_struct_tm = localtime(&temps_local_sous_forme_de_timestamp);

	//
	annee_en_cours = (temps_local_sous_forme_de_struct_tm->tm_year + 1900);

	//
	return annee_en_cours;

}

//Cette fonction renvoie le temps actuel (heure et date actuelles) UTC (Coordinated Universal Time), donc le temps universel coordonné
time_t retour_du_temps_utc_sous_forme_de_timestamp()
{

	//Déclaration de la variable temps_utc_sous_forme_de_struct_tm: Cette variable contiendra le temps UTC (heure et date) sous forme de struct tm
	struct tm *temps_utc_sous_forme_de_struct_tm;

	//Déclaration de la variable temps_utc_sous_forme_de_timestamp: Cette variable contiendra le temps UTC (heure et date) sous forme de timestamp
	time_t temps_utc_sous_forme_de_timestamp;

	//Déclaration et initialisation de la variable temps_actuel_sous_forme_de_timestamp: Cette variable contient le temps actuel (heure et date) sous forme de timestamp
	time_t temps_actuel_sous_forme_de_timestamp = time(NULL);

	//
	temps_utc_sous_forme_de_struct_tm = gmtime(&temps_actuel_sous_forme_de_timestamp);

	//
	temps_utc_sous_forme_de_timestamp = timegm(temps_utc_sous_forme_de_struct_tm);

	//Le temps UTC, sous forme de timestamp, est retourné
	return temps_utc_sous_forme_de_timestamp;

}

//Cette fonction détermine si une année passée en paramétre est une année bissextile selon le calendrier persan
/*

Petite explication: dans le calendrier persan (en vigueur en République islamique d'Iran et en République islamique d'Afghanistan), une année jalali (pas grégorien mais jalali) 

est bissextile si et seulement si le reste de la division de cette année par 33 est égal à 1 OU 5 OU 9 OU 13 OU 17 OU 22 OU 33.

*/
int est_une_annee_bissextile_selon_le_calendrier_persan(int annee)
{
	//Déclaration des variables locales utilisées dans la fonction est_une_annee_bissextile_selon_le_calendrier_persan
	int annee_jalali;
	int hegire = 622;

	//
	annee_jalali = (annee - 622) + 1;

	//Si le reste de la division de l'année passée en paramétre (convertie en année jalali) par 33 est égal à 1 OU 5 OU 9 OU 13 OU 17 OU 22 OU 26 OU 30 alors...
	if((annee_jalali % 33 == 1) || (annee_jalali % 33 == 5) || (annee_jalali % 33 == 9) || (annee_jalali % 33 == 13) || (annee_jalali % 33 == 17) || (annee_jalali % 33 == 22) || (annee_jalali % 33 == 26) || (annee_jalali % 33 == 30))
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

//
int est_une_annee_qui_va_par_paire_de_quatre_selon_le_calendrier_persan(int annee)
{
	//Déclaration des variables locales utilisées dans la fonction est_une_annee_qui_va_par_paire_de_quatre_selon_le_calendrier_persan
        int annee_jalali;
        int hegire = 622;

        //
        annee_jalali = (annee - 622) + 1;

	//
	if(annee_jalali % 4 == 3)
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

//Cette fonction renvoie le timestamp courant avec plusieurs années de différence (en fonction de l'année passée en paramétre de la fonction)
time_t fonction_de_precision_de_l_annee_en_cours(time_t timestamp_du_temps_courant, int annee_particuliere_voulue)
{

	//Declaration des variables
	struct tm *horaire = gmtime(&timestamp_du_temps_courant);
	time_t timestamp_du_temps_voulu_a_retourner;
	int annee_particuliere_voulue_mis_sous_format_du_champ_tm_year_du_struct_tm;

	//Calcul de l'année voulu sous format attendu par le struct tm pour le cham:ps tm_year, et afféctation de celui-ci dans la variable annee_particuliere_voulue_mis_sous_format_du_champ_tm_year_du_struct_tm
	annee_particuliere_voulue_mis_sous_format_du_champ_tm_year_du_struct_tm = annee_particuliere_voulue - 1900;

	//Afféctation au champs tm_year de la structure tm de l'année particuliére passée en paramétre de la fonction fonction_de_precision_de_l_annee_en_cours
	horaire->tm_year = annee_particuliere_voulue_mis_sous_format_du_champ_tm_year_du_struct_tm;

	//Après cette opération, la structure tm horaire est convertie en timestamp via la fonction timegm, et le résultat est affécté à la variable timestamp_du_temps_voulu_a_retourner
	timestamp_du_temps_voulu_a_retourner = timegm(horaire);

	//Puis, le résultat est retourné
	return timestamp_du_temps_voulu_a_retourner;

}

//Cette fonction permet de récupérer pour un timezone passé en paramétre son indicateur pour déterminer si l'heure d'été s'applique ou non pour cette timezone
int recuperation_de_l_indicateur_d_application_de_l_heure_d_ete_pour_une_timezone_donnee(char* nom_de_la_timezone)
{
	//Déclaration des variables
	sqlite3 *connecteur_de_la_base_heure_monde;
	sqlite3_stmt *declaration_pour_sqlite3;
	int indicateur_d_application_de_l_heure_d_ete_pour_la_timezone_donnee = 0;

	//
        if(sqlite3_open("src/bibliotheque_de_fonctions_utiles/heure_monde.db", &connecteur_de_la_base_heure_monde) == SQLITE_OK)
        {
		//
		sqlite3_prepare_v2(connecteur_de_la_base_heure_monde, "SELECT indicateur_d_application_de_l_heure_d_ete FROM table_des_decalages_horaires WHERE nom_de_la_timezone = ?;",  -1, &declaration_pour_sqlite3, NULL);

		//
		sqlite3_bind_text(declaration_pour_sqlite3, 1, nom_de_la_timezone, -1, SQLITE_STATIC);

		//Si le nombre de colonnes contenue dans le résultat de la requête préparée declaration_pour_sqlite3 est égale à 1 (la requête ne contient qu'un seul résultat), alors...
		if(sqlite3_column_count(declaration_pour_sqlite3) == 1)
		{
			//
			while(sqlite3_step(declaration_pour_sqlite3) == SQLITE_ROW)
			{

				//
				indicateur_d_application_de_l_heure_d_ete_pour_la_timezone_donnee = sqlite3_column_int(declaration_pour_sqlite3, 0);

			}

			//Destruction de la requête préparée contenue dans la variable declaration_pour_sqlite3
                        sqlite3_finalize(declaration_pour_sqlite3);

                        //Destruction de la connexion SQLITE courante (contenue dans la variable connecteur_de_la_base_heure_monde)
                        sqlite3_close(connecteur_de_la_base_heure_monde);
		}
		//Sinon...
		else
		{
			//Affichage du message d'erreur
			printf("Erreur: il ne peut avoir qu'un seul indicateur d'application de l'heure d'été par timezone. Quelquechose ne va pas dans votre base de données heure_monde: %d.\n", sqlite3_column_count(declaration_pour_sqlite3));

			//Destruction de la requête préparée contenue dans la variable declaration_pour_sqlite3
			sqlite3_finalize(declaration_pour_sqlite3);

			//Destruction de la connexion SQLITE courante (contenue dans la variable connecteur_de_la_base_heure_monde)
			sqlite3_close(connecteur_de_la_base_heure_monde);

			//Le programme courant se termine avec la fonction exit à qui on passe le paramétre 1 (EXIT_FAILURE)
			exit(1);
		}
	}
	//Sinon...
        else
        {
                //Affichage du message d'erreur
                printf("Erreur lors de l'ouverture de la base de données heure_monde. Pourquoi ? Eh bien: %s\n", sqlite3_errmsg(connecteur_de_la_base_heure_monde));

                //Destruction de la connexion SQLITE courante (contenue dans la variable connecteur_de_la_base_heure_monde)
                sqlite3_close(connecteur_de_la_base_heure_monde);

                //Le programme courant se termine avec la fonction exit à qui on passe le paramétre 1 (EXIT_FAILURE)
                exit(1);
        }

	//L'indicateur d'application de l'heure d'été est retourné
	return indicateur_d_application_de_l_heure_d_ete_pour_la_timezone_donnee;
}

//Cette fonction permet de récupérer pour un timezone passé en paramétre son décalage horaire courant (sous DST) par rapport à l'UTC comme nombre de secondes
int recuperation_du_decalage_horaire_courant_sous_DST_pour_une_timezone_donnee(char* nom_de_la_timezone)
{
	//Déclaration des variables
        sqlite3 *connecteur_de_la_base_heure_monde;
        sqlite3_stmt *declaration_pour_sqlite3;
        int decalage_par_rapport_a_UTC;

	//
	if(sqlite3_open("src/bibliotheque_de_fonctions_utiles/heure_monde.db", &connecteur_de_la_base_heure_monde) == SQLITE_OK)
	{

		//
		sqlite3_prepare_v2(connecteur_de_la_base_heure_monde, "SELECT decalage_par_rapport_a_UTC_durant_l_heure_ete FROM table_des_decalages_horaires WHERE nom_de_la_timezone = ?;",  -1, &declaration_pour_sqlite3, NULL);

		//
		sqlite3_bind_text(declaration_pour_sqlite3, 1, nom_de_la_timezone, -1, SQLITE_STATIC);

		//Si le nombre de colonnes contenue dans le résultat de la requête préparée declaration_pour_sqlite3 est égale à 1 (la requête ne contient qu'un seul résultat), alors...
		if(sqlite3_column_count(declaration_pour_sqlite3) == 1)
		{
			//
			while(sqlite3_step(declaration_pour_sqlite3) == SQLITE_ROW)
			{

				//
				decalage_par_rapport_a_UTC = sqlite3_column_int(declaration_pour_sqlite3, 0);

			}

			//Destruction de la requête préparée contenue dans la variable declaration_pour_sqlite3
                        sqlite3_finalize(declaration_pour_sqlite3);

                        //Destruction de la connexion SQLITE courante (contenue dans la variable connecteur_de_la_base_heure_monde)
                        sqlite3_close(connecteur_de_la_base_heure_monde);
		}
		//Sinon...
		else
		{
			//Affichage du message d'erreur
			printf("Erreur: il ne peut avoir qu'un seul décalage horaire enregistré par timezone. Quelquechose ne va pas dans votre base de données heure_monde: %d.\n", sqlite3_column_count(declaration_pour_sqlite3));

			//Destruction de la requête préparée contenue dans la variable declaration_pour_sqlite3
			sqlite3_finalize(declaration_pour_sqlite3);

			//Destruction de la connexion SQLITE courante (contenue dans la variable connecteur_de_la_base_heure_monde)
			sqlite3_close(connecteur_de_la_base_heure_monde);

			//Le programme courant se termine avec la fonction exit à qui on passe le paramétre 1 (EXIT_FAILURE)
			exit(1);
		}
	}
	else
	{
		//Affichage du message d'erreur
		printf("Erreur lors de l'ouverture de la base de données heure_monde. Pourquoi ? Eh bien: %s\n", sqlite3_errmsg(connecteur_de_la_base_heure_monde));

		//Destruction de la connexion SQLITE courante (contenue dans la variable connecteur_de_la_base_heure_monde)
		sqlite3_close(connecteur_de_la_base_heure_monde);

		//Le programme courant se termine avec la fonction exit à qui on passe le paramétre 1 (EXIT_FAILURE)
		exit(1);
	}

	//Le décalage horaire par rapport à l'UTC comme nombre de secondes est retournée
	return decalage_par_rapport_a_UTC;
}

//Cette fonction permet de récupérer pour un timezone passé en paramétre son décalage horaire courant (pas DST) par rapport à l'UTC comme nombre de secondes
int recuperation_du_decalage_horaire_courant_hors_DST_pour_une_timezone_donnee(char* nom_de_la_timezone)
{
	//Déclaration des variables
        sqlite3 *connecteur_de_la_base_heure_monde;
        sqlite3_stmt *declaration_pour_sqlite3;
        int decalage_par_rapport_a_UTC;

	//
	if(sqlite3_open("src/bibliotheque_de_fonctions_utiles/heure_monde.db", &connecteur_de_la_base_heure_monde) == SQLITE_OK)
	{

		//
		sqlite3_prepare_v2(connecteur_de_la_base_heure_monde, "SELECT decalage_par_rapport_a_UTC FROM table_des_decalages_horaires WHERE nom_de_la_timezone = ?;",  -1, &declaration_pour_sqlite3, NULL);

		//
		sqlite3_bind_text(declaration_pour_sqlite3, 1, nom_de_la_timezone, -1, SQLITE_STATIC);

		//Si le nombre de colonnes contenue dans le résultat de la requête préparée declaration_pour_sqlite3 est égale à 1 (la requête ne contient qu'un seul résultat), alors...
		if(sqlite3_column_count(declaration_pour_sqlite3) == 1)
		{
			//
			while(sqlite3_step(declaration_pour_sqlite3) == SQLITE_ROW)
			{

				//
				decalage_par_rapport_a_UTC = sqlite3_column_int(declaration_pour_sqlite3, 0);

			}

			//Destruction de la requête préparée contenue dans la variable declaration_pour_sqlite3
                        sqlite3_finalize(declaration_pour_sqlite3);

                        //Destruction de la connexion SQLITE courante (contenue dans la variable connecteur_de_la_base_heure_monde)
                        sqlite3_close(connecteur_de_la_base_heure_monde);
		}
		//Sinon...
		else
		{
			//Affichage du message d'erreur
			printf("Erreur: il ne peut avoir qu'un seul décalage horaire enregistré par timezone. Quelquechose ne va pas dans votre base de données heure_monde: %d.\n", sqlite3_column_count(declaration_pour_sqlite3));

			//Destruction de la requête préparée contenue dans la variable declaration_pour_sqlite3
			sqlite3_finalize(declaration_pour_sqlite3);

			//Destruction de la connexion SQLITE courante (contenue dans la variable connecteur_de_la_base_heure_monde)
			sqlite3_close(connecteur_de_la_base_heure_monde);

			//Le programme courant se termine avec la fonction exit à qui on passe le paramétre 1 (EXIT_FAILURE)
			exit(1);
		}
	}
	//Sinon...
	else
	{
		//Affichage du message d'erreur
		printf("Erreur lors de l'ouverture de la base de données heure_monde. Pourquoi ? Eh bien: %s\n", sqlite3_errmsg(connecteur_de_la_base_heure_monde));

		//Destruction de la connexion SQLITE courante (contenue dans la variable connecteur_de_la_base_heure_monde)
		sqlite3_close(connecteur_de_la_base_heure_monde);

		//Le programme courant se termine avec la fonction exit à qui on passe le paramétre 1 (EXIT_FAILURE)
		exit(1);
	}

	//Le décalage horaire par rapport à l'UTC comme nombre de secondes est retournée
	return decalage_par_rapport_a_UTC;
}

//Cette fonction permet de récupérer pour un timezone passé en paramétre son décalage horaire par rapport à l'UTC comme nombre de secondes
int recuperation_du_decalage_horaire_pour_une_timezone_donnee(char* nom_de_la_timezone)
{
	//Déclaration des variables
	int decalage_par_rapport_a_UTC;
	int indicateur_d_application_de_l_heure_d_ete;

	//
	indicateur_d_application_de_l_heure_d_ete = recuperation_de_l_indicateur_d_application_de_l_heure_d_ete_pour_une_timezone_donnee(nom_de_la_timezone);

	//
	if(indicateur_d_application_de_l_heure_d_ete)
	{
		//
		decalage_par_rapport_a_UTC = recuperation_du_decalage_horaire_courant_sous_DST_pour_une_timezone_donnee(nom_de_la_timezone);
	}
	//Sinon...
	else
	{
		//
		decalage_par_rapport_a_UTC = recuperation_du_decalage_horaire_courant_hors_DST_pour_une_timezone_donnee(nom_de_la_timezone);
	}

	//Le décalage horaire par rapport à l'UTC comme nombre de secondes est retournée
	return decalage_par_rapport_a_UTC;
}
