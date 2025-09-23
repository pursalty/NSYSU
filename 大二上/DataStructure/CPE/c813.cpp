#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    while(cin >> num && num != 0){
        while(num >= 10){
            int tmp = num;
            int n = 0;
            while(tmp > 0){
                n += tmp % 10;
                tmp /= 10;
            }
            num = n;
        }
        cout << num << endl;
    }
    return 0;

}
