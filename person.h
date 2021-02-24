#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

enum Honorific {
	Mr,
	Mrs,
	Ms,
	Dr
};
enum Sex { male, 
			female
			};


class person
{
private:

	string dataGName;
	string dataSName;
	Sex dataSex;
	Honorific dataHonorific;
	char dataInit;
	string dataAddress;
	string dataCity;
	string dataState;
	int dataZipcode;
	int dataNumber;
	string dataEmail;
	string dataBirthday;
	

public:

	//Constructors
	person();

	//Getters
	int getNumber();
	string getGName();
	string getSName();
	Sex getSex();
	Honorific getHonorific();
	char getInit();
	string getAddress();
	string getCity();
	string getState();
	int getZipcode();
	string getEmail();
	string getBirthday();

	//Setters
		
	bool setAddress(string n);
	bool setCity(string n);
	bool setState(string n);
	bool setZipcode(int n);
	bool setEmail(string n);
	bool setBirthDay(string n);
	bool setSName(string n);
	bool setPerson(string sName, string address, string city, string state, int zipcode, string email, string birthday, int cNumber, Sex Sex, Honorific Honorific, string gName, char init);
	bool setNumber(int n);
	bool setGName(string n);
	bool setSex(Sex n);
	bool setHonorific(Honorific n);
	bool setInit(char n);
	

};

