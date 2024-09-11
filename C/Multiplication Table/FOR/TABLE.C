//Program to print multiplication table of a given number
#include<stdio.h>
#include<conio.h>
int main() 
{
	int n,i,res;
	
	printf("Enter a number : ");
	scanf("%d",&n);
	printf("\n\n<------Multiplication table of %d------>",n);
	for(i=1;i<=10;i=i+1)
		{
			res=i*n;
			printf("\n%d",n);
			printf("x%d",i);
			printf("=%d",res);
		}
	getch();
    return 0;
}