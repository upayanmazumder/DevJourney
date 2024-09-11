//Program to input student's marks, find total and remarks
#include<stdio.h>
#include<conio.h>
int main()
{
	struct student
		{
			int rlno;
			char name[20];
			int m1,m2,m3,m4,tot;
			char rem;
			float avg;
		};
	typedef struct student st;
	st a[20],l[20];
	int n,i,j,tem,maxl[20],c,d,max=0;
	
	printf("Enter number of students : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
			printf("Enter the information of student %d : ",i+1);
			printf("\n> Enter roll number : ");
			scanf("%d",&a[i].rlno);
			printf("> Enter name : ");
			scanf("%s",a[i].name);
			printf("> Enter marks : ");
			scanf("%d%d%d%d",&a[i].m1,&a[i].m2,&a[i].m3,&a[i].m4);
		}
	for(i=0;i<n;i++)
		{
			a[i].tot=a[i].m1+a[i].m2+a[i].m3+a[i].m4;
			a[i].avg=a[i].tot/4;
			if(a[i].avg<40)
				a[i].rem='F';
			else
				a[i].rem='P';
		}
	
	for(i=0;i<n;i++)	//For each student
		{
			c=0; //Reset letter count to zero
			for(j=0;a[i].name[j]!='\0';j++) //Until a space is found, for each char
				{
					c++; //Adjust letter count
					maxl[i]=c; //Set max letters for student
					{
						if(maxl[i]>max)   //Set length of longest name
							max=maxl[i];
					}
				}
		}
	printf("Result sheet");
	printf("\n------");
	printf("\n Roll no Name ");
	for(i=0;i<(max+10);i++)
		printf(" ");
	printf(" Total Average  Remarks");
	printf("\n-----------------------------------");
	for(i=0;i<n;i++)
		{
			printf("\n> %d      %s ",a[i].rlno,a[i].name);
			for(d=0;d<(20-maxl[i]);d++)
				printf(" ");
			printf(" %d %f %c",a[i].tot,a[i].avg,a[i].rem);
		}
	printf("\n-----------------------------------");
	getch();
    return 0;
}