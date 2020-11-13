#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<ll , ll >
const int maxi = 2e5+10;
const ll oo = 1e18;
vector<vector<pii>>g(maxi);

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n, m;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b,w; cin>>a>>b>>w;
    g[a].push_back(pii(b,w));
  }
  vector<ll>d(n+1, oo);
  d[1] = 0;
  set<pair<ll , ll>>q;
  q.insert(pii(0,1));
  while(q.size()){
    ll u = q.begin()->second;
    ll w = q.begin()->first;
    q.erase(q.begin());
    for(auto e: g[u]){
      ll v = e.first;
      ll nw = w + e.second;
      if(nw < d[v]){
        q.erase(pii(d[v], v));
        d[v] = nw;
        q.insert(pii(d[v], v));
      }
    }
  }
  for(int i=1; i<=n; i++){
    cout<<d[i]<<" ";
  }
  cout<<endl;
  return 0;
}
