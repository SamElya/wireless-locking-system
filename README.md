# README

## Introduction

This project aims to develop a wireless locking system using two ESP8266 modules and an electromagnetic lock. One of the ESP8266 modules is connected to a push button, while the other is connected to an electromagnetic lock via a relay, which controls the locking system. The ESP-NOW protocol is used to enable wireless communication between the two modules. This project is part of a home automation solution that allows remote control of access to a door.

## Project Functionality

1. **ESP-NOW**: The two ESP8266 modules communicate with each other using the ESP-NOW protocol.
    - The ESP8266 connected to the button sends a signal to the other ESP8266 when pressed.
    - The other ESP8266 receives this signal and activates or deactivates the electromagnetic lock.

2. **Electromagnetic Lock**:
    - The electromagnetic lock is responsible for the physical locking of the door.
    - It is powered by an external 6V DC source as the voltage of the ESP8266 (3.3V) is insufficient to operate it directly.

3. **Relay**:
    - The relay is used to switch the power to the electromagnetic lock based on the signals sent by the ESP8266.
    - This allows remote control of the 6V DC power to the electromagnetic lock.

4. **Push Button**:
    - The button is connected to one ESP8266 and allows the sending of commands to open or close the door.
    - A press activates the electromagnetic lock (closes the door), and a second press deactivates it (opens the door).

5. **MAC Address Retrieval**:
    - The `macAdress` code is used to retrieve and display the MAC address of each ESP8266 module via the Serial Monitor.
    - You need to upload this code to each ESP8266 before proceeding to the next steps.

## Required Materials

- **ESP8266** x2
- **Electromagnetic Lock** model RS 3002501280
- **Relay** 5V DC
- **Push Button** rated for 50mA 24V DC max
- **External Power Supply**: Sony Ericsson CST-60 charger (5V output)
- **Connection Wires**, **Breadboard**

## Wiring Diagram

1. **ESP8266 (button)**:
    - Connect one pin of the button to a digital input of the ESP8266.
    - Connect the other pin of the button to the GND of the ESP8266.

2. **ESP8266 (electromagnetic lock)**:
    - Connect a digital output of the ESP8266 to the relay.
    - Connect the relay to the external power source to control the power to the electromagnetic lock.

## Installation and Configuration

1. **Preparing the ESP8266 with Arduino**:
    - Install the Arduino IDE.
    - Add support for ESP8266 boards via the Boards Manager (URL: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`).
    - **First, upload the Arduino code "macAdress" to each ESP to obtain their MAC addresses (view in the Serial Monitor).**
    - **Specify the receiver's MAC address in the `broadcastAddress[]` variable in the "sender" file.**
    - Flash both ESP8266 modules with the necessary firmware to use ESP-NOW.
    - Upload the code to the ESP8266 connected to the button to send a signal to the other ESP8266 when the button is pressed.
    - On the ESP8266 connected to the electromagnetic lock, write the code to receive the ESP-NOW signal and switch the relay accordingly.

2. **Connecting the Modules**:
    - Follow the wiring diagrams to connect the various components (ESP8266, button, relay, electromagnetic lock).

3. **Power Supply**:
    - The ESP8266 is powered via USB (through a computer or power bank).
    - The relay is connected to an external power supply to provide the necessary voltage (6V DC) to the electromagnetic lock.

## Arduino Dependencies

- **ESP8266WiFi**: Allows configuring Wi-Fi on the ESP8266 modules.
- **ESP8266ESP-NOW**: Enables the use of the ESP-NOW protocol for wireless communication.

The libraries can be installed via the library manager in the Arduino IDE.
