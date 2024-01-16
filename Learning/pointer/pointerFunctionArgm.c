#include <stdio.h>
#include <stdlib.h>

void incr(int *p){
    *p = *p + 1;
}

void incrPa(int **g){
    //? g the pointer to p
    **g = **g + 1;
}

int main(){
    int a = 5;
    int b = 10;
    //! int *p = 10 is wrong, bc *p get the value of it pointed address. Not the value it pointed to 
    int *p = &b;
    incr(&a);
    incrPa(&p);
  
    //! change value of a without using return in a function using pointer.
    printf("a = %d\n", a); // should be 6. Because a value changed to 6 in incr function.
    printf("b = %d\n", *p); // should be 11. Because b value changed to 11 in incrPa function.
    

    return 0;
}