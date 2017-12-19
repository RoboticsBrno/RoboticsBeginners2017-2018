#include <LearningKit.h>

void setup() {
  // Nastavíme piny a sériovou linku
  setupLeds();
  Serial.begin(9600);
  Serial.println("Zaciname pracovat");
}

int intenzitaSvetla = 0; // proměnná pro ukládání hodnoty z pinu PHOTO
void loop() {
  intenzitaSvetla = analogRead(PHOTO);  // vyčteme analogovou hodnotu (napětí) na pinu PHOTO
  Serial.println(intenzitaSvetla);      // vypiseme intenzitu okolního osvětlení na sériovou linku
  delay(200);

  // následuje zapínání LEDek podle proměnné intenzitaSvetla
  digitalWrite(L_R, LOW);
  digitalWrite(L_Y, LOW);
  digitalWrite(L_G, LOW);
  digitalWrite(L_B, LOW);
  if(intenzitaSvetla > 1000) {
    digitalWrite(L_B, HIGH);
  }
  if(intenzitaSvetla > 2000) {
    digitalWrite(L_G, HIGH);
  }
  if(intenzitaSvetla > 3000) {
    digitalWrite(L_Y, HIGH);
  }
  if(intenzitaSvetla > 4000) {
    digitalWrite(L_R, HIGH);
  }
}
