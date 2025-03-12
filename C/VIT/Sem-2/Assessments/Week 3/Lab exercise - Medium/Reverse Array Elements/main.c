#include <stdio.h>

void displayarray(int *a, int n) {
    for(int i = n -1; i >= 0; i--) {
        printf("%d ",*(a +i));
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for(int i = 0; i < N; i++) {
        scanf("%d",(arr + i));
    }
    displayarray(arr,N);
    
}