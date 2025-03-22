#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int year;

    // Parameterized Constructor
    Car(string b, int y) {
        brand = b;
        year = y;
    }

    // Copy Constructor
    Car(const Car &obj) {
        brand = obj.brand;
        year = obj.year;
    }

    void display() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car car1("Tesla", 2022);
    Car car2 = car1;  // Copying car1 into car2

    car1.display();
    car2.display();
    return 0;
}
    