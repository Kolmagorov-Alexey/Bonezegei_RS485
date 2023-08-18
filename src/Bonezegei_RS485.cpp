/*
  This Library is written for RS 485 module (RS485 to UART)
  Author: Bonezegei (Jofel Batutay)
  Date: August 2023 

  8 bit word 1 Stop bit
*/

#include "Bonezegei_RS485.h"

Bonezegei_RS485::Bonezegei_RS485() {
  ser = 0;
}

Bonezegei_RS485::Bonezegei_RS485(HardwareSerial &serial, int dir) {
  ser = 0;
  hardserial = (HardwareSerial *)&serial;
  _dir = dir;
  pinMode(_dir, OUTPUT);
  digitalWrite(_dir, LOW);
}

Bonezegei_RS485::Bonezegei_RS485(Bonezegei_SoftSerial &serial, int dir) {
  ser = 1;
  softserial = (Bonezegei_SoftSerial *)&serial;
  _dir = dir;
  pinMode(_dir, OUTPUT);
  digitalWrite(_dir, LOW);
}

void Bonezegei_RS485::begin(int baud) {
  if (ser) {
    softserial->begin(baud);
  } else {
    hardserial->begin(baud);
  }
}

void Bonezegei_RS485::write(char ch) {
  digitalWrite(_dir, HIGH);
  if (ser) {
    softserial->write(ch);
  } else {
    hardserial->write(ch);
  }
  digitalWrite(_dir, LOW);
}

void Bonezegei_RS485::print(const char *ch) {
  digitalWrite(_dir, HIGH);
  if (ser) {
    softserial->print(ch);
  } else {
    hardserial->print(ch);
  }
  digitalWrite(_dir, LOW);
}

void Bonezegei_RS485::println(const char *ch) {
  digitalWrite(_dir, HIGH);
  if (ser) {
    softserial->println(ch);
  } else {
    hardserial->println(ch);
  }
  digitalWrite(_dir, LOW);
}

char Bonezegei_RS485::available() {
  digitalWrite(_dir, LOW);
  if (ser) {
    return softserial->available();
  } else {
    return hardserial->available();
  }
}

int Bonezegei_RS485::read() {
  digitalWrite(_dir, LOW);
  if (ser) {
    return softserial->read();
  } else {
    return hardserial->read();
  }
}
