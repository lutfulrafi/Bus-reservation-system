#include "Bus.h"

vector<Bus*> Bus::buses;

Bus::Bus(int lisc_no, Station* from, Station* to)
	:isEmpty(false),lisc_no(lisc_no), from(from), to(to){}
Bus::Bus() 
	:isEmpty(true), lisc_no(NULL), from(nullptr), to(nullptr){}

void Bus::print(){
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	cout << "liscense no: " << lisc_no << endl;
	cout << "From Station: "<<endl; from->print();
	cout << "To Station: "<<endl; to->print();
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
}

bool Bus::empty(){
	return isEmpty;
}

Bus* Bus::find(Station* from, Station* to){
	for(auto& i : Bus::buses){
		if(i->from == from && i->to == to){
			return i;
		}
	}
	throw "no bus found";
	return nullptr;
}

void Bus::add(){
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	int lisc;
	string fs;
	string ts;
	Station* fss = nullptr;
	Station* tss = nullptr;
	cout << "liscense no: "; cin >> lisc;
	cout << "From Station: "; cin >> fs;
	try{
		fss = Station::find(fs);
	} catch(const string& e){
		cout << e << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		return;
	}
	cout << "To Station: "; cin >> ts;
	
	try{
		tss = Station::find(ts);
	} catch(const string& e){
		cout << e << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		return;
	}
	Bus::buses.push_back(new Bus(lisc, fss, tss));
	cout << "success" << endl;
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
}

void Bus::display(){
	if(Bus::buses.empty()){
		cout << "database empty!!!" << endl;
		return;
	}
	for(auto& i : Bus::buses){
		i->print();
	}
}

void Bus::write(){
	ofstream fout(".data/bus.dat", ios::trunc | ios::binary);
	if(!fout){
		throw "Bus database write error!!!";
	}
	for(auto& i : Bus::buses){
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cout << "writing" << endl;
		i->print();
		fout.write((char*) i, sizeof(Bus));
		cout << "success" << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	}
	if(Bus::buses.empty()){
		throw "database is empty!!!";
	}
	fout.close();
}

void Bus::read(){
	if(!Bus::buses.empty()){
		for(auto& i : Bus::buses)delete(i);
		Bus::buses.clear();
	}
	ifstream fin(".data/bus.dat", ios::binary);
	if(!fin){
		throw "Bus database read error!!!";
	}
	while(!fin.eof()){
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cout << "reading" << endl;
		Bus* temp = new Bus;
		fin.read((char*) temp, sizeof(Bus));
		if(temp->empty()){
			delete(temp);
			if(Bus::buses.empty())throw "database empty!!!";
			else continue;
		}
		Bus::buses.push_back(temp);
		cout << "success" << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	}
	if(Bus::buses.empty()){
		throw "database is empty!!!";
	}
	fin.close();
}