#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


//! note: caution for scanf & and input data type like 
//! double - %lf

int enterDecimal(){
    int n;
    do{
        printf("Enter a number form 1 to 50: ");
        scanf("%d", &n);
    }
    while(n < 1 || n > 50);

    return n;
}

// void decimalToBinary(int n){
//     int store[1000]; // store binary chars. static so it won't be destroyed after the functon call
//     int i = 0;
        
//     // Step1: Convert num to binary
//     while (n > 0)
//     {
//         i++; // result i = 5. But store[0] leave empty
//         int binaryN = n % 2;
//         n /= 2;

//         store[i] = binaryN;
//         // caution - if put i++ at the end i will be 1 more than the actual number of digits. result in i = 6;        
//     }

//     printf("Binary:\n");
//     // print store array in reverse to get the binary format
//     //? why value at pos 6 is trash value ?
//     for (int j = i; j > 0 ; j--){
//         printf("%d - %d\n", j, store[j]);
//     }
// }


// 2 bytes array
void nhap_danhsach(short *arr, int n){
    long num;
    
    for (int i = 0; i < n; i++){
        // check if the input is short with long 
        do {
            printf("Enter a number between %d and %d: ", SHRT_MIN, SHRT_MAX);
            scanf("%ld", &num); //! remember long is %ld, short is %hd

            if (num < SHRT_MIN || num > SHRT_MAX) {
                printf("Invalid input, Re-Enter\n");
            }

        } while (num < SHRT_MIN || num > SHRT_MAX);
        
        // Type casting long num back to short num & save num to the array at i position
        arr[i] = (short) num;
    }
    
    printf("\n");
}
    
short minValue(short *arr, int n){
    short min = arr[0];
    int pos = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] < min) {
            min = arr[i];
            pos = i;
        }
    }
    printf("Min address: %d\n", &arr[pos]); // use for testing purpose
    return min;
}

// use *filename because it more dynamic 
// not use char filename[n] Filename is not restricted to [n] char length 
void writeArrayToFile(short *arr, int n, const char *filename){
    // FILE *fp; // declare a file pointer

    // open file in write mode
    char path[40] = "../FileHolder/";
    strcat(path, filename); // path = "../FileHolder/mang_nguyen.txt"
    FILE *fp = fopen(path, "w");
    if (fp == NULL){
        printf("Cannot open file\n");
        return;
    }
    
    for (int i = 0; i < n; i++){
        fprintf(fp, "%d", arr[i]);
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main(){
    //! Ex 1
    int n, m;
    n = enterDecimal();
    char binaryBuffer[33];
    // decimalToBinary(n); // self-made Decimal to Binary
    // itoa() a function use to convert decimal to binary
    itoa(n, binaryBuffer, 2);  // itoa(a_num, char_holder, base) base = 2 for binary, base = 10 for decimal, base = 16 for hexa, etc..
    printf("Binary form: %s\n", binaryBuffer);

    //! Ex 2
    // Check 3rd bit and set 0 if it is 1. 
    // Ex: 1 = 0001 (1 << 2) shift the bit two places to the left: 0001 -> 0100 which is 4 in decimal
    // n & (1 << 2). On the right side we have 1 as the 3rd bit. 
    // AND: 00 -> 0, 01 -> 0, 10 -> 0, 11 -> 1. So if n 3rd bit is 1, the result of n & (1 << 2) will be 1
    
    m = n;
    printf("before: %d\n", m);
    // 1100 = 12
    if (m & (1 << 2)){ // 1100 & 0100 = 1110 = 14 -> 3rd bit = 1 = True. If True then run the condition 
        m &= ~(1 << 2); // 1100 & 1011 = 1000 = 8 -> 3rd bit  = 0. Successfully convert 3rd of m from 1 to 0.
    }

    printf("after: %d\n", m);

    //! Ex4 
    // take n as the array length
    short* head;
    // allocate memory for each element in the array (base on the array length) 
    head = (short*) malloc (n * sizeof(short)
    if (head == NULL){
        printf("Cannot Allocate Memory\n");
    }

    //! Ex2
    nhap_danhsach(head, n);
    for (int i = 0; i < n; i++){
        printf("arr[%d] = %d at %d: \n", i, head[i], (void*)&head[i]);
    }

    //! Ex5
    int minVar;
    minVar = minValue(head, n);
    printf("min value of the array is %d", minVar);

    //! Ex6: Write array to file
    writeArrayToFile(head, n, "danhsach_nguyen.txt");
    free(head);

    // return 0;
}





















