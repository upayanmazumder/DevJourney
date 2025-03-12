#include <stdio.h>
#include <string.h>

struct Student {
    char name[21];
    int age;
    struct Marks {
        int C, DS, Physics;
    } marks;
    int totalMarks;
};

void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

void sortStudents(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].totalMarks > students[j + 1].totalMarks) {
                swap(&students[j], &students[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Student students[n];

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d %d", students[i].name, &students[i].age, 
              &students[i].marks.C, &students[i].marks.DS, &students[i].marks.Physics);
        students[i].totalMarks = students[i].marks.C + students[i].marks.DS + students[i].marks.Physics;
    }

    sortStudents(students, n);

    for (int i = 0; i < n; i++) {
        printf("%s %d %d\n", students[i].name, students[i].age, students[i].totalMarks);
    }

    return 0;
}