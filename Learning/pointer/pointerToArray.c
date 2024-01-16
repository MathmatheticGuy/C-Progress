#include <stdio.h>

void DoubleArray(int *A, int size){ // int *A is the same as int A[]
    for (int i = 0; i < size; i++){
        A[i] = A[i] * 2;
    }
}

int main(){
    int A[] = {2, 4, 5, 7, 8, 1};
    int i;
    int *p = A;
    for  (int i = 0; i < 5; i++){
        printf("A[%d] = %d at %d\n", i, A[i], &A[i]);
    }
    
    // must pass size in main() because DoubleArray() does not know the size of A
    int size = (sizeof(A)/sizeof(A[0])); 
    // multiply each array element by 2
    DoubleArray(A, size);

    printf("\nAfter double\n");
    for  (int i = 0; i < 5; i++){
        printf("A[%d] = %d at %d\n", i, A[i], &A[i]);
    }
}