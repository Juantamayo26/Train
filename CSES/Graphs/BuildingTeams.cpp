#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 2e5+10;
vector<vector<int>>s(maxi);
vector<int>ans(maxi,-1);
int seen[maxi];


int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n,m;
  cin>>n>>m;
  for(int i=0; i<m; i++){
    int a, b; cin>>a>>b;
    s[a].push_back(b);
    s[b].push_back(a);
  }
  queue<int>q;
  int aux =1;
  for(int i=1; i<=n; i++){
    if(!seen[i]){
      q.push(i);
      seen[i]=1;
      ans[i]=aux;
      while(!q.empty()){
        int u = q.front();
        q.pop();
        aux=1-aux;
        for(int j: s[u]){
          if(!seen[j]){
            q.push(j);
            seen[j]=1;
            //ans[j]=aux;
            ans[j]=ans[u]^1;
          }else{
            if(ans[j]==ans[u]){
              cout<<"IMPOSSIBLE"<<endl;
              return 0;
            }
          }
        }
      }
    }
  }
  for(int i=1; i<=n; i++){
    if(ans[i]==0){
      cout<<2<<" ";
    }else{
      cout<<ans[i]<<" ";
    }
  }
}
