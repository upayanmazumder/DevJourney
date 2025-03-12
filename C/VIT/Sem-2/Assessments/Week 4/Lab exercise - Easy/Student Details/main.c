#include <stdio.h>

struct Student {
  int roll_no;
  char name[50];
  float marks;
};

int main() {
    struct Student student[50];
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %s %f", &student[i].roll_no, &student[i].name, &student[i].marks);
   }
   
   printf("Details of all students\n");
   for ( i = 0; i < n; i++) {
       printf("Student %d\nRoll no: %d\nName: %s\nMarks: %.2f\n", i + 1, student[i].roll_no, student[i].name, student[i].marks);
   }
}