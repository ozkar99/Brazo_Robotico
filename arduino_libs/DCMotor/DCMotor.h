/*
  DCMotor.h - Librry for using DC Motors
  Created by Oscar Moreno Garza, April 16, 2013
  Released into the public domain.
*/
#ifndef DCMotor_h
#define DCMotor_h

#include "Arduino.h"

class DCMotor
{
  public:
    DCMotor(int _c, int _n);
    void regular();
    void inverse();
    void stop();
  private:
    int _pin_n;
    int _pin_c;
};

#endif
