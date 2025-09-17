#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b;
    while (cin >> a >> b)
    {
        vector<long long> result;
        bool chk = true;
        if (b == 0 || b == 1)
        {
            chk = false;
        }
        result.push_back(a);
        while (a >= b && chk)
        {
            if (a % b == 0)
            {
                a /= b;
                result.push_back(a);
            }
            else
            {
                chk = false;
                break;
            }
        }
        if (chk && result.back() == 1)
        {
            for (int i = 0; i < result.size(); i++)
            {
                cout << result[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Boring!" << endl;
        }
    }
    return 0;
}
