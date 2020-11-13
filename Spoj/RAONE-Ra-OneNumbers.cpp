#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e9;
ll dp[40][2][40];
//if posiciones pares - posiciones impares 
//ll dt(int idx, bool top, int cant, int imp, int par,const string s){
ll dt(ll idx, bool top, ll cant,const string s){
  if(idx==s.size()){
    return cant;
  }
  ll &ans = dp[idx][top][cant];
  if(ans!=-1){
    return ans;
  }
  ans = 0;
  int stop = top ? s[idx] : 9;
  for(int i=0; i<=9; i++){
    ans+=dt(idx+1, top && stop==i, cant + (par-imp==1) , s);
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int t; cin>>t;
  while(t--){
    string a, b; cin>>a>>b;
  }
  return 0;
}

