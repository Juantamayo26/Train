#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 2e5+10;
vector<vector<int>>s(maxi);
vector<int>ans(maxi,-1);

int dfs(int u, int aux){
  ans[u]=aux;
  for(int i: s[u]){
    if(ans[i]==-1){
      int ok = dfs(i,1-aux);
      if(!ok) return 0;
    }else{
      if(ans[i]==ans[u]){
        return 0;
      }
    }
  }
  return 1;
}

int main(){
//  ios::sync_with_stdio(0); cin.tie(0); 
  int n, m;
  cin>>n>>m;
  for(int i=0;i<m; i++){
    int a, b; cin>>a>>b;
    s[a].push_back(b);
    s[b].push_back(a);
  }
  for(int i=1;i<=n; i++){
    if(ans[i]==-1){
      int ok = dfs(i, 0);
      if(!ok){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
      }
    }
  }
  for(int i=1; i<=n; i++){
    cout<<ans[i]+1<<" ";
  }
  cout<<endl;
}

