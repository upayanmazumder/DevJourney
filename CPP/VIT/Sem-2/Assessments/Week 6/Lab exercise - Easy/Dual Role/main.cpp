#include <iostream>
#include <iomanip>
using namespace std;

class Person {
public:
    string name;
    int age;
    Person(string n, int a) : name(n), age(a) {}
};

class Student : virtual public Person {
public:
    Student(string n, int a) : Person(n, a) {}
    double calculateStipend() { return age * 100.0; }
};

class Employee : virtual public Person {
public:
    Employee(string n, int a) : Person(n, a) {}
    double calculateSalary() { return age * 500.0; }
};

class TeachingAssistant : public Student, public Employee {
public:
    TeachingAssistant(string n, int a) : Person(n, a), Student(n, a), Employee(n, a) {}
    void displayIncome(char type) {
        if (type == 'S') 
            cout << name << "'s Income: Rs. " << fixed << setprecision(2) << calculateStipend() << endl;
        else if (type == 'E') 
            cout << name << "'s Income: Rs. " << fixed << setprecision(2) << calculateSalary() << endl;
        else 
            cout << "Invalid status!" << endl;
    }
};

int main() {
    string name;
    int age;
    char type;
    cin >> name >> age >> type;
    TeachingAssistant obj(name, age);
    obj.displayIncome(type);
}