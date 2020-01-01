# [Test2 : STM32F103 LED on RF](/STM32RF24ButtonLED)

## Description

Replace simply one of teh Arduinos of previous test with an STM32F103C8 (aka BluePill), cheap and powerfull (around 1.6 € on AliExpress).
Two nodes talking to each other on Radio Frequency (2.4Ghz): both having a button and a led. When the button on one is pressed, the LED on the other should turn on.

## Inspiration

After some research on the nRF24L01, I followed this project: https://create.arduino.cc/projecthub/muhammad-aqib/nrf24l01-interfacing-with-arduino-wireless-communication-0c13d4

## Hardware

* 2 stm32F103 (or here, I keepo one arduino and replace only one node with an STM32)
* 2 nRF24L01 + 47µF capacitor (capacitor may not be needed, depending on the power supply used to power the radio. I've seen different values in different articles (10µF, 47µF)...)
* 2 LED + 220 Ω resistor
* 2 switches + 10 KΩ resistor

## Connections

![STM32F103 pinout diagram](/media/stm32f103-pinout-diagram.png)
[Pinout of STM32F103](http://reblag.dk/wordpress/wp-content/uploads/2016/07/The-Generic-STM32F103-Pinout-Diagram.pdf) by  Rasmus Friis Kjeldsen is licensed under [Creative Commons Attribution-Share Alike 4.0 International](https://creativecommons.org/licenses/by-sa/4.0/deed.en)

I used the standard SPI pins PA4, PA5, PA6, PA7 (SS, SCK, MISO, MOSI) + CE on PB0. The order of pins is different than for arduino !
The LED is connected on pin 3.
The button is connected on pin 2.

![Project diagram](/media/ArduinoRF24ButtonLED.png)

## Software

I used the Arduino IDE and added the RF24 library to the project.

![Arduino library manager: RF24 library](/media/ArduinoRF24ButtonLED-ArduinoIDE-RF24library.png)

I had to also add the board to the File->Preferences dialog: http://dan.drown.org/stm32duino/package_STM32duino_index.json
![Arduino File Preferences: board](/media/STM32RF24ButtonLED-ArduinoIDE-PreferencesBoard.png)

I had to select the board and the ST-Link v2 as the upload method.
When I connect an additional cable to the USB port, it appears in the COM ports as a Maple mini.



## What I learned

## What must be improved
