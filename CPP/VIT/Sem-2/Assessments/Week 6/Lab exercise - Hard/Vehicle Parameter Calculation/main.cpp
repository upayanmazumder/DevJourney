#include <iostream>
#include <iomanip>
using namespace std;

class Vehicle {
protected:
    double fuelEfficiency, maxCapacity;
public:
    Vehicle(double fe, double mc) : fuelEfficiency(fe), maxCapacity(mc) {}
};

class Car : public Vehicle {
public:
    Car(double fe, double mc) : Vehicle(fe, mc) {}

    double calculateMaxRange() {
        return fuelEfficiency * maxCapacity;
    }
};

class EmilyCar : public Car {
public:
    EmilyCar(double fe, double mc) : Car(fe, mc) {}

    double calculatePayloadCapacity() {
        return 0.8 * maxCapacity;
    }

    double calculateFullyLoadedWeight() {
        return calculatePayloadCapacity() + calculateMaxRange();
    }

    void displayCalculations() {
        cout << fixed << setprecision(2);
        cout << "Maximum Range: " << calculateMaxRange() << " km" << endl;
        cout << "Payload Capacity: " << calculatePayloadCapacity() << " kg" << endl;
        cout << "Fully loaded Weight: " << calculateFullyLoadedWeight() << " kg" << endl;
    }
};

int main() {
    double fuelEfficiency, maxCapacity;
    cin >> fuelEfficiency >> maxCapacity;

    EmilyCar car(fuelEfficiency, maxCapacity);
    car.displayCalculations();

    return 0;
}