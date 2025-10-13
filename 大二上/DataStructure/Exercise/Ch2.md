---
title: Ch2

---

### 2.1.4
>Implememnt a class $Complex$, which represent the Complex Number data type. Implement the following operations:
#### (b)
> Overload **$operator+$** to add two complex numbers.
```C++
#include <iostream>
using namespace std;

class Complex {
private:
    double real;   // 實部
    double imag;   // 虛部

public:
    // 預設建構子
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    // getter for real part
    double getReal() const { return real; }

    // getter for imaginary part
    double getImag() const { return imag; }

    // 重載 + 運算子
    Complex operator+(const Complex &other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // 輸出函數
    void print() const {
        cout << real;
        if (imag >= 0) cout << " + " << imag << "i";
        else cout << " - " << -imag << "i";
        cout << endl;
    }
};

int main() {
    Complex a(2, 3);  // 2 + 3i
    Complex b(1, 4);  // 1 + 4i

    Complex c = a + b; // 使用重載的 + 運算子

    c.print(); // 輸出 3 + 7i

    return 0;
}

```
#### (c\)
>Overload **$operation*$** to multiply two complex numbers.
```C++
Complex operator*(const Complex &other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }
```
---
### 2.5.2
>How many values can be held by each of the arrays _a_[_n_], _b_[_n_][_m_], _c_[_n_][2][3]?

$a$[$n$] : $n$
$b$[$n$][$m$] : $n \times m = mn$
$c$[$n$][2][3] : $n \times 2 \times 3 = 6n$

---
### 2.5.3
>Obtain an adressing formular for the element _$a$_[_$i$~1~_][_$i$~2~_], ... , [_$i$~n~_] in an array declared as _$a$_[_$u$~1~_][_$u$~2~_], ... , [_$u$~n~_]. Assume a column-major representation of the array with one word per element and $\alpha$ the adress of _$a$_[0][0], ... , [0]. In a column-major representation, a, two-dimensional array is stored sequentilly by columns rather than by rows.

**問題：**  
求 n 維陣列 `a[u_1][u_2]...[u_n]` 中元素 `a[i_1][i_2]...[i_n]` 的位址公式，假設使用 **column-major** 存放方式，每個元素佔一個 word，α 為 `a[0][0]...[0]` 的位址。

**解答：**

1. **Column-major 存放規則**  
在 column-major（列優先）表示法中：
- 最內層維度的元素變化最慢。
- 最外層維度的元素變化最快。

2. **公式推導**  

假設 `a[i_1][i_2]...[i_n]` 是目標元素，則它在記憶體中的偏移量（以 word 為單位）為：

$$
\text{offset} = i_1 + u_1 i_2 + u_1 u_2 i_3 + \dots + u_1 u_2 \cdots u_{n-1} i_n
$$

使用求和表示法：

$$
\text{offset} = \sum_{k=1}^{n} \left( i_k \prod_{j=1}^{k-1} u_j \right),
$$

其中約定：

$$
\prod_{j=1}^{0} u_j = 1
$$

3. **最終位址公式**  

$$
\text{Address of } a[i_1, i_2, \dots, i_n] = \alpha + \sum_{k=1}^{n} \left( i_k \prod_{j=1}^{k-1} u_j \right)
$$


**舉例（2維陣列）**  

若 `a[u_1][u_2]`，則 column-major 位址公式為：

$$
\text{Address of } a[i_1][i_2] = \alpha + i_1 + u_1 \cdot i_2
$$

對比 row-major（行優先）公式：

$$
\text{Address of } a[i_1][i_2] = \alpha + u_2 \cdot i_1 + i_2
$$
---


### 2.8.3

>When all the elements either above or below the main diagonal of square matrix are zero, then the matrix is said to be triangular. Figure 2.8 shows a lower and upper triangular matrix. In a lower triangular matrix, $a$, with $n$ rows, the maximum number of nonezero terms in row $i$ is $i+1$. Hence, the total number of nonezero terms is $\sum_{i=0}^{n-1}i(i+1) = \frac{n(n+1)}{2}$. For large $n$ it would be worthwhile to save the space taken by the zero entries in the upper triangle. Obtain an addressing formular for elements $a$~ij~ in the lower triangle if this lower triangle is stored by rows in an array $b[\frac{n(n+1)}{2}]$ with $a$[0][0] being stored in $b$[0]. What is the relationship between $i$ and $j$ for elements in the zero part of $A$?

>[!Note] Figure 2.8
>$$
\textbf{Lower Triangular:} \quad
\begin{bmatrix}
x &  &  &  &  \\
x & x &  & \text{zero} &  \\
x  & \text{non-} & x &  &  \\
x & \text{zero} &  & x &  \\
x & x & x & x & x
\end{bmatrix}
\qquad\qquad
\textbf{Upper Triangular:} \quad
\begin{bmatrix}
x & x & x & x & x \\
  & x & x & \text{non-} & x \\
  & \text{zero} & x & \text{zero} & x \\
  &   &   & x & x \\
  &   &   &   & x
\end{bmatrix}
$$

