#include <bits/stdc++.h>
using namespace std;

int getValue(char c)
{
    if (c <= '9' && c >= '0')
    {
        return c - '0';
    }
    else if (c <= 'Z' && c >= 'A')
    {
        return c - 'A' + 10;
    }
    else if (c <= 'z' && c >= 'a')
    {
        return c - 'a' + 36;
    }
    return -1;
}

int main()
{
    string str;
    while (getline(cin, str))
    {
        int maxNum = -1;
        long long sum = 0;
        for (int i = 0; i < (int)str.size(); i++)
        {   
            int v = getValue(str[i]);
            if(v == -1) continue;
            if (v > maxNum)
            {
                maxNum = v;
            }
            sum += v;
        }
        bool chk = true;
        for (int i = max(maxNum + 1, 2); i <= 62; i++)
        {
            if (sum % (i - 1) == 0)
            {
                cout << i << endl;
                chk = false;
                break;
            }
        }
        if (chk)
            cout << "such number is impossible!" << endl;
    }
    return 0;
}
