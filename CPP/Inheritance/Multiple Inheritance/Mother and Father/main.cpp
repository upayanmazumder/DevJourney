#include <iostream>
using namespace std;

// Base class 1
class Father {
public:
    void fatherTraits() {
        cout << "Tall height\n";
    }
};

// Base class 2
class Mother {
public:
    void motherTraits() {
        cout << "Brown eyes\n";
    }
};

// Derived class
class Child : public Father, public Mother {};

int main() {
    Child obj;
    obj.fatherTraits();
    obj.motherTraits();
    return 0;
}
