#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL69r-yXF-O"
#define BLYNK_TEMPLATE_NAME "Group P11 1"
#define BLYNK_AUTH_TOKEN "gl4oQmenFMzMvro-Bp-DCjDFM65azQYX"

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


#define SM_PIN 4 // D4 PIN
#define LDR_PIN 2 // D2 PIN
#define DHT_PIN 5 // D5 PIN



DHT dhtSensor(DHT_PIN,DHT11);

void connectToWiFi()
{
  Serial.print("Connecting to WiFi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  unsigned long startAttemptTime = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_TIMEOUT_MS)
  {
    Serial.print(".");
    delay(100);
    if (WiFi.status() != WL_CONNECTED)
    {
      Serial.println(" Failed!");
      // take action
    }
    else
    {
      Serial.print("Connected!");
      Serial.println(WiFi.localIP());
    }
  }
}




void setup() {
  connectToWiFi();
  Serial.begin(9600);
   Blynk.begin(BLYNK_AUTH_TOKEN, WIFI_SSID, WIFI_PASSWORD, "blynk.cloud", 80);

  dhtSensor.begin();

}

void loop() {
  int smValue = analogRead(SM_PIN);
  int lightLevel = analogRead(LDR_PIN);
  float temperature = dhtSensor.readTemperature();
  float humidity = dhtSensor.readHumidity();
  
  
  float smPercentage = ((4095 - smValue) / 4095.0) * 100.0;
  
  Serial.print("soil moisture value : ");
  Serial.print(smPercentage);
  Serial.println("%");
  Serial.print("LDR value : ");
  Serial.println(lightLevel);
  Serial.print("temperature value : ");
  Serial.print(temperature);
  Serial.print(" \t humidity value : ");
  Serial.println(humidity);

  
  delay(2000);

}