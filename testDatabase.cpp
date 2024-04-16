#include <iostream>
#include "Database.h"

using namespace std;
using namespace Records;

int main()
{   
    cout << "*** Test Database class ***" << endl;

    // Test Database class addEmloyee and getEmployee methods
    cout << "=== Test addEmployee method ===" << endl;
    Database myDB;
	Employee& emp1 = myDB.addEmployee("Greg", "Wallis");
    emp1.fire();
	Employee& emp2 = myDB.addEmployee("Marc", "White");
    emp2.setSalary(100000);
	Employee& emp3 = myDB.addEmployee("John", "Doe");
    emp3.setSalary(10000);
    emp3.promote();

    cout << "=== Test getEmployee method ===" << endl;
    cout << "-- Get employee named as 'Jone Doe' " << endl;
    try {
        Employee emp = myDB.getEmployee("John", "Doe");
        emp.display();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    cout << "-- Get employee named as 'Mia Zhong' " << endl;
    try {
        Employee emp = myDB.getEmployee("Mia", "Zhong");
        emp.display();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }


    // Test Database class display methods
    cout << endl;
    cout << "=== Test display methods ===" << endl;
	cout << "all employees: " << endl << endl;
    myDB.displayAll();
    
	cout << endl << "current employees: " << endl << endl;
    myDB.displayCurrent();
    
	cout << endl << "former employees: " << endl << endl;
    myDB.displayFormer();
    
	return 0;
}