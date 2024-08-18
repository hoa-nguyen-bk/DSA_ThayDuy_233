TRƯỜNG ĐẠI HỌC BÁCH KHOA - ĐHQG-HCM

KHOA KHOA HỌC VÀ KỸ THUẬT MÁY TÍNH

BÀI TẬP CÓ HƯỚNG DẪN

Nội dung: Graph

# Bài tập 1
1. Sử dụng danh sách liên kề để biểu diễn đồ thị trên, biết rằng thứ tự trong một danh sách được sắp xếp theo thứ tự z-a.
2. Sử dụng ma trận liền kề để biểu diễn đồ thị trên, biết rằng thứ tự theo hàng và theo cột
là thứ tự a-z.
3. Hãy trình bày thứ tự các đỉnh khi thực hiện duyệt cây ưu tiên theo chiều rộng trong đó
việc chọn các đỉnh được lấy theo danh sách liền kề ở câu 1. Đỉnh bắt đầu là a.
4. Sắp xếp các danh sách liền kề ở câu 1 theo chiều tăng dần của trọng số các cạnh. Hãy
trình bày lại thứ tự các đỉnh khi thực hiện duyệt cây ưu tiên theo chiều rộng. Đỉnh bắt
đầu là a.
5. Tìm đường đi ngắn nhất giữa a và g bằng hai cây ưu tiên chiều rộng (breadth-first tree)
tìm được ở câu 3 và 4.
6. Hãy trình bày thứ tự các đỉnh khi thực hiện duyệt cây ưu tiên theo chiều sâu trong đó
việc chọn các đỉnh được lấy theo danh sách liền kề ở câu 1.
7. Sử dụng giải thuật Prim và giải thuật Kruskal (đã được học ở môn Cấu trúc rời rạc) để
tìm cây khung nhỏ nhất trong đồ thị trên.
Từ đó, viết mã giả cho hai giải thuật trên với hai cách biểu diễn đồ thị.

## Câu 1

Dựa trên đồ thị đã cho và yêu cầu, chúng ta cần biểu diễn đồ thị bằng danh sách liên kề với thứ tự các đỉnh trong mỗi danh sách liên kề được sắp xếp theo thứ tự giảm dần từ z đến a.

### Danh sách liên kết theo thứ tự z-a:

1. **Đỉnh g**: $( g )$ kết nối với $( f (12), e (8) )$.
   - Danh sách liên kết: $( g \rightarrow f (12) \rightarrow e (8) )$

2. **Đỉnh f**: $( f )$ kết nối với $( g (12), e (17), d (9) )$.
   - Danh sách liên kết: $( f \rightarrow g (12) \rightarrow e (17) \rightarrow d (9) )$

3. **Đỉnh e**: $( e )$ kết nối với $( g (8), f (17), d (19), c (15), b (11) )$.
   - Danh sách liên kết: $( e \rightarrow g (8) \rightarrow f (17) \rightarrow d (19) \rightarrow c (15) \rightarrow b (11) )$

4. **Đỉnh d**: $( d )$ kết nối với $( e (19), a (20), f (9) )$.
   - Danh sách liên kết: $( d \rightarrow e (19) \rightarrow a (20) \rightarrow f (9) )$

5. **Đỉnh c**: $( c )$ kết nối với $( e (15), b (13) )$.
   - Danh sách liên kết: $( c \rightarrow e (15) \rightarrow b (13) )$

6. **Đỉnh b**: $( b )$ kết nối với $( e (11), c (13), a (5) )$.
   - Danh sách liên kết: $( b \rightarrow e (11) \rightarrow c (13) \rightarrow a (5) )$

7. **Đỉnh a**: $( a )$ kết nối với $( e (16), d (20), b (5) )$.
   - Danh sách liên kết: $( a \rightarrow e (16) \rightarrow d (20) \rightarrow b (5) )$

### Tổng hợp danh sách liên kết:

```
g: f (12) → e (8)
f: g (12) → e (17) → d (9)
e: g (8) → f (17) → d (19) → c (15) → b (11)
d: e (19) → a (20) → f (9)
c: e (15) → b (13)
b: e (11) → c (13) → a (5)
a: e (16) → d (20) → b (5)
```

Các danh sách trên đã được sắp xếp theo thứ tự z-a.

## Câu 2

