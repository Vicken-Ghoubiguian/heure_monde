#include <stdio.h>
#include "../src/retour_de_la_date_et_de_l_heure.h"

//Fonction de test de la fonction retour_de_la_date_et_de_l_heure
int main(int argc, char* argv[])
{
	//
	int incrementeur;

	//
	char* date_et_heure_du_fuseau_horaire_courant;

	//
	if(argc < 2)
	{
		//
		printf("Ecrivez donc le nom des fuseaux hoarires que vous voulez.\n");
	}
	//
	else
	{
		//
		for(incrementeur = 1; incrementeur < argc; incrementeur++)
		{
			//
			date_et_heure_du_fuseau_horaire_courant = retour_de_l_heure_et_de_la_date_pour_une_ville_determinee_et_connue(time(NULL), argv[incrementeur]);

			//
			printf("%s\n", date_et_heure_du_fuseau_horaire_courant);
		}
	}

        //
        return 0;
}
