#include <iostream>
using namespace std;

// Base class definition
class Vehicle {
    public:
        int wheels; // Public member variable to store the number of wheels
        void honk() { // Public member function to simulate honking
            cout << "Beep Beep!" << endl;
        }
};

// Derived class definition
// The Car class inherits publicly from the Vehicle class
class Car : public Vehicle {
    public:
        string brand; // Public member variable to store the brand of the car
};

int main() {
    Car myCar; // Create an object of the Car class
    myCar.wheels = 4; // Set the number of wheels for the car
    myCar.brand = "Tesla"; // Set the brand of the car
    myCar.honk(); // Call the honk() function inherited from the Vehicle class
    return 0;
}