Để biểu diễn đồ thị bằng ma trận kề (adjacency matrix) với thứ tự các đỉnh theo hàng và cột là từ **a-z**, chúng ta sẽ tạo một ma trận vuông, trong đó mỗi hàng và mỗi cột tương ứng với một đỉnh. Giá trị tại vị trí $ (i, j) $ trong ma trận là trọng số của cạnh giữa đỉnh $ i $ và đỉnh $ j $. Nếu không có cạnh giữa hai đỉnh, giá trị tương ứng sẽ là $0$.

### Danh sách các đỉnh theo thứ tự a-z:
- **a**: 1
- **b**: 2
- **c**: 3
- **d**: 4
- **e**: 5
- **f**: 6
- **g**: 7

### Ma trận kề:

Dựa vào đồ thị đã cho, ta có các cạnh với trọng số tương ứng:

- $ a $ kết nối với $ b (5), d (20), e (16) $
- $ b $ kết nối với $ a (5), c (13), e (11) $
- $ c $ kết nối với $ b (13), e (15) $
- $ d $ kết nối với $ a (20), e (19), f (9) $
- $ e $ kết nối với $ a (16), b (11), c (15), d (19), f (17), g (8) $
- $ f $ kết nối với $ d (9), e (17), g (12) $
- $ g $ kết nối với $ e (8), f (12) $

Bây giờ ta tạo ma trận kề:

$
\begin{array}{c|ccccccc}
   & a & b & c & d & e & f & g \\
\hline
a & 0 & 5 & 0 & 20 & 16 & 0 & 0 \\
b & 5 & 0 & 13 & 0 & 11 & 0 & 0 \\
c & 0 & 13 & 0 & 0 & 15 & 0 & 0 \\
d & 20 & 0 & 0 & 0 & 19 & 9 & 0 \\
e & 16 & 11 & 15 & 19 & 0 & 17 & 8 \\
f & 0 & 0 & 0 & 9 & 17 & 0 & 12 \\
g & 0 & 0 & 0 & 0 & 8 & 12 & 0 \\
\end{array}
$

### Giải thích ma trận:

- Dòng và cột đầu tiên tương ứng với đỉnh $ a $, dòng và cột thứ hai tương ứng với đỉnh $ b $, v.v.
- Các giá trị tại các vị trí giao nhau giữa các hàng và cột thể hiện trọng số của các cạnh nối hai đỉnh tương ứng.
- Ví dụ, tại vị trí $ (a, b) $ (giao của hàng 1 và cột 2) có giá trị là $5$, biểu thị rằng có cạnh nối từ $a$ đến $b$ với trọng số $5$.
- Các ô có giá trị $0$ biểu thị rằng không có cạnh nối giữa hai đỉnh tương ứng.

Ma trận này mô tả đầy đủ các mối liên kết giữa các đỉnh trong đồ thị theo thứ tự từ $a$ đến $z$.

## Câu 3
Để thực hiện duyệt cây ưu tiên theo chiều rộng (Breadth-First Search - BFS) từ đỉnh bắt đầu là $a$, chúng ta sẽ lần lượt thăm các đỉnh theo thứ tự trong hàng đợi, theo đúng danh sách liên kề đã sắp xếp từ z-a ở câu 1. Cụ thể, thứ tự thăm đỉnh sẽ như sau:

### Danh sách liên kề (từ z-a) đã cho:

1. $ a: e \rightarrow d \rightarrow b $
2. $ b: e \rightarrow c \rightarrow a $
3. $ c: e \rightarrow b $
4. $ d: e \rightarrow a \rightarrow f $
5. $ e: g \rightarrow f \rightarrow d \rightarrow c \rightarrow b $
6. $ f: g \rightarrow e \rightarrow d $
7. $ g: f \rightarrow e $

### Thực hiện duyệt BFS bắt đầu từ đỉnh $a$:

1. **Bước 1**: Bắt đầu từ đỉnh $a$. Thêm các đỉnh kết nối với $a$ vào hàng đợi theo thứ tự từ z-a:
   - Hàng đợi: $ [e, d, b] $
   - Đỉnh đã thăm: $ [a] $

2. **Bước 2**: Lấy đỉnh $e$ từ hàng đợi và thăm. Thêm các đỉnh kết nối với $e$ vào hàng đợi theo thứ tự từ z-a (chỉ thêm các đỉnh chưa thăm):
   - Hàng đợi: $ [d, b, g, f, c] $
   - Đỉnh đã thăm: $ [a, e] $

