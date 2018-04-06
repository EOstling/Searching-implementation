#include "OstlingPersonGen\PersonGen.h"
#include "OstlingPersonGen\Date.h"
#include "OstlingPersonGen\Person.h"
#include "Search.h"
#include <iostream>
#include "OstlingPersonGen\PersonSort.h"
using namespace std;

int main() 
{

	PersonGen pg;
	string name;
	string fullName;
	int pos = -1;
	int total;
	int pNumCompares = 0;
	bool sqsearch = false;
	bool binSearch = false;
	bool rBinSearch = false;
	string exporterFile;
	


	//array of Dynamic New Person Gen obj
	PersonGen *genArray;
	genArray = new PersonGen[100];
	


	Date date;
	date.SetDesc("\nDefault Description\n");


	cout << "Enter a name";
	getline(cin,exporterFile);

	ofstream oStream;
	oStream.open(exporterFile.c_str());
	oStream << exporterFile << date.GetFormattedDate()<<endl;
	

	Person folks[100];//generic person obj

	pg.UseFile("Eliot-Ostling.txt");

	//for loop to assign to the arrays
	for (int i = 0; i<100; ++i)
	{
		folks[i] = pg.GetPerson();
	}
	//Output to the screen
	for (int i=0; i<100;++i) 
	{
		cout << folks[i].GetName();
	}


	//create a person sort obj
	PersonSort ps;
	ps.shellSort(folks,100);

	//output this stuff
	for (int i=0; i<10; ++i) 
	{
		cout << folks[i].GetName()<<endl; 
	}

	//start a sentinel do while loop and get user info
	char iterator = 'N';
	do
	{
		//get user name info
		cout << "Please enter a Full Name"<<endl;
		getline(cin,fullName);
		//call seq search
		sqsearch = SequentialSearch(folks,100,fullName,&total, &pNumCompares);

		//now we do bin search
		//rrsearch

	} while (iterator =='N');































	return -1;
}