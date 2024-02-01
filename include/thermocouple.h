#ifndef THERMOCOUPLE_H
#define THERMOCOUPLE_H
//déclaration de fonction qui sont partagé dans avec les autres fichiers
double thermoRead();
//uint16_t readRawValue();

//définition de constante
#define thermoDO 2
#define thermoCS 3
#define thermoCLK 4
#define nombreEchantillons 5

//variable globale accessible partout dans le code
extern double temperatureMoyenne;
extern double rawtemp;
extern uint16_t rawValue;
extern double tunnedTemp;

#endif