//Introduction to functions
#include<stdio.h>
#include<conio.h>
void main()
{
	int fact(int);
	int n,r;
	clrscr();
	printf("Enter a number : ");
	scanf("%d",&n);
	r=fact(n);
	printf("Factorial of %d is %d",n,r);
	getch();
}
//The factorial function
int fact(int a)
{
	int f=1;
	int i;
	for(i=2;i<=a;i++)
		f=f*i;
	return(f);
}