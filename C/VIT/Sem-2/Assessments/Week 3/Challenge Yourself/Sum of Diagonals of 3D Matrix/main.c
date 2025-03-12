#include <stdio.h>
#include <stdlib.h>

int main() {
    int *r = (int *)malloc(sizeof(int));
    int *c = (int *)malloc(sizeof(int));
    int *h = (int *)malloc(sizeof(int));
    scanf("%d %d %d", r,c,h);
    if((*r == *c) & (*c == *h)) {
        int A[*r][*c][*h];
        for(int i = 0 ; i < *r; i++) {
            for(int j = 0; j < *c; j++) {
                for(int k = 0; k < *h; k++) {
                    scanf("%d", &A[i][j][k]);
                }
            }
        }
        int (*P)[*c][*h] = A;
        int *sum  = (int *)malloc(sizeof(int));
        *sum = 0;
        for(int i = 0; i < *r;i++) {
            for(int j = 0; j < *c; j++) {
                for(int k = 0; k < *h; k++) {
                    if((i == j) & (j == k)) {
                        *sum = *sum + *(*(*(P + i) + j) + k);
                    }
                }
            }
        }
        printf("%d", *sum);
    } else {
        printf("Error");
    }
}