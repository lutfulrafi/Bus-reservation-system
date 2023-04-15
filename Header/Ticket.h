#pragma once
#include "Bus.h"
#include "Station.h"

using namespace std;

//////////////////////////////
//							//
// A bus ticket from		//
// one station to another	//
//							//
//////////////////////////////

class Ticket{
public:
	Ticket(Bus* bus, Station* from, Station* to);
	Ticket() = default;

	int getFare();

private:
	Bus* bus;
	Station* from;
	Station* to;
	int fare;
};
