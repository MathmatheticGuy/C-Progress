#include <stdio.h>
#include <stdlib.h>

void writeArrayToFile(int* arr, int n, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
        if ((i + 1) % 3 == 0) {
            fprintf(file, "\n");
        }
    }

    fclose(file);
}

int main() {
    int n = 10; // Number of elements in the array
    int* pa = (int*)malloc(n * sizeof(int)); // Allocate memory for the array

    // Populate the array with some values
    for (int i = 0; i < n; i++) {
        pa[i] = i + 1;
    }

    writeArrayToFile(pa, n, "mang_nguyen.txt");

    // Free the allocated memory
    free(pa);
    pa = NULL;

    return 0;
}

void writeArrayToFile(int* arr, int n, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
        if ((i + 1) % 3 == 0) {
            fprintf(file, "\n");
        }
    }

    fclose(file);
}

int main() {
    int n = 10; // Number of elements in the array
    int* pa = (int*)malloc(n * sizeof(int)); // Allocate memory for the array

    // Populate the array with some values
    for (int i = 0; i < n; i++) {
        pa[i] = i + 1;
    }

    writeArrayToFile(pa, n, "mang_nguyen.txt");

    // Free the allocated memory
    free(pa);
    pa = NULL;

    return 0;
}
