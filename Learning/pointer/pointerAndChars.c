#include <stdio.h>
#include <stdlib.h>

//! Printing a string using pointer
void print(char *C){ // char *C is the same as char C[]
    int i = 0;
    //! C is not holding the string, it is holding the address of the first character of the string
    while (*C != '\0'){ // if the 1st character is not null (\0)
        printf("C value: %c\n", *C);
        //! C - address itself, *C - value at the address C pointed to
        printf("address of C: %d\n", C);
        C++; // increment the address of C by 1
    }
}


int main(){
    char C[20] = "Hello"; // string gets stored in the space for array
    // char *C = "Hello"; // string gets stoed as compile time constant 
    // C[0] = 'A'; // cannot modify *C. Bc *C is in read only mode / constant
    print(C);
    return 0;
}