# I. Bluetooth / liaison des appareils

Nous avons finalement réussi à faire fonctionner le bluetooth pour mettre en liason l'accéléroscope et la voiture.

L'erreur était toute simple : en refaisant le circui j'ai branché le RX de la carte sur le RX du capteur bluetooth (de même avec le TX).  
Alors qu'il faut brancher le RX avec le TX... 
J'ai ensuite modifié le code sur l'accéléromètre pour envoyer des lettres (via bluetooth) indiquant la direction (ZQSD).

Voici le code: qui a été ajouter au code principale :

```
if ((a.acceleration.x) <= -2){
    Serial.println("Devant");
    BlueT.write("Z");
  }
  if ((a.acceleration.x) >= 2){
    Serial.println("Derrière");
    BlueT.write("S");
  }
  if ((a.acceleration.y) <= -2){
    Serial.println("Gauche");
    BlueT.write("Q");
  }
  if ((a.acceleration.y) >= 2){
    Serial.println("Droite");
    BlueT.write("D");
  }
  Serial.println("------------");
  delay(200);
 ```

# II. Correction de bug / amélioration à faire

On a réaliser plusieurs tests : la voiture peut avancer et tourner, même si la boite coquilette était trop fragile, ce qui avait pour conséquence de pencher les moteurs et les roues.

Pour la prochaine séance nous aurons surement une planche en bois.
Parfois l'accéléromètre cèsse de fonctionner et n'envoie plus de données. Après quelques tests j'ai découvert que cela était surement du à un fil qui était mal fixé et qui pouvait, quand on faisait bouger le capteur se détacher. En effet si un des fils se déconnecte pendant l'utilisation, même s'il est rebranché après le capteur n'envoie plus de donnés.
J'ai donc remplacer ce fil et je n'ai pour l'instant plus eu ce problème.

Enfin puisque par bluetooth on ne peut envoyer qu'un message il serait plus interessant que selon l'inclinaison du capteur j'envoie un couple de nombre compris entre 0 et 255 ex : 120/255, donnant directement comme infomation qu'elle puissance attribué au moteur A et au Moteur B.
Cela permet à l'utilisateur de pouvoir controler la vitesse du véhicule en inclinant plus ou moins sa main.
