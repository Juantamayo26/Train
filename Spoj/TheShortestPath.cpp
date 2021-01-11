#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e5+10;
const ll oo = 1e9;
vector<vector<pii>>caminos(maxi);
ll d[maxi];
unordered_map<string, int>citys;

ll dijkstra(int i, int f,int n){
  for(int i=1;i<=n ;i++){
    d[i] = oo;
  }
  d[i]=0;
  priority_queue<pii, vector<pii>, greater<pii>>x;
  x.push({0, i});
  while(x.size()){
    int v = x.top().second;
    int w = x.top().first;
    x.pop();
    if(w != d[v]){
      continue;
    }
    for(auto a: caminos[v]){
      int u = a.first;
      int nw = a.second + w;
      if(d[u] > nw){
        d[u] = nw;
        x.push({nw, u});
      }
    }
  }
  return d[f];
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int s;
  int p;
  int n; 
  string city;
  int nr, cost;
  string a, b;
  int r;
  cin>>s;
  while(s--){
    cin>>n;
    for(int i=1;i<=n;i++){
      cin>>city;
      citys[city] = i;
      cin>>p;
      for(int j=0;j<p;j++){
        cin>>nr>>cost;
        caminos[i].push_back({nr, cost});
      }
    }
    cin>>r;
    for(int i=0;i<r; i++){
      cin>>a>>b;
      int a1 = citys[a];
      int b1 = citys[b];
      cout<<dijkstra(a1, b1, n)<<endl;
    }
  //  for(int i=1;i<=n; i++){
  //    caminos[i].clear();
  //  }
    caminos.clean();
  }
  return 0;
}

