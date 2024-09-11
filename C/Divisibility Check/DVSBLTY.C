//Program to input 2 nos and check whether divisible by 2nd or not
#include<stdio.h>
#include<conio.h>
int main()
{
	int a,b,r;
	
	printf("Enter the number to divide : ");
	scanf("%d",&a);
	printf("Enter the number to divide by : ");
	scanf("%d",&b);
	r=a%b;
	if(r==0)
		printf("Divisible");
	else
		printf("Not divisible");
	getch();
    return 0;
}