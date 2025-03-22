#include <iostream>
using namespace std;

class Grandparent {
public:
    void displayGrandparent() {
        cout << "This is Grandparent\n";
    }
};

class Parent : public Grandparent {
public:
    void displayParent() {
        cout << "This is Parent\n";
    }
};

class Child : public Parent {
public:
    void displayChild() {
        cout << "This is Child\n";
    }
};

int main() {
    Child obj;
    obj.displayGrandparent();
    obj.displayParent();
    obj.displayChild();
    return 0;
}
