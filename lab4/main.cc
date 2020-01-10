//includa våra klasser
//ta emot fyra parametrar, för att sen köra vår simulering och skriva ut den i
//terminalen
// Lab4-CircuitSimulator.cpp : This file contains the 'main' function. Program execution begins and ends

#include <iostream>
#include <iomanip>
#include <vector>
#include "Connection.h"
#include "Component.h"
#include "Battery.h"
#include "Resistor.h"
#include "Capacitor.h"
#include <string>
using namespace std;
// TODO Complementary work needed: net should be a reference since it is not necessary to copy the vector
void simulate(vector <Component*> net, int iterations, int lines, double lapse)
{
    int print_every = iterations / lines;
    int actual = 0;
    
    for (vector <Component *>::iterator c = net.begin(); c != net.end(); ++c)
    {
	cout.width(12);
	cout << (*c)->get_name();
    }
    cout << endl;

    for (vector <Component *>::iterator c = net.begin(); c != net.end(); ++c)
    {
	cout.width(6);
	cout << "Volt";
	cout.width(6);
	cout << "Curr";
    }
    cout << endl;


    for (int i = 0; i < iterations; i++)
    {
	for (vector <Component *>::iterator c = net.begin(); c != net.end(); ++c)
	{
	    (*c)->simulate(lapse);
	}
	if (((i + 1) % print_every) == 0)
	{
	    actual++;
	    for (vector <Component *>::iterator c = net.begin(); c != net.end(); ++c)
	    {
		cout.width(6);
		cout << setprecision(2)<< fixed << (*c)->get_voltage();
		cout.width(6);
		cout << ((*c)->get_current());
	    }
	    cout << endl;
	}
    }

    if (actual < lines)
    {
	for (vector <Component *>::iterator c = net.begin(); c != net.end(); ++c)
	{
	    cout.width(6);
	    cout << (*c)->get_voltage();
	    cout.width(6);
	    cout << (*c)->get_current();
	}
    }
}

void deallocate_components(vector <Component*> net)
{
    for (vector <Component *>::iterator c = net.begin(); c != net.end(); ++c)
    {
	delete (*c);
    }
    net.clear();
}

int main(int argc, char* argv[])
{

    double Marc_Charac{};
    int iterations{};
    int lines{};
    double steps{};

    if (argc >= 2)
    {
	try
	{
	    iterations = stoi(argv[1]);
	}
	catch(std::invalid_argument& e)
	{
	    cout<< "That was not a valid iteration number!" << endl;
	    cout << "Write it again: " << flush;
	    cin >> iterations;
	}

	try
	{
	    lines = stoi(argv[2]);
	}
	catch(std::invalid_argument& e)
	{
	    cout<< "That was not a valid line number!" << endl;
	    cout << "Write it again: " << flush;
	    cin >> lines;
	}
	try
	{
	     steps =  atof(argv[3]);
	}
	catch(std::invalid_argument& e)
	{
	    cout<< "That was not a valid step number!" << endl;
	    cout << "Write it again: " << flush;
	    cin >> steps;
	}
	try
	{
	    Marc_Charac = stoi(argv[4]);
	}
	catch(std::invalid_argument& e)
	{
	    cout<< "That was not a valid Voltage number!" << endl;
	    cout << "Write it again: " << flush;
	    cin >> Marc_Charac;
	}


    }

    //Test 1
    Connection p{ "p" };
    Connection n{ "n", true};
    // vector<Component*> net;
    // net.push_back(new Battery{ "Batt", Marc_Charac, &p, &n });
    // net.push_back(new Resistor{ "R1", 6.0, &p, &n });
    // net.push_back(new Resistor{ "R2", 8.0, &p, &n });
    // simulate(net, 10000, 10, 0.1);
    // deallocate_components(net);


    Connection r23{"R23"};
    Connection r124{"R124"};
    vector<Component*> pet;
    pet.push_back(new Battery{ "Batt", Marc_Charac, &p, &n });
    pet.push_back(new Resistor{ "R1", 6.0, &p, &r124 });
    pet.push_back(new Resistor{ "R2", 4.0, &r124 , &r23 });
    pet.push_back(new Resistor{ "R3", 8.0, &r23, &n });
    pet.push_back(new Resistor{ "R4", 12.0, &r124, &n });
    simulate(pet, iterations, lines, steps);
    deallocate_components(pet);

    Connection l{ "L" };
    Connection r{ "R"};
    vector<Component*> bet;
    bet.push_back(new Battery{ "Batt", Marc_Charac, &p, &n });
    bet.push_back(new Resistor{ "R1", 150.0, &p, &l });
    bet.push_back(new Resistor{ "R2", 50.0, &p, &r });
    bet.push_back(new Resistor{ "R3", 100.0, &r, &l });
    bet.push_back(new Resistor{ "R4", 300.0, &l, &n });
    bet.push_back(new Resistor{ "R5", 250.0, &r, &n });

    simulate(bet, iterations, lines, steps);
    deallocate_components(bet);


    vector<Component*> fet;
    fet.push_back(new Battery{ "Batt", 24.0, &p, &n });
    fet.push_back(new Resistor{ "R1", 150.0, &p, &l });
    fet.push_back(new Resistor{ "R2", 50.0, &p, &r });
    fet.push_back(new Capacitor{ "C3", 1.0, &r, &l });
    fet.push_back(new Resistor{ "R4", 300.0, &l, &n });
    fet.push_back(new Capacitor{ "C5", 0.75, &r, &n });

    simulate(fet, iterations, lines, steps);
    deallocate_components(fet);
}
