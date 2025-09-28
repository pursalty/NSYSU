#include<bits/stdc++.h>
using namespace std;

int main(){
    string num;
    while(cin >> num && num != "0"){
        int odd = 0, even = 0;
        for(int i = 0; i < num.size(); i += 2){
            even += (num[i] - '0');
        }
        for(int j = 1; j < num.size(); j += 2){
            odd += (num[j] - '0');
        }
        int ans = abs(even - odd);
        if(ans % 11 == 0){
            cout << num << " is a multiple of 11." << endl;
        }
        else{
            cout << num << " is not a multiple of 11." << endl;
        }
    }
    return 0;
}
