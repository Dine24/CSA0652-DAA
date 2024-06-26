#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void sieveOfEratosthenes(int n) {
	int p,i;
    bool *prime = (bool *)malloc((n + 1) * sizeof(bool));
    for (i = 0; i <= n; i++)
        prime[i] = true;
    for (p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    printf("Prime numbers up to %d are:\n", n);
    for ( p = 2; p <= n; p++)
        if (prime[p])
            printf("%d ", p);
    printf("\n");
    free(prime);
}
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    sieveOfEratosthenes(n);
    return 0;
}

