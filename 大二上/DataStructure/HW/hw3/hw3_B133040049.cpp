// Author: B133040049 李梓銜
// Date: 2025/10/4
// Purpose: 一個n*n的西洋棋盤上，騎士(knight)置於某位置(x,y)，撰寫一個程式以便找出此騎士(n2-1)次移動的順序，而每個格子只拜訪過一次。
//          實作方式使用stack，而不使用recursion。

#include <bits/stdc++.h>
using namespace std;

// 建立一個template，主要型別參數為T，第二型別參數為Container, 若無指定，則為deque<T>
template <class T, class Container = deque<T>>

// 建立一個 class Stack，裡面包含stack的一些基本功能如push, pop, empty, top
class Stack
{
protected:
    Container c;

public:
    void push(const T &val)
    {
        c.push_back(val);
    }
    void pop()
    {
        c.pop_back();
    }
    bool empty() const
    {
        return c.empty();
    }
    T &top()
    {
        return c.back();
    }
};

// 建立一個陣列用來表示方向K1~K8
int dir[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

// 計算Backtracking的函式
void calculate(int n)
{
    // 宣告一個 Stack，元素型別為 tuple<int,int,int,int>，裡面分別儲存x, y(座標), 走第幾步，方向
    Stack<tuple<int, int, int, int>> st;
    // 宣告一個vector visited來記錄這個座標是否有走過
    vector<vector<int>> visited(n + 1, vector<int>(n + 1, 0));
    // 宣告一個vector position來記錄這個座標是第幾步走的
    vector<vector<int>> position(n + 1, vector<int>(n + 1, 0));

    // 第一步為(1, 1)，方向0
    st.push({1, 1, 1, 0});

    // 若st不為空，則繼續找，直到所有方向皆找完，且已回到第一步了
    while (!st.empty())
    {
        // 取出st最頂元素並從st刪除->先往回退一步
        auto cur = st.top();
        st.pop();

        // 分別記錄下來為座標，步數，方向
        int cx = get<0>(cur);
        int cy = get<1>(cur);
        int step = get<2>(cur);
        int dirIndex = get<3>(cur);

        // 將此座標標示為已找到，並記錄
        visited[cx][cy] = 1;
        position[cx][cy] = step;

        // 若已全部走完，則印出
        if (step == n * n)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                    cout << setw(3) << position[i][j] << " ";
                cout << endl;
            }
            cout << endl;
            return;
        }

        // 宣告一個變數來檢查是否有倒退
        bool chk = true;
        // 依照方向去走下去，直到在規範內或所有方向皆已試完
        for (int i = dirIndex; i < 8; i++)
        {
            // 宣告下一步的座標位置
            int nx = cx + dir[i][0];
            int ny = cy + dir[i][1];

            // 若座標在規範內，則記錄下來，並跳出迴圈
            if (nx > 0 && nx <= n && ny > 0 && ny <= n && visited[nx][ny] == 0)
            {
                get<3>(cur) = i + 1;
                st.push(cur);
                st.push({nx, ny, step + 1, 0});
                // 沒有往回，更改chk
                chk = false;
                break;
            }
        }

        // 已往回，故要將此座標標示為未走過
        if (chk)
        {
            visited[cx][cy] = 0;
            position[cx][cy] = 0;
        }
    }

    // 無解，則輸出:
    cout << "No solution\n"
         << endl;
}

int main()
{
    // 計算並輸出1~6的結果
    for (int i = 1; i <= 6; i++)
    {
        calculate(i);
    }
    return 0;
}
