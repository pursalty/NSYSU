#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    while(getline(cin, a) && getline(cin, b)){
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        string str = "";
        int i = 0, j = 0;
        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]){
                str += a[i];
                i++;
                j++;
            }
            else if(a[i] < b[j]){
                i++;
            }
            else{
                j++;
            }
        }
        cout << str << endl;
    }
    return 0;
}
