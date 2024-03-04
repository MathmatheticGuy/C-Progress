#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct staff
{
    char staffID[4];
    char staffName[129];
    float salary;
    struct staff *next;
} staff;

int input()
{
    int num;
    bool valid = false;

    while (!valid)
    { // !valid = true
        printf("Enter an integer number: ");
        if (scanf("%d", &num) != 1)
        {
            printf("Invalid Input\n");
            while (getchar() != '\n')
                ;
        }
        else
        {
            if (num < 1 || num > 50)
            {
                printf("Number out of range\n");
            }
            else
            {
                valid = true;
            }
        }
    }

    return num;
}

staff *enterStaffArray(){
    staff *head;
    char input[200];
    
    head = (staff *) malloc(n * sizeof(staff));

}

int main()
{
    int n;
    char binary[12]; // lenght of 9. Bc last element is NULL
    n = input();

    itoa(n + 200, binary, 2);
    printf("binary form: %s\n", binary);

    // get 3s highest bytes (1-bit has 8-bytes)
    int highestBytes = (n >> 5) & 0xF; // 0xF == 00000000 (8x0 bytes)
    printf("highestBytes: %d", highestBytes);

    staff *head;
    head = enterStaffArray();

    return 0;
}