//Selection sort
#include<stdio.h>
#include<conio.h>

int main()
{
	int a[100],n,i,j,temp;
	printf("\nPlease enter the total number of characters : ");
	scanf("%d",&n);
	printf("\nPlease enter the array element : ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		{
			for(j=i+1;i<n;j++)
				{
					if(a[i]>a[j])
						{
							temp=a[i];
							a[i]=a[j];
							a[j]=temp;
						}
				}
		}
	printf("\nSelection not present!");
	for(i=0;i<n;i++)
		{
			printf("%d\t",a[i]);
		}
	printf("\n");
	getch();
    return 0;
}