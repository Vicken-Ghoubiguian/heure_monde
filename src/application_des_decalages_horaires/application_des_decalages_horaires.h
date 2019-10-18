#ifndef APPLICATION_DES_DECALAGES_HORAIRES
#define APPLICATION_DES_DECALAGES_HORAIRES

#include <time.h>

//Cette fonction permet d'appliquer le changement d'heure pour les Fidji 
void application_du_changement_d_heure_pour_les_fidji(time_t temps_utc);

//Cette fonction permet d'appliquer le changement d'heure pour le Brésil  
void application_du_changement_d_heure_pour_le_bresil(char* nom_de_la_timezone, time_t temps_utc);

//Cette fonction permet d'appliquer le changement d'heure pour la Syrie
void application_du_changement_d_heure_pour_la_syrie(time_t temps_utc);

//Cette fonction permet d'appliquer le changement d'heure pour Israel
void application_du_changement_d_heure_pour_israel(time_t temps_utc);

//Cette fonction permet d'appliquer le changement d'heure pour la Palestine
void application_du_changement_d_heure_pour_la_palestine(char* nom_de_la_timezone, time_t temps_utc);

//Cette fonction permet d'appliquer le changement d'heure pour le Liban
void application_du_changement_d_heure_pour_le_liban(time_t temps_utc);

//Cette fonction permet d'appliquer le changement d'heure pour l'Iran
void application_du_changement_d_heure_pour_l_iran(time_t temps_utc);

//Cette fonction permet d'appliquer le changement d'heure pour la Jordanie
void application_du_changement_d_heure_pour_la_jordanie(time_t temps_utc);

//Cette fonction permet d'appliquer le changement d'heure pour le Paraguay
void application_du_changement_d_heure_pour_le_paraguay(time_t temps_utc);

//Cette fonction permet d'appliquer le changement d'heure pour l'Europe continentale
int application_du_changement_d_heure_pour_l_europe_continentale(time_t temps_courant);

//Cette fonction permet d'appliquer le changement d'heure pour l'Amérique du Nord
int application_du_changement_d_heure_pour_l_amerique_du_nord(time_t temps_courant);

//Cette fonction permet d'appliquer le changement d'heure pour le Chili
void application_du_changement_d_heure_pour_le_chili(char* nom_de_la_timezone, time_t temps_courant);

//Cette fonction permet d'appliquer le changement d'heure pour la Nouvelle Zelande
void application_du_changement_d_heure_pour_la_nouvelle_zelande(char* nom_de_la_timezone, time_t temps_utc);

//Cette fonction permet d'appliquer le changement d'heure pour la Grande Bretagne
int application_du_changement_d_heure_pour_la_grande_bretagne(time_t temps_courant);

//Cette fonction permet d'appliquer le changement d'heure pour l'Australie
void application_du_changement_d_heure_pour_l_australie(char* nom_de_la_timezone, time_t temps_utc);

//Cette fonction permet d'appliquer le changement d'heure pour l'île Lord Howe
void application_du_changement_d_heure_pour_le_cas_particulier_de_lord_howe(time_t temps_utc);

//Cette fonction permet d'appliquer le changement d'heure pour les Samoa
void application_du_changement_d_heure_pour_les_samoa(time_t temps_utc);

//Cette fonction permet d'appliquer le changement d'heure pour la base antarctique de Troll
void application_du_changement_d_heure_pour_la_base_antarctique_de_troll(time_t temps_utc);

//Cette fonction permet d'appliquer le changement d'heure pour l'Europe continentale
void application_du_changement_d_heure_pour_l_europe_continentale_R(char* nom_de_la_timezone, time_t temps_utc);

#endif
