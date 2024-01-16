#include <stdio.h>

int main(){
    int d;
    int b;
    char a; // declare c as an array of characters

    printf("Enter a sth: ");
    scanf("%d", &d);

    getchar(); // read the newline character (enter key
    
    printf("Enter a sth: ");
    scanf("%c", &a); // read a string into c
    
    printf("%d\n", d);
    printf("%c\n", a); // print the string
    
    return 0;
}
    
