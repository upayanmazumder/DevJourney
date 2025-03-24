#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    string id;

public:
    Person(string n, string i) : name(n), id(i) {}
};

class Score {
protected:
    double score;

public:
    Score(double s) : score(s) {}
};

class UndergraduateStudent : public Person, public Score {
public:
    UndergraduateStudent(string n, string i, double s) : Person(n, i), Score(s) {}

    void displayGrade() {
        char grade;
        if (score >= 90) grade = 'A';
        else if (score >= 80) grade = 'B';
        else if (score >= 70) grade = 'C';
        else if (score >= 60) grade = 'D';
        else grade = 'F';

        cout << "Student " << name << " with ID " << id << " received grade " << grade << "." << endl;
    }
};

class PostgraduateStudent : public Person, public Score {
public:
    PostgraduateStudent(string n, string i, double s) : Person(n, i), Score(s) {}

    void displayResult() {
        string result = (score >= 60) ? "Pass" : "Fail";
        cout << "Student " << name << " with ID " << id << " " << result << " the course." << endl;
    }
};

int main() {
    string ugName, ugId, pgName, pgId;
    double ugScore, pgScore;

    cin >> ugName >> ugId >> ugScore;
    cin >> pgName >> pgId >> pgScore;

    UndergraduateStudent ug(ugName, ugId, ugScore);
    PostgraduateStudent pg(pgName, pgId, pgScore);

    ug.displayGrade();
    pg.displayResult();

    return 0;
}