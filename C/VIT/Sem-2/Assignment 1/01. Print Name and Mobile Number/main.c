#include<stdio.h>

int main() {
    long int no;
    char name[100];
    printf("Enter name: ");
    scanf("%99s",name);
    printf("Enter mobile number: ");
    scanf("%ld",&no);
    printf("Your name is %s\n",name);
    printf("Your mobile number is %ld\n",no);
}