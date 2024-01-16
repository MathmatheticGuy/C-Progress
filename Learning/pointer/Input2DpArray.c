#include <stdio.h>
#include <stdlib.h>


/**
 * This program demonstrates the dynamic allocation and manipulation of a 2D array using pointers in C.
 * It prompts the user to enter the number of rows and columns for the array, allocates memory for the array,
 * and then allows the user to input values for each element of the array.
 * Finally, it prints the array.
**/

int main(){
    int rows;
    int cols;

    //! get user input for 2D array size
    printf("Enter total rows: ");
    scanf("%d", &rows);
    printf("Enter total cols: ");
    scanf("%d", &cols);

    //! 2D array pointer
    int **arr;
   

    //! Assigning memory block for each rows and cols
    // allocate memory for the 2D array (for each rows (each cols inside that row) )
    // (int **) because we are declare an 2D array.  
    // as the 1st * pointed to the array, and the 2nd * pointed to the cols inside that array
    // When I declare rows * sizeof(int *) its mean I declare the array of pointer (int *) -> (*arr) == (*arr)[0]
    // Each of these pointers will point to the array of int (int) 
    // which is the columns (element) of the array pointer -> (*arr)[n]
    arr = (int **) malloc (rows * sizeof(int *));
    if (arr == NULL){
        printf("Memory allocation failed");
        exit(1);
    }

    for (int i = 0; i < rows; i++){
        // assign memory for each element (col) inside that row
        arr[i] = (int *) malloc(cols * sizeof(int));
    }

    //! get user input for each array elements
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("Enter element [%d][%d]: ", i, j);
            // scanf("%d", &(*(*(arr+i)+ j)));        
            //  scanf("%d", (*(arr+i)+ j));
            scanf("%d", &arr[i][j]);
        }
    }

    
    //! remember: p[1] == *(p + 1) == *p !== *p[1]
    // printf("%d\n", *(p[1] + 2));
    //! printf out the array
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            // arr[i][j] == *(*(arr + i) + j); 
            // printf("%d ", arr[i][j]);
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }

    return 0;
}

