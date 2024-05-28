//Program to multiply two matrices
//UNFINISHED
#include<stdio.h>
#include<conio.h>
void main()
{
	int x[10][10],y[10][10],z[10][10],i,j,m,r,c;
	clrscr();
	printf("Enter number of rows : ");
	scanf("%d",&r);
	printf("Enter number of columns : ");
	scanf("%d",&c);
	//Take user input
	for(m=0;m<2;m++)
		{
			printf("\n<======MATRIX %d======>\n",m);
			for(i=0;i<r;i++)	//For each row
				{
					for(j=0;j<c;j++)	//For each column
						{
							printf("Value of <%d,%d>: ",i,j);
							if(m==0)
								scanf("%d",&x[i][j]);
							else if(m==1)
								scanf("%d",&y[i][j]);
						}
				}

		}
	//Multiply the matrices
	for(i=0;i<r;i++)	//For each row
		{
			for(j=0;j<c;j++)
				{
					z[i][j]=x[i][j]*y[i][j]+x[;
				}
		}
	getch();
}