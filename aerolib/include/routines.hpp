#ifndef ROUTINES_HPP
#define ROUTINES_HPP
#include "aerogrowlib.hpp"

void pulvroutine(Pulverisateur pulv);
bool Refuelroutine(LevelSensor lvl, ElectroVanne vane, FlowSensor flow, Pump pump, int refuelstate);
void mixpumproutine(MixPump pump, int duration);

#endif /*ROUTINES_HPP*/