# Automated Greenhouse Project

## Overview
The Automated Greenhouse Project utilizes an ESP32 microcontroller, various sensors, and actuators to create a smart greenhouse environment. This system automatically monitors and adjusts temperature, humidity, light levels, and soil moisture to maintain optimal growing conditions for plants.

## Team Members
- Kavindu Ranthisaru
- Dinithi Wickramasekara
- Sasindu Amaraguru
- Tharushi Samarasinghe
- Hasindu Methsara
- Amesha Rajapaksha

## Features
- **Temperature & Humidity Control**: Monitors the environment using a DHT11 sensor. The system activates either a heater or cooler (12V fans) based on predefined temperature thresholds.
- **Light Control**: An LDR (light-dependent resistor) detects ambient light levels. A 12V LED bulb is activated when light levels drop below a threshold.
- **Soil Moisture Management**: A soil moisture sensor tracks moisture levels in the soil. A 12V water pump automatically waters the plants when the soil becomes too dry.
  
## Power Efficiency
We utilized buck converters to step down the voltage from a 12V power pack to power the system, ensuring efficient energy usage.

## Actuators
- **Heater & Cooler**: Two 80mm 12V fans act as a heater and cooler, controlled automatically via relay modules.
- **Water Pump**: A 12V pump waters the plants based on soil moisture readings.
- **LED Bulb**: A 12V daylight bulb provides additional light when ambient light is insufficient.

## IoT Integration
Using the Blynk IoT platform, the system allows for remote monitoring and control through Wi-Fi, enabling real-time adjustments to environmental conditions.

##Circuit Diagram
<img src="https://i.ibb.co/7XhpRPq/Circuit-diagram-P11-1.png" alt="Circuit-diagram-P11-1" border="0">
