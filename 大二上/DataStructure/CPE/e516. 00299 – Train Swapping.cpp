#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    while(cin >> num && num != 0){
        int top = 1, north = 2, west = 3, east = 4, south = 5, bottom = 6;
        string str;
        for(int i = 0; i < num; i ++){
            cin >> str;
            if(str == "south"){
                swap(top, north);
                swap(north, bottom);
                swap(bottom, south);
            }
            else if(str == "north"){
                swap(top, south);
                swap(south, bottom);
                swap(bottom, north);
            }
            else if(str == "east"){
                swap(top, west);
                swap(west, bottom);
                swap(bottom, east);
            }
            else{
                swap(top, east);
                swap(east, bottom);
                swap(bottom, west);
            }
        }
        cout << top << endl;
    }
    return 0;
}
