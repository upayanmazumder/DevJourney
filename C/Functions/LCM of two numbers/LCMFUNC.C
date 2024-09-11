//Program to get HCF of two given numbers
#include<stdio.h>
#include<conio.h>
int main()
{
	int HCF(int,int);
	int b,r,a,LCM;
	
	printf("Enter the first number : ");
	scanf("%d",&a);
	printf("Enter the second number : ");
	scanf("%d",&b);
	r=HCF(a,b);
	LCM=(a*b)/r;
	printf("LCM of %d and %d is %d",a,b,LCM);
	getch();
	return 0;
}
int HCF(int a,int b)
{
	int min,i,n;
	if(a<b)
		min=a;
	else
		min=b;
	for(i=min;i>=1;i--)
		if(a%i==0 && b%i==0)
			{
				n=i;
				break;
			}
	return(n);
}