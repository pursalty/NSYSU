#include <bits/stdc++.h>
using namespace std;

void fact(int n)
{
    vector<int> ans(1, 1);

    for (int i = 1; i <= n; i++)
    {
        int remain = 0;
        for (int j = 0; j < ans.size(); j++)
        {
            ans[j] = (ans[j] * i) + remain;
            remain = ans[j] / 10;
            ans[j] %= 10;
        }
        while (remain > 0)
        {
            int tmp = remain % 10;
            ans.push_back(tmp);
            remain /= 10;
        }
        cout << i << "!=";
        for (int l = ans.size() - 1; l >= 0; l--)
        {
            cout << ans[l];
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int num;
    vector<int> arr;
    while (cin >> num && num != 0)
    {
        arr.push_back(num);
    }
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        fact(arr[i]);
    }
    return 0;
}