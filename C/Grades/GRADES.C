//Program to calculate marks and grade of a student
#include<stdio.h>
#include<conio.h>
int main() 
{
    int a,b,c,total;
    float avg;
    
    printf("Enter marks in subject a : ");
    scanf("%d",&a);
    printf("Enter marks in subject b : ");
    scanf("%d",&b);
    printf("Enter marks in subject c : ");
    scanf("%d",&c);
    total=a+b+c;
    avg=total/3;
    if(avg>80)
        printf("Grade A");
    else if(avg>70)
        printf("Grade B");
    else if(avg>60)
        printf("Grade C");
    else
        printf("FAIL");
    printf("\nTotal marks = %d", total);
    printf("\nAverage marks = %f", avg);
    getch();
    return 0;
}
