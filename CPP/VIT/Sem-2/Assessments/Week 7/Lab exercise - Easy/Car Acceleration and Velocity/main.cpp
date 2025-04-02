#include <iostream>
#include <iomanip>

using namespace std;

class Acceleration {
    float value;
    public:
    Acceleration(float v) : value(v) {}
    float operator*(float time) {
    return value * time;
    }
};

int main() {
float initialVelocity, acceleration, time;
cin >> initialVelocity >> acceleration >> time;
Acceleration accel(acceleration);
float finalVelocity = initialVelocity + (accel * time);

cout << fixed << setprecision(1) << finalVelocity << " m/s";

return 0;

}
