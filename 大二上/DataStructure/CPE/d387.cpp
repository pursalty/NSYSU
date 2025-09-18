#include <bits/stdc++.h>
using namespace std;

int reverse(int n)
{
    int tmp = 0;
    while (n > 0)
    {
        tmp = n % 10 + tmp * 10;
        n /= 10;
    }
    return tmp;
}

bool prime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{

    int num;
    while (cin >> num)
    {
        int reverse_num = reverse(num);
        if (!prime(num))
        {
            cout << num << " is not prime." << endl;
        }
        else if (prime(reverse_num) && reverse_num != num)
        {
            cout << num << " is emirp." << endl;
        }
        else
        {
            cout << num << " is prime." << endl;
        }
    }
    return 0;
}
