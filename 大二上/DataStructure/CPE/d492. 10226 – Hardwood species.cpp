#include <bits/stdc++.h>
using namespace std;

int main() {
    int num;
    cin >> num;
    cin.ignore(); // 吃掉換行符號

    string line;
    while (getline(cin, line) && line.empty());

    for (int i = 0; i < num; i++) {
        map<string,int> cnt;
        int total = 0;

        do {
            if (!line.empty()) {
                cnt[line]++;
                total++;
            }
        } while (getline(cin, line) && !line.empty());

        // map 本身是字典序排序
        for (auto &p : cnt) {
            double percent = (double)p.second * 100.0 / total;
            cout << p.first << " " << fixed << setprecision(4) << percent << "\n";
        }

        if (i != num - 1) cout << "\n";
    }

    return 0;
}
