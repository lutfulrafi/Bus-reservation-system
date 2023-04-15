#pragma once
#include "Person.h"
#include "Bus.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
//																	//
//	A Driver is a person driving a bus with his driving license		//
//																	//
//////////////////////////////////////////////////////////////////////

class Driver:Person{
public:
	Driver(Person*,Bus*,int);
	Driver() = default;

private:
	int driving_lisc_no;
	Bus* driving;
};
