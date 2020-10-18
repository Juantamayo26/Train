#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
const int maxi = 2e5+10;
vector<vector<int>>s(maxi);
int seen[maxi];
int ans =0;

void dfs(int u){
  seen[u]=1;
  for(int i: s[u]){
    if(!seen[i]){
      cout<<"HOLA"<<endl;
      ans++;
      dfs(i);
    }
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n;
  cin>>n;
  set<int>s1;
  for(int i=1 ; i<n; i++){
    int a,b; cin>>a>>b;
    s[a].push_back(b);
    s1.insert(a);
  }
  cout<<s1.size()<<endl;
}

