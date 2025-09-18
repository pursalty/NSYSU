#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    while(cin >> a >> b){
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        string str = "";
        int i = 0, j = 0;
        while(i <= a.size() || j <= b.size()){
            if(a[i] == b[j]){
                str += a[i];
                i ++;
                j ++;
            }
            else if(a[i] < b[j]){
                if(i == a.size()) break;
                i ++;
            }
            else {
                if(j == b.size()) break;
                j ++;
            }
        }
        cout << str << endl;
    }
    return 0;
}
