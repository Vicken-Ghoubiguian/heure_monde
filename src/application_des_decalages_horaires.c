#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "calcul_des_passages_heure_d_ete_heure_d_hiver_et_reciproquement.h"
#include "application_des_decalages_horaires.h"

//Cette fonction permet de déterminer si il faut (ou non) en fonction du changement d'heure ajouter une heure (ou non) pour le calcul des fuseaux horaires de Pekin, Tokyo, Seoul, Moscou, et Vladivostok
int application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(time_t date)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour prrocéder aux calculs
	time_t ete = date_du_dernier_dimanche_de_mars(date, 2);
	time_t hiver = date_du_dernier_dimanche_d_octobre(date, 3);

	//Ici, on vérifie (grace à des comparaison de valeurs entre timestamp) que la date se situe entre ete et hiver (inclus)
	//Si la date passée en paramétre se situe entre l'horaire de changement de l'heure d'été et celui de changement de l'heure d'hiver, 0 est retourné (il y à aucune heure à ajouter)
	if(date >= ete && date <= hiver)
	{
		return 0;
	}
	//Sinon, 1 est retourné (il faudra ajouter une heure)
	else
	{
		return 1;
	}
}

//Cette fonction permet de calculer le decallage horaire d'Auckland (Nouvelle-Zelande) avec l'heure française
int calcul_du_decalage_avec_auckland(time_t aujourdhui)
{
	//Définition des variables nécessaires au calcul du décalage
        time_t date_passage_heure_d_ete_europe = date_du_dernier_dimanche_de_mars(aujourdhui, 2);
        time_t date_passage_heure_d_hiver_europe = date_du_dernier_dimanche_d_octobre(aujourdhui, 3);
        time_t date_passage_heure_d_ete_nouvelle_zelande = date_du_dernier_dimanche_de_septembre(aujourdhui);
        time_t date_passage_heure_d_hiver_nouvelle_zelande = date_du_premier_dimanche_d_avril(aujourdhui, 3);

	//Calcul du décallage en fonction de l'interval de temps dans lequel est la valeur passée en paramétre
	if((aujourdhui >= date_passage_heure_d_ete_europe && aujourdhui < date_passage_heure_d_hiver_nouvelle_zelande) || (aujourdhui >= date_passage_heure_d_ete_nouvelle_zelande && aujourdhui < date_passage_heure_d_hiver_europe))
	{
		return 1;
	}
	else if(aujourdhui >= date_passage_heure_d_hiver_nouvelle_zelande && aujourdhui < date_passage_heure_d_ete_nouvelle_zelande)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

//Cette fonction permet de calculer le decallage horaire de l'Australie avec l'heure française
int calcul_du_decalage_avec_l_australie(time_t aujourdhui)
{
	//Définition des variables nécessaires au calcul du décalage
	time_t date_passage_heure_d_ete_europe = date_du_dernier_dimanche_de_mars(aujourdhui, 2);
	time_t date_passage_heure_d_hiver_europe = date_du_dernier_dimanche_d_octobre(aujourdhui, 3);
	time_t date_passage_heure_d_ete_australie = date_du_premier_dimanche_d_octobre(aujourdhui);
	time_t date_passage_heure_d_hiver_australie = date_du_premier_dimanche_d_avril(aujourdhui, 2);

	//Calcul du décalage en fonction de l'interval de temps dans lequel est la valeur passée en paramétre
	if((aujourdhui >= date_passage_heure_d_ete_europe && aujourdhui < date_passage_heure_d_hiver_australie) || (aujourdhui >= date_passage_heure_d_ete_australie && aujourdhui < date_passage_heure_d_hiver_europe))
	{
		return 1;
	}
	else if(aujourdhui >= date_passage_heure_d_hiver_australie && aujourdhui < date_passage_heure_d_ete_australie)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

//Cette fonction permet de calculer le decallage horaire de Santiago du Chili (Chili) avec l'heure française
int calcul_du_decalage_avec_le_chili(time_t aujourdhui)
{
	//Définition des variables nécessaires au calcul du décalage
	time_t date_passage_heure_d_ete_europe = date_du_dernier_dimanche_de_mars(aujourdhui, 2);
	time_t date_passage_heure_d_hiver_europe = date_du_dernier_dimanche_d_octobre(aujourdhui, 3);
	time_t date_passage_heure_d_ete_chili = date_du_deuxieme_dimanche_d_aout(aujourdhui);
	time_t date_passage_heure_d_hiver_chili = date_du_deuxieme_dimanche_de_mai(aujourdhui);

	//Calcul du décalage en fonction de l'interval de temps dans lequel est la valeur passée en paramétre
	if((aujourdhui >= date_passage_heure_d_ete_europe && aujourdhui < date_passage_heure_d_hiver_chili) || (aujourdhui >= date_passage_heure_d_ete_chili && aujourdhui < date_passage_heure_d_hiver_europe))
	{
		return 1;
	}
	else if(aujourdhui >= date_passage_heure_d_hiver_chili && aujourdhui < date_passage_heure_d_ete_chili && aujourdhui > date_passage_heure_d_ete_europe)
	{
		return 0;
	}
	else
	{
		return 2;
	}
}

//Cette fonction permet de calculer le decallage horaire de Los Angeles et de New York City (USA) avec l'heure française
int calcul_du_decalage_avec_l_amerique_du_nord(time_t aujourdhui)
{
	//Définition des variables nécessaires au calcul du décalage
	time_t date_passage_heure_d_ete_europe = date_du_dernier_dimanche_de_mars(aujourdhui, 2);
	time_t date_passage_heure_d_hiver_europe = date_du_dernier_dimanche_d_octobre(aujourdhui, 3);
	time_t date_passage_heure_d_ete_usa = date_du_deuxieme_dimanche_de_mars(aujourdhui);
	time_t date_passage_heure_d_hiver_usa = date_du_premier_dimanche_de_novembre(aujourdhui);

	//Calcul du décalage en fonction de l'interval de temps dans lequel est la valeur passée en paramétre
	if((aujourdhui >= date_passage_heure_d_ete_usa && aujourdhui < date_passage_heure_d_ete_europe) || (aujourdhui >= date_passage_heure_d_hiver_europe && aujourdhui < date_passage_heure_d_hiver_usa))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Cette fonction permet de calculer le decallage horaire de Londres avec l'heure française
int calcul_du_decallage_avec_la_grande_bretagne(time_t aujourdhui)
{
	//Définition des variables nécessaires au calcul du décalage
        time_t date_passage_heure_d_ete_france = date_du_dernier_dimanche_de_mars(aujourdhui, 2);
        time_t date_passage_heure_d_hiver_france = date_du_dernier_dimanche_d_octobre(aujourdhui, 3);
	time_t date_passage_heure_d_ete_uk = date_du_dernier_dimanche_de_mars(aujourdhui, 1);
	time_t date_passage_heure_d_hiver_uk = date_du_dernier_dimanche_d_octobre(aujourdhui, 2);

	//Calcul du décalage en fonction de l'interval de temps dans lequel est la valeur passée en paramétre
	if(((aujourdhui > date_passage_heure_d_ete_uk) && (aujourdhui < date_passage_heure_d_ete_france)) || ((aujourdhui > date_passage_heure_d_hiver_uk) && (aujourdhui < date_passage_heure_d_hiver_france)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
