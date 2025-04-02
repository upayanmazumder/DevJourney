#include <iostream>
#include <iomanip>
using namespace std;

class Student {
protected:
    string name, rollNumber;
public:
    Student(string n, string r) : name(n), rollNumber(r) {}

    virtual void inputGrades() = 0;
    virtual void calculateGrade() = 0;

    void displayInfo() {
        cout << "Name: " << name << endl << "Roll Number: " << rollNumber << endl;
    }

    virtual ~Student() {} // Virtual destructor
};

class UndergraduateStudent : public Student {
    int midterm, finalExam;
public:
    UndergraduateStudent(string n, string r) : Student(n, r), midterm(0), finalExam(0) {}

    void inputGrades() override {
        cin >> midterm >> finalExam;
    }

    void calculateGrade() override {
        int totalGrade = (midterm + finalExam) / 2;
        displayInfo();
        cout << "Total Grade: " << totalGrade << endl;
    }
};

class GraduateStudent : public Student {
    int research, presentation;
public:
    GraduateStudent(string n, string r) : Student(n, r), research(0), presentation(0) {}

    void inputGrades() override {
        cin >> research >> presentation;
    }

    void calculateGrade() override {
        int totalGrade = (research + presentation) / 2;
        displayInfo();
        cout << "Total Grade: " << totalGrade << endl;
    }
};

int main() {
    string name, rollNumber;
    char studentType;
    
    cin >> name >> rollNumber >> studentType;

    Student* student;
    if (studentType == 'U') {
        student = new UndergraduateStudent(name, rollNumber);
    } else if (studentType == 'G') {
        student = new GraduateStudent(name, rollNumber);
    } else {
        return 0;
    }

    student->inputGrades();
    student->calculateGrade();

    delete student;
    return 0;
}