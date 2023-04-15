#include "Passenger.h"

vector<Passenger*> Passenger::list;

Passenger::Passenger(Person* ref, Bus* bus, Station* from, Station* to)
	:isEmpty(false)
	,Passenger::Person(*ref)
	,bus(bus)
	,from(from)
	,to(to){
	tickets.push_back(new Ticket(bus, from, to));
}

Passenger::Passenger()
	:isEmpty(true)
	,bus(nullptr)
	,from(nullptr)
	,to(nullptr){
	tickets.clear();
}

Passenger::~Passenger(){
	for(auto& i : tickets){
		delete(i);
	}
	tickets.clear();
}

void Passenger::issueTicket(Bus* bus, Station* from, Station* to){
	string a;
	string b;
	Station* f = nullptr;
	Station* t = nullptr;
	cout << "from station: "; cin >> a;
	try{
		f = Station::find(a);
	} catch(const string& e){
		cout << e << endl;
		return;
	}
	cout << "to station: "; cin >> b;
	try{
		t = Station::find(b);
	} catch(const string& e){
		cout << e << endl;
		return;
	}
	Bus* bu = nullptr;
	try{
		bus = Bus::find(from, to);
	} catch(const char* e){
		cout << e << endl;
		cout << "from" << endl;
		from->print();
		cout << to << endl;
		to->print();
		return;
	}
	tickets.push_back(new Ticket(bu, f, t));
	try{
		acc->withdraw(tickets.back()->getFare());

	} catch(const char* e){
		cout << e << endl;
	}
}

void Passenger::print(){
	Person::print();
	cout << "Bus: " << endl;
	bus->print();

}

void Passenger::add(){
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	int id;
	cout << "ID: "; cin >> id;
	Person* him;
	try{
		him = Person::find(id);
	} catch(const char* e){
		cout << e << endl;
		return;
	}
	string a;
	string b;
	Station* from;
	Station* to;
	cout << "from station: "; cin >> a;
	try{
		from=Station::find(a);
	} catch(const string& e){
		cout << e << endl;
		return;
	}
	cout << "to station: "; cin >> b;
	try{
		to = Station::find(b);
	} catch(const string& e){
		cout << e << endl;
		return;
	}
	Bus* bus;
	try{
		bus = Bus::find(from, to);
	} catch(const char* e){
		cout << e << endl;
		cout << "from" << endl;
		from->print();
		cout << "to" << endl;
		to->print();
		return;
	}
	Passenger::list.push_back(new Passenger(him, bus, from, to));
	try{
		Passenger::list.back()->acc->withdraw(Passenger::list.back()->tickets.back()->getFare());
	} catch(const char* e){
		cout << e << endl;
	}
	cout << "success" << endl;
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
}

void Passenger::write(){
	ofstream fout(".data/passengers.dat", ios::trunc | ios::binary);
	if(!fout){
		throw "Passenger database write error!!!";
	}
	for(auto& i : Passenger::list){
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cout << "writing" << endl;
		fout.write((char*)i, sizeof(Passenger));
		i->print();
		cout << "success" << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	}
	if(Passenger::list.empty()){
		throw "database is empty!!!";
	}
	fout.close();
}

void Passenger::read(){
	if(!Passenger::list.empty()){
		for(auto& i : Passenger::list)
			delete(i);
		Passenger::list.clear();
	}
	ifstream fin(".data/passengers.dat", ios::binary);
	if(!fin){
		throw "Passenger database read error!!!";
	}
	while(!fin.eof()){
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cout << "reading" << endl;
		Passenger* temp = new Passenger;
		fin.read((char*)temp, sizeof(Passenger));
		if(temp->empty()){
			delete(temp);
			if(Passenger::list.empty())throw "database empty!!!";
			else continue;
		}
		Passenger::list.push_back(temp);
		temp->print();
		cout << "success" << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	}
	if(Passenger::list.empty()){
		throw "database is empty!!!";
	}
	fin.close();
}

void Passenger::display(){
	if(Person::people.empty()){
		cout << "database empty!!!" << endl;
		return;
	}
	for(auto& i : Person::people){
		i->print();
	}
}
