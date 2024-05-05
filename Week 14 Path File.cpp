// Week 14 Path File.cpp : This file contains the 'main' function. Program execution begins and ends there.
//28/12/2023 13:00

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readFromFile();

void writeToFile();


int main()
{
	int select;
	do {
		system("cls"); //Clear the console screen
		cout << "1 - Read Data\n";
		cout << "2 - Write Data\n";
		cout << "3 - Exit\n";

		cin >> select;

		switch (select)
		{
		case 1:
			system("cls");
			//Read data operations
			readFromFile();
			break;
		case 2:
			//Write data operations
			writeToFile();
			break;
		default:
			system("exit");
			//Exit data
			break;
		}
	} while ((select != 1) && (select != 2) && (select != 3));
	cout << "OK..";
}

void readFromFile()
{
	ifstream readData("data.txt", ios::app);

	string line;
	while(getline(readData,line))
	{
		cout << line << endl;
	}
	//read data from the file

	readData.close();
}

void writeToFile()
{
	ofstream writeData("data.txt", ios::app);

	if (writeData.is_open())
	{
		writeData << "HelloWorld...\n";
	}
	writeData.close();
}
