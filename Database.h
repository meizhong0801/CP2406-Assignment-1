#ifndef _DATABASE_H
#define _DATABASE_H

#include "Employee.h"
#include <string>
#include <vector>

namespace Records {
    const int kFirstEmployeeNumber = 1000;
    class Database {
        public:
            Employee& addEmployee(const std::string& firstName,
                                  const std::string& LastName);
            Employee& getEmployee(int employeeNumber);
            Employee& getEmployee(const std::string& firstName,
                                  const std::string& LastName);
            Employee& getEmployeeByNumber(const int employeeNumber);
            void displayAll() const;
            void displayCurrent() const;
            void displayFormer() const;

        private: 
            std::vector<Employee> mEmployees;
            int mNextEmployeeNumber = kFirstEmployeeNumber;
    };

}

#endif