//Armstrong Number
//Sum of cube of digits should be equal to number
#include<stdio.h>
#include<conio.h>
int main()
{
	int n,r,sum=0,i;
	
	printf("Enter a number : ");
	scanf("%d",&n);
	i=n;
	printf("Sum of the cubes of the digits of %d is ",n);
	while(i>9)
		{
			r=i%10;
			sum=sum+(r*r*r);
			i=i/10;
		}
	sum=sum+(i*i*i);
	printf("%d.\n Hence it is ",sum);
	if(sum==n)
		printf("");
	else
		printf("not ");
	printf("an Armstrong number!");
	getch();
    return 0;
}