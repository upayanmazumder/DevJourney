#include <iostream>
#include <iomanip>
using namespace std;

class Student {
    int id;
    double weight;
public:
    Student(int i, double w) : id(i), weight(w) {}

    friend Student operator++(Student &s);

    void display() {
        cout << id << " " << fixed << setprecision(2) << weight << " " << endl;
    }
};

Student operator++(Student &s) {
    s.weight += 1.0;
    return s;
}

int main() {
    int id;
    double weight;
    cin >> id >> weight;

    Student student(id, weight);
    student.display();

    ++student;
    student.display();

    return 0;
}