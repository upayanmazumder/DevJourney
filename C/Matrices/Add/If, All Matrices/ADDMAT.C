//Program to add two matrices of same dimensions using if
#include<stdio.h>
#include<conio.h>
int main()
{
	int x[10][10],y[10][10],z[10][10],i,j,r,c,m;
	
	printf("Enter number of rows : ");
	scanf("%d",&r);
	printf("Enter number of columns : ");
	scanf("%d",&c);
	for(m=0;m<2;m++)
		{
			printf("<====== MATRIX %d ======>\n",m+1);
			for(i=0;i<r;i++)
				{
					for(j=0;j<c;j++)
						{
							printf("Enter value at (%d,%d) : ",i+1,j+1);
							if(m==0)
								scanf("%d",&x[i][j]);
							else if(m==1)
								scanf("%d",&y[i][j]);
						}
				}
		}
	//Calculate the resultant matrix
	for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
				{
					z[i][j]=x[i][j]+y[i][j];
				}
		}
	//Print the matrices
	for(m=0;m<3;m++)
		{
			printf("\n\n<======MATRIX %d======>\n",m+1);
			for(i=0;i<r;i++)
				{
					for(j=0;j<c;j++)
						if(m==0)
							printf("\n%d ",x[i][j]);
						else if(m==1)
							printf("\n%d ",y[i][j]);
						else if(m==2)
							printf("\n%d ",z[i][j]);
				}
		}
	getch();
    return 0;
}