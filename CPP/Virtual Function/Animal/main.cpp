#include <iostream>
using namespace std;

class Animal {
    public:    
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
    void speak() override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
    void speak() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->speak(); // Output: Dog barks
    animal2->speak(); // Output: Cat meows

    delete animal1;
    delete animal2;

    return 0;
}