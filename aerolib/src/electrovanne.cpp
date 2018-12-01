#include "../include/electrovanne.hpp"

void ElectroVanne::setup(int pin)
{
    this->pin = pin;
    pinMode(6,OUTPUT);
}

void ElectroVanne::on()
{
 	digitalWrite(pin, HIGH);
}

void ElectroVanne::off()
{
 	digitalWrite(pin, LOW);
}

void ElectroVanne::on_for(int time)
{
	on();
	delay(time);
    off();
}