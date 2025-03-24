#include <iostream>
#include <iomanip>

using namespace std;

class HighwayDriver {
private:
    double distance;
    double time;

public:
    HighwayDriver(double dist, double hours, double mins) {
        distance = dist;
        time = hours + (mins / 60.0);
        displaySpeed();
    }

    HighwayDriver(double dist, double hours) {
        distance = dist;
        time = hours;
        displaySpeed();
    }

    void displaySpeed() {
        cout << fixed << setprecision(2) << (distance / time) << " mph" << endl;
    }
};

int main() {
    double dist1, hours1, mins1, dist2, hours2;
    cin >> dist1 >> hours1 >> mins1;
    HighwayDriver driver1(dist1, hours1, mins1);
    cin >> dist2 >> hours2;
    HighwayDriver driver2(dist2, hours2);
    return 0;
}