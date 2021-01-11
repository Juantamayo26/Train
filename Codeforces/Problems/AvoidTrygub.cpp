#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e9;

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int t;
  cin>>t;
  while(t--){
    int a; cin>>a;
    map<char, int>s;
    for(int i=0;i<a; i++){
      char x; cin>>x;
      s[x]++;
    }
    for(auto i: s){
      for(int j = 0; j<i.second; j++){
        cout<<i.first;
      }
    }
    cout<<endl;
  }
  
  return 0;
}

