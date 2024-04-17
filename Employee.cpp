#include <iostream>
#include "Employee.h"

using namespace std;

namespace Records {
    // constructor 
    Employee::Employee(const string& firstName, const string& lastName)
        : mFirstName(firstName)
        , mLastName(lastName)
    {
	}
	Employee::Employee(const string& firstName, 
				 const string& middleName,
				 const string& lastName,
				 const string& address)
		: mFirstName(firstName)
		, mMiddleName(middleName)
		, mLastName(lastName)
		, mAddress(address)
	{ }

    //Getters
    const string& Employee::getFirstName() const
	{
		return mFirstName;
	}

    const string& Employee::getLastName() const
	{
		return mLastName;
	}
	int Employee::getEmployeeNumber() const
	{
		return mEmployeeNumber;
	}
	int Employee::getSalary() const
	{
		return mSalary;
	}
	const string& Employee::getMiddleName() const
	{
		return mMiddleName;
	}

	const string& Employee::getAddress() const
	{
		return mAddress;
	}



    // Setters
	void Employee::setFirstName(const string& firstName)
	{
		mFirstName = firstName;
	}
	void Employee::setLastName(const string& lastName)
	{
		mLastName = lastName;
	}
	void Employee::setEmployeeNumber(int employeeNumber)
	{
		mEmployeeNumber = employeeNumber;
	}
	void Employee::setSalary(int salary)
	{
		mSalary = salary;
	}

void Employee::setMiddleName(const string& middleName)
	{
		mMiddleName = middleName;
	}

	void Employee::setAddress(const string& address)
	{
		mAddress = address;
	}
    //Other methods
    void Employee::promote(int raiseAmount)
	{
		setSalary(getSalary() + raiseAmount);
	}

	void Employee::demote(int demeritAmount)
	{
		setSalary(getSalary() - demeritAmount);
	}

	void Employee::hire()
	{
		mHired = true;
	}

	void Employee::fire()
	{
		mHired = false;
	}

	void Employee::display() const
	{
		cout << "Employee: " << getLastName() << ", " << getFirstName() << endl;
		cout << "Address: " << getAddress() << endl;
		cout << "-------------------------" << endl;
		cout << (isHired() ? "Current Employee" : "Former Employee") << endl;
		cout << "Employee Number: " << getEmployeeNumber() << endl;
		cout << "Salary: $" << getSalary() << endl;
		cout << endl;
	}

    bool Employee::isHired() const
	{
		return mHired;
	}

}
