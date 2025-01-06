#include<stdio.h>
#include<math.h>

int main() {
    int i,sum=0,n=0,r;
    float N;
    scanf("%f",&N);
    if (fmod(N,2) == 0) { // Even
        printf("Sum of digits: ");
        goto find_sum;
        
    } else { // odd
        printf("Reversed number: ");
        goto reversed;
    }
    
    find_sum:
        while (N > 0) {
            r = fmod(N,10);
            sum += r;
            N = (N - r) / 10;
        }
        printf("%d",sum);
        goto end_program;
        
    reversed:
        while (N > 0) {
            r = fmod(N,10);
            n += r;
            n *= 10;
            N = (N - r) / 10;
        }
        n /= 10;
        printf("%d",n);
    end_program:;
}