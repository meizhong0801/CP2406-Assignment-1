#ifndef _USER_H
#define _USER_H

#include <string>

using namespace std;

namespace Records {
    class User {
        public:
            // constructor
            User() = default;
            User(const string& userName, const string& password);
            User(const string& userName, const string& password, const string& level);

            // getters and setters
            void setUserID(int id);
            int getUserID() const;
            void setUserName(const string& userName);
            const string& getUserName() const;
            void setPassword(const string& password);
            const string& getPassword() const;
            void setLevel(const string& level);
            const string& getLevel() const;
            void setEmployeeNumber(int employeeNumber);
            int getEmployeeNumber() const;


            void display() const; // Outputs user info to console

        private:
            int mUserID = -1;
            string mUserName;
            string mPassword;
            string mLevel = "Employee";
            int mEmployeeNumber = -1;
    };
}

#endif