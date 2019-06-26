/* Inclusion des bibliothéques standards du C utilisées dans cette bibliothéque-ci */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Inclusion des bibliothéques internes à l'API */
#include "calcul_des_passages_heure_d_ete_heure_d_hiver_et_reciproquement.h"

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

	//Ici, le programme procéde à une boucle infinie
	while(1){

		//On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
		date_timestamp = date_timestamp - 86400;

		//La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
		date_tm = gmtime(&date_timestamp);

		//Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au dernier dimanche (tm_wday) du mois de Mars (tm_mon), on quitte définitivement la boucle
		if(date_tm->tm_wday == 0 && date_tm->tm_mon == 2)
		{
			break;
		}
	}

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

	//Ici, le programme procéde à une boucle infinie
        while(1){

		//On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp - 86400;

		//La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = gmtime(&date_timestamp);

		//Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au dernier dimanche (tm_wday) du mois d'Octobre (tm_mon), on quitte définitivement la boucle
		if(date_tm->tm_wday == 0 && date_tm->tm_mon == 9)
		{
			break;
		}
        }

	//On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
	return date_timestamp;
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

        //Définition d'une variable i qui va contenir le nombre de dimanche comptabilisé dans notre parcours du mois d'Avril
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

        //Ici, le programme procéde à une boucle infinie
        while(1){

                //Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au dernier dimanche (tm_wday) du mois d'Octobre (tm_mon), et que i est égal à 1 (on est au premier dimanche du mois d'Avril), on quitte définitivement la boucle
                if(date_tm->tm_wday == 0 && date_tm->tm_mon == 3 && i == 1)
                {
                        break;

		}
		else
		{
			//On affecte à la variable date_timestamp la somme entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                	date_timestamp = date_timestamp + 86400;

                	//La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                	date_tm = gmtime(&date_timestamp);

			//Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au premier dimanche (tm_wday) du mois d'Avril (tm_mon), la valeur contenue dans la variable i est augmentée de 1
                        if(date_tm->tm_wday == 0 && date_tm->tm_mon == 3)
                        {
                                i = i + 1;
                        }

                }
        }

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour l'Australie) à l'aide du timestamp passé en paramétre
time_t date_du_premier_dimanche_d_octobre(time_t aujourdhui)
{
        //Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) novembre (tm_mon) à 3 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 9;
        date_tm->tm_hour = 2;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

        //Définition d'une variable i qui va contenir le nombre de dimanche comptabilisé dans notre parcours du mois d'Octobre 
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

        //Ici, le programme procéde à une boucle infinie
        while(1){

                //Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au dernier dimanche (tm_wday) du mois d'Octobre (tm_mon), et que i est égal à 1 (on est au premier dimanche du mois d'Octobre ), on quitte définitivement la boucle
                if(date_tm->tm_wday == 0 && date_tm->tm_mon == 9 && i == 1)
                {
                        break;

		}
		else
		{
			//On affecte à la variable date_timestamp la somme entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                	date_timestamp = date_timestamp + 86400;

                	//La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                	date_tm = gmtime(&date_timestamp);

			//Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au premier dimanche (tm_wday) du mois d'Octobre (tm_mon), la valeur contenue dans la variable i est augmentée de 1
                        if(date_tm->tm_wday == 0 && date_tm->tm_mon == 9)
                        {
                                i = i + 1;
                        }

                }
        }

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver pour les USA à l'aide du timestamp
time_t date_du_premier_dimanche_de_novembre(time_t aujourdhui)
{
        //Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) novembre (tm_mon) à 2 heures (USA) ou 0 (Bresil) (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 10;
	date_tm->tm_hour = 2;
	date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

        //Définition d'une variable i qui va contenir le nombre de dimanche comptabilisé dans notre parcours du mois de novembre 
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

        //Ici, le programme procéde à une boucle infinie
        while(1){

                //Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au dernier dimanche (tm_wday) du mois d'Octobre (tm_mon), et que i est égal à 1 (on est au premier dimanche du mois de Novembre), on quitte définitivement la boucle
                if(date_tm->tm_wday == 0 && date_tm->tm_mon == 10 && i == 1)
                {
                        break;

		}
		else
		{
			//On affecte à la variable date_timestamp la somme entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                	date_timestamp = date_timestamp + 86400;

                	//La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                	date_tm = gmtime(&date_timestamp);

			//Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au premier dimanche (tm_wday) du mois de Novembre (tm_mon), la valeur contenue dans la variable i est augmentée de 1
                        if(date_tm->tm_wday == 0 && date_tm->tm_mon == 10)
                        {
                                i = i + 1;
                        }

                }
        }

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour les USA) à l'aide du timestamp passé en paramétre
time_t date_du_deuxieme_dimanche_de_mars(time_t aujourdhui)
{
        //Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) avril (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
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

        //Ici, le programme procéde à une boucle infinie
        while(1){

                //On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp + 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = gmtime(&date_timestamp);

                //Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au dernier dimanche (tm_wday) du mois de Mars (tm_mon) et que i = 1 (un dimanche du mois de mars est passé), on quitte définitivement la boucle
                if(date_tm->tm_wday == 0 && date_tm->tm_mon == 2 && i == 1)
                {
                        break;
                }
		//Dans le cas contraire
		else
		{
			//Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au dernier dimanche (tm_wday) du mois de Mars (tm_mon), la valeur contenue dans la variable i est incrementé de 1
			if(date_tm->tm_wday == 0 && date_tm->tm_mon == 2)
			{
				i = i + 1;
			}
		}
        }

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

        //Ici, le programme procéde à une boucle infinie
        while(1){

                //On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp + 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = gmtime(&date_timestamp);

                //Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au deuxieme dimanche (tm_wday) du mois de Mai (tm_mon) et que i = 1 (un dimanche du mois de Mai est passé), on quitte définitivement la boucle
                if(date_tm->tm_wday == 0 && date_tm->tm_mon == 4 && i == 1)
                {
                        break;
                }
		//Dans le cas contraire
		else
		{
			//Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au deuxieme dimanche (tm_wday) du mois de Mai (tm_mon), la valeur contenue dans la variable i est incrementé de 1
			if(date_tm->tm_wday == 0 && date_tm->tm_mon == 4)
			{
				i = i + 1;
			}
		}
        }

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

        //Ici, le programme procéde à une boucle infinie
        while(1){

                //On affecte à la variable date_timestamp la somme entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp + 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = gmtime(&date_timestamp);

                //Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au deuxieme dimanche (tm_wday) du mois d'Aout (tm_mon) et que i = 1 (un dimanche du mois de mars est passé), on quitte définitivement la boucle
                if(date_tm->tm_wday == 0 && date_tm->tm_mon == 7 && i == 1)
                {
                        break;
                }
		//Dans le cas contraire
		else
		{
			//Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au deuxieme dimanche (tm_wday) du mois de Aout (tm_mon), la valeur contenue dans la variable i est incrementé de 1
			if(date_tm->tm_wday == 0 && date_tm->tm_mon == 7)
			{
				i = i + 1;
			}
		}
        }

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour la Nouvelle-Zelande) à l'aide du timestamp passé en paramétre
time_t date_du_dernier_dimanche_de_septembre(time_t aujourdhui)
{
        //Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
        struct tm *date_tm;
        time_t date_timestamp;

        //la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
        date_tm = gmtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) octobre (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 9;
        date_tm->tm_hour = 2;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction timegm
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = timegm(date_tm);
        date_tm = gmtime(&date_timestamp);

        //Ici, le programme procéde à une boucle infinie
        while(1){

                //On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp - 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = gmtime(&date_timestamp);

                //Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au dernier dimanche (tm_wday) du mois de Septembre (tm_mon), on sort definitivement de la boucle
                if(date_tm->tm_wday == 0 && date_tm->tm_mon == 8)
                {
                        break;
                }
        }

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}
