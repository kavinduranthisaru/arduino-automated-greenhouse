// // Greenhouse Project - P11-1

// #define BLYNK_PRINT Serial
// #define BLYNK_TEMPLATE_ID "TMPL69r-yXF-O"
// #define BLYNK_TEMPLATE_NAME "Group P11 1"
// #define BLYNK_AUTH_TOKEN "R1pTeFHT6IunKTTPmXDZw7QYzdRW4K52"

// #define WIFI_SSID "Dexter's iPhone"
// #define WIFI_PASSWORD "kavindu123"
// #define WIFI_TIMEOUT_MS 20000

// #include <Arduino.h>
// #include <DHT.h>
// #include <Wire.h>
// #include <SPI.h>
// #include "WiFi.h"
// #include <WiFiClient.h>
// #include <BlynkSimpleEsp32.h>

// // SENSORS PIN DEFINE
// #define DHT_PIN 27 // G27 PIN
// #define LDR_PIN 33 // G33 PIN
// #define SM_PIN 32 // G32 PIN

// // ACTUATORS PIN DEFINE
// #define HEATER_PIN 4 // G4 PIN
// #define COOLER_PIN 5 // G5 PIN
// #define DAY_LIGHT_PIN 17 // G17 PIN
// #define WATER_PUMP_PIN 16 // G16 PIN

// #define TEMPERATURE_UPPER 30;
// #define TEMPERATURE_LOWER 25;
// #define TEMPERATURE_LIMIT 28;
// #define LDR_LIMIT 36;
// #define SM_LIMIT 50;

// // DELAY TIME IN LOOP
// #define LOOP_DELAY 2000;

// DHT dhtSensor(DHT_PIN,DHT11);

// void connectToWiFi() {
//   Serial.println("Connecting to WiFi...");
//   WiFi.mode(WIFI_STA);
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
//   unsigned long startAttemptTime = millis();

//   while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_TIMEOUT_MS) {
//     if (WiFi.status() != WL_CONNECTED) {
//       Serial.println(" Failed!");

//     } else {
//       Serial.println("Connected!");
//       Serial.print("Current IP: ");
//       Serial.println(WiFi.localIP());

//     }
//   }
// }

// void WiFiStatus() {
//    if (WiFi.status() != WL_CONNECTED) {
//     Serial.println("Not Connected!");

//    } else {
//     Serial.println("Connected!");

//    }
// }

// void temperatureHandler() {
//   if (temperature > TEMPERATURE_UPPER) {
//     digitalWrite(HEATER_PIN, HIGH);

//   } else if (temperature == TEMPERATURE_LIMIT) {
//     digitalWrite(HEATER_PIN, LOW);

//   }

//   if (temperature < TEMPERATURE_LOWER) {
//     digitalWrite(COOLER_PIN, HIGH);

//   } else if (temperature == TEMPERATURE_LIMIT) {
//     digitalWrite(COOLER_PIN, LOW);

//   }
//  }

//  void sunlightHandler() {
//   if (ldrPercentage < LDR_LIMIT) {
//     digitalWrite(DAY_LIGHT_PIN, HIGH);

//   } else if (ldrPercentage > LDR_LIMIT) {
//     digitalWrite(DAY_LIGHT_PIN, LOW);

//   }
//  }

//  void soilmoistureHandler() {
//   if (smPercentage < SM_LIMIT) {
//     digitalWrite(WATER_PUMP_PIN, HIGH);

//   } else if (smPercentage > SM_LIMIT) {
//     digitalWrite(WATER_PUMP_PIN, LOW);

//   }
//  }

// void setup() {
//   Serial.begin(115200);
//   connectToWiFi();
//   Blynk.begin(BLYNK_AUTH_TOKEN, WIFI_SSID, WIFI_PASSWORD, "blynk.cloud", 80);
//   dhtSensor.begin();
//   pinMode(4, OUTPUT);
//   pinMode(5, OUTPUT);
//   pinMode(16, OUTPUT);
//   pinMode(17, OUTPUT);

// }

// void loop() {
//   int smValue = analogRead(SM_PIN);
//   int lightLevel = analogRead(LDR_PIN);
//   float temperature = dhtSensor.readTemperature();
//   float humidity = dhtSensor.readHumidity();
  
//   float smPercentage = ((4095 - smValue) / 4095.0) * 100.0;
//   float ldrPercentage = ((1900 - lightLevel) / 1900.0) * 100.0;

//   WiFiStatus();
//   temperatureHandler();
//   sunlightHandler();
//   soilmoistureHandler();
  
//   Blynk.virtualWrite(V0, temperature);
//   Blynk.virtualWrite(V1, humidity);
//   Blynk.virtualWrite(V2, ldrPercentage);
//   Blynk.virtualWrite(V3, smPercentage);

//   Serial.print("Soil moisture value: ");
//   Serial.print(smPercentage);
//   Serial.println("%");
//   Serial.print("LDR percentage: ");
//   Serial.print(ldrPercentage);
//   Serial.println("%");
//   Serial.print("Temperature value: ");
//   Serial.print(temperature);
//   Serial.print("°C");
//   Serial.print(" \t Humidity value: ");
//   Serial.print(humidity);
//   Serial.println("%");

//   delay(LOOP_DELAY);

// }



// LCD ADDRESS SCANNER
#include <Wire.h>

void setup() {
  Serial.begin (9600);
  while (!Serial) 
    {
    }

  Serial.println ();
  Serial.println ("HRTE PROJECTS I2C address. Scanning ...");
  byte count = 0;
  
  Wire.begin();
  for (byte i = 8; i < 120; i++)
  {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
      {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      count++; 
  } 
  }
  Serial.println ("Done.");
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s).");
}  

void loop() {}
