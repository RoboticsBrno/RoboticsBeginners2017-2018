#include <LearningKit.h>

//static const int pin = L_R;
int pin = L_R;

void setup() {
  //pinMode(pin, OUTPUT); // lze nastavit jednotlivé piny
  setupLeds();            // nebo můžete využít funkci v naší knihovně

  // Seril.begin() -> musí být vždy v setup() pokud chceme používat Serial Monitor (komunikace mezi PC a Arduinem)
  Serial.begin(9600); // otevře seriový port, komunikační linku mezi Arduinem a PC, komunikační rychlost 9600 bps (bity za sekundu -> běžně přednastavená rychlost u Seriového monitoru v Arduino prostředích)
  Serial.print(65);   // odešle dané číslo do PC -> zobrazí "65"
  Serial.println(65); // odešle dané číslo do PC a přidá nový řádek
  Serial.write(65);   // zobrazí znak odpovídající dané ASCII hodnotě -> 65 = 'A' (více o ASCII: https://cs.wikipedia.org/wiki/ASCII)
  Serial.println(" Ahoj lidi"); 
}

int znak; // proměnná do které se ukládají přichozí znaky
void loop() {
  if (Serial.available()) // Serial.available() - řekne, zda jsou dostupná nějaká data na sériové lince: true 
  {
    znak = Serial.read(); // když jsou data dostupné (Serial.available()), přečtu jeden znak (Serial.read())
    Serial.write(znak);
    Serial.write('\n');
      
    // 0 -> vypnu LED
    // 1 -> zapnu LED
    if(znak == '0') {
      Serial.println(": Vypnu LED 1");
      digitalWrite(pin, LOW);
    } else if(znak == '1') {
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