3. **Bước 3**: Lấy đỉnh $d$ từ hàng đợi và thăm. Thêm các đỉnh kết nối với $d$ vào hàng đợi theo thứ tự từ z-a (chỉ thêm các đỉnh chưa thăm):
   - Hàng đợi: $ [b, g, f, c] $ (không thêm đỉnh nào vì $e$ và $a$ đã được thăm)
   - Đỉnh đã thăm: $ [a, e, d] $

4. **Bước 4**: Lấy đỉnh $b$ từ hàng đợi và thăm. Thêm các đỉnh kết nối với $b$ vào hàng đợi theo thứ tự từ z-a (chỉ thêm các đỉnh chưa thăm):
   - Hàng đợi: $ [g, f, c] $ (không thêm đỉnh nào vì các đỉnh kết nối với $b$ đều đã được thăm)
   - Đỉnh đã thăm: $ [a, e, d, b] $

5. **Bước 5**: Lấy đỉnh $g$ từ hàng đợi và thăm. Thêm các đỉnh kết nối với $g$ vào hàng đợi theo thứ tự từ z-a (chỉ thêm các đỉnh chưa thăm):
   - Hàng đợi: $ [f, c] $ (không thêm đỉnh nào vì các đỉnh kết nối với $g$ đều đã được thăm hoặc có trong hàng đợi)
   - Đỉnh đã thăm: $ [a, e, d, b, g] $

6. **Bước 6**: Lấy đỉnh $f$ từ hàng đợi và thăm. Thêm các đỉnh kết nối với $f$ vào hàng đợi theo thứ tự từ z-a (chỉ thêm các đỉnh chưa thăm):
   - Hàng đợi: $ [c] $ (không thêm đỉnh nào vì các đỉnh kết nối với $f$ đều đã được thăm hoặc có trong hàng đợi)
   - Đỉnh đã thăm: $ [a, e, d, b, g, f] $

7. **Bước 7**: Lấy đỉnh $c$ từ hàng đợi và thăm. Không thêm đỉnh nào vì $c$ không kết nối với đỉnh nào chưa thăm.
   - Hàng đợi: $ [] $
   - Đỉnh đã thăm: $ [a, e, d, b, g, f, c] $

### Kết quả:
Thứ tự các đỉnh khi thực hiện duyệt cây ưu tiên theo chiều rộng từ đỉnh $a$ là: 

$ \mathbf{a, e, d, b, g, f, c} $

## Câu 7
### Cây khung nhỏ nhất (Minimum Spanning Tree - MST) là cây bao gồm tất cả các đỉnh của đồ thị, nhưng chỉ có các cạnh cần thiết để giữ kết nối tất cả các đỉnh, sao cho tổng trọng số của các cạnh là nhỏ nhất. Để tìm MST, ta có thể sử dụng hai thuật toán: **Prim** và **Kruskal**.

### 1. Thuật toán Prim

**Nguyên lý:** Thuật toán Prim bắt đầu từ một đỉnh bất kỳ, sau đó liên tục thêm các cạnh có trọng số nhỏ nhất mà không tạo thành chu trình, cho đến khi tất cả các đỉnh được bao phủ.

#### Mã giả cho Prim với biểu diễn đồ thị bằng ma trận kề:

```pseudo
Input: G - Đồ thị với n đỉnh được biểu diễn bằng ma trận kề
Output: T - Cây khung nhỏ nhất (MST)

1. Chọn một đỉnh bất kỳ làm đỉnh bắt đầu (ví dụ: đỉnh u)
2. Đặt T = {u}, tập hợp các đỉnh đã thăm
3. While |T| < n:
    a. Tìm cạnh (u, v) có trọng số nhỏ nhất, trong đó u ∈ T và v ∉ T
    b. Thêm cạnh (u, v) vào MST
    c. Thêm v vào T
4. Trả về MST
```

**Thực hiện thuật toán Prim trên đồ thị đã cho:**

Bắt đầu từ đỉnh $ a $:

- Bước 1: Từ $ a $, chọn cạnh nhỏ nhất $ a - b $ với trọng số 5.
- Bước 2: Từ $ b $, chọn cạnh nhỏ nhất $ b - e $ với trọng số 11.
- Bước 3: Từ $ e $, chọn cạnh nhỏ nhất $ e - g $ với trọng số 8.
- Bước 4: Từ $ g $, chọn cạnh nhỏ nhất $ g - f $ với trọng số 12.
- Bước 5: Từ $ f $, chọn cạnh nhỏ nhất $ f - d $ với trọng số 9.

