# I. Code 

Voir code dans le répertoire Ressources.

Nous avons corrigé quelques erreurs dans le code, (ex : oublie du signe moins sur l'angle en y lors de deuxième cas) et rajouter une condition
Pour que quand la voiture est stationnaire on envoie 0/0. Ce n'était pas le cas avant ( on envoyait en boucle la dernière donné, il n'était donc pas 
possible de s'arrêter).

De plus, pour des raisons inconnus la marche arrière ne fonctionnait pas pour des valeurs supérieurs (en valeur absolue) à -128. Les moteurs etaient au 
max à -128 puis si on dépassait cette valeur, les moteurs s'arrêtaient.
J'ai donc changer le map, il va maintenant de 0 à -128 pour des valeurs de x négatives.

D'autre part, parfois la chaine de caractère (couple Moteur1/Moteur2) était coupée, surement du au fait que la partie gant envoyait plus d'information que ce que la partie voiture pouvait traiter ce qui provoque un décalage. Pour régler le problème nous avons décider d'envoyer le couple entre les lettres "D" et "F", indiquant le début et la fin d'une information.

Enfin, nous avions constater lors des séances précédentes que naturellement, si l'on penche sa main vers l'avant (pour avancer), quand on tourne sa main 
(à gauche ou à droite), il est difficile de garder sa main incliner vers l'avant. Donc puisque je soustrais à un moteur une valeur proportionelle à l'angle
en y je pouvais me retrouver avec une valeur négative (car angle_y>>angle_x). Cela avait pour conséquences de ne pas faire avancer et tourner la voiture,
mais de la faire reculer et tourner dans la directions opposés. (ex : au lieu d'avancer et de tourner à droite, elle reculait et tournait à gauche). 
Pour régler ce problème j'ai fais en sorte pour que dans ce cas la valeur envoyé au moteur n'aille pas de 0 à 255 mais de 128 à 255.

On peut aussi l'ajout de commentaire et d'un code plus propre (meilleur nom de variable, print avec une phrase annonçant la valeur affichée).

# II. gant

Un fil de l'accéléromètre se détachait, ce qui avait pour conséquence de stopper le fonctionement de l'accéléromètre ( il ne peut pas redémarrer par 
lui même je pense), je l'ai donc remplacé par un autre.
J'ai aussi retirer le surplus de colle qu'on avait mis sur la "boule" d'alimentation et de masse. Ce n'était pas très propre et rendait les réparations impossible.
A la place on a juste rajouté plus d'etain.

La batterie étant lourdre ne tenait pas sur le gant. Pour régler ce problème l'utilisateur tiens juste la batterie dans la paume de sa main.
