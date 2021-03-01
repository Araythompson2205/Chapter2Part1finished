// Participants: Gabriela Lopez, Andrew Thompson, and Lincoln Nguyen
// Date: 02-23-21
// Description: implementation file for the list class 

#include "List.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "employee.h"
using namespace std;

List::List() : head(NULL), tail(NULL)
{
	size = 0;
}

listNode* List::getHead()
{
	return head;
}
bool List::empty() const
{
	return (head == NULL);
}
List::List(const List& obj)
{
	head = new listNode;
	head->obj = obj.head->obj;
	head->next = obj.head->next;
}
//List::~List()
//{
//	listNode* current = head;
//	while (current != 0) {
//		listNode* next = current->next;
//		delete current;
//		current = next;
//	}
//	head = 0;
//}
void List::addItem(Employee& newObj) 
{	
	if (head == NULL) 
	{
		size = 1;
		head = new listNode;
		head->obj = newObj;
		head->next = NULL;
		
	}
	else 
	{
		listNode *temp = new listNode;
		temp->obj = newObj;
		temp->next = NULL;
		
		listNode *tempPtr = head;

		while (tempPtr->next != NULL)
			tempPtr = tempPtr->next;

		temp->next = tempPtr->next;
		tempPtr->next = temp;
		size++;
	}
}


