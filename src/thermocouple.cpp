#include <Arduino.h>
#include <max6675.h>
#include "utility.h"
#include "thermocouple.h"
Timer TimerThermo(10);
//variable globale utiliser pour récupérer les températures
//cela va changer au fur et a mesure que le projet va changer, car c'est pas le best d'avoir bcp de variable globale
//niveau sécurité, on veut le moins possible de globales c'est une bonne habitude a prendre mais pour l'instant c'est ok
double echantillons[nombreEchantillons];
double temperatureMoyenne = 0;
double rawtemp=0;
double tunnedTemp=0;
uint16_t rawValue;

// Créer un objet MAX6675
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

double thermoRead() 
{
  
  rawValue = thermocouple.readRawValue();
  rawtemp = thermocouple.readCelsius();
  tunnedTemp=(1.0491*(thermocouple.readCelsius()))+1.0744;
  //la tunnedTemp a été créer a partir d'un fichier excel que je vais t'envoyer
  //j'ai pris le graphique qui s'appel Réelle en fonction de exp
  // c'est basé sur un autre thermocouple (de la marque big Green eggs)
  Serial.print("Raw Value: ");
  Serial.println(rawValue);
  Serial.print("Raw Temperature: ");
  Serial.println(rawtemp);

  //je met à jour le tableau d'échantillons
  for (int i = nombreEchantillons-1; i > 0; i--) 
  {
    //il fait 4 fois la boucle for
    //Serial.print("FOR");
    echantillons[i]= echantillons[i-1];
   
  }
  echantillons[0] = rawtemp;
  
  // if(TimerThermo.check())
  // {
  //   //rawValue
  //   rawValue = thermocouple.readRawValue();
  //   //rawtemp
  //   rawtemp=thermocouple.readCelsius();
    
  // }
  /*
  ATTENTION: la moyenne est présentement calculer avec la Rawtemp, pas la tunned
  donc ce n'est pas la moyenne que nous allons utiliser pour la suite du projet
  */
  double moyenneLocal=0;
  //calcul de la moyenne local (qui sera ensuite assigné a temperatureMoyenne)
  for (int i = 0; i < nombreEchantillons; i++) 
  {
    moyenneLocal += echantillons[i];
  }
  moyenneLocal /= nombreEchantillons;
  temperatureMoyenne=moyenneLocal;
  Serial.print("Average Temperature: ");
  Serial.println(temperatureMoyenne);

  return temperatureMoyenne;
}
