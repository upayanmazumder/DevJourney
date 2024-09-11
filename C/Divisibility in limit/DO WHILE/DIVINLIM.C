#include<stdio.h>
#include<conio.h>
int main()
{
	int l,h,i,d,c=0;
	
	printf("Enter upper limit: ");
	scanf("%d",&h);
	printf("Enter lower limit: ");
	scanf("%d",&l);
	printf("Enter divisor: ");
	scanf("%d",&d);
	i=l;
	printf("%d has factors : ",d);
	do {
		if(i%d==0)
			{
				printf("%d ",i);
				c++;
			}
		i=i++;
	   } while(i<=h);
	printf("\nIn total, %d has ",d);
	printf("%d factors in the range",c);
	getch();
    return 0;
}