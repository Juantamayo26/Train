#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

ll a[20];
ll sumt=0;

ll solve(ll i, ll sum,ll n){
  if(i<0 || i>=n){
    return 1e9+10;
  }
  ll sump = abs(sum - (sumt - sum));
  ll ans = min({solve(i+1, sum+a[i], n), solve(i+1,sum, n), sump});
  return ans;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
    sumt+=a[i];
  }
  ll ans = 1e9+10;
  ans = min(ans, solve(0,0, n));
  cout<<ans<<endl;
}

