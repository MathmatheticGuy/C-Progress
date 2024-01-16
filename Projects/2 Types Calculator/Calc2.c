#include <stdio.h>
#include <string.h>

//! Using Switch Operator
double calculator(double a, char op, double b){
    double result;
    
    switch (op){
        case '+': 
            result = a + b;
            break;
        case '-': 
            result = a - b;
            break;
        case '*': 
            result = a * b;
            break;
        case '/': 
            result = a / b;
            break;
        default:
            printf("Invalid operator /n");
        return 0;
    }

    return result;
}
 
int main(){
    double num1;
    char op;
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