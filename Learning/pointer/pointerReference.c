#include <stdio.h>


void add_to_int(int *p){
    (*p)+=5;
}

int main(){
    int a = 0;
    int *ra = &a;

    
    printf("%d\n", a);
    printf("%d\n", *ra);
    
    add_to_int(ra);
    
    printf("%d\n", a);
    printf("%d\n", *ra);

    return 0;
}