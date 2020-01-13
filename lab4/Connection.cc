#include "Connection.h"
#include <string>
#include <ostream>
using namespace std;


Connection::Connection(string name)
{
	_name = name;
	sink = false;
	voltage = 0.0;
}

Connection::Connection(string name, bool thisIsSink)
{
	_name = name;
	sink = thisIsSink;
	voltage = 0.0;
}


Connection::~Connection()
{
}

ostream& operator<<(ostream& os, Connection& c)
{
	os.precision(1);
	os << "Kopplingspunkt: '" << c.get_name() << "'. Volt:  " << std::fixed << c.get_voltage() << "  " << endl;
	return os;
}


void Connection::simulate(double lapse)
{
	if (sink)
	{
		voltage = 0.0;
	}
}

bool Connection::is_sink() const
{
	return sink;
}

string Connection::get_name() const
{
	return _name;
}

void Connection::set_voltage(double v) const
{
	//Sätter spänning till fast värde (görs av batteri)
	voltage = v;
}

void Connection::add_voltage(double v)
{
	//Adderar spänning (görs av komponent)
	voltage += v;
}

double Connection::get_voltage() const
{
	return voltage;
}
