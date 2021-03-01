// Participants: Gabriela Lopez, Andrew Thompson, and Lincoln Nguyen
// Date: 02-23-21
// Description: Implementation file for the employee class


#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "employee.h"
#include "List.h"
using namespace std;

Employee::Employee( ) : firstName("No name yet"),lastName("No name yet"), id(0), status('A'), startDate("default"), endDate("Current")
{

}

Employee::Employee(string newFirstName, string newLastName, char newStatus, string newStartDate, string newEndDate,int newId) : firstName(newFirstName), lastName(newLastName), status('T'), startDate(newStartDate), endDate(newEndDate), id(newId)
{
        
}

string Employee::getFirstName( ) const
{
    return firstName;
}
string Employee::getLastName() const
{
    return lastName;
}
char Employee::getStatus( ) const
{
    return status;
}

int Employee::getId( ) const
{
    return id;
}

void Employee::setFirstName(string newFirstName)
{
    firstName = newFirstName;
}
void Employee::setLastName(string newLastName)
{
    lastName = newLastName;
}
void Employee::setStatus (char newStatus)
{
    if (newStatus == 'A' || newStatus == 'I' || newStatus == 'U')
        status = newStatus;
    else
        status = 'U';
}

void Employee::setId (int newId)
{
    id = newId;
}

string Employee::getStartDate( ) const
{
    return startDate;
}

string Employee::getEndDate( ) const
{
    return endDate;
}

void Employee::setStartDate(string newDate)
{
    startDate = newDate;
}

void Employee::setEndDate(string newDate)
{
    endDate = newDate;
}

int Employee::inputInteger(string prompt, int startRange, int endRange)
{
    int input;
    do
    {
        cout << prompt;
        if (!(cin >> input))
        {
            cout << "ERROR-3A: Invalid input. Must be an integer type.\n";
            cin.clear();
            cin.ignore(999, '\n');
        }
        else if (!(input >= min(startRange, endRange) && input <= max(startRange, endRange)))
            cout << "ERROR-3A: Invalid input. Must be from " << startRange << ".." << endRange << ".\n";
        else
        {
            cin.clear();
            cin.ignore(999, '\n');
            break;
        }
    } while (true);
    return input;
}

int Employee::employeeMainMenu()
{
    system("cls");
    cout << '\n';
    cout << '\t' << char(201) << string(70, char(205)) << char(187) << '\n';
    cout << '\t' << char(186) << "     \t\t  CMPR131: List of Employees System                    " << char(186) << '\n';
    cout << '\t' << char(186) << " Made by:                                                             " << char(186) << '\n';
    cout << '\t' << char(186) << " - Gabriela Lopez\t- Andrew Thompson\t- Lincoln Nguyen       " << char(186) << '\n';
    cout << '\t' << char(186) << " - Long Duong\t\t- Christopher Gomez\t- Gia Minh Hoang       " << char(186) << '\n';
    cout << '\t' << char(186) << " - Duyen Tran                                                         " << char(186) << '\n';
    cout << "\t" << char(204) << string(70, char(205)) << char(185) << "\n";
    cout << "\t" << char(186) << "  1: Read data from file and store into a list                        " << char(186) << "\n";
    cout << "\t" << char(186) << "  2: Insert a new employee record into the list                       " << char(186) << "\n";
    cout << "\t" << char(186) << "  3: Update an employee record from the list                          " << char(186) << "\n";
    cout << "\t" << char(186) << "  4: Display all, active or inactive employee records from the list   " << char(186) << "\n";
    cout << "\t" << char(186) << "  5: Write data from the list to a file                               " << char(186) << "\n";
    cout << "\t" << char(199) << string(70, char(196)) << char(182) << "\n";
    cout << "\t" << char(186) << "   0: Exit                                                            " << char(186) << "\n";
    cout << "\t" << char(200) << string(70, char(205)) << char(188) << "\n";

    int option = inputInteger("\t    Option: ", 0, 5);
    cin.clear();
    return option;
}

