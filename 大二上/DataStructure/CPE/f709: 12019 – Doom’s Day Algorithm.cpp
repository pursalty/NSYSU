#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;
    while(num --){
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string daysOfWeek[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

        int month, day;
        cin >> month >> day;

        int total = day - 1;
        for(int i = 0; i < month - 1; i ++){
            total += daysInMonth[i];
        }
        total %= 7;
        cout << daysOfWeek[total] << endl;
    }
    return 0;
}
