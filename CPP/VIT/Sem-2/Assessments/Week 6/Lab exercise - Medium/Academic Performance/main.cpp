#include <iostream>
#include <iomanip>
using namespace std;

class GPA {
protected:
    double gpa;
public:
    GPA(double g) : gpa(g) {}
};

class CreditHours {
protected:
    int creditHours;
public:
    CreditHours(int ch) : creditHours(ch) {}
};

class Student : public GPA, public CreditHours {
    double attendance;
public:
    Student(double g, int ch, double a) : GPA(g), CreditHours(ch), attendance(a) {}

    void calculateGradePoints() {
        double gradePoints = gpa * creditHours;
        if (attendance > 80.0) {
            gradePoints += 5;
        }
        cout << fixed << setprecision(1) << gradePoints << endl;
    }
};

int main() {
    double gpa, attendance;
    int creditHours;
    cin >> gpa >> creditHours >> attendance;

    Student patrick(gpa, creditHours, attendance);
    patrick.calculateGradePoints();

    return 0;
}