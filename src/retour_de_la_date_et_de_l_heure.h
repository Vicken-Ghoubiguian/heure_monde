#ifndef RETOUR_DE_LA_DATE_ET_DE_L_HEURE
#define RETOUR_DE_LA_DATE_ET_DE_L_HEURE

#include <time.h>

//Cette fonction permet de calculer et de renvoyer les horaires pour une ville spécifiée en paramétre
char* calcul_et_renvoie_horaire(time_t temps, char* ville);

//Cette fonction calcule puis retourne l'heure et la date pour une ville déterminée et connue passée en paramétre sous forme d'une chaine de caractères
char* retour_de_l_heure_et_de_la_date_pour_une_ville_determinee_et_connue(time_t temps_courant, char* nom_de_la_ville);

#endif
