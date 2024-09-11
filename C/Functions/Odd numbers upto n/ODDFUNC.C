//Program to print odd numbers upto n
#include<stdio.h>
#include<conio.h>
int main() 
{
	int printOddNumbers(int),n,p;
	
	printf("Enter a number : ");
	scanf("%d",&n);
	printf("Odd numbers upto %d : ",n);
	p=printOddNumbers(n);
	getch();
	return 0;
}
//The printOddNumbers function
int printOddNumbers(int a)
{
	int f,r,i,temp;
	temp=1;
	for(i=0;i<a;i++)
		{
			r=temp%2;
			if(r!=0)
				printf("%d ",temp);
			temp++;
		}
	return(f);
}