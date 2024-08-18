# ***Bài tập 1***

# ***Bài tập 2***

Cho một dãy các số nguyên đã sắp xếp: [2, 9, 11, 14, 16, 18, 23, 25, 44, 49, 50, 53, 57, 70, 74, 76, 78, 79, 81, 83, 84, 86, 91, 93, 97].

*1.* Sử dụng giải thuật tìm kiếm nhị phân để tìm phần tử 84, số phép so sánh phải thực hiện là bao nhiêu? Liệt kê các phép so sánh đó.

**Giải câu 1**: 

Giải thuật tìm kiếm nhị phân hoạt động bằng cách chia đôi dãy số và so sánh phần tử cần tìm với phần tử ở giữa. Nếu phần tử cần tìm lớn hơn phần tử giữa, ta sẽ tiếp tục tìm kiếm ở nửa dãy bên phải, ngược lại thì sẽ tìm kiếm ở nửa bên trái. Quá trình này lặp lại cho đến khi tìm thấy phần tử hoặc không còn phần tử nào để so sánh.

```
  // Return the position of an element in sorted array "A" of
  // size "n" with value "K". If "K" is not in "A", return
  // the value "n".
  int binary(int A[], int n, int K) {
    int l = -1;
    int r = n; // l and r are beyond array bounds
    while (l+1 != r) { // Stop when l and r meet
      int i = (l+r)/2; // Check middle of remaining subarray
      if (K < A[i]) r = i; // In left half
      if (K == A[i]) return i; // Found it
      if (K > A[i]) l = i; // In right half
    }
    return n; // Search value not in A
  }
```
Figure 3.5 Implementation for binary search

Để tìm phần tử 84 trong dãy số `[2, 9, 11, 14, 16, 18, 23, 25, 44, 49, 50, 53, 57, 70, 74, 76, 78, 79, 81, 83, 84, 86, 91, 93, 97]`, chúng ta sẽ thực hiện các bước sau:

1. **Bước 1**: 
   - Lấy phần tử ở giữa dãy: $( \text{middle} = \left\lfloor \frac{0 + 24}{2} \right\rfloor = \left\lfloor \frac{24}{2} \right\rfloor = 12 )$
   - Phần tử ở vị trí 12 là 57.
   - So sánh: $( 84 > 57 )$. Vì 84 lớn hơn 57, tiếp tục tìm kiếm ở nửa bên phải (từ vị trí 13 đến 24).

2. **Bước 2**:
   - Lấy phần tử ở giữa dãy con bên phải: $( \text{middle} = \left\lfloor \frac{13 + 24}{2} \right\rfloor = \left\lfloor \frac{37}{2} \right\rfloor = 18 )$
   - Phần tử ở vị trí 18 là 81.
   - So sánh: $( 84 > 81 )$. Vì 84 lớn hơn 81, tiếp tục tìm kiếm ở nửa bên phải (từ vị trí 19 đến 24).

NOTE: từ đây tới cuối chưa biết nó đúng hay sai nha

3. **Bước 3**:
   - Lấy phần tử ở giữa dãy con: $( \text{middle} = \left\lfloor \frac{19 + 24}{2} \right\rfloor = \left\lfloor \frac{43}{2} \right\rfloor = 21 )$
   - Phần tử ở vị trí 22 là 86.
   - So sánh: $( 84 < 86 )$. Vì 84 nhỏ hơn 86, tiếp tục tìm kiếm ở nửa bên trái (từ vị trí 20 đến 21).

4. **Bước 4**:
   - Lấy phần tử ở giữa dãy con: $( \text{middle} = \left\lfloor \frac{20 + 21}{2} \right\rfloor = \left\lfloor \frac{41}{2} \right\rfloor = 20 )$
   - Phần tử ở vị trí 20 là 84.
   - So sánh: $( 84 = 84 )$. Đã tìm thấy phần tử.

Như vậy, để tìm phần tử 84 trong dãy đã cho, ta phải thực hiện **4** phép so sánh.

### Các phép so sánh:
1. $( 84 > 57 )$
2. $( 84 > 83 )$
3. $( 84 < 86 )$
4. $( 84 = 84 )$
---

