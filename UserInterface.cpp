#include <iostream>
#include <stdexcept>
#include <exception>
#include "Database.h"
#include "UserDatabase.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;
using namespace Records;

// declare functions
// int displayMenu();
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

int displayLoginMenu();
int login(UserDatabase& userDB);
int displayManagerMenu();
int displayEmployeeMenu();

void doUserCreate(UserDatabase& userDB);
void doUserEdit(UserDatabase& userDB);
void doUserDelete(UserDatabase& userDB);
void doUserDatebaseSave(UserDatabase& userDB);
void doUserDatabaseLoad(UserDatabase& userDB);


int main() {
    Database employeeDB;
    employeeDB.load("employee2.db");
    UserDatabase userDB;
    // load data from user.db
    userDB.load("user2.db");
    
    // User login
    int userID;
    bool loginDone = false;
    while (!loginDone) {
        int selection = displayLoginMenu();
		switch (selection) {
		case 0:
			loginDone = true;
			break;
		case 1:
			userID = login(userDB);
            if (userID > 0) {
                loginDone = true;
            } else {
                cout << "Wrong user name or password. Plesae try again!" << endl;
            }
			break;
        }
    }

    if (userID < 1 ) {
        return 0;
    }

    // check user level
    string userLevel = userDB.findUserLevel(userID);
    if (userLevel == "Manager") {
        bool done = false;
        while (!done) {
            int selection = displayManagerMenu(); 
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
            case 12:
                doUserCreate(userDB);
                break;
            case 13:
                doUserEdit(userDB);
                break;
            case 14:
                doUserDelete(userDB);
                break;
            case 15:
                doUserDatebaseSave(userDB);
                break;
            case 16:
                doUserDatabaseLoad(userDB);
                break;
            case 17:
                userDB.displayAll();
                break;

            default:
                cerr << "Unknown command." << endl;
                break;
            }
        }        
    }
    else {
        User& theUser = userDB.findUser(userID);
        int employeeNumber = theUser.getEmployeeNumber();
        Employee& theEmployee = employeeDB.getEmployee(employeeNumber);
        bool done = false;
        while (!done) {
            int selection = displayEmployeeMenu(); 
            switch (selection) {
            case 0:
                done = true;
                break;
            case 1:
                theEmployee.display();
                break;
            case 2:
                theUser.display();
                break;
            default:
                cerr << "Unknown command." << endl;
                break;
            }
        }
    }

    return 0;
}

int displayLoginMenu() {
    // Note:
	//		One important note is that this code assumes that the user will
	//		"play nice" and type a number when a number is requested.
	//		When you read about I/O in Chapter 13, you will learn how to
	//		protect against bad input.

    int selection;

    cout << "User Database login" << endl;
    cout << "-----------------" << endl;
    cout << "1) Login" << endl;
    cout << "0) quit" << endl;
    cout << "---> ";

    cin >> selection;

    return selection;
}

int login(UserDatabase& userDB) {
    string userName;
    string password;

    cout << "User Name? ";
    cin >> userName;
    cout << "Password? ";
    cin >> password;

    int userID = userDB.checkUser(userName, password);

    return userID;
}

int displayManagerMenu() {
    // Note:
	//		One important note is that this code assumes that the user will
	//		"play nice" and type a number when a number is requested.
	//		When you read about I/O in Chapter 13, you will learn how to
	//		protect against bad input.

    int selection;

    cout << endl;
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
    cout << "User Database" << endl;
    cout << "-----------------" << endl;
    cout << "12) Create a user" << endl;
    cout << "13) Edit a user" << endl;
    cout << "14) Delete a user" << endl;
    cout << "15) Save to file" << endl;
    cout << "16) Load from file" << endl;
    cout << "17) List all users" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "---> ";

    cin >> selection;

    return selection;
}



int displayEmployeeMenu() {
    // Note:
	//		One important note is that this code assumes that the user will
	//		"play nice" and type a number when a number is requested.
	//		When you read about I/O in Chapter 13, you will learn how to
	//		protect against bad input.

    int selection;

    cout << endl;
    cout << "Employee Database" << endl;
    cout << "-----------------" << endl;
    cout << "1) Display your record" << endl;
    cout << "User Database" << endl;
    cout << "-----------------" << endl;
    cout << "2) Display your user info" << endl;
    cout << "0) Quit" << endl;

    cout << endl;
    cout << "---> ";

    cin >> selection;

    return selection;
}


// User database related.
void doUserCreate(UserDatabase& userDB) {
    string userName, password, level, employeeNumber;
    cout << "Username? ";
    cin >> userName;
    cout << "Password? ";
    cin >> password;
    cout << "Level? ";
    cin >> level;
    cout << "Employee Number? ";
    cin >> employeeNumber;

    userDB.createUser(userName, password, level, stoi(employeeNumber));
}

void doUserEdit(UserDatabase& userDB) {
    string userID, newUserName, newPassword;
    cout << "User ID? ";
    cin >> userID;
    cout << "New user name? ";
    cin >> newUserName;
    cout << "New password? ";
    cin >> newPassword;

    userDB.editUser(stoi(userID), newUserName, newPassword);
}

void doUserDelete(UserDatabase& userDB) {
    string userID;
    cout << "User ID? ";
    cin >> userID;

    userDB.deleteUser(stoi(userID));
}

void doUserDatebaseSave(UserDatabase& userDB) {
    string filename;
    string overwritting;

    cout << "filename? ";
    cin >> filename;
    cout << "overwritting? 1 for YES and others for NO ";
    cin >> overwritting;

    if (overwritting == "1") {
        userDB.save(filename, true);
    } else {
        userDB.save(filename, false);
    }
}

void doUserDatabaseLoad(UserDatabase& userDB) {
    string filename;

    cout << "filename? ";
    cin >> filename;

    userDB.load(filename);
}


// Employee Database related
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

    cout << "How to search? 1: firstname, 2: lastname, 3: middle name, 4: address: ";
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
