#include <stdio.h>

int *findLarger(int *num1, int *num2) {
    return (*num1 > *num2) ? num1 : num2;
}

int main() {
    int n1, n2;
    scanf("%d", &n1);
    scanf("%d", &n2);
    int *larger = findLarger(&n1, &n2);
    printf("%d", *larger);
}