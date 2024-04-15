#include "Employee.h"
#include <iostream>

using namespace std;

int main() {
    cout << "*** Testing the Employee class. ***" << endl;

    cout << "=== Test constructor with parameters" << endl;
    Records::Employee emp1("John", "Doe");
    cout << "First Name: " << emp1.getFirstName() << "\n"
         << "Last Name: " << emp1.getLastName()
         << endl;
    cout << endl;


    return 0;

}