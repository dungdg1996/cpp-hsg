
## Phân tích đề
1. Nếu muốn lấy số kẹo nhiều nhất thì phải lấy số kẹo có giá thấp nhất
2. Muốn lấy số kẹo từ giá thấp nhất thì phải sắp xếp lại mảng

## Tìm cách giải

### Phân tích Input

Số loại kẹo: N = 5  
Số tiền đang có: K = 50

Loại kẹo (i) | Giá tiền (P[i]) | Số người (C[i]) 
--- | --- | --- |
0 | 5 | 3
1 | 1 | 1
2 | 10 | 4
3 | 7 | 2
4 | 60 | 1

### Sấp xếp lại mảng 
Ta sẽ sắp xếp bảng này theo chiều tăng dần của giá tiền P

Đây là kết quả sau khi sắp xếp

Loại kẹo (i) | Giá tiền (P[i]) | Số người (C[i]) 
--- | --- | --- |
1 | 1 | 1
0 | 5 | 3
3 | 7 | 2
2 | 10 | 4
4 | 60 | 1

### Lấy kẹo
Ta sẽ lấy kẹo từ giá thấp đến giá cao cho tới khi hết tiền  

1. Lấy 1 viên loại kẹo 1: 1K
2. Lấy 3 viên loại kẹo 0: 9K
3. Lấy 2 viên loại kẹo 3: 14k
4. Lấy 2 viên loại kẹo 2: 20k
5. Lúc này chỉ còn lại 6k nên không lấy thêm nữa  
-> Kết quả ta dùng 44k để mua 8 viên kẹo

Loại kẹo (i) | Giá tiền (P[i]) | Số người (C[i]) | Mua | Giá tiền | Số tiền còn lại
--- | --- | --- | --- | --- | --- |  
1 | 1 | 1 | 1 | 1 | 49
0 | 5 | 3 | 3 | 9 | 40
3 | 7 | 2 | 2 | 14 | 26
2 | 10 | 4 | 2 | 20 | 4
4 | 60 | 1 | 0 | 0 | 4



## Giải thuật:
1. Nhập dữ liệu từ file
2. Sắp xếp mảng P và C theo chiều tăng dần của C
3. Ta sẽ lấy kẹo từ giá thấp đến giá cao cho tới khi hết tiền hoặc không mua được kẹo







