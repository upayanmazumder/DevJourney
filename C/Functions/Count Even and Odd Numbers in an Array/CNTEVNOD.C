//Program to count number of even and odd numbers in an array using function
#include<stdio.h>
#include<conio.h>
int main() 
{
	int countEven(int),countOdd(int);
	int arr[10];
	int i,n,even=0,odd=0,p,q;
	
	printf("Length of array : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
			printf("Enter %dth value : ",i+1);
			scanf("%d",&arr[i]);
		}
	for(i=0;i<n;i++)
		{
			p=countEven(arr[i]);
			q=countOdd(arr[i]);
			even=even+p;
			odd=odd+q;
		}
	printf("In the array there are %d even numbers and %d odd numbers",even,odd);
	getch();
	return 0;
}
int countEven(int a)
{
	int e=0;
	if(a%2==0)
		e++;
	return(e);
}
int countOdd(int b)
{
	int o=0;
	if(b%2!=0)
		o++;
	return(o);
}