#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m && n != 0 && m != 0)
    {
        vector<int> odd;
        vector<int> even;
        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if(x % 2 == 0) even.push_back(x);
            else odd.push_back(x);
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end(), greater<int>());
        vector<int> ans;
        for(int i = 1 - m; i < m; i ++){
            for(int j = 0; j < odd.size(); j ++){
                if(odd[j] % m == i) ans.push_back(odd[j]);
            }
            for(int j = 0; j < even.size(); j ++){
                if(even[j] % m == i) ans.push_back(even[j]);
            }
        }
        cout << n << " " << m << endl;
        for(int i = 0; i < ans.size(); i ++){
            cout << ans[i] << endl;
        }
    }
    cout << "0 0" << endl;
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m && (n || m)) {
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        sort(v.begin(), v.end(), [m](int a, int b) {
            int ra = a % m;
            int rb = b % m;

            if (ra != rb) return ra < rb;               // 餘數小的排前
            if ((a % 2) != (b % 2)) return a % 2 != 0;  // 奇數排前偶數
            if (a % 2 != 0) return a > b;              // 都奇數，值大排前
            return a < b;                               // 都偶數，值小排前
        });

        cout << n << " " << m << "\n";
        for (int x : v) cout << x << "\n";
    }
    cout << "0 0\n";
    return 0;
}

*/
