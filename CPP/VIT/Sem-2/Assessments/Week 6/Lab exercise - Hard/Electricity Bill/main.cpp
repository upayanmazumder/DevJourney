#include <iostream>
#include <iomanip>
using namespace std;

class Consumption {
protected:
    double units;
public:
    Consumption(double u) : units(u) {}
};

class Rate {
protected:
    double residentialRate, commercialRate;
public:
    Rate(double r, double c) : residentialRate(r), commercialRate(c) {}
};

class ConnectionType {
protected:
    string type;
public:
    ConnectionType(string t) : type(t) {}
};

class ElectricityBill : public Consumption, public Rate, public ConnectionType {
public:
    ElectricityBill(double u, double r, double c, string t) 
        : Consumption(u), Rate(r, c), ConnectionType(t) {}

    void calculateTotalCost() {
        double cost = (type == "residential") ? (units * residentialRate) : (units * commercialRate);
        cout << fixed << setprecision(2) << cost << endl;
    }
};

int main() {
    double units, residentialRate, commercialRate;
    string type;
    
    cin >> units >> residentialRate >> commercialRate >> type;
    
    ElectricityBill bill(units, residentialRate, commercialRate, type);
    bill.calculateTotalCost();

    return 0;
}