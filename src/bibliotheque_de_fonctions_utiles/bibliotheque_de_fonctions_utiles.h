#ifndef BIBLIOTHEQUE_DE_FONCTIONS_UTILES
#define BIBLIOTHEQUE_DE_FONCTIONS_UTILES

#include <time.h>

//Cette fonction renvoie l'année en cours à partir du temps local de la machine d'execution
int retour_de_l_annee_en_cours();

//Cette fonction permet de retourner le numéro du jour du mois pour le changement d'heure en Iran
int retour_du_numero_du_jour_du_mois_pour_le_changement_d_heure_pour_l_iran(int annee);

//Cette fonction renvoie le temps actuel (heure et date actuelles) UTC (Coordinated Universal Time), donc le temps universel coordonné
time_t retour_du_temps_utc_sous_forme_de_timestamp();

//Cette fonction renvoie le timestamp courant avec plusieurs années de différence (en fonction de l'année passée en paramétre de la fonction)
time_t fonction_de_precision_de_l_annee_en_cours(time_t timestamp_du_temps_courant, int annee_particuliere_voulue);

//Cette fonction permet de mettre à jour la valeur de l'indicateur d'application de l'heure d'été pour une timezone donnée
void mise_a_jour_de_l_indicateur_d_application_de_l_heure_d_ete(char* nom_de_la_timezone, int nouvelle_valeur_pour_l_indicateur_d_application_de_l_heure_d_ete_pour_la_timezone_donnee);

//Cette fonction permet de récupérer pour un timezone passé en paramétre son indicateur pour déterminer si l'heure d'été s'applique ou non pour cette timezone
int recuperation_de_l_indicateur_d_application_de_l_heure_d_ete_pour_une_timezone_donnee(char* nom_de_la_timezone);

//Cette fonction permet de récupérer pour un timezone passé en paramétre son décalage horaire par rapport à l'UTC comme nombre de secondes
int recuperation_du_decalage_horaire_courant_hors_DST_pour_une_timezone_donnee(char* nom_de_la_timezone);

//Cette fonction permet de récupérer pour un timezone passé en paramétre son décalage horaire par rapport à l'UTC comme nombre de secondes 
int recuperation_du_decalage_horaire_pour_une_timezone_donnee(char* nom_de_la_timezone);

#endif
