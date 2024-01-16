#include <stdio.h>
#include <string.h>

//! Using strcmp() from <string.h> library
double calculator(double a, char op[1], double b){
    double result;
    
    if (strcmp(op,"+") == 0){
        result = a + b;
    }else if (strcmp(op,"-") == 0){
        result = a - b;
    }else if (strcmp(op,"*") == 0){
        result = a * b;
    }else if (strcmp(op,"/") == 0){
        result = a / b;
    }else{
        printf("Invalid Operator");
        return 0;
    }
    return result;
}
 
int main(){
    double num1;
    char op[1];
    double num2;

    printf("Enter 1st num: ");
    scanf("%lf", &num1);
    
    
    printf("Enter an operator (+, -, *, /): ");
    // because scanf reads the newline character from the previous input
    scanf(" %c", &op); 
    
    printf("Enter 2nd num: ");
    scanf("%lf", &num2);
    
    
    double result = calculator(num1, op, num2);
    printf("Result: %f\n", result);
    return 0;
}