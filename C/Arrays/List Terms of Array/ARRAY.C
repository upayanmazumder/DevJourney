//Program to print terms of an array
#include<stdio.h>
#include<conio.h>
int main()
{
	int arr[10],i,n;
	
	printf("Total number of numbers : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
			printf("Enter number %d : ",i+1);
			scanf("%d",&arr[i]);
		}
	printf("The numbers are : ");
	for(i=0;i<n;i++)
		{
			printf("%d ",arr[i]);
		}
	getch();
    return 0;
}