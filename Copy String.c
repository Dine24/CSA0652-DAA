#include <stdio.h>
void copyString(char *source, char *destination) {
    while (*source != '\0') {
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0'; 
}
int main() {
    char source[100], destination[100];
    printf("Enter a string to copy: ");
    scanf("%s", source);
    copyString(source, destination);

    
    printf("The copied string is: %s\n", destination);

    return 0;
}

