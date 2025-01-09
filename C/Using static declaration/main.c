#include<stdio.h>

int main() {
    int a,b,res,ch;
    int add(int,int);int sub(int,int);int prod(int,int);int quo(int,int);
    printf("Enter number 1: ");
    scanf("%d",&a);
    printf("Enter number 2: ");
    scanf("%d",&b);
    printf("\n1. Add\n2. Subtract\n3. Product\n4. Divide\nEnter the number corresponding to the operation you wish to perform.");
    scanf("%d",&ch);
    switch(ch) {
        case 1:
            res = add(a,b);
            break;
        case 2:
            res = sub(a,b);
            break;
        case 3:
            res = prod(a,b);
            break;
        case 4:
            res = quo(a,b);
            break;
        default:
            printf("Incorrect choice!");
    }
    printf("Result = %d",res);
}

int add(int x, int y) {
    int i;
    static int sec = 0;
    for(i=0;i<y;i++){
        sec++;
    }
    return x+sec;
}

int sub(int x, int y) {
    int i;
    static int sec = 0;
    for(i=0;i<y;i++){
        sec++;
    }
    return x-sec;
}

int prod(int x, int y) {
    int i;
    static int sec = 0;
    for(i=0;i<y;i++){
        sec++;
    }
    return x*sec;
}

int quo(int x, int y) {
    int i;
    static int sec = 0;
    for(i=0;i<y;i++){
        sec++;
    }
    return x/sec;
}