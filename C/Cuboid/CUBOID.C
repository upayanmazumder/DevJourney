//Program to calculate dimensions of a cuboid
#include<stdio.h>
#include<conio.h>
int main()
{
    float l,b,h,a1,a2,a3,v;
    
    printf("Enter length : ");
    scanf("%f",&l);
    printf("Enter breadth : ");
    scanf("%f",&b);
    printf("Enter height : ");
    scanf("%f",&h);
    a1=l*b;
    a2=b*h;
    a3=h*l;
    v=l*b*h;
    printf("Area of the side bound by length and breadth is %f",a1);
    printf("\nArea of the side bound by breadth and height is %f",a2);
    printf("\nArea of the side bound by length and height is %f",a3);
    printf("\nVolume of the entire cuboid is %f",v);
    getch();
    return 0;
}