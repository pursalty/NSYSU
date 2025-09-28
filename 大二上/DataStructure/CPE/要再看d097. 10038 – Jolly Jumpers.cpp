#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        if (n == 1) { // 特例 n=1
            cout << "Jolly\n";
            continue;
        }

        vector<bool> seen(n, false); // 差值 1..n-1
        bool jolly = true;
        for (int i = 1; i < n; i++) {
            int diff = abs(arr[i] - arr[i - 1]);
            if (diff < 1 || diff >= n || seen[diff]) {
                jolly = false;
                break;
            }
            seen[diff] = true;
        }

        cout << (jolly ? "Jolly\n" : "Not jolly\n");
    }
}
