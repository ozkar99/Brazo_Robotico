/*
  DCMotor.cpp - Library for using DC Motors
  Created by Oscar Moreno Garza, April 16, 2013.
  Released into the public domain.
*/

#include "Arduino.h"
#include "DCMotor.h"

DCMotor::DCMotor(int _c, int _n)
{
  pinMode(_c, OUTPUT);
  _pin_c = _c;

  pinMode(_n, OUTPUT);
  _pin_n = _n;

}


void DCMotor::stop()
{
  digitalWrite(_pin_c, LOW);
  digitalWrite(_pin_n, LOW);

}


void DCMotor::regular()
{
  digitalWrite(_pin_c, HIGH);
  digitalWrite(_pin_n, LOW);

}

void DCMotor::inverse()
{
  digitalWrite(_pin_c, LOW);
  digitalWrite(_pin_n, HIGH);

}