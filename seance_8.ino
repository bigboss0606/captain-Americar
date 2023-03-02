#include<SoftwareSerial.h>

//-- MOTEUR A --
int ENA=10; //Connecté à Arduino pin 9(sortie PWM)
int IN1=6; //Connecté à Arduino pin 4
int IN2=7; //Connecté à Arduino pin 5

//-- MOTEUR B --
int ENB=9; //Connecté à Arduino pin 10(Sortie PWM)
int IN3=4; //Connecté à Arduino pin 6
int IN4=5; //Connecté à Arduino pin 7

//-- Bluetooth --
int RX = 12;
int TX = 13;
SoftwareSerial BlueT(RX,TX);
 
bool sensA = true;
bool sensB = true;
int puissanceA = 0;
int puissanceB = 0;


void setup() {
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

  Serial.begin(9600);
  delay(500);
  Serial.println("Bonjour -Pret pour les commandes AT");
  BlueT.begin(38400);
  delay(500);
}


void loop() {
  String reponse = "";
  while (BlueT.available()) {
        reponse += char(BlueT.read()); 
  }
  Serial.println(reponse);

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
  
  analogWrite(ENA, puissanceA);
  analogWrite(ENB, puissanceB);
  
  delay(100);
} 
