#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const ll MOD = 1e9+7;

ll exp(ll a, ll b,ll M){
  ll ans =1;
  while(b){
    if(b&1){
      ans=(ans*a)%M;
    }
    a = (a*a)%M;
    b>>=1;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int t;
  cin>>t;
  while(t--){
    ll a, b, c;
    cin>>a>>b>>c;
    ll w = exp(b,c,MOD-1);
    ll ans = exp(a,w, MOD);
    cout<<ans<<endl;
  }
  
}

