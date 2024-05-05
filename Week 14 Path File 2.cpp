// Week 14 Path File 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readFromFile();

void writeToFile();

struct Product
{
	string name;
	int ID;
	float price;
};


int main()
{
	int select;
	do {
		

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
	while (getline(readData, line))
	{
		cout << line << endl;
	}
	//read data from the file

	readData.close();
}

void writeToFile()
{
	Product newProduct;

	cout << "1 - Enter Product Name  :\n"; cin >> newProduct.name;
	cout << "2 - Enter Product ID    :\n"; cin >> newProduct.ID;
	cout << "3 - Enter Product Price :\n"; cin >> newProduct.price;
	
}


