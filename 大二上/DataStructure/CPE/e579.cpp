#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> result;
    for (int i = 0; i < t; i++)
    {
        int day;
        cin >> day;
        int party;
        cin >> party;
        int arr[party];
        vector<int> total(day, 0);
        for (int j = 0; j < party; j++)
        {
            cin >> arr[j];
        }
        for (int k = 0; k < party; k++)
        {
            int tmp = arr[k];
            while (tmp <= day)
            {
                total[tmp-1]++;
                tmp += arr[k];
            }
        }
        int ans = 0;
        for (int m = 0; m < day; m++)
        {
            int tmp = total[m];
            if (tmp > 0 && m % 7 != 5 && m % 7 != 6)
            {
                ans++;
            }
        }
        result.push_back(ans);
    }
    for (int j = 0; j < result.size(); j++)
    {
        cout << result[j] << endl;
    }
    return 0;
}
