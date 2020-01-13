#include "Component.h"
#include <string>

Component::Component(string name, double Mark_Charac, Connection *t1, Connection *t2)
{
    _name = name;
    _Mark_Charac = Mark_Charac;
    _t1 = t1;
    _t2 = t2;
}

Component:: ~Component()
{
}

void Component::simulate(double lapse)
{
    //kommer bli overridad av barnen
}

string Component::get_name const()
{
    return _name;
}

Connection* Component:: get_terminal(int i)
{
    return (i == 1) ? _t1 : (i == 2) ? _t2: nullptr;
}

double Component::get_voltage const()
{
    return voltage;
}

void Component::set_voltage(double v)
{
    voltage = v;
}
double Component::get_current const()
{
    return current;
}
void Component:: set_current(double c)
{
    current = c;
}
