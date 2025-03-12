#include <stdio.h>
#include <stdlib.h>

void mergeArrays(int *arr1, int m, int *arr2, int n, int *merged) {
    int i,j;
    for(i = 0; i < m; i++) {
        *(merged + i) = *(arr1 + i);
    }
    for(j = 0; j < n; j++) {
        *(merged + i +j) = *(arr2 + j);
    }
}

int main() {
    int m,n,i;
    scanf("%d", &m);
    int *arr1 = (int *)malloc(m*sizeof(int));
    for(i = 0; i < m; i++) {
        scanf("%d", (arr1 + i));
    }
    scanf("%d", &n);
    int *arr2 = (int *)malloc(n*sizeof(int));
    for(i = 0; i < n; i++) {
        scanf("%d", (arr2 + i));
    }
    int *merged = (int *)malloc((m + n)*sizeof(int));
    mergeArrays(arr1, m, arr2, n, merged);
    for(i = 0; i < m + n; i++) {
        printf("%d ", *(merged + i));
    }
    printf("\n");
    free(arr1);
    free(arr2);
    free(merged);
}
