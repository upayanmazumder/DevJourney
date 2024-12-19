#include<stdio.h>

int main() {
	int n,r,sum=0,i;
	printf("Enter a number : ");
	scanf("%d",&n);
	i = n;
	while(i > 9)
		{
			r = i % 10;
			sum = sum + (r * r * r);
			i = i / 10 ;
		}
	sum = sum + (i * i * i);

	printf("It is ");

    if(sum != n)
        printf("not ");
    
	printf("an Armstrong number!");
}