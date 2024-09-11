//Program to add two square matrices using switch
#include<stdio.h>
#include<conio.h>
int main()
{
	int a[10][10],b[10][10],c[10][10],m,i,j,n;
	
	printf("Enter matrix dimension: ");
	scanf("%d",&n);
	for(m=0;m<2;m++)	//Configure each matrix
		{
			printf("<======MATRIX %d======>\n",m+1);
			for(i=0;i<n;i++)	//Configure each row
				{
					for(j=0;j<n;j++)	//Configure each column
						{

							printf("Enter value of row  %d ",i+1);
							printf("column %d of",j+1);
							printf(" matrix %d : ",m+1);
							switch(m)	//Cycle through the matrices
								{
									case 0: //3rd matrix
										scanf("%d",&a[i][j]);
										break;
									case 1:	//2nd matrix
										scanf("%d",&b[i][j]);
										break;
									default:
										break;
								}
						}
				}
		}
	//Calculate the value of the resultant matrix
	for(i=0;i<n;i++)	//For each row
		{
			for(j=0;j<n;j++)
				{
					c[i][j]=a[i][j]+b[i][j];
				}
		}
	//Print the result
	for(m=0;m<3;m++)	//Each matrix
		{
			for(i=0;i<n;i++)	//For each row
				{
					printf("[ ");
					for(j=0;j<n;j++)	//For each column
						{
							switch(m)
								{
									case 0: //First matrix
										printf("%d ",a[i][j]);
										break;
									case 1: //2nd matrix
										printf("%d ",b[i][j]);
										break;
									case 2: //3rd matrix (OUT)
										printf("%d ",c[i][j]);
										break;
									default:
										break;
								}
						}
					printf("]\n");
				}
			switch(m)
				{
					case 0:
						printf("\n   +   \n\n");
						break;
					case 1:
						printf("\n   =   \n\n");
						break;
					case 2:
						break;
				}
		}
	getch();
    return 0;
}