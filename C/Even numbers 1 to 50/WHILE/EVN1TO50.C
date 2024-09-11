//Program to print even numbers from 1 to 50 using while
#include<stdio.h>
#include<conio.h>
int main()
{
	int i=2,n=50;
	
	while(i<=n)
		{
			printf("%d ",i);
			i=i+2;
		}
	getch();
    return 0;
}