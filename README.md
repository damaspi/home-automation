# home-automation
Experimentation with IOT for Home Automation

## Objectives
My house is quite old (1911) and electricity was an afterthought: everything is apparent.  I was impressed in an hotel by a remote switch (I later found out that it was an Ikea switch) and thought that I have everything at hand to do the same thing (maybe with additional purchases) and improve the situation : turn off lights in rooms we are no more present, welcome me by turning the lights on, and then maybe build on that for the heating, having temperature sensors in strategic rooms, for dimming lights in my office and to centrally control and manage the whole.

## Constraints
I want all that to be open source and not depending on specific vendors, to be based on "standards" (de jure or de facto) or at least be interoperable with standards, I want it to be affordable (fair prices) and low energy (minimize battery consumption).

## Protocols
I'll probably check simple RF, WiFi, BLE, Zigbee, LoRa and see what I can do.

Let's get started... 

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





