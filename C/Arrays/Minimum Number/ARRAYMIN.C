//Program to print the smallest number in an array
#include<stdio.h>
#include<conio.h>
int main() 
{
	int arr[10],i,n,min;
	
	printf("Enter length of array: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
			printf("Enter number %d : ",i+1);
			scanf("%d",&arr[i]);
		}
	min=arr[0];
	for(i=1;i<n;i++)
		{
			if(min>arr[i])
				min=arr[i];
		}
	printf("The minimum value is %d",min);
	getch();
    return 0;
}