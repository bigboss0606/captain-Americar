# I. Code 

Voir code dans le répertoire Ressources.

Nous avons corrigé quelques erreurs dans le code (Ex : oublie du signe moins sur l'angle de l'axe y lorsqu'il est négatif) et rajouter une condition
Pour que quand la voiture est stationnaire, on envoie 0/0. Ce n'était pas le cas avant ( On envoyait en boucle le dernier couple envoyé donnée, il n'était donc pas possible de s'arrêter).

De plus, pour des raisons inconnues, la marche arrière ne fonctionnait pas pour des valeurs supérieures (en valeur absolue) à -128. Les moteurs étaient au régime maximal à -128 puis si on dépassait cette valeur, les moteurs s'arrêtaient.
J'ai donc changer le map(), il va maintenant de 0 à -128 pour des valeurs de x négatives.

D'autre part, parfois la chaîne de caractère (couple Moteur1/Moteur2) était coupée, sûrement dû au fait que la partie gant envoyait plus d'information que ce que la partie voiture pouvait traiter ce qui provoque un décalage. Pour régler le problème, nous avons décidé d'envoyer le couple entre les lettres "D" et "F", indiquant le début et la fin d'une information.

Enfin, nous avions constaté lors des séances précédentes que naturellement, si l'on penche sa main vers l'avant (pour avancer), quand on tourne sa main,
(à gauche ou à droite) il est difficile de garder sa main inclinée vers l'avant. Donc puisque je soustrais à un moteur une valeur proportionnelle à l'angle
de l'axe y, je pouvais me retrouver avec une valeur négative (car angle_y>>angle_x). Cela avait pour conséquence de ne pas faire avancer et tourner la voiture.
Mais de la faire reculer et tourner dans la direction opposée. (Ex : au lieu d'avancer et de tourner à droite, elle reculait et tournait à gauche.).
Pour régler ce problème, j'ai fait en sorte pour que dans ce cas la valeur envoyée au moteur n'aille pas de 0 à 255, mais de 128 à 255.

On peut aussi noter l'ajout de commentaire et d'un code plus propre (meilleur nom de variable, print avec une phrase annonçant la valeur affichée).

# II. gant

Voir photo dans Ressources

Un fil de l'accéléromètre se détachait, ce qui avait pour conséquence de stopper le fonctionnement de l'accéléromètre (il ne peut pas redémarrer par lui-même, je pense.) je l'ai donc remplacé par un autre.
J'ai aussi retiré le surplus de colle qu'on avait mis sur la "boule" d'alimentation et de masse. Ce n'était pas très propre et rendait les réparations impossibles.
À la place, on a juste rajouté plus d'étain.

La batterie étant lourde ne tenait pas sur le gant. Pour régler ce problème, l'utilisateur tient juste la batterie dans la paume de sa main.
