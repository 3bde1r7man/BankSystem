#include "BankSystem.h"

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
