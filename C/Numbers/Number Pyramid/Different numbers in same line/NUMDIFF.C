#include<stdio.h>
#include<conio.h>
int main() 
{
	int i,j,k,n;
	
	printf("Enter number of rows : ");
	scanf("%d",&n);
	for(i=(n+1);i>1;i--)
		{
			for(j=1;j<=(i-2);j++)
				{
					printf("  ");
				}
			for(k=1;(k+j)<=(n+1);k++)
				{
					printf("%d ",k);
				}
			printf("\n");
		}
	getch();
    return 0;
}