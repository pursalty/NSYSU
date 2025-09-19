#include<bits/stdc++.h>
using namespace std;

int main(){
    int x;
    while(cin >> x){
        string line, enter;
        getline(cin, enter);
        getline(cin, line);

        stringstream ss(line);
        int a;
        vector<int> poly;
        while(ss >> a){
            poly.push_back(a);
        }
        reverse(poly.begin(), poly.end());
        vector<int> after(poly.size() - 1);
        for(int i = 1; i < poly.size(); i ++){
            after[i - 1] = poly[i] * i;
        }
        long long ans = 0;
        for(int j = 0; j < after.size(); j ++){
            ans += after[j] * pow(x, j);
        }
        cout << ans << endl;
    }
    return 0;
}
