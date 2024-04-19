#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <ctype.h>
#include "UserDatabase.h"

using namespace std;

namespace Records {

	User& UserDatabase::createUser(const string& userName, const string& password) {
		User theUser(userName, password);
		theUser.setUserID(mNextUserID++);
		mUsers.push_back(theUser);

		return mUsers[mUsers.size() - 1];
	}

	User& UserDatabase::createUser(const string& userName, const string& password, const string& level) {
		User theUser(userName, password, level);
		theUser.setUserID(mNextUserID++);
		mUsers.push_back(theUser);
		
		return mUsers[mUsers.size() - 1];
	}

	User& UserDatabase::createUser(const string& userName, const string& password, const string& level, int employeeNumber) {
		User theUser(userName, password, level);
		theUser.setUserID(mNextUserID++);
		theUser.setEmployeeNumber(employeeNumber);
		mUsers.push_back(theUser);
		
		return mUsers[mUsers.size() - 1];
	}



	User& UserDatabase::createUser(int userID, const string& userName, const string& password, const string& level, int employeeNumber) {
		User theUser(userName, password, level);
		theUser.setUserID(userID);
		theUser.setEmployeeNumber(employeeNumber);
		mUsers.push_back(theUser);
		setNextUserID(++userID);
		
		return mUsers[mUsers.size() - 1];
	}


	void UserDatabase::displayAll() const
	{
		for (const auto& user : mUsers) {
			user.display();
		}
	}

	void UserDatabase::save(const string& filename, bool isOverwriting) const 
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

		for (const auto&  user : mUsers) {
			outfile << user.getUserID() << " "
					<< quoted(user.getUserName()) << " "
					<< quoted(user.getPassword()) << " "
					<< quoted(user.getLevel()) << " "
					<< user.getEmployeeNumber() << " "
					<< endl;
			if(!outfile) {
				throw std::runtime_error {"Error: Fail to write to file."};
			}
		}
	}

	void UserDatabase::load(const string& filename) {
		// clear mUsers first.
		mUsers.clear();

		ifstream infile(filename.data());
		if (!infile)
		{
			throw std::runtime_error {"Cannot open file."};
		}
		while (infile) {
			std::string line, userID, userName, password, level, employeeNumber;
			std::getline(infile, line);
			if (!infile && !infile.eof()) {
				throw std::runtime_error {"Failed to read line from file."};
			}
			
			if (!line.empty())
			{
				std::istringstream inLine{line};
				inLine >> userID 
					   >> quoted(userName) 
					   >> quoted(password) 
					   >> quoted(level)
					   >> employeeNumber;
					  
				createUser(stoi(userID), userName, password, level, stoi(employeeNumber));
			}
		}
	}

	void UserDatabase::editUser(int userID, const string& username, const string& password) {
		for (int i = 0; i < mUsers.size(); i++) {
			if (mUsers[i].getUserID() == userID) {
				mUsers[i].setUserName(username);
				mUsers[i].setPassword(password);
			}
		}
	}

	void UserDatabase::deleteUser(int userID) {
		for (int i = 0; i < mUsers.size(); i++) {
			if (mUsers[i].getUserID() == userID) {
				// delete current employee from mEmployees vector
				mUsers.erase(mUsers.begin() + i);
			}
		}
	}

	int UserDatabase::checkUser(const string& username, const string& password) const
	{
		for (auto user : mUsers) {
			if (user.getUserName() == username && user.getPassword() == password) {
				return user.getUserID();
			}
		}
		return 0;
	}

	string UserDatabase::findUserLevel(int userID) const {
		for (auto user : mUsers) {
			if (user.getUserID() == userID) {
				return user.getLevel();
			}
		}
		return "none";
	}

	void UserDatabase::setNextUserID(int userID) {
		mNextUserID = userID;
	}

	User& UserDatabase::findUser(int userID) {
		for (auto& user : mUsers) {
			if (user.getUserID() == userID) {
				return user;
			}
		}
		throw logic_error("No employee found.");
	}

}