2. Sử dụng giải thuật tìm kiếm Jump để tìm phần tử 84 với kích thước một block là 5, số phép so sánh phải thực hiện là bao nhiêu? Liệt kê các phép so sánh đó.
3. Hãy so sánh kết quả của câu 2 với việc sử dụng kích thước một block là 3 và 7. Liệu có
tồn tại một kích thước nào mà số phép so sánh ít hơn khi dùng kích thước block là 5?
4. Sử dụng giải thuật tìm kiếm nội suy để tìm kiếm phần tử 84 trong danh sách trên. So
sánh kết quả với việc tìm kiếm bằng giải thuật tìm kiếm nhị phân? Giải thích kết quả so
sánh trên.

***Bài tập 2***
Cho một bảng băm có kích thước m = 19 sử dụng một hàm băm h(k) = k mod 19. Lần
lượt thêm các khóa 15, 78, 56, 25, 19, 38, 57, 76, 34, 53, 72, 91 vào bảng băm trên với các giả
định:
1. Sử dụng phương pháp kết chuỗi (chaining) để giải quyết đụng độ.

**Giải câu 1**: 
### 1. Sử dụng phương pháp kết chuỗi (chaining) để giải quyết đụng độ:

Phương pháp kết chuỗi (chaining) lưu trữ các khóa bị đụng độ trong cùng một vị trí của bảng băm dưới dạng danh sách liên kết (linked list).

Ta có hàm băm $( h(k) = k \mod 19 )$, và m = 19.

Dưới đây là quá trình thêm các khóa vào bảng băm:

1. **Khóa 15**:
   - $( h(15) = 15 \mod 19 = 15 )$
   - Chèn 15 vào vị trí 15.
  
2. **Khóa 78**:
   - $( h(78) = 78 \mod 19 = 2 )$
   - Chèn 78 vào vị trí 2.

3. **Khóa 56**:
   - $( h(56) = 56 \mod 19 = 18 )$
   - Chèn 56 vào vị trí 18.

4. **Khóa 25**:
   - $( h(25) = 25 \mod 19 = 6 )$
   - Chèn 25 vào vị trí 6.

5. **Khóa 19**:
   - $( h(19) = 19 \mod 19 = 0 )$
   - Chèn 19 vào vị trí 0.

6. **Khóa 38**:
   - $( h(38) = 38 \mod 19 = 0 )$
   - Vị trí 0 đã có khóa 19, chèn 38 vào vị trí 0 dưới dạng danh sách liên kết.

7. **Khóa 57**:
   - $( h(57) = 57 \mod 19 = 0 )$
   - Vị trí 0 đã có khóa 19 và 38, chèn 57 vào vị trí 0 dưới dạng danh sách liên kết.

8. **Khóa 76**:
   - $( h(76) = 76 \mod 19 = 0 )$
   - Vị trí 0 đã có khóa 19, 38 và 57, chèn 76 vào vị trí 0 dưới dạng danh sách liên kết.

9. **Khóa 34**:
   - $( h(34) = 34 \mod 19 = 15 )$
   - Vị trí 15 đã có khóa 15, chèn 34 vào vị trí 15 dưới dạng danh sách liên kết.

10. **Khóa 53**:
    - $( h(53) = 53 \mod 19 = 15 )$
    - Vị trí 15 đã có khóa 15 và 34, chèn 53 vào vị trí 15 dưới dạng danh sách liên kết.

11. **Khóa 72**:
    - $( h(72) = 72 \mod 19 = 15 )$
    - Vị trí 15 đã có khóa 15, 34 và 53, chèn 72 vào vị trí 15 dưới dạng danh sách liên kết.

12. **Khóa 91**:
    - $( h(91) = 91 \mod 19 = 15 )$
    - Vị trí 15 đã có khóa 15, 34, 53 và 72, chèn 91 vào vị trí 15 dưới dạng danh sách liên kết.

Kết quả cuối cùng của bảng băm với phương pháp kết chuỗi sẽ như sau:

