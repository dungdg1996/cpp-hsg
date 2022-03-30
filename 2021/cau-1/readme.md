
## Phân tích đề
1. Giới hạn của số K là 1 < K < 10^9  
-> Vậy không thể dùng vòng lặp for để giải bài này
2. Bài như vầy thường là tìm công thức, hoặc cách tính đặt biệt  

## Tìm công thức  
Ví dụ với K = 27
Ta sẽ tách K ra làm 2 phần
- Phần chia hết cho 5: 25
- Phần còn dư khi chia cho 5: soDu = 2
- Số lần tăng giây cộng thêm: N = 25 / 5 = 5

> Tong = 5x30 + 5x60 + 5x90 + 5x120 + 5x150 + 2x180

## Tính số giây của phần chia hết cho 5

> Tong = 5x30 + 5x60 + 5x90 + 5x120 + 5x150

Ta thấy có số hạng chung là 5x30, nên sẽ rút gọn công thức lại

> Tong = 5 * 30 * (1 + 2 + 3 + 4 + 5)          (1)

Phần (1 + 2 + 3 + 4 + 5) có thể rút gọn thành 

> (1 + 2 + 3 + 4 + 5) = (1 + 2 + ...+ soLanTang) = soLanTang x (soLanTang + 1) / 2            (2)

(1) và (2) Suy Ra

> Tong = 150 x soLanTang x (soLanTang + 1) / 2  
> = 75 x soLanTang x (soLanTang + 1)

## Tính số giây của phần dư
> PhanDu = 2 x 180 = soDu x (N + 1) x 30


## Công thức tổng:

> Tong = 75 x soLanTang x (soLanTang + 1) + soDu x (N + 1) x 30  

> Tong = (soLanTang + 1) x (75 x soLanTang + 30 x soDu)

## Giải thuật:
1. Nhập `K`
2. Đặt `N = K / 5`
3. Đặt `soDu = fmod(K, 5)`
4. Đặt `Tong = (soLanTang + 1) x (75 x soLanTang + 30 x soDu)`  







