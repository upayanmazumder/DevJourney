#include<stdio.h>

int main() {
    int a,b,temp;
    printf("Enter a: ");
    scanf("%d",&a);
    printf("Enter b: ");
    scanf("%d",&b);
    printf("Before swapping swapping,\na = %d\nb = %d\n",a,b);
    temp = b;
    b = a;
    a = temp;
    printf("After swapping,\na = %d\nb = %d\n",a,b);
}