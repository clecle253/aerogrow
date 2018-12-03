#ifndef PULVERISATEUR_HPP
#define PULVERISATEUR_HPP

#include <Arduino.h>
class Pulverisateur
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

#endif /*PULVERISATEUR_HPP*/