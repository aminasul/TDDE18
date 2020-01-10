#include "Battery.h"
#include <iostream>


Battery::Battery(string name, double Mark_Charac, Connection *t1, Connection *t2) 
	: Component(name, Mark_Charac, t1, t2)
{
	voltage = Mark_Charac;
	set_voltage(Mark_Charac);
	set_current(0.0);
}


Battery::~Battery()
{
}

void Battery::simulate(double lapse) 
{
     
	if (get_terminal(1)->is_sink())
	{
		if (get_terminal(2)->is_sink())
		{
		       
			cout << "Batteriet kortslutet!" << endl;
		}
		else
		{	
			get_terminal(2)->set_voltage(-1 * voltage);
		}
	}
	else
	{
	    if (get_terminal(2)->is_sink())
		{
			get_terminal(1)->set_voltage(voltage);
		}
		else
		{
 
			get_terminal(1)->set_voltage(get_terminal(2)->get_voltage() + voltage);
		}
	}

	get_terminal(1)->simulate(lapse);
	get_terminal(2)->simulate(lapse);
}
