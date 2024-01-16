#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum element in an array
int findMin(int arr[], int n) {
    int min = arr[0]; // Assume the first element as the minimum

    // Traverse through the array and update the minimum if a smaller element is found
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min; // Return the minimum element
}

int main() {
    int n; // Number of elements in the array
    int* pa; // Pointer to the array

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for the array dynamically
    pa = (int*)malloc(n * sizeof(int));

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pa[i]);
    }

    int minValue = findMin(pa, n); // Call the function to find the minimum value

    printf("The minimum value in the array is: %d\n", minValue);

    // Free the dynamically allocated memory
    free(pa);

    return 0;
}
