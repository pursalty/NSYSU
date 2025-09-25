#include<bits/stdc++.h>
using namespace std;

int main(){
  string str;
  string ans;
  bool first = true;
  while(getline(cin, str)){
    for(char c : str){
      if(c == '"'){
        if(first){
          ans += "``";
          first = false;
        }
        else{
          ans += "''";
          first = true;
        }
      }
      else{
        ans += c;
      }
    }
    ans += "\n";
  }
   cout << ans;
  return 0;
}
