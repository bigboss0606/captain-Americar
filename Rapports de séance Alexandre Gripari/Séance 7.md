# I. Code :

Amélioration du code, j’ai amélioré le code pour que la voiture soit plus maniable.
 Même s'il serait mieux de le simplifier puisque pour l’instant, nous traitons chaque cas (le programme est un enchaînement de if, else if, else ce qui n'est pas très propre est peu lisible.).



```
float angle_x = -(atan((a.acceleration.x) / sqrt(pow((a.acceleration.y),2) + pow((a.acceleration.z),2))) * 180/3.14);
  float angle_y = (atan((a.acceleration.y) / sqrt(pow((a.acceleration.x),2) + pow((a.acceleration.z),2))) * 180/3.14);
  if (angle_x >=20){
    if (angle_y>=20) {
      Moteur1 = map(angle_x,0,70,0,255);
      Moteur2 = map(angle_x,0,70,0,255) - map(angle_y,0,70,0,127);
    }
    else if (angle_y<20) {
      Moteur1 = map(angle_x,0,70,0,255) + map(angle_y,-70,0,-127,0);
      Moteur2 = map(angle_x,0,70,0,255);
    }
    else {
      Moteur1 = map(angle_x,0,70,0,255);
      Moteur2 = map(angle_x,0,70,0,255);
    }
  }
  if (angle_x<=-20){
    if (angle_y>=20) {
      Moteur1 = map(angle_x,-70,0,-255,0);
      Moteur2 = map(angle_x,-70,0,-127,0) + map(angle_y,0,70,0,255);
    }
    else if (angle_y<20) {
      Moteur1 = map(angle_x,-70,0,-127,0) - map(angle_y,-70,0,-255,0);
      Moteur2 = map(angle_x,-70,0,-255,0);
    }
    else {
      Moteur1 = map(angle_x,0,70,0,255);
      Moteur2 = map(angle_x,0,70,0,255);
    }
  }
  if ((angle_x<=20) && (angle_x>=-20)){
    if (angle_y >= 20) {
      Moteur1 = map(angle_y,0,70,0,255);
      Moteur2 = 0;
    }
    else if (angle_y>20) {
      Moteur1 = 0;
      Moteur2 = -map(angle_y,-70,0,-255,0);
      }
  }
  if (Moteur1>255){
    Moteur1 = 255;
  }
  if (Moteur2>255){
    Moteur2 = 255;
  }
  if (Moteur1<-255){
    Moteur1 = -255;
  }
  if (Moteur2<-255){
    Moteur2 = -255;
  }
  String info = String(Moteur1)+"/"+String(Moteur2);
  String info1 = String(angle_x)+"/"+String(angle_y);
  Serial.println(info);
  Serial.println(info1);
  BlueT.write(info.c_str(),info.length());
  delay(100);
}
```
Ce qui a changé par rapport à la version précédente est le fait que j'estime que l'utilisateur veut réellement tourner si l'angle de l'axe y (gauche/droite) est supérieur à 20 en valeur absolue (i.e >20 ou <-20). Sinon, ce sont juste des mouvement parasites puisqu'il est difficile de garder sa main parfaitement droite et donc difficile de garder une trajectoire en ligne droite.

# II. Construction :

L’interrupteur n’était pas fixe proprement nous avons donc fait les trous et les soudures nécessaires (pour rallonger les fils) afin de fixer l’interrupteur sur le dessus de la voiture sans que les fils ne soient visibles.

Pour que l’accéléromètre puisse être cousu au gant, j’ai dû changer les pins de branchement qui était orienté vers le bas et m’orienter vers une connexion vers le haut en « L ».

# III. Extra-séance vendredi

Nous avons finalement reçu le gant, nous avons donc décidé de finir son montage et d'y fixer tous les composants dessus.

Nous avons fait principalement deux choses :

## 1) Fixer les composants 
      
  C'est Robin qui s'est chargé de coudre tous les éléments aux gants pour pouvoir les fixer convenablement.

## 2) Raccourcir les fils et miniaturiser le tout

Surement la partie la plus longue, afin de raccourcir les fils, nous avons coupé et ressouder pratiquement tous les fils.
Ensuite, puisque la barrette de deux lignes (une pour le + et une pour le -) prenait trop de place sur le gant nous avons décidé de coudre deux écrous sur le gant et d'y souder tous les fils qui auraient du être relié aux 5 V. Idem pour la masse.

## 3) Régler les problèmes

He oui, ce changement a entraîné un certain nombre de problèmes. Il faut encore faire des tests pour vérifier, mais parfois, l'accéléromètre cesse de
fonctionner puis renvoie NaN ( Not a number), cela est surement du au fil femelle de l'alimentation que peut se détacher quand on agite le gant. Le problème vient peut-être aussi de la soudure entre les différents fils relié aux 5 V ou de la soudure des fils relié à la masse.
Enfin, parfois, le programme se fige, c'est-à-dire que l'angle change, mais la valeur envoyée au moteur reste inchangé. Je n'ai toujours pas identifié la cause de ce problème.