void List::deleteLast() {


	if (head == NULL) {
		return;
	}
	if (head->next == NULL) {
		delete head;
		head = NULL;
		return;
	}
	listNode* temp = head;
	while (temp->next && temp->next->next != NULL) {
		temp = temp->next;
	}
	delete temp->next;
	temp->next = NULL;
}
void List::addEmployee()
{
	if (head == NULL)
		cout << "\nERROR: Empty employee list.\n";
	else
	{
		string firstName, lastName, startDate;
		Employee newEmployee;
		size++;
		newEmployee.setId(size);
		cout << "\n Enter the last name: ";
		cin >> lastName;
		cout << "\n Enter the first name: ";
		cin >> firstName;
		startDate = inputDate("\nEnter the Starting date: ");
		newEmployee.setFirstName(firstName);
		newEmployee.setLastName(lastName);
		newEmployee.setStartDate(startDate);
		addItem(newEmployee);
	}
}
ostream& operator <<(ostream& outs, List& obj) {
	listNode* temp = obj.head;
	while (temp != NULL) {
		cout << '\t' << "Employee ID : " << temp->obj.getId() << '\n';
		cout << '\t' << "Name        : " << temp->obj.getLastName() << ", " << temp->obj.getFirstName() << '\n';
		cout << '\t' << "Status      : " << temp->obj.getStatus() << '\n';
		cout << '\t' << "Start date  : " << temp->obj.getStartDate() << '\n';
		cout << '\t' << "End date    : " << temp->obj.getEndDate() << "\n\n";
			
		temp = temp->next;
	}

	return outs;
}
void List::readFile()
{
	ifstream file;
	Employee newEmployee;
	string value, value1;
	string fileName;
	do
	{
		
		cout << "Enter the file name: ";
		cin >> fileName;
		fileName;
		file.open(fileName);
		if (!file.is_open())
			cout << "Error: file not found!\n";

	} while (!file.is_open());
	if (file.is_open())
	{
		if (file.peek() == ifstream::traits_type::eof())
		{
			cout << "\n ERROR: The file is empty.\n";
		
		}
		else
		{
			while (getline(file, value, ','))
			{
				newEmployee.setStatus(value[0]);
				getline(file, value, ',');
				newEmployee.setId(stoi(value));
				getline(file, value, ',');
				newEmployee.setLastName(value);
				getline(file, value, ',');
				newEmployee.setFirstName(value);
				getline(file, value, ',');
				newEmployee.setStartDate(value);
				getline(file, value, '\n');
				newEmployee.setEndDate(value);
				addItem(newEmployee);
			}
			cout << "\nCompleted transfering data from file to list.\n";
			
		}
		file.close();
	}

}
void List::copyToFile()
{
	string fileName;
	if (empty())
		cout << "\n ERROR: Empty employee list.\n";
	else
	{
		cout << "Enter the file name: ";
		cin >> fileName;
		ofstream writeToFile;
		writeToFile.open(fileName);

		listNode* currentPtr;
		currentPtr = getHead();
		while (currentPtr != NULL)
		{
			writeToFile << currentPtr->obj.getStatus() << ',' << currentPtr->obj.getId() << ','
				<< currentPtr->obj.getLastName() << ',' << currentPtr->obj.getFirstName() << ',' << currentPtr->obj.getStartDate()
				<< ',' << currentPtr->obj.getEndDate() << '\n';
			currentPtr = currentPtr->next;
		}
		cout << "\n Data successfully saved.\n";
	}
}
void List::outputActive(List obj) const
{

	listNode* temp = obj.head;
	while (temp != NULL) {
		if (toupper(temp->obj.getStatus()) == 'A') 
		{
			cout << '\t' << "Employee ID : " << temp->obj.getId() << '\n';
			cout << '\t' << "Name        : " << temp->obj.getLastName() << ", " << temp->obj.getFirstName() << '\n';
			cout << '\t' << "Status      : " << temp->obj.getStatus() << '\n';
			cout << '\t' << "Start date  : " << temp->obj.getStartDate() << '\n';
			cout << '\t' << "End date    : " << temp->obj.getEndDate() << "\n\n";

		}
		temp = temp->next;
	}
	return;
}
void List::outputInactive(List obj) const
{
	listNode* temp = obj.head;
	while (temp != NULL) {
		if (toupper(temp->obj.getStatus()) == 'I') 
		{
			cout << '\t' << "Employee ID : " << temp->obj.getId() << '\n';
			cout << '\t' << "Name        : " << temp->obj.getLastName() << ", " << temp->obj.getFirstName() << '\n';
			cout << '\t' << "Status      : " << temp->obj.getStatus() << '\n';
			cout << '\t' << "Start date  : " << temp->obj.getStartDate() << '\n';
			cout << '\t' << "End date    : " << temp->obj.getEndDate() << "\n\n";

		}
		temp = temp->next;
	}
	return;
}
void List::outputMenu (List& employeeList) 
{
	bool loop = true;
	if (employeeList.empty())
	{
		cout << "The list is Empty! please add some employees and try again!\n";
		return;
	}
	do {
		cout << "\t" << string(50, char(205)) << "\n";
		cout << "\t" << "  A: All records " << "\n";
		cout << "\t" << "  B: Actice records " << "\n";
		cout << "\t" << "  C: Inactive records " << "\n";
		cout << "\t" << string(50, char(205)) << "\n";
		cout << "\t" << "  X: Return\n";
		cout << "\t" << string(50, char(205)) << "\n";

		char option = inputCharacter("\t    Option: ", "ABCX");
		cin.clear();

		switch (toupper(option))
		{
		case('X'): loop = false; break;
		case('A'): cout << employeeList; break;
		case('B'): employeeList.outputActive(employeeList); break;
		case('C'): employeeList.outputInactive(employeeList); break;
		}

	} while (loop);
	return;
}
string inputDate(string prompt)			//validates date in form dd/mm/yy
{
	char input[9];
	string toReturn="";
	do
	{
		cout << prompt;
		cin >> input;
		if (strlen(input) < 8 || strlen(input) > 8)
		{
			cout << "Error: date must be in mm/dd/yy format\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (strlen(input) == 8)
		{
			char m[3], d[3], y[3];
			int mm, dd, yy;
			int i, n;
			for (i = 0; i < 2; i++)
				m[i] = input[i];
			for (i = 3, n = 0; i < 5; i++, n++)
				d[n] = input[i];
			for (i = 6, n = 0; i < 8; i++, n++)
				y[n] = input[i];
			mm = atoi(m);
			dd = atoi(d);
			yy = atoi(y);
			if ((mm == 1 || mm == 3 || mm == 5 || mm == 7 ||
				mm == 8 || mm == 10 || mm == 12) && (dd > 31 || dd < 1))
			{
				cout << "Error: date must be in mm/dd/yy format\n";
				cin.clear();
				cin.ignore(999, '\n');
			}
			else if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && (dd > 30 || dd < 1))
			{
				cout << "Error: Date \n";
				cin.clear();
				cin.ignore(999, '\n');
			}
			else if ((mm == 2) && (yy % 4 == 0) && (dd > 29 || dd < 1))
			{
				cout << "Error: date must be in mm/dd/yy format\n";
				cin.clear();
				cin.ignore(999, '\n');
			}
			else if ((mm == 2) && (yy % 4 != 0) && (dd > 28 || dd < 1))
			{
				cout << "Error: date must be in mm/dd/yy format\n";
				cin.clear();
				cin.ignore(999, '\n');
			}
			else if ((mm < 1) || (mm > 12))
			{
				cout << "Error: date must be in mm/dd/yy format\n";
				cin.clear();
				cin.ignore(999, '\n');
			}
			else
			{
				for (i = 0; i < 8; i++)
					toReturn = toReturn + input[i];
				break;
			}
		}
		
	} while (true);
	return toReturn;
}
//return an input char
char inputCharacter(string prompt, string listChars)
{
	char input;
	do
	{
		cout << prompt;
		if (!(cin >> input))
		{
			cout << "ERROR-1A: Invalid input. Must be a character type.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		bool bfound = false;
		for (unsigned c = 0; c < listChars.length(); c++)
			if (toupper(listChars[c]) == toupper(input))
			{
				bfound = true;
				break;
			}
		if (!bfound)
		{
			cout << "ERROR-2A: Invalid input. Must be a character from the list of '";
			for (unsigned c = 0; c < listChars.length() - 1; c++)
				cout << "'" << static_cast<char>(toupper(listChars[c])) << "', ";
			cout << "or '" << static_cast<char>(toupper(listChars.back())) << "'.\n";
		}
		else
			break;
	} while (true);
	return input;
}
