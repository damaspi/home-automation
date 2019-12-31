# home-automation
Experimentation with IOT for Home Automation

## Objectives
My house is quite old (1911) and electricity was an afterthought: everything is apparent.  I was impressed in an hotel by a remote switch (I later found out that it was an Ikea switch) and thought that I have everything at hand to do the same thing (maybe with additional purchases) and improve the situation : turn off lights in rooms we are no more present, welcome me by turning the lights on, and then maybe build on that for the heating, having temperature sensors in strategic rooms, for dimming lights in my office and to centrally control and manage the whole.

## Constraints
I want all that to be open source and not depending on specific vendors, to be based on "standards" (de jure or de facto) or at least be interoperable with standards, I want it to be affordable (fair prices) and low energy (minimize battery consumption).

## Protocols
I'll probably check simple RF, WiFi, BLE, Zigbee, LoRa and see what I can do.

Let's get started... 

# [Simple test : Arduino LED on RF](/ArduinoRF24ButtonLED)

## What I learned
* Serial Peripheral Interfaces ([SPI](https://en.wikipedia.org/wiki/Serial_Peripheral_Interface)).
* Patience from connecting the nRF24L01 to the arduino (not breadboard friendly, diagrams from top and pins from bottom)
* "printf.h" that implements printf and redirects stdout to Serial, and how to make it work with non arduino boards ([See here](/printf2serial.md))

## What is wrong with this test
* It emits continuously. It should sleep, wake up when button pressed and only transmit changes.
* There is no proper variable structure containing the type of device and its status or action.
* The addressing is built-in which prevents configuration on installation.
* It is mainly point-to-point. It should send the message centrally, and we need a gateway and an automation controller.
* It has a limited range (about 15m) and may need repeaters or a mesh protocol (or an antenna mod).
* It is not secure (any value emitted for the target address will do).
* There is no dedicated power supply (two computers with USB ports)








