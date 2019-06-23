#ifndef APPLICATION_DES_DECALAGES_HORAIRES
#define APPLICATION_DES_DECALAGES_HORAIRES

#include <time.h>

//Cette fonction permet d'appliquer le changement d'heure pour l'Europe continentale
int application_du_changement_d_heure_pour_l_europe_continentale(time_t temps_courant);

//Cette fonction permet d'appliquer le changement d'heure pour l'Amérique du Nord
int application_du_changement_d_heure_pour_l_amerique_du_nord(time_t temps_courant);

//Cette fonction permet d'appliquer le changement d'heure pour le Chili
int application_du_changement_d_heure_pour_le_chili(time_t temps_courant);

//Cette fonction permet d'appliquer le changement d'heure pour la Nouvelle Zelande
int application_du_changement_d_heure_pour_la_nouvelle_zelande(time_t temps_courant);

//Cette fonction permet d'appliquer le changement d'heure pour la Grande Bretagne
int application_du_changement_d_heure_pour_la_grande_bretagne(time_t temps_courant);

////Cette fonction permet d'appliquer le changement d'heure pour l'Australie
int application_du_changement_d_heure_pour_l_australie(time_t temps_courant);

//Cette fonction permet d'appliquer le changement d'heure pour le cas particulier de Lord Howe (en Australie)
int application_du_changement_d_heure_pour_le_cas_particulier_de_lord_howe(time_t temps_courant);

#endif