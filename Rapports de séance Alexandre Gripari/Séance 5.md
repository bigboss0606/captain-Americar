# I. "Bricolage"

Dans le but de poursuivre ce que nous avons commencé, nous avons vissé tout les composants à part le module bluetooth ( nous n'avons pas encore décider de
la position final) et le boitier de pile qui se situera à l'étage supérieur de la voiture.

Nous avons aussi fixer les entretoises pour pouvoir fixer l'étage supérieur.

Rq : Je suis passé d'une Arduino Uno à une Arduino Nano et remplacer la breadboard de base par une breadboard 2 lignes ( je n'ai que besoin du 5V et le masse).

# II. Traitement des données

Cette partie s'est annoncé plus difficile que prévu puisque l'information donné par l'accéléromètre n'est pas directement utilisable.

Je m'explique, je reçois 2 informations : 

 + l'angle selon l'axe x qui varie entre -90 et 90 degré. (derriere/devant)
 + l'angle selon l'axe y qui varie entre -90 et 90 degré. (gauche/droite)

Et je dois envoyer 2 informations :

+ la valeur analogique à attribuer au moteurA (0,255).
+ la valeur analogique à attrivuer au moteurB (0,255).

Ici une simple conversion ne suffit pas !!! ex : si je reçois 90/90, il ne faut pas mettre les 2 moteurs au maximum, mais il faudrait mettre le moteur gauche au maximum
et le moteur droit à mi-régime (on aurait alors le couple 255/127).
Les deux moteurs au maximum (255/255) correspond à (90/0).

Il y a aussi une différence au niveau des moteurs si l'on veut tourner à l'arret ou en avanceant.

Si on est à l'arret il suffit de mettre en marche seulement le moteur opposé de la direction dans laquelle on veut tourner (ex : si on veut tourner à gauche, il faut
faire tourner le moteur et donc la roue droite).

Or, si on est en train d'avancer il faut réduire la puissance du moteur de la direction dans laquelle on veut tourner ( ex : si on veut tourner à gauche, il faut réduire 
la puissance du moteur et donc de la roue de gauche).
