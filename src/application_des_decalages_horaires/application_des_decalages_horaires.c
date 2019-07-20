/* Inclusion des bibliothéques standards du C utilisées dans cette bibliothéque-ci */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Inclusion des bibliothéques internes à l'API */
#include "../calcul_des_passages_heure_d_ete_heure_d_hiver_et_reciproquement/calcul_des_passages_heure_d_ete_heure_d_hiver_et_reciproquement.h"
#include "application_des_decalages_horaires.h"

//Cette fonction permet d'appliquer le changement d'heure pour le Brésil
int application_du_changement_d_heure_pour_le_bresil(time_t temps_courant)
{
        //On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
        time_t ete = date_du_premier_dimanche_de_novembre(temps_courant);
        time_t hiver = date_du_troisieme_dimanche_de_fevrier(temps_courant);

        //
        if(hiver <= temps_courant && temps_courant < ete)
        {
                //On retourne 0
                return 0;
        }
        //Sinon...
        else
        {
                //On retourne 1
                return 1;
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour la Syrie
int application_du_changement_d_heure_pour_la_syrie(time_t temps_courant)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
        time_t ete = date_du_dernier_vendredi_de_mars(temps_courant);
        time_t hiver = date_du_dernier_vendredi_d_octobre(temps_courant);

	//
        if(temps_courant >= ete && temps_courant <= hiver)
        {
                //On retourne 1
                return 1;
        }
        //Sinon...
        else
        {
                //On retourne 0
                return 0;
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour la Palestine
int application_du_changement_d_heure_pour_la_palestine(time_t temps_courant)
{
        //On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
        time_t ete = date_du_dernier_samedi_de_mars(temps_courant);
        time_t hiver = date_du_dernier_samedi_d_octobre(temps_courant);

        //
        if(temps_courant >= ete && temps_courant <= hiver)
        {
                //On retourne 1
                return 1;
        }
        //Sinon...
        else
        {
                //On retourne 0
                return 0;
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour Israel
int application_du_changement_d_heure_pour_israel(time_t temps_courant)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
        time_t ete = date_du_dernier_vendredi_de_mars(temps_courant);
        time_t hiver = date_du_dernier_dimanche_d_octobre(temps_courant, 3);

        //
        if(temps_courant >= ete && temps_courant <= hiver)
        {
                //On retourne 1
                return 1;
        }
        //Sinon...
        else
        {
                //On retourne 0
                return 0;
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour le Liban
int application_du_changement_d_heure_pour_le_liban(time_t temps_courant)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
        time_t ete = date_du_dernier_dimanche_de_mars(temps_courant, 2);
        time_t hiver = date_du_dernier_dimanche_d_octobre(temps_courant, 3);

	//
	if(temps_courant >= ete && temps_courant <= hiver)
        {
                //On retourne 1
                return 1;
        }
        //Sinon...
        else
        {
                //On retourne 0
                return 0;
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour l'Iran
int application_du_changement_d_heure_pour_l_iran(time_t temps_courant)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
        time_t ete = date_du_changement_d_heure_d_ete_pour_l_iran(temps_courant);
        time_t hiver = date_du_changement_d_heure_d_hiver_pour_l_iran(temps_courant);

        //
        if(temps_courant >= ete && temps_courant <= hiver)
        {
                //On retourne 1
                return 1;
        }
        //Sinon...
        else
        {
                //On retourne 0
                return 0;
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour la Jordanie
int application_du_changement_d_heure_pour_la_jordanie(time_t temps_courant)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
	time_t ete = date_du_dernier_vendredi_de_mars_ou_du_premier_vendredi_d_avril(temps_courant);
	time_t hiver = date_du_dernier_vendredi_d_octobre(temps_courant);

	//
        if(temps_courant >= ete && temps_courant <= hiver)
        {
                //On retourne 1
                return 1;
        }
        //Sinon...
        else
        {
                //On retourne 0
                return 0;
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour le Paraguay
int application_du_changement_d_heure_pour_le_paraguay(time_t temps_courant)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
        time_t ete = date_du_premier_dimanche_d_octobre(temps_courant, 0);
        time_t hiver = date_du_quatrieme_dimanche_de_mars(temps_courant, 0);

        //
        if(hiver <= temps_courant && temps_courant < ete)
        {
                //On retourne 0
                return 0;
        }
        //Sinon...
        else
        {
                //On retourne 1
                return 1;
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour la base antarctique de Troll
int application_du_changement_d_heure_pour_la_base_antarctique_de_troll(time_t temps_courant)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
	time_t ete = date_du_dernier_dimanche_de_mars(temps_courant, 1);
	time_t hiver = date_du_dernier_dimanche_d_octobre(temps_courant, 3);

	//
	if(temps_courant >= ete && temps_courant <= hiver)
	{
		//On retourne 2
		return 2;
	}
	//Sinon...
	else
	{
		//On retourne 0
		return 0;	
	}
}

//Cette fonction permet d'appliquer le changement d'heure pour les Samoa
int application_du_changement_d_heure_pour_les_samoa(time_t temps_courant)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
	time_t ete = date_du_dernier_dimanche_de_septembre(temps_courant, 3);
	time_t hiver = date_du_premier_dimanche_d_avril(temps_courant, 4);

	//
        if(hiver <= temps_courant && temps_courant < ete)
        {
                //On retourne 0
                return 0;
        }
        //Sinon...
        else
        {
                //On retourne 1
                return 1;
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour l'Australie
int application_du_changement_d_heure_pour_l_australie(time_t temps_courant)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
	time_t ete = date_du_premier_dimanche_d_octobre(temps_courant, 2);
	time_t hiver = date_du_premier_dimanche_d_avril(temps_courant, 3);

	//
	if(hiver <= temps_courant && temps_courant < ete)
	{
		//On retourne 0
		return 0;
	}
	//Sinon...
	else
	{
		//On retourne 1
		return 1;
	}
}

//Cette fonction permet d'appliquer le changement d'heure pour le cas particulier de Lord Howe (en Australie)
int application_du_changement_d_heure_pour_le_cas_particulier_de_lord_howe(time_t temps_courant)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
        time_t ete = date_du_premier_dimanche_d_octobre(temps_courant, 2);
        time_t hiver = date_du_premier_dimanche_d_avril(temps_courant, 2);

        //
        if(hiver <= temps_courant && temps_courant < ete)
        {
		//On retourne 0
                return 0;
        }
        //Sinon...
        else
        {
                //On retourne 1800 (nombre de secondes correspondant à l'application du changement d'heure pour lord howe, ce qui correspond à 30 minutes)
                return 1800;
        }
}

//Cette fonction permet d'appliquer le changement d'heure pour la Nouvelle Zelande
int application_du_changement_d_heure_pour_la_nouvelle_zelande(time_t temps_courant)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
	time_t ete = date_du_dernier_dimanche_de_septembre(temps_courant, 2);
	time_t hiver = date_du_premier_dimanche_d_avril(temps_courant, 3);

	//
	if(hiver <= temps_courant && temps_courant < ete)
	{
		//On retourne 0
		return 0;
	}
	//Sinon...
	else
	{
		//On retourne 1
		return 1;
	}
}

//Cette fonction permet d'appliquer le changement d'heure pour le Chili
int application_du_changement_d_heure_pour_le_chili(time_t temps_courant)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
	time_t ete = date_du_deuxieme_dimanche_d_aout(temps_courant);
	time_t hiver = date_du_dernier_dimanche_d_octobre(temps_courant, 3);

	//
	if(temps_courant < ete && temps_courant > hiver)
	{
		//On retourne 1
		return 1;
	}
	//Sinon...
	else
	{
		//On retourne 0
		return 0;
	}
}

//Cette fonction permet d'appliquer le changement d'heure pour l'Amérique du Nord
int application_du_changement_d_heure_pour_l_amerique_du_nord(time_t temps_courant)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
	time_t ete = date_du_deuxieme_dimanche_de_mars(temps_courant);
	time_t hiver = date_du_premier_dimanche_de_novembre(temps_courant);

	//
	if(temps_courant >= ete && temps_courant <= hiver)
	{
		//On retourne 1
		return 1;
	}
	//Sinon...
	else
	{
		//On retourne 0
		return 0;
	}
}

//Cette fonction permet d'appliquer le changement d'heure pour la Grande Bretagne
int application_du_changement_d_heure_pour_la_grande_bretagne(time_t temps_courant)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
	time_t ete = date_du_dernier_dimanche_de_mars(temps_courant, 1);
	time_t hiver = date_du_dernier_dimanche_d_octobre(temps_courant, 2);

	//
	if(temps_courant >= ete && temps_courant <= hiver)
	{
		//On retourne 1
		return 1;
	}
	//Sinon...
	else
	{
		//On retourne 0
		return 0;
	}
}

//Cette fonction permet d'appliquer le changement d'heure pour l'Europe continentale
int application_du_changement_d_heure_pour_l_europe_continentale(time_t temps_courant)
{
	//On calcul l'horaire de changement de l'heure d'été et de changement de l'heure d'hiver, et on stocke ces valeurs dans des variables de type time_t (timestamp) pour procéder aux calculs
	time_t ete = date_du_dernier_dimanche_de_mars(temps_courant, 2);
	time_t hiver = date_du_dernier_dimanche_d_octobre(temps_courant, 3);

	//
	if(temps_courant >= ete && temps_courant <= hiver)
	{
		//On retourne 1
		return 1;
	}
	//Sinon...
	else
	{
		//On retourne 0
		return 0;
	}
}

