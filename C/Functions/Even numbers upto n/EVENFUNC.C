//Program to print even numbers upto n
#include<stdio.h>
#include<conio.h>
int main() 
{
	int printEvenNumbers(int),n,p;
	
	printf("Enter a number : ");
	scanf("%d",&n);
	printf("Even numbers upto %d : ",n);
	p=printEvenNumbers(n);
	getch();
	return 0;
}
//The printEvenNumbers function
int printEvenNumbers(int a)
{
	int f,r,i,temp;
	temp=1;
	for(i=0;i<a;i++)
		{
			r=temp%2;
			if(r==0)
				printf("%d ",temp);
			temp++;
		}
	return(f);
}