#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    vector<int> ans;
    while (cin >> num)
    {
        vector<int> result;
        int element;
        for (int j = 0; j < num; j++)
        {
            cin >> element;
            result.push_back(element);
        }
        sort(result.begin(), result.end());
        int mid1 = (result.size() - 1) / 2, mid2 = result.size() / 2, minimum = min(result[mid1], result[mid2]), quantity = 0, type = 0;
        for (int j = 0; j < result.size(); j++)
        {
            if (result[j] == result[mid1] || result[j] == result[mid2])
                quantity++;
        }
        if (result[mid1] == result[mid2])
        {
            type = 1;
        }
        else
        {
            type = result[mid2] - result[mid1] + 1;
        }
        ans.push_back(minimum);
        ans.push_back(quantity);
        ans.push_back(type);
    }
    for (int j = 0; j < ans.size(); j++)
    {
        if (j % 3 == 0)
            cout << ans[j];
        else
            cout << " " << ans[j];
        if (j % 3 == 2)
            cout << endl;
    }
    return 0;
}
