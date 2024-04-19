#include <iostream>
#include "UserDatabase.h"

using namespace std;
using namespace Records;

int main() {

    UserDatabase myDB;
    
    cout << "=== Test User related method ===" << endl;
    cout << "=== Test createUser method ===" << endl;
	User& user1 = myDB.createUser("Mia1", "11111");
    user1.display();
    User& user2 = myDB.createUser("Mia2", "22222", "Manager");
    user2.display();
    User& user3 = myDB.createUser("Mia3", "22222", "Manager", 1000);
    user3.display();
    User& user4 = myDB.createUser(10, "Mia4", "22222", "Manager", 1000);
    user4.display();
    cout << endl;
    
    cout << "=== Test displayAll method ===" << endl;
    myDB.displayAll();
    cout << endl;

    cout << "=== Test save method ===" << endl;
    cout << "--- Test overwritting" << endl;
    try {
        myDB.save("user.db", true);
        cout << "Saved to user.db, overwritting." << endl;
    } catch (const exception e) {
        cout << e.what() << endl;
    }

    cout << "--- Test append" << endl;
    try {
        myDB.save("user.db", false);
        cout << "Saved to user.db, append." << endl;
    } catch (const exception e) {
        cout << e.what() << endl;
    }

    cout << endl;
    cout << "=== Test load method === " << endl;
    UserDatabase myDB1;
    myDB1.load("user2.db");
    myDB1.displayAll();

    cout << "=== Test editUser method === " << endl;
    myDB1.editUser(1, "new name", "newPassword");
    myDB1.displayAll();

    cout << "=== Test deleteUser method === " << endl;
    myDB1.deleteUser(1);
    myDB1.displayAll();

    cout << endl;
    cout << "=== Test checkUser method ===" << endl;
    if (myDB1.checkUser("Mia1", "22222") > 0) {
        cout << "Successful!" << endl;
    } else {
        cout << "Fail" << endl;
    }
    if (myDB1.checkUser("Mia", "22222") > 0) {
        cout << "Successful!" << endl;
    } else {
        cout << "Fail" << endl;
    }
    if (myDB1.checkUser("Mia", "Zhong1") > 0) {
        cout << "Successful!" << endl;
    } else {
        cout << "Fail" << endl;
    }

    cout << endl;
    cout << "=== Test findUser method ===" << endl;
    auto level = myDB1.findUserLevel(2);
    
    cout << "User level: " << level << endl;

    
    return 0;
}