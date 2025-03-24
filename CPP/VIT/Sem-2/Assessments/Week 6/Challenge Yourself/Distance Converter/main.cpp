#include <iostream>
#include <iomanip>

using namespace std;

class MarathonRunner {
public:
    double convertedDistance;

    MarathonRunner(double distance, char unit) {
        if (unit == 'm') {
            convertedDistance = distance * 1.60934;
        } else if (unit == 'k') {
            convertedDistance = distance * 1.2;
        } else {
            convertedDistance = -1;
        }
    }

    void display() {
        if (convertedDistance == -1) {
            cout << "Invalid input for unit." << endl;
        } else {
            cout << fixed << setprecision(2) << convertedDistance << endl;
        }
    }
};

int main() {
    double distance;
    char unit;
    cin >> distance >> unit;

    MarathonRunner runner(distance, unit);
    runner.display();

    return 0;
}