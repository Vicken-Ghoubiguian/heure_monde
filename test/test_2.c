/* Inclusion des bibliothéques standards du C utilisées dans cette bibliothéque-ci */
#include <stdio.h>

/* Inclusion des bibliothéques internes à l'API */
#include "../src/retour_de_la_date_et_de_l_heure/retour_de_la_date_et_de_l_heure.h"

//Fonction de test de la fonction retour_de_la_date_et_de_l_heure
//argv[] est un tableau de chaines de caractéres contenant tous les arguments passés en paramétre du programme exécutable, et argc est la longueur de ce même tableau
int main(int argc, char* argv[])
{
	//
	int incrementeur;

	//
	char* date_et_heure_du_fuseau_horaire_courant;

	//Si le nombre d'arguments passés au programme (donc, argc) est strictement inférieur à 2 (par défaut, un programme exécutable ne comporte qu'un seul argument: lui même), alors...
	if(argc < 2)
	{
		//On affiche le fait que ce programme exécutable prend un argument ou plusieurs arguments
		printf("Ecrivez donc le nom des fuseaux horaires que vous voulez.\n");
	}
	//Sinon...
	else
	{
		//On parcours le tableau des arguments passés en paramétre de ce programme exécutable
		for(incrementeur = 1; incrementeur < argc; incrementeur++)
		{
			//On calcul la date et l'heure courante pour le fuseau horaire courant (les arguments de ce programme exécutable sont des fuseaux horaires), pour la stocker dans la variable date_et_heure_du_fuseau_horaire_courant
			date_et_heure_du_fuseau_horaire_courant = retour_de_l_heure_et_de_la_date_pour_une_ville_determinee_et_connue(argv[incrementeur]);

			//Puis on affiche la valeur de la variable date_et_heure_du_fuseau_horaire_courant (qui est un char*)
			printf("%s\n", date_et_heure_du_fuseau_horaire_courant);
		}
	}

        //La fonction main retourne 0 quoiqu'il arrive (signe que ce programme s'est exécuté sans probléme)
        return 0;
}
