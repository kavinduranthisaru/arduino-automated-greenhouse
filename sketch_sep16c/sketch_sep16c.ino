/*#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL69r-yXF-O"
#define BLYNK_TEMPLATE_NAME "Group P11 1"
#define BLYNK_AUTH_TOKEN "CJTZHTAItg-x9yoAH99yg45YIEHhuauW"

#define WIFI_SSID "Im Not A Witch Im Your Wifi ;)"
#define WIFI_PASSWORD "Walura@458699%"
#define WIFI_TIMEOUT_MS 20000
#include <Arduino.h>
#include <DHT.h>
#include <Wire.h>
#include <SPI.h>
#include "WiFi.h"
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define SM_PIN 32 // D32 PIN
#define LDR_PIN 33 // D33 PIN
#define DHT_PIN 27 // D27 PIN

DHT dhtSensor(DHT_PIN,DHT11);

void connectToWiFi() {
  Serial.println("Connecting to WiFi...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  unsigned long startAttemptTime = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_TIMEOUT_MS) {
    if (WiFi.status() != WL_CONNECTED) {
      Serial.println(" Failed!");
      // take action
    } else {
      Serial.println("Connected!");
      Serial.print("Current IP: ");
      Serial.println(WiFi.localIP());
    }
  }
}

void test() {
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(18, HIGH);
  delay(30000);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(18, LOW);

}

void setup() {
  Serial.begin(115200);
  connectToWiFi();
  Blynk.begin(BLYNK_AUTH_TOKEN, WIFI_SSID, WIFI_PASSWORD, "blynk.cloud", 80);
  dhtSensor.begin();
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(18, OUTPUT);

  test();

}

void loop() {
  int smValue = analogRead(SM_PIN);
  int lightLevel = analogRead(LDR_PIN);
  float temperature = dhtSensor.readTemperature();
  float humidity = dhtSensor.readHumidity();
  
  
  float smPercentage = ((4095 - smValue) / 4095.0) * 100.0;
  float ldrPercentage = ((1900 - lightLevel) / 1900.0) * 100.0;
  
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);
  Blynk.virtualWrite(V2, ldrPercentage);
  Blynk.virtualWrite(V3, smPercentage);

  Serial.print("Soil moisture value: ");
  Serial.print(smPercentage);
  Serial.println("%");
  Serial.print("LDR percentage: ");
  Serial.print(ldrPercentage);
  Serial.println("%");
  Serial.print("Temperature value: ");
  Serial.print(temperature);
  Serial.print("°C");
  Serial.print(" \t Humidity value: ");
  Serial.print(humidity);
  Serial.println("%");

  delay(2000);

} */


#include <Arduino.h>

void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(18, OUTPUT);

}

void loop() {
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(18, HIGH);
  delay(20000);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(18, LOW);
  delay(10000);

}
