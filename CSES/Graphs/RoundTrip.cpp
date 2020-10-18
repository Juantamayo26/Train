#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 2e5+10;
int seen[maxi];
vector<vector<int>>s(maxi);

int dfs(int u, int p){
  seen[u] = p;
  for(int i: s[u]){
    if(!seen[i]&&seen[i]!=p){
      int bol = dfs(i, u);
      if(bol!=-1){
        dfs(i, u);
      }
    }else{
      seen[i]=u;
      return i; // se encontro camino/
    }
  }
  return -1; //no se encontro respuesta/
}
int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n, m;
  cin>>n>>m;
  for(int i=0; i<m; i++){
    int a,b; cin>>a>>b;
    s[a].push_back(b);
    s[b].push_back(a);
  }
  dfs(1, 0);
  for(int i=0; i<m; i++){
    cout<<seen[i]<<" ";
  }
  cout<<endl;
}

