#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "Person.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////
//																		//
//	An Account is as it says, a account for transaction of bus fare		//
//	Account holder uses the account to add or withdraw money to or		//
//	from his account and pays his fare									//
//																		//
//////////////////////////////////////////////////////////////////////////

class Person;

class Account{
public:
	Account(Person* account_holder, int accno);
	Account();
	
	void withdraw(int b);
	void add_money(int b);
	void set_min_bal(int b);
	void print();
	bool empty();
	
	static vector<Account*> accounts;
	static void add();
	static void display();
	static void write();
	static void read();

private:
	Person* account_holder;
	int account_no;
	int balance;
	int min_bal;
	bool isEmpty;
};



