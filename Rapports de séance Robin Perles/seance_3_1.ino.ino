#include<SoftwareSerial.h>

//-- MOTEUR A --
int ENA=9; //Connecté à Arduino pin 9(sortie PWM)
int IN1=4; //Connecté à Arduino pin 4
int IN2=5; //Connecté à Arduino pin 5

//-- MOTEUR B --
int ENB=10; //Connecté à Arduino pin 10(Sortie PWM)
int IN3=6; //Connecté à Arduino pin 6
int IN4=7; //Connecté à Arduino pin 7

//-- Bluetooth --
int RX = 12;
int TX = 13;
SoftwareSerial BlueT(RX,TX);
 

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
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  // Direction du Moteur B
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);

  Serial.begin(9600);
  delay(500);
  Serial.println("Bonjour -Pret pour les commandes AT");
  BlueT.begin(38400);
  delay(500);
}


void loop() {
  // Moteur A - Plein régime
  // Moteur B - Mi-régime

  String reponse = "";
  while (BlueT.available()) {
        reponse += char(BlueT.read()); 


  }
  Serial.println(reponse);

  
  if(reponse == "Z")
  {
      Serial.println("1");
      analogWrite(ENA,255);
      analogWrite(ENB,255);
  }
  else if(reponse == "ZQ")
  {
      analogWrite(ENA,255);
      analogWrite(ENB,170);
  }
  else if(reponse == "ZD")
  {
      analogWrite(ENA,170);
      analogWrite(ENB,255);
  }
  else if(reponse == "D")
  {
      analogWrite(ENA,0);
      analogWrite(ENB,255);
  }
  
  else if(reponse == "Q")
  {
      analogWrite(ENA,255);
      analogWrite(ENB,0);
  }

  /*while (Serial.available()) {
    BlueT.write(char(Serial.read())); 
  }*/
  delay(100);
} 
