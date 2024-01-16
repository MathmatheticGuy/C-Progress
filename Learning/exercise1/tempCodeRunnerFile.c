// Câu 1 (2đ): Viết hàm nhập vào từ bàn phím số nguyên 2 byte n trong khoảng [1,20].
// Nhập sai thì nhập lại. Gọi hàm trong hàm main() để nhận giá trị của 2 biến nguyên m và n.
// Hiển thị m trong dạng nhị phân.

#include <stdio.h>
#include <stdlib.h>

void binaryN(int m){
    int a[10],m,i;    
    system ("cls");  
    printf("Enter the number to convert: ");    
    scanf("%d",&m);    
    for(i=0;m>0;i++)    
    {    
        a[i]=m%2;    
        m=m/2;    
    }    
        printf("\nBinary of Given Number is=");    
    for(i=i-1;i>=0;i--)    
    {    
      printf("%d",a[i]);    
    }    
}
void convert(int n){
    do
    {
        printf("Nhap so nguyen 2 byte (1-20): ");
        scanf("%d", &n);
    } while (n < 1 || n > 20);
    printf("n = %d\n", n);
    binaryN(n);
}
int main()
{
    int n = 2;
    convert(2);
    //Trong hàm main() viết 1 lệnh lấy số tạo bởi bit thứ 3 và 4 từ phải sang trái của m. Hiển thị số tìm được.
    int bit3and4 = (n >> 2) & 0b11;
    printf("Number formed by bits 3 and 4 from right to left: %d\n", bit3and4);

    return 0;
}