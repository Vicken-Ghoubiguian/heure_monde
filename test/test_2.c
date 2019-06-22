#include <stdio.h>
#include "../src/retour_de_la_date_et_de_l_heure.h"

int main()
{
        //
        char* premier_test = retour_de_l_heure_et_de_la_date_pour_une_ville_determinee_et_connue(time(NULL), "Seoul");

        //
        printf("%s\n", premier_test);

        //
        char* second_test = retour_de_l_heure_et_de_la_date_pour_une_ville_determinee_et_connue(time(NULL), "Addis-Abeba");

        //
        printf("%s\n", second_test);

        //
        char* troisieme_test = retour_de_l_heure_et_de_la_date_pour_une_ville_determinee_et_connue(time(NULL), "Hong Kong");

        //
        printf("%s\n", troisieme_test);

        //
        char* quatrieme_test = retour_de_l_heure_et_de_la_date_pour_une_ville_determinee_et_connue(time(NULL), "Enfin le dernier");

        //
        printf("%s\n", quatrieme_test);

        //
        return 0;
}
