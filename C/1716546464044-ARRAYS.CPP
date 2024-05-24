#include<stdio.h>
#include<conio.h>
void main()
{
	int arr[10],i,n;
	clrscr();
	printf("Enter length of array: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
			printf("Enter number %d : ",i+1);
			scanf("%d",&arr[i]);
		}
	printf("The items of the array are : ");
	for(i=0;i<n;i++)
		{
			printf("%d ",arr[i]);
		}
	getch();
}