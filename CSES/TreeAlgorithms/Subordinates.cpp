#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 2e5;
vector<vector<int>>s(maxi);
int seen[maxi];  
int ans[maxi];

void dfs(int u){
  ans[u]=1;
  for(auto i: s[u]){
    dfs(i);
    ans[u]+=ans[i];
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n;
  cin>>n;
  for(int i=2;i<=n;i++){
    int aux; cin>>aux;
    s[aux].push_back(i);
  }

  dfs(1);
  for(int i=1;i<=n;i++){
    cout<<ans[i]-1<<" ";
  }
}

