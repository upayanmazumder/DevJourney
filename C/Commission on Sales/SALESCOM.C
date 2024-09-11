//Program to find commission based on sales
#include<stdio.h>
#include<conio.h>
int main()
{
	float sp,c;
	
	printf("Enter the price of goods sold: ");
	scanf("%f",&sp);
	if(sp<=10000)
		c=sp*2/100;
	else if(sp<=30000)
		c=sp*5/100;
	else if(sp<=50000)
		c=sp*7/100;
	else
		c=(sp*10/100)+2000;
	printf("Your commission earned is Rs %f",c);
	getch();
    return 0;
}