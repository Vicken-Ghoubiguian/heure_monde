/* Inclusion des bibliothéques standards du C utilisées dans cette bibliothéque-ci */
#include <time.h>

/* Inclusion des bibliothéques internes à l'API */
#include "bibliotheque_de_fonctions_utiles.h"

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
