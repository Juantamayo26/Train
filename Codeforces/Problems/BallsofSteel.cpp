#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<ll,ll>
vector<pii>s;

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll t;
  cin>>t;
  while(t--){
    ll p, m;
    cin>>p>>m;
    if(m==0){
      cout<<-1<<endl;
      continue;
    }
    for(int i=0;i<p; i++){
      ll a, b;
      cin>>a>>b;
      s.push_back({a,b});
    }
    ll ans=1;
    bool band = true;
    for(int i=0; i<p; i++){
      for(int j=0; j<p; j++){
        if(((abs(s[i].first-s[j].first))+(abs(s[i].second-s[j].second)))<=m && i!=j){
          ans++;
        }
        if(ans == p && band){
          cout<<1<<endl;
          band = false;
          break;
        }
      }
      ans = 1;
    }
    if(band){
      cout<<-1<<endl;
    }
    s.clear();
  }
  
  return 0;
}

