#include<stdio.h>

int main() {
    int l,b,a,p;
    printf("Enter length: ");
    scanf("%d",&l);
    printf("Enter breadth: ");
    scanf("%d",&b);
    a = l * b;
    p = 2 * (l + b);
    printf("Area = %d\nPerimeter = %d\n",a,p);
}