#include <iostream>
#include <iomanip>

using namespace std;

class Vehicle {
public:
    double fuelCapacity;

    Vehicle(double fc) : fuelCapacity(fc) {}
};

class Car : public Vehicle {
public:
    double fuelEfficiency;

    Car(double fc, double fe) : Vehicle(fc), fuelEfficiency(fe) {}

    double calculateRange() {
        return fuelCapacity * fuelEfficiency;
    }
};

class ElectricCar : public Car {
private:
    double batteryCapacity;

public:
    ElectricCar(double fc, double fe, double bc) : Car(fc, fe), batteryCapacity(bc) {}

    double calculateElectricRange() {
        return batteryCapacity * fuelEfficiency;
    }
};

int main() {
    double fuelCap, fuelEff, batteryCap, batteryEff;

    // Read input for fuel-based car
    cin >> fuelCap >> fuelEff;

    // Read input for electric car
    cin >> batteryCap >> batteryEff;

    // Create objects
    Car fuelCar(fuelCap, fuelEff);
    ElectricCar electricCar(fuelCap, batteryEff, batteryCap);

    // Print results
    cout << "Car Estimated Range: " << fixed << setprecision(1) << fuelCar.calculateRange() << " miles" << endl;
    cout << "Electric Car Estimated Range: " << fixed << setprecision(1) << electricCar.calculateElectricRange() << " miles" << endl;

    return 0;
}