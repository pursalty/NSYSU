#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a, b;
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0)
            break;
        int first = (int)ceil(sqrt(a)), second = (int)floor(sqrt(b));
        int ans = second - first + 1;
        cout << ans << endl;
    }
    return 0;
}
