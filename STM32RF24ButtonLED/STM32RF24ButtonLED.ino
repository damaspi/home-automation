
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//RF24 radio(9, 10); // CE, CSN
RF24 radio(PB0, PA4); // CE, CSN

const byte addresses [][6] = {"00001", "00002"};  //Setting the two addresses. One for transmitting and one for receiving
int button_pin = 2;
int led_pin = 3;

boolean button_state_local = 0;
boolean button_state_remote = 0;

#define NODE2

void setup() {
  Serial.begin(115200);

  pinMode(button_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  radio.begin();                           //Starting the radio communication
#ifdef NODE1 
  Serial.println("Starting Node 1 ");
  radio.openWritingPipe(addresses[1]);     //Setting the address at which we will send the data
  radio.openReadingPipe(1, addresses[0]);  //Setting the address at which we will receive the data
#endif
#ifdef NODE2 
  Serial.println("Starting Node 2 ");
  radio.openWritingPipe(addresses[0]);     //Setting the address at which we will send the data
  radio.openReadingPipe(1, addresses[1]);  //Setting the address at which we will receive the data
#endif
  radio.setPALevel(RF24_PA_MAX); //You can set it as minimum or maximum depending on the distance between the transmitter and receiver. 
  Serial.println("before ");
  radio.printDetails();
  Serial.println("after ");

}


void loop() {  
  delay(5);
  radio.stopListening();                             //This sets the module as transmitter
  button_state_local = digitalRead(button_pin);
 // button_state_local = ! button_state_local;  // auto toggle value to check radio range
  radio.write(&button_state_local, sizeof(button_state_local));  //Sending the data
  Serial.print("Send local button ");
  Serial.println(button_state_local);
  delay(5);
  
  radio.startListening();                            //This sets the module as receiver
  if(radio.available()) {                         //Looking for incoming data
    Serial.print("Read ");
    radio.read(&button_state_remote, sizeof(button_state_remote)); //Reading the data
    if (button_state_remote == HIGH) {
      digitalWrite(led_pin, HIGH);
    } else {
      digitalWrite(led_pin, LOW);
    }
    Serial.print("Read remote button ");
    Serial.println(button_state_remote);
  }
  
  }
