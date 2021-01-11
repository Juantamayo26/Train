#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 2e6;
vector<vector<pii>>g(maxi);
vector<int>d(maxi);

int dijkstra(int a, int b){
  fill(d.begin(), d.begin()+maxi, 1e9);
  d[a] = 0;
  d[a+1] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> q;
  q.push({0, a});
  q.push({0, a+1});
  while(q.size()){
    int u = q.top().second;
    int w = q.top().first;
    q.pop();
    if(w != d[u]){
      continue;
    }
    for(auto i: g[u]){
      int v = i.first;
      int nw = i.second+w;
      if(nw < d[v]){
        d[v] = nw;
        q.push({nw, v});
      }
    }
  }
  return min(d[b], d[b+1]);
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n, c;
  int a, b;
  cin>>n>>c;
  for(int i=0;i<c; i++){
    cin>>a>>b;
    a<<=1; b<<=1;
    g[a].push_back({b+1, 1});
    g[a+1].push_back({b+1, 0});
    g[b].push_back({a, 0});
    g[b+1].push_back({a,1});
  }
  cin>>a>>b;
  a<<=1; b<<=1;
  cout<<dijkstra(a, b)<<endl;
  return 0;
}

