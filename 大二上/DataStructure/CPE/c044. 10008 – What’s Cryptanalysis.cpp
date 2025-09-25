#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;
    cin.ignore();
    map<char, int> ans;
    for(int i = 0; i < num; i ++){
        string str;
        getline(cin, str);
        for(char & c : str) c = toupper(c);
        for(int j = 0; j < str.size(); j ++){
            if(isalpha(str[j])){
                ans[str[j]] ++;
            }
        }
    }
    vector<pair<char, int>> result;
    for(auto p : ans){
        result.push_back(p);
    }
    sort(result.begin(), result.end(), [](pair<char, int> a, pair<char, int> b){
        if(a.second != b.second) return a.second > b.second;
        return a.first< b.first;
    });
    for(int j = 0; j < result.size(); j ++){
        cout << result[j].first << " " << result[j].second << endl;
    }
    return 0;
}
