#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++){
        int num;
        cin >> num;
        int hex_num = 0, tmp = num;
        while(tmp > 0){
            hex_num = (tmp%10) + hex_num * 16;
            tmp /= 10;
        }
        int bin = 0, hex = 0, tmp_h = hex_num;
        tmp = num;
        while(tmp > 0  || tmp_h > 0){
            if(tmp % 2 == 1) bin ++;
            if(tmp_h % 2 == 1) hex ++;
            tmp /= 2;
            tmp_h /= 2;
        }
        cout << bin << " " << hex << endl;
    }
    return 0;
}
