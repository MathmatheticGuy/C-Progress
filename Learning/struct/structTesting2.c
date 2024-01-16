#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//! 1. Define node Structure
typedef struct Student{
    char studentID[4];
    char studentName[129];
    float avgMark;
    struct Student* next;
} Student;

//! 2. Create Head Pointer
Student *head = NULL;

//! Input Node to Linked List
void nhap_danhsach(){

    Student *current;
    int n;
    printf("Enter total Student: ");
    scanf("%d", &n);
    
    
    for (int i = 0; i < n; i++){
        // use linked list so we must declare each new node 
        Student *newStd = (Student*) malloc(sizeof(Student));
        newStd->next = NULL;


        printf("Enter info of Student[%d]\n", i); 
        char input[130];

        //! problem: user input handling
        do {
            printf("Enter student[%d] ID: ", i);
            scanf("%d", input);
            // Remove trailing newline, if there is one
            input[strcspn(input, "\n")] = '\0';

            if (strlen(input) < 4){
                strncpy(newStd->studentID, input, 3);
                newStd->studentID[4] = '\0'; // '\0' should be placed at position 3, not 4
            } else {
                // Clear extra characters from input stream
                if (!strchr(input, '\n')) { // input was too long
                    int ch;
                    while ((ch = getchar()) != '\n' && ch != EOF);
                }
            }
        }
        while (strlen(input) > 4);
        
        // do {
        //     printf("Enter student[%d] Name: ", i);
        //     fgets(input, sizeof(input), stdin);
        //     // Remove trailing newline, if there is one
        //     input[strcspn(input, "\n")] = '\0';

        //     if (strlen(input) > 128){
        //         strncpy(newStd->studentName, input, 128);
        //         newStd->studentName[129] = '\0'; // '\0' should be placed at position 128, not 4
        //     } else {
        //         // Clear extra characters from input stream
        //         if (!strchr(input, '\n')) { // input was too long
        //             int ch;
        //             while ((ch = getchar()) != '\n' && ch != EOF);
        //         }
        //     }
        // }
        // while (strlen(input) < 128);

        printf("Enter Student[%d] avgMark: ", i);
        while (scanf("%f", &(newStd->avgMark)) != 1 || newStd->avgMark <= 0){
            scanf("%*[^\n]");
            printf("Invalid avgMark, Re-enter: ");
        }
        printf("\n");
    
        
        if (head == NULL){
            head = newStd;
            current = newStd;
        }
        else{
            current->next = newStd;
            current = newStd;
        }   
    }    
}

void in_danhsach(){
    Student *current = head;
    while (current != NULL){
        printf("Ma sinh vien: %s\n", current->studentID);
        // printf("Ten sinh vien: %s\n", current->studentName);
        printf("Diem trung binh: %.2f\n", current->avgMark);
        printf("--------------------\n");
        current = current->next; 
    }
}

void writeToFile(char path[100]){
    FILE *fp;
    fp = fopen(path, "w");
    
    if (fp == NULL){
        printf("Error opening file.\n");
        return;
    }

    Student *current = head;
    while (current != NULL){
        fprintf(fp, "%s %s %.2f\n", current->studentID, current->studentName, current->avgMark);
        current = current->next;
    }

    fclose(fp);    
}

void clearLinkedList(){
    Student *current = head;
    Student *nextStd;
    while (current != NULL){
        nextStd = current->next;
        free(current);
        current = nextStd;
    }
    head = NULL;
}

int main(){
    nhap_danhsach();
    in_danhsach();
    

    // writeToFile("danhsach_nguyen.txt");

    //! clear LinkedList and clear head pointer
    // clearLinkedList();


    return 0;
}