#include <iostream>
#include <stdexcept>
#include <exception>
#include "Database.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;
using namespace Records;

// declare functions
int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doDemote(Database& db);
void generateNewDatabase(Database& db);
vector<string> readData(string filename);
void doSave(Database& db);
void doLoad(Database& db);
void doEdit(Database& db);
void doSearch(Database& db);

int main() {
    Database employeeDB;
    
 	bool done = false;
	while (!done) {
		int selection = displayMenu();
		switch (selection) {
		case 0:
			done = true;
			break;
		case 1:
			doHire(employeeDB);
			break;
		case 2:
			doFire(employeeDB);
			break;
		case 3:
			doPromote(employeeDB);
			break;
		case 4:
			employeeDB.displayAll();
			break;
		case 5:
			employeeDB.displayCurrent();
			break;
		case 6:
			employeeDB.displayFormer();
			break;
        case 7:
			generateNewDatabase(employeeDB);
			break; 
        case 8:
			doSave(employeeDB);
			break;  
        case 9:
			doLoad(employeeDB);
			break;  
        case 10:
			doEdit(employeeDB);
			break;  
        case 11:
			doSearch(employeeDB);
			break;  
		default:
			cerr << "Unknown command." << endl;
			break;
		}
	}




    return 0;

}

int displayMenu() {
    // Note:
	//		One important note is that this code assumes that the user will
	//		"play nice" and type a number when a number is requested.
	//		When you read about I/O in Chapter 13, you will learn how to
	//		protect against bad input.

    int selection;

    cout << "Employee Database" << endl;
    cout << "-----------------" << endl;
    cout << "1) Hire a new employee" << endl;
    cout << "2) Fire an employee" << endl;
    cout << "3) Promote an employee" << endl;
    cout << "4) List all employees" << endl;
    cout << "5) List all current employees" << endl;
    cout << "6) List all former employees" << endl;
    cout << "7) Generate new database" << endl;
    cout << "8) Save database to file" << endl;
    cout << "9) Load database from file" << endl;
    cout << "10) Edit employee" << endl;
    cout << "11) Search employee" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "---> ";

    cin >> selection;

    return selection;
}

void doHire(Database& db)
{
    string firstName;
    string lastName;
    string middleName;
    string address;

    cout << "First name? ";
    cin >> firstName;
    cout << "Last name? ";
    cin >> lastName;
    cout << "Middle name? ";
    cin >> middleName;
    cout << "Address? ";
    cin >> address;

    db.addEmployee(firstName, lastName, middleName, address);
}

void doFire(Database& db)
{
    int employeeNumber;

    cout << "Employee number? ";
    cin >> employeeNumber;

    try {
        Employee& emp = db.getEmployeeByNumber(employeeNumber);
        emp.fire();
        cout << "Employee " << employeeNumber << " terminated." << endl;
    } catch (const std::logic_error& exception) {
        cerr << "Unable to terminate employee: " << exception.what() << endl;
    }
}

void doPromote(Database& db)
{
    int employeeNumber;
    int raiseAmount;

    cout << "Employee number? ";
    cin >> employeeNumber;
    cout << "How much of a raise? ";
    cin >> raiseAmount;

    try {
        Employee& emp = db.getEmployeeByNumber(employeeNumber);
        emp.promote(raiseAmount);
    } catch (const std::logic_error& exception) {
        cerr << "Unable to promote employee: " << exception.what() << endl;
    }
}

void generateNewDatabase(Database& db) {

    vector<string> firstNames = readData("./names/firstnames.txt");
    vector<string> middleNames = readData("./names/middlenames.txt");
    vector<string> lastNames = readData("./names/lastnames.txt");
    vector<string> numbers = readData("./names/numbers.txt");
    vector<string> streetNames = readData("./names/streetnames.txt");
    vector<string> cities = readData("./names/cities.txt");

    // generate 8000 names
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            for (int k = 0; k < 20; k++) {
                string address = numbers[k] + " " + streetNames[j] + " " + cities[i];
                db.addEmployee(firstNames[i], lastNames[k], middleNames[j], address);
            }
        }
    }

    cout << "8000 employees have been created and added to database. \n" << endl;
}

vector<string> readData(string filename) {
    vector<string> names;
    ifstream nameFile(filename);
    if (!nameFile.is_open()) {
        throw runtime_error {"Error while opening file."};
    }
    string line;
    while ( getline (nameFile, line) ) {
        names.push_back(line);
    }

    return names;
}



void doSave(Database& db) {
    string filename;
    string overwritting;

    cout << "filename? ";
    cin >> filename;
    cout << "overwritting? 1 for YES and others for NO ";
    cin >> overwritting;

    if (overwritting == "1") {
        db.save(filename, true);
    } else {
        db.save(filename, false);
    }
}

void doLoad(Database& db) {
    string filename;

    cout << "filename? ";
    cin >> filename;

    db.load(filename);
}

void doEdit(Database& db) {
    
    string employeeNumber, address, salary, hired;
    bool ishired;

    cout << "employee number? ";
    cin >> employeeNumber;
    cout << "address? ";
    cin >> address;
    cout << "salary? ";
    cin >> salary;
    cout << "hired? 1 for YES and others for NO ";
    cin >> hired;

    if (hired == "1") {
        db.editEmployee(stoi(employeeNumber), address, stoi(salary), true);
    } else {
        db.editEmployee(stoi(employeeNumber), address, stoi(salary), false);
    }

}

void doSearch(Database& db) {
    
    string where, what;
    bool ishired;

    cout << "How to search? 1-firstname, 2-lastname, 3-middle name, 4-address: ";
    cin >> where;
    cout << "search what? ";
    cin >> what;

    if (where == "1") {
        where = "firstName";
    } else if (where == "2") {
        where = "lastName";
    } else if (where == "3") {
        where = "middleName";
    } else if (where == "4") {
        where = "address";
    } 


    cout << endl;
    auto searchResult = db.searchEmployee(what, where);
    cout << "*** Search result: ***" << endl;
    cout << "--------------------" << endl;
    cout << searchResult.size() << " employees found." << endl;
    cout << "--------------------" << endl;
    for (auto employee : searchResult) {
        employee.display();
    }

}



