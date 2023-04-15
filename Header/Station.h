#pragma once
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//////////////////////////
//						//
// A Staion somewhere	//
//						//
//////////////////////////

class Station{
public:
	Station(string name);
	Station();

	void print();
	bool empty();

	static int get_fare(Station* from, Station* to);
	static int count;
	static vector<Station*> stations;
	static Station* find(string name);
	static void add();
	static void display();
	static void write();
	static void read();

private:
	string name;
	int dist;
	bool isEmpty;
};
