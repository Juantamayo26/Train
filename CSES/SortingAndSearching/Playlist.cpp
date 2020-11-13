#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 2e5+10;
ll a[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll n;
  cin>>n;
  for(ll i=0; i<n; i++){
    cin>>a[i];
  }
  unordered_set<int>s;
  ll aux=0;
  ll ans=0;
  for(ll i=0;i<n;i++){
    if(!s.count(a[i])){
      aux++;
    }else{
      s.clear();
      aux=1;
    }
    s.insert(a[i]);
    ans= max(ans, aux);
  }
  cout<<ans<<endl;
  return 0;
}

