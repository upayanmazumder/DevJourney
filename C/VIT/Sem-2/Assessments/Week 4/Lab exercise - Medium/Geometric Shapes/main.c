#include <stdio.h>
struct Point3D {
    double x, y, z;
};

struct Sphere {
    struct Point3D center;
    double radius;
};

struct Cylinder {
    struct Point3D base_center;
    double radius, height;
};

struct GeometryCalculator {
    struct Sphere sphere;
    struct Cylinder cylinder;
};

int main() {
    struct GeometryCalculator geo;
    scanf("%lf %lf %lf", &geo.sphere.center.x, &geo.sphere.center.y, &geo.sphere.center.z);
    scanf("%lf", &geo.sphere.radius);
    scanf("%lf %lf %lf", &geo.cylinder.base_center.x, &geo.cylinder.base_center.y, &geo.cylinder.base_center.z);
    scanf("%lf %lf", &geo.cylinder.radius, &geo.cylinder.height);
    double sphere_volume = (4.0 / 3.0) * 3.14 * geo.sphere.radius * geo.sphere.radius * geo.sphere.radius;
    double cylinder_volume = 3.14 * geo.cylinder.radius * geo.cylinder.radius * geo.cylinder.height;
    printf("Sphere's Volume: %.2lf cubic units\n", sphere_volume);
    printf("Cylinder's Volume: %.2lf cubic units\n", cylinder_volume);
}