#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

class BankApp
{
protected:


public:
	BankApp();
	~BankApp();
};

class BankAcc
{

protected:

public:
	BankAcc();
	~BankAcc();



};

class SavingBankAcc :public BankAcc
{
protected:


public:
	SavingBankAcc ();
	~SavingBankAcc ();

};

class Client
{
protected:

public:
	Client();
	~Client();


};

