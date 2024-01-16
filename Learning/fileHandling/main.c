#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    #define FILENAME "ha.txt"
    #define FILENAME2 "ha2.txt"


    FILE* fptr;
    FILE* fptr2;

    fptr = fopen(FILENAME, "r");

    char content[1000];
    char content2[100];
    char array[1000];

    // check if file open or not
    if (fptr != NULL){
        printf("File Open Successful\n");
        // can only read 1 line of the file
        fgets(content, 1000, fptr); 
        strcat(array, content);

        printf("Content 1: %s\n", content);
        
        // read all available line (include empty line)
        while(fgets(content2, 100, fptr)){
            strcat(array, content2);
            printf("Content2: %s", content2);
        }
    }
    else{
        printf("File Open Failed\n");
    }

    // Write to file
    fptr2 = fopen(FILENAME2, "w");  

    fputs(array, fptr2);
    fputs("Programmierung C ist der beste\n", fptr2);
    

    // Closing file. The File cannot be manipulate now
    fclose(fptr);
    
    return 0;
}
