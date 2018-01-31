#include <LearningKit.h>

// Generování PWM signálu pomocí delay()/ delayMicroseconds()
// https://en.wikipedia.org/wiki/Servo_control
// https://en.wikipedia.org/wiki/Servo_control#/media/File:ServoPwm.png

void setup() {
  pinMode(S1, OUTPUT);	// S1 - výstup pro serva	 			
}

void loop() {
  int sig = analogRead(POT1);	// 0 - 4096 -> rozsah hodnot, který vrací analogRead()
  digitalWrite(S1, HIGH);    	// nastaví výstupní signal na HIGH = VCC
  delayMicroseconds(1000);   	// počká 1 ms (= 1000 us = 0,001 s) - standard pro servo signál
  delayMicroseconds(sig/4);  	// sig/4 = 0 - 1024 -> počká dalších 0 - 1024 us, podle polohy potenciometru 
  digitalWrite(S1, LOW);     	// nastaví výstupní signal na LOW = GND = 0 V
  delayMicroseconds(19000 - (sig/4)); // počká 19000 us - pozice potenciometru, tak aby byl generován správný servo signál
}
