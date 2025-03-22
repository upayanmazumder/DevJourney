#include <stdio.h>

struct Employee {
    int empId;
    union {
        int salary;
        int hourlyWage;
    } pay;
};

int main() {
    struct Employee e1;
    e1.empId = 101;
    e1.pay.salary = 50000;

    printf("Employee ID: %d\n", e1.empId);
    printf("Salary: %d\n", e1.pay.salary);
    
    return 0;
}
