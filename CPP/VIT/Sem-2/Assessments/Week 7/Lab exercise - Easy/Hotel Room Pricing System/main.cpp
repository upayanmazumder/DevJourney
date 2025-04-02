#include <iostream>

using namespace std;

class Hotel {
public:
    virtual int calculatePrice(int nights, int guests) = 0;
    virtual ~Hotel() {}
};

class SingleRoom : public Hotel {
public:
    int calculatePrice(int nights, int guests) override {
        int baseCost = nights * 100;
        if (nights > 5) {
            return baseCost * 0.9;
        }
        return baseCost + 15;
    }
};

class DoubleRoom : public Hotel {
public:
    int calculatePrice(int nights, int guests) override {
        int baseCost = nights * 150;
        if (nights > 5) {
            return baseCost * 0.9;
        }
        return baseCost + 15;
    }
};

int main() {
    int n, p;
    cin >> n >> p;

    SingleRoom single;
    DoubleRoom dbl;

    cout << "Single Room Cost: " << single.calculatePrice(n, p) << " ";
    cout << "\nDouble Room Cost: " << dbl.calculatePrice(n, p);

    return 0;
}