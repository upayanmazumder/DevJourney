#include <stdio.h>
#define KINETIC_ENERGY(m,v) (0.5 *(m)*(v)*(v))

union Car {
    double mass;
    double velocity;
    double energy;
};

int main() {
    union Car car;
    scanf("%lf", &car.mass);
    double mass = car.mass;
    scanf("%lf", &car.velocity);
    double velocity = car.velocity;
    car.energy = KINETIC_ENERGY(mass, velocity);
    printf("%.2f Joules", car.energy);
}