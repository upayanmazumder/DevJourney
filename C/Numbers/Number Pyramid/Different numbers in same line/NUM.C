//
#include<stdio.h>
#include<conio.h>
int main() 
{
	int i,j,n;
	
	printf("Enter number of columns : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)	//Row
		{
			for(j=1;j<=i;j++)	//Column
				{
					printf("%d ",j);
				}
			printf("\n");
		}
	getch();
    return 0;
}