#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "Eating...\n";
    }
};

// Derived class
class Dog : public Animal {
public:
    void bark() {
        cout << "Barking...\n";
    }
};

int main() {
    Dog d;
    d.eat();  // Inherited function
    d.bark(); // Function of Dog class
    return 0;
}
