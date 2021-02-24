// Gurnaman_Singh_HW6.cpp 
// Date: 4/7/2020

#include "person.h"
#include <fstream>
#include <chrono>
#include <thread>
#include <sstream>
#include <map>
#include <set>
#include <functional>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <string>
#include <string>
#include <vector>

using namespace std;


string fileInput = "";
string fileOutput = "";


string  address, email, birthday, state, city, row, record, givenName, surName;
Sex gender;
Honorific title;


int extractNamesData(string dataFound);
int displayIntroduction();
int executionCompleted();
int outputNames(string strOutFile);
int uniCount(vector < string > stringCountUnique);
int cityCount(vector < string > stringCountUnique);
person currentIndividual;

vector < string > stringPerson;
vector < string > popularNames;
vector < string > popularCities;
vector < person > nameList;
vector < string > columnCity;
vector < string > columngivenName;

char middleName;
int zipcode;
int uniqueCount;
int cNumber;


int executionCompleted() {
	displayIntroduction();

	cout << "\n\t    DATA SUCCESSFULLY EXRACTED FROM FakeNames.csv  \n";
	cout << "\n\t                File load completed \n";
	cout << "\n\t       Please Find summary.txt In Project's Folder\n";

	return 0;
}
void progressLoadBar(std::ostream& os, int time,    //This is a loading bar that displays on screen to let user know the time left till execution.

	std::string message, char symbol = '*')			//Credit to Dev Toby Speight from Stack Overflow for this Logic. Brian Latham also helped me but we couldn't figure out last part of this project...

{													//Just a cool feature to look at while this project loads. 
										
	static											//Project Takes around 30 seconds to load. 
		const auto bar_length = 70;					//Read/Write from csv takes a lot of time.

	// not including the percentage figure and spaces


	if (message.length() >= bar_length) {

		os << message << '\n';

		message.clear();

	}
	else {

		message += " ";

	}


	const auto progress_level = 100.0 / (bar_length - message.length());


	std::cout << message;


	for (double percentage = 0; percentage <= 100; percentage += progress_level) {

		message += symbol;

		os << "\r [" << std::setw(3) << static_cast <int> (percentage) << "%] "

			<<
			message << std::flush;

		std::this_thread::sleep_for(std::chrono::milliseconds(time));

	}

	os << "\n\n";

}

void ClearScreen()							//// ERASES HISTORY ON THE ENTIRE SCREEN

{

	int n;

	for (n = 0; n < 10; n++)

		printf("\n\n\n\n\n\n\n\n\n\n");

}

int displayIntroduction() {
	ClearScreen();						// CALLS THE FUNCTION THAT ERASES HISTORY ON THE ENTIRE SCREEN
	cout << "\n\t		    Program: Census Time Homework 6\n";

	return 0;
}

int extractNamesData(string dataFound) {
	cout << "\n\t                   Extracting Data From FakeNames.csv\n";
	cout << "\n\t		    Wait 30 Seconds:FakeNames.csv \n";
	progressLoadBar(std::clog, 100, "progress", '#');			//Shows the progress till execution has loaded.


	int columnumnNumber = 0;
	int mainCount = 0;
	int copyCNumber = 0;
	nameList.clear();

	ifstream fin;									//Read data from FakeNames.csv
	fin.open(dataFound);

	while (fin.good()) {

		getline(fin, row);
		stringstream s(row);


		while (s.good()) {
			getline(s, record, ',');				// Looks out for punctuation. 
													// Uses punctuation as a delimeter.
			stringstream t(record);					//Read and writing from csv takes a lot of time.

			for (int i = 0, len = record.size(); i < len; i++) {
				if (ispunct(record[i])) 
				{
					record.erase(i--, 1);
					len = record.size();
				}
			}
			switch (columnumnNumber) {

				case 0:
					if (isdigit(record[0])) {
						cNumber = stoi(record);
						columnumnNumber++;
					}

					break;
				case 1:
					if (record == "male") {
						gender = male;
					}
					else if (record == "female") {
						gender = female;
					}

					columnumnNumber++;
					break;
				case 2:
					if (record == "Mr.") {
						title = Mr;
					}
					else if (record == "Ms.") {
						title = Ms;
					}
					else if (record == "Dr.") {
						title = Dr;
					}
					else if (record == "Mrs.") {
						title = Mrs;
					}
					columnumnNumber++;
					break;
				case 3:
					givenName = record;
					columnumnNumber++;
					break;
				case 4:
					middleName = record[0];
					columnumnNumber++;
					break;
				case 5:
					surName = record;
					columnumnNumber++;
					break;
				case 6:
					address = record;
					columnumnNumber++;
					break;
				case 7:
					city = record;
					columnumnNumber++;
					break;
				case 8:
					state = record;
					columnumnNumber++;
					break;
				case 9:
					zipcode = stoi(record);
					columnumnNumber++;
					break;
				case 10:
					email = record;
					columnumnNumber++;
					break;
				case 11:
					birthday = record;
					columnumnNumber = 0;
					break;
			}
		}

		if (currentIndividual.setPerson(surName, address, city, state, zipcode, email, birthday, cNumber, gender, title, givenName, middleName)) {
			if (copyCNumber == cNumber) {
				continue;
			}
			else {
				person* ptr = nullptr;
				ptr = new person;

				*ptr = currentIndividual;

				nameList.push_back(*ptr);
				delete ptr;

				mainCount++;
				copyCNumber = cNumber;

				string* strPtr = nullptr;
				strPtr = new string;

				*strPtr = (to_string(cNumber) + ", " + givenName + " " + middleName + ". " + surName + ", " + birthday);
				stringPerson.push_back(*strPtr);
				delete strPtr;

				string* strPtrTwo = nullptr;
				strPtrTwo = new string;

				*strPtrTwo = givenName;
				columngivenName.push_back(*strPtrTwo);
				delete strPtrTwo;

				string* strPtrThree = nullptr;
				strPtrThree = new string;

				*strPtrThree = city;
				columnCity.push_back(*strPtrThree);
				delete strPtrThree;
			}
		}
	}

	fin.close();

	return 0;
}


