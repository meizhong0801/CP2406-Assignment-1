#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <string>

namespace Records {
    const int kDefaultStartingSalary = 30000;
    class Employee{
    
        public:
            // constructor
            Employee() = default;
            Employee(const std::string& firstName, const std::string& lastName);

            // Getters
            const std::string& getFirstName() const;
            const std::string& getLastName() const;
            int getEmployeeNumber() const;
            int getSalary() const;

            // Setters
            void setFirstName(const std::string& firstName);
            void setLastName(const std::string& lastName);
            void setEmployeeNumber(int employeeNumber);
            void setSalary(int newSalary);

            // Other methods
            void promote(int raiseAmount = 1000);
            void demote(int demeritAmount = 1000);
            void hire(); // Hires or rehires the employee
            void fire(); // Dismisses the employee
            void display() const;// Outputs employee info to console
            bool isHired() const;

        private:
            std::string mFirstName;
            std::string mLastName;
            int mEmployeeNumber = -1;
            int mSalary = kDefaultStartingSalary;
            bool mHired = false;

    };

}

#endif