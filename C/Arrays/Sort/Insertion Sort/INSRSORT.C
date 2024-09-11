//Insertion sort
#include<stdio.h>
#include<conio.h>
int main()
{
	int a[50],i,n,j,temp;
	
	printf("Enter the size of the array : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",a[i]);
	for(i=0;i<n-1;i++)
		{
			for(j=j+1;j>0;j--)
				{
					if(a[j]<a[j-1])
						{
							temp=a[j];
							a[j]=a[j-1];
							a[j-1]=temp;
						}
				}
		}
	printf("The array after sort in the technique of insertion sort : ");
	for(i=0;i<n;i++)
		{
			printf("%d ",a[i]);
		}
	getch();
    return 0;
}