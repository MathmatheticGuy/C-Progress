#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char game[20];
    printf("What is your favourite game: ");
    scanf("%19s", game);

    printf("%sjhwerhjkbjk", game);
    int charCount = strlen(game);
    // while (game[charCount] != '\0'){
    //     charCount++;
    // }
    printf("\nThe length of the string is %d", charCount);



    return 0;
}
