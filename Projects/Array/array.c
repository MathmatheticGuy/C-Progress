#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char sizeChar[123];
    int size;
    


    printf("Enter the size of the array: ");
    scanf("%s", &sizeChar);
    
    for(int i=0; sizeof(sizeChar) != "\0"; i++){ // for loop if there isn't a null character
        if (isdigit(sizeChar[i])){
            printf("Is Digit\n");
            break;
        }
    }
    printf("Enter the size of the array: %s", sizeChar);
    
}