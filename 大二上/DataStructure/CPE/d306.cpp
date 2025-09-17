#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;
    cin.ignore();
    for(int i = 1; i <= num; i ++){
        string a, b;
        getline(cin, a);
        getline(cin, b);
        long long num_a = 0, num_b = 0;
        for(int j = 0; j < a.size(); j ++){
            num_a = num_a * 2 + (a[j] - '0');
        }
        for(int k = 0; k < b.size(); k ++){
            num_b = num_b * 2 + (b[k] - '0');
        }
        cout << "Pair #" << i << ": ";
        if (__gcd(num_a, num_b) > 1) {
            cout << "All you need is love!" << endl;
        } else {
            cout << "Love is not all you need!" << endl;
        }
    }
    return 0;
}
