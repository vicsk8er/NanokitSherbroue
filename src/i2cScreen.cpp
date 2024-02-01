
// aide mémoire si nécessaire: make custom characters (2 exemples)

// byte dotOff[] = { 0b00000, 0b01110, 0b10001, 0b10001,
//                   0b10001, 0b01110, 0b00000, 0b00000 };
// byte dotOn[] = { 0b00000, 0b01110, 0b11111, 0b11111,
//                  0b11111, 0b01110, 0b00000, 0b00000 };

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
#include "utility.h"
Timer screenInitTimer(2000);
// Adresse I2C de l'écran (peut varier selon votre écran)
#define I2C_ADDRESS 0x27

// Créer une instance de la classe LiquidCrystal_PCF8574
LiquidCrystal_PCF8574 lcd(I2C_ADDRESS);

void i2cScreenInit() {
  // Initialiser l'écran avec le nombre de colonnes et de lignes
  Wire.begin();
  Wire.beginTransmission(I2C_ADDRESS);
  lcd.begin(20, 4); //on spécifie le nb de colonnes et de lignes de l'écran
  lcd.setBacklight(255);
  lcd.home();
    
  // Effacer l'écran
  lcd.clear();

  // Déplacer le curseur à la position (0, 0)
  lcd.setCursor(0, 0);

  // Afficher un message de bienvenue
  lcd.print("Hello, Arduino!!!");

  // Attendre quelques secondes (2s)
   //delay(1500);
  while(!(screenInitTimer.check()))
  {
    Serial.println("bloquer");
   
  }
// Effacer l'écran
  lcd.clear();
  Serial.println("Écran clear");
  
  
}

void i2cScreenPrint(const char* message, int row, int col) {
  // Déplacer le curseur à la position spécifiée
  lcd.setCursor(col, row);

  // Afficher le message
  lcd.print(message);
}
void i2cScreenPrintTemp(double temp, int ROW, int COL) {
  // Déplacer le curseur à la position spécifiée
  lcd.setCursor(COL, ROW);

  // Afficher le message
  lcd.print(temp);
}