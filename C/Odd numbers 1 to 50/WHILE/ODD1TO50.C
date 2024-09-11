//Program to print odd numbers from 1 to 50
#include<stdio.h>
#include<conio.h>
int main()
{
	int i=1,n=50;
	
	while(i<=n)
		{
		 printf("%d ",i);
		 i=i+2;
		}
	getch();
    return 0;
}