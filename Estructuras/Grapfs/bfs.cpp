#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n'
const int maxi = 1e6;
vector<vector<int>>s(maxi);
int seen[maxi];
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin>>n;
  int a,b; 
  for(int i=1; i<n; i++){
    cin>>a>>b;
    s[a].push_back(b);
    s[b].push_back(a);
  }
  queue<int>q;
  q.push(1);
  seen[1]=1;
  while(!q.empty()){
    int u=q.front(); q.pop();
    for(auto i : s[u]){
      if(!seen[i]){
        cout<<u<<" "<<i<<endl;
        q.push(i);
        seen[i]=1;
      }
    }
  }
}
