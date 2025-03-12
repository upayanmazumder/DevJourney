#include <stdio.h>
#include <string.h>

struct cricketer {
    char name[100];
    int age;
    int matches;
    float avgRuns;
};

void sortCricketers(struct cricketer arr[], int n) {
    struct cricketer temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].avgRuns > arr[j + 1].avgRuns) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    struct cricketer players[N];
    for (int i = 0; i < N; i++) {
        scanf("%s %d %d %f", players[i].name, &players[i].age, &players[i].matches, &players[i].avgRuns);
    }
    sortCricketers(players, N);
    for(int i = 0; i < N; i++) {
        printf("%s %d %d %.2f\n", players[i].name, players[i].age, players[i].matches, players[i].avgRuns);
    }
}