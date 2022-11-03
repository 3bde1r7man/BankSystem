#include "BankSystem.h"

//_______________________________BankApp___________________________________
void BankApp::menu()
{
	int choice;
	while (true)
	{
		cin >> choice;
		cout << "Welcome to FCAI Banking Application\n";
		cout << "1. Create a New Account\n";
		cout << "2. List Clients and Accounts\n";
		cout << "3. Withdraw Money\n";
		cout << "4. Deposit Money\n";
		if (choice >= 1 && choice <= 4) {
			break;
		}
		else
		{
			cout << "invalid Choice!!\n";
		}
	}
	switch (choice)
	{
	case 1:
	{

	}
	case 2:
	{

	}
	case 3:
	{

	}
	case 4:
	{

	}
	default:
		break;
	}
	
}

void BankApp::addClient()
{

}

void BankApp::List()
{
	for(int i=0;i<bankAcc.size();i++){
		
	}
}

void BankApp::withdraw()
{

}

void BankApp::deposit()
{

}

BankApp::BankApp()
{
	
	fstream dataFile;
	string temp = "";
	dataFile.open("data.txt", ios::in);
	int count{ 0 };
	while (!dataFile.eof())
	{
		if (getline(dataFile, temp)) { // Count lines
			count++;
		}
	}
	bankAcc.resize(count / 6);
	temp = "";
	int i = 0;
	while (!dataFile.eof() && dataFile.peek() != EOF) {
		getline(dataFile, temp);
		bankAcc[i].setAccID(temp);
		getline(dataFile, temp);
		bankAcc[i].setAccType(bool(stoi(temp)));
		getline(dataFile, temp);
		bankAcc[i].setBalance(stod(temp));
		getline(dataFile, temp);
		bankAcc[i].get_client()->setName(temp);
		getline(dataFile, temp);
		bankAcc[i].get_client()->setAddress(temp);
		getline(dataFile, temp);
		bankAcc[i].get_client()->setPhone(temp);
		i++;
	}
	dataFile.close();
}
//___________________________________BankAcc________________________________
BankAcc::BankAcc(Client& client){
	this->client = &client;
}
//-------------------------SETTER
void BankAcc::setAccID(string id)
{	
	accID = id;
}

void BankAcc::setBalance(double bal)
{
	balance = bal;
}

void BankAcc::setAccType(bool type)
{
	accType = type;
}
//-----------------------GETTER
string BankAcc::getAccID()
{
	return accID;
}

double BankAcc::getBalance()
{
	return balance;
}

bool BankAcc::getAccType()
{
	return accType;
}

Client* BankAcc::get_client()
{
	return client;
}
//----------------------func
int BankAcc::withdraw(double amount) 
{
	return 0;
}

int BankAcc::deposit(double amount)
{
	return 0;
}

bool BankAcc::isFoundAccID(string id)
{
	return false;
}

//_____________________________client________________________________
//-------------------------SETTER
void Client::setName(string n)
{
	name = n;
}

void Client::setAddress(string a)
{
	address = a;
}

void Client::setPhone(string p)
{
	phone = p;
}
//-----------------------GETTER
string Client::getName()
{
	return string();
}

string Client::getAddress()
{
	return string();
}

string Client::getPhone()
{
	return string();
}
//-----------------------func
bool Client::isValidPhoneNumber(string p)
{
	if (regex_match(p, regex(("^(010|011|012|015)[0-9]{8}$"))))
		return true;
	else
		return false;
}