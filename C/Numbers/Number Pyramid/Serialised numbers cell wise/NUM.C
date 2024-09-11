#include<stdio.h>
#include<conio.h>
int main() 
{
	int i,j,k=1,n;
	
	printf("Enter number of rows: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
				{
					printf("%d ",k);
					k++;
				}
			printf("\n");
		}
	getch();
    return 0;
}