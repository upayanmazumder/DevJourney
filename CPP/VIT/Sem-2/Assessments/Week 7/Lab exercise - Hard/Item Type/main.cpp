#include <iostream>
#include <iomanip>
using namespace std;

class ItemType {
public:
    virtual double calculateAmount() = 0;
};

class Wooden : public ItemType {
private:
    int numberOfItems;
    double cost;

public:
    Wooden(int n, double c) : numberOfItems(n), cost(c) {}

    double calculateAmount() override {
        return numberOfItems * cost;
    }
};

class Electronics : public ItemType {
private:
    double cost;

public:
    Electronics(double c) : cost(c) {}

    double calculateAmount() override {
        return cost * 0.8;
    }
};

int main() {
    int choice;
    cin >> choice;

    if (choice == 1) {
        int numItems;
        double cost;
        cin >> numItems >> cost;
        Wooden w(numItems, cost);
        cout << fixed << setprecision(2) << w.calculateAmount() << endl;
    } else if (choice == 2) {
        double cost;
        cin >> cost;
        Electronics e(cost);
        cout << fixed << setprecision(2) << e.calculateAmount() << endl;
    }

    return 0;
}