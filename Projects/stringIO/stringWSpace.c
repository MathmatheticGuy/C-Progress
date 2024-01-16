#include <stdio.h>

int main() {
    char d[100]; // Declare d as an array of characters
    char a[100]; // Declare a as an array of characters

    printf("Enter a string: ");
    fgets(d, sizeof(d), stdin); // Read a string, including spaces, into d

    printf("Enter another string: ");
    scanf("%s", &a); // Read a string, including spaces, into a

    printf("\nd - %s", d);
    printf("a - %s\n", a); // Print the strings

    return 0;
}