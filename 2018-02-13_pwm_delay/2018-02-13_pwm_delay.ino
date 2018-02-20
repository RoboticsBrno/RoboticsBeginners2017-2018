#include <LearningKit.h>

// Generování PWM signálu pomocí delay()/ delayMicroseconds()
// info PWM: https://cs.wikipedia.org/wiki/Pulzn%C4%9B_%C5%A1%C3%AD%C5%99kov%C3%A1_modulace

const int PWM_pin = L_R; 

void setup() {
  pinMode(PWM_pin, OUTPUT);  // S1 - výstup pro serva        
}

void loop() {
  int sig = analogRead(POT1);   // 0 - 4095 -> rozsah hodnot, který vrací analogRead()
  digitalWrite(PWM_pin, HIGH);  // nastaví výstupní signal na HIGH = VCC
  delayMicroseconds(sig);       // sig = 0 - 4095 -> počká dalších 0 - 4095 us, podle polohy potenciometru 
  digitalWrite(PWM_pin, LOW);   // nastaví výstupní signal na LOW = GND = 0 V
  delayMicroseconds(4095 - sig);// počká (4095 - sig) us -> generuje PWM se stridou 50 % 
  // info Střída: https://cs.wikipedia.org/wiki/St%C5%99%C3%ADda_(elektronika)
}
