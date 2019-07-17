/* Inclusion des bibliothéques internes à l'API */
#include "../src/fonction_pour_l_affichage_des_changements_d_heures/fonction_pour_l_affichage_des_changements_d_heures.h"

//Fonction de test des passages heure d'été <=> heure d'hiver, pour les zones géographques qui les comportes
int main(int argc, char* argv[])
{

	//
	fonction_pour_l_affichage_des_changements_d_heures(argc, argv);

	//La fonction main retourne 0, signe que ce programme s'est exécuté sans probléme
	return 0;

}
