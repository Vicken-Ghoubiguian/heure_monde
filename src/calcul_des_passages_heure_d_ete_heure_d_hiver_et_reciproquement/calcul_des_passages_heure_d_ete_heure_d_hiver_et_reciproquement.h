#ifndef HEURE_MONDE
#define HEURE_MONDE

#include <time.h>

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour le Chili) à l'aide du timestamp passé en paramétre
time_t date_du_changement_d_heure_d_ete_pour_le_chili(time_t aujourdhui);

//Cette fonction retourne le premier jour de la semaine dans un mois donnés en paramétre, calibré à l'heure passée en paramétre
time_t date_du_premier_jour_de_la_semaine_donne_du_mois_donne(time_t aujourdhui, int heure, int jour_de_la_semaine, int mois);

//Cette fonction retourne le niéme jour de la semaine dans un mois donnés en paramétre, calibré à l'heure passée en paramétre
time_t date_du_n_ieme_jour_de_la_semaine_donne_du_mois_donnee(time_t aujourdhui, int numero_voulu, int heure, int jour_de_la_semaine, int mois);

//Cette fonction retourne le dernier jour de la semaine dans un mois donnés en paramétre, calibré à l'heure passée en paramétre 
time_t date_du_dernier_jour_de_la_semaine_donne_du_mois_donnee(time_t aujourdhui, int heure, int jour_de_la_semaine, int mois);

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour les Fidji) à l'aide du timestamp passé en paramétre
time_t date_du_changement_d_heure_d_hiver_pour_les_fidji(time_t aujourdhui);

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'hiver (pour l'Iran) à l'aide du timestamp passé en paramétre
time_t date_du_changement_d_heure_d_hiver_pour_l_iran(time_t aujourdhui);

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour l'Iran) à l'aide du timestamp passé en paramétre
time_t date_du_changement_d_heure_d_ete_pour_l_iran(time_t aujourdhui);

//Cette fonction calcule puis retourne l'horaire (date et heure) du changement d'heure d'été (pour la Jordanie) à l'aide du timestamp passé en paramétre
time_t date_du_changement_d_heure_d_hiver_pour_la_jordanie(time_t aujourdhui);

#endif
