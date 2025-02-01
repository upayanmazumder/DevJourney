#include <stdio.h>

int main()
{
    int n, *p;
    n = 100;
    p = &n;

    printf("n = %d\n", n);
    printf("n is stored at %p [using &]\n", &n);
    printf("n is stored at %p [using pointer]", p);
}