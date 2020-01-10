#pragma once
#include "Component.h"
class Resistor :
public Component
{

public:
    Resistor(string name, double Mark_Charac, Connection *t1, Connection *t2);
    ~Resistor();
    void simulate(double lapse);
private:
    double resistance;

};
