#ifndef APPLICATION_DES_DECALAGES_HORAIRES
#define APPLICATION_DES_DECALAGES_HORAIRES

#include <time.h>

//Cette fonction permet de déterminer si il faut (ou non) en fonction du changement d'heure ajouter une heure (ou non) pour le calcul des fuseaux horaires de Pekin, Tokyo, Seoul, Moscou, et Vladivostok
int application_de_l_heure_d_ete_pour_les_fuseaux_sans_changements(time_t date);

//Cette fonction permet de calculer le decallage horaire d'Auckland (Nouvelle-Zelande) avec l'heure française
int calcul_du_decalage_avec_auckland(time_t aujourdhui);

//Cette fonction permet de calculer le decallage horaire de l'Australie avec l'heure française
int calcul_du_decalage_avec_l_australie(time_t aujourdhui);

//Cette fonction permet de calculer le decallage horaire de Santiago du Chili (Chili) avec l'heure française
int calcul_du_decalage_avec_le_chili(time_t aujourdhui);

//Cette fonction permet de calculer le decallage horaire de Los Angeles et de New York City (USA) avec l'heure française
int calcul_du_decalage_avec_l_amerique_du_nord(time_t aujourdhui);

//Cette fonction permet de calculer le decallage horaire de Londres avec l'heure française
int calcul_du_decallage_avec_la_grande_bretagne(time_t aujourdhui);

//
int application_du_changement_d_heure_pour_l_europe_continentale(time_t temps_courant);

//
int application_du_changement_d_heure_pour_l_amerique_du_nord(time_t temps_courant);

//
int application_du_changement_d_heure_pour_le_chili(time_t temps_courant);

//
int application_du_changement_d_heure_pour_la_nouvelle_zelande(time_t temps_courant);

//
int application_du_changement_d_heure_pour_la_grande_bretagne(time_t temps_courant);

#endif
