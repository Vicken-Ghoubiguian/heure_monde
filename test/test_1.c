/* Inclusion des bibliothéques standards du C utilisées dans cette bibliothéque-ci */
#include <stdio.h>

/* Inclusion des bibliothéques internes à l'API */
#include "../src/affichage_de_l_horloge/affichage_de_l_horloge.h"

//Fonction de test de la fonction affichage_de_l_horloge
int main()
{
	//Appel à la fonction affichage_de_l_horloge, qui calcule et affiche l'heure et la date courantes sur tous les fuseaux horaires du monde entier
	affichage_de_l_horloge();

	//
	return 0;
}
