#include <stdio.h>

int main() {
    // Mảng dữ liệu cần ghi vào file CSV
    char *data[4][3] = {
        {"Name", "Age", "City"},
        {"John", "25", "New York"},
        {"Anna", "30", "London"},
        {"Mike", "35", "Berlin"}
    };

    // Mở file "output.csv" ở chế độ ghi (với lỗi)
    FILE *fp = fopen("../../FileHolder/outputt.csv", "w");
   
    // Ghi dữ liệu vào file CSV (với lỗi)
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            fprintf(fp, "%s", data[i][j]);
            if (j < 2) {
                fprintf(fp, ","); // Thêm dấu phẩy ngăn cách giữa các trường
            }
        }
        fprintf(fp, "\n"); // Xuống dòng sau mỗi hàng
    }
   
    fclose(fp); // Đóng file (với lỗi)
   
    return 0;
}