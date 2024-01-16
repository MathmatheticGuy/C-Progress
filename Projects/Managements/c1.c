#include <stdio.h>
#include <ctype.h>

int main() {
    int b;

    while (1) {
        printf("Enter a number: ");
        if (scanf("%d", &b) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        if (b >= 0 && b <= 50) {
            printf("Your number: %d\n", b);
            break; // Exit the loop if the number is within the range
        } else {
            printf("Your number is not in the range 0-50.\n");
        }
    }

    return 0;
}
