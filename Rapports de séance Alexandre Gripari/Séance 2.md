# I. Principe bluetooth

Tentative de relier la carte qui controle les moteurs et la carte qui s'occupe de récupérer les informations données par l'accéléromètre et le gyroscope.
On a récupérer deux module (1 maitre, 1 esclave) qui sont déjà couplés ensemble.

Après avoir effectuer les branchements, nous constatons que les modules sont bien appareillés (la LED du module esclave reste allumé et celle du module maître,
clignote environ toutes les 2 secondes.

On revanche nous n'arrivons ni à envoyer des messages, ni à en recevoir sur les modules.

 # II. Code

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
