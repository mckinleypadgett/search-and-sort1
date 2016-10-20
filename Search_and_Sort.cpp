//============================================================================
// Name        : Search_and_Sort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void displayMenu();
int userChoice();
void displayList(string[], string[], string[], int);
void sort(string[], string[], string[], int);
void searchList(string[], string[], string[], int);

int main() {

	int entryAmount;
	int count = 0;
	int choice;
	ifstream infile;
	string inputFile;

	cout << "Please enter the input file name: "; // Gather input file
	cin >> inputFile;

	infile.open(inputFile.c_str()); // Open input file

	if(!infile)
	{
		cout << "Error: Unable to open file " << inputFile << "for reading." << endl;
		cout << "Terminating program." << endl;
	}

	infile >> entryAmount; // Gather amount of entries in input file

	const int ARRAY_SIZE = entryAmount;

	// Initialize parallel arrays
	string* lastName = new string[ARRAY_SIZE];
	string* firstName = new string[ARRAY_SIZE];
	string* birthDate = new string[ARRAY_SIZE];
	string* originalLast = new string[ARRAY_SIZE];
	string* originalFirst = new string[ARRAY_SIZE];
	string* originalBirth = new string[ARRAY_SIZE];

	// Assign input values to parallel arrays
	while(count < ARRAY_SIZE)
	{
		infile >> lastName[count];
		infile >> firstName[count];
		infile >> birthDate[count];

		count++;
	}

	// Create duplicates for original arrays for original display
	for(int element = 0; element < ARRAY_SIZE; element++)
	{
		originalLast[element] = lastName[element];
		originalFirst[element] = firstName[element];
		originalBirth[element] = birthDate[element];
	}


	do
	{
		displayMenu();
		choice = userChoice();
		cout << "recieved from keyboard: " << choice << endl;

		if (choice !=5)
		{
			switch (choice)
			{
			case 1: searchList(lastName, firstName, birthDate, ARRAY_SIZE);
					break;
			case 2: displayList(originalLast, originalFirst, originalBirth, ARRAY_SIZE);
					break;
			case 3: sort(firstName, lastName, birthDate, ARRAY_SIZE);
					displayList(lastName, firstName, birthDate, ARRAY_SIZE);
					break;
			case 4: sort(lastName, firstName, birthDate, ARRAY_SIZE);
					displayList(lastName, firstName, birthDate, ARRAY_SIZE);
					break;
			default: cout << "The choice was: " << choice << endl;
					break;
			}
		}
	}while (choice !=5);

	delete[] lastName;
	delete[] firstName;
	delete[] birthDate;

	return 0;
}

void displayMenu() {
	cout << "\nUser Option \n\n";
	cout << "1. Search\n";
	cout << "2. Display original input\n";
	cout << "3. Sort by first name\n";
	cout << "4. Sort by last name\n";
	cout << "5. Quit\n";

	return;
}

int userChoice() {

	int choice;

	cout << "\nPlease enter choice: ";
	cin >> choice;

	while (choice < 1 || choice > 5)
	{
		cout << "The only valid choice are 1-5. Please re-enter: ";
		cin >> choice;
	}
	return choice;
}

void displayList(string lastName[], string firstName[], string birthDate[], int ARRAY_SIZE)
{
	for (int index = 0; index < ARRAY_SIZE; index++)
	{
		cout << lastName[index] << endl;
		cout << firstName[index] << endl;
		cout << birthDate[index] << endl;
		cout << endl;
	}
	cout << "\nPress the Enter key to return to the menu.";
	cin.get();
	cin.get();
	return;
}

void sort(string name1[], string name2[], string birthDate[], int ARRAY_SIZE)
{
	string temp;
	bool swap;

	do
	{
		swap = false;
		for (int index = 0; index < (ARRAY_SIZE - 1); index++)
		{
			if (name1[index] > name1[index + 1])
			{
				temp = name1[index];
				name1[index] = name1[index + 1];
				name1[index + 1]= temp;

				temp = name2[index];
				name2[index] = name2[index + 1];
				name2[index + 1] = temp;

				temp = birthDate[index];
				birthDate[index] = birthDate[index + 1];
				birthDate[index + 1] = temp;

				swap = true;
			}
		}
	}while (swap);
	return;
}

void searchList(string lastName[], string firstName[], string birthDate[], int ARRAY_SIZE)
{
	string searchValue;

	cout << "Please enter a search value: ";
	cin >> searchValue;

	for (int index = 0; index < ARRAY_SIZE; index++)
	{
		if (!lastName[index].find(searchValue))
		{
			cout << endl;
			cout << lastName[index] << endl;
			cout << firstName[index] << endl;
			cout << birthDate[index] << endl;
			cout << endl;
		}
		if (!firstName[index].find(searchValue))
		{
			cout << endl;					cout << lastName[index] << endl;
			cout << firstName[index] << endl;
			cout << birthDate[index] << endl;
			cout << endl;
		}
		if (!birthDate[index].find(searchValue))
		{
			cout << endl;
			cout << lastName[index] << endl;
			cout << firstName[index] << endl;
			cout << birthDate[index] << endl;
			cout << endl;
		}
	}
	cout << "\nPress the Enter key to return to the menu.";
	cin.get();
	cin.get();

	return;
}

