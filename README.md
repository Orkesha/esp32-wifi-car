# Project Name: WiFi Controlled Car


## Description:
This project allows you to control a car remotely using WiFi. It consists of two main components: an ESP32-based controller for the car, and an Arduino Nano-based controller for the car's movements. By connecting to the designated WiFi network and accessing a web interface, you can drive the car in various directions.

## Hardware Requirements:
ESP32 development board (e.g., ESP32 CAM)
Arduino Nano
Motor driver module
Chassis, motors, wheels, and other necessary mechanical components for the car
Power source (e.g., battery pack)
Wires and connectors for hardware connections

## Software Requirements:
Arduino IDE
ESP32 core (version 1.0.6 or later)
Internet browser

## Installation and Setup:
Upload the **esp32_car.ino** file to the ESP32 development board using Arduino IDE.
Upload the **nano_car.ino** file to the Arduino Nano using Arduino IDE.
Wire and connect the components according to the schematic or instructions provided.
Connect to the WiFi network named **"ESP CAR"** with the password **"12345678"**.
Open a web browser and navigate to **http://192.168.4.1/**.
Enjoy controlling the car remotely!

## Usage:
Once connected to the web interface, you should see controls for driving the car in different directions (forward, backward, left, right).
Click on the respective buttons to control the car's movements.
Experiment with different commands to maneuver the car effectively.

## Troubleshooting:
If you encounter any issues, ensure that all components are properly connected and powered.
Check the serial monitor in the Arduino IDE for any error messages or debugging information.
Make sure you're connected to the correct WiFi network with the correct password.

## Credits:
This project was created by Lord Orka. Feel free to contribute or report issues on GitHub.

## License:
This project is licensed under the MIT License. Feel free to use and modify it according to your needs.

## Disclaimer:
**Caution**: This project involves working with electronic components and potentially hazardous moving parts. Take necessary precautions and ensure adult supervision, especially if working with children.
The creators of this project are not responsible for any damage or harm caused by the construction or operation of the WiFi Controlled Car.