void Employee::updateEmployee(List& employeeList)
{
    if (employeeList.empty())
        cout << "\n ERROR: Empty employee list.\n";
    else
    {
        List listCopy(employeeList);
        listNode* currentPtr;
        currentPtr = listCopy.getHead();
        int firstID = currentPtr->obj.getId();
        int lastID;
        while (currentPtr != NULL)
        {
            lastID = currentPtr->obj.getId();
            if (currentPtr->next == NULL)
                break;
            else
                currentPtr = currentPtr->next;
        }

        int ID = currentPtr->obj.inputInteger("\nEnter a valid employee ID ("
            + to_string(firstID) + ".." + to_string(lastID) + "): ", firstID, lastID);

        int menuOption;

        currentPtr = listCopy.getHead();

        while (currentPtr->obj.getId() != ID)
        {
            if (currentPtr->next == NULL)
            {
                cout << "\nERROR: ID NOT FOUND.\n";
                break;
            }
            else
                currentPtr = currentPtr->next;
        }

        char newStatus = currentPtr->obj.getStatus();
        string newLastName = currentPtr->obj.getLastName();
        string newFirstName = currentPtr->obj.getFirstName();
        string newStartDate = currentPtr->obj.getStartDate();
        string newEndingDate = currentPtr->obj.getEndDate();

        do
        {
            menuOption = updatingMenu(ID, listCopy);
            switch (menuOption)
            {
            case 0: cout << "\nNot Saved.\n"; break;
            case 1: newStatus = getNewStatus(); currentPtr->obj.setStatus(newStatus); break;
            case 2: newLastName = getNewLastName(); currentPtr->obj.setLastName(newLastName); break;
            case 3: newFirstName = getNewFirstName(); currentPtr->obj.setFirstName(newFirstName); break;
            case 4: newStartDate = getNewStartDate(); currentPtr->obj.setStartDate(newStartDate); break;
            case 5: newEndingDate = getNewEndingDate(); currentPtr->obj.setEndDate(newEndingDate); break;
            case 6: commitUpdate(ID, employeeList, newStatus, newLastName,
                newFirstName, newStartDate, newEndingDate);
                break;

            default: cout << "\t\t    ERROR-Invalid Option. Please re-enter."; break;
            }
            if (menuOption == 0 || menuOption == 6)
                break;
            cout << '\n';
        } while (true);
    }
}

int Employee::updatingMenu(int theEmployeeID, List employeeList)
{
    if (employeeList.empty())
    {
        cout << "The list is Empty! please add some employees and try again!\n";
        return 0;
    }
    listNode* currentPtr;
    currentPtr = employeeList.getHead();
    while (currentPtr->obj.getId() != theEmployeeID)
        currentPtr = currentPtr->next;

    cout << "\t" << string(50, char(205)) << "\n";
    cout << "\t" << "  1: Current Status: " << currentPtr->obj.getStatus() << "            \n";
    cout << "\t" << "  2: Current Last Name: " << currentPtr->obj.getLastName() << "           \n";
    cout << "\t" << "  3: Current First Name: " << currentPtr->obj.getFirstName() << "          \n";
    cout << "\t" << "  4: Current Starting Date: " << currentPtr->obj.getStartDate() << "  \n";
    cout << "\t" << "  5: Current Ending Date: " << currentPtr->obj.getEndDate() << "      \n";
    cout << "\t" << string(50, char(205)) << "\n";
    cout << "\t" << "  6: Commit the change(s) and return                                 \n";
    cout << "\t" << "  0: Uncommit the change(s) and return                               \n";
    cout << "\t" << string(50, char(205)) << "\n";

    int option = inputInteger("\t    Option: ", 0, 6);
    cin.clear();
    return option;
}

char Employee::inputChar(string prompt, string listChars)
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

char Employee::getNewStatus()
{
    char newStatus = toupper(inputChar("\nChange status to A-active, I-inactice or U-Unknown status: ", "aiu"));
    return newStatus;
}

string Employee::getNewLastName()
{
    string newLastName;
    cout << "Enter the new last name: ";
    cin >> newLastName;
    return newLastName;
}

string Employee::getNewFirstName()
{
    string newFirstName;
    cout << "Enter the new first name: ";
    cin >> newFirstName;
    return newFirstName;
}

string Employee::getNewStartDate()
{
    string newStartDate;
    cout << "Enter the new start date (mm/dd/yy): ";
    cin >> newStartDate;
    return newStartDate;
}

string Employee::getNewEndingDate()
{
    string newEndingDate;
    cout << "Enter the new ending date (mm/dd/yy): ";
    cin >> newEndingDate;
    return newEndingDate;
}

void Employee::commitUpdate(int employeeID, List& employeeList, char newStatus,
    string newLastName, string newFirstName, string newStartDate, string newEndingDate)
{
    listNode* currentPtr;
    currentPtr = employeeList.getHead();
    while (currentPtr->obj.getId() != employeeID)
        currentPtr = currentPtr->next;

    currentPtr->obj.setStatus(newStatus);
    currentPtr->obj.setLastName(newLastName);
    currentPtr->obj.setFirstName(newFirstName);
    currentPtr->obj.setStartDate(newStartDate);
    currentPtr->obj.setEndDate(newEndingDate);

    cout << "\nThe changes has been saved.\n";
}
