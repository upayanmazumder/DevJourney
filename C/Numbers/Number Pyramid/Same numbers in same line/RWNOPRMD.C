//Row same number pyramid
#include<stdio.h>
#include<conio.h>
int main() 
{
	int i,j,n;
	
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
    return 0;
}