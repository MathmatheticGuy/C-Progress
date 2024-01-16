#include <stdio.h>

int main(){
    int num = 0;
    for (int i=0; i < 11; i++){
        for (int j=i; j >= 0; j--){
            printf("%d ", j);
        }
        printf("\n");
    }
}