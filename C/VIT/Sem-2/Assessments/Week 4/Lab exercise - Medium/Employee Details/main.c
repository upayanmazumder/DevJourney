#include <stdio.h>

struct Employee {
    char name[50];
    double current_salary;
    int hours_worked;
    double salary_increase, final_salary, monthly_salary;
};

double calculate_salary_increase(int hours_worked) {
    if (hours_worked >= 12) {
        return 150.00;
    } else if (hours_worked >= 10) {
        return 100.00;
    } else if (hours_worked >= 8) {
        return 50.00;
    } else {
        return 0.00;
    }
}

double calculate_final_salary(double current_salary, double salary_increase) {
    return current_salary + salary_increase;
}

double calculate_monthly_salary(double final_salary) {
    return final_salary * 30;
}

int main() {
    struct Employee emp;
    scanf("%s", emp.name);
    scanf("%lf", &emp.current_salary);
    scanf("%d", &emp.hours_worked);
    emp.salary_increase = calculate_salary_increase(emp.hours_worked);
    emp.final_salary = calculate_final_salary(emp.current_salary, emp.salary_increase);
    emp.monthly_salary = calculate_monthly_salary(emp.final_salary);
    printf("Final Salary: $%.2f\n", emp.final_salary);
    printf("Total Salary: $%.2f\n", emp.monthly_salary);
}