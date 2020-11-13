#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 2e5+10;
vector<vector<int>>s(maxi);
int seen[maxi];

ll dfs(int u, int p){
  seen[u]=p;
  for(int i:s[u]){
    if(i!=p){
      if(!seen[i]){
        int bol=dfs(i, u);
        if(bol!=0){
          return bol;
        }
      }else{
        seen[i]=u;
        return i;
      }
    }
  }
  return 0;
}

int main(){
//  ios::sync_with_stdio(0); cin.tie(0); 
  int n, m;
  cin>>n>>m;
  for(int i=0;i<m; i++){
    int a,b; cin>>a>>b;
    s[a].push_back(b);
    s[b].push_back(a);
  }
  for(int i=1; i<=n; i++){
    if(!seen[i]){
      int bol = dfs(i,i);
      if(bol!=0){
        vector<int> ans;
        ans.push_back(bol);
        int u = seen[bol];
        while(u!=bol){
          ans.push_back(u);
          u=seen[u];
        }
        ans.push_back(u);
        reverse(ans.begin(), ans.end());
        cout<<ans.size()<<endl;
        for(int i: ans){
          cout<<i<<" ";
        }
        cout<<endl;
        return 0;
      }
    }
  }
  cout<<"IMPOSSIBLE"<<endl;
  return 0;
}

