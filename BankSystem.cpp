#include "BankSystem.h"

//_______________________________BankApp___________________________________
void BankApp::menu()
{
	BankApp bank;
	int choice;
	while (true)
	{
		cout << "Welcome to FCAI Banking Application\n";
		cout << "1. Create a New Account\n";
		cout << "2. List Clients and Accounts\n";
		cout << "3. Withdraw Money\n";
		cout << "4. Deposit Money\n";
		cout << "Please Enter Choice =========> ";
		cin >> choice;
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
		bank.addClient();
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
	string name, address, phone, accID;
	int accType;
	double balance;
	Client c;
	BankAcc* ba = new BankAcc(c);
	SavingBankAcc s(c);
	cout << "Please Enter Client Name =========> ";
	cin.ignore();
	getline(cin, name);
	c.setName(name);
	cout << "Please Enter Client Address =======> ";
	cin.ignore();
	getline(cin, address);
	c.setAddress(address);
	while (true)
	{
		cout << "Please Enter Client Phone =======> ";
		cin >> phone;
		if (c.isValidPhoneNumber(phone)) {
			c.setPhone(phone);
			break;
		}
		else
		{
			cout << "invalid Phone number!!\n";
		}
	}
	while (true)
	{
		cout << "What Type of Account Do You Like? (1) Basic (2) Saving � Type 1 or 2 =========> ";
		cin >> accType;
		if (accType == 1) {
			break;
			ba->setAccType(1);
		}
		else if (accType == 2) {
			break;
			ba->setAccType(2);
		}
		else
		{
			cout << "invalid Account type!!\n";
		}
	}
	if (accType == 1) {
		cout << "Please Enter the Starting Balance =========> ";
		cin >> balance;
	}
	else
	{
		while (true)
		{
			cout << "Please Enter the Starting Balance =========> ";
			cin >> balance;
			if (balance < s.getMiniBalace())
			{
				cout << "this is less than the starting balance!!\n";
			}
			else
			{
				ba->setBalance(balance);
			}
		}
	}
	ba->setAccID("FCAI-" + to_string(bankAcc.size() + 1));
	bankAcc.push_back(ba);
	bankAcc.size();
	cout << "An account was created with ID " << ba->getAccID() << " and Starting Balance " << balance << " L.E. ";
}

void BankApp::List()
{
	for (int i = 0; i < bankAcc.size(); i++) {
		cout << setfill('-') << std::setw(35) << bankAcc.at(i)->get_client()->getName() << setfill('-') << std::setw(35) << ' ' << endl;
		cout << "Address: " << bankAcc.at(i)->get_client()->getAddress() << endl;
		cout << "Account ID: " << bankAcc.at(i)->getAccID() << endl;
		cout << "Balance: " << bankAcc.at(i)->getBalance() << endl;
		cout << setfill('-') << std::setw(70) << ' ' << endl;
	}
}

void BankApp::withdraw()
{
	string accid;
	double amount;
	cout << "Please Enter Account ID (e.g., FCAI-015) =========> ";
	cin >> accid;
	for (int i = 0; i < bankAcc.size(); i++) {
		if (accid == bankAcc.at(i)->getAccID()) {
			cout << "Account ID: " << accid << endl;
			if (bankAcc.at(i)->getAccType() == 1) {
				cout << "Account Type: " << "Basic" << endl;
				cout << "Balance: " << bankAcc.at(i)->getBalance();
				cout << "Please Enter The Amount to Withdraw =========> ";
				cin >> amount;
				bankAcc.at(i)->withdraw(amount);
			}
			else if (bankAcc.at(i)->getAccType() == 2) {
				cout << "Account Type: " << "Saving" << endl;
				cout << "Balance: " << bankAcc.at(i)->getBalance();
				cout << "Please Enter The Amount to Withdraw =========> ";
				cin >> amount;
				bankAcc.at(i)->withdraw(amount);
			}
		}
	}
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
	Client c;
	while (!dataFile.eof() && dataFile.peek() != EOF) {

		getline(dataFile, temp);
		bankAcc[i]->setAccID(temp);
		getline(dataFile, temp);
		bankAcc[i]->setAccType(bool(stoi(temp)));
		getline(dataFile, temp);
		bankAcc[i]->setBalance(stod(temp));
		getline(dataFile, temp);
		bankAcc[i]->get_client()->setName(temp);
		getline(dataFile, temp);
		bankAcc[i]->get_client()->setAddress(temp);
		getline(dataFile, temp);
		bankAcc[i]->get_client()->setPhone(temp);
		i++;
	}
	dataFile.close();
}

//___________________________________BankAcc________________________________
BankAcc::BankAcc(Client& client)
{
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

void BankAcc::setAccType(int type)
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

int BankAcc::getAccType()
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
//--------------------------SavingBankAcc----------------------------
int SavingBankAcc::withdraw(double amount)
{
	return 0;
}

int SavingBankAcc::deposit(double amout)
{
	return 0;
}
