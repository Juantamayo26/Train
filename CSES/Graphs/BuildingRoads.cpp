#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 1e5+10;
vector<vector<int>>s(maxi);
int vis[maxi];

void dfs(int u){
  vis[u]=1;
  for(auto i: s[u]){
    if(!vis[i]){
      dfs(i);
    }
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll n, m;
  cin>>n>>m;
  for(int i=0; i<m; i++){
    ll a, b;
    cin>>a>>b;
    s[a].push_back(b);
    s[b].push_back(a);
  }
  ll cont=0;
  dfs(1);
  vector<pair<ll, ll>>ans;
  for(ll i=1; i<=n; i++){
    if(vis[i]==0){
      ans.push_back({1,i});
      dfs(i);
      cont++;
    }
  }
  cout<<cont<<endl;
  for(auto i: ans){
    cout<<i.first<<" "<<i.second<<endl;
  }
}

