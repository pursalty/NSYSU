#include <bits/stdc++.h>
using namespace std;

int main()
{
    string num;
    while (cin >> num && num != "0")
    {
        int sum = 0;
        for (char c : num)
            sum += (c - '0');
        if (sum % 9 != 0)
        {
            cout << num << " is not a multiple of 9.\n";
        }
        else
        {
            int degree = 1;
            while (sum >= 10)
            {
                int tmp = sum;
                int next_n = 0;
                while (tmp > 0)
                {
                    next_n += (tmp % 10);
                    tmp /= 10;
                }
                sum = next_n;
                degree ++;
            }
            cout << num << " is a multiple of 9 and has 9-degree " << degree << ".\n";
        }
    }
    return 0;
}
