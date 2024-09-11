#include<stdio.h>
#include<conio.h>
int main()
{
	int i=1,n,f=1;
	
	printf("Enter a number : ");
	scanf("%d",&n);
	do {
		f=f*i;
		i++;
	   }	while(i<=n);
	printf("The factorial of %d is ",n);
	printf("%d",f);
	getch();
    return 0;
}