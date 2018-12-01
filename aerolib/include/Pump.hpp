#ifndef PUMP_HPP
#define PUMP_HPP

#include "Arduino.h"

class Pump
{
public:
void setup(int pin);
void on();
void off();
void on_for(int time);

private:
int pin;

};

#endif /*PUMP_HPP*/