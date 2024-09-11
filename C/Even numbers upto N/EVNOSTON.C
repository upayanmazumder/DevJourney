//Program to print odd numbers upto N terms
#include<stdio.h>
#include<conio.h>
int main()
{
	int i=2,N;
	
	printf("Enter terminal number : ");
	scanf("%d",&N);
	while(i<=N)
		{
			printf("%d ",i);
			i=i+2;
		}
	getch();
    return 0;
}
