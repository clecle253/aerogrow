#include "../include/aerogrowlib.hpp"


void pulvroutine(Pulverisateur pulv)
{
    static unsigned long time = millis();

    if (millis() < time)
    {
    // securité anti overflow de 50 jours + resset a on au cas ou
      time = millis();
      pulv.on();
    }
    if ((millis() - time) > 30000)
    {
      time = millis();
      pulv.on_off();
    }
}

bool Refuelroutine(LevelSensor lvl, ElectroVanne vane, FlowSensor flow, Pump pump, int refuelstate)
{
    bool refueld = false;

    while (lvl.getLevel(100) < refuelstate)
    {
        vane.on_on();
        flow.start();
        pump.on();
        refueld = true;
    }
    flow.Stop();
    vane.off();
    pump.off();
    //serial.print("water flow value: ");
    //serial.println(flow.GetTotalFlow());
    return refueld;
}

void mixpumproutine(MixPump pump, int duration)
{
    static unsigned long time = millis();

    if (millis() < time)
    {
      time = millis();
      pump.on();
    }
    if ((millis() - time) > duration)
    {
      time = millis();
      pump.on_off();
    }
}