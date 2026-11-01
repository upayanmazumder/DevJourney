#include <stdio.h>
#include <stdlib.h>

int read_positive(const char *prompt, int *value) {
    printf("%s", prompt);
    if (scanf("%d", value) != 1 || *value <= 0) {
        fprintf(stderr, "Invalid input: enter a positive integer.\n");
        return 0;
    }
    return 1;
}

int main(void) {
    printf("24BDS0367\nUpayan Mazumder\n");
    int block_count, process_count;
    int *blocks = NULL, *processes = NULL, *allocation = NULL;

    if (!read_positive("Number of memory blocks: ", &block_count))
        return EXIT_FAILURE;

    blocks = calloc((size_t)block_count, sizeof(*blocks));

    if (!blocks) {
        fprintf(stderr, "Memory allocation failed.\n");
        goto failure;
    }
    for (int j = 0; j < block_count; ++j) {
        printf("Block B%d size (KB): ", j + 1);
        if (!read_positive("", &blocks[j]))
            goto failure;
    }

    if (!read_positive("Number of processes: ", &process_count))
        goto failure;

    processes = calloc((size_t)process_count, sizeof(*processes));
    allocation = calloc((size_t)process_count, sizeof(*allocation));
    if (!processes || !allocation) {
        fprintf(stderr, "Memory allocation failed.\n");
        goto failure;
    }
    for (int i = 0; i < process_count; ++i) {
        printf("Process P%d size (KB): ", i + 1);
        if (!read_positive("", &processes[i]))
            goto failure;
    }
    int allocated_count = 0;
    printf("BEST-FIT MEMORY ALLOCATION\n\n");
    printf("Process Size Block Remaining\n");

    for (int i = 0; i < process_count; ++i) {
        int selected = -1;
        for (int j = 0; j < block_count; ++j) {
            if (blocks[j] >= processes[i] && (selected == -1 || blocks[j] < blocks[selected])) {
                selected = j;
            }
        }
        allocation[i] = selected;
        if (selected != -1) {
            blocks[selected] -= processes[i];
            ++allocated_count;
            printf("P%-7d %-4d KB B%-13d %d KB\n", i + 1, processes[i], selected + 1,
                   blocks[selected]);
        } else {
            printf("P%-7d %-4d KB Not allocated -\n", i + 1, processes[i]);
        }
    }

    printf("\nProcesses that could not be allocated:");
    int failed = 0;
    for (int i = 0; i < process_count; ++i) {
        if (allocation[i] == -1) {
            printf(" P%d", i + 1);
            failed = 1;
        }
    }
    if (!failed) {
        printf(" None");
    }

    printf("\n\nRemaining memory in blocks:\n");
    long long total_remaining = 0;

    for (int j = 0; j < block_count; ++j) {
        printf("B%d: %d KB\n", j + 1, blocks[j]);
        total_remaining += blocks[j];
    }

    printf("\nAllocated processes: %d of %d\n", allocated_count, process_count);
    printf("Total remaining memory: %lld KB\n", total_remaining);
    free(blocks);
    free(processes);
    free(allocation);
    return EXIT_SUCCESS;
failure:
    free(blocks);
    free(processes);
    free(allocation);
    return EXIT_FAILURE;
}
