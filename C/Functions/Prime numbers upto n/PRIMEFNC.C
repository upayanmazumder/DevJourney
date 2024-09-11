//Program to print prime numbers upto n
#include<stdio.h>
#include<conio.h>
int main() 
{
	int printPrime(int),n,p;
	
	printf("Enter a number : ");
	scanf("%d",&n);
	printf("Prime numbers upto %d : ",n);
	p=printPrime(n);
	getch();
}
//The printPrime function
int printPrime(int a) //a is user input
{
	int f,i,temp,d,v;
	//v is is used to keep track of divisors
	for(temp=1;temp<=a;temp++)
		{
			v=0; //Reset divisor count to 0 for the term
			for(d=2;d<temp;d++) //For each term, divisor is 2 to before that term
				{
					if(temp%d==0)	//Divisible
						v++;
				}
			if(v==0) //Found no divisor
				printf("%d ",temp);
		}
	return(f);
    return 0;
}