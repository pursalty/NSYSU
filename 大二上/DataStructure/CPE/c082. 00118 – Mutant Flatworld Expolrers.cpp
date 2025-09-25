#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;

    int ori_x, ori_y, direc;
    char ch_direc;
    char d[4] = {'N', 'E', 'S', 'W'};

    // 只紀錄格子氣味
    set<pair<int, int>> scent;

    while (cin >> ori_x >> ori_y >> ch_direc)
    {
        // 將方向轉成索引
        for (int j = 0; j < 4; j++)
        {
            if (ch_direc == d[j])
            {
                direc = j;
            }
        }

        string str;
        cin >> str;
        bool chk = true;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 'R')
            {
                direc = (direc + 1) % 4;
            }
            else if (str[i] == 'L')
            {
                direc = (direc + 3) % 4;
            }
            else if (str[i] == 'F')
            {
                int nx = ori_x, ny = ori_y;
                if (direc == 0)
                    ny++;
                else if (direc == 1)
                    nx++;
                else if (direc == 2)
                    ny--;
                else if (direc == 3)
                    nx--;

                // 超出邊界
                if (nx > x || nx < 0 || ny > y || ny < 0)
                {
                    // 檢查這格子是否已有氣味
                    if (scent.count({ori_x, ori_y}))
                    {
                        // 有氣味 → 忽略這一步
                        continue;
                    }
                    else
                    {
                        // 沒氣味 → 掉落
                        cout << ori_x << " " << ori_y << " " << d[direc] << " LOST" << endl;
                        scent.insert({ori_x, ori_y});
                        chk = false;
                        break;
                    }
                }
                else
                {
                    ori_x = nx;
                    ori_y = ny;
                }
            }
        }

        if (chk)
        {
            cout << ori_x << " " << ori_y << " " << d[direc] << endl;
        }
    }
    return 0;
}
