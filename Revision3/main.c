// 2D array speed run
#include <stdio.h>
#include <stdlib.h>

int enterNum(){
    int m;
    do{
        printf("Enter a number from 1 to 50: ");
        scanf("%d", &m); 

        if (m < 1 || m > 50){
            printf("Invalid\n");
        }
    }
    while (m < 1 || m > 50);
    
    printf("\n");
    return m; 
}



//! int ***arr mean a pointer pointed to &p. (to modify a pointer we must we another pointer) 
int** array2D(int rows, int cols){
    int** arr;

    arr = (int **) malloc(rows * sizeof(int *));

    for (int i = 0; i <rows;i++){
        arr[i] = (int*) malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("Enter element [%d][%d]: ", i, j);
            // scanf("%d", &(*(*(arr+i)+ j)));        
            //  scanf("%d", (*(arr+i)+ j));
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return arr;

}

void colSum(int **arr, int rows, int cols) {
    int sum = 0;
    for(int i = 0; i < rows; i ++){     
        for(int j = 0; j < 1; j ++){
            sum += arr[i][0];
        }
    }
    printf("Sum of the first cols: %d", sum);
}

void arrayToFile(int** arr, int rows, int cols){
    FILE* pf;
    pf = fopen("mang2_sothuc.txt", "w");
    
    // fprintf(pf, "%d %d\n", rows, cols);    
    for(int i = 0; i < rows; i ++){     
        for(int j = 0; j < cols; j ++){
            fprintf(pf, "%d ", arr[i][j]);
        }
        fprintf(pf, "\n");
    }

    fclose(pf);
}

int main(){
    int m, n;
    char binary[100];
    m = enterNum();
    itoa(m, binary, 2);
    printf("%s\n", binary);

    // get high bytes of m.
    // 0xFF = 11111111 (use to keep only the significant bit: 1 using AND operator)
    // if m = 48 and shift 8 bytes to the right we get 00000000 00000000
    // so (m >> 8) & 0xFF the highest bytes will be 0 (only take the 1st bytes, value doesn't need to be 1 it can be 0)
    
    // unsigned char high_byte = (m >> 8) & 0xFF;
    // printf("The highest by of number: %s\n", high_byte);
    printf("highest bytes: %d\n", m >> 8);


    int rows;
    int cols;

    printf("Enter tol rows: ");
    scanf("%d", &rows);
    printf("Enter tol cols: ");
    scanf("%d", &cols);

    int **pa;
    //todo: how to save a 2D Array to pa without return value from array2D (purpose: save more memory) 
    pa = array2D(rows, cols);
    colSum(pa, rows, cols);
    

    arrayToFile(pa, rows, cols);
    
    for (int i = 0; i < rows; i++){
        free(pa[i]);  // Free each row
    }
    free(pa);  // Free the array of pointers
    return 0;

}