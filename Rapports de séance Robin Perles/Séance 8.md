# Rapport séance 8 Robin PERLES


## Changement d'alimentation

Auparavant, notre voiture était alimenté par un boitier de pile de 6V, on a remplacé cela par une pile de 9V. 
La voiture est beaucoup plus rapide et nerveuse. 

## Amélioration du code

On a ensuite révisé le code pour rendre les contrôles plus fluide, en utilisant des map().

## Correction d'un problème du module Bluetooth

Avant, le gant envoyé à la voiture des messages du type "puissanceA/puissanceB", mais parfois, quand la voiture récupérait les informations au mauvais moment, le message était coupé : "puissanceA/".
Cela provoqué des accoups de la voiture.
On a trouvé une solution : le gant envoi maintenant un message du type "DpuissanceA/puissanceBF".
La voiture change la vitesse des roues si le message contient bien "D", "F" et que le "D" est bien avant le "F".

