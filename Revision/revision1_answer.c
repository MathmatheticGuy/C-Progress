#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Câu 1: Nhập số nguyên n từ bàn phím
int nhapSoNguyenN()
{
    int n;
    do
    {
        printf("Nhap so nguyen n (1 <= n <= 50): ");
        scanf("%d", &n);
        if (n < 1 || n > 50)
        {
            printf("So nguyen n nhap vao khong hop le. Vui long nhap lai!\n");
        }
    } while (n < 1 || n > 50);
    return n;
}

// Câu 3: Chuyển số nguyên n sang hệ nhị phân
void nhapMang(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Câu 5: Tìm giá trị nhỏ nhất trong mảng
int timMin(int *arr, int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

// Câu 6: Ghi mảng n phần tử vào file
void ghiMangVaoFile(int *arr, int n, const char *tenFile)
{
    
    char path[40] = "../FileHolder/";
    strcat(path, tenFile); // path = "../FileHolder/mang_nguyen.txt"
    

    FILE *f = fopen(path, "w");
    if (f == NULL)
    {
        printf("Khong mo duoc file de ghi!\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%d ", arr[i]);
        if ((i + 1) % 3 == 0)
        { // In tối đa 3 số trên một dòng
            fprintf(f, "\n");
        }
    }
    fclose(f);
}

void main()
{
    int n, m;
    char st[32 + 1];
    n = nhapSoNguyenN();
    itoa(n, st, 2);
    printf("n duoi dang nhi phan %s", st);

    // câu 2
    if (n & 4) // 4=100
    {
        m = n ^ 4;
        itoa(m, st, 2);
        printf("\n %d co bieu dien bit=%s\n", m, st);
    } // if

    // Câu 4
    int *pa = (int *)malloc(n * sizeof(int));
    if (pa == NULL)
    {
        printf("Loi: Khong the cap phat bo nho cho mang!\n");
    }

    nhapMang(pa, n);
    // Câu 5
    int min = timMin(pa, n);
    printf("Gia tri nho nhat trong mang la: %d\n", min);

    // Câu 6
    ghiMangVaoFile(pa, n, "mang_nguyen.txt");
    printf("Da ghi mang vao file mang_nguyen.txt\n");

    // Giải phóng vùng nhớ đã cấp phát
    free(pa);
    pa = NULL;
}