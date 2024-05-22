#include<stdio.h>
#include<conio.h>
void main()
{
	int i,j,n;
	clrscr();
	printf("How many no to enter : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)	//ROW
	{
		for(j=1;j<=i;j++)	//COLUMN
			{
				printf("* ");
			}
		printf("\n");
	}
	getch();
}
