// Program to multiply two matrices
#include <stdio.h>

int main() {
    int x[10][10], y[10][10], z[10][10];
    int i, j, k, r1, c1, r2, c2;

    // Input dimensions for the first matrix
    printf("Enter number of rows for the first matrix: ");
    scanf("%d", &r1);
    printf("Enter number of columns for the first matrix: ");
    scanf("%d", &c1);

    // Input dimensions for the second matrix
    printf("Enter number of rows for the second matrix: ");
    scanf("%d", &r2);
    printf("Enter number of columns for the second matrix: ");
    scanf("%d", &c2);

    // Check if multiplication is possible
    if (c1 != r2) {
        printf("Error! Number of columns of the first matrix must be equal to the number of rows of the second matrix.\n");
        return 1;
    }

    // Input values for the first matrix
    printf("\n<======MATRIX 1======>\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("Value of <%d,%d>: ", i, j);
            scanf("%d", &x[i][j]);
        }
    }

    // Input values for the second matrix
    printf("\n<======MATRIX 2======>\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            printf("Value of <%d,%d>: ", i, j);
            scanf("%d", &y[i][j]);
        }
    }

    // Initialize the result matrix with 0
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            z[i][j] = 0;
        }
    }

    // Multiply the matrices
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            for (k = 0; k < c1; k++) {
                z[i][j] += x[i][k] * y[k][j];
            }
        }
    }

    // Print the resulting matrix
    printf("\n<======RESULTANT MATRIX======>\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d ", z[i][j]);
            if (j == c2 - 1)
                printf("\n");
        }
    }

    return 0;
}
