//Program to print the sum of all the terms of an array
#include<stdio.h>
#include<conio.h>
int main() 
{
	int arr[10],i,n,s=0;
	
	printf("Enter length of array: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
			printf("Enter number %d : ",i+1);
			scanf("%d",&arr[i]);
		}
	for(i=0;i<n;i++)
		{
			s=s+arr[i];
		}
	printf("Sum of the elements of the array is %d",s);
	getch();
    return 0;
}