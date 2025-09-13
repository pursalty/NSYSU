#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> result(n - 1);
        for (int j = 0; j < n - 1; j++)
        {
            result[j] = abs(arr[j] - arr[j + 1]);
        }
        sort(result.begin(), result.end());
        bool chk = true;
        for (int k = 0; k < n - 2; k++)
        {
            if (result[k + 1] - result[k] != 1)
            {
                chk = false;
                break;
            }
        }
        if (chk && result[0] == 1 && result[n - 2] == n - 1)
        {
            cout << "Jolly\n";
        }
        else
        {
            cout << "Not jolly\n";
        }
    }
    return 0;
}
