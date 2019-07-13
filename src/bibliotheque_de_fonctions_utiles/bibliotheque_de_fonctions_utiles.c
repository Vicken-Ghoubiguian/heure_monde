/* Inclusion des bibliothéques standards du C utilisées dans cette bibliothéque-ci */
#include <time.h>

/* Inclusion des bibliothéques internes à l'API */
#include "bibliotheque_de_fonctions_utiles.h"

#include <stdio.h>

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
	//
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
