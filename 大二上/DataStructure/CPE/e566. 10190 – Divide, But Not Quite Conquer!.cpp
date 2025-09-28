#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n, m;
    vector<long long int> list; 
    bool isBoring;

    while (cin >> n >> m){
        isBoring = false;
        list.clear();

        if (n < m || m <= 1 || n <= 1){
            cout << "Boring!" << endl;
        } else {
            for (; n > 1; n /= m){
                if (n % m == 0){
                    list.push_back(n);
                } else {
                    isBoring = true;
                    break;
                }
            }
            list.push_back(1);

            if (!isBoring){
                cout << list[0];
                for (int i = 1; i < list.size(); i++){
                    cout << " " << list[i];
                }
                cout << endl;
            }else{
                cout << "Boring!" << endl;
            }
        }
    }
    return 0;
}
