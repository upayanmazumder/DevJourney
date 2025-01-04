#include<stdio.h>
#include<conio.h>
int main() {
	int temp,a[20],i,j,k,n;

	printf("How many numbers: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++) {
		printf("Enter %dth number: ",i+1);
		scanf("%d",&a[i]);
	}

	for(j=0;j<i-1;j++) {
		for(k=j+1;k<i;k++) {
			if(a[j]>a[k]) {
				temp=a[j];
				a[j]=a[k];
				a[k]=temp;
			}
		}
	}
	
	printf("Ascending order: \n");
	for(i=0;i<n;i++) {
			printf("%d ",a[i]);
	}
}