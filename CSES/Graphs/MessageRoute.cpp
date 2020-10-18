#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 2e5+10;
vector<vector<int>>s(maxi);
vector<int>ans;
int visited[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n, m;
  cin>>n>>m;
  for(int i=1;i <=m; i++){
    int aux; cin>>aux;
    int aux2; cin>>aux2;
    s[aux2].push_back(aux);
    s[aux].push_back(aux2);
  }
  queue<int>q;
  q.push(1);
  visited[1]=-1;
  while(!q.empty()){
    int u=q.front(); q.pop();
    if(u==n){
      break;
    }
    for(auto i: s[u]){
      if(!visited[i]){
        q.push(i);
        visited[i]=u;
      }
    }
  }
  if(visited[n]){
    while(n!=-1){
      ans.push_back(n);
      n=visited[n];
    }
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(auto i: ans){
      cout<<i<<" ";
    }
    cout<<endl;
  }else{
    cout<<"IMPOSSIBLE"<<endl;
  }

}

