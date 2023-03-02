// ESP32 Guide: https://RandomNerdTutorials.com/esp32-mpu-6050-accelerometer-gyroscope-arduino/
// ESP8266 Guide: https://RandomNerdTutorials.com/esp8266-nodemcu-mpu-6050-accelerometer-gyroscope-arduino/
// Arduino Guide: https://RandomNerdTutorials.com/arduino-mpu-6050-accelerometer-gyroscope/

// On importe toutes les bibliothèques nécessaires.
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include<SoftwareSerial.h>

#define RX 11
#define TX 10
SoftwareSerial BlueT(RX,TX);
Adafruit_MPU6050 mpu;

int Moteur1 = 0;
int Moteur2 = 0;

void setup(void) {
  Serial.begin(9600);
  BlueT.begin(38400); //communication entre 2 modules Bluetooth en 38400
  while (!Serial)
    delay(10); // will pause until serial console opens

  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip"); // permet de savoir si l'accéléromètre est mal branché.
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");
  
  //Permet de changer différente caratérisque de l'accéléromètre, tout en ayant un print à chaque démarage quels sont les options choisies.
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
    Serial.println("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.println("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.println("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.println("+- 2000 deg/s");
    break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
  case MPU6050_BAND_260_HZ:
    Serial.println("260 Hz");
    break;
  case MPU6050_BAND_184_HZ:
    Serial.println("184 Hz");
    break;
  case MPU6050_BAND_94_HZ:
    Serial.println("94 Hz");
    break;
  case MPU6050_BAND_44_HZ:
    Serial.println("44 Hz");
    break;
  case MPU6050_BAND_21_HZ:
    Serial.println("21 Hz");
    break;
  case MPU6050_BAND_10_HZ:
    Serial.println("10 Hz");
    break;
  case MPU6050_BAND_5_HZ:
    Serial.println("5 Hz");
    break;
  }

  Serial.println("");
  delay(100);
}

void loop() {
  /* On récupère l'accélération, le gyroscope et la température */ 
  
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  /* calcul des angles d'inclinaisons grace à l'accélération
   * remarque: il y a un signe moins avant le calcul de l'angle x puisque je veux que quand on penche l'accéléromètre vers l'avant l'angle soit positif
   */
  
  float angle_x = -(atan((a.acceleration.x) / sqrt(pow((a.acceleration.y),2) + pow((a.acceleration.z),2))) * 180/3.14);
  float angle_y = (atan((a.acceleration.y) / sqrt(pow((a.acceleration.x),2) + pow((a.acceleration.z),2))) * 180/3.14);
  
  /* On teste tous les cas possibles, cela est du au faite que l'on réalise pas la même action pour tourner quand la voiture avance vers l'avant
   * que quand elle ou recule ou est immobile, il faut donc distinguer ces 3 cas 
   * Rq : on définit que la voiture est stationnaire pour un angle_x (devant/derrière) compris entre -10 et 10 et un angle en y (gauche/droite)
   *  compris entre -20 et 20,
   * pour éviter les légers mouvements parasites (il est difficile de rester parfaitement droit).
   * De plus la vitesse maximale est atteinte pour un angle de 70 degrés et pas 90 puisque n'est pas très pratique de faire un angle de 90 degrés avec sa maint
   */
  
  if (angle_x >=10){
    if (angle_y>=20) {
      Moteur1 = map(angle_x,10,70,128,255);
      Moteur2 = map(angle_x,10,70,128,255) - map(angle_y,20,70,0,127);
    }
    else if (angle_y<-20) {
      Moteur1 = map(angle_x,10,70,128,255) + map(angle_y,-70,-20,-127,0);
      Moteur2 = map(angle_x,10,70,128,255);
    }
    else {
      Moteur1 = map(angle_x,10,70,0,255);
      Moteur2 = map(angle_x,10,70,0,255);
    }
  }
  else if (angle_x<=-20){
    if (angle_y>=20) {
      Moteur1 = map(angle_x,-70,-20,-255,-128);
      Moteur2 = map(angle_x,-70,-20,-255,-128) + map(angle_y,20,70,0,255);
    }
    else if (angle_y<-20) {
      Moteur1 = map(angle_x,-70,-20,-255,-128) - map(angle_y,-70,-20,-255,0);
      Moteur2 = map(angle_x,-70,-20,-255,-128);
    }
    else {
      Moteur1 = map(angle_x,-70,-20,-128,0);
      Moteur2 = map(angle_x,-70,-20,-128,0);
    }
  }
  else if ((angle_x<=10) && (angle_x>=-20)){
    if (angle_y >= 20) {
      Moteur1 = map(angle_y,20,70,0,255);
      Moteur2 = 0;
    }
    else if (angle_y<-20) {
      Moteur1 = 0;
      Moteur2 = -map(angle_y,-70,-20,-255,0);
      }
    else {
      Moteur1 = 0;
      Moteur2 = 0;
    }
  }
  /*Il se peut que la valeur dépasse 255 ou -255 si la personne réalise un angle supérieur à 70 degrés*/
  if (Moteur1>255){
    Moteur1 = 255;
  }
  if (Moteur2>255){
    Moteur2 = 255;
  }
  if (Moteur1<-128){
    Moteur1 = -128;
  }
  if (Moteur2<-128){
    Moteur2 = -128;
  }
  String info = "D" + String(Moteur1)+"/"+String(Moteur2) + "F"; //On stock l'information sous la forme d'un couple compris entre 2 lettres indiquant le début et la fin de l'information
  String c_angles = String(angle_x)+"/"+String(angle_y); 
  Serial.println("angles : "+c_angles);
  Serial.println("message envoye : "+ info);
  BlueT.write(info.c_str(),info.length()); // On envoie l'information grace au module Bluetooth
  delay(100);
}
