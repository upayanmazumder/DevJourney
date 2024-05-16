//Program to print even numbers from 1 to 50
#include<stdio.h>
#include<conio.h>
void main()
{
	int i;
	clrscr();
	for(i=2;i<=50;i=i+2)
		{
			printf("%d ",i);
		}
	getch();
}