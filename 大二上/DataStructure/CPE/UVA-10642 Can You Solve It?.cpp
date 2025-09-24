#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;
    for(int k = 1; k <= num; k ++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        auto index = [](long long x, long long y) -> long long {
            return (x + y) * (x + y + 1) / 2 + x;
        };

        long long count = index(x2, y2) - index(x1, y1);
        cout << "Case " << k << ": " << count << endl;
    }
}
