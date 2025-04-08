#include <iostream>
using namespace std;

class Product {
    int number;
    float cost;
public:
    void getData(int a, float b) {
        number = a;
        cost = b;
    }
    void putData() {
        cout << "Number: " << number << ", Cost: " << cost;
    }
};

int main() {
    Product p1;
    p1.getData(1, 100.5);
    p1.putData();
    return 0;
}
