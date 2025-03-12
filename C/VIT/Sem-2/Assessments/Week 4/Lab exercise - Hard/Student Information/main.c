#include <stdio.h>
#include <string.h>

struct Student {
    int rollNo, age;
    char name[50], address[100];
};

void findStudentsByAge(struct Student *students, int n) {
    for (int i = 0; i < n; i++) {
        if (students[i].age == 17) {
            printf("%s ", students[i].name);
        }
    }
    printf("\n");
}

void findStudentsByEvenRoll(struct Student *students, int n) {
    for (int i = 0; i < n; i++) {
        if (students[i].rollNo % 2 == 0) {
            printf("%s ", students[i].name);
        }
    }
    printf("\n");
}

void searchStudentByRollNo(struct Student *students, int n, int searchRollNo) {
    for (int i = 0; i < n; i++) {
        if (students[i].rollNo == searchRollNo) {
            printf("%d %s %d %s\n", students[i].rollNo, students[i].name, students[i].age, students[i].address);
            return;
        }
    }
}

int main() {
    int n, searchRollNo;
    scanf("%d", &n);
    struct Student students[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d %s", &students[i].rollNo, students[i].name, &students[i].age, students[i].address);
    }
    scanf("%d", &searchRollNo);
    findStudentsByAge(students,n);
    findStudentsByEvenRoll(students, n);
    searchStudentByRollNo(students,n,searchRollNo);
    return 0;
}