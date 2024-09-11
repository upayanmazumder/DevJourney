#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,n;
	
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
    return 0;
}
