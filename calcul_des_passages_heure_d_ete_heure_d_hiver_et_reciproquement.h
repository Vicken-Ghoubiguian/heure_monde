#ifndef HEURE_MONDE
#define HEURE_MONDE

#include <time.h>

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour les pays européens) à l'aide du timestamp et de l'heure (1 pour la Grande Bretagne et 2 pour la France) passé en paramétre
time_t date_du_dernier_dimanche_de_mars(time_t aujourdhui, int heure);

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver (pour les pays européens) à l'aide du timestamp et de l'heure (2 pour la Grande Bretagne et 3 pour la France) passé en paramétre
time_t date_du_dernier_dimanche_d_octobre(time_t aujourdhui, int heure);

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver (pour l'Australie et la Nouvelle-Zélande) à l'aide du timestamp et de l'heure (2 pour l'Australie, 3 pour la Nouvelle-Zélande) passés en paramétres
time_t date_du_premier_dimanche_d_avril(time_t aujourdhui, int heure);

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour l'Australie) à l'aide du timestamp passé en paramétre
time_t date_du_premier_dimanche_d_octobre(time_t aujourdhui);

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver pour les USA à l'aide du timestamp
time_t date_du_premier_dimanche_de_novembre(time_t aujourdhui);

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour les USA) à l'aide du timestamp passé en paramétre
time_t date_du_deuxieme_dimanche_de_mars(time_t aujourdhui);

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver (pour le Chili) à l'aide du timestamp passé en paramétre
time_t date_du_deuxieme_dimanche_de_mai(time_t aujourdhui);

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour le Chili) à l'aide du timestamp passé en paramétre
time_t date_du_deuxieme_dimanche_d_aout(time_t aujourdhui);

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour la Nouvelle-Zelande) à l'aide du timestamp passé en paramétre
time_t date_du_dernier_dimanche_de_septembre(time_t aujourdhui);

#endif