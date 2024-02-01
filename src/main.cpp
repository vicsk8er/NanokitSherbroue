
//include de librairie
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
#include <Servo.h>

//include de fichier
#include "main.h"
#include "i2cScreen.h"
#include "thermocouple.h"
#include "utility.h"
#include "servomoteur.h"

//class
LiquidCrystal_PCF8574 lcd1(0x27);

Timer servoTimer(1500);
Timer Timer1(1000);

Servo myServo;



void setup() 
{
  myServo.write(180);// définition de l'angle initiale
  myServo.attach(5);// initialisation de la broche PWM 5 (on connecte le servo a la 5)
  
  Serial.begin(9600);  // début de la connexion avec le serial port
                      //pourrait être enlevé mais important pour déboguer le code
 
  i2cScreenInit(); //initialisation de l'écran
}  


void loop() 
{
  
  //le code suivant permet de tester le servomoteur
  
  if (servoTimer.check()) {
    static bool toggle = false; // Alternance entre 90 et 0 degrés
    if (toggle) {
      Serial.println("Moving to 90 degrees");
      myServo.write(130);
    } else {
      Serial.println("Moving to 0 degrees");
      myServo.write(180);
    }
    toggle = !toggle;
  }

  
  
  //le code suivant permet d'avoir un visuelle différent au 1500ms sur l'écran
  if(Timer1.check())
  {
    thermoRead();//on lit le thermocouple

    //i2cScreenPrint: on affiche un message et on décide la colonne et la ligne
    //i2cScreenPrintTemp: on affiche la température (double) et on décide la colonne et la lignes sur l'écran

    i2cScreenPrint("rawValue: ",0,0);
    i2cScreenPrintTemp(rawValue,0,10);
    Serial.println(rawValue);// permet d'avoir un visuelle dans le serialPort aussi (on print la valeur dans la console SERIAL)
    i2cScreenPrint("rawTemp: ",1,0);
    i2cScreenPrintTemp(rawtemp,1,10);
    i2cScreenPrint("Moyenne: ",2,0);
    i2cScreenPrintTemp(temperatureMoyenne,2,10);
    i2cScreenPrint("Tunned: ",3,0);
    i2cScreenPrintTemp(tunnedTemp,3,10);
  }
}  
