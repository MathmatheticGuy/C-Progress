#include <string.h> // Include this to use strcat(), strcpy()
#include <stdio.h>  // Include this to use printf(), scanf()
#include <stdlib.h> // Include this to use malloc(), calloc(), free()

//? *inputNUm() returns a pointer to a char array
char *inputNum()
{ 
    int num;
    int binaryNum;
    static char store[123] = ""; // Initialize store to an empty string. And make it static so it won't be destroyed after the function call
    int count = 0; // This is optional. Use for printf infos

    do
    {
        printf("Enter num from 1 to 50: ");
        scanf("%d", &num);
    } while (num < 1 || num > 50);

    do
    {
        // Convert num to binary
        num /= 2;
        binaryNum = num % 2;
        count += 1;

        // Store binaryNum to a string
        char temp[2];
        sprintf(temp, "%d", binaryNum); // Convert binaryNum to temp string
        strcat(store, temp);            // Append temp to store

        // printf("%d\n", binaryNum); // print each binary character
        printf("Convert to binary %d time: %s\n", count, store);
    } while (num /= 2 > 0);

    printf("\n");
    return store;
}

// use short** to return a 2D array
short** dynamicArray(int rows, int cols)
{
    int var;

    if (rows < 1 || cols < 1){
        printf("No Rows and Cols, Bye Bye\n");
        return NULL;
    }

    // Dynamically allocate memory for 2D array
    short** Array2D = malloc(rows * sizeof(short*));
    for(int i = 0; i < rows; i++) {
        Array2D[i] = malloc(cols * sizeof(short));
    }

    // Enter 2DArray
    for (int i = 0; i < rows; i++)
    {
        printf("Enter value of the %d row\n", i);
        for (int j = 0; j < cols; j++)
        {
            printf("Enter 2 bytes value of the [%d] rows [%d] cols:", i, j);
            do{
                scanf("%d", &var);
                if (var > 32767 || var < -32768)
                    printf("Invalid value. Please enter a value between -32768 and 32767: ");
            }
            while(var > 32767 || var < -32768);

            Array2D[i][j] = var;
        }
        printf("\n");
    }

    return Array2D;
}


void enterArray(short *parr, int n){
    // parr is a pointer to the first element of the array
    int i = 0;
    for (;i < n; i++){
        // parr + i is the address of the i th element. Ex: parr + 1 is the address of the 2nd element
        printf("Enter the value of the %dth element:", i+1);
        scanf("%hd", parr + i);
    }
}

void findMin(short *parr, int n){
    short min = *parr;
    int minIndex = 0;

    for (int i = 0; i < n; i++){
        if (*(parr + i) < min){
            min = *(parr + i);
            minIndex = i;
        }
    }
    printf("Min value of the Array: %hd at %p\n", min, (parr + minIndex));
}


void writeArrayToFile(short *parr, int arrayLength, const char filename[20]){
    FILE* fp;
    fp = fopen(filename, "w");
    // char content[1000];

    if (fp != NULL){
        printf("File Open Successful\n");
        for (int i = 0; i < arrayLength; i++){
            if (i % 3 == 0 && i > 0){
                fputs("\n", fp);               
            }
            fprintf(fp, "%hd ", *(parr + i));
        }
    }
    else{
        printf("File Open Failed\n");
    }
}

void writeAddressToFile(short *parr, int arrayLength, const char filename[20]){
    FILE* fp;
    fp = fopen(filename, "w");
    // char content[1000];

    if (fp != NULL){
        printf("File Open Successful\n");
        for (int i = 0; i < arrayLength; i++){
            // if (i % 3 == 0 && i > 0){
                // fputs("\n", fp);               
            // }
            fprintf(fp, "Value %hd has address of %p\n", *(parr + i), (parr + i));
        }
    }
    else{
        printf("File Open Failed\n");
    }    
}


int main()
{
    char n[128];
    char m[128];

    // Exercise 1
    strcpy(n, inputNum()); // copy array of char from inputNum() to n copy n to m
    printf("Decimal to Binary: %s\n", n);
    

    // From the 3rd bit of n. Convert 1 to 0
    printf("From the 3rd bit of n convert 1 to 0\n");

    for (int i = 0; i < strlen(n); i++)
    {
        if (i > 1 && n[i] == '1')
        {
            n[i] = '0';
        }
        strncat(m, &n[i], 1); // Append n[i] to m
    }

    printf("Converted m: %s\n", m);

    //! Exercise 2
    int rows;
    int cols;
    
    // 2 Bytes integer
    // Called a short. It can store values ranging from -32,768 to 32,767.
    // In memory, a short takes up 2 bytes of

    printf("Enter total rows: ");
    scanf("%d", &rows);

    printf("Enter total cols: ");
    scanf("%d", &cols);

    short** Array2D = dynamicArray(rows, cols);
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%hd ", Array2D[i][j]);
        }
        printf("\n");
    }
    


    // Exercise 4
    short *parr;
    int arrayNum;
    
    printf("Enter the number of array elenments: ");
    scanf("%d", &arrayNum);
    
    // Allocate 2 bytes memory for n elements input
    parr = (short*) malloc(arrayNum * sizeof(short)); 
    enterArray(parr, arrayNum);

    
    printf("The array values are: \n");
    for (int i = 0; i < arrayNum; i++){
        // ouput the value and the memory address of each element
        printf("value %hd locate at %p \n", *(parr + i), (parr + i));
    }
    findMin(parr, arrayNum);

    
    //! Ex5: PRINT DYNAMIC ARR  AY FROM EXERCISE 2
    writeArrayToFile(parr, arrayNum, "array.txt");
    writeAddressToFile(parr, arrayNum, "mang_nguyen.txt");

    // free *parr from the memory
    free(parr);


    return 0;
}