// Greenhouse Project - P11-1

#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL69r-yXF-O"
#define BLYNK_TEMPLATE_NAME "Group P11 1"
#define BLYNK_AUTH_TOKEN "atVBx-PFCYq1ifT__EuDDuPuCQgDxdD5"

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

// SENSORS PIN DEFINE
#define DHT_PIN 27 // G27 PIN
#define LDR_PIN 33 // G33 PIN
#define SM_PIN 32 // G32 PIN

// ACTUATORS PIN DEFINE
#define HEATER_PIN 4 // G4 PIN
#define COOLER_PIN 5 // G5 PIN
#define DAY_LIGHT_PIN 17 // G17 PIN
#define WATER_PUMP_PIN 16 // G16 PIN

int TEMP_UPPER = 32;
int TEMP_LOWER = 28;
int LDR_THRESHOLD = 36;
int SM_THRESHOLD = 50;

DHT dhtSensor(DHT_PIN,DHT11);
BlynkTimer timer;

int DATA_INTERVAL = 3000L;
int WiFi_INTERVAL = 30000L;

void connectToWiFi() {
  Serial.println("Connecting to WiFi...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  unsigned long startAttemptTime = millis();

  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_TIMEOUT_MS) {
    if (WiFi.status() != WL_CONNECTED) {
      Serial.println("Connection Failed!");

    } else {
      Serial.println("WiFi Connected!");
      Serial.print("Current IP: ");
      Serial.println(WiFi.localIP());

    }
  }
}

void WiFiStatus() {
  if (WiFi.status() != WL_CONNECTED) {
      Serial.println("WiFi Status: Not Connected! \n");

    } else {
      Serial.println("WiFi Status: Connected! \n");
    }
}

BLYNK_CONNECTED() {
  Blynk.syncVirtual(V4, V5, V6, V7);
}

BLYNK_WRITE(V4) {
  TEMP_UPPER = param.asInt();
}

BLYNK_WRITE(V5) {
  TEMP_LOWER = param.asInt();
}

BLYNK_WRITE(V6) {
  LDR_THRESHOLD = param.asInt();
}

BLYNK_WRITE(V7) {
  SM_THRESHOLD = param.asInt();
}

void dataReadAndWrite() {
  int smValue = analogRead(SM_PIN);
  int ldrValue = analogRead(LDR_PIN);
  float temperature = dhtSensor.readTemperature();
  float humidity = dhtSensor.readHumidity();
  
  float smPercentage = ((4095 - smValue) / 4095.0) * 100.0;
  float ldrPercentage = ((4095 - ldrValue) / 4095.0) * 100.0;

  int TEMP_THRESHOLD = (TEMP_UPPER + TEMP_LOWER) / 2;

  // COOLER HANDLER
  if (temperature > TEMP_UPPER) {
    digitalWrite(COOLER_PIN, LOW);
    Blynk.virtualWrite(V12, 1);
  } else if (temperature <= TEMP_THRESHOLD) {
    digitalWrite(COOLER_PIN, HIGH);
    Blynk.virtualWrite(V12, 0);
  }

  // HEATER HANDLER
  if (temperature < TEMP_LOWER) {
    digitalWrite(HEATER_PIN, LOW);
    Blynk.virtualWrite(V13, 1);

  } else if (temperature >= TEMP_THRESHOLD) {
    digitalWrite(HEATER_PIN, HIGH);
    Blynk.virtualWrite(V13, 0);

  }

  // DAY LIGHT HANDLER
  if (ldrPercentage < LDR_THRESHOLD) {
    digitalWrite(DAY_LIGHT_PIN, LOW);
    Blynk.virtualWrite(V14, 1);

  } else {
    digitalWrite(DAY_LIGHT_PIN, HIGH);
    Blynk.virtualWrite(V14, 0);

  }

  // WATER PUMP HANDLER
  if (smPercentage < SM_THRESHOLD) {
    digitalWrite(WATER_PUMP_PIN, LOW);
    Blynk.virtualWrite(V15, 1);

  } else {
    digitalWrite(WATER_PUMP_PIN, HIGH);
    Blynk.virtualWrite(V15, 0);

  }
  
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
  Serial.println("% \n");

}

void setup() {
  Serial.begin(115200);
  dhtSensor.begin();
  connectToWiFi();
  Blynk.begin(BLYNK_AUTH_TOKEN, WIFI_SSID, WIFI_PASSWORD, "blynk.cloud", 80);
  timer.setInterval(DATA_INTERVAL, dataReadAndWrite);
  timer.setInterval(WiFi_INTERVAL, WiFiStatus);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);

  Blynk.virtualWrite(V4, TEMP_UPPER);
  Blynk.virtualWrite(V5, TEMP_LOWER);
  Blynk.virtualWrite(V6, LDR_THRESHOLD);
  Blynk.virtualWrite(V7, SM_THRESHOLD);

  digitalWrite(COOLER_PIN, LOW);
  digitalWrite(HEATER_PIN, LOW);

}

void loop() {
  Blynk.run();
  timer.run();
  
}

