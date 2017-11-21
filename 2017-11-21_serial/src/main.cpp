#include <Arduino.h>
#include "LearningKit.h"

// proměnná pocitadlo 
int pocitadlo = 0; // int = cele cislo (+- 4 miliardy)

void setup() {
    Serial.begin(9600); // otevře seriový port, komunikační linku mezi Arduinem a PC, komunikační rychlost 9600 bps (bity za sekundu -> běžně přednastavená rychlost u Seriového monitoru v Arduino prostředích)
    Serial.println("Ahoj pocitaci"); // odešle text "Ahoj pocitaci" do PC a odsadi na novy radek
}

void loop() {
    //Serial.print("Ahoj svete, jak se mas"); // vypíše text, ale neodsadí na další řádek: print() vs println()
    
    pocitadlo++; // pocitadlo += 1; (stejný význam/efekt)
    Serial.print(pocitadlo); // vypíše hodnotu proměnné pocitadlo
    
    Serial.print(": tlacitko - "); 
    Serial.print(digitalRead(SW1)); // vypise '0' nebo '1' podle stavu tlacitka
    Serial.print("  potenciometr - ");
    Serial.println(analogRead(POT1)); // vypíše aktuální hodnotu napětí na potenciometru (0 - 4095)
    delay(500); // počká 500 milisekund - většinou je potřeba mít ve smyčce s odesíláním dat nějaký delay(), jinak dojde k zahlcení seriové linky a nečitelnému výstupu pro uživatele
}