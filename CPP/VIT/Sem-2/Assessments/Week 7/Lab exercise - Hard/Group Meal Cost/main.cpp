#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class MenuItem {
protected:
    vector<double> prices;

public:
    virtual double calculatePrice() = 0;
    void addPrice(double price) {
        prices.push_back(price);
    }
};

class Appetizer : public MenuItem {
public:
    double calculatePrice() override {
        double total = 0;
        for (double price : prices) {
            total += price;
        }
        return total;
    }
};

class MainCourse : public MenuItem {
public:
    double calculatePrice() override {
        double total = 0;
        for (double price : prices) {
            total += price;
        }
        return total;
    }
};

int main() {
    int n, N, M;
    cin >> n >> N >> M;

    Appetizer appetizers;
    MainCourse mainCourses;

    for (int i = 0; i < N; i++) {
        double price;
        cin >> price;
        appetizers.addPrice(price);
    }

    for (int i = 0; i < M; i++) {
        double price;
        cin >> price;
        mainCourses.addPrice(price);
    }

    double totalCost = (appetizers.calculatePrice() + mainCourses.calculatePrice()) * n;
    cout << fixed << setprecision(2) << "Rs. " << totalCost << endl;

    return 0;
}