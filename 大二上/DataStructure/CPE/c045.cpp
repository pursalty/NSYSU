#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> str;
    string s;
    int max = 0;
    while (getline(cin, s))
    {
        str.push_back(s);
        if (max < s.size())
            max = s.size();
    }
    for (int i = 0; i < max; i++)
    {
        for (int j = str.size() - 1; j >= 0; j--)
        {
            if (i < str[j].size())
                cout << str[j][i];
            else
                cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
