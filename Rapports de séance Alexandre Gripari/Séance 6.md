# I. Code / échange d'information

Pendant le début de la séance nous nous somme concentré sur l'échange d'information entre l'accéléromètre et les moteurs.
Au final le plus pratique est d'envoyer l'information sous la forme d'un couple séparé d'un slash qui contient comme information quelle puissance envoyer au moteur.
Pour la marche arrière nous avons décidé de mettre un moins devant.

Le code de mon coté résultant de ces différents essais, est le suivant :

'''
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

'''
