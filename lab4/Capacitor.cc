#include "Capacitor.h"
#include <iostream>
using namespace std;


Capacitor::Capacitor(string name, double Mark_Charac, Connection *t1, Connection *t2)
    : Component(name, Mark_Charac, t1, t2)
{
    stored_voltage = 0.0;
    capacitance = Mark_Charac;
    set_voltage(0.0);
    set_current(0.0);
}


Capacitor::~Capacitor()
{
}


void Capacitor::simulate(double lapse)
{

//när objektet skapas har den 0 volt sparad.

//den ska alltså räkna ut hur mkt volt som strömmar genom komponenten
    double voltage_over_component = abs(get_terminal(1)->get_voltage()) - abs(get_terminal(2)-> get_voltage());

    double to_move = (capacitance * (voltage_over_component - stored_voltage) * lapse);

//vad som är storeat under hela tiden som simultationen har gått
    stored_voltage += to_move;


    	if (get_terminal(1)->get_voltage() >= get_terminal(2)->get_voltage())
	{
	    get_terminal(1)->add_voltage(-1 * abs(to_move));
	    get_terminal(2)->add_voltage(abs(to_move));
	}
	else
	{
	    get_terminal(1)->add_voltage(abs(to_move));
	    get_terminal(2)->add_voltage(-1 * abs(to_move));
	}
	set_voltage(get_terminal(1)->get_voltage() - get_terminal(2)-> get_voltage());
	set_current((get_terminal(1)->get_voltage() - get_terminal(2)->get_voltage() - get_voltage()) * capacitance);
	//Uppdatera kopplingspunkterna
	get_terminal(1)->simulate(lapse);
	get_terminal(2)->simulate(lapse);

}
