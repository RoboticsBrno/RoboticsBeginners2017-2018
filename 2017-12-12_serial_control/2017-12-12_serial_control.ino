#include <LearningKit.h> // naše knihovna pro vývojový kit ALKS - verze pro ESP32: http://platformio.org/lib/show/1745/ArduinoLearkingKitStarter
// návod na instalace do Arduino IDE: https://github.com/RoboticsBrno/RoboticsBeginners2017-2018/

// když chci pracovat s piny na Arduinu, je lepší si definovat proměnnou s označující daný pin a přiřadit do ní číslo pinu
int pin = L_R; // jednoduchá, ale schůdná varianta
//static const int pin = L_R; // lepší forma definice proměnné pro pin -> "rychlejší" vykonávání programu

void setup() {
  // v setup() je potřeba inicializovat všechny piny Arduina, s kterými budeme pracovat
  //pinMode(pin, OUTPUT); // lze je nastavit po jednotlivých pinech pomocí funkce pinMode(cislo_pinu, OUTPUT/INPUT/INPUT_PULLUP);
  setupLeds();            // nebo lze využít funkce v knihovně pro náš vývojový kit ALKS (setupLeds(), setupRgbLed(), setupButtons())

  // Seril.begin() -> musí být vždy v setup() pokud chceme používat Serial Monitor (komunikace mezi PC a Arduinem)
  Serial.begin(9600); // otevře sériový port, komunikační linku mezi Arduinem a PC, komunikační rychlost 9600 bps (bity za sekundu 
                      // -> běžně přednastavená rychlost u sériového monitoru v Arduino prostředích: Tools -> Serial Monitor)
  Serial.println(" Ahoj lidi"); // odešle z Arduina textový řetězec " Ahoj lidi"
}

int znak; // proměnná do které se ukládají příchozí znaky
bool ledStav = false; // proměnná pro ukládání stavu LED -> využíváme k zapínání a vypínání LED jedním znakem (rozdíl oproti předchozí lekci 2017-12-05)
void loop() {
  if(Serial.available()) {            // pokud přišla nějaká data na sériovou linku je podmínka splněna (vrátí TRUE)
    znak = Serial.read();               // přečte jeden znak ze sériové linky a uloží jej do proměnné znak
    if(znak == 'c') {                   // pokud přijde znak 'c'
      if(ledStav == false) {              // a ledStav je roven FALSE
        ledStav = true;                     // ledStav se nastaví na TRUE -> digitalWrite() na konci programu zapne LED
        Serial.println("LED zapnuta");      // a na sériové lince se vypíše text "LED zapnuta"    
      } else {                            // když se ledStav nerovná FALSE
        ledStav = false;                    // ledStav se nastaví na FALSE -> digitalWrite() na konci programu vypne LED
        Serial.println("LED vypnuta");      // a na sériové lince se vypíše text "LED zapnuta"
      }
    } else {                            // pokud nepřijde znak 'c' -> vypíše se info na sériovou linku
      Serial.print("Poslal jste spatny znak: ");
      Serial.write(znak);
      Serial.print("\nPro ovladani LED poslete 'c'\n");  
    }
  }
  // při každém průchodu smyčkou se nastaví pin L_G
  digitalWrite(L_G, ledStav); // nastaví (zapne/vypne) LED podle proměnné ledStav

//  // ukázka jednoduchého zapínání a vypínání LED pomocí tlačítka -> pro připomenutí a porovnání s řešením výše
//  if(digitalRead(SW1) == LOW) {
//    digitalWrite(L_G, HIGH);
//    Serial.println("LED zapnuta");    
//  } else {
//    digitalWrite(L_G, LOW);
//    Serial.println("LED vypnuta");
//  }
//  delay(200);
}
