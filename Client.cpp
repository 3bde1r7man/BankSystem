#include "BankSystem.h"

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