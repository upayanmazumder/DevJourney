//Program to create a triangle
#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,k,n;
	
	printf("Enter height of half : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		{
			printf("|");
			for(j=1;j<=i;j++)
				{
					printf(" ");
				}
			printf("\\");
			printf("\n");
		}
	for(i=n;i>=1;i--)
		{
			printf("|");
			for(j=i;j>=1;j--)
				{
					printf(" ");
				}
			printf("/\n");
		}
	getch();
    return 0;
}