#include <stdio.h>
#define MAX 100 
void printSubset(int subset[], int subsetSize) {
	int i;
    for (i = 0; i < subsetSize; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}
void sumOfSubsets(int set[], int subset[], int n, int subsetSize, int total, int sum, int node) {
	int i;
    if (total == sum) {
        printSubset(subset, subsetSize);
        return;
    }
    for (i = node; i < n; i++) {
        if (total + set[i] <= sum) {
            subset[subsetSize] = set[i]; 
            sumOfSubsets(set, subset, n, subsetSize + 1, total + set[i], sum, i + 1);  
        }
    }
}

int main() {
    int n, sum,i;
    int set[MAX];
    int subset[MAX];
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    printf("Enter the elements of the set:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    printf("Enter the desired sum: ");
    scanf("%d", &sum);
    printf("Subsets that sum up to %d are:\n", sum);
    sumOfSubsets(set, subset, n, 0, 0, sum, 0);

    return 0;
}

