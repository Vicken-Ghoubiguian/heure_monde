# heure_monde
API écrite en C pour le calcul et l'affichage de l'heure et de la date pour tous les fuseaux horaires du monde en temps reel.

Deux fonctions permettent d'integrer l'API, ou de l'utiliser: affichage_de_l_horloge et retour_de_la_date_et_de_l_heure.

retour_de_la_date_et_de_l_heure permet de calculer l'heure et la date, pour un fuseau horaire passé en paramétre, à partir du temps UTC (Universal Time Coordinated).

affichage_de_l_horloge permet de calculer l'heure et la date, pour tous les fuseau horaires, à partir du temps UTC (Universal Time Coordinated).

Cette API évolue pour que l'heure courante et la date courante soient calculées puis affichées ou retournées pour tous les fuseaux horaires du monde entier, nommés selon la nomenclature de la base d'Olson.

Cette API ne nécessite aucune connexion internet, et peut être utilisée sur n'importe quelle machine (PC, serveur...), quelque soit son heure de référence, dans le monde.

Cet API se compose de 2 répertoires: src et test.

Le répertoire src est le coeur de l'API.

Celui-ci se compose de 6 bibliothéques, et chacune posséde un rôle spécifique dans l'API:

* calcul_des_passages_heure_d_ete_heure_d_hiver_et_reciproquement: Cette bibliothéque contient toutes les fonctions de calcul de passage de l'heure d'hiver à l'heure d'été, et réciproquement, pour tous les pays appliquants le changement d'heure.

* application_des_decalages_horaires: Cette bibliothéque contient toutes les fonctions d'application du décalage horaire, en prenant également en compte le changement d'heure.

* fonctions_d_affichage_et_de_renvoie_de_l_heure_et_de_la_date: Cette bibliothéque contient toutes les fonction qui permettent de mettre en forme, puis d'afficher ou de renvoyer l'heure et la date courante passées en paramétre relatives au fuseau horaire passé en paramétre.

* affichage_de_l_horloge: cette bibliothéque contient la fonction affichage_de_l_horloge qui sert à afficher l'heure et la date courante sur tous les fuseaux horaires du monde.

* retour_de_la_date_et_de_l_heure: Cette bibliothéque contient la fonction retour_de_l_heure_et_de_la_date_pour_un_fuseau_horaire_determine_et_connu qui sert à afficher l'heure et la date courante sur un fuseau horaire donné de part le monde.

* bibliotheque_de_fonctions_utiles: Cette bibliothéque contient toutes les fonctions de calcul et de manipulation pour le bon fonctionnement de l'API. Elle contient également la base heure_monde.db et le script SQL de création de celle-ci, avec la création de la table table_des_decalages_horaires et l'insertion des données dans celle-ci.

Le répertoire test contient tois fichier: 2 pour tester chacune des 2 fonctions qui permettent d'utiliser l'API (affichage_de_l_horloge et retour_de_la_date_et_de_l_heure), et 1 pour tester les dates et heures lors d'un changement d'heure pour une année donnée pour toutes les zones géographiques appliquant le changement d'heure:

* le fichier test_1.c permet de tester la fonction affichage_de_l_horloge,

* le fichier test_2.c permet de tester la fonction retour_de_la_date_et_de_l_heure,

* le fichier test_3.c permet de tester les dates et heures lors d'un changement d'heure pour une année donnée pour toutes les zones géographiques appliquant le changement d'heure.

Pour compiler le fichier de test de la fonction affichage_de_l_horloge, faire la commande suivante:

$ gcc test/test_1.c src/(étoile_sur_le_clavier)/(étoile_sur_le_clavier).c -lsqlite3

Pour compiler le fichier de test de la fonction retour_de_la_date_et_de_l_heure, faire la commande suivante:

$ gcc test/test_2.c src/(étoile_sur_le_clavier)/(étoile_sur_le_clavier).c -lsqlite3

Pour compiler le fichier pour tester les dates et heures lors d'un changement d'heure pour une année donnée pour toutes les zones géographiques appliquant le changement d'heure, faire la commande suivante:

$ gcc test/test_3.c src/(étoile_sur_le_clavier)/(étoile_sur_le_clavier).c -lsqlite3

Dans les 3 cas, un fichier exécutable a.out sera généré dans le répertoire principal de l'API, il faut l'éxécuter à l'aide de la commande suivante:

$ ./a.out

Si vous souhaitez nommer le fichier exécutable à générer sous un autre nom, faire la commande suivante:

$ gcc test/test_1.c src/(étoile_sur_le_clavier)/(étoile_sur_le_clavier).c -o nom_du_fichier_executable_que_vous_aurez_au_prealable_choisi -lsqlite3

Cet exemple concerne le fichier de test de la fonction affichage_de_l_horloge.

Mais la même commande est à appliquer, de la même maniére, pour le fichier de test de la fonction retour_de_la_date_et_de_l_heure:

$ gcc test/test_2.c src/(étoile_sur_le_clavier)/(étoile_sur_le_clavier).c -o nom_du_fichier_executable_que_vous_aurez_au_prealable_choisi -lsqlite3

Ainsi que pour le fichier pour tester les dates et heures lors d'un changement d'heure pour une année donnée pour toutes les zones géographiques appliquant le changement d'heure:

$ gcc test/test_3.c src/(étoile_sur_le_clavier)/(étoile_sur_le_clavier).c -o nom_du_fichier_executable_que_vous_aurez_au_prealable_choisi -lsqlite3

L'option -lsqlite3 sert à inclure la librairie <sqlite3.h> dans le projet en cours. Celle-ci permet d'effectuer les opérations SQL sur des bases SQLite.

La base de données heure_monde.db doit être créee dans le répertoire src/bibliotheque_de_fonctions_utiles.

Elle est crée grace à la commande suivante: 

$ sqlite3 heure_monde.db

Une fois créee, il faut créer la table table_des_decalages_horaires puis la remplir, toutes ces opérations éffectuées depuis le fichier heure_monde.sql.

Pour cela éffectuer la commande suivante tout de suite après la commande de création de la base SQLITE heure_monde (ci-dessus):

sqlite> .read heure_monde.sql

A part cela, cette API peut être intégrée dans n'importe quel projet développé en C.
