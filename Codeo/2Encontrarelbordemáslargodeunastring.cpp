//kosaraju algorithm
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e6;
vector<vector<int>>g1(maxi);
vector<vector<int>>g2(maxi);
vector<bool>vis(maxi);
stack<int>s;

void dfs(int u){
  vis[u] = true;
  for(auto i: g1[u]){
    if(!vis[i]){
      dfs(i);
    }
  }
  s.push(u);
}

void dfs2(int u){
  vis[u] = true;
  for(auto i: g2[u]){
    if(!vis[i]){
      dfs2(i);
    }
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n, m;
  cin>>n>>m;
  bool flag = false;
  for(int i=0;i<m;i++){
    int a, b;
    cin>>a>>b;
    g1[a].push_back(b);
    g2[b].push_back(a);
    if(a==b){
      flag = true;
    }
  }
  if(flag){
    cout<<"Yes"<<endl;
    return 0;
  }
  for(int i=0; i<n;i++){
    if(!vis[i]){
      dfs(i);
    }
  }
  vis.assign(n, false);
  int comp = 0;
  while(s.size()){
    int i = s.top();
    s.pop();
    if(!vis[i]){
      dfs2(i);
      comp++;
    }
  }
//  cout<<comp<<endl;
  if(comp == n){
    cout<<"No"<<endl;
  }else{
    cout<<"Yes"<<endl;
  }
  return 0;
}

