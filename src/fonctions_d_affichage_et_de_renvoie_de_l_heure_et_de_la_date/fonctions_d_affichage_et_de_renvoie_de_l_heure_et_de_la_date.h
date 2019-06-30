#ifndef FONCTIONS_D_AFFICHAGE_ET_DE_RENVOIE_DE_L_HEURE_ET_DE_LA_DATE
#define FONCTIONS_D_AFFICHAGE_ET_DE_RENVOIE_DE_L_HEURE_ET_DE_LA_DATE

#include <time.h>

//Cette fonction permet de calculer et d'afficher les horaires pour une ville spécifiée en paramétre
void calcul_et_affichage_horaire(time_t temps, char* ville);

//Cette fonction permet de calculer et de renvoyer les horaires pour une ville spécifiée en paramétre
char* calcul_et_renvoie_horaire(time_t temps, char* ville);

//Cette fonction permet de calculer et de renvoyer la date et l'heure précise en fonction d'un timestamp (time_t) passé en paramétre
char* calcul_et_renvoie_de_l_heure_et_de_la_date_en_fonction_du_timestamp_passe_en_parametre(time_t temps);

#endif
