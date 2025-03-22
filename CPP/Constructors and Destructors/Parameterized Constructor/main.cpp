#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int year;

    // Constructor with parameters
    Car(string b, int y) {
        brand = b;
        year = y;
    }

    void display() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car car1("Tesla", 2022);
    car1.display();
    return 0;
}
