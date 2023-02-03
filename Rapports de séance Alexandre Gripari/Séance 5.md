# I. "Bricolage"

Dans le but de poursuivre ce que nous avons commencé, nous avons vissé tous les composants à part le module Bluetooth (nous n'avons pas encore décidé de la position final) et le boîtier de pile qui se situera à l'étage supérieur de la voiture.
Nous avons aussi fixé les entretoises pour pouvoir fixer l'étage supérieur.

Rq : je suis passé d'une Arduino Uno à une Arduino Nano et remplacer la breadboard de base par une breadboard 2 lignes (je n'ai que besoin du 5V et la masse.)

# II. Traitement des données

Cette partie s'est annoncée plus difficile que prévu puisque l'information donnée par l'accéléromètre n'est pas directement utilisable.

Je m'explique, je reçois 2 informations :
+ l'angle selon l'axe x qui varie entre -90 et 90 degrés. (derriere/devant)
+ l'angle selon l'axe y qui varie entre -90 et 90 degrés. (gauche/droite)

Et je dois envoyer 2 informations :
+ la valeur analogique à attribuer au moteurA (0,255).
+ la valeur analogique à attribuer au moteurB (0,255).

Ici, une simple conversion ne suffit pas !!! ex : si l'accéléromètre renvoie 90/90, il ne faut pas mettre les 2 moteurs au maximum, mais il faudrait mettre le moteur gauche au maximum, et le moteur droit à mi-régime (on aurait alors le couple 255/127).
Les deux moteurs au maximum (255/255) correspond au couple (90/0).

Il y a aussi une différence au niveau des moteurs si l'on veut tourner à l'arrêt ou en avançant.

Si on est à l'arrêt il suffit de mettre en marche seulement le moteur opposé de la direction dans laquelle on veut tourner (ex : si on veut tourner à gauche, il faut
faire tourner le moteur et donc la roue droite).
Or, si on est en train d'avancer, il faut réduire la puissance du moteur de la direction dans laquelle on veut tourner ( ex : si on veut tourner à gauche, il faut réduire la puissance du moteur et donc de la roue de gauche).
Il faut donc traiter plusieurs cas.

Voici le code (qui n'a pas encore été testé avec la voiture) :
```
float angle_x = -(atan((a.acceleration.x) / sqrt(pow((a.acceleration.y),2) + pow((a.acceleration.z),2))) * 180/3.14);
  float angle_y = (atan((a.acceleration.y) / sqrt(pow((a.acceleration.x),2) + pow((a.acceleration.z),2))) * 180/3.14);
  if (angle_x >=20){
    if (angle_y>=0) {
      Moteur1 = map(angle_x,0,90,0,255);
      Moteur2 = map(angle_x,0,90,0,255) - map(angle_y,0,90,0,255);
    }
    else {
      Moteur1 = map(angle_x,0,90,0,255) + map(angle_y,-90,0,-255,0);
      Moteur2 = map(angle_x,0,90,0,255);
    }
  }
  if (angle_x<=-20){
    if (angle_y>=0) {
      Moteur1 = map(angle_x,-90,0,-255,0);
      Moteur2 = map(angle_x,-90,0,-255,0) + map(angle_y,0,90,0,255);
    }
    else {
      Moteur1 = map(angle_x,-90,0,-255,0) - map(angle_y,-90,0,-255,0);
      Moteur2 = map(angle_x,-90,0,-255,0);
    }
  }
  if ((angle_x<=20) && (angle_x>=-20)){
    if (angle_y >= 0) {
      Moteur1 = map(angle_y,0,90,0,255);
      Moteur2 = 0;
    }
    else {
      Moteur1 = 0;
      Moteur2 = map(angle_y,0,90,0,255);
    }
  }
  ```
