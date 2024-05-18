#include<stdio.h>
#include<conio.h>
void main()
{
    int i,sum=0,r,n;
    clrscr();
    printf("enter the no");
    scanf("%d",&n);
    while(n>9)
        {
            r=n%10;
            sum=sum+r;
            n=n/10;
        }
    sum=sum+n;
    printf("sum of digit=%d",sum);
    getch();
}