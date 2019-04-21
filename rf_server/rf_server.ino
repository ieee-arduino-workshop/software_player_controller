/*
* Arduino Wireless Communication Tutorial
*       Example 1 - Receiver Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE 5
#define CSN 10


RF24 radio(CE, CSN); // CE, CSN
const byte address[6] = "00001";
void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  if (radio.available()) {
    uint16_t text;
    // radio.read(&text, sizeof(text));    
    radio.read(&text, sizeof(text));    
    Serial.println(text,BIN);
  }
}