#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long num;
    int chk = 1;
    while (cin >> num)
    {
        if (num == 0)
        {
            cout << chk << ". 0\n";
            chk++;
            continue;
        }

        string str = "";
        int count = 0;

        while (num > 0)
        {
            int tmp;

            if (count % 4 == 1)
            {
                tmp = num % 10;
                if (tmp != 0)
                    str = to_string(tmp) + " shata " + str;
                num /= 10;
            }
            else
            {
                tmp = num % 100;
                if (tmp != 0)
                {
                    if (count % 4 == 0)
                        str = to_string(tmp) + " " + str;
                    else if (count % 4 == 2)
                        str = to_string(tmp) + " hajar " + str;
                    else if (count % 4 == 3)
                        str = to_string(tmp) + " lakh " + str;
                }
                num /= 100;
            }

            count++;
            if (count % 4 == 0 && num > 0)
            {
                str = "kuti " + str;
            }
        }
        cout << chk << ". " << str << endl;
        chk++;
    }
    return 0;
}
