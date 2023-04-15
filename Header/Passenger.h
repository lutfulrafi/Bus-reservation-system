#pragma once
#include <vector>
#include <iostream>
#include "Station.h"
#include "Bus.h"
#include "Person.h"
#include "Ticket.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////
//																		//
// A Passenger buys a ticket from a station to another station by bus	//
//																		//
//////////////////////////////////////////////////////////////////////////

class Passenger:Person{
public:
	Passenger(Person*, Bus*, Station*, Station*);
	~Passenger();
	Passenger();

	void issueTicket(Bus*, Station*, Station*);
	void print();


	static vector<Passenger*> list;
	static void add();
	static void write();
	static void read();
	static void display();

private:

	vector<Ticket*> tickets;
	bool isEmpty;
	Bus* bus;
	Station* from;
	Station* to;
};
