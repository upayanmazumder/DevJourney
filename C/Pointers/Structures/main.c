#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    float marks;
};

int main() {
    struct Student *ptr;
    ptr = (struct Student *)malloc(sizeof(struct Student));

    ptr->id = 101;
    ptr->marks = 90.5;

    printf("ID: %d, Marks: %.2f\n", ptr->id, ptr->marks);

    free(ptr);
    return 0;
}
