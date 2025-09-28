#include<bits/stdc++.h>
using namespace std;

int main(){
    int s;
    cin >> s;
    for(int j = 0; j < s; j ++){
        int n, i;
        double p;
        cin >> n >> p >> i;
        double ans;
        if(p == 0) ans = 0;
        else{
            double numerator = p * pow((1 - p), (i - 1));
            double denominator = 1 - (pow((1-p), n));
            ans = numerator / denominator;
        }
        cout << fixed << setprecision(4) << ans << endl;
    }
    return 0;
}
