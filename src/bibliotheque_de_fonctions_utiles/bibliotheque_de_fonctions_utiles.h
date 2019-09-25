#ifndef BIBLIOTHEQUE_DE_FONCTIONS_UTILES
#define BIBLIOTHEQUE_DE_FONCTIONS_UTILES

#include <time.h>

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

//Cette fonction permet de récupérer pour un timezone passé en paramétre son indicateur pour déterminer si l'heure d'été s'applique ou non pour cette timezone
int recuperation_de_l_indicateur_d_application_de_l_heure_d_ete_pour_une_timezone_donnee(char* nom_de_la_timezone);

//Cette fonction permet de récupérer pour un timezone passé en paramétre son décalage horaire par rapport à l'UTC comme nombre de secondes 
int recuperation_du_decalage_horaire_pour_une_timezone_donnee(char* nom_de_la_timezone);

#endif
