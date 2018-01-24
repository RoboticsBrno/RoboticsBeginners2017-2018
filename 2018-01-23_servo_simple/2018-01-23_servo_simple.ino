#include <LearningKit.h>

// Generování PWM signálu pomocí delay()/ delayMicroseconds()
// https://en.wikipedia.org/wiki/Servo_control
// https://en.wikipedia.org/wiki/Servo_control#/media/File:ServoPwm.png

void setup() {
  pinMode(S1, OUTPUT);
}

void loop() {
  int sig = analogRead(POT1); // 0 - 4096
  digitalWrite(S1, HIGH);
  delayMicroseconds(1000);
  delayMicroseconds(sig/4);   // sig/4 = 0 - 1024 
  digitalWrite(S1, LOW);
  delayMicroseconds(19000 - (sig/4));
}
