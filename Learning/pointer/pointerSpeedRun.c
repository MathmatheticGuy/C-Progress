#include <stdio.h>
#include <stdlib.h>

int main(){
    int rows;
    int cols;
    int **pa;

    printf("Enter tol rows: ");
    scanf("%d", &rows);

    printf("Enter tol cols: ");
    scanf("%d", &cols);


    pa = (int **) malloc(rows * sizeof(int *));
    if (pa == NULL){
        printf("pa ml fail");
    }

    for (int i = 0; i< rows; i++){
        pa[i] = (int *) malloc (cols * sizeof(int));
        if (pa == NULL){
            printf("pa ml fail");
        }
    }
    
    for (int i = 0;i< rows; i++){
        for (int j = 0;j< cols; j++){
            printf("Enter pa[%d][%d]: ", i, j);
            scanf("%d", &pa[i][j]);
        }
    }

    for (int i = 0;i< rows; i++){
        for (int j = 0;j< cols; j++){
            printf("%d ", pa[i][j]);     
        }
        printf("\n");
    }

    return 0;

}
