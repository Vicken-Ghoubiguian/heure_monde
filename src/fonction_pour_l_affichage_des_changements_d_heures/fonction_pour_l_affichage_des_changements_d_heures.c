/* Inclusion des bibliothéques standards du C utilisées dans cette bibliothéque-ci */
#include <stdio.h>
#include <stdlib.h>

/* Inclusion des bibliothéques internes à l'API */
#include "../fonctions_d_affichage_et_de_renvoie_de_l_heure_et_de_la_date/fonctions_d_affichage_et_de_renvoie_de_l_heure_et_de_la_date.h"
#include "../calcul_des_passages_heure_d_ete_heure_d_hiver_et_reciproquement/calcul_des_passages_heure_d_ete_heure_d_hiver_et_reciproquement.h"
#include "../bibliotheque_de_fonctions_utiles/bibliotheque_de_fonctions_utiles.h"
#include "fonction_pour_l_affichage_des_changements_d_heures.h"

//Cette fonction permet d'afficher les changements d'heures heure d'été <=> heure d'hiver pour tous les pays et zones géographiques qui l'appliquent
void fonction_pour_l_affichage_des_changements_d_heures(int nombre_d_arguments_passes_en_parametre, char* liste_des_arguments_passes_en_parametre[])
{

	//Déclaration et afféctation de la variable timestamp_courant (grâce à la fonction time, qui prend NULL comme paramétre, indiquant qu'on veut le temps courant)
	time_t timestamp_courant = time(NULL);

	//Déclaration de la variable timestamp_courant_avec_annee_voulue qui représente le timestamp sur lequel on afféctera l'année voulue
	time_t timestamp_courant_avec_annee_voulue;

	//Déclaration de la variable annee_voulue qui contient l'année passée en argument du programme
	int annee_voulue;

	//Si le nombre d'arguments passé en paramétre est égal à 2, alors...
	if(nombre_d_arguments_passes_en_parametre == 2)
	{

		//Afféctation de la valeur en argument du programme représentant l'année en cours dans la variable annee_voulue, mais d'abord convertie sous forme de int grâce à la fonction atoi
		annee_voulue = atoi(liste_des_arguments_passes_en_parametre[1]);

	}
	//Sinon...
	else
	{
	
		//Afféctation de la valeur renvoyée par la fonction retour_de_l_annee_en_cours (année local en cours) dans la variable annee_voulue
		annee_voulue = retour_de_l_annee_en_cours();

	}

	//Si l'année voulue est strictement supérieur à 0, et donc si elle est valide par conséquent, alors...
	if(0 < annee_voulue)
	{

		//Déclaration des variables de changement d'heure heure d'été <=> heure d'hiver, pour toutes les zones géographique l'appliquant, sous forme de timestamp
		time_t horaire_de_passage_a_l_heure_d_ete_pour_les_samoa_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_hiver_pour_les_samoa_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_ete_pour_l_europe_continentale_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_hiver_pour_l_europe_continentale_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_ete_pour_la_base_antarctique_de_troll_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_hiver_pour_la_base_antarctique_de_troll_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_ete_pour_l_amerique_du_nord_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_hiver_pour_l_amerique_du_nord_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_ete_pour_la_grande_bretagne_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_hiver_pour_la_grande_bretagne_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_ete_pour_l_australie_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_hiver_pour_l_australie_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_ete_pour_la_nouvelle_zelande_et_la_base_antarctique_de_mcmurdo_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_hiver_pour_la_nouvelle_zelande_et_la_base_antarctique_de_mcmurdo_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_ete_pour_le_paraguay_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_hiver_pour_le_paraguay_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_ete_pour_la_jordanie_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_hiver_pour_la_jordanie_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_ete_pour_l_iran_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_hiver_pour_l_iran_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_ete_pour_le_liban_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_hiver_pour_le_liban_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_ete_pour_l_etat_d_israel_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_hiver_pour_l_etat_d_israel_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_ete_pour_la_syrie_sous_forme_de_timestamp;
                time_t horaire_de_passage_a_l_heure_d_hiver_pour_la_syrie_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_ete_pour_la_palestine_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_hiver_pour_la_palestine_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_ete_pour_le_bresil_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_hiver_pour_le_bresil_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_ete_pour_les_fidji_sous_forme_de_timestamp;
		time_t horaire_de_passage_a_l_heure_d_hiver_pour_les_fidji_sous_forme_de_timestamp;

		//Déclaration des variables de changement d'heure heure d'été <=> heure d'hiver, pour toutes les zones géographiques l'appliquant, sous forme de char*
		char* horaire_de_passage_a_l_heure_d_ete_pour_les_samoa_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_hiver_pour_les_samoa_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_ete_pour_l_europe_continentale_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_hiver_pour_l_europe_continentale_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_ete_pour_la_base_antarctique_de_troll_sous_forme_de_chaine_de_caracteres;
                char* horaire_de_passage_a_l_heure_d_hiver_pour_la_base_antarctique_de_troll_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_ete_pour_l_amerique_du_nord_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_hiver_pour_l_amerique_du_nord_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_ete_pour_la_grande_bretagne_sous_forme_de_chaine_de_caracteres;
                char* horaire_de_passage_a_l_heure_d_hiver_pour_la_grande_bretagne_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_ete_pour_l_australie_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_hiver_pour_l_australie_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_ete_pour_la_nouvelle_zelande_et_la_base_antarctique_de_mcmurdo_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_hiver_pour_la_nouvelle_zelande_et_la_base_antarctique_de_mcmurdo_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_ete_pour_le_paraguay_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_hiver_pour_le_paraguay_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_ete_pour_la_jordanie_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_hiver_pour_la_jordanie_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_ete_pour_l_iran_sous_forme_de_chaine_de_caractere;
		char* horaire_de_passage_a_l_heure_d_hiver_pour_l_iran_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_ete_pour_le_liban_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_hiver_pour_le_liban_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_ete_pour_l_etat_d_israel_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_hiver_pour_l_etat_d_israel_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_ete_pour_la_syrie_sous_forme_de_chaine_de_caracteres;
                char* horaire_de_passage_a_l_heure_d_hiver_pour_la_syrie_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_ete_pour_la_palestine_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_hiver_pour_la_palestine_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_ete_pour_le_bresil_sous_forme_de_chaine_de_caracteres;
                char* horaire_de_passage_a_l_heure_d_hiver_pour_le_bresil_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_ete_pour_les_fidji_sous_forme_de_chaine_de_caracteres;
		char* horaire_de_passage_a_l_heure_d_hiver_pour_les_fidji_sous_forme_de_chaine_de_caracteres;

		//Affectation de la valeur du timestamp du temps courant à l'année voulue
		timestamp_courant_avec_annee_voulue = fonction_de_precision_de_l_annee_en_cours(timestamp_courant, annee_voulue);

		//

		/* République des Fidji */
		horaire_de_passage_a_l_heure_d_ete_pour_les_fidji_sous_forme_de_timestamp = date_du_premier_dimanche_de_novembre(timestamp_courant_avec_annee_voulue, 3);
		horaire_de_passage_a_l_heure_d_hiver_pour_les_fidji_sous_forme_de_timestamp = date_du_changement_d_heure_d_hiver_pour_les_fidji(timestamp_courant_avec_annee_voulue);

		/* République fédérative du Brésil */
		horaire_de_passage_a_l_heure_d_ete_pour_le_bresil_sous_forme_de_timestamp = date_du_premier_dimanche_de_novembre(timestamp_courant_avec_annee_voulue, 3);
		horaire_de_passage_a_l_heure_d_hiver_pour_le_bresil_sous_forme_de_timestamp = date_du_n_ieme_jour_de_la_semaine_donne_du_mois_donnee(timestamp_courant_avec_annee_voulue, 3, 3, 0, 1);

		/* République arabe syrienne */
		horaire_de_passage_a_l_heure_d_ete_pour_la_syrie_sous_forme_de_timestamp = date_du_dernier_jour_de_la_semaine_donne_du_mois_donnee(timestamp_courant_avec_annee_voulue, 2, 5, 2);
		horaire_de_passage_a_l_heure_d_hiver_pour_la_syrie_sous_forme_de_timestamp = date_du_dernier_jour_de_la_semaine_donne_du_mois_donnee(timestamp_courant_avec_annee_voulue, 3, 5, 9);

		/* État d'Israël */
		horaire_de_passage_a_l_heure_d_ete_pour_l_etat_d_israel_sous_forme_de_timestamp = date_du_dernier_jour_de_la_semaine_donne_du_mois_donnee(timestamp_courant_avec_annee_voulue, 2, 5, 2);
		horaire_de_passage_a_l_heure_d_hiver_pour_l_etat_d_israel_sous_forme_de_timestamp = date_du_dernier_jour_de_la_semaine_donne_du_mois_donnee(timestamp_courant_avec_annee_voulue, 3, 0, 9);

		/* État de Palestine */
		horaire_de_passage_a_l_heure_d_ete_pour_la_palestine_sous_forme_de_timestamp = date_du_dernier_jour_de_la_semaine_donne_du_mois_donnee(timestamp_courant_avec_annee_voulue, 1, 6, 2);
		horaire_de_passage_a_l_heure_d_hiver_pour_la_palestine_sous_forme_de_timestamp = date_du_dernier_jour_de_la_semaine_donne_du_mois_donnee(timestamp_courant_avec_annee_voulue, 1, 6, 9);

		/* République libanaise */
		horaire_de_passage_a_l_heure_d_ete_pour_le_liban_sous_forme_de_timestamp = date_du_dernier_jour_de_la_semaine_donne_du_mois_donnee(timestamp_courant_avec_annee_voulue, 2, 0, 2);
		horaire_de_passage_a_l_heure_d_hiver_pour_le_liban_sous_forme_de_timestamp = date_du_dernier_jour_de_la_semaine_donne_du_mois_donnee(timestamp_courant_avec_annee_voulue, 3, 0, 9);

		/* République islamique d'Iran */
		horaire_de_passage_a_l_heure_d_ete_pour_l_iran_sous_forme_de_timestamp = date_du_changement_d_heure_d_ete_pour_l_iran(timestamp_courant_avec_annee_voulue);
		horaire_de_passage_a_l_heure_d_hiver_pour_l_iran_sous_forme_de_timestamp = date_du_changement_d_heure_d_hiver_pour_l_iran(timestamp_courant_avec_annee_voulue);

		/* Royaume hachémite de Jordanie */
		horaire_de_passage_a_l_heure_d_ete_pour_la_jordanie_sous_forme_de_timestamp = date_du_dernier_vendredi_de_mars_ou_du_premier_vendredi_d_avril(timestamp_courant_avec_annee_voulue);
		horaire_de_passage_a_l_heure_d_hiver_pour_la_jordanie_sous_forme_de_timestamp = date_du_dernier_jour_de_la_semaine_donne_du_mois_donnee(timestamp_courant_avec_annee_voulue, 3, 5, 9); 

		/* République du Paraguay */
		horaire_de_passage_a_l_heure_d_ete_pour_le_paraguay_sous_forme_de_timestamp = date_du_premier_dimanche_d_octobre(timestamp_courant_avec_annee_voulue, 0);
		horaire_de_passage_a_l_heure_d_hiver_pour_le_paraguay_sous_forme_de_timestamp = date_du_n_ieme_jour_de_la_semaine_donne_du_mois_donnee(timestamp_courant_avec_annee_voulue, 4, 0, 0, 2);

		/* Base antarctique de Troll */
		horaire_de_passage_a_l_heure_d_ete_pour_la_base_antarctique_de_troll_sous_forme_de_timestamp = date_du_dernier_jour_de_la_semaine_donne_du_mois_donnee(timestamp_courant_avec_annee_voulue, 1, 0, 2);
		horaire_de_passage_a_l_heure_d_hiver_pour_la_base_antarctique_de_troll_sous_forme_de_timestamp = date_du_dernier_jour_de_la_semaine_donne_du_mois_donnee(timestamp_courant_avec_annee_voulue, 3, 0, 9);

		/* Nouvelle-Zélande et Base antarctique de McMurdo */
		horaire_de_passage_a_l_heure_d_ete_pour_la_nouvelle_zelande_et_la_base_antarctique_de_mcmurdo_sous_forme_de_timestamp = date_du_dernier_jour_de_la_semaine_donne_du_mois_donnee(timestamp_courant_avec_annee_voulue, 2, 0, 8);
		horaire_de_passage_a_l_heure_d_hiver_pour_la_nouvelle_zelande_et_la_base_antarctique_de_mcmurdo_sous_forme_de_timestamp = date_du_premier_dimanche_d_avril(timestamp_courant_avec_annee_voulue, 3);

		/*  Commonwealth d'Australie */
		horaire_de_passage_a_l_heure_d_ete_pour_l_australie_sous_forme_de_timestamp = date_du_premier_dimanche_d_octobre(timestamp_courant_avec_annee_voulue, 2);
		horaire_de_passage_a_l_heure_d_hiver_pour_l_australie_sous_forme_de_timestamp = date_du_premier_dimanche_d_avril(timestamp_courant_avec_annee_voulue, 3);

		/* État indépendant des Samoa */
		horaire_de_passage_a_l_heure_d_ete_pour_les_samoa_sous_forme_de_timestamp = date_du_dernier_jour_de_la_semaine_donne_du_mois_donnee(timestamp_courant_avec_annee_voulue, 4, 0, 8);
		horaire_de_passage_a_l_heure_d_hiver_pour_les_samoa_sous_forme_de_timestamp = date_du_premier_dimanche_d_avril(timestamp_courant_avec_annee_voulue, 3);

		/* Europe continentale */
		horaire_de_passage_a_l_heure_d_ete_pour_l_europe_continentale_sous_forme_de_timestamp = date_du_dernier_jour_de_la_semaine_donne_du_mois_donnee(timestamp_courant_avec_annee_voulue, 3, 0, 2);
		horaire_de_passage_a_l_heure_d_hiver_pour_l_europe_continentale_sous_forme_de_timestamp = date_du_dernier_jour_de_la_semaine_donne_du_mois_donnee(timestamp_courant_avec_annee_voulue, 2, 0, 9);

		/* Royaume-Uni de Grande-Bretagne et d'Irlande du Nord */
		horaire_de_passage_a_l_heure_d_ete_pour_la_grande_bretagne_sous_forme_de_timestamp = date_du_dernier_jour_de_la_semaine_donne_du_mois_donnee(timestamp_courant_avec_annee_voulue, 1, 0, 2);
		horaire_de_passage_a_l_heure_d_hiver_pour_la_grande_bretagne_sous_forme_de_timestamp = date_du_dernier_jour_de_la_semaine_donne_du_mois_donnee(timestamp_courant_avec_annee_voulue, 2, 0, 9);

		/* Amérique du Nord */
		horaire_de_passage_a_l_heure_d_ete_pour_l_amerique_du_nord_sous_forme_de_timestamp = date_du_n_ieme_jour_de_la_semaine_donne_du_mois_donnee(timestamp_courant_avec_annee_voulue, 2, 2, 0, 2);
		horaire_de_passage_a_l_heure_d_hiver_pour_l_amerique_du_nord_sous_forme_de_timestamp = date_du_premier_dimanche_de_novembre(timestamp_courant_avec_annee_voulue, 2);

		//

		/* République des Fidji */
		horaire_de_passage_a_l_heure_d_ete_pour_les_fidji_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_ete_pour_les_fidji_sous_forme_de_timestamp);
		horaire_de_passage_a_l_heure_d_hiver_pour_les_fidji_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_hiver_pour_les_fidji_sous_forme_de_timestamp);

		/* République fédérative du Brésil */
		horaire_de_passage_a_l_heure_d_ete_pour_le_bresil_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_ete_pour_le_bresil_sous_forme_de_timestamp);
		horaire_de_passage_a_l_heure_d_hiver_pour_le_bresil_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_hiver_pour_le_bresil_sous_forme_de_timestamp);

		/* République arabe syrienne */
		horaire_de_passage_a_l_heure_d_ete_pour_la_syrie_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_ete_pour_la_syrie_sous_forme_de_timestamp);
		horaire_de_passage_a_l_heure_d_hiver_pour_la_syrie_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_hiver_pour_la_syrie_sous_forme_de_timestamp);

		/* État d'Israël */
		horaire_de_passage_a_l_heure_d_ete_pour_l_etat_d_israel_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_ete_pour_l_etat_d_israel_sous_forme_de_timestamp);
		horaire_de_passage_a_l_heure_d_hiver_pour_l_etat_d_israel_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_hiver_pour_l_etat_d_israel_sous_forme_de_timestamp);

		/* État de Palestine */
		horaire_de_passage_a_l_heure_d_ete_pour_la_palestine_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_ete_pour_la_palestine_sous_forme_de_timestamp);
		horaire_de_passage_a_l_heure_d_hiver_pour_la_palestine_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_hiver_pour_la_palestine_sous_forme_de_timestamp);

		/* République libanaise */
		horaire_de_passage_a_l_heure_d_ete_pour_le_liban_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_ete_pour_le_liban_sous_forme_de_timestamp);
		horaire_de_passage_a_l_heure_d_hiver_pour_le_liban_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_hiver_pour_le_liban_sous_forme_de_timestamp);

		/* République islamique d'Iran */
		horaire_de_passage_a_l_heure_d_ete_pour_l_iran_sous_forme_de_chaine_de_caractere = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_ete_pour_l_iran_sous_forme_de_timestamp);
		horaire_de_passage_a_l_heure_d_hiver_pour_l_iran_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_hiver_pour_l_iran_sous_forme_de_timestamp);

		/* Royaume hachémite de Jordanie */
		horaire_de_passage_a_l_heure_d_ete_pour_la_jordanie_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_ete_pour_la_jordanie_sous_forme_de_timestamp);
		horaire_de_passage_a_l_heure_d_hiver_pour_la_jordanie_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_hiver_pour_la_jordanie_sous_forme_de_timestamp);

		/* République du Paraguay */
		horaire_de_passage_a_l_heure_d_ete_pour_le_paraguay_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_ete_pour_le_paraguay_sous_forme_de_timestamp);
		horaire_de_passage_a_l_heure_d_hiver_pour_le_paraguay_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_hiver_pour_le_paraguay_sous_forme_de_timestamp);

		/* Base antarctique de Troll */
		horaire_de_passage_a_l_heure_d_ete_pour_la_base_antarctique_de_troll_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_ete_pour_la_base_antarctique_de_troll_sous_forme_de_timestamp);
		horaire_de_passage_a_l_heure_d_hiver_pour_la_base_antarctique_de_troll_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_hiver_pour_la_base_antarctique_de_troll_sous_forme_de_timestamp);

		/* Nouvelle-Zélande et Base antarctique de McMurdo */
		horaire_de_passage_a_l_heure_d_ete_pour_la_nouvelle_zelande_et_la_base_antarctique_de_mcmurdo_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_ete_pour_la_nouvelle_zelande_et_la_base_antarctique_de_mcmurdo_sous_forme_de_timestamp);
		horaire_de_passage_a_l_heure_d_hiver_pour_la_nouvelle_zelande_et_la_base_antarctique_de_mcmurdo_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_hiver_pour_la_nouvelle_zelande_et_la_base_antarctique_de_mcmurdo_sous_forme_de_timestamp);

		/* Commonwealth d'Australie */
		horaire_de_passage_a_l_heure_d_ete_pour_l_australie_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_ete_pour_l_australie_sous_forme_de_timestamp);
		horaire_de_passage_a_l_heure_d_hiver_pour_l_australie_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_hiver_pour_l_australie_sous_forme_de_timestamp);

		/* État indépendant des Samoa */
		horaire_de_passage_a_l_heure_d_ete_pour_les_samoa_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_ete_pour_les_samoa_sous_forme_de_timestamp);
		horaire_de_passage_a_l_heure_d_hiver_pour_les_samoa_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_hiver_pour_les_samoa_sous_forme_de_timestamp);

		/* Europe continentale */
		horaire_de_passage_a_l_heure_d_ete_pour_l_europe_continentale_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_ete_pour_l_europe_continentale_sous_forme_de_timestamp);
		horaire_de_passage_a_l_heure_d_hiver_pour_l_europe_continentale_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_hiver_pour_l_europe_continentale_sous_forme_de_timestamp);

		/* Royaume-Uni de Grande-Bretagne et d'Irlande du Nord */
		horaire_de_passage_a_l_heure_d_ete_pour_la_grande_bretagne_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_ete_pour_la_grande_bretagne_sous_forme_de_timestamp);
		horaire_de_passage_a_l_heure_d_hiver_pour_la_grande_bretagne_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_hiver_pour_la_grande_bretagne_sous_forme_de_timestamp);

		/* Amérique du Nord */
		horaire_de_passage_a_l_heure_d_ete_pour_l_amerique_du_nord_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_ete_pour_l_amerique_du_nord_sous_forme_de_timestamp);
		horaire_de_passage_a_l_heure_d_hiver_pour_l_amerique_du_nord_sous_forme_de_chaine_de_caracteres = calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(horaire_de_passage_a_l_heure_d_hiver_pour_l_amerique_du_nord_sous_forme_de_timestamp);

		//Affichage de tous les changements d'heure heure d'été <=> heure d'hiver pour l'année annee_voulue

		//
		printf("\n");

		//
		printf("République des Fidji:\n");
		printf("Passage à l'heure d'été en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_ete_pour_les_fidji_sous_forme_de_chaine_de_caracteres);
		printf("Passage à l'heure d'hiver en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_hiver_pour_les_fidji_sous_forme_de_chaine_de_caracteres);

		//
		printf("\n");
			
		//
		printf("République fédérative du Brésil:\n");
		printf("Passage à l'heure d'été en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_ete_pour_le_bresil_sous_forme_de_chaine_de_caracteres);
		printf("Passage à l'heure d'hiver en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_hiver_pour_le_bresil_sous_forme_de_chaine_de_caracteres);

		//
		printf("\n");

		//
		printf("République arabe syrienne:\n");
		printf("Passage à l'heure d'été en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_ete_pour_la_syrie_sous_forme_de_chaine_de_caracteres);
		printf("Passage à l'heure d'hiver en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_hiver_pour_la_syrie_sous_forme_de_chaine_de_caracteres);

		//
		printf("\n");

		//
		printf("État d'Israël:\n");
		printf("Passage à l'heure d'été en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_ete_pour_l_etat_d_israel_sous_forme_de_chaine_de_caracteres);
                printf("Passage à l'heure d'hiver en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_hiver_pour_l_etat_d_israel_sous_forme_de_chaine_de_caracteres);

		//
		printf("\n");

		//
		printf("État de Palestine:\n");
		printf("Passage à l'heure d'été en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_ete_pour_la_palestine_sous_forme_de_chaine_de_caracteres);
		printf("Passage à l'heure d'hiver en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_hiver_pour_la_palestine_sous_forme_de_chaine_de_caracteres);

		//
		printf("\n");

		//
		printf("République libanaise:\n");
		printf("Passage à l'heure d'été en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_ete_pour_le_liban_sous_forme_de_chaine_de_caracteres);
                printf("Passage à l'heure d'hiver en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_hiver_pour_le_liban_sous_forme_de_chaine_de_caracteres);

		//
		printf("\n");

		//
		printf("République islamique d'Iran:\n");
		printf("Passage à l'heure d'été en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_ete_pour_l_iran_sous_forme_de_chaine_de_caractere);
		printf("Passage à l'heure d'hiver en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_hiver_pour_l_iran_sous_forme_de_chaine_de_caracteres);

		//
		printf("\n");

		//
		printf("Royaume hachémite de Jordanie:\n");
		printf("Passage à l'heure d'été en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_ete_pour_la_jordanie_sous_forme_de_chaine_de_caracteres);
		printf("Passage à l'heure d'hiver en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_hiver_pour_la_jordanie_sous_forme_de_chaine_de_caracteres);

		//
		printf("\n");

		//
		printf("République du Paraguay:\n");
		printf("Passage à l'heure d'été en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_ete_pour_le_paraguay_sous_forme_de_chaine_de_caracteres);
		printf("Passage à l'heure d'hiver en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_hiver_pour_le_paraguay_sous_forme_de_chaine_de_caracteres);

		//
		printf("\n");

		//
		printf("Base antarctique de Troll:\n");
		printf("Passage à l'heure d'été en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_ete_pour_la_base_antarctique_de_troll_sous_forme_de_chaine_de_caracteres);
		printf("Passage à l'heure d'hiver en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_hiver_pour_la_base_antarctique_de_troll_sous_forme_de_chaine_de_caracteres);

		//
		printf("\n");

		//
		printf("Nouvelle-Zélande et Base antarctique de McMurdo:\n");
		printf("Passage à l'heure d'été en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_ete_pour_la_nouvelle_zelande_et_la_base_antarctique_de_mcmurdo_sous_forme_de_chaine_de_caracteres);
		printf("Passage à l'heure d'hiver en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_hiver_pour_la_nouvelle_zelande_et_la_base_antarctique_de_mcmurdo_sous_forme_de_chaine_de_caracteres);

		//
		printf("\n");

		//
		printf("Commonwealth d'Australie:\n");
		printf("Passage à l'heure d'été en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_ete_pour_l_australie_sous_forme_de_chaine_de_caracteres);
		printf("Passage à l'heure d'hiver en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_hiver_pour_l_australie_sous_forme_de_chaine_de_caracteres);

		//
		printf("\n");

		//
		printf("État indépendant des Samoa:\n");
		printf("Passage à l'heure d'été en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_ete_pour_les_samoa_sous_forme_de_chaine_de_caracteres);
		printf("Passage à l'heure d'hiver en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_hiver_pour_les_samoa_sous_forme_de_chaine_de_caracteres);

		//
		printf("\n");

		//
		printf("Europe continentale:\n");
		printf("Passage à l'heure d'été en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_ete_pour_l_europe_continentale_sous_forme_de_chaine_de_caracteres);
		printf("Passage à l'heure d'hiver en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_hiver_pour_l_europe_continentale_sous_forme_de_chaine_de_caracteres);

		//
		printf("\n");
		printf("Royaume-Uni de Grande-Bretagne et d'Irlande du Nord:\n");
		printf("Passage à l'heure d'été en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_ete_pour_la_grande_bretagne_sous_forme_de_chaine_de_caracteres);
                printf("Passage à l'heure d'hiver en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_hiver_pour_la_grande_bretagne_sous_forme_de_chaine_de_caracteres);

		//
		printf("\n");

		//
		printf("Amérique du Nord:\n");
		printf("Passage à l'heure d'été en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_ete_pour_l_amerique_du_nord_sous_forme_de_chaine_de_caracteres);
		printf("Passage à l'heure d'hiver en %d: %s\n", annee_voulue, horaire_de_passage_a_l_heure_d_hiver_pour_l_amerique_du_nord_sous_forme_de_chaine_de_caracteres);

		//
		printf("\n");

	}
	//Sinon...
	else
	{

		//Affichage d'un message d'avertissement en cas où l'année passée en argument du programme n'est pas valide
		printf("L'année passée en paramétre du programme éxecutable n'est pas valide.\n");

	}
}
