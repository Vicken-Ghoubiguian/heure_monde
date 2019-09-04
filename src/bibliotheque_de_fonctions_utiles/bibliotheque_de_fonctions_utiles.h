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

#endif
