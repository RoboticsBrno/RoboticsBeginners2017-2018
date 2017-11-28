#include <Arduino.h>
#include "LearningKit.h"

// proměnné
int pocitadlo = 0; // int = cele cislo (+- 4 miliardy)
float floatCislo = 123456.12345678; // desetinné číslo s přesností na 7 desetinných míst
float floatVelkeCislo = 987654321.12345678; // desetinné číslo s přesností na 7 desetinných míst
double doubleVelkeCislo = 987654321.12345678; // desetinné číslo s přesností na 15 desetinných míst

char znak = 'z'; // znak musí být v apostrofech ''
char poleZnaku[] = "z"; // pole znaků - používají se uvozovky
char text[] = "ahoj";

bool pravdanepravda = true; // dva stavy - pravda/nepravda => true/false => HIGH/LOW

void setup() {
    int promenaSetup = 1; // k dispozici jen v setupu
    Serial.begin(9600); // otevře seriový port, komunikační linku mezi Arduinem a PC, komunikační rychlost 9600 bps (bity za sekundu -> běžně přednastavená rychlost u Seriového monitoru v Arduino prostředích)
    Serial.println("Ahoj pocitaci"); // odešle text "Ahoj pocitaci" do PC a odsadi na novy radek
    Serial.println(floatCislo);
    Serial.println(floatVelkeCislo);
    Serial.println(doubleVelkeCislo);
    Serial.println(text);

    // text[X] - měním jednotlivé znaky na pozici X
    text[0] = 'z';
    Serial.println(text);
    text[1] = 'd';
    Serial.println(text);
    text[2] = 'a';
    Serial.println(text);
    text[3] = 'r';
    Serial.println(text);
    //text = "nazdar"; // nelze
}

void loop() {
    // // ++promenaSetup; // již zde neni dostupna - existuje jen v setupu
    // Serial.println(promenaSetup);
}