```
0: 19 -> 38 -> 57 -> 76
1: 
2: 78
3: 
4: 
5: 
6: 25
7: 
8: 
9: 
10: 
11: 
12: 
13: 
14: 
15: 15 -> 34 -> 53 -> 72 -> 91
16: 
17: 
18: 56
```

### 2. Sử dụng phương pháp địa chỉ mở (open addressing) với dò tìm tuyến tính:
### 1. Sử dụng phương pháp kết chuỗi (chaining) để giải quyết đụng độ:

Phương pháp kết chuỗi (chaining) lưu trữ các khóa bị đụng độ trong cùng một vị trí của bảng băm dưới dạng danh sách liên kết (linked list).

Ta có hàm băm $( h(k) = k \mod 19 )$, và m = 19.

Dưới đây là quá trình thêm các khóa vào bảng băm:

1. **Khóa 15**:
   - $( h(15) = 15 \mod 19 = 15 )$
   - Chèn 15 vào vị trí 15.
  
2. **Khóa 78**:
   - $( h(78) = 78 \mod 19 = 2 )$
   - Chèn 78 vào vị trí 2.

3. **Khóa 56**:
   - $( h(56) = 56 \mod 19 = 18 )$
   - Chèn 56 vào vị trí 18.

4. **Khóa 25**:
   - $( h(25) = 25 \mod 19 = 6 )$
   - Chèn 25 vào vị trí 6.

5. **Khóa 19**:
   - $( h(19) = 19 \mod 19 = 0 )$
   - Chèn 19 vào vị trí 0.

6. **Khóa 38**:
   - $( h(38) = 38 \mod 19 = 0 )$
   - Vị trí 0 đã có khóa 19, chèn 38 vào vị trí 0 dưới dạng danh sách liên kết.

7. **Khóa 57**:
   - $( h(57) = 57 \mod 19 = 0 )$
   - Vị trí 0 đã có khóa 19 và 38, chèn 57 vào vị trí 0 dưới dạng danh sách liên kết.

8. **Khóa 76**:
   - $( h(76) = 76 \mod 19 = 0 )$
   - Vị trí 0 đã có khóa 19, 38 và 57, chèn 76 vào vị trí 0 dưới dạng danh sách liên kết.

9. **Khóa 34**:
   - $( h(34) = 34 \mod 19 = 15 )$
   - Vị trí 15 đã có khóa 15, chèn 34 vào vị trí 15 dưới dạng danh sách liên kết.

10. **Khóa 53**:
    - $( h(53) = 53 \mod 19 = 15 )$
    - Vị trí 15 đã có khóa 15 và 34, chèn 53 vào vị trí 15 dưới dạng danh sách liên kết.

11. **Khóa 72**:
    - $( h(72) = 72 \mod 19 = 15 )$
    - Vị trí 15 đã có khóa 15, 34 và 53, chèn 72 vào vị trí 15 dưới dạng danh sách liên kết.

12. **Khóa 91**:
    - $( h(91) = 91 \mod 19 = 15 )$
    - Vị trí 15 đã có khóa 15, 34, 53 và 72, chèn 91 vào vị trí 15 dưới dạng danh sách liên kết.


Kết quả cuối cùng của bảng băm với phương pháp kết chuỗi sẽ như sau:

```
0: 19 -> 38 -> 57 -> 76
1: 
2: 78
3: 
4: 
5: 
6: 25
7: 
8: 
9: 
10: 
11: 
12: 
13: 
14: 
15: 15 -> 34 -> 53 -> 72 -> 91
16: 
17: 
18: 56
```

Nhớ thêm là thêm vào là đầu danh sách nên ta đảo danh sách lại

```
0: 76-> 57 -> 38 -> 19 
1: 
2: 78
3: 
4: 
5: 
6: 25
7: 
8: 
9: 
10: 
11: 
12: 
13: 
14: 
15: 91 -> 72 -> 53 -> 34 -> 15
16: 
17: 
18: 56
```

### 2. Sử dụng phương pháp địa chỉ mở (open addressing) với dò tìm tuyến tính:

Phương pháp địa chỉ mở sử dụng dò tìm tuyến tính để giải quyết đụng độ. Khi xảy ra đụng độ, ta dò tìm vị trí tiếp theo theo công thức:

