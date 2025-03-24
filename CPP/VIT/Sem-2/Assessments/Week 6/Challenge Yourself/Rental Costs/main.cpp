#include <iostream>
#include <iomanip>

using namespace std;

class Vehicle {
public:
    double mileageCovered;
    double fuelConsumed;

    Vehicle(double mileage, double fuel) : mileageCovered(mileage), fuelConsumed(fuel) {}
};

class Car : public Vehicle {
public:
    Car(double mileage, double fuel) : Vehicle(mileage, fuel) {}

    double calculateCarCost() {
        return 0.1 * mileageCovered + 2.0 * fuelConsumed;
    }
};

class Truck : public Vehicle {
public:
    Truck(double mileage, double fuel) : Vehicle(mileage, fuel) {}

    double calculateTruckCost() {
        return 1.5 * (0.1 * mileageCovered + 2.0 * fuelConsumed);
    }
};

class Rental : public Car, public Truck {
public:
    Rental(double carMileage, double carFuel, double truckMileage, double truckFuel)
        : Car(carMileage, carFuel), Truck(truckMileage, truckFuel) {}

    void printCosts() {
        cout << "Total Rental Cost for Car: " << fixed << setprecision(2) << calculateCarCost() << endl;
        cout << "Total Rental Cost for Truck: " << fixed << setprecision(2) << calculateTruckCost() << endl;
    }
};

int main() {
    double carMileage, carFuel, truckMileage, truckFuel;
    cin >> carMileage >> carFuel >> truckMileage >> truckFuel;
    Rental rental(carMileage, carFuel, truckMileage, truckFuel);
    rental.printCosts();
    return 0;
}