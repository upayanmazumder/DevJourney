//Program to print fibonacci series
#include<stdio.h>
#include<conio.h>
void main()
{
	int a,b,c,n=1;
	clrscr();
	for(a=0;n<11;n=n+1)
		{
			switch(n)
				{
					case 1: //First case
						b=0; //a=0
						break;
					case 2: //Second case
						b=1;
						a=0;
						break;
					default:
						c=b;
						b=a+b;
						a=c;
						break;
				}
			printf("%d ",b);
		}
	getch();
}


