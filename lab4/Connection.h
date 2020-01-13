#pragma once
#include <string>
#include <ostream>
using namespace std;

class Connection
{
        private:
	string _name;
	bool sink;
	double voltage;

public:
	Connection(string name);
	Connection(string name, bool thisIsSink);
	~Connection();

	//Utskrift
	friend ostream& operator<<(ostream& os, Connection& c);

	void simulate(double lapse);
	bool is_sink() const;
	string get_name() const;
	double get_voltage() const;
	void set_voltage(double v)const;
	void add_voltage(double v) ;
};
