#include <stdio.h>
int findLargest(int arr[], int n) {
    if (n == 1)
        return arr[0];

    int max_in_rest = findLargest(arr, n - 1);
    return (arr[n - 1] > max_in_rest) ? arr[n - 1] : max_in_rest;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int largest = findLargest(arr, n);
    printf("The largest number in the array is %d.\n", largest);

    return 0;
}

