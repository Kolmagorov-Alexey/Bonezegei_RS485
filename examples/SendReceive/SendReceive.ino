/*
  Sample for Read and Write data on RS485 Module 
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023 

  8 bit word 1 Stop bit
*/

#include <Bonezegei_RS485.h>
#include <Bonezegei_SoftSerial.h>

#define PIN_DIR 4

//Change the Serial port to be use
Bonezegei_RS485 rs485(Serial2, PIN_DIR);

void setup() {
  Serial.begin(9600);

  rs485.begin(9600);

  //write strring to RS485 module
  rs485.println("Hello RS485");
}

void loop() {


  if (rs485.available()) {    //check if RS 485 data is available
    char ch = rs485.read();   //read data
    Serial.write(ch);
  }

  if (Serial.available()) {
    char ch = Serial.read();
    rs485.write(ch);          //write data
  }
}
