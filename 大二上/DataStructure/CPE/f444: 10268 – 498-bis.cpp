#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    while(cin >> x){
        string line;
        getline(cin, line); // 吃掉換行
        getline(cin, line);

        stringstream ss(line);
        vector<long long> poly;
        long long a;
        while(ss >> a) poly.push_back(a);

        int n = poly.size() - 1; // 多項式最高次
        long long ans = 0;
        for(int i = 0; i < n; i++){ // 導數只有到 a1
            ans = ans * x + poly[i] * (n - i);
        }

        cout << ans << endl;
    }
    return 0;
}
