#include <LearningKit.h>

void setup() {
  pinMode(S1, OUTPUT);
}

void loop() {
  int sig = analogRead(POT1); // 0 - 4096
  digitalWrite(S1, HIGH);
  delayMicroseconds(1000);
  delayMicroseconds(sig/4);
  digitalWrite(S1, LOW);
  delayMicroseconds(19000 - (sig/4));
}
