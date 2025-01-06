#include<stdio.h>

int main() {
	int n,r,sum=0,i,l=0,x,p;
	printf("Enter a number : ");
	scanf("%d",&n);
	i = n;
	x= n;

	while(x != 0) {
		x = x / 10;
		l++;
	}

	while(i != 0) {
			r = i % 10;
			p = 1;
			for(int j=0;j<l;j++)
				p = p * r;
			sum = sum + p;
			i = i / 10 ;
	}

	printf("It is %san Armstrong number!", (sum != n) ? "not " : "");
}