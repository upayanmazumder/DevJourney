#include <iostream>
#include <iomanip>

using namespace std;

class ItemType {
public:
    virtual double calculateAmount() = 0;
    virtual ~ItemType() {}
};

class Wooden : public ItemType {
private:
    int noOfItems;
    double cost;
public:
    Wooden(int n, double c) : noOfItems(n), cost(c) {}

    double calculateAmount() override {
        return noOfItems * cost;
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
        int noOfItems;
        double cost;
        cin >> noOfItems >> cost;
        Wooden wooden(noOfItems, cost);
        cout << fixed << setprecision(2) << wooden.calculateAmount();
    } 
    else if (choice == 2) {
        double cost;
        cin >> cost;
        Electronics electronics(cost);
        cout << fixed << setprecision(2) << electronics.calculateAmount();
    } 
    else {
        cout << "Invalid choice.";
    }

    return 0;
}