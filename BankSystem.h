#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <fstream>

using namespace std;


class BankApp
{
private:
	vector<BankAcc> bankAcc;
	vector<Client> client;
public:
	void menu();
	void addClient();
	void List();
	void withdraw();
	void deposit();
	BankApp();
	virtual ~BankApp() {

	}
};

class BankAcc
{

protected:
	string accID;
	double balance;
	bool accType;

public:
	BankAcc() {

	}
	virtual ~BankAcc() {

	}
	void setAccID(string id);
	void setBalance(double bal);
	void setAccType(bool type);
	string getAccID();
	double getBalance();
	bool getAccType();
	int withdraw(double amount);
	int deposit(double amount);
	bool isFoundAccID(string id);
	
	


};

class SavingBankAcc :public BankAcc
{
private:
	double minimumBalance, minimumWithdraw;
public:
	SavingBankAcc() {
		minimumBalance = 1000.0;
		minimumWithdraw = 100.0;
	}
	virtual ~SavingBankAcc() {

	}

};

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
	bool isValidPhoneNumber(string p);
};

