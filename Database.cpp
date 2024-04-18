#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <iomanip>
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
			outfile << employee.getEmployeeNumber() << " "
					<< quoted(employee.getFirstName()) << " "
					<< quoted(employee.getLastName()) << " "
					<< quoted(employee.getMiddleName()) << " "
					<< quoted(employee.getAddress()) << " "
					<< employee.getSalary() << " "
					<< quoted(to_string(employee.isHired()))
					<< endl;
			if(!outfile) {
				throw std::runtime_error {"Error: Fail to write to file."};
			}
		}
	}

	void Database::load(const string& filename) {
		ifstream infile(filename.data());
		if (!infile)
		{
			throw std::runtime_error {"Cannot open file."};
		}
		while (infile) {
			std::string line, employeeNumber, firstName, lastName, middleName, address, salary, hired;
			std::getline(infile, line);
			if (!infile && !infile.eof()) {
				throw std::runtime_error {"Failed to read line from file."};
			}
			
			if (!line.empty())
			{
				std::istringstream inLine{line};
				inLine >> employeeNumber 
					   >> quoted(firstName) 
					   >> quoted(lastName) 
					   >> quoted(middleName)
					   >> quoted(address)
					   >> salary
					   >> hired;
				// inLine >> first_name >> last_name >> initials;
				
				Employee theEmployee(firstName, middleName, lastName, address);
				theEmployee.setSalary(stoi(salary));
				theEmployee.setEmployeeNumber(stoi(employeeNumber));
				if (hired == "1") {
					theEmployee.hire();
				} else {
					theEmployee.fire();
				}
				mEmployees.push_back(theEmployee);
			}
		}
	}

}