#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
void containerLoading(int weights[], int values[], int n, int capacity) {
    int i, w;
    int **K = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++) {
        K[i] = (int *)malloc((capacity + 1) * sizeof(int));
    }
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    int result = K[n][capacity];
    printf("Maximum value in Knapsack = %d\n", result);
    printf("Items included:\n");
    w = capacity;
    for (i = n; i > 0 && result > 0; i--) {
        if (result == K[i - 1][w])
            continue;
        else {
            printf("Item %d (Weight: %d, Value: %d)\n", i, weights[i - 1], values[i - 1]);
            result = result - values[i - 1];
            w = w - weights[i - 1];
        }
    }
    for (i = 0; i <= n; i++) {
        free(K[i]);
    }
    free(K);
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n],i;
    printf("Enter the weights and values of the items:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &weights[i]);
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &values[i]);
    }
    printf("Enter the capacity of the container: ");
    scanf("%d", &capacity);
    containerLoading(weights, values, n, capacity);

    return 0;
}

