//Factorial
#include<stdio.h>
#include<conio.h>
int main()
{
	int n,f,i;
	
	printf("Enter a number: ");
	scanf("%d",&n);
	i=1;
	f=1;
	while(i<=n)
		{
			f=f*i;
			i=i+1;
		}
	printf("The factorial of %d is ",n);
	printf("%d",f);
	getch();
    return 0;
}






