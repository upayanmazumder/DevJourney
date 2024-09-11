#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,k,n;
	
	printf("Enter side length of square : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)	//Top side
		{
			printf("* ");
		}
	printf("\n");
	for(j=1;j<=(n-2);j++)	//Section between top and mid
		{
			printf("* ");
			for(k=1;k<=(n-2);k++)
				{
					printf("  ");
				}
			printf("*");
			printf("\n");
		}
	for(i=1;i<=n;i++)	//Bottom side
		{
			printf("* ");
		}
	getch();
    return 0;
}