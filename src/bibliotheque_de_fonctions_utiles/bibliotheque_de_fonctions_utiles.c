/* Inclusion des bibliothéques standards du C utilisées dans cette bibliothéque-ci */
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Inclusion des bibliothéques internes à l'API */
#include "bibliotheque_de_fonctions_utiles.h"

//Cette fonction renvoie l'année en cours à partir du temps local de la machine d'execution
int retour_de_l_annee_en_cours()
{

	//Déclaration de la variable temps_local_sous_forme_de_struct_tm: Cette variable contiendra le temps local (heure et date) sous forme de struct tm
        struct tm *temps_local_sous_forme_de_struct_tm;

	//
	int annee_en_cours;

        //Déclaration et initialisation de la variable temps_actuel_sous_forme_de_timestamp: Cette variable contient le temps actuel (heure et date) sous forme de timestamp
        time_t temps_local_sous_forme_de_timestamp = time(NULL);

	//
        temps_local_sous_forme_de_struct_tm = localtime(&temps_local_sous_forme_de_timestamp);

	//
	annee_en_cours = (temps_local_sous_forme_de_struct_tm->tm_year + 1900);

	//
	return annee_en_cours;

}

//Cette fonction renvoie le temps actuel (heure et date actuelles) UTC (Coordinated Universal Time), donc le temps universel coordonné
time_t retour_du_temps_utc_sous_forme_de_timestamp()
{

	//Déclaration de la variable temps_utc_sous_forme_de_struct_tm: Cette variable contiendra le temps UTC (heure et date) sous forme de struct tm
	struct tm *temps_utc_sous_forme_de_struct_tm;

	//Déclaration de la variable temps_utc_sous_forme_de_timestamp: Cette variable contiendra le temps UTC (heure et date) sous forme de timestamp
	time_t temps_utc_sous_forme_de_timestamp;

	//Déclaration et initialisation de la variable temps_actuel_sous_forme_de_timestamp: Cette variable contient le temps actuel (heure et date) sous forme de timestamp
	time_t temps_actuel_sous_forme_de_timestamp = time(NULL);

	//
	temps_utc_sous_forme_de_struct_tm = gmtime(&temps_actuel_sous_forme_de_timestamp);

	//
	temps_utc_sous_forme_de_timestamp = timegm(temps_utc_sous_forme_de_struct_tm);

	//Le temps UTC, sous forme de timestamp, est retourné
	return temps_utc_sous_forme_de_timestamp;

}

