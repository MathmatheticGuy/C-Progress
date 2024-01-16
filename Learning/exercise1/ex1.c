#include <stdio.h>
#include <stdlib.h>

/*
    Câu 1 (2đ): Viết hàm nhập vào từ bàn phím số nguyên 2 byte n trong khoảng [1,20].
    Nhập sai thì nhập lại. Gọi hàm trong hàm main() để nhận giá trị của 2 biến nguyên m và n. 
    Hiển thị m trong dạng nhị phân.
*/
void toBinary(int m) {
    int a[10], i;
    for (i = 0; m > 0; i++) {
        a[i] = m % 2;
        m = m / 2;
    }
    printf("\nBinary of Given Number is = ");
    for (i = i - 1; i >= 0; i--) {
        printf("%d", a[i]);
    }
}

int convert() {
    int n;
    do {
        printf("Nhap so nguyen 2 byte (1-20): ");
        scanf("%d", &n);
    } while (n < 1 || n > 20);
    printf("n = %d\n", n);
    return n;
}

// Ex3. Viết hàm nhập mảng động 2 chiều với m dòng, n cột gồm m*n số nguyên không dấu 2 byte. Nhập sai thì nhập lại.
void inputDynamicArray() {
    int i, j;
    unsigned short **array;
    int m, n;

    // declare the array
    printf("Nhap so dong: ");
    scanf("%d", &m);
    printf("Nhap so cot: ");
    scanf("%d", &n);
    array = (unsigned short **)malloc(m * sizeof(unsigned short *));
    for (int i = 0; i < m; i++) {
        array[i] = (unsigned short *)malloc(n * sizeof(unsigned short));
    }
    
    // Input array
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            do {
                printf("Nhap phan tu [%d][%d]: ", i, j);
                scanf("%hu", &array[i][j]);
                if (array[i][j] < 0 || array[i][j] > 65535) {
                    printf("Nhap sai! Vui long nhap lai.\n");
                }
            } while (array[i][j] < 0 || array[i][j] > 65535);
        }
    }

    // Print array
    printf("\nArray elements:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%hu ", array[i][j]);
        }
        printf("\n");
    }
}

void write2DArrayToFile(unsigned short **array, int m, int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Cannot open file %s\n", filename);
        return;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(file, "%hu ", array[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}


int main() {
    int m = convert();
    toBinary(m);

    // Ex2. Trong hàm main() viết 1 lệnh lấy số tạo bởi bit thứ 3 và 4 từ phải sang trái của m. Hiển thị số tìm được.
    int bit3and4 = (m >> 2) & 0b11;
    printf("\nNumber formed by bits 3 and 4 from right to left: %d\n", bit3and4);

    
    // Declare and allocate memory for the dynamic 2D array
    unsigned short **pa;
    int n;
    printf("Nhap so dong: ");
    scanf("%d", &m);
    printf("Nhap so cot: ");
    scanf("%d", &n);
    pa = (unsigned short **)malloc(m * sizeof(unsigned short *));
    for (int i = 0; i < m; i++) {
        pa[i] = (unsigned short *)malloc(n * sizeof(unsigned short));
    }

    // Call inputDynamicArray()
    inputDynamicArray(pa, m, n);


    // Display the elements of the array
    printf("\nArray elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%hu ", pa[i][j]);
        }
        printf("\n");
    }

    // Write the 2D array to file
    write2DArrayToFile(pa, m, n, "mang2d_songuyen.txt");

    // Free the memory
    for (int i = 0; i < m; i++) {
        free(pa[i]);
    }
    free(pa);

    return 0;
}
