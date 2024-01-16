#include <stdio.h>
#include <stdlib.h>

int main() {
    // Input the length of the 2D array
    int length;
    printf("Enter the length of the 2D array: ");
    scanf("%d", &length);

    // Define the 2D array
    int array[length][length];

    // Input values from the user
    printf("Enter new values for the array:\n");
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            int value;
            printf("Enter value for array[%d][%d]: ", i, j);
            while (scanf("%d", &value) != 1) {
                printf("Invalid input. Please enter an integer value: ");
                while (getchar() != '\n'); // Clear input buffer
            }
            array[i][j] = value;
        }
    }

    // Print updated array elements
    printf("Updated array:\n");
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
