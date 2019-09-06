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

//
int recuperation_du_decalage_horaire_pour_une_timezone_donnee(char* nom_de_la_timezone)
{
	//
	sqlite3 *connecteur_de_la_base_heure_monde;
	sqlite3_stmt *declaration_pour_sqlite3;
	int resultat_de_la_requete;
	int decalage_par_rapport_a_UTC;

	//
	if(sqlite3_open("heure_monde.db", &connecteur_de_la_base_heure_monde) == SQLITE_OK)
	{
		//
		sqlite3_prepare_v2(connecteur_de_la_base_heure_monde, "SELECT decalage_par_rapport_a_UTC FROM table_des_decalages_horaires WHERE nom_de_la_timezone = ?;",  -1, &declaration_pour_sqlite3, NULL);

		//
		sqlite3_bind_text(declaration_pour_sqlite3, 1, "Asia/Anadyr", -1, SQLITE_STATIC);

		//
		if(sqlite3_column_count(declaration_pour_sqlite3) == 1)
		{
			while(sqlite3_step(declaration_pour_sqlite3) == SQLITE_ROW)
			{

				//
				decalage_par_rapport_a_UTC = sqlite3_column_int(declaration_pour_sqlite3, 0);

			}

			//
                        sqlite3_finalize(declaration_pour_sqlite3);

                        //
                        sqlite3_close(connecteur_de_la_base_heure_monde);

			//
			printf("Valeur: %d.\n", decalage_par_rapport_a_UTC);
		}
		//Sinon...
		else
		{
			//
			printf("Erreur: il ne peut avoir qu'un seul décalage horaire enregistré par timezone. Quelquechose ne va pas dans votre base de données heure_monde: %d.\n", sqlite3_column_count(declaration_pour_sqlite3));

			//
			sqlite3_finalize(declaration_pour_sqlite3);

			//
			sqlite3_close(connecteur_de_la_base_heure_monde);

			//
			exit(1);
		}
	}
	//Sinon...
	else
	{
		//
		printf("Erreur lors de l'ouverture de la base de données heure_monde. Pourquoi ? Eh bien: %s\n", sqlite3_errmsg(connecteur_de_la_base_heure_monde));

		//
		sqlite3_finalize(declaration_pour_sqlite3);

		//
		sqlite3_close(connecteur_de_la_base_heure_monde);

		//
		exit(1);
	}

	return decalage_par_rapport_a_UTC;
}
