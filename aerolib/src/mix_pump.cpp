#include "../include/mix_pump.hpp"

void MixPump::setup(int pin)
{
	this->pin = pin;
	pinMode(pin, OUTPUT);
}

void MixPump::on()
{
 	digitalWrite(pin, HIGH);
}

void MixPump::off()
{
 	digitalWrite(pin, LOW);
}

void MixPump::on_for(int time)
{
	on();
	delay(time);
}