#include <Arduino.h>
#include <DHT.h>

#define SM_PIN 4 // D4 PIN
#define LDR_PIN 2 // D2 PIN
#define DHT_PIN 5 // D5 PIN



DHT dhtSensor(DHT_PIN,DHT11);
void setup() {
  Serial.begin(115200);
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
