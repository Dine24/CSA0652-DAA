#include <stdio.h>
void printPascalTriangle(int n) {
    int arr[n][n];
    int i,line;
    for (line = 0; line < n; line++) {
        for ( i = 0; i <= line; i++) {
            if (i == 0 || i == line) {
                arr[line][i] = 1;
            } else {
                arr[line][i] = arr[line - 1][i - 1] + arr[line - 1][i];
            }
            printf("%d ", arr[line][i]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printPascalTriangle(n);
    return 0;
}

