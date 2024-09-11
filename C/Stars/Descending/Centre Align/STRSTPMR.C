//Program to print a straight pyramid with stars in reverse order
#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,k,l,n;
	
	printf("Enter height of pyramid: ");
	scanf("%d",&n);
	for(i=n;i>=1;i--)
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
    return 0;
}