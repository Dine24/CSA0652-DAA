#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void multiplyMatrices(int **matA, int **matB, int **matC, int rowA, int colA, int colB) {
    int i, j, k;
    for (i = 0; i < rowA; i++) {
        for (j = 0; j < colB; j++) {
            matC[i][j] = 0;
            for (k = 0; k < colA; k++) {
                matC[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}
void printMatrix(int **matrix, int rows, int cols) {
	int i,j;
    for (i = 0; i < rows; i++) {
        for ( j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int rowA, colA, rowB, colB;
    int i,j;
    printf("Enter the number of rows and columns of matrix A: ");
    scanf("%d %d", &rowA, &colA);
    printf("Enter the number of rows and columns of matrix B: ");
    scanf("%d %d", &rowB, &colB);
    if (colA != rowB) {
        printf("Matrix multiplication not possible. Number of columns in A must be equal to number of rows in B.\n");
        return 1;
    }
    int **matA = (int **)malloc(rowA * sizeof(int *));
    int **matB = (int **)malloc(rowB * sizeof(int *));
    int **matC = (int **)malloc(rowA * sizeof(int *));
    for (i = 0; i < rowA; i++) {
        matA[i] = (int *)malloc(colA * sizeof(int));
        matC[i] = (int *)malloc(colB * sizeof(int));
    }
    for (i = 0; i < rowB; i++) {
        matB[i] = (int *)malloc(colB * sizeof(int));
    }
    printf("Enter the elements of matrix A:\n");
    for (i = 0; i < rowA; i++) {
        for (j = 0; j < colA; j++) {
            scanf("%d", &matA[i][j]);
        }
    }
    printf("Enter the elements of matrix B:\n");
    for (i = 0; i < rowB; i++) {
        for (j = 0; j < colB; j++) {
            scanf("%d", &matB[i][j]);
        }
    }
    clock_t start = clock();
    multiplyMatrices(matA, matB, matC, rowA, colA, colB);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Resultant Matrix C:\n");
    printMatrix(matC, rowA, colB);
    printf("Time taken for matrix multiplication: %f seconds\n", time_taken);
    printf("The time complexity for matrix multiplication is O(n^3).\n");
    for ( i = 0; i < rowA; i++) {
        free(matA[i]);
        free(matC[i]);
    }
    for ( i = 0; i < rowB; i++) {
        free(matB[i]);
    }
    free(matA);
    free(matB);
    free(matC);

    return 0;
}

