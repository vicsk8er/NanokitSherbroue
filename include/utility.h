// #ifndef UTILITY_H
// #define UTILITY_H

// bool timerFunctionThermo(unsigned long interval);
// bool timerFunction(unsigned long Interval, unsigned long PreviousMillis);
// #endif
#ifndef UTILITY_H
#define UTILITY_H

class Timer {
public:
    Timer(unsigned long interval);//constructeur
    bool check();// methode de la classe Timer

private:
    unsigned long previousMillis;//variable qu'on passe en privée
    unsigned long interval;// car elle n'ont pas besoin d'être en publique pour que le code fonctionne (on fournie en publique la méthode et le constructeur)
};

#endif
