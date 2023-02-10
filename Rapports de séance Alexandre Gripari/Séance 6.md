# I. Code / échange d'information

Pendant le début de la séance, nous nous sommes concentrés sur l'échange d'informations entre l'accéléromètre et les moteurs.
Au final, le plus pratique est d'envoyer l'information sous la forme d'un couple séparé d'un slash qui contient comme information quelle puissance envoyer au moteur.
Pour la marche arrière, nous avons décidé de mettre un moins devant.

Exemple : MoteurA/MoteurB

Le code, de mon coté résultant de ces différents essais, est le suivant :

```
  float angle_x = -(atan((a.acceleration.x) / sqrt(pow((a.acceleration.y),2) + pow((a.acceleration.z),2))) * 180/3.14);
  float angle_y = (atan((a.acceleration.y) / sqrt(pow((a.acceleration.x),2) + pow((a.acceleration.z),2))) * 180/3.14);
  if (angle_x >=20){
    if (angle_y>=0) {
      Moteur1 = map(angle_x,0,70,0,255);
      Moteur2 = map(angle_x,0,70,0,255) - map(angle_y,0,70,0,127);
    }
    else {
      Moteur1 = map(angle_x,0,70,0,255) + map(angle_y,-70,0,-127,0);
      Moteur2 = map(angle_x,0,70,0,255);
    }
  }
  if (angle_x<=-20){
    if (angle_y>=0) {
      Moteur1 = map(angle_x,-70,0,-255,0);
      Moteur2 = map(angle_x,-70,0,-127,0) + map(angle_y,0,70,0,255);
    }
    else {
      Moteur1 = map(angle_x,-70,0,-127,0) - map(angle_y,-70,0,-255,0);
      Moteur2 = map(angle_x,-70,0,-255,0);
    }
  }
  if ((angle_x<=20) && (angle_x>=-20)){
    if (angle_y >= 0) {
      Moteur1 = map(angle_y,0,70,0,255);
      Moteur2 = 0;
    }
    else {
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
  String info = String(Moteur1)+"/"+String(Moteur2);
  String info1 = String(angle_x)+"/"+String(angle_y);
  Serial.println(info);
  Serial.println(info1);
  BlueT.write(info.c_str(),info.length());
  delay(100);
}
```
A noter qu'on uilise : BlueT.write(info.c_str(),info.length()), puisqu'on ne peut pas envoyer d'objet de type String avec BlueT.write.

Il nous reste encore à faire des tests pour que le contrôle soit facile. Pour l'instant, la voiture est considérée comme "en train d'avancer" si l'angle en x est supérieur à 20 en valeur absolue.

De plus, on remarquera que la puissance maximale du moteur est atteinte pour un angle de 70 degrés et non pas 90. Après plusieurs tests, nous avons remarqué qu'il n'est surement pas très pratique de pencher sa main à 90 degrés. Nous avons donc fixé comme valeur arbitraire 70 degré.

Toutes ces valeurs sont sujets à changement puisqu'il est difficile de juger la maniabilité de la voiture en n'utilisant que l'accéléromètre.
Nous ferons des changements la séance prochaine une fois le gant opérationnel.

# II. Le gant

Le gant est bientôt fini (même si on n'a toujours pas le gant, tous les composants à attacher sont prêts.), j'ai décidé d'alimenter la carte directement avec une pile de 9V, ce qui permet d'avoir un système embarqué totalement indépendant (plus besoin de l'ordinateur pour alimenter les composants et la carte).

# III. Extra

Nous avons enfin relié le système de la voiture à un interrupteur pour éviter le faite de systématiquement enlever une pile pour éteindre le système.
Nous avons aussi pensé à d'éventuelles fonctionnalités à rajouter si nous finissons le projet en avance. (des phares et/ou un klaxon qui pouront éventuellement être contrôle par un capteur de flexion).
