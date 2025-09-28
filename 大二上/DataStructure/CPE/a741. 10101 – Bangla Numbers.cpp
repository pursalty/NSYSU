#include<bits/stdc++.h>
using namespace std;
void num(long long n){
    if(n>=10000000){
        num(n/10000000);
        cout<<" kuti";
        n%=10000000;
    }
    if(n>=100000){
        num(n/100000);
        cout<<" lakh";
        n%=100000;
    }
    if(n>=1000){
        num(n/1000);
        cout<<" hajar";
        n%=1000;
    }
    if(n>=100){
        num(n/100);
        cout<<" shata";
        n%=100;
    }
    if(n){
        cout<<" "<<n;
    }
}
int main(){
    long long a,kase=1;
    while(cin>>a){
        cout<<setw(4)<<kase++<<".";
        if(a){
            num(a);
        }
        else{
            cout<<" 0";
        }
        cout<<endl;
    }
}
