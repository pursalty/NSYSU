#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    while (cin >> num)
    {
        int result = num;
        while (num >= 3)
        {
            num -= 3;
            num++;
            result++;
        }
        if (num == 2)
            result++;
        cout << result << endl;
    }
    return 0;
}
