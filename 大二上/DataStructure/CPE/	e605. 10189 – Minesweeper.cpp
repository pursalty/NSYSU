#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    int cnt = 1;
    while(cin >> a >> b){
        if(a == 0 && b == 0) break;
        vector<vector<char>> ch(a, vector<char>(b));
        for(int i = 0; i < a; i ++){
            for(int j = 0; j < b; j ++){
                cin >> ch[i][j];
            }
        } 

        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        if(cnt != 1) cout << endl;
        cout << "Field #" << cnt << ":" << endl;
        for(int i = 0; i < a; i ++){
            for(int j = 0; j < b; j ++){
                if(ch[i][j] == '*'){
                    cout << '*';
                }
                else{
                    int count = 0;
                    for(int d = 0; d < 8; d ++){
                        int ni = i + dx[d], nj = j + dy[d];
                        if(ni >= 0 && ni < a && nj >= 0 && nj < b && ch[ni][nj] == '*') count ++;
                    }
                    cout << count;
                }
            }
            cout << endl;
        }
        cnt ++;
    }
    return 0;
}
