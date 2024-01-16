#include <stdio.h>
#include <stdlib.h>

int getInput() {
    char str[2];
    int num;
    do {
        printf("Enter an integer between 1 and 50: ");
        scanf("%s", &str);
        num = atoi(str);
        if (num < 1 || num > 50){
            printf("Invalid input. Please try again.\n");
        }

    } while (num < 1 || num > 50);

    return num;
}

struct Student {
    char studentID[4];
    char studentName[129];
    float avgMark();
    struct Student *next;
}

void nhap_danhsach(){

}

int main() {
    //! ex1: 1 byte decimale to binary
    int num = getInput();
    char binaryNum[32];
    printf("You entered: %d\n", num);
    itoa(num, binaryNum, 2);
    printf("Binary: %s\n", binaryNum);

    //! ex2: highest 4 bits 
    int highest4bits = (num >> 4) & 0xF;
    printf("highest bytes: %d", highest4bits);
    
    //! ex3: Write the function nhap_danhsach to input from the keyboard a list with the structure Student (do not enter the next field). Gas
    //! enter the elements of the list, if entered incorrectly, re-enter.
    nhap_danhsach();
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
