#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Triangle {
    int a, b, c;
    double area;
};

double calculate_area(int a, int b, int c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int compare(const void *t1, const void *t2) {
    struct Triangle *tri1 = (struct Triangle *)t1;
    struct Triangle *tri2 = (struct Triangle *)t2;
    return (tri1 -> area > tri2 -> area) - (tri1 -> area < tri2 -> area);
}

int main() {
    int n;
    scanf("%d", &n);
    struct Triangle *triangles = (struct Triangle *)malloc(n * sizeof(struct Triangle));
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &triangles[i].a, &triangles[i].b, &triangles[i].c);
        triangles[i].area = calculate_area(triangles[i].a, triangles[i].b, triangles[i].c);
    }
    qsort(triangles, n, sizeof(struct Triangle), compare);
    for(int i = 0; i < n; i++) {
        printf("%d \%d %d\n", triangles[i].a, triangles[i].b, triangles[i].c);
    }
    free(triangles);
}