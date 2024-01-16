#include <string.h>
#include <stdio.h>


#define FILENAME "hey.txt"
#define FILENAME2 "kobe.txt"

int main(){

    FILE* pf;
    char store[200];

    if (pf != NULL){
        pf = fopen(FILENAME, "w");
        fputs("Hellw World\n", pf);
        fputs("Hello World\n", pf);
        // must close the file after write to it
        fclose(pf);
    }
    
    
    pf = fopen(FILENAME, "r");    
    if (pf != NULL){
        while(fgets(store, 200, pf) != NULL){
            printf("%s\n", store);
        }
    }
    else{
        perror("File Open Failed\n");
    }
    

}