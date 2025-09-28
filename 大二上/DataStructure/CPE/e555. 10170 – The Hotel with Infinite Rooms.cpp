#include<bits/stdc++.h>
using namespace std;

int main(){
    long long s, d;
    while(cin >> s >> d){
        long long total = 0, i = s;
        while(total < d){
            total += i;
            if(total >= d){
                cout << i << endl;
                break;
            }
            i ++;
        }
    }
    return 0;
}
