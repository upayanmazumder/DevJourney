#include<stdio.h>
#include<conio.h>
void main()
{
	int arr[10],i,n,sum=0;
	clrscr();
	printf("Total number of numbers : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
			printf("Enter number %d : ",i+1);
			scanf("%d",&arr[i]);
		}
	for(i=0;i<n;i++)
			sum=sum+arr[i];
	printf("Sum is %d",sum);
	getch();
}