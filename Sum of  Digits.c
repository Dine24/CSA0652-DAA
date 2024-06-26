#include <stdio.h>
int sumOfDigits(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int result = sumOfDigits(num);
    printf("The sum of the digits of %d is %d\n", num, result);
    return 0;
}