Kết quả MST: Các cạnh $a - b$, $b - e$, $e - g$, $g - f$, và $f - d$ với tổng trọng số là 5 + 11 + 8 + 12 + 9 = 45.

### 2. Thuật toán Kruskal

**Nguyên lý:** Thuật toán Kruskal bắt đầu từ việc sắp xếp tất cả các cạnh theo thứ tự tăng dần của trọng số. Sau đó, từng cạnh một, nó thêm vào MST nếu việc thêm cạnh đó không tạo ra chu trình, cho đến khi tất cả các đỉnh được kết nối.

#### Mã giả cho Kruskal với biểu diễn đồ thị bằng danh sách cạnh:

```pseudo
Input: G - Đồ thị với n đỉnh được biểu diễn bằng danh sách cạnh
Output: T - Cây khung nhỏ nhất (MST)

1. Sắp xếp tất cả các cạnh theo thứ tự trọng số tăng dần
2. Đặt T = ∅, tập hợp các cạnh của MST
3. Khởi tạo tập hợp rời rạc cho tất cả các đỉnh (disjoint-set)
4. For each cạnh (u, v) trong danh sách cạnh đã sắp xếp:
    a. Nếu u và v không nằm trong cùng một tập hợp rời rạc:
        i. Thêm cạnh (u, v) vào T
        ii. Hợp nhất tập hợp chứa u và v
    b. Nếu T có đủ n-1 cạnh, dừng vòng lặp
5. Trả về T
```

**Thực hiện thuật toán Kruskal trên đồ thị đã cho:**

- Bước 1: Sắp xếp các cạnh theo trọng số: $a - b (5)$, $g - e (8)$, $f - d (9)$, $b - e (11)$, $g - f (12)$, $b - c (13)$, $c - e (15)$, $a - e (16)$, $e - f (17)$, $e - d (19)$, $a - d (20)$.
- Bước 2: Bắt đầu thêm các cạnh vào MST:
  - Chọn $a - b (5)$ vào MST.
  - Chọn $g - e (8)$ vào MST.
  - Chọn $f - d (9)$ vào MST.
  - Chọn $b - e (11)$ vào MST.
  - Chọn $g - f (12)$ vào MST.

Kết quả MST: Các cạnh $a - b$, $g - e$, $f - d$, $b - e$, và $g - f$ với tổng trọng số là 5 + 8 + 9 + 11 + 12 = 45.

### 3. Tổng kết:

- **MST của đồ thị** có tổng trọng số là 45 với các cạnh: $a - b$, $g - e$, $f - d$, $b - e$, và $g - f$.
- Cả hai thuật toán **Prim** và **Kruskal** đều đưa ra cùng một MST cho đồ thị đã cho.

Mỗi thuật toán có lợi thế riêng: Prim tốt cho đồ thị dày đặc (dense), còn Kruskal phù hợp hơn cho đồ thị thưa (sparse).



# Bài tập 2


