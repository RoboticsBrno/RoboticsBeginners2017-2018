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
  Serial.print(65);   // odešle dané číslo do PC -> zobrazí "65"
  Serial.println(65); // odešle dané číslo do PC a přidá nový řádek
  Serial.write(65);   // zobrazí znak odpovídající dané ASCII hodnotě -> 65 = 'A' (více o ASCII: https://cs.wikipedia.org/wiki/ASCII)
  Serial.println(" Ahoj lidi"); // odešle z Arduina textový řetězec " Ahoj lidi"
}

int znak; // proměnná do které se ukládají příchozí znaky
void loop() {
  if (Serial.available()) // Serial.available() - řekne, zda jsou dostupná nějaká data na sériové lince: true 
  {
    znak = Serial.read(); // když jsou data dostupné -> Serial.available() == true -> přečtu jeden znak -> Serial.read()
    Serial.write(znak);   // pro kontrolu odešlu znak zpět po sériové lince do PC
    Serial.write('\n');   // + odešlu nový řádek -> '\n'
      
    // 0 -> vypnu LED
    // 1 -> zapnu LED
    if(znak == '0') { // pokud přišel znak '0' -> vypnu LED
      Serial.println(": Vypnu LED 1");
      digitalWrite(pin, LOW);
    } else if(znak == '1') { // pokud přišel znak '1' -> ...
      Serial.println(": Zapnu LED 1");
      digitalWrite(pin, HIGH);
    } else if(znak == 'z') {
      Serial.println(": Zapnu LED 2");
      digitalWrite(L_G, HIGH);
    } else if(znak == 'v') {
      Serial.println(": Vypnu LED 2");
      digitalWrite(L_G, LOW);
    }
  }
}
