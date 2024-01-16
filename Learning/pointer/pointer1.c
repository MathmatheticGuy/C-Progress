#include <stdio.h> 
#include <stdio.h>
#include <string.h>


int main(){
    int slices = 20;
    int *p = &slices;
    printf("Slices: %d\n", slices);
    printf("Slices: %d\n", &p);
    printf("Slices: %d\n", &slices);
    
    (*p)++; // increament the value of slices
    printf("Da Slices: %d\n", *p);
    

    if (*p == slices){
        printf("True\n");
    }

    return 0;
}