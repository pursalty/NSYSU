#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;
    for(int j = 1; j <= num; j ++){
        int a, b;
        cin >> a;
        cin >> b;
        int ans = 0;
        for(int i = a; i <= b; i ++){
            if(i % 2 == 1) ans += i; 
        }
        cout << "Case " << j << ": " << ans << endl;
    }
}
