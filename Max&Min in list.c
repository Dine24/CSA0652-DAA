#include <stdio.h>
struct Pair {
    int min;
    int max;
};
struct Pair findMinMax(int arr[], int low, int high) {
    struct Pair minmax, leftMinMax, rightMinMax;
    int mid;
    if (low == high) {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        } else {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }
    mid = (low + high) / 2;
    leftMinMax = findMinMax(arr, low, mid);
    rightMinMax = findMinMax(arr, mid + 1, high);
    if (leftMinMax.min < rightMinMax.min)
        minmax.min = leftMinMax.min;
    else
        minmax.min = rightMinMax.min;
    if (leftMinMax.max > rightMinMax.max)
        minmax.max = leftMinMax.max;
    else
        minmax.max = rightMinMax.max;

    return minmax;
}

int main() {
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Pair minmax = findMinMax(arr, 0, n - 1);
    printf("Minimum value in the array is: %d\n", minmax.min);
    printf("Maximum value in the array is: %d\n", minmax.max);

    return 0;
}

