# Lab Activity 3: I2C Multi-Module Communication with ESP32

## 📌 Project Overview
This repository contains the implementation for Lab Activity 3, focusing on the **I2C (Inter-Integrated Circuit)** communication protocol. The objective is to demonstrate how multiple slave devices can coexist on a single I2C bus using an **ESP32** as the master.

In this setup, the ESP32 simultaneously communicates with a **DS3231 Real-Time Clock (RTC)** to retrieve precise time data and a **16x2 I2C LCD** to display that data in real-time.

---

## 🛠️ Hardware Components
* **Microcontroller:** ESP32 (DevKit V1)
* **Display:** 16x2 LCD with I2C Backpack (PCF8574)
* **Timekeeper:** DS3231 RTC Module
* **Wiring:** Breadboard and Jumper Wires

---

## 🔌 Circuit & Pin Mapping
Since I2C is a bus protocol, both modules share the same data and clock lines.

| ESP32 Pin | LCD (I2C) | DS3231 RTC |
| :--- | :--- | :--- |
| **VIN (5V)** | VCC | VCC |
| **GND** | GND | GND |
| **GPIO 21 (SDA)** | SDA | SDA |
| **GPIO 22 (SCL)** | SCL | SCL |

---

## 📂 Repository Contents
* `I2C_MultiModule_Clock.ino`: The primary Arduino sketch that initializes the I2C bus, retrieves time from the RTC, and updates the LCD.
* `I2C_Scanner.ino`: A utility script used to verify the hex addresses of the connected modules.

---

## ⚙️ How it Works
1.  **I2C Scanning:** The system first identifies the unique hex addresses (typically `0x27` for the LCD and `0x68` for the RTC).
2.  **Data Retrieval:** The ESP32 requests the current timestamp from the DS3231 over the I2C bus.
3.  **Data Processing:** The raw time data is formatted into a readable string.
4.  **Display:** The formatted time and date are sent to the LCD via the same I2C bus.

---

## 📚 Libraries Used
To run this code, ensure you have the following libraries installed in your Arduino IDE:
* `RTClib` by Adafruit
* `LiquidCrystal I2C` by Frank de Brabander
* `Wire.h` (Built-in)

---
 
Date: February 25 2026