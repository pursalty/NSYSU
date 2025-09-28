#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}
int main(){
    int num;
    while(cin >> num && num != 0){
        long long g = 0;
        for(int i = 1; i <= num; i ++){
            for(int j = i + 1; j <= num; j ++){
                g += gcd(i, j);
            }
        }
        cout << g << endl;
    }
    return 0;
}
