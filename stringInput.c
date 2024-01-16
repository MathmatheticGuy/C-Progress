#include <stdio.h>
#define MAX_LENGTH 

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    printf("You entered: %s", str);
    return 0;
}
