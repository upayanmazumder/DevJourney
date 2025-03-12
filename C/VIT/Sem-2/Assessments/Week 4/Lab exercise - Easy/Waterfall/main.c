#include <stdio.h>

struct Waterfall {
  double w, h, d;
};

struct TotalFlow {
    struct Waterfall waterfall;
};

double calcV(struct TotalFlow flow) {
    return flow.waterfall.w * flow.waterfall.h * flow.waterfall.d;
}

double calcA(struct TotalFlow flow) {
    double w, h, d;
    w = flow.waterfall.w;
    h = flow.waterfall.h;
    d = flow.waterfall.d;
    return 2 * (w * h + h * d + d * w);
}

int main() {
    struct TotalFlow flow;
    scanf("%lf %lf %lf", &flow.waterfall.w, &flow.waterfall.h, &flow.waterfall.d);
    printf("%.2lf cubic meters\n%.2lf square meters",calcV(flow), calcA(flow));
}