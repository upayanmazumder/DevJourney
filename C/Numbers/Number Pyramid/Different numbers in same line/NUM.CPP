//
#include<stdio.h>
#include<conio.h>
void main()
{
	int i,j,n;
	clrscr();
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
}