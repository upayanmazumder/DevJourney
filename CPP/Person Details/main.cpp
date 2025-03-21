#include <iostream>
using namespace std;

class person {
    char name[30];
    int age;

    public:
        void getdata(void);
        void display(void);
};

void person::getdata(void) {
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
}

void person::display(void) {
    cout << "\nName: " << name;
    cout << "\nAge: " << age;
}

int main() {
    person p;
    p.getdata();
    p.display();
}