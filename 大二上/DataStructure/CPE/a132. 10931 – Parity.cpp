#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    while(cin >> num && num != 0){
        int count = 0;
        string result = "";
        while(num > 0){
            result = char((num % 2) + '0') + result;
            if(num % 2 == 1) count ++;
            num /= 2; 
        }
        cout << "The parity of " << result << " is " << count << " (mod 2)." << endl;
    }
    return 0;
}
