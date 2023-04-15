#include "Driver.h"

Driver::Driver(Person* ref,Bus* bus,int lisc)
	:Driver::Person(*ref)
	,driving(bus)
	,driving_lisc_no(lisc){}