$[ hp(k, i) = (h(k) + i) \mod m ]$

Dưới đây là quá trình thêm các khóa vào bảng băm:

1. **Khóa 15**:
   - $( h(15) = 15 \mod 19 = 15 )$
   - Chèn 15 vào vị trí 15.

2. **Khóa 78**:
   - $( h(78) = 78 \mod 19 = 2 )$
   - Chèn 78 vào vị trí 2.

3. **Khóa 56**:
   - $( h(56) = 56 \mod 19 = 18 )$
   - Chèn 56 vào vị trí 18.

4. **Khóa 25**:
   - $( h(25) = 25 \mod 19 = 6 )$
   - Chèn 25 vào vị trí 6.

5. **Khóa 19**:
   - $( h(19) = 19 \mod 19 = 0 )$
   - Chèn 19 vào vị trí 0.

6. **Khóa 38**:
   - $( h(38) = 38 \mod 19 = 0 )$
   - Vị trí 0 đã bị chiếm, dò tìm vị trí tiếp theo:
   - $( hp(38, 1) = (0 + 1) \mod 19 = 1 )$
   - Chèn 38 vào vị trí 1.

7. **Khóa 57**:
   - $( h(57) = 57 \mod 19 = 0 )$
   - Vị trí 0 đã bị chiếm, dò tìm vị trí tiếp theo:
   - $( hp(57, 1) = (0 + 1) \mod 19 = 1 )$
   - Vị trí 1 đã bị chiếm, tiếp tục dò tìm:
   - $( hp(57, 2) = (0 + 2) \mod 19 = 2 )$
   - Vị trí 2 đã bị chiếm, tiếp tục dò tìm:
   - $( hp(57, 3) = (0 + 3) \mod 19 = 3 )$
   - Chèn 57 vào vị trí 3.

8. **Khóa 76**:
   - $( h(76) = 76 \mod 19 = 0 )$
   - Vị trí 0 đã bị chiếm, dò tìm vị trí tiếp theo:
   - $( hp(76, 1) = (0 + 1) \mod 19 = 1 )$
   - Vị trí 1 đã bị chiếm, tiếp tục dò tìm:
   - $( hp(76, 2) = (0 + 2) \mod 19 = 2 )$
   - Vị trí 2 đã bị chiếm, tiếp tục dò tìm:
   - $( hp(76, 3) = (0 + 3) \mod 19 = 3 )$
   - Vị trí 3 đã bị chiếm, tiếp tục dò tìm:
   - $( hp(76, 4) = (0 + 4) \mod 19 = 4 )$
   - Chèn 76 vào vị trí 4.

9. **Khóa 34**:
   - $( h(34) = 34 \mod 19 = 15 )$
   - Vị trí 15 đã bị chiếm, dò tìm vị trí tiếp theo:
   - $( hp(34, 1) = (15 + 1) \mod 19 = 16 )$
   - Chèn 34 vào vị trí 16.

10. **Khóa 53**:
    - $( h(53) = 53 \mod 19 = 15 )$
    - Vị trí 15 đã bị chiếm, dò tìm vị trí tiếp theo:
    - $( hp(53, 1) = (15 + 1) \mod 19 = 16 )$
    - Vị trí 16 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(53, 2) = (15 + 2) \mod 19 = 17 )$
    - Chèn 53 vào vị trí 17.

11. **Khóa 72**:
    - $( h(72) = 72 \mod 19 = 15 )$
    - Vị trí 15 đã bị chiếm, dò tìm vị trí tiếp theo:
    - $( hp(72, 1) = (15 + 1) \mod 19 = 16 )$
    - Vị trí 16 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(72, 2) = (15 + 2) \mod 19 = 17 )$
    - Vị trí 17 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(72, 3) = (15 + 3) \mod 19 = 18 )$
    - Vị trí 18 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(72, 4) = (15 + 4) \mod 19 = 0 )$
    - Vị trí 0 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(72, 5)

 = (15 + 5) \mod 19 = 1 )$
    - Vị trí 1 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(72, 6) = (15 + 6) \mod 19 = 2 )$
    - Vị trí 2 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(72, 7) = (15 + 7) \mod 19 = 3 )$
    - Vị trí 3 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(72, 8) = (15 + 8) \mod 19 = 4 )$
    - Vị trí 4 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(72, 9) = (15 + 9) \mod 19 = 5 )$
    - Chèn 72 vào vị trí 5.

