#include <stdio.h>

// Hàm kiểm tra số nguyên n có nằm trong khoảng [1, 50] hay không
int isValid(int n) {
    return (n >= 1 && n <= 50);
}

// Hàm nhập số nguyên 1 byte từ bàn phím trong khoảng [1, 50]
int inputNumber() {
    int n;
    do {
        printf("Nhap so nguyen 1 byte trong khoang [1, 50]: ");
        scanf("%d", &n);

        if (!isValid(n)) {
            printf("Nhap sai. Vui long nhap lai.\n");
        }

    } while (!isValid(n));

    return n;
}

// Hàm hiển thị số nguyên n dưới dạng nhị phân
void displayBinary(int n) {
    printf("Gia tri n duoi dang nhi phan: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

struct Student {
    char studentID[4];
    char studentName[129];
    float avgMark();
    struct Student *next;
}

int main() {
    // Gọi hàm để nhận giá trị của biến nguyên n
    int n = inputNumber();

    // Hiển thị giá trị của n dưới dạng nhị phân
    displayBinary(n);

    // Lấy giá trị 4 bit cao nhất của n
    int high4Bits = (n >> 4) & 0xF;
    printf("4 bit cao nhat cua n la: %d\n", high4Bits);

    return 0;
}