#include "../include/mix_pump.hpp"

void MixPump::setup(int pin)
{
	this->pin = pin;
	this->status = false;
	pinMode(pin, OUTPUT);
}

void MixPump::on()
{
	this->status = true;
 	digitalWrite(pin, HIGH);
}

void MixPump::off()
{
	this->status = false;
 	digitalWrite(pin, LOW);
}

void MixPump::on_for(int time)
{
	on();
	delay(time);
	off();
}

bool MixPump::GetStatus()
{return this->status;}

void MixPump::on_off()
{
	if (this->status == true)
		off();
	else
		on();
}
