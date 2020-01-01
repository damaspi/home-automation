# Simple test : Arduino LED on RF

## Description

Two Arduino talking to each other on Radio Frequency (2.4Ghz): both having a button and a led. When the button on one is pressed, the LED on the other should turn on.

## Inspiration

After some research on the nRF24L01, I followed this project: https://create.arduino.cc/projecthub/muhammad-aqib/nrf24l01-interfacing-with-arduino-wireless-communication-0c13d4

## Hardware

* 2 arduinos (in fact, one Arduino UNO and one XDRduino UNO)
* 2 nRF24L01 + 47µF capacitor (capacitor may not be needed, depending on the power supply used to power the radio)
* 2 LED + 220 Ω resistor
* 2 switches + 10 KΩ resistor

## Connections

![Arduino Uno pinout diagram](/media/arduino-uno-pinout-diagram.png)
[Pinout of ARDUINO Board and ATMega328PU](https://commons.wikimedia.org/wiki/File:Pinout_of_ARDUINO_Board_and_ATMega328PU.svg) by pighixxx is licensed under [Creative Commons Attribution-Share Alike 4.0 International](https://creativecommons.org/licenses/by-sa/4.0/deed.en)

I used the standard SPI pins 10,11,12,13 (SS, MOSI, MISO, SCK) + CE on 9
The LED is connected on pin 3.
The button is connected on pin 2.

![Project diagram](/media/ArduinoRF24ButtonLED.png)

## Software

I used the Arduino IDE and added the RF24 library to the project.

![Arduino library manager: RF24 library](/media/ArduinoRF24ButtonLED-ArduinoIDE-RF24library.png)

## What I learned
* [nRF24L01](https://lastminuteengineers.com/nrf24l01-arduino-wireless-communication/)
* Serial Peripheral Interfaces ([SPI](https://en.wikipedia.org/wiki/Serial_Peripheral_Interface)).
* Patience from connecting the nRF24L01 to the arduino (not breadboard friendly, diagrams from top and pins from bottom)
* "printf.h" that redirects stdout to Serial, and how to make it work with non arduino boards ([See here](/printf2serial.md))
* [Fritzing](https://fritzing.org/download/) for wiring diagrams. I gave my 8 €, it's worth it.

## What must be improved
* It emits continuously. It should sleep, wake up when button pressed and only transmit changes.
* There is no proper variable structure containing the type of device and its status or action.
* The addressing is built-in which prevents configuration on installation.
* It is mainly point-to-point. It should send the message centrally, and we need a gateway and an automation controller.
* It has a limited range (about 15m) and may need repeaters or a mesh protocol (or an antenna mod).
* It is not secure (any value emitted for the target address will do).
* There is no dedicated power supply (two computers with USB ports)
* It lacks a proper enclosure (but it's just a test)
