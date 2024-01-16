#include <stdio.h>
#include <stdlib.h>

int main() {
    // Đọc vào số n từ bàn phím
    int n;
    printf("Nhập số n: ");
    scanf("%d", &n);

    // Khởi tạo mảng và gán giá trị từ 1 đến n
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
    {
        arr[i] = i + 1;
    }

    // Ghi mảng vào file nhị phân
    FILE *fp = fopen("../../FileHolder/array.bin", "wb");
    fwrite(arr, sizeof(int), n, fp);
    fclose(fp);

    // Gán n = -1
    n = -1;

    // Mở file nhị phân để đọc và hiển thị mảng (với lỗi)
    fp = fopen("../../FileHolder/array.bin", "rb");
    if (fp == NULL) {
        printf("Không thể mở file!\n");
        return 1;
    }

    // Đọc mảng từ file nhị phân (với lỗi)
    int *read_arr = (int *)malloc((n + 1) * sizeof(int)); // Cấp phát động với kích thước lớn hơn
    fread(read_arr, sizeof(int), n, fp); 
    fclose(fp);

    // Hiển thị mảng đọc được (với lỗi)
    printf("Mảng sau khi đọc từ file nhị phân: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", read_arr[i]);
    }
    printf("\n");

    // Giải phóng bộ nhớ (với lỗi)
    free(arr);
    free(read_arr);

    return 0;
}