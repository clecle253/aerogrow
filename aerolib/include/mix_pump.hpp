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
bool GetStatus();
void on_off();


private:
int pin;
bool status;

};

#endif  /*MIX_PUMP_HPP*/