12. **Khóa 91**:
    - $( h(91) = 91 \mod 19 = 15 )$
    - Vị trí 15 đã bị chiếm, dò tìm vị trí tiếp theo:
    - $( hp(91, 1) = (15 + 1) \mod 19 = 16 )$
    - Vị trí 16 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(91, 2) = (15 + 2) \mod 19 = 17 )$
    - Vị trí 17 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(91, 3) = (15 + 3) \mod 19 = 18 )$
    - Vị trí 18 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(91, 4) = (15 + 4) \mod 19 = 0 )$
    - Vị trí 0 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(91, 5) = (15 + 5) \mod 19 = 1 )$
    - Vị trí 1 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(91, 6) = (15 + 6) \mod 19 = 2 )$
    - Vị trí 2 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(91, 7) = (15 + 7) \mod 19 = 3 )$
    - Vị trí 3 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(91, 8) = (15 + 8) \mod 19 = 4 )$
    - Vị trí 4 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(91, 9) = (15 + 9) \mod 19 = 5 )$
    - Vị trí 5 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(91, 10) = (15 + 10) \mod 19 = 6 )$
    - Vị trí 6 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(91, 11) = (15 + 11) \mod 19 = 7 )$
    - Chèn 91 vào vị trí 7.

Kết quả cuối cùng của bảng băm với phương pháp dò tìm tuyến tính sẽ như sau:

```
0: 19
1: 38
2: 78
3: 57
4: 76
5: 72
6: 25
7: 91
8: 
9: 
10: 
11: 
12: 
13: 
14: 
15: 15
16: 34
17: 53
18: 56
```



2. Sử dụng phương pháp địa chỉ mở (open addressing) để giải quyết đụng độ với phương
pháp dò tìm tuyến tính:
$[ hp(k, i) = (h(k) + i^2) \mod m ]$

Sử dụng phương pháp địa chỉ mở với dò tìm bậc hai để giải quyết đụng độ trong bảng băm. Công thức băm được sử dụng là:

$[ hp(k, i) = (h(k) + i^2) \mod m ]$

Trong đó:
- $( h(k) = k \mod 19 )$ là hàm băm cơ bản.
- $( i )$ là số lần đụng độ.
- $( m = 19 )$ là kích thước của bảng băm.

Dưới đây là quá trình thêm các khóa vào bảng băm:

1. **Khóa 15**:
   - $( h(15) = 15 \mod 19 = 15 )$
   - Chèn 15 vào vị trí 15.

2. **Khóa 78**:
   - $( h(78) = 78 \mod 19 = 2 )$
   - Chèn 78 vào vị trí 2.

3. **Khóa 56**:
   - $( h(56) = 56 \mod 19 = 18 )$
   - Chèn 56 vào vị trí 18.

4. **Khóa 25**:
   - $( h(25) = 25 \mod 19 = 6 )$
   - Chèn 25 vào vị trí 6.

5. **Khóa 19**:
   - $( h(19) = 19 \mod 19 = 0 )$
   - Chèn 19 vào vị trí 0.

6. **Khóa 38**:
   - $( h(38) = 38 \mod 19 = 0 )$
   - Vị trí 0 đã bị chiếm, dò tìm vị trí tiếp theo:
   - $( hp(38, 1) = (0 + 1^2) \mod 19 = 1 )$
   - Chèn 38 vào vị trí 1.

7. **Khóa 57**:
   - $( h(57) = 57 \mod 19 = 0 )$
   - Vị trí 0 đã bị chiếm, dò tìm vị trí tiếp theo:
   - $( hp(57, 1) = (0 + 1^2) \mod 19 = 1 )$
   - Vị trí 1 đã bị chiếm, tiếp tục dò tìm:
   - $( hp(57, 2) = (0 + 2^2) \mod 19 = 4 )$
   - Chèn 57 vào vị trí 4.

