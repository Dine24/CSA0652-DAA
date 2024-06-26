#include <stdio.h>
void printFactors(int n) {
    printf("Factors of %d are: ", n);
    int i;
    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    printFactors(n);
    return 0;
}

