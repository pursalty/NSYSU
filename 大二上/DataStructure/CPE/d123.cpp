#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    int count = 1;
    while (cin >> num)
    {
        int arr[num];
        for (int i = 0; i < num; i++)
        {
            cin >> arr[i];
        }
        bool chk = true;
        set<int> result;
        for (int i = 0; i < num; i++)
        {
            for (int j = i; j < num; j++)
            {
                int n = arr[i] + arr[j];
                if (result.find(n) != result.end())
                {
                    chk = false;
                    break;
                }
                else
                {
                    result.insert(n);
                }
            }
            if (!chk)
                break;
        }
        if (chk)
            cout << "Case #" << count << ": It is a B2-Sequence.\n";
        else
            cout << "Case #" << count << ": It is not a B2-Sequence.\n";
        count++;
    }
    return 0;
}
