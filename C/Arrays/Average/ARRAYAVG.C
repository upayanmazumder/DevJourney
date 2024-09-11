//Program to print the average value of the terms in an array
#include<stdio.h>
#include<conio.h>
int main()
{
	int arr[10],i,n,s=0,avg;
	
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
	avg=s/n;
	printf("Average of the elements of the array is %d",avg);
	getch();
    return 0;
}