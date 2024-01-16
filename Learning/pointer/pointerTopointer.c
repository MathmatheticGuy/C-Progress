#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    int x = 213;
    int *p = &x;
    printf("x addr= %d\n", &x); 

    printf("p = %d\n", *p);
    printf("p addr= %d\n",  p);
    
    *p = 99;
    
    // pointer r pointed to pointer p address
    int **r = &p;
    
    printf("r = %d\n", **r);
    printf("r addr = %d\n", &r);
    **r = 69;
    int ***h =&r;
    printf("h = %d\n", ***h);
    printf("h addr= %d\n", h);

    // deference mean the value at the memory address h pointed to changed with h. 
    // h hold the address of r, r hold the address of p, p hold the address of x.
    // ***h -> **r -> *p -> x (so ***h = x) therefor ***h = 5 mean x = 5
    
    ***h = 5; // Because h pointed to r pointed to p pointed to x.
    **r = *p + 1; // Because x value changed to 5. So *p = 5 and **r = 5 + 1 = 6
    printf("p = %d\n", *p); // should be 6
    


    return 0;   
}