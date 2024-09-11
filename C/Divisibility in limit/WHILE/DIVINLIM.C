//Divisibility check in while
#include<stdio.h>
#include<conio.h>
int main()
{
	int l,h,i,d,n=0;
	
	printf("Enter upper limit: ");
	scanf("%d",&h);
	printf("Enter lower limit: ");
	scanf("%d",&l);
	printf("Enter the divisor: ");
	scanf("%d",&d);
	i=l;
	while(i<=h)
		{
			if(i%d==0)
				{
					printf("%d ",i);
					n=n+1;
				}
			i=i+1;
		}
	printf("\n\nThere are %d number(s) divisible by ",n);
	printf("%d between ",d);
	printf("%d and ",l);
	printf("%d.",h);
	getch();
    return 0;
}