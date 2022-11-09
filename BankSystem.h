#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <fstream>
#include <iomanip>

using namespace std;

class Client
{
private:
	string name, address, phone;

public:
	Client() {

	}
	virtual ~Client() {

	}
	void setName(string n);
	void setAddress(string a);
	void setPhone(string p);
	string getName();
	string getAddress();
	string getPhone();
	bool isValidPhoneNumber(string& p);
};


class BankAcc
{

protected:
	string accID;
	Client client;
	double balance;
	int accType;

public:
	BankAcc() = default;
	BankAcc(Client& client);
	virtual ~BankAcc() {

	}
	void setAccID(string id);
	void setBalance(double bal);
	void setAccType(int type);
	string getAccID();
	double getBalance();
	int getAccType();
	Client& getClient();
	virtual int withdraw(double amount);
	virtual int deposit(double amount);
};



class SavingBankAcc : public BankAcc
{
private:
	double minimumBalance, minimumWithdraw;
public:
	SavingBankAcc(Client& client) : BankAcc(client) {
		minimumBalance = 1000.0;
		minimumWithdraw = 100.0;
	}
	int withdraw(double amount);
	int deposit(double amount);
	virtual ~SavingBankAcc() {

	}
	int getMiniBalance() {
		return minimumBalance;
	}
	int getMIniWithdraw() {
		return minimumWithdraw;
	}
};


class BankApp
{
private:
	vector<BankAcc*> bankAcc;
public:
	void menu(BankApp&);
	void addClient();
	void List();
	void withdraw();
	void deposit();
	BankApp();
	virtual ~BankApp();
};
