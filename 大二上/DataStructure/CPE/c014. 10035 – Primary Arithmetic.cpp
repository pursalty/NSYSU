#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    while(cin >> a >> b){
        if(a == 0 && b == 0){
            break;
        }
        int carry = 0, count = 0;
        while(a > 0 || b > 0){
            int ra = a % 10, rb = b % 10;
            carry += ra + rb;
            if(carry >= 10) count ++;
            carry /= 10;
            a /= 10;
            b /= 10;
        }
        if(count == 0){
            cout << "No carry operation.\n";
        }
        else if(count == 1){
            cout << "1 carry operation.\n";
        }
        else{
            cout << count << " carry operations.\n";
        }
    }
    return 0;
}
