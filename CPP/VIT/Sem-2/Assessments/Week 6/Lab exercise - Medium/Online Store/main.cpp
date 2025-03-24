#include <iostream>
#include <iomanip>
using namespace std;

class Product {
protected:
    string name;
    double price;
    int quantity;
public:
    Product(string n, double p, int q) : name(n), price(p), quantity(q) {}
    double calculateCost() {
        return price * quantity;
    }
};

class Electronics : public Product {
public:
    Electronics(string n, double p, int q) : Product(n, p, q) {}
    double calculateElecCost() {
        double cost = calculateCost();
        if (quantity >= 3) cost *= 0.9;
        return cost;
    }
};

class Clothing : public Product {
public:
    Clothing(string n, double p, int q) : Product(n, p, q) {}
    double calculateClothCost() {
        double cost = calculateCost();
        if (quantity >= 5) cost *= 0.95;
        return cost;
    }
};

class OrderCalculator : public Electronics, public Clothing {
public:
    OrderCalculator(string elecName, double elecPrice, int elecQty, string clothName, double clothPrice, int clothQty)
        : Electronics(elecName, elecPrice, elecQty), Clothing(clothName, clothPrice, clothQty) {}

    double calculateTotalCost() {
        return calculateElecCost() + calculateClothCost();
    }
};

int main() {
    string elecName, clothName;
    double elecPrice, clothPrice;
    int elecQty, clothQty;

    cin >> elecName >> elecPrice >> elecQty;
    cin >> clothName >> clothPrice >> clothQty;

    OrderCalculator order(elecName, elecPrice, elecQty, clothName, clothPrice, clothQty);

    cout << fixed << setprecision(2);
    cout << "Total Order Cost: Rs. " << order.calculateTotalCost() << endl;

    return 0;
}