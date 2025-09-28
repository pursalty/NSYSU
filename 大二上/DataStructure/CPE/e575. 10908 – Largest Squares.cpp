#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;
    string tmp;
    getline(cin, tmp);
    while(num --){
        int l, h, n;
        cin >> l >> h >> n;
        vector<vector<char>> arr(l, vector<char>(h));
        for(int i = 0; i < l; i ++){
            for(int j = 0; j < h; j ++){
                cin >> arr[i][j];
            }
        }
        cout << l << " " << h << " " << n << endl;
        for(int k = 0; k < n; k ++){
            int a, b;
            cin >> a >> b;
            char target = arr[a][b];
            int size = 0;
            bool chk = true;
            while(chk){
                size ++;
                if(size + a >= l || a - size < 0 || b + size >= h || b - size < 0) break;
                for(int i = a - size; i <= size + a; i ++){
                    for(int j = b - size; j <= size + b; j ++){
                        if(arr[i][j] != target){
                            chk = false;
                            break;
                        }
                    }
                    if(!chk) break;
                }
            }
            cout << (2 * size - 1) << endl;
        }
    }
    return 0;
}
