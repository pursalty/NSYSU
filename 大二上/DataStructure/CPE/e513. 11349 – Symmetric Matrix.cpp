#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;

    for (int k = 1; k <= num; k++)
    {
        bool chk = true;
        char a, b;
        int n;
        cin >> a >> b >> n;
        int size = n * n;
        long long arr[size];
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
            if (arr[i] < 0)
                chk = false;
        }
        for (int i = 0; i < size / 2 && chk; i++)
        {
            if (arr[i] != arr[size - 1 - i])
            {
                chk = false;
                break;
            }
        }
        cout << "Test #" << k << ": ";
        if (chk)
            cout << "Symmetric.\n";
        else
            cout << "Non-symmetric.\n";
    }
    return 0;
}
