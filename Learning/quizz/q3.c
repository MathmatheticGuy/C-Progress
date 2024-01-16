#include<stdio.h>

int main() {

    int a = 2, b = 5;

    a = a ^ b;  // XOR operation to swap values
    b = b ^ a;  // XOR operation to restore the original value of 'a' to 'b'
    a = a ^ b;  // XOR operation to restore the original value of 'b' to 'a'

    printf("%d %d", a, b);

    return 0;
}
