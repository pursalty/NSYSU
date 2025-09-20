#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    map<string, int> result;
    int num;
    cin >> num;
    string a;
    getline(cin, a);
    for(int i = 0; i < num; i ++){
        string line;
        getline(cin, line);
        string country = "";
        for(int k = 0; k < line.size(); k ++){
            if(line[k] == ' ') break;
            country += line[k];
        }
        result[country] ++;
    }
    for(auto p: result){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
