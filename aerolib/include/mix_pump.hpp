#ifndef MIX_PUMP_HPP
#define MIX_PUMP_HPP

#include <Arduino.h>
class MixPump
{
public:
void setup(int pin);
void on();
void off();
void on_for(int time);

private:
int pin;

};

#endif  /*MIX_PUMP_HPP*/