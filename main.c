#include "heure_monde.h"
#include <stdio.h>

int main()
{
	//Appel à la fonction affichage_de_l_horloge avec comme paramétre le temps courant sous forme d'un timestamp (time_t)
	affichage_de_l_horloge(time(NULL));

	//
	char* test = retour_de_l_heure_et_de_la_date_pour_une_ville_determinee_et_connue(time(NULL), "Seoul");

	//
	printf("%s\n", test);

	//
	return 0;
}
