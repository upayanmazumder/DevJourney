//Program to find simple interest
#include<stdio.h>
#include<conio.h>
int main()
{
    float p,r,t,si;
    
    printf("Enter principal amount : ");
    scanf("%f",&p);
    printf("Enter rate : ");
    scanf("%f",&r);
    printf("Enter time : ");
    scanf("%f",&t);
    si=(p*r*t)/100;
    printf("Interest is=%f",si);
    getch();
    return 0;
}
