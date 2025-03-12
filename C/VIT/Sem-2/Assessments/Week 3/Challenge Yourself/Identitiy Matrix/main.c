#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    int A[n][m];
    int (*p)[m] = A;
    for( int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d ", *(p + i) + j);
        }
    }
    int chk = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == j) {
                if( *(*(A + i) + j) != 1) {
                    chk = 0;
                    goto end;
                }
            } else {
                if(*(*(A + i) + j) != 0) {
                    chk = 0;
                    goto end;
                }
            }
        }
    }
    end:
    if (chk == 1) {
        printf("Identity matrix");
    } else {
        printf("Not an identity matrix");
    }
}