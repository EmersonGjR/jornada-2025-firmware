# ESP32 Firmware for Multi-Sensor BME688 with BLE Notification

This firmware is designed for the *ESP32 microcontroller* and enables the operation of up to 8 BME688 sensors using Bosch's BSEC2 library. It reads environmental data such as temperature, pressure, humidity, and gas resistance, then sends this data via Bluetooth Low Energy (BLE) notifications.

## Features

- Supports up to 8 BME688 sensors simultaneously.
- Uses BSEC2 library to process sensor data (IAQ, CO2 equivalent, bVOC, compensated temperature and humidity, etc.).
- Communicates with sensors via a communication multiplexer (I²C/SPI).
- Sends sensor data over Bluetooth Low Energy (BLE) using a custom GATT service.
- Designed and tested for the *ESP32* platform.

## Hardware Requirements

- ESP32 Development Board.
- Up to 8 BME688 sensors.
- Multiplexer setup (compatible with I²C or SPI, via comm_mux library).

## Libraries Used

- [BSEC2](https://www.bosch-sensortec.com/software-tools/software/bsec/) by Bosch for sensor fusion and output.
- commMux for interfacing multiple sensors over shared communication bus.
- ESP32's BLEDevice, BLEServer, and related BLE libraries (part of the ESP32 Arduino core).

## BLE Service

- *Device Name:* ESP32_BLE
- *Service UUID:* 4fafc201-1fb5-459e-8fcc-c5c9c331914b
- *Characteristic UUID:* beb5483e-36e1-4688-b7f5-ea07361b26a8
- Sends notifications of gas data.

## Installation & Setup

1. Clone this repository into your Arduino project directory.
2. Install the required libraries (BSEC2, commMux, and ESP32 BLE libraries).
3. Connect your BME688 sensors using I²C or SPI through a communication multiplexer.
4. Upload the firmware to your *ESP32* board using Arduino IDE or PlatformIO.
5. Open the Serial Monitor at 115200 baud to debug.
6. Connect a BLE client (e.g., nRF Connect) to receive sensor data notifications.

## Code Structure

- setup() initializes BLE and BME688 sensors.
- loop() iterates over each sensor, processing and sending data.
- newDataCallback() handles incoming data and prepares BLE notifications.
- checkBsecStatus() verifies and prints errors/warnings from BSEC and BME688.

## Output Example

Via Serial Monitor:
