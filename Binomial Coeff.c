#include <stdio.h>
int binomialCoeff(int n, int k) {
    int C[n+1][k+1];
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= k; j++) {
            C[i][j] = 0;
        }
    }
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= k && j <= i; j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }

    return C[n][k];
}

int main() {
    int n, k;
    printf("Enter the values of n and k: ");
    scanf("%d %d", &n, &k);
    int result = binomialCoeff(n, k);
    printf("Binomial Coefficient C(%d, %d) = %d\n", n, k, result);
    return 0;
}

