//Reverse order of stars
#include<stdio.h>
#include<conio.h>
void main()
{
	int i,j,n;
	clrscr();
	printf("Enter max stars in a line: ");
	scanf("%d",&n);
	for(i=n;i>=1;i--)
		{
			for(j=1;j<=i;j++)
				{
					printf("* ");
				}
			printf("\n");
		}
	getch();
}
