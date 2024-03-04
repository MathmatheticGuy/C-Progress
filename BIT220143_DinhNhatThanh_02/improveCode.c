#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct staff {
    char staffID[5]; // Increase size to accommodate null terminator
    char staffName[130]; // Increase size to accommodate null terminator
    float salary;
    struct staff* next;
} staff;

int getInput() {
    int num;
    bool check = false;

    printf("Enter an integer between 0 and 11: ");
    while (!check) {
        if (scanf("%d", &num) != 1) {
            printf("You entered wrong! Enter again.\n");
            while (getchar() != '\n'); // Clear input buffer
        } else {
            if (num < 0 || num > 11) {
                printf("You entered wrong! Enter again.\n");
            } else {
                check = true;
            }
        }
    }
    return num;    
}

staff* nhap_danhsach(int n) {
    staff *head;
    char input[200];

    head = (staff*) malloc(n * sizeof(staff));
    
    for (int i = 0; i < n; i++) {
        printf("Enter info of staff[%d]\n", i); 

        do {
            printf("Enter staff[%d] ID: (4 characters max) ", i);
            scanf("%4s", input); // Limit input to 4 characters
            strncpy(head[i].staffID, input, 4);
            head[i].staffID[4] = '\0'; // Null terminate the string

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF); // Clear input buffer
        } while (strlen(input) > 4);
    
        do {
            printf("Enter staff[%d] Name: ", i);
            scanf("%129s", input); // Limit input to 129 characters
            strncpy(head[i].staffName, input, 129);
            head[i].staffName[129] = '\0'; // Null terminate the string

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF); // Clear input buffer
        } while (strlen(input) > 129);

        printf("Enter staff[%d] salary: ", i);
        while (scanf("%f", &head[i].salary) != 1 || head[i].salary < 0) {
            printf("Invalid salary, Re-enter: ");
            while (getchar() != '\n'); // Clear input buffer
        }
        printf("\n");
    }

    return head;
}

void hienthi_ds(staff *head, int n) {
    printf("Displaying information of employees with salary higher than 10,000,000 VND: \n");

    for (int i = 0; i < n; i++) {
        if (head[i].salary > 10000000) {
            printf("Staff ID: %s\n", head[i].staffID);
            printf("Staff Name: %s\n", head[i].staffName);        
            printf("Staff Salary: %.3f\n", head[i].salary);
            printf("\n");
        }
    }
}

void writeToFile(staff *head, int n, char path[100]) {
    FILE *fp;
    fp = fopen(path, "w");
    
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    for (int i = 0; i < n; i++) {
        fprintf(fp, "Staff Info\n");
        fprintf(fp, "%s, %s, %.3f", head[i].staffID, head[i].staffName, head[i].salary);        
        fprintf(fp, "\n");
    }

    fclose(fp);    
}

int main() {
    int n = getInput();
    char binaryNum[33]; // Increase size to accommodate null terminator

    printf("You entered: %d\n", n);
    int inNum = n + 200;
    itoa(inNum, binaryNum, 2);
    printf("%d+200 in Binary: %s\n", n, binaryNum); // 8 bits numbers

    int highest3bits = (inNum >> 5) & 0xF; // bit shift 5 bit to get the last 3 bytes 
    printf("Highest 3 bits: %d\n", highest3bits);

    staff *head;
    head = nhap_danhsach(n);

    hienthi_ds(head, n);

    writeToFile(head, n, "danhsach_cautruc.csv");

    for (int i= 0; i < n; i++){
        free(head[i].staffID);
        free(head[i].staffName);
    }
    free(head);
    

    hienthi_ds(head, n);
}