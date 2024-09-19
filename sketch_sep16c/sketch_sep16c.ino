// #define BLYNK_PRINT Serial
// #define BLYNK_TEMPLATE_ID "TMPL69r-yXF-O"
// #define BLYNK_TEMPLATE_NAME "Group P11 1"
// #define BLYNK_AUTH_TOKEN "CJTZHTAItg-x9yoAH99yg45YIEHhuauW"

// #define WIFI_SSID "Galaxy A33 5G0666"
// #define WIFI_PASSWORD "11111111"
// #define WIFI_TIMEOUT_MS 20000
// #include <Arduino.h>
// #include <DHT.h>
// #include <Wire.h>
// #include <SPI.h>
// #include "WiFi.h"
// #include <WiFiClient.h>
// #include <BlynkSimpleEsp32.h>

// #define SM_PIN 32 // D32 PIN
// #define LDR_PIN 33 // D33 PIN
// #define DHT_PIN 27 // D27 PIN

// // ACTUATORS PIN DEFINE
// #define HEATER_PIN 4   
// #define COOLER_PIN 5   
// #define WATER_PUMP_PIN 16   
// #define DAY_LIGHT_PIN 17  

// #define TEMERATURE_UPPER_LEVEL=30;
// #define TEMERATURE_UPPER_LEVEL=28;
// #define LIGHT_TRESHOLD=30;



// DHT dhtSensor(DHT_PIN,DHT11);

// void handleLight(int ldrValue){

// }

// void connectToWiFi() {
//   Serial.println("Connecting to WiFi...");
//   WiFi.mode(WIFI_STA);
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//   unsigned long startAttemptTime = millis();
//   while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_TIMEOUT_MS) {
//     if (WiFi.status() != WL_CONNECTED) {
//       Serial.println(" Failed!");
//       // take action
//     } else {
//       Serial.println("Connected!");
//       Serial.print("Current IP: ");
//       Serial.println(WiFi.localIP());
//     }
//   }
// }



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

//   delay(2000);

// }

#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Serial.println("\nI2C Scanner");
  byte count=0;
  Wire.begin(21, 22);  // Initialize I2C on ESP32 with SDA on GPIO 21, SCL on GPIO 22
  for(byte i=8;i<120;i++){
    Wire.beginTransmission(i);
    if(Wire.endTransmission()==0){
  Serial.print(i,DEC);
  Serial.print(" (0x");
    }
  }  // Wait for Serial to initialize
}

void loop() {
  
}