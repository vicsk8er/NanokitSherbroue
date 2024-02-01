
#include "utility.h"
#include <Arduino.h>
// constructeur de la classe Timer qui est dans le utility.h (il faut que le constructeur est le même nom que la classe)
Timer::Timer(unsigned long interval) 
{
    this->interval = interval;
    this->previousMillis = 0;
}
//méthode (fonction de Timer) qui vérifie si le timer est écoulé
bool Timer::check() 
{
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        return true;
    }

    return false;
}

