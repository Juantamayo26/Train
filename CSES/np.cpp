#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<ll, ll>
const int maxi = 4e6;
vector<vector<pii>>s(maxi);
vector<ll>d(maxi);

void dijkstra(ll a, ll b){
  fill(d.begin(), d.begin()+maxi, 1e18);
  d[a] = 0;
  d[a+1] = 0;
  priority_queue<pii, vector<pii>, greater<pii>>q;
  q.push({0, a});
  q.push({0, a+1});
  while(q.size()){
    ll v = q.top().second;
    ll w = q.top().first;
    q.pop();
    for(auto i: s[v]){
      int u = i.first;
      ll nw = w+i.second;
      if(nw<d[u]){
        d[u] = nw;
        q.push({nw, u});
      }
    }
  }
  cout<<min(d[b], d[b+1])<<endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll n,t;
  cin>>n>>t;
  for(int i=0;i<t;i++){
    int a, b, w;
    cin>>a>>b>>w;
    a<<=1; b<<=1;
    s[a].push_back({b,w});
    s[a+1].push_back({b, w/2});
  }
  n<<=1;
  dijkstra(2, n);
  
  return 0;
}
