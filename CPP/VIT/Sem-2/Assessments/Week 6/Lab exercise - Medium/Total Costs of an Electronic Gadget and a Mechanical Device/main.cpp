#include <iostream>
#include <iomanip>
using namespace std;

class Product {
protected:
    double cost, discount;

public:
    Product(double c, double d) : cost(c), discount(d) {}
};

class ElectronicGadget : public Product {
public:
    ElectronicGadget(double c, double d) : Product(c, d) {}

    void calcTotalE() {
        double totalCost = cost - (cost * discount);
        cout << "Electronic Cost: Rs. " << fixed << setprecision(2) << totalCost << endl;
    }
};

class MechanicalDevice : public Product {
public:
    MechanicalDevice(double c, double d) : Product(c, d) {}

    void calcTotalM() {
        double totalCost = cost - (cost * discount);
        cout << "Mechanical Cost: Rs. " << fixed << setprecision(2) << totalCost << endl;
    }
};

int main() {
    double costE, discountE, costM, discountM;
    cin >> costE >> discountE >> costM >> discountM;

    ElectronicGadget eg(costE, discountE);
    MechanicalDevice md(costM, discountM);

    eg.calcTotalE();
    md.calcTotalM();

    return 0;
}