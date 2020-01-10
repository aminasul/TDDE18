#pragma once
#include "Component.h"
class Battery :
public Component
{
public:
    Battery(string name, double Mark_Charac, Connection *t1, Connection *t2);
    ~Battery();
    void simulate(double lapse);
private:
    double voltage;


};
