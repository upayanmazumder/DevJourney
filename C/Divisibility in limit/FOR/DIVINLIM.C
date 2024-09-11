//Program to print nos divibile a number in a certain domain
#include<stdio.h>
#include<conio.h>
int main()
{
	int l,h,n,i;
	
	printf("Enter the lower limit : ");
	scanf("%d",&l);
	printf("Enter the second limit : ");
	scanf("%d",&h);
	printf("Enter the number to use to divide : ");
	scanf("%d",&n);
	for(i=l;i<=h;i=i+1)
		{
			//Dividend is i and divisor is n
			if(i%n==0)
				printf("%d ",i);
		}
	getch();
    return 0;
}