/* Inclusion des bibliothéques standards du C utilisées dans cette bibliothéque-ci */
#include <stdio.h>

/* Inclusion des bibliothéques internes à l'API */
#include "../src/fonctions_d_affichage_et_de_renvoie_de_l_heure_et_de_la_date/fonctions_d_affichage_et_de_renvoie_de_l_heure_et_de_la_date.h"
#include "../src/calcul_des_passages_heure_d_ete_heure_d_hiver_et_reciproquement/calcul_des_passages_heure_d_ete_heure_d_hiver_et_reciproquement.h"
#include "../src/bibliotheque_de_fonctions_utiles/bibliotheque_de_fonctions_utiles.h"

//Fonction de test des passages heure d'été <=> heure d'hiver, pour les zones géographques qui les comportes
//
int main(int argc, char* argv[])
{

	//Déclaration et afféctation de la variable timestamp_courant (grâce à la fonction time, qui prend NULL comme paramétre, indiquant qu'on veut le temps courant)
	time_t timestamp_courant = time(NULL);

	//Déclaration de la variable timestamp_courant_avec_annee_voulue qui représente le timestamp sur lequel on afféctera l'année voulue
	time_t timestamp_courant_avec_annee_voulue;

	//
	int annee_voulue = 2020;

	//
	time_t horaire_de_passage_a_l_heure_d_ete_pour_les_samoa_sous_forme_de_timestamp;
	time_t horaire_de_passage_a_l_heure_d_hiver_pour_les_samoa_sous_forme_de_timestamp;

	//
	char* horaire_de_passage_a_l_heure_d_ete_pour_les_samoa_sous_forme_de_chaine_de_caracteres;
	char* horaire_de_passage_a_l_heure_d_hiver_pour_les_samoa_sous_forme_de_chaine_de_caracteres;

	//
	timestamp_courant_avec_annee_voulue = fonction_de_precision_de_l_annee_en_cours(timestamp_courant, annee_voulue);

	//
	horaire_de_passage_a_l_heure_d_ete_pour_les_samoa_sous_forme_de_timestamp = date_du_dernier_dimanche_de_septembre(timestamp_courant_avec_annee_voulue);
	horaire_de_passage_a_l_heure_d_hiver_pour_les_samoa_sous_forme_de_timestamp = date_du_premier_dimanche_d_avril(timestamp_courant_avec_annee_voulue, 3);

	//
	horaire_de_passage_a_l_heure_d_ete_pour_les_samoa_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_ete_pour_les_samoa_sous_forme_de_timestamp);
	horaire_de_passage_a_l_heure_d_hiver_pour_les_samoa_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_hiver_pour_les_samoa_sous_forme_de_timestamp);

	//
	printf("Passage à l'heure d'été en %d pour l'État indépendant des Samoa: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_ete_pour_les_samoa_sous_forme_de_chaine_de_caracteres);
	printf("Passage à l'heure d'hiver en %d pour l'État indépendant des Samoa: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_hiver_pour_les_samoa_sous_forme_de_chaine_de_caracteres);

	//La fonction main retourne 0, signe que ce programme s'est exécuté sans probléme
	return 0;

}
