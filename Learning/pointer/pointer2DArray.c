#include <stdio.h>



int main(){
    int (*arr)[3]; // which means "pointer to an array of 3 integers"
    int nums[2][3] = {{1, 2, 3}, {4, 5, 6}};
    arr = nums; //? *arr this pointed to the first element of nums, which is {1, 2, 3} 
    //? notice: arr = &nums[0].


    
    for (int i = 0; i < 2; i++) { // this loop 2 times
        for (int j = 0; j < 3; j++) { // this loop 3 times
            //! *(arr + i) pointed to the i array (i row)
            //! *(*(arr + i) + j) pointed to the element (j column) of the array. with j the position of the element inside the array
            // *arr + i = {1,2,3} + i 
            // *arr + 0 = {1,2,3} + 0 = {1,2,3}. This move to the first element of nums, which is {1, 2, 3}
            // *arr + 1 = {1,2,3} + 1 = {1,2,3} + 1 = {4,5,6}. This move to the second element of nums, which is {4, 5, 6}
            //? caution: i use to move rows, j use to move columns
            printf("%d ", *(*arr + i) + j);
        }
        printf("\n");
    }


    return 0;
}