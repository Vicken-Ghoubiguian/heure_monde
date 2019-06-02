# heure_monde
Bibliothèque de fonctions de calcul et d'affichage de l'heure et de la date pour plusieurs villes du monde en temps reel à partir de l'heure et de la date courantes dans la tz timezone "Europe/Paris".

Cette bibliothèque évolue pour que l'heure et la date soit affichées pour tous les tz timezones nommées selon la nomenklature de la base d'Olsen.

Pour compiler le fichier main.c et le fichier heure_monde.c, faire la commande suivante:

$ gcc main.c heure_monde.c

Un fichier exécutable a.out est généré, il faut l'éxécuter à l'aide de la commande suivante:

$ ./a.out

Mais cette bibliothèque peut être intégrée dans votre projet C quelle qu'elle soit.
