//Count nos divisible in a lim by a number in the domain
#include<stdio.h>
#include<conio.h>
int main()
{
	int l,h,i,n=0,d; //n is used to count
	
	printf("Enter lower limit : ");
	scanf("%d",&l);
	printf("Enter upper limit : ");
	scanf("%d",&h);
	printf("Enter divisor : ");
	scanf("%d",&d);
	for(i=l;i<=h;i=i+1)
		{
			if(i%d==0)
				n=n+1;
		}
	printf("Total divisible nos in range is %d",n);
	getch();
    return 0;
}
