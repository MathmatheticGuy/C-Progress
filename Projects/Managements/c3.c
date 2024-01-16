#include <stdio.h>
#include <stdlib.h>

// Function to input an array of 2-byte integers from the keyboard
int* nhapmang(int n) {
    int* arr = (int*)malloc(n * sizeof(int)); // Allocate memory for the array

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        int input;
        int isValid = 0;

        do {
            printf("Nhap phan tu thu %d: ", i + 1);
            if (scanf("%d", &input) == 1) {
                // Input is valid
                isValid = 1;
            } else {
                // Input is invalid, clear the input buffer
                while (getchar() != '\n');
                printf("Nhap sai! Vui long nhap lai.\n");
            }
        } while (!isValid);

        arr[i] = input;
    }

    return arr;
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    
    int* arr = nhapmang(n);

    // Print the array
    printf("Mang vua nhap la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // Free the allocated memory

    return 0;
}
