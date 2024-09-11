//Program to find the largest of three numbers
#include<stdio.h>
#include<conio.h>
int main() 
{
    int a,b,c;
    
    printf("Enter three numbers: ");
    scanf("%d%d%d",&a,&b,&c);
    if(a>b && a>c)
        printf("The largest number is %d",a);
    else if(b>a && b>c)
        printf("The largest number is %d",b);
    else
        printf("The largest number is %d",c);
    getch();
    return 0;
}