#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// void result_and_score(int player_index_choice,int bot_index_choice);

int main(){
    srand (time(NULL));
    int player_throw = 0;
    int ai_throw = 0;


    do{
        printf("Select your throw.\n");
        printf("1) ROCK\n 2) PAPER\n 3) SCISSORS\n");
        printf("Selection: ");
        scanf("%d", &player_throw);
        
        if (player_throw < 1 || player_throw > 3){
            printf("Invalid input. Please enter a value between 1 and 3\n");
        }

        char choice[20] = {"ROCK", "PAPER", "SCISSORS"}; 
        ai_throw = (rand() % 3);
        printf("AI throws: %s\n", choice[ai_throw]);

        // result_and_score(player_throw-1, ai_throw);
        break;

    }while (1);

    return 0;
}



// void result_and_score(int player_index_choice,int bot_index_choice){
//     int rps_matrix[4][3] = {
//         {0,2,1},
//         {1,0,2},
//         {2,1,0},
//         {3,3,3},
//     }

//     int result_index = rps_matrix[player_index_choice][bot_index_choice];
//     char result[] = {"Tie", "You Lose", "You Won", "Invalid Input"};
//     printf("%s\n",result[result_index] + "\n");    
// }