**問題：**  
假設方陣 $A[n][n]$ 是下三角矩陣，主對角線上方元素皆為零。第 $i$ 行的非零元素數量為 $i+1$，總非零元素數量為：

$$
\sum_{i=0}^{n-1} (i+1) = \frac{n(n+1)}{2}
$$

將下三角矩陣按照**行優先**存放到一維陣列

$$
b[0 \dots \frac{n(n+1)}{2}-1]
$$

並且 $a[0][0]$ 存在 $b[0]$，求：

1. 元素 $a_{ij}$ 在一維陣列 $b$ 的索引公式  
2. 零元素的條件（上三角部分）

**解答：**

1. **行起始索引**  

第 $i$ 行的非零元素在一維陣列中的起始索引為：

$$
\text{start index of row } i = \sum_{k=0}^{i-1} (k+1) = \frac{i(i+1)}{2}
$$

2. **行內偏移**  

在第 $i$ 行中，第 $j$ 個元素的偏移量為：

$$
\text{offset in row } i = j \quad (0 \le j \le i)
$$

3. **最終索引公式**  

$$
b\Big[\frac{i(i+1)}{2} + j\Big] = a_{ij}, \quad 0 \le j \le i < n
$$

4. **零元素條件**  

下三角矩陣的零元素位於上三角部分：

$$
a_{ij} = 0 \quad \text{if } j > i
$$

**總結：**

- 下三角元素的行優先索引公式：
$$
b\Big[\frac{i(i+1)}{2} + j\Big] = a_{ij}
$$
- 上三角零元素條件：
$$
j > i
$$


---

### 2.8.5
>Another kind of sparse matrix that arises often in practice is the tridiagonal matrix. In this square matrix, all elements other than those on the major diagonal and on the diagonals immediately above and below this one are zero (Figure 2.9). If the elements in the band formed by these three diagonals are representedby rows in an array, $b$, with $a$[0][0] being stored in $b$[0], obtain an alorithm to determine the value of $a$[$i$][$j$], $0 \leq i,j < n$from the array b.

>[!Note] Figure 2.9: Tridiagonal matrix
>$$
\textbf{Tridiagonal matrix:} \quad
\begin{bmatrix}
x & x &   &   &   &   &   \\
x & x & x &   &   &   &   \\
  & x & x & x &   &   &   \\
  &   & \cdot & \cdot & \cdot &   & \text{zero} \\
  & \text{zero} &   & \cdot & \cdot & \cdot &   \\
  &   &   &   & x & x & x \\
  &   &   &   & x & x & x
\end{bmatrix}
$$


**問題：**  
給定方陣 $A[n][n]$ 是三對角矩陣，即：

$$
a_{ij} = 0 \quad \text{if } |i-j|>1
$$

三條對角線依 **行優先** 存到一維陣列 `b`，`a[0][0]` 對應 `b[0]`。求算法：對任意 `(i,j)`，找到 `a[i][j]`。


1️⃣ 索引規則

- **主對角線**（`a[i][i]`）：行內第一個元素  
- **上對角線**（`a[i][i+1]`）：每行第二個元素（除了最後一行）  
- **下對角線**（`a[i][i-1]`）：每行第三個元素（除了第一行）

假設每行存放：
- 第一行：`a[0][0], a[0][1]`  
- 中間行（1 ≤ i ≤ n-2）：`a[i][i-1], a[i][i], a[i][i+1]`  
- 最後一行：`a[n-1][n-2], a[n-1][n-1]`  


2️⃣ 計算 b 中的起始索引

每行非零元素數量：
- 第 0 行：2 個
- 第 n-1 行：2 個
- 其他行：3 個  

定義 `row_start[i]` 為第 i 行在 b 中的起始索引：

$$
\begin{cases}
row\_start[0] = 0 \\
row\_start[i] = row\_start[i-1] + (\text{number of non-zero elements in row } i-1), & i=1..n-1
\end{cases}
$$

- 第 0 行 2 個  
- 第 1..n-2 行 3 個  
- 第 n-1 行 2 個


3️⃣ 確定元素在行內偏移

- 對於任意 `(i,j)`：
  - 如果 $j = i-1$ → 下對角線 → 行內偏移 = 0
  - 如果 $j = i$ → 主對角線 → 行內偏移 = 1 (除第 0 行外)  
    - 第 0 行偏移 = 0  
    - 第 n-1 行偏移 = 1
  - 如果 $j = i+1$ → 上對角線 → 行內偏移 = 2  
    - 第 0 行偏移 = 1  
    - 第 n-1 行偏移 = 不存在

4️⃣ 最終算法（pseudocode）

```text
function getA(i, j, b, n):
    if |i-j| > 1:
        return 0  // 非對角帶內元素為零

    // 計算 row_start[i]
    start = 0
    for k = 0 to i-1:
        if k == 0 or k == n-1:
            start += 2
        else:
            start += 3

    // 計算行內偏移
    if i == 0:
        if j == 0: offset = 0
        else if j == 1: offset = 1
    else if i == n-1:
        if j == n-2: offset = 0
        else if j == n-1: offset = 1
    else:  // 中間行
        if j == i-1: offset = 0
        else if j == i: offset = 1
        else if j == i+1: offset = 2

    return b[start + offset]

```

