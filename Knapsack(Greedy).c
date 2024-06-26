#include <stdio.h>
#include <stdlib.h>
struct Item {
    int value;
    int weight;
};
int compare(const void *a, const void *b) {
    double r1 = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double r2 = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;
    if (r1 < r2)
        return 1;
    else if (r1 > r2)
        return -1;
    else
        return 0;
}
double fractionalKnapsack(int W, struct Item arr[], int n) {
    qsort(arr, n, sizeof(struct Item), compare);

    int currentWeight = 0; 
    int i;
    double finalValue = 0.0; 
    for (i = 0; i < n; i++) {
        if (currentWeight + arr[i].weight <= W) {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        } 
        else {
            int remainingWeight = W - currentWeight;
            finalValue += arr[i].value * ((double)remainingWeight / arr[i].weight);
            break;
        }
    }

    return finalValue;
}

int main() {
    int W, n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    printf("Enter the value and weight of each item:\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("Value of item %d: ", i + 1);
        scanf("%d", &arr[i].value);
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &arr[i].weight);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    double maxValue = fractionalKnapsack(W, arr, n);
    printf("Maximum value in knapsack = %.2f\n", maxValue);

    return 0;
}

