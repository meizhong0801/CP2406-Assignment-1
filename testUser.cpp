#include "User.h"
#include <iostream>

using namespace std;
using namespace Records;

int main() {
     cout << "*** Testing the User class. ***" << endl;
     cout << "=== Test 2 parameter constructor " << endl;
     User user("Mia0801", "11111");

     // getters
     cout << "=== Test getters " << endl;
     cout << "User name: " << user.getUserName() << "\n"
          << "Password: " << user.getPassword() << "\n"
          << "Level: " << user.getLevel() 
          << endl;
     cout << endl;

     // display
     cout << "=== Test display " << endl;
     user.display();

     cout << "=== Test 3 parameter constructor " << endl;
     User user1("Mia0801", "11111", "Manager");
     user1.display();



     // setters
     cout << "=== Test setters " << endl;
     user.setUserName("Mia2222");
     user.setPassword("00000");
     user.setLevel("Manager");
     user.setEmployeeNumber(1000);
     user.display();
     

    return 0;
}
