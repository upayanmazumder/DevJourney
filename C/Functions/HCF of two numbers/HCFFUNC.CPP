//Program to print factors
#include<stdio.h>
#include<conio.h>
void main()
{
	int printHCF1(int),printHCF2(int),n1,n2,p;
	clrscr();
	printf("Enter first number : ");
	scanf("%d",&n1);
	printf("Enter second number : ");
	scanf("%d",&n2);
	printf("Factor(s) of %d : ",n1);
	p=printHCF1(n1);
	printf("Factor(s) of %d : ",n2);
	p=printHCF2(n2);
	getch();
}
//The printHCF1 function
int printHCF1(int a) //a is user input 1
{
	int f,i,d;
	for(d=2;d<a;d++) //For each term, divisor is 2 to before that term
		{
			if(a%d==0)	//Divisible
				{
					printf("%d ",d);
				}
		}
	return(f);
}

//The printHCF2 function
int printHCF2(int b) //b is user input 2
{
	int f,i,d;
	for(d=2;d<b;d++)
		{
			if(b%d==0)
				{
					printf("%d ",d);
				}
		}
	return(f);
}