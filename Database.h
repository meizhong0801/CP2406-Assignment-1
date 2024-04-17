#ifndef _DATABASE_H
#define _DATABASE_H

#include <vector>
#include "Employee.h"

namespace Records {
    const int kFirstEmployeeNumber = 1000;

    class Database {
        public:
            Employee& addEmployee(const std::string& firstName,
                                  const std::string& lastName,
								  const std::string& middleName="",
								  const std::string& address=""); // middleName and address has default value ""
            Employee& getEmployee(int employeeNumber);
            Employee& getEmployee(const std::string& firstName,
                                  const std::string& LastName);
            void displayAll() const;
            void displayCurrent() const;
            void displayFormer() const;

        private: 
            std::vector<Employee> mEmployees;
            int mNextEmployeeNumber = kFirstEmployeeNumber;
    };
}

#endif