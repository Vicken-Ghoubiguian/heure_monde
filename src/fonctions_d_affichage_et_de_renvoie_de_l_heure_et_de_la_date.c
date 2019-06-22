#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Cette fonction permet de calculer et de renvoyer les horaires d'une ville passée en paramétre
char* calcul_et_renvoie_horaire(time_t temps, char* ville)
{
	//Declaration des variables
	struct tm *horaire = gmtime(&temps);
	char* jour_semaine;
	char* mois;
	char* resultat_du_calcul = malloc(sizeof(char) * 85);
	char chiffre_a_convertir_en_str[5];

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
	strcat(resultat_du_calcul, ville);

	//
	strcat(resultat_du_calcul, " : ");

	//
	if(horaire->tm_hour < 10)
	{
		//
		sprintf(chiffre_a_convertir_en_str, "%02d", horaire->tm_hour);
	}
	//Sinon...
	else
	{
		//
		sprintf(chiffre_a_convertir_en_str, "%d", horaire->tm_hour);
	}

	//
	strcat(resultat_du_calcul, chiffre_a_convertir_en_str);

	//
	strcat(resultat_du_calcul, ":");

	//
	if(horaire->tm_min < 10)
	{
		//
		sprintf(chiffre_a_convertir_en_str, "%02d", horaire->tm_min);
	}
	//Sinon...
	else
	{
		//
		sprintf(chiffre_a_convertir_en_str, "%d", horaire->tm_min);
	}

	//
	strcat(resultat_du_calcul, chiffre_a_convertir_en_str);

	//
	strcat(resultat_du_calcul, ":");

	//
	if(horaire->tm_sec < 10)
	{
		//
		sprintf(chiffre_a_convertir_en_str, "%02d", horaire->tm_sec);
	}
	//Sinon...
	else
	{
		//
		sprintf(chiffre_a_convertir_en_str, "%d", horaire->tm_sec);
	}

	//
	strcat(resultat_du_calcul, chiffre_a_convertir_en_str);

	//
	strcat(resultat_du_calcul, " - ");

	//
	strcat(resultat_du_calcul, jour_semaine);

	//
	strcat(resultat_du_calcul, " ");

	//
	if(horaire->tm_mday < 10)
	{
		//
		sprintf(chiffre_a_convertir_en_str, "%02d", horaire->tm_mday);
	}
	//Sinon...
	else
	{
		//
		sprintf(chiffre_a_convertir_en_str, "%d", horaire->tm_mday);
	}

	//
	strcat(resultat_du_calcul, chiffre_a_convertir_en_str);

	//
	strcat(resultat_du_calcul, " ");

	//
        strcat(resultat_du_calcul, mois);

	//
	strcat(resultat_du_calcul, " ");

	//
	sprintf(chiffre_a_convertir_en_str, "%d", horaire->tm_year + 1900);
        strcat(resultat_du_calcul, chiffre_a_convertir_en_str);

	//
	return resultat_du_calcul;
}

//Cette fonction permet de calculer et d'afficher les horaires d'une ville passée en paramétre
void calcul_et_affichage_horaire(time_t temps, char* ville)
{
	//Declaration des variables
	struct tm *horaire = gmtime(&temps);
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
