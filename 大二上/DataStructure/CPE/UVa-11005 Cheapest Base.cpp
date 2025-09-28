#include<bits/stdc++.h>
using namespace std;

int main(){
    int numOfCase, cost, num;
    cin >> numOfCase;
    for(int Case = 1; Case <= numOfCase; Case ++){
        map<int, int> mp;
        for(int i = 0; i < 36; i ++){
            cin >> cost;
            mp[i] = cost;
        }
        cin >> num;
        if(Case > 1) cout << endl;
        cout << "Case " << Case << ":\n";
        while(num --){
            map<int, int> total;
            int x, small = INT_MAX;
            cin >> x;
            for(int i = 2; i <= 36; i ++){
                int tmp = x, a = 0;
                while(tmp){
                    a += mp[tmp % i];
                    tmp /= i;
                }
                total[i] = a;
                small = min(small, a);
            }
            cout << "Cheapest base(s) for number " << x << ":";
            for(int i = 2; i <= 36; i ++){
                if(total[i] == small)cout << " " << i;
            }
            cout << endl;
        }
    }
    return 0;
}
