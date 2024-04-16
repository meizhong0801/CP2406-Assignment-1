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

    cout << "=== Test default constructor" << endl;
    Records::Employee emp;
    cout << "-- default values" << endl;
    cout << "First Name: " << emp.getFirstName() << "\n"
         << "Last Name: " << emp.getLastName() << "\n"
         << "Employee Number: " << emp.getEmployeeNumber() << "\n"
         << "Salary: " << emp.getSalary() << "\n"
         << "IsHired: " << emp.isHired()
         << endl;
    cout << endl;


    return 0;

}