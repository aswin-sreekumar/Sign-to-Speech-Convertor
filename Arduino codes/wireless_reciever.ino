// Basic two point reciever code
// nrf24L01+ interfaced to Arduino

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";
char text[32] = "";

void setup() 
{
  Serial.begin(115200);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() 
{
  if (radio.available()) 
  {
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}
