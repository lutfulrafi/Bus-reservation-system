#include "Ticket.h"

Ticket::Ticket(Bus* bus, Station* from, Station* to)
	:bus(bus), from(from), to(to){
	fare = Station::get_fare(from, to);
}

int Ticket::getFare(){
	return fare;
}
