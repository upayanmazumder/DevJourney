#include <stdio.h>

struct Marks {
    int rollNo;
    char name[50];
    int m[5];
};

int main() {
    int n, i, j;
    float sum, avg;
    scanf("%d", &n);
    struct Marks stu[10];
    
    for (i = 0; i < n; i++) {
        scanf("%d %s", &stu[i].rollNo, stu[i].name);
        for (j = 0; j < 5; j++) {
            scanf("%d",&stu[i].m[j]);
        }
        
    }
    
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 0; j < 5; j++) {
            sum += stu[i].m[j];
        }
        avg = sum / 5;
        printf("%.2f ",avg);
    }
}