//Program to find factorial of a number
#include<stdio.h>
#include<conio.h>
void main()
{
	int n,res=1,i;
	clrscr();
	printf("Enter the number : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		{
		   res=res*i;
		}
	printf("factorial no=%d",res);
	getch();
}