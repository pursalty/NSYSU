// Author: B133040049 李梓銜
// Date: 2025/09/08
// Purpose: 製作N階(N為奇數)的魔方陣(magic square)，使其每個橫列、直排、斜對角線相加的值皆相等

#include <bits/stdc++.h>
using namespace std;

void matrix(int n)
{                                                // 一個生成魔方陣，並輸出的函式
    vector<vector<int>> m(n, vector<int>(n, 0)); // 初始魔方陣
    int i = 0, j = n / 2, tmp = 1;               // i為初始的row，j為初始的column，tmp為現在填入的數字

    while (tmp <= (n * n))
    {
        m[i][j] = tmp;
        int ni = (i - 1 + n) % n, nj = (j - 1 + n) % n;
        if (m[ni][nj] != 0)
        {
            i = (i + 1) % n;
        }
        else
        {
            i = ni;
            j = nj;
        }
        tmp++;
    }
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            cout << m[r][c] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

int main()
{

    for (int i = 1; i <= 9; i += 2)
    {
        matrix(i);
    }
}