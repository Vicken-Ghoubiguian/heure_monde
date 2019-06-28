#ifndef RETOUR_DE_LA_DATE_ET_DE_L_HEURE
#define RETOUR_DE_LA_DATE_ET_DE_L_HEURE

#include <time.h>

//Cette fonction calcule puis retourne l'heure courant et la date courante pour un fuseau horaire déterminé et connu passé en paramétre sous forme d'une chaine de caractères
/*
	Explication du calcul:

	Prenons un fuseau horaire quelconque noté zone_quelquonque/fuseau_horaire_quelquonque.

	Définissons, pour le fuseau horaire zone_quelquonque/fuseau_horaire_quelquonque, les régles suivantes:

	-> Sur le fuseau zone_quelquonque/fuseau_horaire_quelquonque: UTC+03:00 (heure d'hiver),

	-> Sur le fuseau zone_quelquonque/fuseau_horaire_quelquonque: UTC+04:00 (heure d'été).

	UTC étant la notation officielle pour "Universel Temps Coordonné": échelle de temps adoptée comme base du temps civil international par la majorité des pays du globe (wikipedia).

	Donc:

	-> heure_pour_fuseau_horaire_quelquonque = temps_utc_courant_en_temps_reel + (nombre_de_minutes_de_decalage_entre_l_utc_et_le_fuseau_horaire_quelquonque * nombre_de_secondes_dans_une_minute) + ((nombre_d_heure_de_decalage_entre_l_utc_et_le_fuseau_horaire_quelquonque * nombre_de_secondes_dans_une_heure) + (application_du_changement_d_heure_pour_le_fuseau_horaire_quelquonque * nombre_de_secondes_dans_une_heure))

	Avec:

	-> nombre_de_secondes_dans_une_heure = 3600 (une heure étant composée de 3600 secondes),

	-> nombre_de_secondes_dans_une_minute = 60 (une minute étant composée de 60 secondes).

	application_du_changement_d_heure_pour_le_fuseau_horaire_quelquonque est une fonction qui applique, pour le fuseau zone_quelquonque/fuseau_horaire_quelquonque, le changement d'heure (d'hiver à été et réciproquement) selon les régles établies par le pays, ou la zone géographique, dans lequel est situé le fuseau zone_quelquonque/fuseau_horaire_quelquonque.
*/
char* retour_de_l_heure_et_de_la_date_pour_une_ville_determinee_et_connue(char* nom_de_la_ville);

#endif
