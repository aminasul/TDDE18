#pragma once
#include "Component.h"
class Capacitor :
	public Component
{
private:
	double capacitance;
	double stored_voltage;
public:
	Capacitor(string name, double Mark_Charac, Connection *t1, Connection *t2);
	~Capacitor();
	void simulate(double lapse);
};