### 2.8.6

>A square band matrix $a$~n,a~ is an $n \times n$ matrix which all the nonezero terms lie in a band certered around the main diagonal. The band includes $a-1$ diagonals below and above the main diagonal and also the main diagonal (Figure 2.10).

:::info
>[!Note] Figure 2.10: Square band matrix
![cac33c6c-e91a-4dc8-bdf5-08b224d596d4](https://hackmd.io/_uploads/Bk5PG8Upxe.jpg)
:::
#### (c\)
>Assume that the band of $a$~n,a~ is stored sequentially in an array $b$ by diagonals starting with the lowermost diagonal. Thus, $a$~4,3~ above would have the following representations:
>$$
\begin{array}{cccccccccccccc}
b[0] & b[1] & b[2] & b[3] & b[4] & b[5] & b[6] & b[7] & b[8] & b[9] & b[10] & b[11] & b[12] & b[13] \\[1em]
9 & 7 & 8 & 3 & 6 & 6 & 0 & 2 & 8 & 7 & 4 & 9 & 8 & 4 \\
a_{20} & a_{31} & a_{10} & a_{21} & a_{32} & a_{00} & a_{11} & a_{22} & a_{33} & a_{01} & a_{12} & a_{23} & a_{02} & a_{13} \\[1em]
\end{array}
$$
>Obtain an address formular for the location of an element $a$~ij~ in the lower band of $a$~n,a~, e.g., LOC($a$~20~) = 0, LOC($a$~31~) = 1 in the example above.



**問題重述：**  
- 矩陣 $A_{n,a}$ 為 $n \times n$ 的方陣帶狀矩陣  
- 帶寬 $a$，包含主對角線及上下 $a-1$ 條對角線  
- 下帶元素按 **對角線順序從最下方開始、按行** 存到一維陣列 $b$  
- 例如 $a_{4,3}$ 的存法：

$$
\begin{array}{cccccccccccccc}
b[0] & b[1] & b[2] & b[3] & b[4] & b[5] & b[6] & b[7] & b[8] & b[9] & b[10] & b[11] & b[12] & b[13] \\
9 & 7 & 8 & 3 & 6 & 6 & 0 & 2 & 8 & 7 & 4 & 9 & 8 & 4 \\
a_{20} & a_{31} & a_{10} & a_{21} & a_{32} & a_{00} & a_{11} & a_{22} & a_{33} & a_{01} & a_{12} & a_{23} & a_{02} & a_{13} \\
\end{array}
$$

求 **LOC($a_{ij}$)**。

 1️⃣ 確定元素所在對角線

- 設第 $k$ 條對角線為：
$$
k = i - j + (a-1)
$$  
- 這裡 \(k = 0\) 為最下方對角線，\(k = a-1\) 為主對角線。

 2️⃣ 計算對角線在一維陣列的起始索引

- 設 \(\text{start}_k\) 為第 $k$ 條對角線在 $b$ 的起始索引  
- 對第 $k$ 條對角線，其元素個數：
$$
\text{len}_k = n - |(a-1) - k|
$$ 
- 對角線起始索引：
$$
\text{start}_0 = 0
$$  
$$
\text{start}_k = \sum_{m=0}^{k-1} \text{len}_m, \quad k \ge 1
$$

 3️⃣ 計算行內偏移

- 行內偏移：
$$
\text{offset} = j - \max(0, i-(a-1))
$$

 4️⃣ LOC 公式

綜合以上，可得到：

$$
\boxed{
\text{LOC}(a_{ij}) = \text{start}_{i-j+a-1} + \big( j - \max(0, i-(a-1)) \big), \quad |i-j| \le a-1
}
$$

> 超出帶寬的元素 \(|i-j| \ge a\) 為零，不存入 $b$。

 5️⃣ 範例驗證

以 $a_{4,3}$ 為例：  

- LOC($a_{20}$)：
  - i=2, j=0, a=3  
  - k = 2-0+2 = 4 ???  
  - 根據存法對應 b[0] → 公式需按「從最下對角線開始、行優先累加」計算 start_k  
- LOC($a_{31}$) = 1 → 符合存法

> 注意：公式中 start_k 計算需依實際存法累加每條對角線元素數量，核心思路是：
> 1. 確定對角線 (k)  
> 2. 計算 start_k  
> 3. 計算行內偏移 offset  
> 4. LOC = start_k + offset



 [2022quiz2](https://drive.google.com/file/d/11XrCHM65SeHdADYFuonMNgFfxVEt4Rfm/view?usp=sharing)
  [2023quiz2](https://drive.google.com/file/d/1ynE9RpxDppaNlVoWi1T39fYvaN6NY3rk/view?usp=sharing)
   [2024quiz2](https://drive.google.com/file/d/17cSnvnGuz2Pg9R9AboJ-rTm-Z-WJRgKu/view?usp=sharing)
    [Array ppt](https://drive.google.com/file/d/1LNshlSad-CIDGi-rP4fTTIVIlTNc-h2_/view?usp=sharing)


