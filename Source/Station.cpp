#include "Station.h"

int Station::count = 0;
vector<Station*> Station::stations;

Station::Station(string name)
	:isEmpty(false),name(name){
	dist = Station::count++;
}

Station::Station()
	:isEmpty(true),name(""),dist(NULL){}

void Station::print(){
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	cout << "Name: " << name << endl;
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
}

bool Station::empty(){
	return isEmpty;
}

int Station::get_fare(Station* from, Station* to){
	return abs(from->dist - to->dist) * 120;
}

Station* Station::find(string name){
	for(auto& i : Station::stations){
		if(name == i->name)return i;
	}
	throw "no station named " + name;
}

void Station::add(){
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	string name;
	cout << "Station Name: "; cin >> name;
	Station::stations.push_back(new Station(name));
	cout << "success" << endl;
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
}

void Station::display(){
	if(Station::stations.empty()){
		cout << "database empty!!!" << endl;
		return;
	}
	for(auto& i : Station::stations){
		i->print();
	}
}

void Station::write(){
	ofstream fout(".data/station.dat", ios::trunc | ios::binary);
	if(!fout){
		throw "Station database write error!!!";
	}
	for(auto& i : Station::stations){
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cout<< "Writing: " << endl;
		i->print();
		fout.write((char*)i, sizeof(Station));
		cout << "success" << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	}
	if(Station::stations.empty()){
		throw "database is empty!!!";
	}
	fout.close();
}

void Station::read(){
	if(!Station::stations.empty()){
		for(auto& i : Station::stations)delete(i);
		Station::stations.clear();
	}
	ifstream fin(".data/station.dat", ios::binary);
	if(!fin){
		throw "Station database read error!!!";
	}
	Station::count = 0;
	while(!fin.eof()){
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cout << "Reading" << endl;
		Station* temp = new Station;
		fin.read((char*)temp, sizeof(Station));
		if(temp->empty()){
			delete(temp);
			if(Station::stations.empty())throw "database empty!!!";
			else continue;
		}
		Station::stations.push_back(temp);
		temp->print();
		Station::count++;
		cout << "success" << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	}
	if(Station::stations.empty()){
		throw "database is empty!!!";
	}
	fin.close();
}