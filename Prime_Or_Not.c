#include <stdio.h>
#include <stdbool.h>
bool isPrimeRecursive(int num, int i) {
    if (num <= 2)
        return (num == 2) ? true : false;
    if (num % i == 0)
        return false;
    if (i * i > num)
        return true;
    return isPrimeRecursive(num, i + 1);
}
bool isPrime(int num) {
    return isPrimeRecursive(num, 2);
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isPrime(num))
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);

    return 0;
}

