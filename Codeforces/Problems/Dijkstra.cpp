#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
#define oo 1e18
int n, c;
const int maxi = 100010;
vector<vector<pii>>s(maxi);
ll ans[maxi];
ll dis[maxi];

void print_ans(int n){
  if(n!=1)
    print_ans(ans[n]);
  cout<<n<<" ";
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  cin>>n>>c;
  int u, v,w; 
  for(int i=0;i<c; i++){
    cin>>u>>v>>w;
    s[u].push_back({v, w});
    s[v].push_back({u, w});
  }
  for(int i=1; i<=n;i++){
    dis[i] = oo;
    ans[i] = i;
  }
  dis[1] = 0;
  set<int>q;
  q.insert(1);
  while(q.size()){
    u = *q.begin();
    q.erase(q.begin());
    for(auto i: s[u]){
      v = i.first;
      w = i.second;
      if(dis[u] + w< dis[v]){
        q.erase(v);
        dis[v] = dis[u]+w;
        ans[v] = u;
        q.insert(v);
      }
    }
  }
  if(dis[n]==oo){
    cout<<-1<<endl;
    return 0;
  }
  print_ans(n);
  cout<<endl;
  return 0;
}
