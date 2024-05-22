//Row same number pyramid
#include<stdio.h>
#include<conio.h>
void main()
{
	int i,j,n;
	clrscr();
	printf("Enter number : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)	//row
		{
			for(j=1;j<=i;j++)
				{
					printf("%d ",i);
				}
			printf("\n");
		}
	getch();
}