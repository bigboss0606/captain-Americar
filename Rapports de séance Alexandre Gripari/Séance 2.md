# I. Bluetooth

Tentative de relier la carte qui contrôle les moteurs et la carte qui s'occupe de récupérer les informations données par l'accéléromètre et le gyroscope.

On a récupéré deux modules (1 maître, 1 esclave) qui sont déjà couplés ensemble.Après avoir effectué les branchements, nous constatons que les modules sont bien appareillés (La LED du module esclave reste allumé et celle du module maître clignote environ toutes les 2 secondes.

En revanche, nous n'arrivons ni à envoyer des messages, ni à en recevoir sur les modules.

La première erreur était que la communication entre 2 modules Bluetooth doit être en 38 400 bits. Mais même après ce changement, on ne pouvait toujours pas envoyer ni recevoir de message.


Ne comprenant pas la source de l'erreur (après plusieurs vérifications des branchements des deux modules, du code, etc.), j'ai décidé d'aider Robin dans la construction de la maquette temporaire (ou pas) de la voiture. Puis j'ai commencé à faire le code se chargeant de l'envoi des données.
Mais cela est assez problématique puisque pour pouvoir construire le gant et commencer les premiers tests sur la sensibilité de l'accéléromètre, il faut que la partie accéléromètre + Bluetooth soit opérationnel.

# III. Traitement des donnés

Pour l'instant, le capteur renvoie des "états" : (avant, arrière, avant/gauche...). Pour faire simple au début, nous enverrons l'information sous forme de mot ex : Avant/Droit, et dans le programme de la carte de la voiture, il y aura un "if" pour chaque direction possible et on fera tourner un moteur plus ou moins vite selon le message reçu.

Il serait en revanche meilleur d'envoyer directement sous forme de chiffre l'inclinaison de la main selon les différents axes, pour pouvoir ainsi contrôler la vitesse de la voiture en fonction de l'inclinaison de la main.

 # III. Code

En théorie, les deux modules n'ont pas besoin de pouvoir lire et envoyer des messages (celui sur le gant ne fera qu'en envoyer quant à celui sur la voiture ne fera que recevoir). Mais pour simplifier les tests, les deux modules ont le même code.


Voici le code pour les 2 modules :
```
#include<SoftwareSerial.h>
#define RX 10
#define TX 11
SoftwareSerial BlueT(RX,TX);
 
void setup(){
  Serial.begin(9600);
  delay(500);
  Serial.println("Bonjour -Pret pour les commandes AT");
  BlueT.begin(38400);
  delay(500);
}
 
void loop(){
  while (BlueT.available()) {
    Serial.print(char(BlueT.read())); 
  }
  while (Serial.available()) {
    BlueT.write(char(Serial.read())); 
  }
}
```
