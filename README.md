# heure_monde
API écrite en C pour le calcul et l'affichage de l'heure et de la date pour tous les fuseaux horaires du monde en temps reel à partir de l'heure et de la date correspondant au fuseau "Europe/Paris".

Cette API évolue pour que tous les fuseaux horaires nommés selon la nomenclature de la base d'Olson.

Pour compiler le fichier de test main.c et le fichier heure_monde.c, faire la commande suivante:

$ gcc test/main.c src/*.c

Un fichier exécutable a.out sera généré dans le répertoire principal de l'API, il faut l'éxécuter à l'aide de la commande suivante:

$ ./a.out

Mais cette API peut être intégrée dans n'importe quel projet développé en C.
