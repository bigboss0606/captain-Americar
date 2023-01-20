# I. Identification de problèmes

Jusqu'à maintenant, on avait beacoup de problème concernant l'appareillage des 2 modules Bluetooth. En réalisant quelque test j'ai constaté qu'il fallait les
démarer en même pour que l'appareillage se fasse rapidement et sans problème. En effet le module Bluetooth relié à l'accéléromètre est constament alimenté puisque 
pour l'instant branché sur l'ordinateur. Ce n'est pas le cas pour l'autre module Bluetooth qui est etteint pour économiser de la batterie sur les piles de
la voiture. Il faut donc lors du démarage de la voiture débrancher et rebrancher la carte sur l'odinateur pour véritablement re-démarrer le module Bluetooth.

Concernant le problème de l'accéléromètre (séance 3) le fil était bien la cause puisque je n'ai plus eu de problème pendant toute l'heure.

# II. De Nouveaux horizons

C'est définitivement la fin de coquillette-mobile. En effet, la boite de pates n'était pas assez résistance pour supporter le poid des moteurs. Pendant 
la séance nous avons donc réaliser sur une planche en bois les trous nécésaire à l'aide d'une perceuse pour pouvoir fixer les deux moteurs (+roues) et la 
rouge de guidage. 

En fin de l'heure nous avons pensé à la disposition des composants : le boitier de pile doit etre facile d'accès, idem pour la carte arduino
s'il y a des changements à faire par exemple. Nous avons ainsi rélaiser tous les trous nécéssaire pour pouvoir fixer les composants et l'entretoise au cours 
prochain.

# III. Amélioration restante

Même si nous pouvons déjà diriger la voiture en inclinant l'accéléromètre il reste beaucoup d'amélioration à faire :

### 1) Code

Grace à la fonction Map je peux convertir l'angle en degré qui varie entre -90 et 0 ou 0 et 90 en une valeur entre 0 et 255 (pour les moteurs).
Le problème et qu'il faut maintenant trouver un moyen de traiter cette information.

### 2) Esthétique




  
