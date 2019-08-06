/* Inclusion des bibliothéques standards du C utilisées dans cette bibliothéque-ci */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Inclusion de la bibliothéque interne bibliotheque_de_fonctions_utiles/bibliotheque_de_fonctions_utiles à l'API */
#include "../bibliotheque_de_fonctions_utiles/bibliotheque_de_fonctions_utiles.h"

//Cette fonction permet de retourner le nombre correspondant au décalage horaire pour le fuseau situé dans la ligne passée en paramétre
int retour_du_nombre_correspondant_au_decalage_horaire_par_rapport_a_l_UTC_pour_un_fuseau_horaire_defini(int numero_de_la_ligne_demandee)
{
        //Déclaration de la variable ligne_demandee et affectation à cette variable de la ligne lue
        char* ligne_demandee = fonction_de_lecture_du_fichier_des_decalages_horaires_a_la_ligne_passee_en_parametre(numero_de_la_ligne_demandee);

        //
        int nombre_correspondant_au_decalage_du_fuseau_horaire_par_rapport_a_l_UTC_pour_le_fuseau_demande = retour_du_nombre_correspondant_au_decalage_du_fuseau_horaire_par_rapport_a_l_UTC_depuis_le_fichier_des_decalages_horaires(ligne_demandee);

        //La valeur contenue dans la variable nombre_correspondant_au_decalage_du_fuseau_horaire_par_rapport_a_l_UTC_pour_le_fuseau_demande est retournée
        return nombre_correspondant_au_decalage_du_fuseau_horaire_par_rapport_a_l_UTC_pour_le_fuseau_demande;
}
