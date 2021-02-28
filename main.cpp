// Participants: Gabriela Lopez, Andrew Thompson, Long Duong, Christopher Gomez, Gia Minh Hoang, Duyen Tran and Lincoln Nguyen
// Date: 02-23-21
// Description: Chapter 2 Solution

#include <iostream>
#include<string>
#include "input.h"
#include "List.h"
#include "employee.h"
using namespace std;

int menuOption();
void employeeSystem();

int main()
{
	do
	{
		switch (menuOption())
		{
		case 0:  exit(0);
		case 1:  system("cls"); employeeSystem();     break;
		//case 2:  system("cls"); baseConverter();  break;
		default: cout << "\t\t    ERROR-Invalid Option. Please re-enter."; break;
		}
		cout << '\n';
		system("pause");
	} while (true);
	return 0;
}

//Precondition: N/A
//Postcondition: Prints menu and returns user int option selected
int menuOption()
{
	system("cls");
	cout << '\n';
	cout << '\t' << char(201) << string(42, char(205)) << char(187) << '\n';
	cout << '\t' << char(186) << "    \t    CMPR131: Chapter 2             " << char(186) << '\n';
	cout << '\t' << char(186) << "      \t\t  Made by:                 " << char(186) << '\n';
	cout << '\t' << char(186) << " - Gabriela Lopez\t- Andrew Thompson  " << char(186) << '\n';
	cout << '\t' << char(186) << " - Lincoln Nguyen\t- Long Duong       " << char(186) << '\n';
	cout << '\t' << char(186) << " - Christopher Gomez\t- Gia Minh Hoang   " << char(186) << '\n';
	cout << '\t' << char(186) << " - Duyen Tran                             " << char(186) << '\n';
	cout << "\t" << char(204) << string(42, char(205)) << char(185) << "\n";
	cout << "\t" << char(186) << "   1: List of Employees                   " << char(186) << "\n";
	cout << "\t" << char(186) << "   2: Pseudorandom                        " << char(186) << "\n";
	cout << "\t" << char(199) << string(42, char(196)) << char(182) << "\n";
	cout << "\t" << char(186) << "   0: Exit                                " << char(186) << "\n";
	cout << "\t" << char(200) << string(42, char(205)) << char(188) << "\n";

	int option = inputInteger("\t    Option: ", 0, 2);
	cin.clear();
	return option;
}

//Precondition: N/A
//Postcondition: Contains the List of Employees system
void employeeSystem()
{
	Employee Employee1;
	list employeeList; 
	int menuOption;
	do
	{
		menuOption = Employee1.employeeMainMenu();
		switch (menuOption)
		{
		case 0: break;
		case 1: employeeList.readFile(); break;
		case 2: employeeList.addEmployee(); break;
		case 3: Employee1.updateEmployee(employeeList); break;
		case 4: employeeList.outputMenu(employeeList); break;
		case 5: employeeList.copyToFile(); break;

		default: cout << "\t\t    ERROR-Invalid Option. Please re-enter."; break;
		}
		if (menuOption == 0)
			break;
		cout << '\n';
		system("pause");
	} while (true);
}