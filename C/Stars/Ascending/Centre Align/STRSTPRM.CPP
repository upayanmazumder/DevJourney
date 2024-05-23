//Program to print a straight pyramid with stars
#include<stdio.h>
#include<conio.h>
void main()
{
	int i,j,k,l,n;
	clrscr();
	printf("Enter height of pyramid: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		{
			for(k=(n-i);k>0;k--)
				{
					printf("  ");
				}
			for(j=1;j<=i;j++)
				{
					printf("* ");
					for(l=n-1;l<n;l++)
						{
							printf("  ");
						}
				}
			printf("\n");
		}
	getch();
}