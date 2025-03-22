#include <iostream>
using namespace std;

class Vehicle {
public:
    void start() {
        cout << "Vehicle is starting...\n";
    }
};

// Derived classes
class Car : public Vehicle {
public:
    void drive() {
        cout << "Car is driving...\n";
    }
};

class Bike : public Vehicle {
public:
    void ride() {
        cout << "Bike is riding...\n";
    }
};

int main() {
    Car c;
    Bike b;

    c.start();
    c.drive();

    b.start();
    b.ride();

    return 0;
}
