// Basic Class & Object
// Create a class Person with attributes name and age. 
// Add a function display() to print the details.
// Include a constructor that initializes the name and age values, 
// and a destructor that prints "Object destroyed".

#include <iostream>
#include <cstring>
using namespace std;

class Person {
public:
    char name[30];
    int age;

    // Constructor
    Person(const char *n, int a) {
        strcpy(name, n);
        age = a;
    }

    // Destructor
    ~Person() {
        cout << "\nObject destroyed";
    }

    void display() {
        cout << "Name: " << name << "\nAge: " << age;
    }
};

int main() {
    int age;
    char name[30];
    cout << "Enter name: ";
    cin.getline(name, 30);
    cout << "Enter age: ";
    cin >> age;
    cin.ignore();

    Person p(name, age);
    p.display();

    return 0;
}