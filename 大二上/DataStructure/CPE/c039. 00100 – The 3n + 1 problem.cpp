#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        int first = min(a, b), second = max(a, b);
        int large = 0;
        int count;
        for (int i = first; i <= second; i++)
        {
            int n = i;
            count = 1;
            while (n != 1)
            {
                if (n % 2 == 1)
                {
                    n = 3 * n + 1;
                }
                else
                {
                    n /= 2;
                }
                count++;
            }
            if (count > large)
                swap(count, large);
        }
        cout << a << " " << b << " " << large << endl;
    }
    return 0;
}
