#include<stdio.h>

int main() {
	int i = 1, n, f = 1;
	
	printf("Enter number : ");
	scanf("%d",&n);

	do {
		f = f * i;
		i++;
    } while (i <= n);

	printf("The factorial of %d is %d",n,f);
}