#include "LearningKit.h"

// proměnné
int pocitadlo = 0; // int = celé číslo (+- 4 miliardy -> platí jen pro ESP32, na jiných čipech Arduino platformy se liší)
float floatCislo = 123456.12345678; // desetinné číslo s přesností na 7 desetinných míst
float floatVelkeCislo = 987654321.12345678; // desetinné číslo s přesností na 7 desetinných míst
double doubleVelkeCislo = 987654321.12345678; // desetinné číslo s přesností na 15 desetinných míst

char znak = 'z'; // znak musí být v apostrofech ''
char poleZnaku[] = "z"; // pole znaků - používají se uvozovky "" -> obsahuje znak 'z' a konec textového řetězce '\0' -> celkový počet znaků = 2
char text[] = "ahoj"; // textový řetězec "ahoj" obsahující 5 znaků: 'a' 'h' 'o' 'j' '\0'

bool pravdanepravda = true; // dva stavy -> pravda/nepravda -> true/false -> HIGH/LOW

void setup() {
    int promenaSetup = 1; // k dispozici jen v setup()
    Serial.begin(9600); // otevře sériový port, komunikační linku mezi Arduinem a PC, komunikační rychlost 9600 bps (bity za sekundu 
                        // -> běžně přednastavená rychlost u sériového monitoru v Arduino prostředích: Tools -> Serial Monitor)
    Serial.println("Ahoj pocitaci"); // odešle text "Ahoj pocitaci" do PC a odsadí na nový řádek
    Serial.println(floatCislo);
    Serial.println(floatVelkeCislo);
    Serial.println(doubleVelkeCislo);
    Serial.println(text);

    // text[X] - měním jednotlivé znaky na pozici X
    text[0] = 'c';
    Serial.println(text);
    text[1] = 'a';
    Serial.println(text);
    text[2] = 'u';
    Serial.println(text);
    text[3] = '\0';
    Serial.println(text);
    //text = "zdar"; // nelze přiřazovat již do existujícího pole
}

void loop() {
    // // ++promenaSetup; // již zde není dostupná -> existuje jen v setup()
    // Serial.println(promenaSetup);
}
