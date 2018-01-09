#include "LearningKit.h"
#include "credentials.h" // ZDE JSOU ZADÁNY PŘIHLAŠOVACÍ ÚDEJE K WIFI!!!

#include <DHT.h>
#define DHTTYPE DHT11
DHT dht(DHT_PIN, DHTTYPE);

#include <WiFi.h>
WiFiClient client;
String api_key = "KYJKQ9OB0RQZJ9CL";  //please place your own api key heres
const char* server = "api.thingspeak.com";

void initWiFi(){
  Serial.println("Pripojuji se na WiFi");
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pwd);
  while(WiFi.status() != WL_CONNECTED){
      delay(500);
      Serial.print(".");
  }
  
  Serial.print("Jsme pripojen na \"");
  Serial.print(ssid);
  Serial.print("\" WIFI s IP adresou: \n");
  Serial.print(WiFi.localIP());
}

void setup (){
  Serial.begin(9600);
  setupButtons();
  setupLeds();
  initWiFi();
  dht.begin();
  Serial.print("Nazdar svete\n");
}

void loop (){
  long timeFromStart = millis()/1000;
  if (client.connect(server,80)) {
      String message = api_key;
      message += "&field1=";
      message += String(dht.readTemperature());
      message += "&field2=";
      message += String(dht.readHumidity());
      message += "\r\n\r\n";
      client.print("POST /update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("X-THINGSPEAKAPIKEY: "+api_key+"\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(message.length());
      client.print("\n\n");
      client.print(message);
      
      Serial.print("Cas od spusteni Arduina: ");
      Serial.print(timeFromStart);
      Serial.print(" vterin"); 
      Serial.println();
      Serial.println(message);
      Serial.println("Udaje odeslany na Thingspeak.");
  }
  client.stop();
  Serial.println("Pauza pred dalsim odeslanim dat. \n");
  delay(30000);
}
