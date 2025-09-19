#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();

    map<char, vector<int>> finger = {
        {'c',{0,1,1,1,0,0,1,1,1,1}},
        {'d',{0,1,1,1,0,0,1,1,1,0}},
        {'e',{0,1,1,1,0,0,1,1,0,0}},
        {'f',{0,1,1,1,0,0,1,0,0,0}},
        {'g',{0,1,1,1,0,0,0,0,0,0}},
        {'a',{0,1,1,0,0,0,0,0,0,0}},
        {'b',{0,1,0,0,0,0,0,0,0,0}},
        {'C',{0,0,1,0,0,0,0,0,0,0}},
        {'D',{1,1,1,1,0,0,1,1,1,0}},
        {'E',{1,1,1,1,0,0,1,1,0,0}},
        {'F',{1,1,1,1,0,0,1,0,0,0}},
        {'G',{1,1,1,1,0,0,0,0,0,0}},
        {'A',{1,1,1,0,0,0,0,0,0,0}},
        {'B',{1,1,0,0,0,0,0,0,0,0}}
    };

    for(int i = 0; i < N; i++){
        string melody;
        getline(cin, melody);

        vector<int> total(10,0);      // 每根手指按鍵總次數
        vector<int> prev(10,0);       // 前一個音符手指狀態

        for(char c : melody){
            auto it = finger.find(c);
            if(it != finger.end()){
                vector<int>& curr = it->second;
                for(int k = 0; k < 10; k++){
                    if(curr[k] == 1 && prev[k] == 0){
                        total[k]++;        // 只有放開→按下才算
                    }
                    prev[k] = curr[k];     // 更新上一個音符狀態
                }
            }
        }

        // 輸出
        for(int k = 0; k < 10; k++){
            if(k > 0) cout << " ";
            cout << total[k];
        }
        cout << endl;
    }

    return 0;
}
