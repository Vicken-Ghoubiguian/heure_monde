#include "heure_monde.h"

int main()
{
	//Appel à la fonction affichage_de_l_horloge avec comme paramétre le temps courant sous forme d'un timestamp (time_t)
	affichage_de_l_horloge(time(NULL));

	return 0;
}
