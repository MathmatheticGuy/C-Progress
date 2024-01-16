import numpy as np

# Đọc vào số n từ bàn phím
n = int(input("Nhập số n: "))

# Khởi tạo mảng số nguyên với n phần tử và gán giá trị từ 1 đến n
arr = np.zeros(n, dtype=int)
for i in range(n):
    arr[i] = i + 1

# Ghi mảng vào file nhị phân
with open('../../FileHolder/array.bin', 'wb') as file:
    arr.tofile(file)

# Gán n = -1
n = -1

# Mở file nhị phân để đọc và hiển thị mảng
with open('../../FileHolder/array.bin', 'rb') as file:
    # Đọc mảng từ file nhị phân
    read_arr = np.fromfile(file, dtype=int, count=n)
   
    # Hiển thị mảng đọc được
    print("Mảng sau khi đọc từ file nhị phân:", read_arr)