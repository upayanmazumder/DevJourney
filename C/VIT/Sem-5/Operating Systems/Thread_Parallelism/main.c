#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    const int *array;
    size_t start;
    size_t end;
    long long partial_sum;
} ThreadData;

static pthread_mutex_t output_lock = PTHREAD_MUTEX_INITIALIZER;

static void *sum_portion(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    data->partial_sum = 0;
    for (size_t i = data->start; i < data->end; ++i) {
        data->partial_sum += data->array[i];
    }

    pthread_mutex_lock(&output_lock);

    printf("Thread %d: Elements =", data->id);
    for (size_t i = data->start; i < data->end; ++i) {
        printf(" %d", data->array[i]);
    }

    printf(" | Partial Sum = %lld\n", data->partial_sum);
    pthread_mutex_unlock(&output_lock);
    return NULL;
}

int main(void) {
    printf("24BDS0367\tUpayan Mazumder\n");
    int input_count;
    printf("Enter number of integers: ");
    fflush(stdout);
    if (scanf("%d", &input_count) != 1 || input_count <= 0) {
        fprintf(stderr, "Invalid size: enter a positive integer.\n");
        return EXIT_FAILURE;
    }
    const size_t n = (size_t)input_count;
    int *array = calloc(n, sizeof(*array));
    if (array == NULL) {
        fprintf(stderr, "Unable to allocate the array.\n");
        return EXIT_FAILURE;
    }

    int num_threads;
    printf("Enter number of threads: ");
    fflush(stdout);

    if (scanf("%d", &num_threads) != 1 || num_threads <= 0) {
        fprintf(stderr, "Invalid thread count: enter a positive integer.\n");
        free(array);
        return EXIT_FAILURE;
    }

    pthread_t *threads = calloc((size_t)num_threads, sizeof(*threads));
    ThreadData *data = calloc((size_t)num_threads, sizeof(*data));

    if (threads == NULL || data == NULL) {
        fprintf(stderr, "Unable to allocate thread storage.\n");
        free(data);
        free(threads);
        free(array);
        return EXIT_FAILURE;
    }

    size_t start = 0;
    printf("Enter %zu integers: ", n);
    fflush(stdout);
    for (size_t i = 0; i < n; ++i) {
        if (scanf("%d", &array[i]) != 1) {
            fprintf(stderr, "Invalid input: expected an integer.\n");
            free(data);
            free(threads);
            free(array);
            return EXIT_FAILURE;
        }
    }
    putchar('\n');

    for (int i = 0; i < num_threads; ++i) {
        size_t count = n / num_threads;
        if ((size_t)i < n % num_threads) {
            ++count;
        }
        data[i] = (ThreadData){
            .id = i + 1, .array = array, .start = start, .end = start + count, .partial_sum = 0};
        start += count;
        int rc = pthread_create(&threads[i], NULL, sum_portion, &data[i]);

        if (rc != 0) {
            fprintf(stderr, "pthread_create: %s\n", strerror(rc));
            for (int j = 0; j < i; ++j) {
                int join_rc = pthread_join(threads[j], NULL);
                if (join_rc != 0) {
                    fprintf(stderr, "pthread_join: %s\n", strerror(join_rc));
                    exit(EXIT_FAILURE);
                }
            }
            pthread_mutex_destroy(&output_lock);
            free(data);
            free(threads);
            free(array);
            return EXIT_FAILURE;
        }
    }

    long long total_sum = 0;

    for (int i = 0; i < num_threads; ++i) {
        int rc = pthread_join(threads[i], NULL);
        if (rc != 0) {
            fprintf(stderr, "pthread_join: %s\n", strerror(rc));
            exit(EXIT_FAILURE);
        }
        total_sum += data[i].partial_sum;
    }

    printf("\nTotal Sum = %lld\n", total_sum);
    pthread_mutex_destroy(&output_lock);
    free(data);
    free(threads);
    free(array);
    return EXIT_SUCCESS;
}
