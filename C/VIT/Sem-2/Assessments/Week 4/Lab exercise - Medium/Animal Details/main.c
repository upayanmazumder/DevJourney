#include <stdio.h>
#include <string.h>

struct Animal {
    char name[50];
    int count;
    char location[50];
};

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    struct Animal animals[n];
    struct Animal *ptr = animals;
    for (int i = 0; i < n; i++) {
        scanf("%s %d %s", (ptr + i) -> name, &(ptr + i) -> count, (ptr + i) -> location);
    }
    int found = 0;
    for (int i = 0; i <n; i++) {
        char tempLocation[50];
        strcpy(tempLocation, (ptr + i) -> location);
        toLowerCase(tempLocation);
        if(strcmp(tempLocation, "india") == 0) {
            printf("%s %d %s\n", (ptr + i) -> name, (ptr + i) -> count, (ptr + i) -> location);
            found = 1;
        }
    }
    if (!found) {
        printf("No animals found in India\n");
    }
}