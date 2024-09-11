//Program to input higher and lower limit and print even nos in range
#include<stdio.h>
#include<conio.h>
int main()
{
	int a,b,i;
	
	printf("Enter the lower limit : ");
	scanf("%d",&a);
	printf("Enter the upper limit : ");
	scanf("%d",&b);
	if(b>a)
		if(a%2==0)  //Lower limit is even
			for(i=a;i<=b;i=i+2)
				{
					printf("%d ",i);
				}
		else //Lower limit is odd
			for(i=(a+1);i<=b;i=i+2)
				{
					printf("%d ",i);
				}

	else
		printf("The lower limit must be less than the upper limit!");
	getch();
    return 0;
}