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

    cout << "=== Test setters" << endl;
    emp.setFirstName("John");
	emp.setLastName("Doe");
	emp.setEmployeeNumber(71);
    emp.setSalary(50000);
    cout << "First Name: " << emp.getFirstName() << "\n"
         << "Last Name: " << emp.getLastName() << "\n"
         << "Employee Number: " << emp.getEmployeeNumber() << "\n"
         << "Salary: " << emp.getSalary()
         << endl;
    cout << endl;

    cout << "=== Test hire related methods" << endl;
    cout << "-- Default isHired value" << endl;
    cout << "Is hired: " << emp.isHired() << endl;
    cout << "-- Hire this employee" << endl;
    emp.hire();
    cout << "Is hired: " << emp.isHired() << endl;
    cout << "-- Fire this employee" << endl;
    emp.fire();
    cout << "Is hired: " << emp.isHired() << endl;
    cout << "-- Hire this employee again" << endl;
    emp.hire();
    cout << "Is hired: " << emp.isHired() << endl;
    cout << endl;

    cout << "=== Test display methods" << endl;
    emp.display();
    cout << "-- Fire this employee" << endl;
    emp.fire();
    emp.display();
    cout << "-- Hire this employee again" << endl;
    emp.hire();
    emp.display();

    cout << "=== Test promote method" << endl;
    cout << "-- Promote this employee" << endl;
    emp.promote(1000);
    emp.display();

    return 0;

}