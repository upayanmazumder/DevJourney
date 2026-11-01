#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("24BDS0367\nUpayan Mazumder\n\n");
    int n, frame_count;
    printf("Enter number of page references: ");
    if (scanf("%d", &n) != 1 || n <= 0)
        return 1;
    int *pages = malloc((size_t)n * sizeof(int));
    if (pages == NULL)
        return 1;
    printf("Enter %d page references: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &pages[i]) != 1) {
            free(pages);
            return 1;
        }
    }
    printf("Enter number of frames: ");
    if (scanf("%d", &frame_count) != 1 || frame_count <= 0) {
        free(pages);
        return 1;
    }
    int *frames = malloc((size_t)frame_count * sizeof(int));
    int *occupied = calloc((size_t)frame_count, sizeof(int));
    int *last_used = malloc((size_t)frame_count * sizeof(int));
    if (frames == NULL || occupied == NULL || last_used == NULL) {
        free(pages);
        free(frames);
        free(occupied);
        free(last_used);
        return 1;
    }
    int faults = 0, hits = 0;
    printf("\nLRU Page Replacement\n");
    printf("%-12s", "Page");
    for (int j = 0; j < frame_count; j++)
        printf("Frame%-7d", j + 1);
    printf("Result\n");
    for (int i = 0; i < n; i++) {
        int found = -1;
        for (int j = 0; j < frame_count; j++) {
            if (occupied[j] && frames[j] == pages[i]) {
                found = j;
                break;
            }
        }
        if (found != -1) {
            hits++;
            last_used[found] = i;
        } else {
            faults++;
            int victim = -1;
            for (int j = 0; j < frame_count; j++) {
                if (!occupied[j]) {
                    victim = j;
                    break;
                }
            }
            if (victim == -1) {
                victim = 0;
                for (int j = 1; j < frame_count; j++) {
                    if (last_used[j] < last_used[victim])
                        victim = j;
                }
            }
            frames[victim] = pages[i];
            occupied[victim] = 1;
            last_used[victim] = i;
        }
        printf("%-12d", pages[i]);
        for (int j = 0; j < frame_count; j++) {
            if (occupied[j])
                printf("%-12d", frames[j]);
            else
                printf("%-12s", "-");
        }
        printf("%s\n", found != -1 ? "Hit" : "Fault");
    }
    printf("\nTotal Page Faults = %d\n", faults);
    printf("Total Page Hits = %d\n", hits);
    free(pages);
    free(frames);
    free(occupied);
    free(last_used);
    return 0;
}
