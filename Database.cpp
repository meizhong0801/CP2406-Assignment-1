#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <ctype.h>
#include "Database.h"
#include "helper.cpp"

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

	Employee& Database::getEmployee(int employeeNumber) {
		for (auto& employee : mEmployees) {
			if (employee.getEmployeeNumber() == employeeNumber) {
					return employee;
			}
		}
		throw logic_error("No employee found.");
	}

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

    Employee& Database::getEmployeeByNumber(const int employeeNumber)
	{
		for (auto& employee : mEmployees) {
			if (employee.getEmployeeNumber() == employeeNumber) {
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


	void Database::editEmployee(int employeeNumber, const string& address, int salary, bool hired) {
		for (int i = 0; i < mEmployees.size(); i++) {
			if (mEmployees[i].getEmployeeNumber() == employeeNumber) {
				// Create new Employee object
				Employee newEmployee;
				newEmployee.setFirstName(mEmployees[i].getFirstName());
				newEmployee.setLastName(mEmployees[i].getLastName());
				newEmployee.setMiddleName(mEmployees[i].getMiddleName());
				newEmployee.setEmployeeNumber(mEmployees[i].getEmployeeNumber());
				newEmployee.setAddress(address);
				newEmployee.setSalary(salary);
				newEmployee.setAddress(address);
				if (hired) {
					newEmployee.hire();
				} else {
					newEmployee.fire();
				}
				
				// delete current employee from mEmployees vector
				mEmployees.erase(mEmployees.begin() + i);
				// Insert edited employee in the original position
				mEmployees.insert(mEmployees.begin() + i, newEmployee);
			}
		}
	}

	vector<Employee> Database::searchEmployee(string searchWord, const string& where) const 
	{
		vector<Employee> result ;
		string searchWordUpper = toUpper(searchWord);
		
		for (auto employee : mEmployees) {
			string whereUpper = "";
			if (toUpper(where) == "FIRSTNAME") {
				// convert firstname to uppercase
				whereUpper = toUpper(employee.getFirstName());
			} 
			else if (where == "lastName") {
				// convert to uppercase
				whereUpper = toUpper(employee.getLastName());
			} 
			else if (where == "middleName") {
				// convert to uppercase
				whereUpper = toUpper(employee.getMiddleName());
			} 
			else if (where == "address") {
				// convert to uppercase
				whereUpper = toUpper(employee.getAddress());
			} 

			if (whereUpper.find(searchWordUpper) != string::npos) {
					result.push_back(employee);
			}
		}
		return result;
	}
}