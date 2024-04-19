#ifndef _USERDATABASE_H
#define _USERDATABASE_H

#include <vector>
#include "User.h"

using namespace std;

namespace Records {
    const int kFirstUserID = 1;
    
    class UserDatabase {
        public:
            User& createUser(const string& username, const string& password);
            User& createUser(const string& username, const string& password, const string& level);
            User& createUser(const string& username, const string& password, const string& level, int employeeNumber);
            User& createUser(int userID, const string& username, const string& password, const string& level, int employeeNumber);
            void displayAll() const;
            void editUser(int userID, const string& username, const string& password);
            void deleteUser(int userID);
            void save(const string& filename, bool isOverwriting) const;
            void load(const string& filename);
            int checkUser(const string& username, const string& password) const;
            string findUserLevel(int userID) const;
            void setNextUserID(int userID);
            User& findUser(int userID);
        private:
            vector<User> mUsers;
            int mNextUserID = kFirstUserID;
    };

}

#endif