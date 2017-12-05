#include <LearningKit.h>

//static const int pin = L_R;
int pin = L_R;

void setup() {
  //pinMode(pin, OUTPUT); // lze nastavit jednotlivé piny
  setupLeds();            // nebo můžete využít funkci v naší knihovně
  
  Serial.begin(9600);
  Serial.print(65);
  Serial.write(65);
  Serial.println(" Ahoj lidi");
}

int znak;
void loop() {
  if (Serial.available()) {
    znak = Serial.read();
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
