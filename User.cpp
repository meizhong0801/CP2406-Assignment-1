#include "User.h"
#include <iostream>

using namespace std;

namespace Records {
    User::User(const string& userName, const string& password)
        : mUserName (userName)
        , mPassword (password)
    { }

    User::User(const string& userName, const string& password, const string& level)
        : mUserName (userName)
        , mPassword (password)
        , mLevel (level)
    { }

    // Getters and setters
	void User::setUserID(int id)
	{
		mUserID = id;
	}

	int User::getUserID() const
	{
		return mUserID;
	}


    void User::setUserName(const string& userName) {
        mUserName = userName;
    }

    const string& User::getUserName() const {
        return mUserName;
    }

     void User::setPassword(const string& password) {
        mPassword = password;
    }

    const string& User::getPassword() const {
        return mPassword;
    }

    void User::setLevel(const string& level) {
        mLevel = level;
    }
    
    const string& User::getLevel() const {
        return mLevel;
    }

    void User::setEmployeeNumber(int employeeNumber) {
        mEmployeeNumber = employeeNumber;
    }
    
    int User::getEmployeeNumber() const {
        return mEmployeeNumber;
    }


    void User::display() const {
        cout << "User: " << getUserID() 
             << ", Username: " << getUserName()
             << ", password: " << getPassword()
             << ", Level: " << getLevel()
             << ", EmpNum: " << getEmployeeNumber()
             << endl;
    }

}