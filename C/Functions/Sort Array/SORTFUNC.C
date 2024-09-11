//Program to sort numbers using function
#include<stdio.h>
#include<conio.h>
int main() 
{
	int sort(int a[],int);
	int arr[20],n,i,s;
	
	printf("How many numbers to be entered : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
			printf("Enter %d no. : ",i+1);
			scanf("%d",&arr[i]);
		}
	s=sort(arr,n);
	printf("The sorted array is as follows : ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("The smallest value is %d",s);
	getch();
}
int sort(int arr[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(arr[j]<arr[i])
				{
					temp=arr[j];
					arr[j]=arr[i];
					arr[i]=temp;
				}
	return(arr[0]);
    return 0;
}