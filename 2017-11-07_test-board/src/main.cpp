#include <Arduino.h>
#include "LearningKit.h"

// za lomeno si pisi komentare - jednoradkovy

/*
toto je viceradkovy komentar
*/

void setup() {
    // setup() - probehne jednou vzdy na pocatku programu - slouzi k nastaveni/inicializaci zarizeni
    
    //pinMode(L_R, OUTPUT); // nastavim nazicku na vystupni
    pinMode(32, INPUT); // testovani POT1 jako digitalniho vstupu
    
    // nastavuji vsechny piny do potrebne pocatecni konfigurace (vstupni/vystupni, pull-up/pull-down)
    setupLeds(); 
    setupRgbLed();
    setupButtons();
}

void loop() {
    // loop() - po provedeni setup() se zacne provadet loop() - porad se bude opakovat (nikdy nezkonci)
    
    // 1. cast - blikani s LED
    // digitalWrite(L_R, HIGH); // nastavuje na pinu L_R vystupni uroven HIGH (== true == 1 => 3,3 V)
    // delay(500); // ceka 500 ms = 0,5 s
    // digitalWrite(L_R, LOW); // nastavuje na pinu L_R vystupni uroven LOW (== false == 0 => 0 V)
    // delay(500);

    digitalRead(SW1); // cteni stavu na pinech - tlacitku SW1: LOW -> stisknuto, HIGH -> nestisknuto (=> kvuli zapojeni na desce ALKS - bezne se tak pouziva) 
    digitalWrite(L_R, !digitalRead(SW1)); // vycteme hodnotu na tlacitku a hned ji nastavime na LEDku
    digitalWrite(L_B, !digitalRead(SW2)); // ! = negace -> invertujeme chovani -> LED nesviti kdyz nestisknuty; sviti kdyz stisknuty
    digitalWrite(L_G, !digitalRead(SW3));
    digitalWrite(L_Y, !digitalRead(POT1)); // zkousime pouzit potenciometr POT1, jako tlacitko -> FUNGUJE

    // podmimka: pokud plati neco => delej tohle
    if (digitalRead(SW1)) {
        digitalWrite(L_RGB_R, HIGH);
    } else {
        digitalWrite(L_RGB_R, LOW);
    }
}
