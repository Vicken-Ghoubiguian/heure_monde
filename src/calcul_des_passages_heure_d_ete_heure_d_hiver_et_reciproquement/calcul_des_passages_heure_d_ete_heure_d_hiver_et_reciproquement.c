/* Inclusion des bibliothéques standards du C utilisées dans cette bibliothéque-ci */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Inclusion des bibliothéques internes à l'API */
#include "calcul_des_passages_heure_d_ete_heure_d_hiver_et_reciproquement.h"
#include "../bibliotheque_de_fonctions_utiles/bibliotheque_de_fonctions_utiles.h"

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour les Fidji) à l'aide du timestamp passé en paramétre
time_t date_du_changement_d_heure_d_hiver_pour_les_fidji(time_t aujourdhui)
{

	//Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'hiver
	struct tm *date_tm;
        struct tm *date_tm_du_20_janvier;
	struct tm *date_tm_du_10_janvier;
	time_t date_timestamp;
        time_t date_timestamp_incrementeur;
	time_t date_timestamp_du_20_janvier;
	time_t date_timestamp_du_10_janvier;
	
	//la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm_du_20_janvier = gmtime(&aujourdhui);

	//
        date_tm_du_20_janvier->tm_mday = 20;
        date_tm_du_20_janvier->tm_mon = 0;
        date_tm_du_20_janvier->tm_hour = 2;
        date_tm_du_20_janvier->tm_min = 0;
        date_tm_du_20_janvier->tm_sec = 0;

	//
        date_timestamp_du_20_janvier = timegm(date_tm_du_20_janvier);

	//la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm_du_10_janvier = gmtime(&aujourdhui);

	//
	date_tm_du_10_janvier->tm_mday = 10;
        date_tm_du_10_janvier->tm_mon = 0;
        date_tm_du_10_janvier->tm_hour = 2;
        date_tm_du_10_janvier->tm_min = 0;
        date_tm_du_10_janvier->tm_sec = 0;

	//
	date_timestamp_du_10_janvier = timegm(date_tm_du_10_janvier);

	//
	date_timestamp_incrementeur = date_timestamp_du_10_janvier;

	//
	while(date_timestamp_incrementeur < date_timestamp_du_20_janvier)
	{
		//
		date_tm = gmtime(&date_timestamp_incrementeur);

		//
		if(date_tm->tm_wday == 0)
		{
			//
			date_timestamp = date_timestamp_incrementeur;
		}

		//
		date_timestamp_incrementeur = date_timestamp_incrementeur + (24 * 3600);
	}

	//On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour le Brésil) à l'aide du timestamp passé en paramétre
time_t date_du_troisieme_dimanche_de_fevrier(time_t aujourdhui)
{
	//Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) fevrier (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 1;
        date_tm->tm_hour = 3;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
	date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

	//Définition d'une variable i qui va contenir le nombre de dimanche comptabilisé dans notre parcours du mois de mars 
	int i;

	//Si le jour de la semaine (renseignée par le champ tm_wday) est dimanche (valeur = 0), alors, la variable i est initialisée à la valeur 1
        if(date_tm->tm_wday == 0)
        {
                i = 1;
        }
        //Dans le cas contraire, la variable i est initialisée à la valeur 0
        else
        {
                i = 0;
        }

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

        //Ici, le programme procéde à une boucle de type do...while
	do
	{
		
		//On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp + 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = gmtime(&date_timestamp);

               	//Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond à un dimanche (tm_wday) dans le mois de Fevrier (tm_mon), la valeur contenue dans $
                if(date_tm->tm_wday == 0 && date_tm->tm_mon == 1)
              	{
                	i = i + 1;
                }

	//Tant que i est strictement inférieur à 3 (on en est pas encore au 3éme dimanche de février), on revient dans la boucle
	}while(i < 3);

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction retourne le niéme jour de la semaine dans un mois donnés en paramétre, calibré à l'heure passée en paramétre
time_t date_du_n_ieme_jour_de_la_semaine_donne_du_mois_donnee(time_t aujourdhui, int numero_voulu, int heure, int jour_de_la_semaine, int mois)
{
	//Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) fevrier (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = mois;
        date_tm->tm_hour = heure;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

        //Définition d'une variable i qui va contenir le nombre de dimanche comptabilisé dans notre parcours du mois passé en paramétre
        int i;

        //Si le jour de la semaine (renseignée par le champ tm_wday) correspond au jour de la semaine contenu dans la variable jour_de_la_semaine, alors, la variable i est initialisée à la valeur 1
        if(date_tm->tm_wday == jour_de_la_semaine)
        {
                i = 1;
        }
        //Dans le cas contraire, la variable i est initialisée à la valeur 0
        else
        {
                i = 0;
        }

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

	//Ici, le programme procéde à une boucle de type do...while
        do
        {

                //On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp + 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = gmtime(&date_timestamp);

                //Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond à un dimanche (tm_wday) dans le mois de Fevrier (tm_mon), la valeur contenue dans $
                if(date_tm->tm_wday == jour_de_la_semaine && date_tm->tm_mon == mois)
                {
                        i = i + 1;
                }

        //Tant que i est strictement inférieur au numéro voulu (on en est pas encore au numéro voulu-iéme jour de la semaine du mois donné), on revient dans la boucle
        }while(i < numero_voulu);

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction retourne le dernier jour de la semaine dans un mois donnés en paramétre, calibré à l'heure passée en paramétre
time_t date_du_dernier_jour_de_la_semaine_donne_du_mois_donnee(time_t aujourdhui, int heure, int jour_de_la_semaine, int mois)
{
	//Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

	//
	int mois_suivant = mois + 1;

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) mois + 1 (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = mois_suivant;
        date_tm->tm_hour = heure;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

	//Ici, le programme procéde à une boucle de type do...while
        do
        {

                //On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp - 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = gmtime(&date_timestamp);

        //Tant que date_tm->tm_wday est différent de la valeur contenue dans la variable jour_de_la_semaine, on revient dans la boucle
        }while(date_tm->tm_wday != jour_de_la_semaine);

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver (pour la Palestine) à l'aide du timestamp passé en paramétre
time_t date_du_dernier_samedi_d_octobre(time_t aujourdhui)
{
	//Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) novembre (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 10;
        date_tm->tm_hour = 1;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

	//Ici, le programme procéde à une boucle de type do...while
	do
	{

		//On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
		date_timestamp = date_timestamp - 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = gmtime(&date_timestamp);

	//Tant que date_tm->tm_wday est différent de 6 (samedi), on revient dans la boucle
	}while(date_tm->tm_wday != 6);

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour la Palestine) à l'aide du timestamp passé en paramétre
time_t date_du_dernier_samedi_de_mars(time_t aujourdhui)
{
	//Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) avril (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 3;
        date_tm->tm_hour = 1;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

	//Ici, le programme procéde à une boucle de type do...while
	do
	{

		//On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp - 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = gmtime(&date_timestamp);

	//Tant que date_tm->tm_wday est différent de 6 (samedi), on revient dans la boucle
	}while(date_tm->tm_wday != 6);

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour le Moyen-Orient) à l'aide du timestamp passé en paramétre
time_t date_du_dernier_vendredi_de_mars(time_t aujourdhui)
{
	//Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) avril (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 3;
        date_tm->tm_hour = 2;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

	//Ici, le programme procéde à une boucle de type do...while
	do
	{

		//On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp - 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = gmtime(&date_timestamp);

	//Tant que date_tm->tm_wday est différent de 5 (vendredi), on revient dans la boucle
	}while(date_tm->tm_wday != 5);

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver (pour l'Iran) à l'aide du timestamp passé en paramétre
time_t date_du_changement_d_heure_d_hiver_pour_l_iran(time_t aujourdhui)
{
	//Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'hiver
        struct tm *date_tm;
        time_t date_timestamp;
	int jour_dans_le_mois_pour_application_du_changement_d_heure;
	int annee_courante;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

	//
	annee_courante = date_tm->tm_year + 1900;

	//
	if(est_une_annee_bissextile_selon_le_calendrier_persan(annee_courante) || est_une_annee_qui_va_par_paire_de_quatre_selon_le_calendrier_persan(annee_courante))
	{
		//
		jour_dans_le_mois_pour_application_du_changement_d_heure = 21;
	}
	//Sinon...
	else
	{
		//
		jour_dans_le_mois_pour_application_du_changement_d_heure = 22;
	}

        //la structure date_tm est modifiée pour correspondre au 22 (tm_mday) septembre (tm_mon) à 0 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = jour_dans_le_mois_pour_application_du_changement_d_heure;
        date_tm->tm_mon = 8;
        date_tm->tm_hour = 0;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
	date_timestamp = timegm(date_tm);

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour l'Iran) à l'aide du timestamp passé en paramétre
time_t date_du_changement_d_heure_d_ete_pour_l_iran(time_t aujourdhui)
{
	//Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'hiver
        struct tm *date_tm;
        time_t date_timestamp;
	int jour_dans_le_mois_pour_application_du_changement_d_heure;
        int annee_courante;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

	//
        annee_courante = date_tm->tm_year + 1900;

        //
        if(est_une_annee_bissextile_selon_le_calendrier_persan(annee_courante) || est_une_annee_qui_va_par_paire_de_quatre_selon_le_calendrier_persan(annee_courante))
        {
                //
                jour_dans_le_mois_pour_application_du_changement_d_heure = 21;
        }
        //Sinon...
        else
        {
                //
                jour_dans_le_mois_pour_application_du_changement_d_heure = 22;
        }

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) mars (tm_mon) à 0 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = jour_dans_le_mois_pour_application_du_changement_d_heure;
        date_tm->tm_mon = 2;
        date_tm->tm_hour = 0;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
	date_timestamp = timegm(date_tm);

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver (pour le Moyen-Orient) à l'aide du timestamp passé en paramétre
time_t date_du_dernier_vendredi_d_octobre(time_t aujourdhui)
{
	//Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'hiver
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) novembre (tm_mon) à 3 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 10;
        date_tm->tm_hour = 3;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

	//Ici, le programme procéde à une boucle de type do...while
	do
	{

		//On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp - 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = gmtime(&date_timestamp);

	//Tant que date_tm->tm_wday est différent de 5 (vendredi), on revient dans la boucle
	}while(date_tm->tm_wday != 5);

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour le Moyen-Orient) à l'aide du timestamp passé en paramétre
time_t date_du_dernier_vendredi_de_mars_ou_du_premier_vendredi_d_avril(time_t aujourdhui)
{
	//Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) avril (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 3;
        date_tm->tm_hour = 2;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

	//Si la date générée à partir du 1er avril est un vendredi, alors...
	if(date_tm->tm_wday == 5)
	{
		//On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
		return date_timestamp;
	}
	//Sinon...
	else
	{
		//Ici, le programme procéde à une boucle de type do...while
		do
		{

			//On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                	date_timestamp = date_timestamp - 86400;

                	//La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                	date_tm = gmtime(&date_timestamp);

		//Tant que date_tm->tm_wday est différent de 5 (vendredi), on revient dans la boucle
		}while(date_tm->tm_wday != 5);

        	//On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        	return date_timestamp;
	}
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver (pour le Paraguay) à l'aide du timestamp passé en paramétre
time_t date_du_quatrieme_dimanche_de_mars(time_t aujourdhui, int heure)
{
        //Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'hiver
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) mars (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 2;
        date_tm->tm_hour = heure;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
	date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

	//Définition d'une variable i qui va contenir le nombre de dimanche comptabilisé dans notre parcours du mois de mars 
	int i;

	//Si le jour de la semaine (renseignée par le champ tm_wday) est dimanche (valeur = 0), alors, la variable i est initialisée à la valeur 1
        if(date_tm->tm_wday == 0)
        {
                i = 1;
        }
        //Dans le cas contraire, la variable i est initialisée à la valeur 0
        else
        {
                i = 0;
        }

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

        //Ici, le programme procéde à une boucle de type do...while
	do
	{

		//On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp + 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = gmtime(&date_timestamp);

                //Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond à un dimanche (tm_wday) dans le mois de Mars (tm_mon), la valeur contenue dans la $
                if(date_tm->tm_wday == 0 && date_tm->tm_mon == 2)
                {
                	i = i + 1;
                }

	//Tant que i est strictement inférieur à 4 (on en est pas encore au 4éme dimanche de dimanche), on revient dans la boucle
	}while(i < 4);

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}


//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour la Nouvelle-Zelande et les Samoa) à l'aide du timestamp et de l'heure (2 pour la Nouvelle-Zélande et 3 pour les Samoa) passés en paramétre
time_t date_du_dernier_dimanche_de_septembre(time_t aujourdhui, int heure)
{
        //Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) octobre (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 9;
        date_tm->tm_hour = heure;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

        //Ici, le programme procéde à une boucle de type do...while
       	do
	{

		//On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp - 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = gmtime(&date_timestamp);

	//Tant que date_tm->tm_wday est différent de 0 (dimanche), on revient dans la boucle
	}while(date_tm->tm_wday != 0);

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour les pays européens) à l'aide du timestamp et de l'heure (1 pour la Grande Bretagne et 2 pour la France) passé en paramétre
time_t date_du_dernier_dimanche_de_mars(time_t aujourdhui, int heure)
{
	//Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
	struct tm *date_tm;
	time_t date_timestamp;

	//la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
	date_tm = gmtime(&aujourdhui);

	//la structure date_tm est modifiée pour correspondre au 1er (tm_mday) avril (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
	date_tm->tm_mday = 1;
        date_tm->tm_mon = 3;
	date_tm->tm_hour = heure;
	date_tm->tm_min = 0;
	date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
	//Puis reconvertie en struct tm grace à la fonction localtime
	date_timestamp = timegm(date_tm);
	date_tm = gmtime(&date_timestamp);

	//Ici, le programme procéde à une boucle de type do...while
	do
	{

		//On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp - 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = gmtime(&date_timestamp);

	//Tant que date_tm->tm_wday est différent de 0 (dimanche), on revient dans la boucle
	}while(date_tm->tm_wday != 0);

	//On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
	return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver (pour les pays européens) à l'aide du timestamp et de l'heure (2 pour la Grande Bretagne et 3 pour la France) passé en paramétre
time_t date_du_dernier_dimanche_d_octobre(time_t aujourdhui, int heure)
{
	//Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

	//la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
	date_tm = gmtime(&aujourdhui);

	//la structure date_tm est modifiée pour correspondre au 1er (tm_mday) novembre (tm_mon) à 3 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 10;
	date_tm->tm_hour = heure;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

	//Ici, le programme procéde à une boucle de type do...while
	do
	{

		//On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp - 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = gmtime(&date_timestamp);

	//Tant que date_tm->tm_wday est différent de 0 (dimanche), on revient dans la boucle
	}while(date_tm->tm_wday != 0);

	//On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
	return date_timestamp;
}

//Cette fonction retourne le premier jour de la semaine dans un mois donnés en paramétre, calibré à l'heure passée en paramétre
time_t date_du_premier_jour_de_la_semaine_donne_du_mois_donne(time_t aujourdhui, int heure, int jour_de_la_semaine, int mois)
{
	//Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'hiver
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) du mois donné (tm_mon) de l'annee prochaine (tm_year) à l'heure donnée (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = mois;
        date_tm->tm_hour = heure;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//Si le jour de la semaine (renseignée par le champ tm_wday) correspond au jour de la semaine donné (valeur = jour_de_la_semaine), alors...
        if(date_tm->tm_wday == 0)
        {
                //On retourne la valeur de la variable date_timestamp
                return date_timestamp;
        }
        //Dans le cas contraire, sinon...
        else
        {
                //On procéde à une boucle do...while
                do
                {

                        //On affecte à la variable date_timestamp la somme entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                        date_timestamp = date_timestamp + 86400;

                        //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                        date_tm = gmtime(&date_timestamp);

                //Tant que date_tm->tm_wday est différent de la valeur contenue dans la variable jour_de_la_semaine, on revient dans la boucle
                }while(date_tm->tm_wday != jour_de_la_semaine);

                //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
                return date_timestamp;
        }
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver (pour l'Australie et la Nouvelle-Zélande) à l'aide du timestamp et de l'heure (2 pour l'Australie, 3 pour la Nouvelle-Zélande) passés en paramétres
time_t date_du_premier_dimanche_d_avril(time_t aujourdhui, int heure)
{
        //Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'hiver
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) avril (tm_mon) de l'annee prochaine (tm_year) à 3 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 3;
        date_tm->tm_hour = heure;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

        //Si le jour de la semaine (renseignée par le champ tm_wday) est dimanche (valeur = 0), alors...
        if(date_tm->tm_wday == 0)
        {
                //On retourne la valeur de la variable date_timestamp
		return date_timestamp;
        }
        //Dans le cas contraire, sinon...
        else
        {
                //On procéde à une boucle do...while
		do
		{

			//On affecte à la variable date_timestamp la somme entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                        date_timestamp = date_timestamp + 86400;

                        //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                        date_tm = gmtime(&date_timestamp);

		//Tant que date_tm->tm_wday est différent de 0 (dimanche), on revient dans la boucle
		}while(date_tm->tm_wday != 0);

		//On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
		return date_timestamp;
        }
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour l'Australie) à l'aide du timestamp passé en paramétre
time_t date_du_premier_dimanche_d_octobre(time_t aujourdhui, int heure)
{
        //Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) novembre (tm_mon) à 3 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 9;
        date_tm->tm_hour = heure;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

        //Définition d'une variable i qui va contenir le nombre de dimanche comptabilisé dans notre parcours du mois d'Octobre 
        //int i;

        //Si le jour de la semaine (renseignée par le champ tm_wday) est dimanche (valeur = 0), alors, on retourne la valeur contenue dans la variable date_timestamp
        if(date_tm->tm_wday == 0)
        {
                //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
		return date_timestamp;
        }
        //Sinon...
        else
        {
                //On procéde à une boucle do...while
		do
		{

			//On affecte à la variable date_timestamp la somme entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                        date_timestamp = date_timestamp + 86400;

                        //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                        date_tm = gmtime(&date_timestamp);

		//Tant que date_tm->tm_wday est différent de 0 (dimanche), on revient dans la boucle
		}while(date_tm->tm_wday != 0);

		//On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
		return date_timestamp;
        }
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver pour les USA à l'aide du timestamp
time_t date_du_premier_dimanche_de_novembre(time_t aujourdhui, int heure)
{
        //Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) novembre (tm_mon) à 2 heures (USA) ou 0 (Bresil) (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 10;
	date_tm->tm_hour = heure;
	date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

        //Définition d'une variable i qui va contenir le nombre de dimanche comptabilisé dans notre parcours du mois de novembre 
        int i;

        //Si le jour de la semaine (renseignée par le champ tm_wday) est dimanche (valeur = 0), alors on retourne la valeur contenue dans la variable date_timestamp
        if(date_tm->tm_wday == 0)
        {
                //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
		return date_timestamp;
        }
        //Dans le cas contraire, la variable i est initialisée à la valeur 0
        else
        {
                //On procéde à une boucle do...while
		do
		{
			//On affecte à la variable date_timestamp la somme entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                        date_timestamp = date_timestamp + 86400;

                        //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                        date_tm = gmtime(&date_timestamp);

		//Tant que date_tm->tm_wday est différent de 0 (dimanche), on revient dans la boucle
		}while(date_tm->tm_wday != 0);

		//On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
		return date_timestamp;
        }
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour les USA) à l'aide du timestamp passé en paramétre
time_t date_du_deuxieme_dimanche_de_mars(time_t aujourdhui)
{
        //Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) mars (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 2;
        date_tm->tm_hour = 2;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
	date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

	//Définition d'une variable i qui va contenir le nombre de dimanche comptabilisé dans notre parcours du mois de mars 
	int i;

	//Si le jour de la semaine (renseignée par le champ tm_wday) est dimanche (valeur = 0), alors, la variable i est initialisée à la valeur 1
	if(date_tm->tm_wday == 0)
	{
		i = 1;
	}
	//Dans le cas contraire, la variable i est initialisée à la valeur 0
	else
	{
		i = 0;
	}

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

        //Ici, le programme procéde à une boucle de type do...while
	do
	{

		//On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp + 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
               	date_tm = gmtime(&date_timestamp);

                //Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond à un dimanche (tm_wday) dans le mois de Mars (tm_mon), la valeur contenue dans la $
                if(date_tm->tm_wday == 0 && date_tm->tm_mon == 2)
              	{
                	i = i + 1;
		}

	//Tant que i est strictement inférieur à 2 (on en est pas encore au 2éme dimanche de mars), on revient dans la boucle
	}while(i < 2);

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver (pour le Chili) à l'aide du timestamp passé en paramétre
time_t date_du_deuxieme_dimanche_de_mai(time_t aujourdhui)
{
        //Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) mai (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 4;
        date_tm->tm_hour = 2;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
	date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

	//Définition d'une variable i qui va contenir le nombre de dimanche comptabilisé dans notre parcours du mois de Mai
	int i;

	//Si le jour de la semaine (renseignée par le champ tm_wday) est dimanche (valeur = 0), alors, la variable i est initialisée à la valeur 1
	if(date_tm->tm_wday == 0)
	{
		i = 1;
	}
	//Dans le cas contraire, la variable i est initialisée à la valeur 0
	else
	{
		i = 0;
	}

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

        //Ici, le programme procéde à une boucle de type do...while
	do
	{

		//On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
        	date_timestamp = date_timestamp + 86400;

         	//La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
              	date_tm = gmtime(&date_timestamp);

             	//Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au deuxieme dimanche (tm_wday) du mois de Mai (tm_mon), la valeur contenue dans la$
              	if(date_tm->tm_wday == 0 && date_tm->tm_mon == 4)
              	{
              		i = i + 1;
              	}

	//Tant que i est strictement inférieur à 2 (on en est pas encore au 2éme dimanche de mai), on revient dans la boucle
	}while(i < 2);

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour le Chili) à l'aide du timestamp passé en paramétre
time_t date_du_deuxieme_dimanche_d_aout(time_t aujourdhui)
{
        //Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) Aout (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 7;
        date_tm->tm_hour = 2;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
	date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

	//Définition d'une variable i qui va contenir le nombre de dimanche comptabilisé dans notre parcours du mois d'Aout
	int i;

	//Si le jour de la semaine (renseignée par le champ tm_wday) est dimanche (valeur = 0), alors, la variable i est initialisée à la valeur 1
	if(date_tm->tm_wday == 0)
	{
		i = 1;
	}
	//Dans le cas contraire, la variable i est initialisée à la valeur 0
	else
	{
		i = 0;
	}

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

        //Ici, le programme procéde à une boucle de type do...while
	do
	{

		//On affecte à la variable date_timestamp la somme entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
              	date_timestamp = date_timestamp + 86400;

           	//La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
             	date_tm = gmtime(&date_timestamp);

           	//Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au deuxieme dimanche (tm_wday) du mois de Aout (tm_mon), la valeur contenue dans l$
              	if(date_tm->tm_wday == 0 && date_tm->tm_mon == 7)
               	{
             		i = i + 1;
             	}

	//Tant que i est strictement inférieur à 2 (on en est pas encore au 2éme dimanche d'aout), on revient dans la boucle
	}while(i < 2);

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}
