#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> ans;
    while(n > 0){
        int r;
        cin >> r;
        vector<int> num;
        for(int i = 0; i < r; i ++){
            int tmp;
            cin >> tmp;
            num.push_back(tmp);
        }
        sort(num.begin(), num.end());
        int mid = r/2, result;

        if(r % 2 == 0){
            result = (num[mid-1] + num[mid]) / 2;
        }
        else{
            result = num[mid];
        }
        int total = 0;
        for(int j = 0; j < r; j ++){
            total += abs(result - num[j]);
        }
        ans.push_back(total);
        n --;
    }
    for(int i = 0; i < ans.size(); i ++){
        cout << ans[i] << endl;
    }
    return 0;
}
