//Program to find out whether a number is prime or composite
#include<stdio.h>
#include<conio.h>
int main()
{
	int i=1,N,fac=0,r;
	
	printf("Enter the number you wish to inspect : ");
	scanf("%d",&N);
	while(i<(N/2))
		{
			i=i+1;
			r=N%i;
			if(r==0)
				fac=fac+1;
		}
	if(fac==0)
		printf("The number is prime");
	else
		printf("The number is composite and has %d factor(s)",fac);
	getch();
    return 0;
}