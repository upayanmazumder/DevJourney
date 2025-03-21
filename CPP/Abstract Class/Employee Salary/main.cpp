#include <iostream>
using namespace std;

class Employee {
public:
    virtual double calculateSalary() = 0; // Pure virtual function
};

class FullTimeEmployee : public Employee {
public:
    double calculateSalary() override { return 50000; }
};

class PartTimeEmployee : public Employee {
public:
    double calculateSalary() override { return 20000; }
};

int main() {
    FullTimeEmployee fte;
    PartTimeEmployee pte;

    cout << "Full-Time Salary: " << fte.calculateSalary() << endl;
    cout << "Part-Time Salary: " << pte.calculateSalary() << endl;

    return 0;
}
