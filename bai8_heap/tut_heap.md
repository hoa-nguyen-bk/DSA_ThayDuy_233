Bài tập 1
1. Một mảng có các phần tử [23, 17, 14, 6, 13, 20, 10, 11, 5, 7, 12] có phải là một max-heap
không? Nếu không, hãy sử dụng giải thuật build heap để dựng lại heap này?
23, 17, 14, 6, 13, 20, 10, 11, 5, 7, 12
23, 17, 14, 6, 13, 20, 10, 11, 5, 7, 12
23, 17, 14, 11, 13, 20, 10, 6, 5, 7, 12
23, 17, 20, 11, 13, 14, 10, 6, 5, 7, 12
23, 17, 20, 11, 13, 14, 10, 6, 5, 7, 12
23, 17, 20, 11, 13, 14, 10, 6, 5, 7, 12
2
2. Lần lượt thêm các phần tử [5, 3, 17, 10, 85, 2, 19, 6, 22, 4] vào một max-heap, hãy cho
biết sự biến đổi của max-heap qua mỗi lần thực hiện thêm phần tử mới.
3. Làm lại câu trên với một min-heap.
4. Sử dụng kết quả của câu 2, hãy cho biết quá trình biến đổi của max-heap khi ta thực
hiện xóa trên heap đó 4 lần?
5. Sử dụng giải thuật sắp xếp bằng heap (heap sort) để sắp xếp mảng ở câu 1.
Các bước để 
Độ phức tạp của giải thuật heap sort là O(n log(n))
6. Heap sort có phải là một giải thuật sắp xếp có tính ổn định (stable) không? Giải thích.
nó duy trì thứ tự trong suốt quá trình sắp xếp mới được gọi là stable, 
Để minh họa Heap Sort không ổn định, chúng ta sẽ xem xét một ví dụ cụ thể:

### Ví dụ:
Cho mảng ban đầu: \[(4_1, 3, 1, 4_2, 2)\]

Trong đó, \(4_1\) và \(4_2\) là hai phần tử có giá trị bằng nhau, nhưng \(4_1\) xuất hiện trước \(4_2\) trong mảng ban đầu.

#### Bước 1: Xây dựng max-heap

- Bắt đầu từ cây nhị phân đầy đủ từ mảng:
  
  ```
         4_1
        /   \
      3      1
     / \
   4_2   2
  ```

- Heapify từ dưới lên trên:

  - So sánh 4_2 và 2 (hai lá): \(4_2\) lớn hơn, không cần thay đổi.
  - Tiếp theo, so sánh 3 với 4_2 và 2. 4_2 lớn hơn nên swap \(3\) với \(4_2\):

  ```
         4_1
        /   \
     4_2      1
     / \
    3   2
  ```

  - So sánh tiếp giữa 4_1 và 4_2. Cả hai bằng nhau, không swap.

#### Bước 2: Thực hiện sắp xếp bằng cách loại bỏ phần tử gốc và heapify lại

1. Swap phần tử gốc với phần tử cuối:

   ```
   [2, 4_2, 1, 3, 4_1]  => [4_1 đã được sắp xếp]
   ```

   Cây heap:
   ```
        2
       / \
     4_2   1
    /
   3
   ```

2. Heapify lại phần tử gốc:

   - Swap 2 và 4_2:

   ```
        4_2
       / \
      2   1
     /
    3
   ```

3. Tiếp tục swap phần tử gốc với phần tử cuối chưa sắp xếp:

   ```
   [3, 2, 1, 4_2, 4_1] => [4_2, 4_1 đã được sắp xếp]
   ```

   Cây heap:
   ```
        3
       / \
      2   1
   ```

4. Heapify lại phần tử gốc (không cần vì heap đã hợp lệ).

5. Swap phần tử gốc với phần tử cuối chưa sắp xếp:

   ```
   [1, 2, 3, 4_2, 4_1] => [3, 4_2, 4_1 đã được sắp xếp]
   ```

   Cây heap:
   ```
        1
       /
      2
   ```

6. Heapify lại phần tử gốc (không cần vì heap đã hợp lệ).

7. Swap phần tử gốc với phần tử cuối chưa sắp xếp:

   ```
   [2, 1, 3, 4_2, 4_1] => [2, 3, 4_2, 4_1 đã được sắp xếp]
   ```

   Cây heap:
   ```
        1
   ```

8. Phần tử cuối cùng:

   ```
   [1, 2, 3, 4_2, 4_1] => [1, 2, 3, 4_2, 4_1 đã được sắp xếp]
   ```

### Kết quả:
Mảng đã sắp xếp: \[(1, 2, 3, 4_2, 4_1)\]

Như bạn thấy, trong mảng ban đầu, \(4_1\) xuất hiện trước \(4_2\), nhưng trong mảng đã sắp xếp, \(4_2\) lại xuất hiện trước \(4_1\). Điều này chứng minh Heap Sort không ổn định vì thứ tự tương đối giữa hai phần tử có giá trị bằng nhau không được giữ nguyên.


Mảng có 2 dạng: truy cập ngẫu nhiên và truy cập tuần tự.
Truy cập ngẫu nhiên: độ phức tạp O(1). Tức la tui biết thèn đó tui truy cập đc liền
Truy cập tuần tự: độ phức tạp O(n). Tức là giống danh sách liên kết, vậy nên truy cập hịu quả hơn