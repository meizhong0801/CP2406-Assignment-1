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
    cout << "-- Get employee by employee number 1000 " << endl;
    try {
        Employee emp = myDB.getEmployee(1000);
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

    cout << endl;
    cout << "=== Test addEmployee method ===" << endl;
	myDB.addEmployee("Greg", "Wallis", "Mn1", "address");
    myDB.displayAll();

    cout << endl;
    cout << "=== Test save method ===" << endl;
    cout << "--- Test overwritting" << endl;
    try {
        myDB.save("employee.db", true);
        myDB.displayAll();
    } catch (const exception e) {
        cout << e.what() << endl;
    }
    // cout << "--- Test append" << endl;
    // try {
    //     myDB.save("employee.db", false);
    //     myDB.displayAll();
    // } catch (const exception e) {
    //     cout << e.what() << endl;
    // }

    cout << endl;
    cout << "=== Test load method === " << endl;
    Database myDB1;
    myDB1.load("employee.db");
    myDB1.displayAll();

    cout << endl;
    cout << "=== Test editEmployee method === " << endl;
    Database myDB2;
    myDB2.addEmployee("Greg", "Wallis", "mName", "address1");
    cout << "--- Initial status: " << endl;
    myDB2.displayAll();
    myDB2.editEmployee(1000, "address200", 45000, false);
    cout << "--- After edit: " << endl;
    myDB2.displayAll();

    cout << endl;
    cout << "=== Test searchEmployee method === " << endl;
    myDB.addEmployee("mia", "Smith", "middle", "000000");
    myDB.addEmployee("mia", "Smarth", "middle", "000000");
    myDB.addEmployee("mia", "aasm", "middle", "000000");
    myDB.addEmployee("mia", "1sm", "middle", "000000");
    cout << "--- All employees: " << endl;
    myDB.displayAll();
    cout << endl;
    cout << "*** Search result: ***" << endl;
    auto searchResult = myDB.searchEmployee("Sm", "lastName");
    cout << "--------------------" << endl;
    cout << searchResult.size() << " employees found." << endl;
    cout << "--------------------" << endl;
    for (auto employee : searchResult) {
        employee.display();
    }
    
	return 0;
}