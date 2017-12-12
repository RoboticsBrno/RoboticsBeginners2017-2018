#include <LearningKit.h>

//static const int pin = L_R;
int pin = L_R;

void setup() {
  //pinMode(pin, OUTPUT); // lze nastavit jednotlivé piny
  setupLeds();            // nebo můžete využít funkci v naší knihovně

  // Seril.begin() -> musí být vždy v setup() pokud chceme používat Serial Monitor (komunikace mezi PC a Arduinem)
  Serial.begin(9600); // otevře seriový port, komunikační linku mezi Arduinem a PC, komunikační rychlost 9600 bps (bity za sekundu -> běžně přednastavená rychlost u Seriového monitoru v Arduino prostředích)
  Serial.println(" Ahoj lidi"); 
}

int znak; // proměnná do které se ukládají přichozí znaky
bool ledStav = false;
void loop() {
  if(Serial.available()) {
    znak = Serial.read();
    if(znak == 'c') {                   // pokud příjde znak 'c'
      if(ledStav == false) {              // a ledStav je roven FALSE
        ledStav = true;                     // ledStav se nastaví na TRUE -> digitalWrite() na konci programu zapne LED
        Serial.println("LED zapnuta");      // a na sériové lince se vypíše text "LED zapnuta"    
      } else {                            // když se ledStav nerovná FALSE
        ledStav = false;                    // ledStav se nastaví na FALSE -> digitalWrite() na konci programu vypne LED
        Serial.println("LED vypnuta");      // a na sériové lince se vypíše text "LED zapnuta"
      }
    } else {                            // pokud nepříjde znak 'c' -> vypíše se info na sériovou linku
      Serial.print("Poslal jste spatny znak: ");
      Serial.write(znak);
      Serial.print("\nPro ovladani LED poslete 'c'\n");  
    }
  }
  digitalWrite(L_G, ledStav); // nastaví (zapne/vypne) LED podle promněnné ledStav

//  // ukázka jednoduchého zapínání a vypínání (== blikání) LED
//  if(digitalRead(SW1) == LOW) {
//    digitalWrite(L_G, HIGH);
//    Serial.println("LED zapnuta");    
//  } else {
//    digitalWrite(L_G, LOW);
//    Serial.println("LED vypnuta");
//  }
//  delay(200);
}
