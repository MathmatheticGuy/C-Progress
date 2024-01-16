#include <stdio.h>

int findMax(int a, int b){
    return a > b ? a : b;
}

int main() {
    int num1 = 3;
    int num2 = 5;
    int max = findMax(num1, num2);
    printf("The maximum of %d and %d is: %d\n", num1, num2, max);
};