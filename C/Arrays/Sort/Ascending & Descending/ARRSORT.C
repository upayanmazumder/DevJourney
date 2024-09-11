//Sorting in descending order
#include<stdio.h>
#include<conio.h>
int main()
{
	int temp,a[20],i,j,k,n;
	
	printf("Enter the number \n");
	for(i=0;i<4;i++)
		{
			scanf("%d",&a[i]);
		}
	for(j=0;j<i-1;j++)
		{
			for(k=j+1;k<i;k++)
				{
					if(a[j]>a[k])
						{
							temp=a[j];
							a[j]=a[k];
							a[k]=temp;
						}
				}
		}
	printf("Ascending order: \n");
	for(i=0;i<4;i++)
		{
			printf("%d\n",a[i]);
		}
	printf("\nDescending order: \n");
	for(i=3;i>=0;i--)
		{
			printf("%d\n",a[i]);
		}
	getch();
    return 0;
}