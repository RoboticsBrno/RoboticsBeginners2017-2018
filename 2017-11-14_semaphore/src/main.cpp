#include <Arduino.h>
#include "LearningKit.h"

void setup() {
    // funkce níže nastavují všechny piny do potřebné počáteční konfigurace (vstupní/výstupní, pull-up/pull-down)
    setupLeds(); 
    setupRgbLed();
    setupButtons();
}

void loop() {
    //// 1. část - blikání s LED
    // digitalWrite(L_R, HIGH); // nastavuje na pinu L_R výstupní uroveň HIGH (== true == 1 => 3,3 V) - LED svítí
    // delay(500); // ceka 500 ms = 0,5 s
    // digitalWrite(L_R, LOW); // nastavuje na pinu L_R výstupní uroveň LOW (== false == 0 => 0 V) - LED nesvíví
    // delay(500);

    // // 2. část - jednoduchý semafor
    // digitalWrite(L_R, HIGH);
    // delay(500);
    // digitalWrite(L_Y, HIGH);
    // delay(500);
    // digitalWrite(L_R, LOW);
    // digitalWrite(L_Y, LOW);
    // digitalWrite(L_G, HIGH);
    // delay(1000);
    // digitalWrite(L_G, LOW);
    // digitalWrite(L_Y, HIGH);
    // delay(500);
    // digitalWrite(L_Y, LOW);

    // 3. část - semafor spouštěný tlačítkem
    digitalWrite(L_R, HIGH);
    if(!digitalRead(SW1)) { // pokud je tlačítko zmáčknuté, spustí se semafor (digitalRead(SW1) - vrací 1, když není tlačítko zmáčknuté => způsobeno interním pull-upem - viz setupButtons())
        delay(500);
        digitalWrite(L_Y, HIGH);
        delay(500);
        digitalWrite(L_R, LOW);
        digitalWrite(L_Y, LOW);
        digitalWrite(L_G, HIGH);
        delay(1000);
        digitalWrite(L_G, LOW);
        digitalWrite(L_Y, HIGH);
        delay(500);
        digitalWrite(L_Y, LOW);
        digitalWrite(L_R, HIGH);
    }
}
