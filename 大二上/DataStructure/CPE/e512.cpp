#include<bits/stdc++.h>
using namespace std;

int main(){
    double x1, x2, x3, x4, y1, y2, y3, y4;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4){
        double ans_x, ans_y;
        if(fabs(x1 - x3) < 1e-9 && fabs(y1 - y3) < 1e-9){
            ans_x = x2 + x4 - x1;
            ans_y = y2 + y4 - y1;
        }
        else if(fabs(x2 - x3) < 1e-9 && fabs(y2 - y3) < 1e-9){
            ans_x = x1 + x4 - x2;
            ans_y = y1 + y4 - y2;
        }
        else if(fabs(x1 - x2) < 1e-9 && fabs(y1 - y2) < 1e-9){
            ans_x = x3 + x4 - x1;
            ans_y = y3 + y4 - y1;
        }
        else if(fabs(x1 - x4) < 1e-9 && fabs(y1 - y4) < 1e-9){
            ans_x = x2 + x3 - x1;
            ans_y = y2 + y3 - y1;
        }
        else if(fabs(x2 - x4) < 1e-9 && fabs(y2 - y4) < 1e-9){
            ans_x = x1 + x3 - x2;
            ans_y = y1 + y3 - y2;
        }
        else if(fabs(x4 - x3) < 1e-9 && fabs(y4 - y3) < 1e-9){
            ans_x = x2 + x1 - x4;
            ans_y = y2 + y1 - y4;
        }
        cout <<fixed << setprecision(3) << ans_x << " " << ans_y << endl;
    }
    return 0;
}
