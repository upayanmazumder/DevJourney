//Program to print odd numbers between two given numbers
#include<stdio.h>
#include<conio.h>
int main() 
{
	int l,h,i;
	
	printf("Enter first number : ");
	scanf("%d",&l);
	printf("Enter second number: ");
	scanf("%d",&h);
	if(l%2==0) //even
		l=l+1;
	for(i=l;i<=h;i=i+2)
		{
			printf("%d ",i);
		}
	getch();
    return 0;
}
