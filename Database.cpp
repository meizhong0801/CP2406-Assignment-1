#include <iostream>
#include <stdexcept>
#include <fstream>
#include <iomanip>
// #include <string_view>
// #include <sstream>
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

	void Database::save(const string& filename, bool isOverwriting) const 
	{
		ofstream outfile;
		if (isOverwriting ) {
			outfile.open(filename, ios_base::trunc);
		} else {
			outfile.open(filename, ios_base::app);
		}

		if (!outfile) {
        	throw std::runtime_error {"Error: cannot open file "};
    	}

		for (const auto&  employee : mEmployees) {
			outfile << employee.getEmployeeNumber()
					<< quoted(employee.getFirstName())
					<< quoted(employee.getLastName())
					<< quoted(employee.getMiddleName())
					<< quoted(employee.getAddress())
					<< employee.getSalary()
					<< employee.isHired()
					<< endl;
			if(!outfile) {
				throw std::runtime_error {"Error: Fail to write to file."};
			}
		}
	}

}