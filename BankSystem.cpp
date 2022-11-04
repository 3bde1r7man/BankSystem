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
			switch (choice)
			{
			case 1:
			{
				bank.addClient();
				break;
			}
			case 2:
			{
				bank.List();
				break;
			}
			case 3:
			{
				bank.withdraw();
				break;
			}
			case 4:
			{
				bank.deposit();
				break;
			}
			default:
				break;
			}
		}
		else
		{
			cout << "invalid Choice!!\n";
		}
	}
	

}

void BankApp::addClient()
{
	string name, address, phone;
	int accType;
	double balance;
	Client c;
	auto* ba = new BankAcc(c);
	SavingBankAcc s(c);
	cout << "Please Enter Client Name =========> ";
	if (cin)
		cin.ignore();
	getline(cin, name);
	ba->getClient().setName(name);
	cout << "Please Enter Client Address =======> ";
	getline(cin, address);
	ba->getClient().setAddress(address);
	while (true)
	{
		cout << "Please Enter Client Phone =======> ";
		cin >> phone;
		if (ba->getClient().isValidPhoneNumber(phone)) {
			ba->getClient().setPhone(phone);
			break;
		}
		else
		{
			cout << "invalid Phone number!!\n";
		}
	}
	while (true)
	{
		cout << "What Type of Account Do You Like? (1) Basic (2) Saving Type 1 or 2 =========> ";
		cin >> accType;
		if (accType == 1) {
			ba->setAccType(1);
			break;
		}
		else if (accType == 2) {
			ba->setAccType(2);
			break;
		}
		else
		{
			cout << "invalid Account type!!\n";
		}
	}
	if (accType == 1) {
		cout << "Please Enter the Starting Balance =========> ";
		cin >> balance;
		ba->setBalance(balance);
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
	for (auto& i: bankAcc) {
		cout << setfill('-') << std::setw(35) <<i->getClient().getName() << setfill('-') << std::setw(35) << ' ' << '\n';
		cout << "Address: " << i->getClient().getAddress() << '\n';
		cout << "Account ID: " << i->getAccID() << '\n';
		cout << "Balance: " << i->getBalance() << '\n';
		cout << setfill('-') << std::setw(70) << ' ' << '\n';
	}
}

void BankApp::withdraw()
{
	string accid;
	double amount;
	cout << "Please Enter Account ID (e.g., FCAI-015) =========> ";
	cin >> accid;
	for (auto& i: bankAcc) {
		if (accid == i->getAccID()) {
			cout << "Account ID: " << accid << '\n';
			if (i->getAccType() == 1) {
				cout << "Account Type: " << "Basic" << '\n';
				cout << "Balance: " << i->getBalance() << '\n';
				while (true)
				{
					cout << "Please Enter The Amount to Withdraw =========> ";
					cin >> amount;
					if (i->withdraw(amount)) {
						break;
					}	
				}
				
			}
			else if (i->getAccType() == 2) {
				cout << "Account Type: " << "Saving" << '\n';
				cout << "Balance: " << i->getBalance() << '\n';
				while (true)
				{
					cout << "Please Enter The Amount to Withdraw =========> ";
					cin >> amount;
					if (((SavingBankAcc*)(i))->withdraw(amount)) {
						break;
					}
				}
				
			}
			cout << "Account ID: " << accid << '\n';
			cout << "New Balance : " << i->getBalance() << '\n';
		}
	}
}

void BankApp::deposit()
{
	string accid;
	double amount;
	cout << "Please Enter Account ID (e.g., FCAI-015) =========> ";
	cin >> accid;
	for (auto& i: bankAcc) {
		if (accid == i->getAccID()) {
			cout << "Account ID: " << accid << '\n';
			if (i->getAccType() == 1) {
				cout << "Account Type: " << "Basic" << '\n';
				cout << "Balance: " << i->getBalance() << '\n';
				while (true)
				{
					cout << "Please Enter The Amount to Deposit =========> ";
					cin >> amount;
					if (i->deposit(amount)) {
						break;
					}	
				}
				
			}
			else if (i->getAccType() == 2) {
				cout << "Account Type: " << "Saving" << '\n';
				cout << "Balance: " << i->getBalance() << '\n';
				while (true)
				{
					cout << "Please Enter The Amount to Deposit =========> ";
					cin >> amount;
					if (((SavingBankAcc*)(i))->deposit(amount)) {
						break;
					}
				}
				
			}
			cout << "Account ID: " << accid << '\n';
			cout << "New Balance : " << i->getBalance() << '\n';
				
		}
	}
}

BankApp::BankApp()
{

	fstream dataFile;
	string temp;
	dataFile.open("data.txt", ios::in);
	int count{ 0 };
	while (!dataFile.eof() && dataFile.peek() != EOF)
	{
		if (getline(dataFile, temp)) { // Count lines
			count++;
		}
	}
	bankAcc.resize(count / 6);

	int i = 0;
	
	while (!dataFile.eof() && dataFile.peek() != EOF) {

		getline(dataFile, temp);
		bankAcc[i]->setAccID(temp);
		getline(dataFile, temp);
		bankAcc[i]->setAccType(bool(stoi(temp)));
		getline(dataFile, temp);
		bankAcc[i]->setBalance(stod(temp));
		getline(dataFile, temp);
		bankAcc[i]->getClient().setName(temp);
		getline(dataFile, temp);
		bankAcc[i]->getClient().setAddress(temp);
		getline(dataFile, temp);
		bankAcc[i]->getClient().setPhone(temp);
		i++;
	}
	dataFile.close();
}

//___________________________________BankAcc________________________________
BankAcc::BankAcc(Client& client)
{
	this->client = client;	
}
//-------------------------SETTER
void BankAcc::setAccID(string id)
{
	accID = move(id);
}

void BankAcc::setBalance(double bal)
{
	balance = move(bal);
}

void BankAcc::setAccType(int type)
{
	accType = move(type);
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

Client& BankAcc::getClient()
{
	return client;
}
//----------------------func
int BankAcc::withdraw(double amount)
{
	if (amount > balance) {
		cout << "Sorry. This is more than what you can withdraw.\n";
		return 0;
	}
	else
	{
		balance -= amount;
		return 1;
	}
}

int BankAcc::deposit(double amount)
{
	if (amount > 0) {
		balance += amount;
		return 1;
	}
	else
	{
		cout << "Sorry, you can't deposit a negative value.\n";
		return 0;
	}
	
}

bool BankAcc::isFoundAccID(const string& id)
{
	return false;
}

//_____________________________client________________________________
//-------------------------SETTER
void Client::setName(string n)
{
	name = move(n);
}

void Client::setAddress(string a)
{
	address = move(a);
}

void Client::setPhone(string p)
{
	phone = move(p);
}
//-----------------------GETTER
string Client::getName()
{
	return name;
}

string Client::getAddress()
{
	return address;
}

string Client::getPhone()
{
	return phone;
}
//-----------------------func
bool Client::isValidPhoneNumber(string& p)
{
	if (regex_match(p, regex(("^(010|011|012|015)[0-9]{8}$"))))
		return true;
	else
		return false;
}
//--------------------------SavingBankAcc----------------------------
int SavingBankAcc::withdraw(double amount)
{
	if (amount > balance) {
		cout << "Sorry. This is more than what you can withdraw.\n";
		return 0;
	}
	else
	{
		balance -= amount;
		return 1;
	}
}

int SavingBankAcc::deposit(double amount)
{
	if (amount > minimumBalance) {
		balance += amount;
		return 1;
	}
	else if(amount > 0 && amount < minimumBalance)
	{
		cout << "Sorry, this is less than the minimum deposit value ($100).\n";
		return	0;
	}
	else
	{
		cout << "Sorry, you can't deposit a negative value.\n";
		return 0;
	}
}
