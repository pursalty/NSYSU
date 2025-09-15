#include<bits/stdc++.h>
using namespace std;

int main(){
    int s;
    cin >> s;
    vector<double> result;
    for(int j = 0; j < s; j ++){
        int n, i;
        double p;
        cin >> n >> p >> i;

        double numerator = p * pow((1 - p), (i - 1));
        double denominator = 1 - (pow((1-p), n));
        double ans = numerator / denominator;
        result.push_back(ans);
    }
    for(int i = 0; i < result.size(); i ++){
        cout << fixed << setprecision(4) << result[i] << endl;
    }
    return 0;
}
