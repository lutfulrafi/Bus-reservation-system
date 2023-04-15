#include "Person.h"

vector<Person*> Person::people;

Person::Person(int id, string name, int age, string address)
	:isEmpty(false)
	, id(id)
	, name(name)
	, age(age)
	, address(address)
	, acc(nullptr){}

Person::Person()
	:isEmpty(true)
	,id(NULL)
	,name("")
	,age(NULL)
	,address("")
	,acc(nullptr){}

Person* Person::find(const int& checkid){
	for(auto& i : Person::people){
		if(i->id == checkid)return i;
	}
	throw "person with id: " + to_string(checkid) + " not found in person database!!!\nconsider registering in people database";
}

void Person::add(){
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	string name;
	int id;
	int age;
	string address;
	cout << "Name: "; cin >> name;
	cout << "ID: "; cin >> id;
	cout << "Age: "; cin >> age;
	cout << "Address: "; cin >> address;
	Person::people.push_back(new Person(id, name, age, address));
	cout << "success" << endl;
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
}

void Person::display(){
	if(Person::people.empty()){
		cout << "database empty!!!" << endl;
		return;
	}
	for(auto& i : Person::people){
		i->print();
	}
}

void Person::write(){
	ofstream fout(".data/ppl.dat", ios::trunc | ios::binary);
	if(!fout){
		throw "People database write error!!!";
	}
	for(auto& i : Person::people){
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cout << "writing" << endl;
		fout.write((char*) i, sizeof(Person));
		i->print();
		cout << "success" << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	}
	if(Person::people.empty()){
		throw "database is empty!!!";
	}
	fout.close();
}

void Person::read(){
	if(!Person::people.empty()){
		for(auto& i : Person::people)
			delete(i);
		Person::people.clear();
	}
	ifstream fin(".data/ppl.dat", ios::binary);
	if(!fin){
		throw "People database read error!!!";
	}
	while(!fin.eof()){
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cout << "reading" << endl;
		Person* temp = new Person;
		fin.read((char*) temp, sizeof(Person));
		if(temp->empty()){
			delete(temp);
			if(Person::people.empty())throw "database empty!!!";
			else continue;
		}
		Person::people.push_back(temp);
		temp->print();
		cout << "success" << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	}
	if(Person::people.empty()){
		throw "database is empty!!!";
	}
	fin.close();
}

void Person::print(){
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Address: " << address << endl;
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
}

void Person::setacc(Account* account){
	acc = account;
}

bool Person::empty(){
	return isEmpty;
}
