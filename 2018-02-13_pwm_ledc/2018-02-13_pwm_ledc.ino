#include "LearningKit.h"

void setup() {
    Serial.begin(115200);
    setupRgbLed();
    setupLeds();
    setupButtons();

    ledcSetup(1, 1000, 12); // ledcSetup(kanal, frekvence v Hz, rozliseni v bitech)
    // kanal = 0 - 15
    // frekvence = 1 - x Hz
    // rozliseni = 10 => 2^10 => 1024
    // rozliseni = 12 => 2^12 => 4096 => analogRead()
    ledcAttachPin(L_G, 1);
}

void loop() {
    ledcWrite(1, analogRead(POT1)); // ledcWrite(kanal, hodnota)
    // hodnota => rozliseni = 0 - 4095
    delay(1);
}
