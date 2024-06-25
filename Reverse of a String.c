#include <stdio.h>
#include <string.h>
void reverseString(char str[]) {
    int n = strlen(str); 
    int start = 0;      
    int end = n - 1;     
    char temp;           
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}

