/*
  This Library is written for RS 485 module (RS485 to UART)
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023 

  8 bit word 1 Stop bit
*/

#ifndef _BONEZEGEI_RS485_H_
#define _BONEZEGEI_RS485_H_
#include <Arduino.h>
#include <Bonezegei_SoftSerial.h>

class Bonezegei_RS485 {
public:

  Bonezegei_RS485();
  Bonezegei_RS485(HardwareSerial &serial, int dir);
  Bonezegei_RS485(Bonezegei_SoftSerial &serial, int dir);

  void begin(int baud);

  void write(char ch);
  void print(const char *ch);
  void println(const char *ch);

  char available();
  int read();

  int _rx;
  int _tx;
  int _dir;

  int _baud;
  unsigned char ser; //serial selected 0 for hardware serial and 1 for softserial
  Bonezegei_SoftSerial *softserial;
  HardwareSerial *hardserial;
};


#endif
