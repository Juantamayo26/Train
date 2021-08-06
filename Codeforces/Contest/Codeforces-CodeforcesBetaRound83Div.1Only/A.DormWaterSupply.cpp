// time-limit: 1000
// problem-url: https://codeforces.com/problemset/problem/107/A
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define endl '\n'
const int maxi = 1010;
vector<vector<pair<int,int>>>s(maxi);
vector<pair<pair<int,int>, int>>ans;
map<int, int>m;

void DFS(int i, int v, int w){
  if(!s[v].size()){
    ans.push_back({{i, v},w});
  }

  for(auto u: s[v]){
      DFS(i, u.first, min(w, u.second));
  }
}
int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n, p;
  cin>>n>>p;
  for(int i=0; i<p; i++){
    int a,b, c; cin>>a>>b>>c;
    s[a].push_back({b, c});
    m[b]++;
  }
  for(int i=1; i<=n;i++){
    if(!m[i] && s[i].size()){
      DFS(i, i, INF);
    }
  }
  cout<<ans.size()<<endl;
  for(auto i: ans){
    cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
  }

	return 0;
}

