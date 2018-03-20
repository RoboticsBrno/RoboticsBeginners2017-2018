#define I2C_SDA 27
#define I2C_SCL 14

// PCF8574 
//#define LCD_I2C_ADDR 0x27
// PCF8574A 
#define LCD_I2C_ADDR 0x3f
#define LCD_WIDTH 20
#define LCD_HEIGHT 4
 
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(LCD_I2C_ADDR, LCD_WIDTH, LCD_HEIGHT);
 
void setup() {
    Serial.begin(115200);
    Serial.println("\n\n\nI2C LCD display test");
 
    Wire.begin(I2C_SDA, I2C_SCL);
 
    lcd.begin(LCD_WIDTH, LCD_HEIGHT);
    lcd.backlight();
 
    lcd.print("ahoj");
    Serial.print("ahoj\n");
}
 
int receiveCh;
 
void loop() {
    if (Serial.available()) {
        receiveCh = Serial.read();
        lcd.write(receiveCh);
 
        Serial.write(receiveCh);
    }
}
