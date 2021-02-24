#include "person.h"

//Constructors

person::person()
{

}


//Setters

bool person::setPerson( string sName, string address, string city, string state, int zipcode, string email, string birthday, int cNumber, Sex Sex, Honorific Honorific, string gName, char init)
{
	if (person::setNumber(cNumber));
	if (person::setSex(Sex));
	if (person::setHonorific(Honorific));
	if (person::setGName(gName));
	if (person::setInit(init));
	if (person::setSName(sName));
	if (person::setAddress(address));
	if (person::setCity(city));
	if (person::setState(state));
	if (person::setZipcode(zipcode));
	if (person::setEmail(email));
	if (person::setBirthDay(birthday));

	return true;
}
bool person::setNumber(int n)
{
	dataNumber = n;
	return true;
}

bool person::setGName(string n)
{
	dataGName = n;
	return true;
}
bool person::setSName(string n)
{
	dataSName = n;
	return true;
}
bool person::setSex(Sex n)
{
	dataSex = n;
	return true;
}
bool person::setHonorific(Honorific n)
{
	dataHonorific = n;
	return true;
}
bool person::setInit(char n)
{
	dataInit = n;
	return true;
}
bool person::setAddress(string n)
{
	dataAddress = n;
	return true;
}
bool person::setCity(string n)
{
	dataCity = n;
	return true;
}
bool person::setState(string n)
{
	dataState = n;
	return true;
}
bool person::setZipcode(int n)
{
	dataZipcode = n;
	return true;
}
bool person::setEmail(string n)
{
	dataEmail = n;
	return true;
}
bool person::setBirthDay(string n)
{
	dataBirthday = n;
	return true;
}


//Getters
int person::getNumber()
{
	return dataNumber;
}
string person::getGName()
{
	return dataGName;
}
string person::getSName()
{
	return dataSName;
}
Sex person::getSex()
{
	return dataSex;
}
Honorific person::getHonorific()
{
	return dataHonorific;
}
char person::getInit()
{
	return dataInit;
}
string person::getAddress()
{
	return dataAddress;
}
string person::getCity()
{
	return dataCity;
}
string person::getState()
{
	return dataState;
}
int person::getZipcode()
{
	return dataZipcode;
}
string person::getEmail()
{
	return dataEmail;
}
string person::getBirthday()
{
	return dataBirthday;
}