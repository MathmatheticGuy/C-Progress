#include <stdio.h>

void hello(char[], int); //* function prototype

int main(){

    //! FUNCTION PROTOTYPE

    //? Function declare without the main body and before main function
    //? Ensures that calls to a function are made with the correct arguments  

    //! IMPORTANT NOTES

    //? Many C compilers do not check for parameters matching
    //? Missing arguments will result in unexpected behaviour
    //? A function prototype causes the compiler to flag an error if arguments are mssing

    //! ADVANTAGES
    
    //? 1. (*) Easier to check for function w/ main() and func prototype at the top
    //? 2. Help with debugging
    //? 3. Commnly used in header files

    char name[] = "test";
    int age = 1230;
    hello(name, age);

    return 0;
}

void hello(char name[], int age){
    printf("\nHello %s you are %d year old", name, age);

}