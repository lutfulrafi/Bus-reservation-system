#pragma once
#include <iostream>
#include <vector>
#include "Station.h"

using namespace std;

//////////////////////////////////
///								//
/// A bus having a license no.	//
/// drives from one station to	//
/// another on a regular basis	//
///								//
//////////////////////////////////

class Bus{
public:
	Bus(int lisc_no, Station* from, Station* to);
	Bus();
	void print();
	bool empty();

	static vector<Bus*> buses;
	static Bus* find(Station*,Station*);
	static void add();
	static void display();
	static void write();
	static void read();

private:
	int lisc_no;
	Station* from;
	Station* to;
	bool isEmpty;
};
