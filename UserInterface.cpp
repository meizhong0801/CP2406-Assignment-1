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
int displayLoginMenu();
int login(UserDatabase& userDB);

int main(){
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
