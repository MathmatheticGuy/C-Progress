#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char studentID[4];
    char studentName[129];
    float avgMark;
} Student;

Student* nhap_danhsach(int n);

int main() {
    // Test 1: n = 1
    int n = 1;
    Student* std1 = nhap_danhsach(n);
    printf("Student ID: %s\n", std1[0].studentID);
    printf("Student Name: %s\n", std1[0].studentName);
    printf("Average Mark: %.2f\n", std1[0].avgMark);
    free(std1);

    // Test 2: n = 3
    n = 3;
    Student* std2 = nhap_danhsach(n);
    for (int i = 0; i < n; i++) {
        printf("Student ID: %s\n", std2[i].studentID);
        printf("Student Name: %s\n", std2[i].studentName);
        printf("Average Mark: %.2f\n", std2[i].avgMark);
    }
    free(std2);

    return 0;
}