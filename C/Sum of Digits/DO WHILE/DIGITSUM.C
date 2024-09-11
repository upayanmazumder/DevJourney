#include<stdio.h>
#include<conio.h>
int main()
{
	int n,i,s=0;
	
	printf("Enter a number : ");
	scanf("%d",&n);
	do {
		i=n%10;
		s=s+i;
		n=(n-i)/10;
	   } while(n>0);
	printf("Sum of digits is %d",s);
	getch();
    return 0;
}