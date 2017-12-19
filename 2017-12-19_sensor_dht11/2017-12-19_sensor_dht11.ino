#include <LearningKit.h>

#include <DHT.h>
// Knihovnu DHT přidáme přes:
// [CZ] Projekt -> Přidat knihovnu -> Spravovat knihovny ..
// [EN] Sketch -> Include Library -> Manage libraries..
// Otevře se Manažér knihoven (Library Manager)
// Do vyhledávacího pole zadáte "DHT" a vyberete hned první
// knihovnu "DHT sensor linrary by Adafruit"
// a zmáčknete tlačítko Instalace. 
// Nyní už můžete z vesela používat senzory DHT

#define DHTTYPE  DHT11 // definuje typ senzoru DHT -> my používáme DHT11
DHT dht(DHT_PIN, DHTTYPE); // vytváří objekt dht, jeho typ je DHT11 a DHT_PIN je nastaven v LearningKit.h

void setup() { // Nastavíme piny a sériovou linku
  setupLeds();
  Serial.begin(9600);
  Serial.println("Zaciname pracovat");
  dht.begin(); // nastaví senzor DHT
}

void loop() {
  Serial.print("Teplota: ");
  Serial.print(dht.readTemperature()); // přečteme teplotu ze senzoru
  Serial.print("   Vlhkost: ");
  Serial.println(dht.readHumidity()); // přečteme vlhost ze senzoru
  delay(200);
}

