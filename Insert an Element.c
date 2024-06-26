#include <stdio.h>

void insertNumber(int arr[], int *size, int position, int number) {
	int i;
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }
    for (i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = number;
    (*size)++;
}

int main() {
    int size, position, number,i;
    int arr[100];  
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    printf("Enter the elements of the list:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position where the number should be inserted: ");
    scanf("%d", &position);
    printf("Enter the number to be inserted: ");
    scanf("%d", &number);
    insertNumber(arr, &size, position, number);
    printf("Updated list:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

