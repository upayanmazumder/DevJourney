#include <iostream>
using namespace std;

class Car {
private:
    string brand;  // Not accessible outside the class

public:
    int year;

    void setBrand(string b) {
        brand = b;
    }
    void display() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car car1;
    car1.year = 2022;
    car1.setBrand("Tesla");

    car1.display();
    return 0;
}
