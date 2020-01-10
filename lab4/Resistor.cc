#include "Resistor.h"


Resistor::Resistor(string name, double Mark_Charac, Connection *t1, Connection *t2)
	: Component(name, Mark_Charac, t1, t2)
{
	resistance = Mark_Charac;
	set_voltage(0.0);
	set_current(0.0);
}


Resistor::~Resistor()
{
}

void Resistor::simulate(double lapse)
{
   
    double charge_to_move = abs(get_terminal(1)->get_voltage() - get_terminal(2)->get_voltage()) / resistance * lapse;

  
    set_voltage(get_terminal(1)->get_voltage() - get_terminal(2)->get_voltage());
    set_current((get_terminal(1)->get_voltage() - get_terminal(2)->get_voltage()) / resistance);

    if (get_terminal(1)->get_voltage() >= get_terminal(2)->get_voltage())
    {
	get_terminal(1)->add_voltage(-1 * charge_to_move);
	get_terminal(2)->add_voltage(charge_to_move);
    }
    else
    {
	get_terminal(1)->add_voltage(-1 * charge_to_move);
	get_terminal(2)->add_voltage(charge_to_move);
    }

    get_terminal(1)->simulate(lapse);
    get_terminal(2)->simulate(lapse);
}
