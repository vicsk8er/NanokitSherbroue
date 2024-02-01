#include <Arduino.h>
#include <Servo.h>
#include "servomoteur.h"


//pour l'instant il n'y a rien ici, car j'ai fait les test dans le main directment
/*
Cependant, voici l'idée générale:
1.  Quand l'utilisateur le souhaite, il va sélectionner une température a atteindre et le temps de cuisson souhaiter
   (exemple je veut 70* pendant 1h). le servo ce met a HI a l'aide d'une fonction que nous allons faire (servoStart())
   et le servo va aller a sa position maximale. Dès qu'il va atteindre 70*, on va faire un PID,
   mais au lieu de le faire avec le servomoteur et d'avoir des grosse valeur de PID pour corriger l'erreur (sa serait vrm trop imprécis)
   on va faire le PID en fonction d'un MOSFET ou d'un relais.

2. la façon que ça marche un relai:
   si a ON (si il y a un certain courant qui le traverse), il laisse passer le courant AC du mur (120 V efficace qui sort des murs)
   si a off (le courant qui le travsere est NULL ou trop faible), il ne laisse pas passer le courant du mur.
   C'est comme si on débranchait le fil de la plaque quand il est a OFF et on le branche quand il est a ON.
   le fameux courant qui le traverse que je te parle a la ligne 15-16 c'est le 5V du arduino.

3. On va donc vérifier avec le thermocouple, si on est au dessus ou au dessous de la température souaitez.
   Si au dessus, il y a 0 courant qui travsere le relais et donc le circuit est ouvert (la plaque est "débranché") 
   Si en desous, il y a 5V qui traverse le relais et donc le relais laisse passer le courant du mur.
   Il va alterner jusqu'a atteindre la valeur juste et se stabiliser (ON/OFF) pour conserver la temp.
   
*/