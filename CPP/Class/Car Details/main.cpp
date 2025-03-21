#include <iostream>
using namespace std;

class Car {   // Class declaration
public:
    string brand;
    int speed;

    void showDetails() {  // Member function
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
    }
};

int main() {
    Car myCar; // Object creation
    myCar.brand = "Toyota";
    myCar.speed = 180;
    myCar.showDetails();  // Calling member function
    return 0;
}
