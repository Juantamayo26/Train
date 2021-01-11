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
    ll a, b;
    cin>>a>>b;
    if(a<b){
      cout<<b-a<<endl;
      continue;
    }
    if(a%b==0){
      cout<<0<<endl;
      continue;
    }
    int aux = a%b;
    cout<<b-aux<<endl;
  }
  
  return 0;
}

