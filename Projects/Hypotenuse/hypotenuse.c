#include <stdio.h>
#include <math.h>

double hypotenuse(double a, double b){
    double c = sqrt(pow(a, 2) + pow(b, 2));
    return c;    
}
int main(){
    double num1;
    double num2;

    printf("Enter a num:" );
    scanf("%lf", &num1);

    printf("Enter another num:" );
    scanf("%lf", &num2);
    
    printf("%f", hypotenuse(num1, num2));
}