int outputNames(string strOutFile) {		 // Fill summary.txt with valid summarized output values.
	
	int columnAmount = 4;
	int popularNamesCnt = 0;
	int uniqCnt = 0;
	int maxCount = 100;
	map<string, int> countMap;	
	
	ofstream outputFile;						//Creates and writes to files
	outputFile.open(strOutFile);	
	outputFile << "Collection contains " << nameList.size() << " records.\n";
	outputFile << setw(13) << right << "First person:" << " " << stringPerson.front() << "\n";
	outputFile << setw(13) << right << "Last person:" << " " << stringPerson.back() << "\n\n";
	outputFile << "Collection contains " << uniCount(columngivenName) << " unique First names.\n";

	
	for (auto& elem : columngivenName) {								//This map will count cities and compare elements to filter only popular ones.
		auto result = countMap.insert(pair < string, int >(elem, 1));
		if (result.second == false)
			result.first -> second++;
	}

	typedef
		function < bool(pair < string, int >, pair < string, int >) > Comparator;			//This function compares the elements.

	Comparator compFunctor = [](pair < string, int > elem1, pair < string, int > elem2) {
		return elem1.second > elem2.second;
	};

	set < pair < string, int >, Comparator > setOfWords(countMap.begin(), countMap.end(), compFunctor);
	for (pair < string, int > element : setOfWords) {
		if (popularNamesCnt >= maxCount) {
			break;
		}
		outputFile << setw(15) << right << element.first << ":" << setw(4) << right << element.second;
		uniqCnt++;
		popularNamesCnt++;

		if (uniqCnt == columnAmount) {
			outputFile << endl;
			uniqCnt = 0;
		}

	}

	countMap.clear();

	outputFile << endl << endl;
	outputFile << "Collection contains " << cityCount(columnCity) << " unique City names.\n";

	uniqCnt = 0;
	columnAmount = 3;
	int popularCitiesCnt = 0;
	map < string, int > countMapCity; 

	for (auto& elem : columnCity) {
		auto result = countMapCity.insert(pair < string, int >(elem, 1));
		if (result.second == false)
			result.first -> second++;
	}

	set < pair < string, int >, Comparator > setOfCityWords(countMapCity.begin(), countMapCity.end(), compFunctor);

	for (pair < string, int > element : setOfCityWords) {						//This map will count cities and compare elements to filter only popular ones.
		if (popularCitiesCnt >= maxCount) {
			break;
		}

		outputFile << setw(21) << right << element.first << ":" << setw(4) << right << element.second;
		uniqCnt++;
		popularCitiesCnt++;

		if (uniqCnt == columnAmount) {
			outputFile << endl;
			uniqCnt = 0;
		}
	}

	countMapCity.clear();

	outputFile << endl;

	outputFile.close();

	return 0;
}


int cityCount(vector < string > stringCountUnique)		 //VECTOR THAT CONTAINS THE COUNT OF UNIQUE CITY NAMES
{
	int nameCount = 0;
	int cityCount = 0;

	for (auto i = stringCountUnique.begin(); i != stringCountUnique.end(); i++) {
		nameCount = count(stringCountUnique.begin(), stringCountUnique.end(), *i);

		if (nameCount == 1) {
			cityCount++;
		}

	}

	return cityCount;
}

int uniCount(vector < string > stringCountUnique)						// Count the unique names in a vector.
{
	int nameCount = 0;
	uniqueCount = 0;

	for (auto i = stringCountUnique.begin(); i != stringCountUnique.end(); i++) {
		nameCount = count(stringCountUnique.begin(), stringCountUnique.end(), *i);

		if (nameCount == 1) {
			uniqueCount++;
		}

	}

	return uniqueCount;
}


int main() {
	fileInput = "FakeNames.csv";
	fileOutput = "summary.txt";

	displayIntroduction();

	extractNamesData(fileInput);
	outputNames(fileOutput);

	executionCompleted();


}

