#include "Account.h"

vector<Account*> Account::accounts;

Account::Account(Person* account_holder, int accno)
	:isEmpty(false)
	,account_holder(account_holder)
	,min_bal(150)
	,account_no(accno){
	srand(time(nullptr));
	balance = 1000 + rand() % 500;
	account_holder->setacc(this);
}

Account::Account()
	:isEmpty(true)
	,account_holder(nullptr)
	,account_no(NULL)
	,balance(NULL)
	,min_bal(NULL){}

void Account::withdraw(int b){
	if(b + min_bal >= balance){
		throw("Not enough balance");
	}
	
	balance -= b;
	cout << "Ticket Confirmed" << endl;
	
}

void Account::add_money(int b){
	if(b < 0)return;
	balance += b;
}

void Account::set_min_bal(int b){
	min_bal = b;
}

void Account::print(){
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	cout << "Account no.: " << account_no << endl;
	cout << "Balance: " << balance << endl;
	cout << "Minimum balance: " << min_bal << endl;
	cout << "Account holder: " << endl;
	account_holder->print();
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
}

bool Account::empty(){
	return isEmpty;
}

void Account::add(){
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	int id;
	int accno;
	cout << "ID: "; cin >> id;
	cout << "Account No.: "; cin >> accno;
	Person* temp = nullptr;
	try{
		temp=Person::find(id);
	} catch(const string& e){
		cout << e << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		return;
	}
	Account::accounts.push_back(new Account(temp, accno));
	cout << "success" << endl;
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
}

void Account::display(){
	if(Account::accounts.empty()){
		cout << "database empty!!!" << endl;
		return;
	}
	for(auto& i : Account::accounts){
		i->print();
	}
}

void Account::write(){
	ofstream fout(".data/acc.dat", ios::trunc | ios::binary);
	if(!fout){
		throw "Account database write error!!!";
	}
	for(auto& i : Account::accounts){
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cout << "writing" << endl;
		i->print();
		fout.write((char*) i, sizeof(Account));
		cout << "success" << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	}
	if(Account::accounts.empty()){
		throw "database is empty!!!";
	}
	fout.close();
}

void Account::read(){
	if(!Account::accounts.empty()){
		for(auto& i : Account::accounts)delete(i);
		Account::accounts.clear();
	}
	ifstream fin(".data/acc.dat", ios::binary);
	if(!fin){
		throw "Acount database read error!!!";
	}
	while(!fin.eof()){
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cout << "reading" << endl;
		Account* temp = new Account;
		fin.read((char*) temp, sizeof(Account));
		if(temp->empty()){
			delete(temp);
			if(Account::accounts.empty())throw "database empty!!!";
			else continue;
		}
		temp->print();
		Account::accounts.push_back(temp);
		cout << "success" << endl;
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	}
	fin.close();
}
