//Program to print odd numbers from an array
#include<stdio.h>
#include<conio.h>
int main()
{
	int arr[10],i,n;
	
	printf("Enter length of array: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
			printf("Enter number %d : ",i+1);
			scanf("%d",&arr[i]);
		}
	for(i=0;i<n;i++)
		{
			if(arr[i]%2!=0)
				printf("%d ",arr[i]);
		}
	getch();
    return 0;
}