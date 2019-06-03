#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "heure_monde.h"

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour les pays européens) à l'aide du timestamp et de l'heure (1 pour la Grande Bretagne et 2 pour la France) passé en paramétre
time_t date_du_dernier_dimanche_de_mars(time_t aujourdhui, int heure)
{
	//Déclaration des variables necessaires au calcul de l'horaire de changement d'heure d'été
	struct tm *date_tm;
	time_t date_timestamp;

	//la valeur contenue dans la variable aujourdhui (passée en paramétre) est convertie de timestamp (type time_t) en structure tm (struct tm) grace à la fonction localtime
	date_tm = localtime(&aujourdhui);

	//la structure date_tm est modifiée pour correspondre au 1er (tm_mday) avril (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
	date_tm->tm_mday = 1;
        date_tm->tm_mon = 3;
	date_tm->tm_hour = heure;
	date_tm->tm_min = 0;
	date_tm->tm_sec = 0;
	
	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
	//Puis reconvertie en struct tm grace à la fonction localtime
	date_timestamp = mktime(date_tm);
	date_tm = localtime(&date_timestamp);
	
	//Ici, le programme procéde à une boucle infinie
	while(1){
		
		//On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
		date_timestamp = date_timestamp - 86400;

		//La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
		date_tm = localtime(&date_timestamp);

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
	date_tm = localtime(&aujourdhui);

	//la structure date_tm est modifiée pour correspondre au 1er (tm_mday) novembre (tm_mon) à 3 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 10;
	date_tm->tm_hour = heure;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

	//Ici, le programme procéde à une boucle infinie
        while(1){
		
		//On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp - 86400;

		//La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = localtime(&date_timestamp);
                
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
        date_tm = localtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) avril (tm_mon) de l'annee prochaine (tm_year) à 3 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 3;
        date_tm->tm_hour = heure;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

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

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

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
                	date_tm = localtime(&date_timestamp);

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
        date_tm = localtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) novembre (tm_mon) à 3 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 9;
        date_tm->tm_hour = 2;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

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

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

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
                	date_tm = localtime(&date_timestamp);

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
        date_tm = localtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) novembre (tm_mon) à 2 heures (USA) ou 0 (Bresil) (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 10;
	date_tm->tm_hour = 2;
	date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

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

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

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
                	date_tm = localtime(&date_timestamp);

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
        date_tm = localtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) avril (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 2;
        date_tm->tm_hour = 2;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
	date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

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

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

        //Ici, le programme procéde à une boucle infinie
        while(1){

                //On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp + 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = localtime(&date_timestamp);

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
        date_tm = localtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) mai (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 4;
        date_tm->tm_hour = 2;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
	date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

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

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

        //Ici, le programme procéde à une boucle infinie
        while(1){

                //On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp + 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = localtime(&date_timestamp);

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
        date_tm = localtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) Aout (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 7;
        date_tm->tm_hour = 2;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

	//la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
	date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

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

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

        //Ici, le programme procéde à une boucle infinie
        while(1){

                //On affecte à la variable date_timestamp la somme entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp + 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = localtime(&date_timestamp);

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
        date_tm = localtime(&aujourdhui);

        //la structure date_tm est modifiée pour correspondre au 1er (tm_mday) octobre (tm_mon) à 2 heures (tm_hour) 0 minutes (tm_min) et 0 secondes (tm_sec)
        date_tm->tm_mday = 1;
        date_tm->tm_mon = 9;
        date_tm->tm_hour = 2;
        date_tm->tm_min = 0;
        date_tm->tm_sec = 0;

        //la valeur contenue dans la structure date_tm (de type struct tm) est reconvertie en timestamp (time_t) grace à la fonction mktime
        //Puis reconvertie en struct tm grace à la fonction localtime
        date_timestamp = mktime(date_tm);
        date_tm = localtime(&date_timestamp);

        //Ici, le programme procéde à une boucle infinie
        while(1){

                //On affecte à la variable date_timestamp la différence entre la précédente valeur contenue dans date_timestamp et le nombre de secondes dans une journée (86400)
                date_timestamp = date_timestamp - 86400;

                //La valeur contenue dans la variable date_timestamp (time_t) est affectée à la variable date_tm (struct tm) par une conversion grace à la fonction localtime
                date_tm = localtime(&date_timestamp);

                //Si la date contenue dans la variable date_tm (struct tm) et date_timestamp (time_t) correspond au dernier dimanche (tm_wday) du mois de Septembre (tm_mon), on sort definitivement de la boucle
                if(date_tm->tm_wday == 0 && date_tm->tm_mon == 8)
                {
                        break;
                }
        }

        //On retourne alors le resultat obtenu sous forme d'un timestamp (time_t)
        return date_timestamp;
}

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

//Cette fonction permet de calculer le decallage horaire de Wellington (Nouvelle-Zelande) avec l'heure française
int calcul_du_decalage_avec_wellington(time_t aujourdhui)
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

//Cette fonction permet de calculer le decallage horaire de Canberra (Australie) avec l'heure française
int calcul_du_decalage_avec_canberra(time_t aujourdhui)
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

//Cette fonction permet de calculer et d'afficher les horaires d'une ville passée en paramétre
void calcul_et_affichage_horaire(time_t temps, char* ville)
{
	//Declaration des variables
	struct tm *horaire = localtime(&temps);
	char* jour_semaine;
	char* mois;
	char heure_a_convertir_en_str[5];
	char minute_a_convertir_en_str[5];
	char seconde_a_convertir_en_str[5];
	char jour_dans_le_mois_a_convertir_en_str[5];

	//Definition du mois en court en fonction du champs tm_mon de la structure tm
	switch(horaire->tm_mon)
	{
		case 0: mois = "Janvier"; break;
		case 1: mois = "Fevrier"; break;
		case 2: mois = "Mars"; break;
		case 3: mois = "Avril"; break;
		case 4: mois = "Mai"; break;
		case 5: mois = "Juin"; break;
		case 6: mois = "Juillet"; break;
		case 7: mois = "Aout"; break;
		case 8: mois = "Septembre"; break;
		case 9: mois = "Octobre"; break;
		case 10: mois = "Novembre"; break;
		case 11: mois = "Decembre"; break;
	}	

	//Definition du jour de la semaine en fonction du champs tm_wday de la structure tm
	switch(horaire->tm_wday)
	{
		case 0: jour_semaine = "Dimanche"; break;
		case 1: jour_semaine = "Lundi"; break;
		case 2: jour_semaine = "Mardi"; break;
		case 3: jour_semaine = "Mercredi"; break;
		case 4: jour_semaine = "Jeudi"; break;
		case 5: jour_semaine = "Vendredi"; break;
		case 6: jour_semaine = "Samedi"; break;
	}

	//
	if(horaire->tm_hour < 10)
	{
		//
		sprintf(heure_a_convertir_en_str, "%02d", horaire->tm_hour);
	}
	//Sinon...
	else
	{
		//
		sprintf(heure_a_convertir_en_str, "%d", horaire->tm_hour);
	}

	//
	if(horaire->tm_min < 10)
	{
		//
		sprintf(minute_a_convertir_en_str, "%02d", horaire->tm_min);
	}
	//Sinon...
	else
	{
		//
		sprintf(minute_a_convertir_en_str, "%d", horaire->tm_min);
	}

	//
	if(horaire->tm_sec < 10)
	{
		//
		sprintf(seconde_a_convertir_en_str, "%02d", horaire->tm_sec);
	}
	//Sinon...
	else
	{
		//
		sprintf(seconde_a_convertir_en_str, "%d", horaire->tm_sec);
	}

	//
	if(horaire->tm_mday < 10)
	{
		//
		sprintf(jour_dans_le_mois_a_convertir_en_str, "%02d", horaire->tm_mday);
	}
	//Sinon...
	else
	{
		//
		sprintf(jour_dans_le_mois_a_convertir_en_str, "%d", horaire->tm_mday);
	}

	//Affichage de l'horaire
	printf("%s : %s:%s:%s - %s %s %s %d.\n",
		ville, heure_a_convertir_en_str, minute_a_convertir_en_str, seconde_a_convertir_en_str,
		jour_semaine, jour_dans_le_mois_a_convertir_en_str, mois, horaire->tm_year + 1900);
}

//Fonction de test pour les calculs d'horaires mises au point dans le fichier heure_monde.c
void affichage_de_l_horloge(time_t temps_courant)
{
	/*Calcul des horaires de différents villes du monde et affectation de la valeur calculée à une variable correspondante*/

	/* États-Unis d'Amérique */
        time_t heure_los_angeles = temps_courant - ((9 - calcul_du_decalage_avec_l_amerique_du_nord(temps_courant)) * 3600); //Los Angeles
        time_t heure_de_nyc = temps_courant - ((6 - calcul_du_decalage_avec_l_amerique_du_nord(temps_courant)) * 3600); //New York City
        time_t heure_d_ottawa = temps_courant - ((6 - calcul_du_decalage_avec_l_amerique_du_nord(temps_courant)) * 3600); //Ottawa
        time_t heure_de_phoenix = temps_courant - ((9 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Phoenix

	/* République du Nicaragua */
	time_t heure_managua = temps_courant - ((8 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Managua

	/* Confédération suisse */
	time_t heure_zurich = temps_courant;

	/* République de Malte */
	time_t heure_malte = temps_courant;

	/* Principauté d'Andorre */
	time_t heure_andorre = temps_courant;

	/* Principauté de Liechtenstein */
	time_t heure_vaduz = temps_courant;

	/* République hellénique */
	time_t heure_d_athenes = temps_courant + 3600; //Athènes

	/* Royaume-Uni de Grande-Bretagne et d'Irlande du Nord */
	time_t heure_de_londres = temps_courant - ((1 - calcul_du_decallage_avec_la_grande_bretagne(temps_courant)) * 3600); //Londres

	/* Commonwealth d'Australie */
        time_t heure_canberra = temps_courant + ((10 - calcul_du_decalage_avec_canberra(temps_courant)) * 3600); //Canberra

	/* République du Chili */
        time_t heure_santiago_chili = temps_courant - ((6 - calcul_du_decalage_avec_le_chili(temps_courant)) * 3600); //Santiago du Chili

	/* République algérienne démocratique et populaire */
	time_t heure_a_alger = temps_courant - ((1 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Alger

	/* République d'Afrique du Sud */
        time_t heure_johannesburg = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Johannesburg

	/* République de Namibie */
        time_t heure_windhoek = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Windhoek

	/* État de Libye */
	time_t heure_tripoli = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Tripoli

	/* État d'Érythrée */
	time_t heure_a_asmara = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Asmara

	/* République fédérale de Somalie */
	time_t heure_a_mogadiscio = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Mogadiscio

	/* République démocratique fédérale d’Éthiopie */
	time_t heure_addis_abeba = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Addis-Abeba

	/* République de Djibouti */
	time_t heure_djibouti = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Djibouti

	/* République du Congo */
	time_t heure_a_brazzaville = temps_courant - ((1 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Brazzaville

	/* République démocratique du Congo */
	time_t heure_a_kinshasa = temps_courant - ((1 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Kinshasa
	time_t heure_a_lubumbashi = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Lubumbashi

	/* République unie de Tanzanie */
	time_t heure_a_dar_es_salam = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Dar_es_Salam

	/* République du Kenya */
	time_t heure_a_nairobi = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Nairobi

	/* République de Zambie */
	time_t heure_lusaka = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Lusaka

	/* République arabe d'Égypte */
	time_t heure_le_caire = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Le Caire

	/* République de Zimbabwe */
	time_t heure_harare = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Harare

	/* Nouvelle-Zélande */
	time_t heure_wellington = temps_courant + ((12 -  calcul_du_decalage_avec_wellington(temps_courant)) * 3600); //Wellington

	/* République argentine */
        time_t heure_buenos_aires = temps_courant - ((5 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Buenos Aires

	/* République de Madagascar */
        time_t heure_antananarivo = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Antananarivo

	/* République du Pérou */
        time_t heure_lima = temps_courant - ((7 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Lima

	/* État du Qatar */
	time_t heure_au_qatar = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Qatar

	/* République du Yémen */
	time_t heure_a_aden = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Aden

	/* République d'Ouzbékistan */
	time_t heure_a_tachkent = temps_courant + ((3 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Tachkent
	time_t heure_a_samarkand = temps_courant + ((3 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Samarkand

	/* République du Tadjikistan */
	time_t heure_a_douchanbe = temps_courant + ((3 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Douchanbé

	/* République kirghize */
	time_t heure_a_bichkek = temps_courant + ((4 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Bichkek

	/* République démocratique fédérale du Népal */
	time_t heure_a_katmandou = temps_courant + (45 * 60) + ((3 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Katmandou

	/* République islamique d'Afghanistan */
	time_t heure_a_kaboul = temps_courant + (30 * 60) + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Kaboul

	/* République populaire démocratique de Corée */
	time_t heure_pyongyang = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Pyongyang

	/* République de Corée */
        time_t heure_seoul = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Seoul

	/* Empire du Japon */
        time_t heure_tokyo = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Tokyo

	/* Royaume du Bhoutan */
	time_t heure_a_thimphou = temps_courant + ((4 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Thimphou

	/* République populaire de Chine */
        time_t heure_pekin = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Pekin
	time_t heure_a_urumqi = temps_courant + ((4 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Urumqi

	/* Région administrative spéciale de Macao de la République populaire de Chine */
	time_t heure_a_macao = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Macao

	/* Région administrative spéciale de Hong Kong de la République populaire de Chine */
	time_t heure_a_hong_kong = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Hong Kong

	/* Negara Brunei Darussalam */
	time_t heure_brunei = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Brunei

	/* Mongolie */
	time_t heure_a_hovd = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Hovd

	/* République de Chine (Taiwan) */
	time_t heure_a_tapei = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Tapei

	/* République des Philippines */
	time_t heure_a_manille = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Manille

	/* République de Singapour */
	time_t heure_a_singapour = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Singapour

	/* Fédération de Russie */
	time_t heure_moscou = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Moscou
        time_t heure_vladivostok = temps_courant + ((8 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Vladivostok
	time_t heure_kaliningrad = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Kaliningrad
	time_t heure_samara = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Samara
	time_t heure_volgograd = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Volgograd
	time_t heure_saratov = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Saratov
	time_t heure_oulianovsk = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Oulianovsk
	time_t heure_astrakhan = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Astrakhan
	time_t heure_anadyr = temps_courant + ((10 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Anadyr
	time_t heure_sakhalin = temps_courant + ((9 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Sakhalin
	time_t heure_omsk = temps_courant + ((4 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Omsk
	time_t heure_tchita = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Tchita
	time_t heure_tomsk = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Tomsk
	time_t heure_barnaoul = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Barnaoul
	time_t heure_magadan = temps_courant + ((9 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Magadan
	time_t heure_iekaterinbourg = temps_courant + ((3 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Iekaterinbourg
	time_t heure_yakoutsk = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Yakoutsk
	time_t heure_irkoutsk = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Irkoutsk
	time_t heure_khandyga = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Khandyga
	time_t heure_novokouznetsk = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Novokouznetsk
	time_t heure_nobossibirsk = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Nobossibirsk
	time_t heure_krasnoyarsk = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Krasnoyarsk
	time_t heure_oust_nera = temps_courant + ((8 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Oust-Nera
	time_t heure_srednekolymsk = temps_courant + ((9 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Srednekolymsk

	/* République d'Arménie */
	time_t heure_erevan = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600); //Erevan

	/*Affichage des différents horiares calculés à coté des villes correspondantes*/

        printf("\n");
	printf("République française:\n");
        calcul_et_affichage_horaire(temps_courant, "Paris");

	printf("\n");
	printf("Confédération suisse:\n");
	calcul_et_affichage_horaire(heure_zurich, "Zurich");

	printf("\n");
	printf("Principauté d'Andorre:\n");
	calcul_et_affichage_horaire(heure_andorre, "Andorre");

	printf("\n");
	printf("République de Malte:\n");
	calcul_et_affichage_horaire(heure_malte, "Malte");

	printf("\n");
	printf("Principauté de Liechtenstein:\n");
	calcul_et_affichage_horaire(heure_vaduz, "Vaduz");

	printf("\n");
	printf("République hellénique:\n");
	calcul_et_affichage_horaire(heure_d_athenes, "Athènes");

	printf("\n");
	printf("États-Unis d'Amérique:\n");
        calcul_et_affichage_horaire(heure_los_angeles, "Los Angeles");
        calcul_et_affichage_horaire(heure_de_nyc, "New York City");
        calcul_et_affichage_horaire(heure_d_ottawa, "Ottawa");
        calcul_et_affichage_horaire(heure_de_phoenix, "Phoenix");

	printf("\n");
	printf("République du Nicaragua:\n");
	calcul_et_affichage_horaire(heure_managua, "Managua");

	printf("\n");
	printf("Royaume-Uni de Grande-Bretagne et d'Irlande du Nord:\n");
	calcul_et_affichage_horaire(heure_de_londres, "Londres");

	printf("\n");
	printf("Commonwealth d'Australie:\n");
        calcul_et_affichage_horaire(heure_canberra, "Canberra");

	printf("\n");
	printf("Nouvelle-Zélande:\n");
	calcul_et_affichage_horaire(heure_wellington, "Wellington");

	printf("\n");
	printf("République du Chili:\n");
        calcul_et_affichage_horaire(heure_santiago_chili, "Santiago du Chili");

	printf("\n");
	printf("République algérienne démocratique et populaire:\n");
	calcul_et_affichage_horaire(heure_a_alger, "Alger");

	printf("\n");
	printf("République d'Afrique du Sud:\n");
        calcul_et_affichage_horaire(heure_johannesburg, "Johannesburg");

	printf("\n");
	printf("République argentine:\n");
        calcul_et_affichage_horaire(heure_buenos_aires, "Buenos Aires");

	printf("\n");
	printf("République de Madagascar:\n");
        calcul_et_affichage_horaire(heure_antananarivo, "Antananarivo");

	printf("\n");
	printf("République du Congo:\n");
	calcul_et_affichage_horaire(heure_a_brazzaville, "Brazzaville");

	printf("\n");
	printf("République démocratique du Congo:\n");
	calcul_et_affichage_horaire(heure_a_kinshasa, "Kinshasa");
	calcul_et_affichage_horaire(heure_a_lubumbashi, "Lubumbashi");

	printf("\n");
	printf("République de Namibie:\n");
        calcul_et_affichage_horaire(heure_windhoek, "Windhoek");

	printf("\n");
	printf("État de Libye:\n");
	calcul_et_affichage_horaire(heure_tripoli, "Tripoli");

	printf("\n");
	printf("République arabe d'Égypte:\n");
	calcul_et_affichage_horaire(heure_le_caire, "Le Caire");

	printf("\n");
	printf("État du Qatar:\n");
	calcul_et_affichage_horaire(heure_au_qatar, "Qatar");

	printf("\n");
	printf("République du Yémen:\n");
	calcul_et_affichage_horaire(heure_a_aden, "Aden");

	printf("\n");
	printf("République démocratique fédérale d’Éthiopie:\n");
	calcul_et_affichage_horaire(heure_addis_abeba, "Addis-Abeba");

	printf("\n");
	printf("République fédérale de Somalie:\n");
	calcul_et_affichage_horaire(heure_a_mogadiscio, "Mogadiscio");

	printf("\n");
	printf("État d'Érythrée:\n");
	calcul_et_affichage_horaire(heure_a_asmara, "Asmara");

	printf("\n");
	printf("République de Djibouti:\n");
	calcul_et_affichage_horaire(heure_djibouti, "Djibouti");

	printf("\n");
	printf("République du Kenya:\n");
	calcul_et_affichage_horaire(heure_a_nairobi, "Nairobi");

	printf("\n");
	printf("République unie de Tanzanie:\n");
	calcul_et_affichage_horaire(heure_a_dar_es_salam, "Dar es Salam");

	printf("\n");
	printf("République de Zambie:\n");
	calcul_et_affichage_horaire(heure_lusaka, "Lusaka");

	printf("\n");
	printf("République de Zimbabwe:\n");
	calcul_et_affichage_horaire(heure_harare, "Harare");

	printf("\n");
	printf("République du Pérou:\n");
        calcul_et_affichage_horaire(heure_lima, "Lima");

	printf("\n");
	printf("République d'Ouzbékistan:\n");
	calcul_et_affichage_horaire(heure_a_tachkent, "Tachkent");
	calcul_et_affichage_horaire(heure_a_samarkand, "Samarkand");

	printf("\n");
	printf("République du Tadjikistan:\n");
	calcul_et_affichage_horaire(heure_a_douchanbe, "Dushanbe");

	printf("\n");
	printf("République kirghize:\n");
	calcul_et_affichage_horaire(heure_a_bichkek, "Bichkek");

	printf("\n");
	printf("République démocratique fédérale du Népal:\n");
	calcul_et_affichage_horaire(heure_a_katmandou, "Katmandou");

	printf("\n");
        printf("République islamique d'Afghanistan:\n");
        calcul_et_affichage_horaire(heure_a_kaboul, "Kaboul");

	printf("\n");
	printf("République populaire démocratique de Corée:\n");
	calcul_et_affichage_horaire(heure_pyongyang, "Pyongyang");

	printf("\n");
	printf("République de Corée:\n");
        calcul_et_affichage_horaire(heure_seoul, "Seoul");

	printf("\n");
	printf("Empire du Japon:\n");
        calcul_et_affichage_horaire(heure_tokyo, "Tokyo");

	printf("\n");
	printf("Negara Brunei Darussalam:\n");
	calcul_et_affichage_horaire(heure_brunei, "Brunei");

	printf("\n");
	printf("République populaire de Chine:\n");
        calcul_et_affichage_horaire(heure_pekin, "Pekin");
	calcul_et_affichage_horaire(heure_a_urumqi, "Urumqi");

	printf("\n");
	printf("République de Chine (Taiwan):\n");
	calcul_et_affichage_horaire(heure_a_tapei, "Tapei");

	printf("\n");
	printf("Région administrative spéciale de Macao de la République populaire de Chine:\n");
	calcul_et_affichage_horaire(heure_a_macao, "Macao");

	printf("\n");
	printf("Région administrative spéciale de Hong Kong de la République populaire de Chine:\n");
	calcul_et_affichage_horaire(heure_a_hong_kong, "Hong Kong");

	printf("\n");
	printf("République des Philippines:\n");
	calcul_et_affichage_horaire(heure_a_manille, "Manille");

	printf("\n");
	printf("République de Singapour:\n");
	calcul_et_affichage_horaire(heure_a_singapour, "Singapour");

	printf("\n");
	printf("Royaume du Bhoutan:\n");
	calcul_et_affichage_horaire(heure_a_thimphou, "Thimphou");

	printf("\n");
	printf("Fédération de Russie:\n");
	calcul_et_affichage_horaire(heure_moscou, "Moscou");
        calcul_et_affichage_horaire(heure_vladivostok, "Vladivostok");
	calcul_et_affichage_horaire(heure_kaliningrad, "Kaliningrad");
	calcul_et_affichage_horaire(heure_samara, "Samara");
	calcul_et_affichage_horaire(heure_volgograd, "Volgograd");
	calcul_et_affichage_horaire(heure_saratov, "Saratov");
	calcul_et_affichage_horaire(heure_oulianovsk, "Oulianovsk");
	calcul_et_affichage_horaire(heure_astrakhan, "Astrakhan");
	calcul_et_affichage_horaire(heure_anadyr, "Anadyr");
	calcul_et_affichage_horaire(heure_sakhalin, "Sakhalin");
	calcul_et_affichage_horaire(heure_omsk, "Omsk");
	calcul_et_affichage_horaire(heure_tchita, "Tchita");
	calcul_et_affichage_horaire(heure_tomsk, "Tomsk");
	calcul_et_affichage_horaire(heure_barnaoul, "Barnaoul");
	calcul_et_affichage_horaire(heure_magadan, "Magadan");
	calcul_et_affichage_horaire(heure_iekaterinbourg, "Iekaterinbourg");
	calcul_et_affichage_horaire(heure_yakoutsk, "Yakoutsk");
	calcul_et_affichage_horaire(heure_irkoutsk, "Irkoutsk");
	calcul_et_affichage_horaire(heure_khandyga, "Khandyga");
	calcul_et_affichage_horaire(heure_novokouznetsk, "Novokouznetsk");
	calcul_et_affichage_horaire(heure_nobossibirsk, "Nobossibirsk");
	calcul_et_affichage_horaire(heure_krasnoyarsk, "Krasnoyarsk");
	calcul_et_affichage_horaire(heure_oust_nera, "Oust-Nera");
	calcul_et_affichage_horaire(heure_srednekolymsk, "Srednekolymsk");

	printf("\n");
	printf("République d'Arménie:\n");
	calcul_et_affichage_horaire(heure_erevan, "Erevan");

	printf("\n");
	printf("Mongolie:\n");
	calcul_et_affichage_horaire(heure_a_hovd, "Hovd");

	printf("\n");
}

//Cette fonction permet de calculer et de renvoyer les horaires d'une ville passée en paramétre
char* calcul_et_renvoie_horaire(time_t temps, char* ville)
{
	//Declaration des variables
	struct tm *horaire = localtime(&temps);
	char* jour_semaine;
	char* mois;
	char* resultat_du_calcul = malloc(sizeof(char) * 85);
	char chiffre_a_convertir_en_str[5];

	//Definition du mois en court en fonction du champs tm_mon de la structure tm
	switch(horaire->tm_mon)
	{
		case 0: mois = "Janvier"; break;
		case 1: mois = "Fevrier"; break;
		case 2: mois = "Mars"; break;
		case 3: mois = "Avril"; break;
		case 4: mois = "Mai"; break;
		case 5: mois = "Juin"; break;
		case 6: mois = "Juillet"; break;
		case 7: mois = "Aout"; break;
		case 8: mois = "Septembre"; break;
		case 9: mois = "Octobre"; break;
		case 10: mois = "Novembre"; break;
		case 11: mois = "Decembre"; break;
	}	

	//Definition du jour de la semaine en fonction du champs tm_wday de la structure tm
	switch(horaire->tm_wday)
	{
		case 0: jour_semaine = "Dimanche"; break;
		case 1: jour_semaine = "Lundi"; break;
		case 2: jour_semaine = "Mardi"; break;
		case 3: jour_semaine = "Mercredi"; break;
		case 4: jour_semaine = "Jeudi"; break;
		case 5: jour_semaine = "Vendredi"; break;
		case 6: jour_semaine = "Samedi"; break;
	}

	//
	strcat(resultat_du_calcul, ville);

	//
	strcat(resultat_du_calcul, " : ");

	//
	if(horaire->tm_hour < 10)
	{
		//
		sprintf(chiffre_a_convertir_en_str, "%02d", horaire->tm_hour);
	}
	//Sinon...
	else
	{
		//
		sprintf(chiffre_a_convertir_en_str, "%d", horaire->tm_hour);
	}

	//
	strcat(resultat_du_calcul, chiffre_a_convertir_en_str);

	//
	strcat(resultat_du_calcul, ":");

	//
	if(horaire->tm_min < 10)
	{
		//
		sprintf(chiffre_a_convertir_en_str, "%02d", horaire->tm_min);
	}
	//Sinon...
	else
	{
		//
		sprintf(chiffre_a_convertir_en_str, "%d", horaire->tm_min);
	}

	//
	strcat(resultat_du_calcul, chiffre_a_convertir_en_str);

	//
	strcat(resultat_du_calcul, ":");

	//
	if(horaire->tm_sec < 10)
	{
		//
		sprintf(chiffre_a_convertir_en_str, "%02d", horaire->tm_sec);
	}
	//Sinon...
	else
	{
		//
		sprintf(chiffre_a_convertir_en_str, "%d", horaire->tm_sec);
	}

	//
	strcat(resultat_du_calcul, chiffre_a_convertir_en_str);

	//
	strcat(resultat_du_calcul, " - ");

	//
	strcat(resultat_du_calcul, jour_semaine);

	//
	strcat(resultat_du_calcul, " ");

	//
	if(horaire->tm_mday < 10)
	{
		//
		sprintf(chiffre_a_convertir_en_str, "%02d", horaire->tm_mday);
	}
	//Sinon...
	else
	{
		//
		sprintf(chiffre_a_convertir_en_str, "%d", horaire->tm_mday);
	}

	//
	strcat(resultat_du_calcul, chiffre_a_convertir_en_str);

	//
	strcat(resultat_du_calcul, " ");

	//
        strcat(resultat_du_calcul, mois);

	//
	strcat(resultat_du_calcul, " ");

	//
	sprintf(chiffre_a_convertir_en_str, "%d", horaire->tm_year + 1900);
        strcat(resultat_du_calcul, chiffre_a_convertir_en_str);

	//
	return resultat_du_calcul;
}

//Cette fonction calcule puis retourne l'heure et la date pour une ville déterminée et connue passée en paramétre sous forme d'une chaine de caractères
char* retour_de_l_heure_et_de_la_date_pour_une_ville_determinee_et_connue(time_t temps_courant, char* nom_de_la_ville)
{

	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Paris"...
	if(strcmp(nom_de_la_ville,"Paris") == 0)
	{

		//L'heure et la date de Paris en temps réel est retournée
		return calcul_et_renvoie_horaire(temps_courant, "Paris");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Athènes"...
	else if(strcmp(nom_de_la_ville,"Athènes") == 0)
	{
		//Calcul de l'heure et de la date à Athènes et stockage de celui-ci dans la variable heure_d_athenes
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_athenes = temps_heure_d_athenes - (décallage_entre_paris_et_athenes_en_temps_reel * 3600)
		time_t heure_d_athenes = temps_courant + 3600;

		//L'heure et la date d'Athènes en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_d_athenes, "Athènes");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Los Angeles"...
	else if(strcmp(nom_de_la_ville,"Los Angeles") == 0)
	{
		//Calcul de l'heure et de la date à Los Angeles et stockage de celui-ci dans la variable heure_los_angeles
		//Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_los_angeles = temps_heure_de_paris - (décallage_entre_paris_et_los_angeles_en_temps_reel * 3600)
		time_t heure_los_angeles = temps_courant - ((9 - calcul_du_decalage_avec_l_amerique_du_nord(temps_courant)) * 3600);

		//L'heure et la date de Los Angeles en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_los_angeles, "Los Angeles");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "New York City"...
	else if(strcmp(nom_de_la_ville,"New York City") == 0)
	{
		//Calcul de l'heure et de la date à New York et stockage de celui-ci dans la variable heure_de_nyc
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_new_york_city = temps_heure_de_paris - (décallage_entre_paris_et_new_york_city_en_temps_reel * 3600)
		time_t heure_de_nyc = temps_courant - ((6 - calcul_du_decalage_avec_l_amerique_du_nord(temps_courant)) * 3600);

		//L'heure et la date de New York City en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_nyc, "New York City");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Ottawa"...
	else if(strcmp(nom_de_la_ville,"Ottawa") == 0)
	{
		//Calcul de l'heure et de la date à Ottawa et stockage de celui-ci dans la variable heure_d_ottawa
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_ottawa = temps_heure_de_paris - (décallage_entre_paris_et_ottawa_en_temps_reel * 3600)
		time_t heure_d_ottawa = temps_courant - ((6 - calcul_du_decalage_avec_l_amerique_du_nord(temps_courant)) * 3600);

		//L'heure et la date de Ottawa en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_d_ottawa, "Ottawa");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Phoenix"...
	else if(strcmp(nom_de_la_ville,"Phoenix") == 0)
	{
		//Calcul de l'heure et de la date à Phoenix et stockage de celui-ci dans la variable heure_de_phoenix
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_phoenix = temps_heure_de_paris - (décallage_entre_paris_et_phoenix_en_temps_reel * 3600)
		time_t heure_de_phoenix = temps_courant - ((9 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Phoenix en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_phoenix, "Phoenix");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Londres"...
	else if(strcmp(nom_de_la_ville,"Londres") == 0)
        {
		//Calcul de l'heure et de la date à Londres et stockage de celui-ci dans la variable heure_de_londres
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_londres = temps_heure_de_paris - (décallage_entre_paris_et_londres_en_temps_reel * 3600)
		time_t heure_de_londres = temps_courant - ((1 - calcul_du_decallage_avec_la_grande_bretagne(temps_courant)) * 3600);

		//L'heure et la date de Londres en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_de_londres, "Londres");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Moscou"...
        else if(strcmp(nom_de_la_ville,"Moscou") == 0)
        {
		//Calcul de l'heure et de la date à Moscou et stockage de celui-ci dans la variable heure_moscou
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_moscou = temps_heure_de_paris - (décallage_entre_paris_et_moscou_en_temps_reel * 3600)
		time_t heure_moscou = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Moscou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_moscou, "Moscou");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Vladivostok"...
        else if(strcmp(nom_de_la_ville,"Vladivostok") == 0)
        {
		//Calcul de l'heure et de la date à Vladivostok et stockage de celui-ci dans la variable heure_vladivostok
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_vladivostok = temps_heure_de_paris - (décallage_entre_paris_et_vladivostok_en_temps_reel * 3600)
		time_t heure_vladivostok = temps_courant + ((8 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Vladivostok en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_vladivostok, "Vladivostok");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Wellington"...
	else if(strcmp(nom_de_la_ville,"Wellington") == 0)
	{
		//Calcul de l'heure et de la date à Wellington et stockage de celui-ci dans la variable heure_wellington
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_wellington = temps_heure_de_paris - (décallage_entre_paris_et_wellington_en_temps_reel * 3600)
		time_t heure_wellington = temps_courant + ((12 -  calcul_du_decalage_avec_wellington(temps_courant)) * 3600);

		//L'heure et la date de Wellington en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_wellington, "Wellington");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Canberra"...
        else if(strcmp(nom_de_la_ville,"Canberra") == 0)
        {
		//Calcul de l'heure et de la date à Canberra et stockage de celui-ci dans la variable heure_canberra
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_canberra = temps_heure_de_paris - (décallage_entre_paris_et_canberra_en_temps_reel * 3600)
		time_t heure_canberra = temps_courant + ((10 - calcul_du_decalage_avec_canberra(temps_courant)) * 3600);

		//L'heure et la date de Canberra en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_canberra, "Canberra");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Santiago du Chili"...
        else if(strcmp(nom_de_la_ville,"Santiago du Chili") == 0)
        {
		//Calcul de l'heure et de la date à Santiago du Chili et stockage de celui-ci dans la variable heure_santiago_chili
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_santiago_du_chili = temps_heure_de_paris - (décallage_entre_paris_et_santiago_du_chili_en_temps_reel * 3600)
		time_t heure_santiago_chili = temps_courant - ((6 - calcul_du_decalage_avec_le_chili(temps_courant)) * 3600);

		//L'heure et la date de Santiago du Chili en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_santiago_chili, "Santiago du Chili");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Johannesburg"...
	else if(strcmp(nom_de_la_ville,"Johannesburg") == 0)
        {
		//Calcul de l'heure et de la date à Johannesburg et stockage de celui-ci dans la variable heure_johannesburg
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_johannesburg = temps_heure_de_paris - (décallage_entre_paris_et_johannesburg_en_temps_reel * 3600)
		time_t heure_johannesburg = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Johannesburg en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_johannesburg, "Johannesburg");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Alger"...
	else if(strcmp(nom_de_la_ville,"Alger") == 0)
	{
		//Calcul de l'heure et de la date à Alger et stockage de celui-ci dans la variable heure_a_alger
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_alger = temps_heure_de_paris - (décallage_entre_paris_et_alger_en_temps_reel * 3600)
		time_t heure_a_alger = temps_courant - ((1 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date d'Alger en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_alger, "Alger");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Nairobi"...
	else if(strcmp(nom_de_la_ville,"Nairobi") == 0)
	{
		//Calcul de l'heure et de la date à Nairobi et stockage de celui-ci dans la variable heure_a_dar_es_salam
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_nairobi = temps_heure_de_paris - (décallage_entre_paris_et_nairobi_en_temps_reel * 3600)
		time_t heure_a_nairobi = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Nairobi en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_nairobi, "Nairobi");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Dar es Salam"...
	else if(strcmp(nom_de_la_ville,"Dar es Salam") == 0)
	{
		//Calcul de l'heure et de la date à Dar es Salem et stockage de celui-ci dans la variable heure_a_dar_es_salam
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_dar_es_salam = temps_heure_de_paris - (décallage_entre_paris_et_dar_es_salam_en_temps_reel * 3600)
		time_t heure_a_dar_es_salam = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Dar es Salam en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_dar_es_salam, "Dar es Salam");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Buenos Aires"...
        else if(strcmp(nom_de_la_ville,"Buenos Aires") == 0)
        {
		//Calcul de l'heure et de la date à Buenos Aires et stockage de celui-ci dans la variable heure_buenos_aires
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_buenos_aires = temps_heure_de_paris - (décallage_entre_paris_et_buenos_aires_en_temps_reel * 3600)
		time_t heure_buenos_aires = temps_courant - ((5 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Buenos Aires en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_buenos_aires, "Buenos Aires");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Antananarivo"...
        else if(strcmp(nom_de_la_ville,"Antananarivo") == 0)
        {
		//Calcul de l'heure et de la date à Antananarivo et stockage de celui-ci dans la variable heure_antananarivo
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_antananarivo = temps_heure_de_paris - (décallage_entre_paris_et_antananarivo_en_temps_reel * 3600)
		time_t heure_antananarivo = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Antananarivo en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_antananarivo, "Antananarivo");

        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Windhoek"...
        else if(strcmp(nom_de_la_ville,"Windhoek") == 0)
        {
		//Calcul de l'heure et de la date à Windhoek et stockage de celui-ci dans la variable heure_windhoek
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_windhoek = temps_heure_de_paris - (décallage_entre_paris_et_windhoek_en_temps_reel * 3600)
		time_t heure_windhoek = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Windhoek en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_windhoek, "Windhoek");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Lima"...
        else if(strcmp(nom_de_la_ville,"Lima") == 0)
        {
		//Calcul de l'heure et de la date à Lima et stockage de celui-ci dans la variable heure_lima
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_lima = temps_heure_de_paris - (décallage_entre_paris_et_lima_en_temps_reel * 3600)
		time_t heure_lima = temps_courant - ((7 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Lima en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_lima, "Lima");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Pyongyang"...
	else if(strcmp(nom_de_la_ville,"Pyongyang") == 0)
	{
		//Calcul de l'heure et de la date à Pyongyang et stockage de celui-ci dans la variable heure_pyongyang
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_pyongyang = temps_heure_de_paris - (décallage_entre_paris_et_pyongyang_en_temps_reel * 3600)
		time_t heure_pyongyang = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Pyongyang en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_pyongyang, "Pyongyang");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Seoul"...
        else if(strcmp(nom_de_la_ville,"Seoul") == 0)
        {
		//Calcul de l'heure et de la date à Seoul et stockage de celui-ci dans la variable heure_seoul
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_seoul = temps_heure_de_paris - (décallage_entre_paris_et_seoul_en_temps_reel * 3600)
		time_t heure_seoul = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Seoul en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_seoul, "Seoul");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tokyo"...
        else if(strcmp(nom_de_la_ville,"Tokyo") == 0)
        {
		//Calcul de l'heure et de la date à Tokyo et stockage de celui-ci dans la variable heure_tokyo
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_tokyo = temps_heure_de_paris - (décallage_entre_paris_et_tokyo_en_temps_reel * 3600)
		time_t heure_tokyo = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Tokyo en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_tokyo, "Tokyo");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Pekin"...
	else if(strcmp(nom_de_la_ville,"Pekin") == 0)
        {
		//Calcul de l'heure et de la date à Pekin et stockage de celui-ci dans la variable heure_pekin
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_pekin = temps_heure_de_paris - (décallage_entre_paris_et_pekin_en_temps_reel * 3600)
		time_t heure_pekin = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Pekin en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_pekin, "Pekin");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Manille"...
	else if(strcmp(nom_de_la_ville,"Manille") == 0)
	{
		//Calcul de l'heure et de la date à Manille et stockage de celui-ci dans la variable heure_a_manille
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_manille = temps_heure_de_paris - (décallage_entre_paris_et_manille_en_temps_reel * 3600)
		time_t heure_a_manille = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Manille en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_manille, "Manille");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Urumqi"...
	else if(strcmp(nom_de_la_ville,"Urumqi") == 0)
	{
		//Calcul de l'heure et de la date à Urumqi et stockage de celui-ci dans la variable heure_a_urumqi
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_urumqi = temps_heure_de_paris - (décallage_entre_paris_et_urumqi_en_temps_reel * 3600)
		time_t heure_a_urumqi = temps_courant + ((4 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date d'Urumqi en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_urumqi, "Urumqi");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Kaliningrad"...
	else if(strcmp(nom_de_la_ville,"Kaliningrad") == 0)
	{
		//Calcul de l'heure et de la date à Kaliningrad et stockage de celui-ci dans la variable heure_kaliningrad
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_kaliningrad = temps_heure_de_paris + (décallage_entre_paris_et_kaliningrad_en_temps_reel * 3600)
		time_t heure_kaliningrad = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Kaliningrad en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_kaliningrad, "Kaliningrad");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Samara"...
	else if(strcmp(nom_de_la_ville,"Samara") == 0)
	{
		//Calcul de l'heure et de la date à Samara et stockage de celui-ci dans la variable heure_kaliningrad
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_samara = temps_heure_de_paris + (décallage_entre_paris_et_samara_en_temps_reel * 3600)
		time_t heure_samara = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Samara en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_samara, "Samara");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Volgograd"...
	else if(strcmp(nom_de_la_ville,"Volgograd") == 0)
	{
		//Calcul de l'heure et de la date à Samara et stockage de celui-ci dans la variable heure_volgograd
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_volgograd = temps_heure_de_paris + (décallage_entre_paris_et_volgograd_en_temps_reel * 3600)
		time_t heure_volgograd = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Volgograd en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_volgograd, "Volgograd");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Saratov"...
	else if(strcmp(nom_de_la_ville,"Saratov") == 0)
	{
		//Calcul de l'heure et de la date à Saratov et stockage de celui-ci dans la variable heure_saratov
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_saratov = temps_heure_de_paris + (décallage_entre_paris_et_saratov_en_temps_reel * 3600)
		time_t heure_saratov = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Saratov en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_saratov, "Saratov");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Oulianovsk"...
        else if(strcmp(nom_de_la_ville,"Oulianovsk") == 0)
	{
		//Calcul de l'heure et de la date à Oulianovsk et stockage de celui-ci dans la variable heure_oulianovsk
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_oulianovsk = temps_heure_de_paris + (décallage_entre_paris_et_oulianovsk_en_temps_reel * 3600)
		time_t heure_oulianovsk = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Saratov en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_oulianovsk, "Oulianovsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Astrakhan"...
	else if(strcmp(nom_de_la_ville,"Astrakhan") == 0)
	{
		//Calcul de l'heure et de la date à Astrakhan et stockage de celui-ci dans la variable heure_astrakhan
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_astrakhan = temps_heure_de_paris + (décallage_entre_paris_et_astrakhan_en_temps_reel * 3600)
		time_t heure_astrakhan = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date d'Astrakhan en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_astrakhan, "Astrakhan");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Anadyr"...
	else if(strcmp(nom_de_la_ville,"Anadyr") == 0)
	{
		//Calcul de l'heure et de la date à Anadyr et stockage de celui-ci dans la variable heure_anadyr
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_anadyr = temps_heure_de_paris + (décallage_entre_paris_et_anadyr_en_temps_reel * 3600)
		time_t heure_anadyr = temps_courant + ((10 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date d'Anadyr en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_anadyr, "Anadyr");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Sakhalin"...
	else if(strcmp(nom_de_la_ville,"Sakhalin") == 0)
	{
		//Calcul de l'heure et de la date à Sakhalin et stockage de celui-ci dans la variable heure_sakhalin
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_sakhalin = temps_heure_de_paris + (décallage_entre_paris_et_sakhalin_en_temps_reel * 3600)
		time_t heure_sakhalin = temps_courant + ((9 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Sakhalin en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_sakhalin, "Sakhalin");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Omsk"...
	else if(strcmp(nom_de_la_ville,"Omsk") == 0)
	{
		//Calcul de l'heure et de la date à Omsk et stockage de celui-ci dans la variable heure_omsk
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_omsk = temps_heure_de_paris + (décallage_entre_paris_et_omsk_en_temps_reel * 3600)
		time_t heure_omsk = temps_courant + ((4 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date d'Omsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_omsk, "Omsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tchita"...
	else if(strcmp(nom_de_la_ville,"Tchita") == 0)
	{
		//Calcul de l'heure et de la date à Tchita et stockage de celui-ci dans la variable heure_tchita
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_tchita = temps_heure_de_paris + (décallage_entre_paris_et_tchita_en_temps_reel * 3600)
		time_t heure_tchita = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Tchita en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_tchita, "Tchita");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tomsk"...
	else if(strcmp(nom_de_la_ville,"Tomsk") == 0)
	{
		//Calcul de l'heure et de la date à Tomsk et stockage de celui-ci dans la variable heure_tomsk
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_tomsk = temps_heure_de_paris + (décallage_entre_paris_et_tomsk_en_temps_reel * 3600)
		time_t heure_tomsk = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Tomsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_tomsk, "Tomsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Barnaoul"...
	else if(strcmp(nom_de_la_ville,"Barnaoul") == 0)
	{
		//Calcul de l'heure et de la date à Barnaoul et stockage de celui-ci dans la variable heure_barnaoul
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_barnaoul = temps_heure_de_paris + (décallage_entre_paris_et_barnaoul_en_temps_reel * 3600)
                time_t heure_barnaoul = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Barnaoul en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_barnaoul, "Barnaoul");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Magadan"...
	else if(strcmp(nom_de_la_ville,"Magadan") == 0)
	{
		//Calcul de l'heure et de la date à Magadan et stockage de celui-ci dans la variable heure_magadan
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_magadan = temps_heure_de_paris + (décallage_entre_paris_et_magadan_en_temps_reel * 3600)
		time_t heure_magadan = temps_courant + ((9 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Magadan en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_magadan, "Magadan");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Iekaterinbourg"...
	else if(strcmp(nom_de_la_ville,"Iekaterinbourg") == 0)
	{
		//Calcul de l'heure et de la date à Iekaterinbourg et stockage de celui-ci dans la variable heure_iekaterinbourg
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_iekaterinbourg = temps_heure_de_paris + (décallage_entre_paris_et_iekaterinbourg_en_temps_reel * 3600)
		time_t heure_iekaterinbourg = temps_courant + ((3 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date d'Iekaterinbourg en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_iekaterinbourg, "Iekaterinbourg");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Yakoutsk"...
	else if(strcmp(nom_de_la_ville,"Yakoutsk") == 0)
	{
		//Calcul de l'heure et de la date à Yakoutsk et stockage de celui-ci dans la variable heure_yakoutsk
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_yakoutsk = temps_heure_de_paris + (décallage_entre_paris_et_yakoutsk_en_temps_reel * 3600)
		time_t heure_yakoutsk = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date d'Yakoutsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_yakoutsk, "Yakoutsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Irkoutsk"...
	else if(strcmp(nom_de_la_ville,"Irkoutsk") == 0)
	{
		//Calcul de l'heure et de la date à Irkoutsk et stockage de celui-ci dans la variable heure_irkoutsk
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_irkoutsk = temps_heure_de_paris + (décallage_entre_paris_et_irkoutsk_en_temps_reel * 3600)
		time_t heure_irkoutsk = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date d'Irkoutsk en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_irkoutsk, "Irkoutsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Khandyga"...
	else if(strcmp(nom_de_la_ville,"Khandyga") == 0)
	{
		//Calcul de l'heure et de la date à Khandyga et stockage de celui-ci dans la variable heure_khandyga
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_khandyga = temps_heure_de_paris + (décallage_entre_paris_et_khandyga_en_temps_reel * 3600)
		time_t heure_khandyga = temps_courant + ((7 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Khandyga en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_khandyga, "Khandyga");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Novokouznetsk"...
	else if(strcmp(nom_de_la_ville,"Novokouznetsk") == 0)
	{
		//Calcul de l'heure et de la date à Novokouznetsk et stockage de celui-ci dans la variable heure_novokouznetsk
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_Novokouznetsk = temps_heure_de_paris + (décallage_entre_paris_et_novokouznetsk_en_temps_reel * 3600)
		time_t heure_novokouznetsk = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Novokouznetsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_novokouznetsk, "Novokouznetsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Nobossibirsk"...
	else if(strcmp(nom_de_la_ville,"Nobossibirsk") == 0)
	{
		//Calcul de l'heure et de la date à Nobossibirsk et stockage de celui-ci dans la variable heure_nobossibirsk
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_Nobossibirsk = temps_heure_de_paris + (décallage_entre_paris_et_nobossibirsk_en_temps_reel * 3600)
		time_t heure_nobossibirsk = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Nobossibirsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_nobossibirsk, "Nobossibirsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Krasnoyarsk"...
	else if(strcmp(nom_de_la_ville,"Krasnoyarsk") == 0)
	{
		//Calcul de l'heure et de la date à Krasnoyarsk et stockage de celui-ci dans la variable heure_krasnoyarsk
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_Krasnoyarsk = temps_heure_de_paris + (décallage_entre_paris_et_krasnoyarsk_en_temps_reel * 3600)
		time_t heure_krasnoyarsk = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Krasnoyarsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_krasnoyarsk, "Krasnoyarsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Oust-Nera"...
	else if(strcmp(nom_de_la_ville,"Oust-Nera") == 0)
	{
		//Calcul de l'heure et de la date à Oust-Nera et stockage de celui-ci dans la variable heure_oust_nera
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_oust-nera = temps_heure_de_paris + (décallage_entre_paris_et_oust-nera_en_temps_reel * 3600)
		time_t heure_oust_nera = temps_courant + ((8 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date d'Oust-Nera en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_oust_nera, "Oust-Nera");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Srednekolymsk"...
	else if(strcmp(nom_de_la_ville,"Srednekolymsk") == 0)
	{
		//Calcul de l'heure et de la date à Srednekolymsk et stockage de celui-ci dans la variable heure_srednekolymsk
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_srednekolymsk = temps_heure_de_paris + (décallage_entre_paris_et_srednekolymsk_en_temps_reel * 3600)
		time_t heure_srednekolymsk = temps_courant + ((9 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date de Srednekolymsk en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_srednekolymsk, "Srednekolymsk");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Le Caire"...
	else if(strcmp(nom_de_la_ville,"Le Caire") == 0)
	{
		//Calcul de l'heure et de la date au Caire et stockage de celui-ci dans la variable heure_le_caire
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_au_caire = temps_heure_de_paris + (décallage_entre_paris_et_le_caire_en_temps_reel * 3600)
		time_t heure_le_caire = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date au Caire en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_le_caire, "Le Caire");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Aden"...
	else if(strcmp(nom_de_la_ville,"Aden") == 0)
	{
		//Calcul de l'heure et de la date à Aden et stockage de celui-ci dans la variable heure_a_aden
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_aden = temps_heure_de_paris + (décallage_entre_paris_et_aden_en_temps_reel * 3600)
		time_t heure_a_aden = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Aden en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_aden, "Aden");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Addis-Abeba"...
	else if(strcmp(nom_de_la_ville,"Addis-Abeba") == 0)
	{
		//Calcul de l'heure et de la date à Addis-Abeba et stockage de celui-ci dans la variable heure_le_caire
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_addis-abeba = temps_heure_de_paris + (décallage_entre_paris_et_addis-abeba_en_temps_reel * 3600)
		time_t heure_addis_abeba = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Addis-Abeba en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_addis_abeba, "Addis-Abeba");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Brazzaville"...
	else if(strcmp(nom_de_la_ville,"Brazzaville") == 0)
	{
		//Calcul de l'heure et de la date à Brazzaville et stockage de celui-ci dans la variable heure_a_brazzaville
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_brazzaville = temps_heure_de_paris + (décallage_entre_paris_et_brazzaville_en_temps_reel * 3600)
		time_t heure_a_brazzaville = temps_courant - ((1 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Brazzaville en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_brazzaville, "Brazzaville");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Kinshasa"...
	else if(strcmp(nom_de_la_ville,"Kinshasa") == 0)
	{
		//Calcul de l'heure et de la date à Kinshasa et stockage de celui-ci dans la variable heure_a_kinshasa
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_kinshasa = temps_heure_de_paris + (décallage_entre_paris_et_kinshasa_en_temps_reel * 3600)
		time_t heure_a_kinshasa = temps_courant - ((1 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Kinshasa en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_kinshasa, "Kinshasa");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Lubumbashi"...
	else if(strcmp(nom_de_la_ville,"Lubumbashi") == 0)
	{
		//Calcul de l'heure et de la date à Lubumbashi et stockage de celui-ci dans la variable heure_a_lubumbashi
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_lubumbashi = temps_heure_de_paris + (décallage_entre_paris_et_lubumbashi_en_temps_reel * 3600)
		time_t heure_a_lubumbashi = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Lubumbashi en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_lubumbashi, "Lubumbashi");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Qatar"...
	else if(strcmp(nom_de_la_ville,"Qatar") == 0)
	{
		//Calcul de l'heure et de la date au Qatar et stockage de celui-ci dans la variable heure_au_qatar
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_au_qatar = temps_heure_de_paris + (décallage_entre_paris_et_le_qatar_en_temps_reel * 3600)
		time_t heure_au_qatar = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date au Qatar en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_au_qatar, "Qatar");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Zurich"...
	else if(strcmp(nom_de_la_ville,"Zurich") == 0)
	{
		//Calcul de l'heure et de la date à Zurich et stockage de celui-ci dans la variable heure_zurich
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_zurich = temps_heure_de_paris + (décallage_entre_paris_et_zurich_en_temps_reel * 3600)
		time_t heure_zurich = temps_courant;

		//L'heure et la date à Zurich en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_zurich, "Zurich");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Andorre"...
	else if(strcmp(nom_de_la_ville,"Andorre") == 0)
	{
		//Calcul de l'heure et de la date à Andorre et stockage de celui-ci dans la variable heure_andorre
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_andorre = temps_heure_de_paris + (décallage_entre_paris_et_andorre_en_temps_reel * 3600)
		time_t heure_andorre = temps_courant;

		//L'heure et la date à Andorre en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_andorre, "Andorre");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Vaduz"...
	else if(strcmp(nom_de_la_ville,"Vaduz") == 0)
	{
		//Calcul de l'heure et de la date à Vaduz et stockage de celui-ci dans la variable heure_vaduz
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_vaduz = temps_heure_de_paris + (décallage_entre_paris_et_vaduz_en_temps_reel * 3600)
		time_t heure_vaduz = temps_courant;

		//L'heure et la date à Vaduz en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_vaduz, "Vaduz");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Malte"...
	else if(strcmp(nom_de_la_ville,"Malte") == 0)
	{
		//Calcul de l'heure et de la date à Malte et stockage de celui-ci dans la variable heure_malte
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_malte = temps_heure_de_paris + (décallage_entre_paris_et_malte_en_temps_reel * 3600)
		time_t heure_malte = temps_courant;

		//L'heure et la date à Malte en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_malte, "Malte");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Djibouti"...
	else if(strcmp(nom_de_la_ville,"Djibouti") == 0)
	{
		//Calcul de l'heure et de la date à Djibouti et stockage de celui-ci dans la variable heure_djibouti
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_djibouti = temps_heure_de_paris + (décallage_entre_paris_et_djibouti_en_temps_reel * 3600)
		time_t heure_djibouti = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Djibouti en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_djibouti, "Djibouti");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Lusaka"...
	else if(strcmp(nom_de_la_ville,"Lusaka") == 0)
	{
		//Calcul de l'heure et de la date à Lusaka et stockage de celui-ci dans la variable heure_lusaka
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_lusaka = temps_heure_de_paris + (décallage_entre_paris_et_lusaka_en_temps_reel * 3600)
		time_t heure_lusaka = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Lusaka en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_lusaka, "Lusaka");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tripoli"...
	else if(strcmp(nom_de_la_ville,"Tripoli") == 0)
	{
		//Calcul de l'heure et de la date à Tripoli et stockage de celui-ci dans la variable heure_tripoli
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_tripoli = temps_heure_de_paris + (décallage_entre_paris_et_tripoli_en_temps_reel * 3600)
		time_t heure_tripoli = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Tripoli en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_tripoli, "Tripoli");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Asmara"...
	else if(strcmp(nom_de_la_ville,"Asmara") == 0)
	{
		//Calcul de l'heure et de la date à Asmara et stockage de celui-ci dans la variable heure_a_asmara
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_asmara = temps_heure_de_paris + (décallage_entre_paris_et_asmara_en_temps_reel * 3600)
		time_t heure_a_asmara = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Asmara en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_asmara, "Asmara");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Harare"...
	else if(strcmp(nom_de_la_ville,"Harare") == 0)
	{
		//Calcul de l'heure et de la date à Harare et stockage de celui-ci dans la variable heure_harare
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_harare = temps_heure_de_paris + (décallage_entre_paris_et_harare_en_temps_reel * 3600)
		time_t heure_harare = temps_courant + ((0 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Harare en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_harare, "Harare");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Managua"...
	else if(strcmp(nom_de_la_ville,"Managua") == 0)
	{
		//Calcul de l'heure et de la date à Managua et stockage de celui-ci dans la variable heure_managua
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_managua = temps_heure_de_paris + (décallage_entre_paris_et_managua_en_temps_reel * 3600)
		time_t heure_managua = temps_courant - ((8 - application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Managua en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_managua, "Managua");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Brunei"...
	else if(strcmp(nom_de_la_ville,"Brunei") == 0)
	{
		//Calcul de l'heure et de la date à Brunei et stockage de celui-ci dans la variable heure_brunei
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_brunei = temps_heure_de_paris + (décallage_entre_paris_et_brunei_en_temps_reel * 3600)
		time_t heure_brunei = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Brunei en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_brunei, "Brunei");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Erevan"...
	else if(strcmp(nom_de_la_ville,"Erevan") == 0)
	{
		//Calcul de l'heure et de la date à Erevan et stockage de celui-ci dans la variable heure_erevan
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_erevan = temps_heure_de_paris + (décallage_entre_paris_et_erevan_en_temps_reel * 3600)
		time_t heure_erevan = temps_courant + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Erevan en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_erevan, "Erevan");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Mogadiscio"...
	else if(strcmp(nom_de_la_ville,"Mogadiscio") == 0)
	{
		//Calcul de l'heure et de la date à Erevan et stockage de celui-ci dans la variable heure_a_mogadiscio
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_mogadiscio = temps_heure_de_paris + (décallage_entre_paris_et_mogadiscio_en_temps_reel * 3600)
		time_t heure_a_mogadiscio = temps_courant + ((1 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Mogadiscio en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_mogadiscio, "Mogadiscio");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Hovd"...
	else if(strcmp(nom_de_la_ville,"Hovd") == 0)
	{
		//Calcul de l'heure et de la date à Hovd et stockage de celui-ci dans la variable heure_a_hovd
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_hovd = temps_heure_de_paris + (décallage_entre_paris_et_hovd_en_temps_reel * 3600)
		time_t heure_a_hovd = temps_courant + ((5 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Hovd en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_hovd, "Hovd");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tapei"...
	else if(strcmp(nom_de_la_ville,"Tapei") == 0)
	{
		//Calcul de l'heure et de la date à Tapei et stockage de celui-ci dans la variable heure_a_tapei
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_tapei = temps_heure_de_paris + (décallage_entre_paris_et_tapei_en_temps_reel * 3600)
		time_t heure_a_tapei = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Tapei en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_tapei, "Tapei");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Macao"...
	else if(strcmp(nom_de_la_ville,"Macao") == 0)
	{
		//Calcul de l'heure et de la date à Macao et stockage de celui-ci dans la variable heure_a_macao
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_macao = temps_heure_de_paris + (décallage_entre_paris_et_macao_en_temps_reel * 3600)
		time_t heure_a_macao = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Macao en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_macao, "Macao");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Tachkent"...
	else if(strcmp(nom_de_la_ville,"Tachkent") == 0)
	{
		//Calcul de l'heure et de la date à Tachkent et stockage de celui-ci dans la variable heure_a_tachkent
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_tachkent = temps_heure_de_tachkent + (décallage_entre_paris_et_tachkent_en_temps_reel * 3600)
		time_t heure_a_tachkent = temps_courant + ((3 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Tachkent en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_tachkent, "Tachkent");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Samarkand"...
        else if(strcmp(nom_de_la_ville,"Samarkand") == 0)
        {
                //Calcul de l'heure et de la date à Samarkand et stockage de celui-ci dans la variable heure_a_samarkand
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_samarkand = temps_heure_de_samarkand + (décallage_entre_paris_et_samarkand_en_temps_reel * 3600)
                time_t heure_a_samarkand = temps_courant + ((3 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

                //L'heure et la date à Samarkand en temps réel est retournée
                return calcul_et_renvoie_horaire(heure_a_samarkand, "Samarkand");
        }
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Dushanbe"...
	else if(strcmp(nom_de_la_ville,"Dushanbe") == 0)
	{
		//Calcul de l'heure et de la date à Douchanbé et stockage de celui-ci dans la variable heure_a_douchanbe
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_douchanbe = temps_heure_de_douchanbe + (décallage_entre_paris_et_douchanbe_en_temps_reel * 3600)
		time_t heure_a_douchanbe = temps_courant + ((3 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Douchanbé en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_douchanbe, "Dushanbe");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Thimphou"...
	else if(strcmp(nom_de_la_ville,"Thimphou") == 0)
	{
		//Calcul de l'heure et de la date à Thimphou et stockage de celui-ci dans la variable heure_a_thimphou
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_thimphou = temps_heure_de_thimphou + (décallage_entre_paris_et_thimphou_en_temps_reel * 3600)
		time_t heure_a_thimphou = temps_courant + ((4 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Thimphou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_thimphou, "Bhoutan");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Bichkek"...
	else if(strcmp(nom_de_la_ville,"Bichkek") == 0)
	{
		//Calcul de l'heure et de la date à Bichkek et stockage de celui-ci dans la variable heure_a_bichkek
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_bichkek = temps_heure_de_bichkek + (décallage_entre_paris_et_bichkek_en_temps_reel * 3600)
		time_t heure_a_bichkek = temps_courant + ((4 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Bichkek en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_bichkek, "Bichkek");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Katmandou"...
	else if(strcmp(nom_de_la_ville,"Katmandou") == 0)
	{
		//Calcul de l'heure et de la date à Katmandou et stockage de celui-ci dans la variable heure_a_katmandou
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_katmandou = temps_heure_de_paris + (nombre_de_minutes_supplemantaires_pour_calculer_l_heure_a_Katmandou) + (décallage_entre_paris_et_katmandou_en_temps_reel * 3600)
		time_t heure_a_katmandou = temps_courant + (45 * 60) + ((3 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Katmandou en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_katmandou, "Katmandou");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Kaboul"...
	else if(strcmp(nom_de_la_ville,"Kaboul") == 0)
	{
		//Calcul de l'heure et de la date à Kaboul et stockage de celui-ci dans la variable heure_a_kaboul
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_kaboul = temps_heure_de_paris + (nombre_de_minutes_supplemantaires_pour_calculer_l_heure_a_Kaboul) + (décallage_entre_paris_et_kaboul_en_temps_reel * 3600)
		time_t heure_a_kaboul = temps_courant + (30 * 60) + ((2 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Kaboul en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_kaboul, "Kaboul");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Singapour"...
	else if(strcmp(nom_de_la_ville,"Singapour") == 0)
	{
		//Calcul de l'heure et de la date à Singapour et stockage de celui-ci dans la variable heure_a_singapour
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_singapour = temps_heure_de_paris + (décallage_entre_paris_et_singapour_en_temps_reel * 3600)
		time_t heure_a_singapour = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Singapour en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_singapour, "Singapour");
	}
	//Si la valeur contenue dans la chaine de caractére nom_de_la_ville est égale à "Hong Kong"...
	else if(strcmp(nom_de_la_ville,"Hong Kong") == 0)
	{
		//Calcul de l'heure et de la date à Hong Kong et stockage de celui-ci dans la variable heure_a_hong_kong
                //Explication simplifiée du calcul: heure_et_date_en_temps_reel_a_hong_kong = temps_heure_de_paris + (décallage_entre_paris_et_hong_kong_en_temps_reel * 3600)
		time_t heure_a_hong_kong = temps_courant + ((6 + application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(temps_courant)) * 3600);

		//L'heure et la date à Hong Kong en temps réel est retournée
		return calcul_et_renvoie_horaire(heure_a_hong_kong, "Hong Kong");
	}
	//Sinon...
	else
	{
		//
		return "Erreur: Le nom de la ville entré en paramétre est inconnue...pour le moment.";
	}
}
