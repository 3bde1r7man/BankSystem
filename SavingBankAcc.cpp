#include "BankSystem.h"


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
	else if (amount > 0 && amount < minimumBalance)
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
