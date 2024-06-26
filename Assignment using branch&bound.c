#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#define N 4 

int costMatrix[N][N] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};

int min(int a, int b) {
    return (a < b) ? a : b;
}

typedef struct {
    int cost;
    int workerID;
    int jobID;
} Node;

void copyMatrix(int src[N][N], int dest[N][N]) {
	int i,j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

int calculateCost(int matrix[N][N]) {
    int cost = 0;
    int i,j;
    for (i = 0; i < N; i++) {
        int minRow = INT_MAX;
        for (j = 0; j < N; j++) {
            if (matrix[i][j] < minRow) {
                minRow = matrix[i][j];
            }
        }
        if (minRow != INT_MAX && minRow != 0) {
            for (j = 0; j < N; j++) {
                if (matrix[i][j] != INT_MAX) {
                    matrix[i][j] -= minRow;
                }
            }
            cost += minRow;
        }
    }
    for (j = 0; j < N; j++) {
        int minCol = INT_MAX;
        for (i = 0; i < N; i++) {
            if (matrix[i][j] < minCol) {
                minCol = matrix[i][j];
            }
        }
        if (minCol != INT_MAX && minCol != 0) {
            for (i = 0; i < N; i++) {
                if (matrix[i][j] != INT_MAX) {
                    matrix[i][j] -= minCol;
                }
            }
            cost += minCol;
        }
    }
    return cost;
}

void solve(int worker, int matrix[N][N], int currCost, int* minCost, bool assigned[N]) {
	int job;
    if (worker == N) {
        *minCost = min(currCost, *minCost);
        return;
    }
    for (job = 0; job < N; job++) {
        if (!assigned[job]) {
            int tempMatrix[N][N];
            copyMatrix(matrix, tempMatrix);
            int i;
            for (i = 0; i < N; i++) {
                tempMatrix[worker][i] = INT_MAX;
                tempMatrix[i][job] = INT_MAX;
            }
            tempMatrix[worker][job] = INT_MAX;
            int cost = currCost + costMatrix[worker][job] + calculateCost(tempMatrix);
            if (cost < *minCost) {
                assigned[job] = true;
                solve(worker + 1, tempMatrix, cost, minCost, assigned);
                assigned[job] = false;
            }
        }
    }
}

int main() {
    int minCost = INT_MAX;
    bool assigned[N] = {false};
    int matrix[N][N];
    copyMatrix(costMatrix, matrix);
    solve(0, matrix, 0, &minCost, assigned);
    printf("The minimum cost is %d\n", minCost);
    return 0;
}

