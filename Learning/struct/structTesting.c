#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Student{
    char studentID[4];
    char studentName[129];
    float avgMark;
    struct Student* next;
} Student;

Student* nhap_danhsach(int n){
    Student *head;
    char input[130];

    head = (Student*) malloc(n * sizeof(Student));
    for (int i = 0; i < n; i++){
        printf("Enter info of Student[%d]\n", i); 

        do {
            printf("Enter student[%d] ID: ", i);
            scanf("%s", input);
           if (strlen(input) == 3){
                strncpy(head[i].studentID, input, 3);
                head[i].studentID[3] = '\0'; // index start from 0 so '\0' will be place at the position 4, index 3. 
           }else{
                // make a input to read all the leftover chars form the input stream to prevent stack-overflow 
                int ch;
                //? This loop will continue reading and discarding characters 
                //? until it encounters a newline or end-of-file. This effectively clears the input stream of any extra characters.
                //! Basically ch take in each chars from the input stream 1 by 1 until it reach the EOF and '\n'
                while ((ch = getchar()) != '\n' && ch != EOF); 
           }

        }
        while (strlen(input) != 3);
    
        do {
            printf("Enter student[%d] Name: ", i);
            scanf("%s", &input);
            if (strlen(input) < 128){
                strncpy(head[i].studentName, input, 128);
                head[i].studentName[128] = '\0';
            }
            else{
                int ch;
                while (ch = getchar() != '\n' && ch != EOF);
            }
        }
        while (strlen(input) > 128);



        printf("Enter Student[%d] avgMark: ", i);
        while (scanf("%f", &head[i].avgMark) != 1 || head[i].avgMark < 0){
            printf("Invalid avgMark, Re-enter: ");
        }
        printf("\n");
    }
  
    return head;
}

void hienthi(Student *head, int n){
    printf("Hien thi thong tin hs: \n");
    Student *current = head;
    while (current != NULL){
        printf("%s %s %.2f\n", current->studentID, current->studentName, current->avgMark);
        current = current->next;
    }
    // for (int i = 0; i < n; i++){
    //     printf("Student ID: %s\n", head[i].studentID);
    //     printf("Student Name: %s\n", head[i].studentName);
    //     printf("Student avgMark: %.3f\n", head[i].avgMark);
    //     printf("\n");
    // }
}

void writeToFile(Student *head, int n, char path[100]){
    FILE *fp;
    fp = fopen(path, "w");
    
    if (fp == NULL){
        printf("Error opening file.\n");
        return;
    }
    
    for (int i = 0; i < n; i++){
        fprintf(fp, "Student ID: %s\n", head[i].studentID);
        fprintf(fp, "Student Name: %s\n", head[i].studentName);
        fprintf(fp, "Student avgMark: %.3f\n", head[i].avgMark);
        fprintf(fp, "\n");        
    }
    fclose(fp);    
}

int main(){
    int n;
    Student *head;

    printf("Enter total Student: ");
    scanf("%d", &n);
    head = nhap_danhsach(n);
    hienthi(head, n);
    writeToFile(head, n, "danhsach_nguyen.txt");

    free(head);
    return 0;

}