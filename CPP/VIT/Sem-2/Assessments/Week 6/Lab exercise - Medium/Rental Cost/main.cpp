#include <iostream>
#include <iomanip>
using namespace std;

class Vehicle {
protected:
    double dailyRate;
public:
    Vehicle(double rate) : dailyRate(rate) {}
    virtual double calculateRentalCost(int days) = 0;
};

class Car : public Vehicle {
public:
    Car(double rate) : Vehicle(rate) {}
    double calculateRentalCost(int days) override {
        return dailyRate * days;
    }
};

class Motorcycle : public Vehicle {
public:
    Motorcycle(double rate) : Vehicle(rate) {}
    double calculateRentalCost(int days) override {
        return dailyRate * days * 0.8;
    }
};

int main() {
    double carRate, bikeRate;
    int carDays, bikeDays;

    cin >> carRate >> bikeRate >> carDays >> bikeDays;

    Car car(carRate);
    Motorcycle bike(bikeRate);

    cout << fixed << setprecision(2);
    cout << "Total rental cost for the car: " << car.calculateRentalCost(carDays) << endl;
    cout << "Total rental cost for the motorcycle: " << bike.calculateRentalCost(bikeDays) << endl;

    return 0;
}