# Smart Flower Pot (IoT)

An Arduino-based smart flower pot that reads soil moisture and tells you whether the plant needs water, using an LCD message and coloured LEDs. Final project for the Internet of Things course (Işık University, 2024).

## How it works

The Arduino Nano powers the soil moisture sensor, reads its value and compares it with two thresholds:

| Sensor reading | LCD message | LED colour | Meaning |
| :--- | :--- | :---: | :--- |
| above 1200 | "Bana Su Ver" (*Give me water*) | 🔴 Red | Soil is dry |
| 550 – 1200 | "Su İstemiyorum" (*I don't need water*) | 🟢 Green | Moisture is fine |
| below 550 | "Su Çok Fazla!!" (*Too much water!*) | 🔵 Blue | Soil is too wet |

The sensor is powered only while it is being read, and every reading is also printed to the serial monitor.

## Hardware

- Arduino Nano
- Soil moisture sensor
- 16×2 I2C LCD display
- NeoPixel RGB LEDs (16)

## Files

| File | Description |
| :--- | :--- |
| `AKILLISAKSI.ino` | Arduino sketch |
| `DamlaSuYayla.pdf` | Project report (Turkish) |

## Libraries

`Wire` · `LiquidCrystal_I2C` · `Adafruit_NeoPixel`
