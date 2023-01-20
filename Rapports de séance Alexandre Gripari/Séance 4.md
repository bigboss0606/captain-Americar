# I. Identification de problèmes

Jusqu'à maintenant, on avait beaucoup de problèmes concernant l'appareillage des 2 modules Bluetooth. En réalisant quelques tests, j'ai constaté qu'il fallait les démarrer en même pour que l'appareillage se fasse rapidement et sans problème. En effet, le module Bluetooth relié à l'accéléromètre est constamment alimenté puisque qu'il est pour l'instant branché sur l'ordinateur. Ce n'est pas le cas pour l'autre module Bluetooth qui est éteint pour économiser de la batterie sur les piles de la voiture. Il faut donc lors du démarrage de la voiture débrancher et rebrancher la carte sur l'ordinateur pour véritablement redémarrer le module Bluetooth.
Concernant le problème de l'accéléromètre (séance 3) le fil était bien la cause puisque je n'ai plus eu de problème pendant toute l'heure.

# II. De Nouveaux horizons

C'est définitivement la fin de coquillette-mobile. En effet, la boite de pâtes n'était pas assez résistante pour supporter le poid des moteurs. Pendant la séance nous avons donc réaliser sur une planche en bois les trous nécésaire à l'aide d'une perceuse pour pouvoir fixer les deux moteurs (+roues) et la
roue de guidage.

En fin de l'heure, nous avons pensé à la disposition des composants : le boîtier de pile doit être facile d'accès, idem pour la carte arduino
s'il y a des changements à faire par exemple. Nous avons ainsi réalisé tous les trous nécéssaire pour pouvoir fixer les composants et l'entretoise au cours
prochain

# III. Améliorations restantes

Même si nous pouvons déjà diriger la voiture en inclinant l'accéléromètre, il reste beaucoup d'amélioration à faire :

Grâce à la fonction Map je peux convertir l'angle en degré qui varie entre -90 et 0 ou 0 et 90 en une valeur entre 0 et 255 (pour les moteurs).
Le problème et qu'il faut maintenant trouver un moyen de traiter cette information.

Pour avoir un prototype encore fonctionnel pour la démonstration, je n'ai pas encore fait les changements de branchements de l'arduino Uno à la Nano.
Il nous faut aussi une breadboard plus petites et un autre module de pile pour avoir un système totalement indépendant.






  
