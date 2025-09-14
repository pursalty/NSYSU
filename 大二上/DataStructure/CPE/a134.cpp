#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    int num;
    for(int i = 0; i < n; i ++){
        cin >> num;
        vector<int> fib{1, 2};
        while(fib.back() <= num){
            fib.push_back(fib.back() + fib[fib.size()-2]);
        }
        fib.pop_back();

        string str = "";
        int remain = num;
        for(int j = fib.size() - 1; j >= 0; j --){
            if(fib[j] <= remain){
                str += '1';
                remain -= fib[j];
            }
            else{
                if(!str.empty()){
                    str += '0';
                }
            }
        }
        cout << num << " = " << str << " (fib)\n";
    }
    return 0;
}
