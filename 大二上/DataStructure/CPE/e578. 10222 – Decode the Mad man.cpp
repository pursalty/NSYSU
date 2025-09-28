#include<bits/stdc++.h>
using namespace std;

int main(){
    string keyboard = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    map<char, char> mp;
    for(int i = 2; i < keyboard.size(); i ++){
        mp[keyboard[i]] = keyboard[i - 2];
    }
    string str;
    while(getline(cin, str)){
        for(int i = 0; i < str.size(); i ++){
            char c = tolower(str[i]);
            if(c == ' ') cout << ' ';
            else cout << mp[c];
        }
        cout << endl;
    }
    return 0;
}
