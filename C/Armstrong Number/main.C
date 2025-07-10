#include<stdio.h>

int main()
{
	int n,r,sum=0,i;
	
	printf("Enter a number : ");
	scanf("%d",&n);

	i = n;
	printf("Sum of the cubes of the digits of %d is ",n);

	while(i>9) {
		r=i%10;
		sum=sum+(r*r*r);
		i=i/10;
	}

	sum += (i * i * i);

	printf("%d.\nHence, it is %san Armstrong number!", n, (sum == n) ? "" : "not ");

	return 0;
}