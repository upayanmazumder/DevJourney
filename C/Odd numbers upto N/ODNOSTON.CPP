//Program to print odd numbers upto N terms
#include<stdio.h>
#include<conio.h>
void main()
{
	int i=1,N;
	clrscr();
	printf("Enter terminal number : ");
	scanf("%d",&N);
	while(i<=N)
		{
			printf("%d ",i);
			i=i+2;
		}
	getch();
}
