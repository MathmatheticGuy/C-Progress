#include <stdio.h>

int main(){
    //* while loop = check the condition first, then run 
    //* do while loop = run first then check the condition

    //* continue = skip rest of code
    //* & force the next iteration of the loop

    int number = 0;
    int sum = 0;

    do {
        printf("Enter number > 10:");
        scanf("%d", &number);

        if (number > 10){
            sum += number;
        } 

    } while (number > 10);

    printf("sum: %d\n", sum + number);


    return 0;
}
