// Participants: Gabriela Lopez, Andrew Thompson, and Lincoln Nguyen
// Date: 02-23-21
// Description: LinkedList of Employees Definition 

//this class creates a list which is used to store objects of the type employee, as well as read from/to files with properly formatted employee data
//header file for the list class

#pragma once
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cstdlib>
#include "employee.h"
using namespace std;

	struct listNode {
		Employee obj;
		listNode* next;
	};
	class List {
	private:
		listNode* head, * tail;
		int size;
	public:
		//Precondition:N/A
		//Postcondition:Creates a list
		List();
		//Precondition:A list object
		//Postcondition:Creates a list with the same items as obj
		List(const List& obj);
		//Precondition: n/a
		//postcondition: destroys the list
		~List();//causes fatal errors. Professor, would you please let me know why this destructor does this? -Andrew Thompson
		//precondition: a  list with at least one node(Please really do not call this on an empty list)
		//postcondition:removes the last node in the list
		void deleteLast();
		//precondition: any list, empty or not.
		//postcondition:adds a node with value of obj at the end of the list
		void addItem(Employee obj);
		//Precondition: a list containing employee objects
		//postcondition: runs the addEmployee option for the employee program, asking the user to create a new employee
		void addEmployee();
		//Precondition: a list containing employee objects
		//postcondition: displays all list nodes and thier contents 
		friend ostream& operator <<(ostream& outs, List& obj);
		//Precondition: a list 
		//postcondition: returns true if empty, false if not.
		bool empty() const;
		//Precondition: a list 
		//postcondition: Returns the location of the head of the list
		listNode* getHead();
		//Precondition: N/A
		 //Postcondition: Open a file and read data, validates existence of file and emptiness of file
		void readFile();
		//Precondition: Needs a linkedlist of employee objects
		//Postcondition: copies the linked list into a file with the name chosen by the user
		void copyToFile();
		//Preconditions: A list of employees wit one or more objects stored
		//Postcondition: displays all active employees
		void outputActive(List obj) const;
		//Preconditions: A list of employees with one or more objects stored
		//Postconditions: displays all inactive employees
		void outputInactive(List obj) const;
		//Preconditions: A list object. calling on an empty list outputs an error
		//postconditions: displays a menu for displaying the contents of the list by All, Active, or inactive.
		void outputMenu(List& obj);
	};
	//Precondition: the employee program is running and the user has chosen to add a new employee
	//Postconditions: returns an input date as a string, provided it is a valid date AND is in mm/dd/yy format.
	string inputDate(string promt);
	//returns an input char
	char inputCharacter(string prompt, string listChars);
#endif 
