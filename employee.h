// Participants: Gabriela Lopez, Andrew Thompson, and Lincoln Nguyen
// Date: 02-23-21
// Description: Class Employee Definition

//EXPLAIN HOW TO USE THIS CLASS************************************************************************
//HEADER FILE COMMENT

#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class list;

class Employee
{
private:
    string firstName;
    string lastName;
    char status;
    int id;
    string startDate;
    string endDate;
public:

    
    //precondition:N/A
    //postcondition:creates an employee object
    Employee( );
    //precondition: a first/last name, status, start and end date, and an id
    //postcondition: creates a employee object with those parameters 
    Employee(string newFirstName, string newLastName, char newStatus, string newStartDate, string newEndDate, int newId);
    //precondition:a employee object 
    //postcondition:returns the first name stored in the object
    string getFirstName( ) const;
    //precondition:a employee object 
    //postcondition:returns the last name stored in the object
    string getLastName() const;
    //precondition:a employee object 
    //postcondition:returns the status of the object
    char getStatus( ) const;
    //precondition:a employee object 
    //postcondition:returns the id of the object
    int getId( ) const;
    //precondition:a employee object and a newFirstName
    //postcondition:Sets the name of the object to newFirstName
    void setFirstName(string newFirstName);
    //precondition:a employee object and a newLastName
    //postcondition:Sets the name of the object to newLastName
    void setLastName(string newLastName);
    //precondition:a employee object and a new status
    //postcondition:sets the objects status to new Status
    void setStatus(char newStatus);
    //precondition:a employee object new id
    //postcondition:sets the objects id to newId
    void setId(int newId);
    //precondition:a employee object 
  //postcondition:returns the start date
    string getStartDate() const;
    //precondition:a employee object 
    //postcondition:returns the end date
    string getEndDate() const;
    //precondition:a employee object and a new start date
    //postcondition:sets the objects start date to newDate
    void setStartDate(string newDate);
    //precondition:a employee object and a new end date
    //postcondition:sets the objects start date to newDate
    void setEndDate(string newDate);
    //Precondition: N/A
    //Postcondition: Prints menu and returns user int option selected
    int employeeMainMenu();
    //Precondition: N/A
    //Postcondition: return an input integer within range ,start and end
    int inputInteger(string prompt, int startRange, int endRange);
    //precondition: an employee objecy
    //postcondition: updates the employee object
    void updateEmployee(list& employeeList);
    //precondition: A list of emplyee objects
    //postcondition: displays the update employee menu
    int updatingMenu(int theEmployeeID, list employeeList);
    //precondition: An employee object
    //postcondition:Asks the user to enter a new status of either A, I, or U
    char inputChar(string prompt, string listChars);
    //precondition: An employee object
    //postcondition:Asks the user to enter a new status of either A, I, or U
    char getNewStatus();
    //precondition: An employee object
    //postcondition:Asks the user to enter a new lastname
    string getNewLastName();
    //precondition: An employee object
    //postcondition:Asks the user to enter a new firstname
    string getNewFirstName();
    //precondition: An employee object
    //postcondition:Asks the user to enter a new startDate
    string getNewStartDate();
    //precondition: An employee object
    //postcondition:Asks the user to enter a new endDate
    string getNewEndingDate();
    //precondition: an employee object wrapped in a list
   //postcondition: commits the changes made in updating menu by replacing the object in the list node
    void commitUpdate(int employeeID, list employeeList, char newStatus,
        string newLastName, string newFirstName, string newStartDate, string newEndingDate);
    
};

#endif
//TODO: Overload = operator, write copy constructor/destructor