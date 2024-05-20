//Program to print odd numbers from 1 to 50
#include<stdio.h>
#include<conio.h>
void main()
{
	int i=1,n=50;
	clrscr();
	while(i<=n)
		{
		 printf("%d ",i);
		 i=i+2;
		}
	getch();
}