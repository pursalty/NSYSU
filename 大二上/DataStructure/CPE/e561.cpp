#include <bits/stdc++.h>
using namespace std;

int main()
{
    int times;
    cin >> times;
    vector<vector<int>> ans(times);
    for (int i = 0; i < times; i++)
    {
        int tmp = 0;
        cin >> tmp;
        for (int j = 0; j < tmp; j++)
        {
            int element;
            cin >> element;
            ans[i].push_back(element);
        }
    }
    for (int k = 0; k < ans.size(); k++)
    {
        int count = 0;
        for (int l = 0; l < ans[k].size(); l++)
        {
            for (int m = 0; m < ans[k].size() - l - 1; m++)
            {
                if (ans[k][m] > ans[k][m + 1])
                {
                    swap(ans[k][m], ans[k][m + 1]);
                    count++;
                }
            }
        }
        cout << "Optimal train swapping takes " << count << " swaps.\n";
    }
    return 0;
}
