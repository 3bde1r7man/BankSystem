#include "BankSystem.h"

//_______________________________BankApp___________________________________
void BankApp::menu(BankApp& b)
{
	
	int choice;
	

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
			b.addClient();
			break;
		}
		case 2:
		{
			b.List();
			break;
		}
		case 3:
		{
			b.withdraw();
			break;
		}
		case 4:
		{
			b.deposit();
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
			ba->setAccType(accType);
			break;
		}
		else if (accType == 2) {
			ba->setAccType(accType);
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
			if (balance < s.getMiniBalance())
			{
				cout << "this is less than the starting balance!!\n";
			}
			else
			{
				ba->setBalance(balance);
			}
		}
	}
	string temp = "FCAI-" + to_string(bankAcc.size() + 1);
	ba->setAccID(temp);
	bankAcc.push_back(ba);
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
	dataFile.close();
	bankAcc.resize(count/6);
	int i = 0;
	dataFile.open("data.txt", ios::in);
	while (!dataFile.eof() && dataFile.peek() != EOF) {
		bankAcc[i] = new BankAcc;
		getline(dataFile, temp);
		bankAcc[i]->setAccID(temp);
		getline(dataFile, temp);
		bankAcc[i]->setAccType(stoi(temp));
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

BankApp::~BankApp()
{
	fstream dataFile;
	string temp;
	dataFile.open("data.txt", ios::out);
	for (int i = 0; i < bankAcc.size(); i++)
	{
		dataFile << bankAcc[i]->getAccID() << '\n';
		dataFile << bankAcc[i]->getAccType() << '\n';
		dataFile << bankAcc[i]->getBalance() << '\n';
		dataFile << bankAcc[i]->getClient().getName() << '\n';
		dataFile << bankAcc[i]->getClient().getAddress() << '\n';
		dataFile << bankAcc[i]->getClient().getPhone() << '\n';
	}
	dataFile.close();
	
	
}

