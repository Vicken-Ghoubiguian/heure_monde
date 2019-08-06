#ifndef BIBLIOTHEQUE_DE_FONCTIONS_UTILES
#define BIBLIOTHEQUE_DE_FONCTIONS_UTILES

#include <time.h>

//Cette fonction permet de retourner le nombre correspondant au décalage horaire pour le fuseau situé dans la chaine de caractéres passée en paramétre
int retour_du_nombre_correspondant_au_decalage_du_fuseau_horaire_par_rapport_a_l_UTC_depuis_le_fichier_des_decalages_horaires(char* chaine_de_caracteres_demandee);

//Cette fonction renvoie l'année en cours à partir du temps local de la machine d'execution
int retour_de_l_annee_en_cours();

//
int est_une_annee_qui_va_par_paire_de_quatre_selon_le_calendrier_persan(int annee);

//Cette fonction détermine si une année passée en paramétre est une année bissextile selon le calendrier persan
int est_une_annee_bissextile_selon_le_calendrier_persan(int annee);

//Cette fonction renvoie le temps actuel (heure et date actuelles) UTC (Coordinated Universal Time), donc le temps universel coordonné
time_t retour_du_temps_utc_sous_forme_de_timestamp();

//Cette fonction renvoie le timestamp courant avec plusieurs années de différence (en fonction de l'année passée en paramétre de la fonction)
time_t fonction_de_precision_de_l_annee_en_cours(time_t timestamp_du_temps_courant, int annee_particuliere_voulue);

//Cette fonction permet de compter le nombre total de lignes dans le fichier des decalages horaires
int fonction_de_comptage_du_nombre_de_lignes_dans_le_fichier_des_decalages_horaires();

//Cette fonction permet de lire une ligne identifiée par un numéro passé en paramétre dans le fichier des décalages horaires
char* fonction_de_lecture_du_fichier_des_decalages_horaires_a_la_ligne_passee_en_parametre(int numero_de_la_ligne_demandee);

#endif
