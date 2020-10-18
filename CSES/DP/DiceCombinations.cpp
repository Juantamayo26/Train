#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const ll maxi = 1e6;
ll dp[maxi+10];
const ll MOD = 1e9+7;

ll f(ll n){
  if(n<0)
    return 0;
  if(n==0)
    return 1;
  if(dp[n] != -1)
    return dp[n];
  dp[n]=0;
  for(ll i=0; i<min((ll)6, n); i++)
    dp[n]=(dp[n]+f(n-(i+1)))%MOD;
  return dp[n];
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  memset(dp, -1, sizeof dp);
  ll n;
  cin>>n;
  cout<<f(n)<<endl;
}
