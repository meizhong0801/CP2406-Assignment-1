#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;

namespace Records {
    // Add implementation code Database class methods
    Employee& Database::addEmployee(const string& firstName,
									const string& lastName,
        							const string& middleName,
									const string& address) {
        Employee theEmployee(firstName, middleName, lastName, address);
        theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
        theEmployee.hire();
		mEmployees.push_back(theEmployee);

		return mEmployees[mEmployees.size() - 1];

    }
	// get employee by emplyee number
	Employee& Database::getEmployee(int employeeNumber)
	{
		for (auto& employee : mEmployees) {
			if (employee.getEmployeeNumber() == employeeNumber) {
				return employee;
			}
		}
		throw logic_error("No employee found.");
	}

	// get employee by emplyee firstname and last name
    Employee& Database::getEmployee(const string& firstName, const string& lastName)
	{
		for (auto& employee : mEmployees) {
			if (employee.getFirstName() == firstName &&
				employee.getLastName() == lastName) {
					return employee;
			}
		}
		throw logic_error("No employee found.");
	}

    void Database::displayAll() const
	{
		for (const auto& employee : mEmployees) {
			employee.display();
		}
	}

    void Database::displayCurrent() const
	{
		for (const auto& employee : mEmployees) {
			if (employee.isHired())
				employee.display();
		}
	}

	void Database::displayFormer() const
	{
		for (const auto& employee : mEmployees) {
			if (!employee.isHired())
				employee.display();
		}
	}

}