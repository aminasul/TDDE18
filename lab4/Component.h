//this is one of many header files............
#pragma once
#include <string>
#include "Connection.h"
// TODO Complementary work needed: base class destructor should be virtual, otherwise slicing may occur
// functions that do not change the object should be const (this applies to all header files)
class Component
{

public:
    Component(string name, double Mark_Charac, Connection *t1, Connection *t2);
    virtual ~Component();
    virtual void simulate(double lapse);
    friend ostream& operator <<(ostream& os, Component& c);

    string get_name() const;
    Connection* get_terminal(int i);
    double get_voltage const();
    void set_voltage(double v);
    double get_current const();
    void set_current(double c);

private:
    bool source;
    Connection *_t1, *_t2;
    double _Mark_Charac;
    string _name;
    double voltage, current;

};
