#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
const int maxi = 1e6;

vector<vector<int>>s(maxi);
int seen[maxi];

void dfs(int u){
  seen[u]=1;
  for(auto i: s[u]){
    if(!seen[i]){
      dfs(i);
    }
  }
  cout<<u<<endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin>>n;
  for(int i=1; i<n; i++){
    int a, b;
    cin>>a>>b;
    s[a].push_back(b);
    s[b].push_back(a);
  }
  dfs(1);
}