//Cette fonction détermine si une année passée en paramétre est une année bissextile selon le calendrier persan
/*

Petite explication: dans le calendrier persan (en vigueur en République islamique d'Iran et en République islamique d'Afghanistan), une année jalali (pas grégorien mais jalali) 

est bissextile si et seulement si le reste de la division de cette année par 33 est égal à 1 OU 5 OU 9 OU 13 OU 17 OU 22 OU 33.

*/
int est_une_annee_bissextile_selon_le_calendrier_persan(int annee)
{
	//Déclaration des variables locales utilisées dans la fonction est_une_annee_bissextile_selon_le_calendrier_persan
	int annee_jalali;
	int hegire = 622;

	//
	annee_jalali = (annee - 622) + 1;

	//Si le reste de la division de l'année passée en paramétre (convertie en année jalali) par 33 est égal à 1 OU 5 OU 9 OU 13 OU 17 OU 22 OU 26 OU 30 alors...
	if((annee_jalali % 33 == 1) || (annee_jalali % 33 == 5) || (annee_jalali % 33 == 9) || (annee_jalali % 33 == 13) || (annee_jalali % 33 == 17) || (annee_jalali % 33 == 22) || (annee_jalali % 33 == 26) || (annee_jalali % 33 == 30))
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

//
int est_une_annee_qui_va_par_paire_de_quatre_selon_le_calendrier_persan(int annee)
{
	//Déclaration des variables locales utilisées dans la fonction est_une_annee_qui_va_par_paire_de_quatre_selon_le_calendrier_persan
        int annee_jalali;
        int hegire = 622;

        //
        annee_jalali = (annee - 622) + 1;

	//
	if(annee_jalali % 4 == 3)
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

//Cette fonction renvoie le timestamp courant avec plusieurs années de différence (en fonction de l'année passée en paramétre de la fonction)
time_t fonction_de_precision_de_l_annee_en_cours(time_t timestamp_du_temps_courant, int annee_particuliere_voulue)
{

	//Declaration des variables
	struct tm *horaire = gmtime(&timestamp_du_temps_courant);
	time_t timestamp_du_temps_voulu_a_retourner;
	int annee_particuliere_voulue_mis_sous_format_du_champ_tm_year_du_struct_tm;

	//Calcul de l'année voulu sous format attendu par le struct tm pour le cham:ps tm_year, et afféctation de celui-ci dans la variable annee_particuliere_voulue_mis_sous_format_du_champ_tm_year_du_struct_tm
	annee_particuliere_voulue_mis_sous_format_du_champ_tm_year_du_struct_tm = annee_particuliere_voulue - 1900;

	//Afféctation au champs tm_year de la structure tm de l'année particuliére passée en paramétre de la fonction fonction_de_precision_de_l_annee_en_cours
	horaire->tm_year = annee_particuliere_voulue_mis_sous_format_du_champ_tm_year_du_struct_tm;

	//Après cette opération, la structure tm horaire est convertie en timestamp via la fonction timegm, et le résultat est affécté à la variable timestamp_du_temps_voulu_a_retourner
	timestamp_du_temps_voulu_a_retourner = timegm(horaire);

	//Puis, le résultat est retourné
	return timestamp_du_temps_voulu_a_retourner;

}

//Cette fonction permet de compter le nombre total de lignes dans le fichier des decalages horaires
int fonction_de_comptage_du_nombre_de_lignes_dans_le_fichier_des_decalages_horaires()
{
	//Déclaration des variables utilisées dans la fonction fonction_de_comptage_du_nombre_de_lignes_dans_le_fichier_des_decalages_horaires
        FILE* fichier_des_decalages_horaires;
        int nombre_de_lignes_comptabilisees_dans_le_fichier_des_decalages_horaires = 0;
        char caractere_courant;

	//Ouverture du fichier fichier_des_decalages_horaires.txt et enregistrement du résultat de celui-ci dans la variable de type FILE* fichier_des_decalages_horaires
        fichier_des_decalages_horaires = fopen("fichier_des_decalages_horaires.txt", "r");

	//Si la variable contenant le résultat de l'opération d'ouverture du fichier fichier_des_decalages_horaires.txt est différent de NULL (opération reussie), alors...
        if(fichier_des_decalages_horaires != NULL)
        {
		//
                while((caractere_courant = fgetc(fichier_des_decalages_horaires)) != EOF)
                {
			//Si le caractére courant est égal au caractére spécial du saut de ligne ('\n'), alors...
                        if(caractere_courant == '\n')
                        {
				//
                                nombre_de_lignes_comptabilisees_dans_le_fichier_des_decalages_horaires = nombre_de_lignes_comptabilisees_dans_le_fichier_des_decalages_horaires + 1;
                        }
                }

		//On ferme le descripteur du fichier des décalages horaires, ouvert (la variable fichier_des_decalages_horaires)
                fclose(fichier_des_decalages_horaires);
        }
	//Sinon...
        else
        {
		//Un message d'erreur est affiché
                printf("Erreur: impossible d'ouvrir le fichier des decalages horaires.\n");

		//On quite le processus avec une erreur
                exit(1);
        }

	//Le résultat de la fonction (le nombre de lignes stocké dans la variable nombre_de_lignes_comptabilisees_dans_le_fichier_des_decalages_horaires) est retournée
        return nombre_de_lignes_comptabilisees_dans_le_fichier_des_decalages_horaires;
}

//Cette fonction permet de lire une ligne identifiée par un numéro passé en paramétre dans le fichier des décalages horaires
char* fonction_de_lecture_du_fichier_des_decalages_horaires_a_la_ligne_passee_en_parametre(int numero_de_la_ligne_demandee)
{
	//Déclaration des variables utilisées dans la fonction fonction_de_comptage_du_nombre_de_lignes_dans_le_fichier_des_decalages_horaires
        FILE* fichier_des_decalages_horaires;
        char* ligne_courante;
        char* ligne_demandee = "";
        int numero_de_la_ligne_courante = 1;
        int nombre_de_lignes_au_total_dans_le_fichier_des_decalages_horaires = fonction_de_comptage_du_nombre_de_lignes_dans_le_fichier_des_decalages_horaires();
        size_t longueur_de_la_ligne = 0;
        ssize_t lecture;

	//Ouverture du fichier fichier_des_decalages_horaires.txt et enregistrement du résultat de celui-ci dans la variable de type FILE* fichier_des_decalages_horaires
        fichier_des_decalages_horaires = fopen("fichier_des_decalages_horaires.txt", "r");

	//Si la variable contenant le résultat de l'opération d'ouverture du fichier fichier_des_decalages_horaires.txt est différent de NULL (opération reussie), alors...
        if(fichier_des_decalages_horaires != NULL)
        {
		//
                if(numero_de_la_ligne_demandee > 0 && numero_de_la_ligne_demandee <= nombre_de_lignes_au_total_dans_le_fichier_des_decalages_horaires)
                {
			//
                        while((lecture = getline(&ligne_courante, &longueur_de_la_ligne, fichier_des_decalages_horaires)) != -1)
                        {
				//Si le numéro de la ligne courante correspond au numéro de la ligne demandée en paramétre, alors...
                                if(numero_de_la_ligne_courante == numero_de_la_ligne_demandee)
                                {
					//La valeur contenue dans la variable ligne_courante est affectée à la variable ligne_demandee 
                                        ligne_demandee = ligne_courante;

					//On quite la boucle grace à l'instruction break
                                        break;
                                }

				//
                                numero_de_la_ligne_courante = numero_de_la_ligne_courante + 1;
                        }

			//
                        free(ligne_courante);

			//On ferme le descripteur du fichier des décalages horaires, ouvert (la variable fichier_des_decalages_horaires)
                        fclose(fichier_des_decalages_horaires);
                }
		//Sinon...
                else
                {
			//Un message d'erreur est affiché
                        printf("Erreur: le nombre de lignes passé en paramétre n'est pas valide (soit inférieur à 0 ou égal, soit supérieur au nombre exact de lignes dans le fichier des décalages horaires).\n");

			//On quite le processus avec une erreur
                        exit(1);
                }
        }
	//Sinon...
	else
        {
		//Un message d'erreur est affiché
                printf("Erreur: impossible d'ouvrir le fichier des decalages horaires.\n");

		//On quite le processus avec une erreur
                exit(1);
        }

	//Le résultat de la fonction (la ligne demandée stocké dans la variable ligne_demandee) est retournée
        return ligne_demandee;
}

//Cette fonction permet de retourner le nombre correspondant au décalage horaire pour le fuseau situé dans la chaine de caractéres passée en paramétre
int retour_du_nombre_correspondant_au_decalage_du_fuseau_horaire_par_rapport_a_l_UTC_depuis_le_fichier_des_decalages_horaires(char* chaine_de_caracteres_demandee)
{
        //Déclaration des variables utilisées dans la fonction retour_du_nombre_correspondant_au_decalage_du_fuseau_horaire_par_rapport_a_l_UTC_depuis_le_fichier_des_decalages_horaires
        char* resultat_du_decoupage_de_la_chaine;
        int nombre_correspondant_au_decalage_du_fuseau_horaire_par_rapport_a_l_UTC;

        //
        resultat_du_decoupage_de_la_chaine = strstr(chaine_de_caracteres_demandee, ";");

        //
        nombre_correspondant_au_decalage_du_fuseau_horaire_par_rapport_a_l_UTC = atoi(&resultat_du_decoupage_de_la_chaine[1]);

        //La valeur contenue dans la variable nombre_correspondant_au_decalage_du_fuseau_horaire_par_rapport_a_l_UTC est retournée
        return nombre_correspondant_au_decalage_du_fuseau_horaire_par_rapport_a_l_UTC;
}
