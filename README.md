# heure_monde
API écrite en C pour le calcul et l'affichage de l'heure et de la date pour tous les fuseaux horaires du monde en temps reel.

Deux fonctions permettent d'integrer l'API, ou de l'utiliser: affichage_de_l_horloge et retour_de_la_date_et_de_l_heure.

retour_de_la_date_et_de_l_heure permet de calculer l'heure et la date, pour un fuseau horaire passé en paramétre, à partir du temps UTC (Universal Time Coordinated).

affichage_de_l_horloge permet de calculer l'heure et la date, pour tous les fuseau horaires, à partir du temps UTC (Universal Time Coordinated).

Cette API évolue pour que tous les fuseaux horaires nommés selon la nomenclature de la base d'Olson.

Cette API ne nécessite aucune connexion internet, et peut être utilisée sur n'importe quelle machine (PC, serveur...), quelque soit son heure de référence, dans le monde.

Cet API se compose de 2 répertoires: src et test.

Le répertoire src est le coeur de l'API.

Celui-ci se compose de 6 bibliothéques, et chacune posséde un rôle spécifique dans l'API:

* calcul_des_passages_heure_d_ete_heure_d_hiver_et_reciproquement: Cette bibliothéque contient toutes les fonctions de calcul de passage de l'heure d'hiver à l'heure d'été, et réciproquement, pour tous les pays appliquants le changement d'heure.

* application_des_decalages_horaires: Cette bibliothéque contient toutes les fonctions d'application du décalage horaire, en prenant également en compte le changement d'heure.

* fonctions_d_affichage_et_de_renvoie_de_l_heure_et_de_la_date: Cette bibliothéque contient toutes les fonction qui permettent de mettre en forme, puis d'afficher ou de renvoyer l'heure et la date courante passées en paramétre relatives au fuseau horaire passé en paramétre.

* affichage_de_l_horloge: cette bibliothéque contient la fonction affichage_de_l_horloge qui sert à afficher l'heure et la date courante sur tous les fuseaux horaires du monde.

* retour_de_la_date_et_de_l_heure: Cette bibliothéque contient la fonction retour_de_l_heure_et_de_la_date_pour_un_fuseau_horaire_determine_et_connu qui sert à afficher l'heure et la date courante sur un fuseau horaire donné de part le monde.

* bibliotheque_de_fonctions_utiles: Cette bibliothéque contient toutes les fonctions de calcul et de manipulation pour le bon fonctionnement de l'API.

Le répertoire test contient deux fichier pour tester chacune des deux fonctions qui permettent d'utiliser l'API:

* le fichier test_1.c permet de tester la fonction affichage_de_l_horloge.

* le fichier test_2.c permet de tester la fonction retour_de_la_date_et_de_l_heure.

Pour compiler le fichier de test de la fonction affichage_de_l_horloge, faire la commande suivante:

$ gcc test/test_1.c src/(étoile_sur_le_clavier)/(étoile_sur_le_clavier).c

Pour compiler le fichier de test de la fonction retour_de_la_date_et_de_l_heure, faire la commande suivante:

$ gcc test/test_2.c src/(étoile_sur_le_clavier)/(étoile_sur_le_clavier).c

Dans les deux cas, un fichier exécutable a.out sera généré dans le répertoire principal de l'API, il faut l'éxécuter à l'aide de la commande suivante:

$ ./a.out

Si vous souhaitez nommer le fichier exécutable à générer sous un autre nom, faire la commande suivante:

$ gcc test/test_1.c src/(étoile_sur_le_clavier)/(étoile_sur_le_clavier).c -o nom_du_fichier_executable_que_vous_aurez_au_prealable_choisi

Cet exemple concerne le fichier de test de la fonction affichage_de_l_horloge.

Mais la même commande est à appliquer, de la même maniére, pour le fichier de test de la fonction retour_de_la_date_et_de_l_heure:

$ gcc test/test_2.c src/(étoile_sur_le_clavier)/(étoile_sur_le_clavier).c -o nom_du_fichier_executable_que_vous_aurez_au_prealable_choisi

A part cela, cette API peut être intégrée dans n'importe quel projet développé en C.
