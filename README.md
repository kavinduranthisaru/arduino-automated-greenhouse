# 🌱 Arduino Automated Greenhouse Project

Welcome to the **Automated Greenhouse Project** – a smart gardening solution powered by the **ESP32** microcontroller, bringing automation and IoT to your plants! 🌿🚀

---

## 📖 Overview

This project is designed to maintain optimal conditions in a greenhouse using real-time sensor data and automated controls. It monitors **temperature**, **humidity**, **soil moisture**, and **light levels**, and automatically adjusts the environment to help your plants thrive — all while being remotely accessible via the **Blynk IoT platform**! 📡📲

---

## ✨ Key Features

- 🌡️ **Temperature & Humidity Control**  
  Uses a **DHT11 sensor** to measure temperature and humidity. Activates **cooling or heating fans** when values go out of range.

- 💡 **Light Level Monitoring**  
  An **LDR sensor** detects ambient light. A **12V LED bulb** switches on automatically in low-light conditions.

- 🌾 **Soil Moisture Detection & Auto-Watering**  
  Monitors soil dryness using a **soil moisture sensor** and activates a **12V water pump** when watering is needed.

- 📲 **Remote Monitoring via Blynk**  
  Stay connected to your greenhouse from anywhere with **real-time data** and manual controls through the Blynk app.

---

## ⚡ Power Efficiency

To optimize energy use, we implemented **buck converters** to safely step down voltage from a 12V power source, efficiently powering the entire system. 🔋⚙️

---

## 🔌 Actuators & Hardware

- 🌬️ **Heater & Cooler Fans**: 2 x 80mm 12V fans controlled via relays  
- 💧 **Water Pump**: 12V pump triggered by soil moisture readings  
- 🔆 **LED Light**: 12V daylight bulb for supplemental lighting

---

## 📡 IoT Platform

We used **Blynk** to create a wireless dashboard for live monitoring and control via Wi-Fi. With Blynk, you can check real-time data, toggle components, and fine-tune your greenhouse settings — all from your smartphone! 📱🌍

---

## 🧩 Circuit Diagram

![Circuit Diagram](https://i.ibb.co/kxkWgs7/Circuit-diagram-P11-1.jpg)

---

## 👨‍👩‍👧‍👦 Project Team

- 👨‍💻 Kavindu Ranthisaru  
- 👩‍🔬 Dinithi Wickramasekara  
- 👨‍🔧 Sasindu Amaraguru  
- 👩‍🌾 Tharushi Samarasinghe  
- 👨‍💼 Hasindu Methsara  
- 👩‍💻 Amesha Rajapaksha  

---

## 📂 Repository

🔗 **GitHub Repo**: [arduino-automated-greenhouse](https://github.com/kavinduranthisaru/arduino-automated-greenhouse)

---

Let’s grow smart! 🌿🤖💧  
Feel free to fork, star ⭐, or contribute to this project.
