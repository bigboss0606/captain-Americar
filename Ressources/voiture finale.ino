#include<SoftwareSerial.h>

//-- On définit les ports du MOTEUR A --
int ENA=10; //Connecté à Arduino pin 9(sortie PWM)
int IN1=6; //Connecté à Arduino pin 4
int IN2=7; //Connecté à Arduino pin 5

//-- On définit les ports du MOTEUR B --
int ENB=9; //Connecté à Arduino pin 10(Sortie PWM)
int IN3=4; //Connecté à Arduino pin 6
int IN4=5; //Connecté à Arduino pin 7

//-- On définit les ports du Bluetooth --
int RX = 12;
int TX = 13;
SoftwareSerial BlueT(RX,TX);
 
bool sensA = true;
bool sensB = true;
int puissanceA = 0;
int puissanceB = 0;


void setup() {
  //On met en place les moteurs
  pinMode(ENA,OUTPUT); // Configurer
  pinMode(ENB,OUTPUT); // les broches
  pinMode(IN1,OUTPUT); // comme sortie
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  digitalWrite(ENA,LOW);// Moteur A - Ne pas tourner
  digitalWrite(ENB,LOW);// Moteur B - Ne pas tourner
  // Direction du Moteur A
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  // Direction du Moteur B
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);

  //On démarre la connexion série etle module Bluetooth
  Serial.begin(9600);
  delay(500);
  BlueT.begin(38400);
  delay(500);
  Serial.println("La voiture est prete");
}


void loop() {
  //On recupere le message du module Bluetooth
  String reponse = "";
  while (BlueT.available()) {
        reponse += char(BlueT.read()); 
  }
  Serial.println(reponse);


  //On verifie que reponse est du type "Dx/yF" avec x et y des entiers
  //Si reponse est du bon type, on met puissaneA à x et puissanceB à y 
  //Sinon on ne change pas puissanceA ni puissanceB
  int debut = reponse.indexOf("D");
  int fin = reponse.indexOf("F");
  if(debut != -1 && fin != -1 && debut < fin)
  {
    String couple = reponse.substring(debut + 1, fin);
    Serial.println(couple);
    int slash = couple.indexOf("/");
    puissanceB = couple.substring(0, slash).toInt();
    puissanceA = couple.substring(slash+1, reponse.length()).toInt();
  }

  Serial.println(puissanceA);
  Serial.println(puissanceB);


  //Si le moteurA a changé de sens, on inverse IN1 et IN2
  if(puissanceA < 0 && sensA)
  {
    sensA = false;
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
  }
  else if(puissanceA > 0 && !sensA)
  {
    sensA = true;
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
  }

  if(puissanceB < 0 && sensB)
  {
    sensB = false;
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
  }
  else if(puissanceB > 0 && !sensB)
  {
    sensB = true;
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
  }


  //On applique puissanceA au moteurA et puissanceB au moteurB
  analogWrite(ENA, puissanceA);
  analogWrite(ENB, puissanceB);
  
  delay(100);
} 
