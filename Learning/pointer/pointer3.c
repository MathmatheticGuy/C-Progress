#include <stdlib.h> 
#include <stdio.h>

int main(){
    int a; //goes on stack
    int *p;
    int *b;

    p = (int*)malloc(sizeof(int)); 
    printf("%d\n", &p);
    *p = 10;
    free(p);

    b = calloc(4, sizeof(int)); // Allocates memory for 4 integers and initializes it to zero *b = 20;
    *b = 20;
    printf("current b memory address: %d\n", &b);
    printf("size of b: %d\n", sizeof(b));
    
    // 2 bytes decimal -> use shorr ("%ld" in scanf)
    printf("%d\n", *p);
}