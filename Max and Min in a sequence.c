#include <stdio.h>
void findMinMax(int arr[], int n, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];
	int i;
    for (i = 1; i < n; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

int main() {
    int n,i;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the list:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int min, max;
    findMinMax(arr, n, &min, &max);
    printf("The minimum value in the list is %d\n", min);
    printf("The maximum value in the list is %d\n", max);

    return 0;
}

