//Program to find area and perimeter of a rectangle
#include<stdio.h>
#include<conio.h>
void main()
{
float l,b,p,a;
clrscr();
printf("Enter length : ");
scanf("%f",&l);
printf("Enter breadth : ");
scanf("%f",&b);
p=2*(l+b);
a=l*b;
printf("Perimeter is %f",p);
printf("Area is %f",a);
getch();
}
