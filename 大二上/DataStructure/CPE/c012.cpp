#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    while(getline(cin, str)){
        map<int, int> result;
        for(int i = 0; i < str.size(); i ++){
            result[str[i]] ++;
        }
        vector<pair<int, int>> final(result.begin(), result.end());
        sort(final.begin(), final.end(), 
        [](pair<int, int> &a, pair<int, int> &b){
            if(a.second != b.second)return a.second < b.second;
            return a.first > b.first;
        });
        for(int j = 0; j < final.size(); j ++){
            cout << final[j].first << " " << final[j].second << endl;
        }
        cout << endl;
    }
    return 0;
}
