#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;
    for(int i = 0; i < num; i ++){
        int a, b, x, y;
        cin >> a >> b;
        x = (a + b) / 2;
        y = a - x;
        if(x < 0 || y < 0 || x + y != a || x - y != b){
            cout << "impossible\n";
        }
        else{
            cout << x << " " << y << endl;
        }
    }
    return 0;
}
