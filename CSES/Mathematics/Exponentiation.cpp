#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const ll mod = 1e9+7;

ll exp(ll a,ll b){
  ll ans=1;
  while(b){
    if(b&1){
      ans=(a*ans)%mod;
    }
    a=(a*a)%mod;
    b>>=1;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int t;
  ll a,b;
  cin>>t;
  while(t--){
    cin>>a>>b;
    cout<<exp(a,b)<<endl;
  }
}

