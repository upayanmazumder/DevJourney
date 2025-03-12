#include <stdio.h>
#include <math.h>

struct Triangle {
    double side1, side2,side3;
};

int isValidTriangle(struct Triangle t) {
    return (t.side1+t.side2>t.side3) && (t.side1+t.side3>t.side2) && (t.side2 + t.side3 > t.side1);
}

double calculateArea(struct Triangle t) {
    double s = (t.side1 + t.side2 + t.side3) / 2.0;
    return sqrt(s * (s - t.side1) * (s - t.side2) * (s - t.side3));
}

int main() {
    struct Triangle t;
    scanf("%lf %lf %lf", &t.side1, &t.side2, &t.side3);
    if (isValidTriangle(t)) {
        printf("%.1lf\n",calculateArea(t));
    } else {
        printf("Invalid Triangle");
    }
}