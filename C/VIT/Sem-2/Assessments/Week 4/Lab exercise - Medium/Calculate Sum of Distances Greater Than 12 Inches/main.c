#include <stdio.h>

typedef struct {
    int feet;
    float inches;
} Distance;

int main() {
    int n;
    scanf("%d", &n);
    Distance d, total = {0, 0.0};
    for (int i =0; i < n; i++) {
        scanf("%d %f", &d.feet, &d.inches);
        total.feet += d.feet;
        total.inches += d.inches;
    }
    
    if (total.inches >= 12.0) {
        total.feet += (int) (total.inches / 12);
        total.inches = total.inches - ((int) (total.inches / 12) * 12);
    }
    
    printf("%d\n%.2f\n", total.feet, total.inches);
}