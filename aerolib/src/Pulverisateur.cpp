#include "../include/Pulverisateur.hpp"

void Pulverisateur::setup(int pin)
{
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

void Pulverisateur::on()
{
 	digitalWrite(pin, HIGH);
}

void Pulverisateur::off()
{
 	digitalWrite(pin, LOW);
}

void Pulverisateur::on_for(int time)
{
	on();
	delay(time);
    off();
}