8. **Khóa 76**:
   - $( h(76) = 76 \mod 19 = 0 )$
   - Vị trí 0 đã bị chiếm, dò tìm vị trí tiếp theo:
   - $( hp(76, 1) = (0 + 1^2) \mod 19 = 1 )$
   - Vị trí 1 đã bị chiếm, tiếp tục dò tìm:
   - $( hp(76, 2) = (0 + 2^2) \mod 19 = 4 )$
   - Vị trí 4 đã bị chiếm, tiếp tục dò tìm:
   - $( hp(76, 3) = (0 + 3^2) \mod 19 = 9 )$
   - Chèn 76 vào vị trí 9.

9. **Khóa 34**:
   - $( h(34) = 34 \mod 19 = 15 )$
   - Vị trí 15 đã bị chiếm, dò tìm vị trí tiếp theo:
   - $( hp(34, 1) = (15 + 1^2) \mod 19 = 16 )$
   - Chèn 34 vào vị trí 16.

10. **Khóa 53**:
    - $( h(53) = 53 \mod 19 = 15 )$
    - Vị trí 15 đã bị chiếm, dò tìm vị trí tiếp theo:
    - $( hp(53, 1) = (15 + 1^2) \mod 19 = 16 )$
    - Vị trí 16 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(53, 2) = (15 + 2^2) \mod 19 = 19 \mod 19 = 0 )$
    - Vị trí 0 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(53, 3) = (15 + 3^2) \mod 19 = 24 \mod 19 = 5 )$
    - Chèn 53 vào vị trí 5.

11. **Khóa 72**:
    - $( h(72) = 72 \mod 19 = 15 )$
    - Vị trí 15 đã bị chiếm, dò tìm vị trí tiếp theo:
    - $( hp(72, 1) = (15 + 1^2) \mod 19 = 16 )$
    - Vị trí 16 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(72, 2) = (15 + 2^2) \mod 19 = 19 \mod 19 = 0 )$
    - Vị trí 0 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(72, 3) = (15 + 3^2) \mod 19 = 24 \mod 19 = 5 )$
    - Vị trí 5 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(72, 4) = (15 + 4^2) \mod 19 = 31 \mod 19 = 12 )$
    - Chèn 72 vào vị trí 12.

12. **Khóa 91**:
    - $( h(91) = 91 \mod 19 = 15 )$
    - Vị trí 15 đã bị chiếm, dò tìm vị trí tiếp theo:
    - $( hp(91, 1) = (15 + 1^2) \mod 19 = 16 )$
    - Vị trí 16 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(91, 2) = (15 + 2^2) \mod 19 = 19 \mod 19 = 0 )$
    - Vị trí 0 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(91, 3) = (15 + 3^2) \mod 19 = 24 \mod 19 = 5 )$
    - Vị trí 5 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(91, 4) = (15 + 4^2) \mod 19 = 31 \mod 19 = 12 )$
    - Vị trí 12 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(91, 5) = (15 + 5^2) \mod 19 = 40 \mod 19 = 2 )$
    - Vị trí 2 đã bị chiếm, tiếp tục dò tìm:
    - $( hp(91, 6) = (15 + 6^2) \mod 19 = 51 \mod 19 = 13 )$
    - Chèn 91 vào vị trí 13.

Kết quả cuối cùng của bảng băm với phương pháp dò tìm bậc hai sẽ như sau:

```
0: 19
1: 38
2: 78
3: 
4: 57
5: 53
6: 25
7: 
8: 
9: 76
10: 
11: 
12: 72
13: 91
14: 
15: 15
16: 34
17: 
18: 56
```

3. Sử dụng phương pháp địa chỉ mở (open addressing) để giải quyết đụng độ với phương
pháp dò tìm bậc hai:
hp(k, i) = (h(k) + i
2
) mod m
.
4. Sử dụng phương pháp địa chỉ mở (open addressing) để giải quyết đụng độ với phương
pháp băm đôi (double hashing):
hp(k, i) = (h1(k) + ih2(k)) mod m


