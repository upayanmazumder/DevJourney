//Program to create a triangle
#include<stdio.h>
#include<conio.h>
void main()
{
	int i,j,k,n;
	clrscr();
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
}