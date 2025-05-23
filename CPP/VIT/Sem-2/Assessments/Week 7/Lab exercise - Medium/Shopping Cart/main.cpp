#include <iostream>
#include <iomanip>
using namespace std;

double calculateTotalPrice(double price) {
    return price;
}

double calculateTotalPrice(double price, int quantity) {
    return price * quantity;
}

double calculateTotalPrice(double price, int quantity, double discount) {
    return (price * quantity) * ((100 - discount) / 100.0);
}

int main() {
    int choice;
    while (cin >> choice) {
        if (choice == 1) {
            double price;
            cin >> price;
            cout << fixed << setprecision(2) << calculateTotalPrice(price) << endl;
        } else if (choice == 2) {
            double price;
            int quantity;
            cin >> price >> quantity;
            cout << fixed << setprecision(2) << calculateTotalPrice(price, quantity) << endl;
        } else if (choice == 3) {
            double price, discount;
            int quantity;
            cin >> price >> quantity >> discount;
            cout << fixed << setprecision(2) << calculateTotalPrice(price, quantity, discount) << endl;
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}