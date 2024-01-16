#include <stdio.h>
#include <stdlib.h>

// Function to dynamically allocate memory for an array and input its elements
int* nhapmang(int n);

int main() {
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    int* pa = (int*)malloc(n * sizeof(int)); // Dynamically allocate memory for the array
    if (pa == NULL) {
        printf("Khong du bo nho!"); // Print error message if memory allocation fails
        return 0;
    }

    pa = nhapmang(n); // Call the function to input array elements

    printf("Cac gia tri da nhap:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", pa[i]); // Print the array elements
    }

    free(pa); // Free the dynamically allocated memory

    return 0;
}

// Function to dynamically allocate memory for an array and input its elements
int* nhapmang(int n) {
    int* arr = (int*)malloc(n * sizeof(int)); // Dynamically allocate memory for the array
    if (arr == NULL) {
        printf("Khong du bo nho!"); // Print error message if memory allocation fails
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        if (scanf("%hd", &arr[i]) != 1) { // Input array element and check for valid input
            printf("Nhap sai! Vui long nhap lai.\n"); // Print error message for invalid input
            i--;
            while (getchar() != '\n'); // Clear input buffer
        }
    }

    return arr; // Return the dynamically allocated array
}
