#include <stdio.h>
#include <stdlib.h>

int main(){
    int number;
    char ch;
    char *Prompt2 = "":
    do {
    printf("%sEnter number :", Prompt2);
    Prompt2 = "Invalid input\n";  // Change Prompt2 
    buffer char[50];
    if (fgets(buffer, sizeof buffer, stdin) == NULL) {
        Handle_EOF();
    }  
    } while (sscanf(buffer, "%d %c", &number, &ch) != 1);
}