![Đã tải lên ảnh](https://files.oaiusercontent.com/file-v9O5jMocCURQ99IQcaiQzCfo?se=2024-08-18T07%3A46%3A58Z&sp=r&sv=2023-11-03&sr=b&rscc=max-age%3D299%2C%20immutable%2C%20private&rscd=attachment%3B%20filename%3Dimage.png&sig=rdRE1g8D6wiSc70Zm/nH2RoqlT9mQVly832jsYKvkP8%3D)

ChatGPT: 

Để tìm thứ tự topo cho đồ thị được cho, ta có thể thực hiện theo hai cách: sử dụng ưu tiên theo chiều sâu (DFS) và sử dụng ưu tiên theo chiều rộng (BFS). Ưu tiên chọn thứ tự từ a-z.
### 1. **Ưu tiên theo chiều sâu (DFS):** 
Với DFS, chúng ta thực hiện theo các bước sau:

1. Khởi tạo một ngăn xếp để lưu trữ thứ tự topo.

2. Duyệt qua từng đỉnh, nếu đỉnh chưa được thăm, ta thực hiện DFS từ đỉnh đó.

3. Trong quá trình DFS, sau khi tất cả các đỉnh kề đã được thăm, đỉnh hiện tại được đưa vào ngăn xếp.

4. Sau khi duyệt hết tất cả các đỉnh, ngăn xếp chứa thứ tự topo từ trên xuống dưới.
### 2. **Ưu tiên theo chiều rộng (BFS):** 
Với BFS, chúng ta thực hiện theo các bước sau:

1. Khởi tạo một hàng đợi để lưu các đỉnh có thể thăm được và chưa có đỉnh kề nào chưa được thăm.

2. Đầu tiên, thêm tất cả các đỉnh không có đỉnh kề vào hàng đợi.

3. Duyệt qua hàng đợi, lấy đỉnh ra khỏi hàng đợi và thêm vào thứ tự topo, đồng thời giảm số đỉnh kề của các đỉnh kề còn lại.

4. Nếu số đỉnh kề của một đỉnh trở thành 0, thêm đỉnh đó vào hàng đợi.

5. Tiếp tục cho đến khi hàng đợi trống.

Bây giờ, mình sẽ tiến hành áp dụng hai phương pháp trên cho đồ thị này để tìm ra thứ tự topo.

### **1. Tìm thứ tự topo bằng DFS:** 

Để thực hiện DFS, ta sẽ duyệt qua các đỉnh theo thứ tự từ `a-z`. Ta bắt đầu từ đỉnh đầu tiên chưa được thăm và thực hiện DFS đến khi không còn đỉnh nào chưa thăm kề nó.**Các bước thực hiện:**  
- **Bước 1:**  Khởi tạo ngăn xếp rỗng và một danh sách để đánh dấu các đỉnh đã thăm.
 
- **Bước 2:**  Duyệt qua các đỉnh từ `m` đến `z` theo thứ tự từ `a-z`. 
  - **Đỉnh m:**  DFS từ `m`, thăm lần lượt `m -> q -> t -> x`, sau đó quay lại thăm `u -> r -> n -> o -> v -> y -> z -> p -> s -> w`. Đỉnh cuối cùng được thêm vào ngăn xếp theo thứ tự DFS là đỉnh mà không còn đỉnh nào kề chưa thăm.
 
- **Bước 3:**  Khi tất cả các đỉnh đã được thăm, lấy các đỉnh ra khỏi ngăn xếp (theo thứ tự từ cuối về đầu) để có thứ tự topo.
**Thứ tự topo bằng DFS:** 
Kết quả là `m, n, o, p, q, r, s, t, u, v, w, x, y, z`**2. Tìm thứ tự topo bằng BFS:** 
Để thực hiện BFS, ta cần:

- Tính bậc vào của tất cả các đỉnh.

- Đưa các đỉnh có bậc vào bằng 0 vào hàng đợi.

- Duyệt các đỉnh từ hàng đợi, thêm vào thứ tự topo và giảm bậc vào của các đỉnh kề.
**Các bước thực hiện:**  
- **Bước 1:**  Tính bậc vào của tất cả các đỉnh. Ban đầu, các đỉnh không có đỉnh nào trỏ tới (bậc vào 0) là `m, n`.
 
- **Bước 2:**  Đưa các đỉnh `m, n` vào hàng đợi.
 
- **Bước 3:**  Thăm `m` trước, sau đó đến `n`, tiếp tục thăm các đỉnh kề khác. Khi thăm đỉnh `q`, thêm `q` vào thứ tự topo, sau đó đến các đỉnh khác như `t, x, u, r, o, v, y, z, p, s, w`.
 
- **Bước 4:**  Khi hàng đợi trống, ta sẽ có thứ tự topo.
**Thứ tự topo bằng BFS:** 
Kết quả là `m, n, o, p, q, r, s, t, u, v, w, x, y, z`

---

**Kết luận:**  
- Thứ tự topo bằng DFS và BFS trong trường hợp này là giống nhau, đều là `m, n, o, p, q, r, s, t, u, v, w, x, y, z`.

1 câu ds liền kề, mtrix liền kề
duyệt rộng duyệt sâu
1 trong 2 giải thuật, tìm cây cung nhỏ nhất, đường đi ngắn nhất theo giải thuật Djiskas
phải ôn lại bảng trnagj thái khi học dijikas, nó sẽ dễ hơn cấu trúc rời rạc
nội dung avl và splay phải tự ôn