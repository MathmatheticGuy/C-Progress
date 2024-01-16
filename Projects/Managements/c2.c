#include <stdio.h>

void clearBitAndPrintBinary(int n) {
    int m;

    // Clear the 3rd bit of 'n' and store the result in 'm'
    m = n & ~(1 << 2); // Clear the 3rd bit

    printf("m in binary: ");
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        // Shift the bits of 'm' to the right and check the rightmost bit
        printf("%d", (m >> i) & 1);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    clearBitAndPrintBinary(n);

    return 0;
}
