#ifndef AFFICHAGE_DE_L_HORLOGE
#define AFFICHAGE_DE_L_HORLOGE

#include <time.h>

//Cette fonction permet de calculer et d'afficher les horaires pour une ville spécifiée en paramétre
void calcul_et_affichage_horaire(time_t temps, char* ville);

//Fonction de test pour l'affichage de tous les calculs d'horaires mises au point
void affichage_de_l_horloge(time_t temps_courant);

#endif
