#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char studentID[4];
    char studentName[129];
    float avgMark;
    struct Student* next;
} Student;

void nhap_danhsach(Student* head, int n) {
    head = NULL;
    Student* current = NULL;
    Student* newStudent = NULL;

    for (int i = 0; i < n; i++) {
        newStudent = (Student*)malloc(sizeof(Student));
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        
        char input[129];

        do {
            printf("Nhap ma sinh vien: ");
            scanf("%s", input);
            if (strlen(input) < 4) {
                strncpy(newStudent->studentName, input, 4);
                newStudent->studentName[4] = '\0';
            } else {
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF);
            }
        } while (strlen(input) > 4);
        
        do {
            printf("Nhap ten sinh vien: ");
            scanf("%s", input);
            if (strlen(input) < 128) {
                strncpy(newStudent->studentName, input, 128);
                newStudent->studentName[128] = '\0';
            } else {
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF);
            }
        } while (strlen(input) > 128);
        
        printf("Nhap diem trung binh: ");
        if (scanf("%f", &(newStudent->avgMark)) != 1) {
            printf("Loi nhap diem trung binh.\n");
            return;
        }

        newStudent->next = NULL;

        if(head == NULL) {
            head = newStudent;
            current = newStudent;
        } else {
            // point the current Node to the newest Node and
            // made the newStudent become the current Node 
            current->next = newStudent;
            current = newStudent;
        }
    }
}

void ghi_danhsach(Student* head, int n) {
    FILE* file = fopen("danhsach_nguyen.txt", "w");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    Student* current = head;
    while (current != NULL) {
        fprintf(file, "%s %s %.2f\n", current->studentID, current->studentName, current->avgMark);
        current = current->next;
    }

    fclose(file);
}

int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    Student* head = NULL;
    nhap_danhsach(head, n);

    printf("\nDanh sach sinh vien:\n");
    Student* current = head;
    while (current != NULL) {
        printf("Ma sinh vien: %s\n", current->studentID);
        printf("Ten sinh vien: %s\n", current->studentName);
        printf("Diem trung binh: %.2f\n", current->avgMark);
        printf("--------------------\n");
        current = current->next;
    }

    ghi_danhsach(head, n);

    // Giải phóng vùng nhớ của dây chuyền n phần tử
    current = head;
    while (current != NULL) {
        Student* temp = current;
        current = current->next;
        free(temp);
    }

    // Gán địa chỉ head về giá trị phù hợp
    head = NULL;
    

    return 0;
}