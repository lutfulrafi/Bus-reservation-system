#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Account.h"

using namespace std;

//////////////////////////////////
//								//		
//	A person with no privacy	//
//								//
//////////////////////////////////

class Account;

class Person{
public:
	Person(int id, string name, int age, string address);
	Person();

	virtual void print();
	void setacc(Account*);
	bool empty();
	
	static vector<Person*> people;
	static Person* find(const int&);
	static void add();
	static void display();
	static void write();
	static void read();

protected:
	int id;
	string name;
	int age;
	string address;
	Account* acc;
	bool isEmpty;
};
