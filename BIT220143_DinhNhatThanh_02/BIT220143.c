#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct staff {
    char staffID[4];
    char staffName[129];
    float salary;
    struct staff* next;
} staff;


int getInput() {
    char str[2];
    int num;
    bool check = false;

    printf("Enter an integer between 0 and 11: ");
    while (!check) {
        if (scanf("%d", &num) != 1) {
            printf("You enter wrong! Enter again.\n");
            while (getchar() != '\n'); // Xoa bo nho dem
        } else {
            if (num < 0|| num> 11 ) {
                printf("You enter wrong! Enter again.\n");
            } else {
                check = true;
            }
        }
    }
    return num;    
}


staff* nhap_danhsach(int n){
    staff *head;
    char input[200];

    head = (staff*) malloc(n * sizeof(staff));
    
    for (int i = 0; i < n; i++){
        printf("Enter info of staff[%d]\n", i); 

        do {
            printf("Enter staff[%d] ID: (4 characters max) ", i);
            scanf("%s", input);
           if (strlen(input) < 4){
                strncpy(head[i].staffID, input, 4);
                head[i].staffID[5] = '\0';  // make sure the last index null 
           }else{
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF); 
           }

        }
        while (strlen(input) > 4);
    
        do {
            printf("Enter staff[%d] Name: ", i);
            scanf("%s", &input);
            if (strlen(input) < 129){
                strncpy(head[i].staffName, input, 129);
                head[i].staffName[130] = '\0';
            }
            else{
                int ch;
                while (ch = getchar() != '\n' && ch != EOF);
            }
        }
        while (strlen(input) > 129);



        printf("Enter staff[%d] salary: ", i);
        while (scanf("%f", &head[i].salary) != 1 || head[i].salary < 0){
            printf("Invalid salary, Re-enter: ");
            while (getchar() != '\n'); // Clear input buffer
        }
        printf("\n");
    }

    return head;

}


void hienthi_ds(staff *head, int n){
    printf("Hien thi thong tin nhan vien salary cao hon 10 000 000 dong: \n");

    for (int i = 0; i < n; i++){
        if (head[i].salary > 10000000){
            printf("staff ID: %s\n", head[i].staffID);
            printf("staff Name: %s\n", head[i].staffName);        
            printf("staff avgMark: %.3f\n", head[i].salary);
            printf("\n");
        }
    }
}


void writeToFile(staff *head, int n, char path[100]){
    FILE *fp;
    fp = fopen(path, "w");
    
    if (fp == NULL){
        printf("Error opening file.\n");
        return;
    }
    
    for (int i = 0; i < n; i++){
        fprintf(fp, "Staff Info\n");
        fprintf(fp, "%s, %s, %.3f", head[i].staffID, head[i].staffName, head[i].salary);        
        fprintf(fp, "\n");
    }

    fclose(fp);    
}

int main(){
    //! Ex1
    int n = getInput();
    char binaryNum[32];

    printf("You entered: %d\n", n);
    int inNum = n + 200;
    itoa(inNum, binaryNum, 2);
    printf("%d+200 in Binary: %s\n", n, binaryNum);

    //! Ex2
    int highest3bits = (inNum >> 6) & 0xF;
    printf("highest bytes: %d", highest3bits);
    printf("\n");

    //! Ex3
    staff *head;
    head = nhap_danhsach(n);

    //! Ex4
    hienthi_ds(head, n);

    writeToFile(head, n, "danhsach_cautruc.csv");

    //! Ex5
    for (int i = 0; i < n; i++) {
        free(head[i].staffID);
        free(head[i].staffName);
        // free(head[i].salary);
    }
    free(head);
    head = NULL;

    hienthi_ds(head, n);
}