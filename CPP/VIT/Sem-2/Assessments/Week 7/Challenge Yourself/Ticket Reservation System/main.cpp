#include <iostream>
#include <iomanip>

using namespace std;

class Reservation {
protected:
    double price;
    int age, quantity;

public:
    Reservation(double p, int a, int q) : price(p), age(a), quantity(q) {}

    virtual double calculate() const = 0;

    virtual ~Reservation() {}
};

class VIP : public Reservation {
public:
    VIP(double p, int a, int q) : Reservation(p, a, q) {}

    double calculate() const override {
        double discount = 0.0;
        if (age >= 4 && age <= 12)
            discount = 0.21;
        else if (age >= 13 && age <= 25)
            discount = 0.15;
        else if (age >= 26 && age <= 64)
            discount = 0.10;
        return quantity * price * (1 - discount);
    }
};

class Standard : public Reservation {
public:
    Standard(double p, int a, int q) : Reservation(p, a, q) {}

    double calculate() const override {
        double discount = 0.0;
        if (age >= 4 && age <= 12)
            discount = 0.18;
        else if (age >= 13 && age <= 25)
            discount = 0.14;
        else if (age >= 26 && age <= 64)
            discount = 0.05;
        return quantity * price * (1 - discount);
    }
};

int main() {
    double vipPrice, stdPrice;
    int vipAge, stdAge, vipQty, stdQty;

    cin >> vipPrice >> vipAge >> vipQty;
    cin >> stdPrice >> stdAge >> stdQty;

    VIP vipReservation(vipPrice, vipAge, vipQty);
    Standard stdReservation(stdPrice, stdAge, stdQty);

    cout << fixed << setprecision(2);
    cout << "VIP ticket price: Rs." << vipReservation.calculate() << endl;
    cout << "Standard ticket price: Rs." << stdReservation.calculate() << endl;

    return 0;
}