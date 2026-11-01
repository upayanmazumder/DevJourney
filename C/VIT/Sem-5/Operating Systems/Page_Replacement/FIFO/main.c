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
    if (frames == NULL || occupied == NULL) {
        free(pages);
        free(frames);
        free(occupied);
        return 1;
    }
    int next = 0, faults = 0, hits = 0;
    printf("\nFIFO Page Replacement\n");
    printf("%-12s", "Page");
    for (int j = 0; j < frame_count; j++)
        printf("Frame%-7d", j + 1);
    printf("Result\n");
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frame_count; j++) {
            if (occupied[j] && frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if (found) {
            hits++;
        } else {
            faults++;
            frames[next] = pages[i];
            occupied[next] = 1;
            next = (next + 1) % frame_count;
        }
        printf("%-12d", pages[i]);
        for (int j = 0; j < frame_count; j++) {
            if (occupied[j])
                printf("%-12d", frames[j]);
            else
                printf("%-12s", "-");
        }
        printf("%s\n", found ? "Hit" : "Fault");
    }
    printf("\nTotal Page Faults = %d\n", faults);
    printf("Total Page Hits = %d\n", hits);
    free(pages);
    free(frames);
    free(occupied);
    return 0;
}
