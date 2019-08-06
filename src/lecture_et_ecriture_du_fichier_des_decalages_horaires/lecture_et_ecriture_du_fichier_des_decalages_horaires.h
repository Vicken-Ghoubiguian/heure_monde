#ifndef LECTURE_ET_ECRITURE_DU_FICHIER_DES_DECALAGES_HORAIRES
#define LECTURE_ET_ECRITURE_DU_FICHIER_DES_DECALAGES_HORAIRES

/* Inclusion des bibliothéques standards du C utilisées dans cette bibliothéque-ci */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Cette fonction permet de retourner le nombre correspondant au décalage horaire pour le fuseau situé dans la ligne passée en paramétre
int retour_du_nombre_correspondant_au_decalage_horaire_par_rapport_a_l_UTC_pour_un_fuseau_horaire_defini(int numero_de_la_ligne_demandee);

#endif
