// Author: B133040049 李梓銜
// Date: 2025/10/5
// Purpose: 上一個習題解題方法為使用stack，本題則為recursion。
//          請注意，當你利用recursion撰寫本習題程式時，應該完全不需使用stack。
//          同樣地，上一個習題利用stack設計程式時，亦應該完全沒有recursion。

#include <bits/stdc++.h>
using namespace std;

// 建立一個陣列用來表示方向K1~K8
int dir[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
// 計算Backtracking並判斷是否有解的函式
bool calculate(int n, int x, int y, int step, vector<vector<int>> &visited, vector<vector<int>> &position)
{
    // 將此座標標記為走過，並紀錄為第幾步
    visited[x][y] = 1;
    position[x][y] = step;

    // 若已全部走完，則印出
    if (step == n * n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << setw(3) << position[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    // 依照方向去走下去，直到在規範內或所有方向皆已試完
    for (int i = 0; i < 8; i++)
    {
        // 宣告下一步的座標位置
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        // 若座標在規範內，則執行以下程式
        if (nx > 0 && nx <= n && ny > 0 && ny <= n && visited[nx][ny] == 0)
        {
            // 若calculate(n, nx, ny, step + 1, visited, position)有解，則回傳true
            if (calculate(n, nx, ny, step + 1, visited, position))
            {
                return true;
            }
        }
    }

    // 已往回，故要將此座標標示為未走過
    visited[x][y] = 0;
    position[x][y] = 0;

    return false;
}

int main()
{
    // 計算並輸出1~6的結果
    for (int i = 1; i <= 6; i++)
    {
        // 宣告一個vector visited來記錄這個座標是否有走過
        vector<vector<int>> visited(i + 1, vector<int>(i + 1, 0));
        // 宣告一個vector position來記錄這個座標是第幾步走的
        vector<vector<int>> position(i + 1, vector<int>(i + 1, 0));
        // 呼叫一個函式來檢查在此情況下是否有解
        bool chk = calculate(i, 1, 1, 1, visited, position);

        // 若無解，則輸出:
        if (!chk)
        {
            cout << "No solution\n"
                 << endl;
        }
    }
    return 0;
}