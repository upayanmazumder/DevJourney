#include <iostream>
#include <iomanip>

using namespace std;

double calculateSpeed(double distance, double time) {
    return distance / time;
}

double calculateSpeed(double distance, double time, double acceleration) {
    return (distance / time) + (acceleration * time);
}

int main() {
    double distance, time, trainAcceleration, planeAcceleration;
    cin >> distance >> time >> trainAcceleration >> planeAcceleration;
    cout << fixed << setprecision(2) << calculateSpeed(distance, time) << endl;
    cout << fixed << setprecision(2) << calculateSpeed(distance, time, trainAcceleration) << endl;
    cout << fixed << setprecision(2) << calculateSpeed(distance, time, planeAcceleration) << endl;
    return 0;
}