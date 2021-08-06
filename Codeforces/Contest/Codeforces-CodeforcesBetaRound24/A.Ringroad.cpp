// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/24/A
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

void __print(int x) {cerr << x;}
void __print(ll x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V> void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T> void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

void _print() {cerr << "]\n";}
template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef Debug
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
const int maxi = 102;
vector<vii>a(maxi);

int dfs(int v, int prev, int start){
  if(v == start){
    return 0;
  }
  for(int i=0; i<2; i++){
    if(a[v][i].first != prev){
      return dfs(a[v][i].first, v, start) + a[v][i].second;
    }
  }
}


int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n; cin>>n;
  for(int i=0; i<n ;i++){
    int u, v, w; cin>>u>>v>>w;
    a[u].push_back({v, 0});
    a[v].push_back({u, w});
  }
  int r1 = dfs(a[1][0].first, 1, 1) + a[1][0].second;
  int r2 = dfs(a[1][1].first, 1, 1) + a[1][1].second;
  cout<<min(r1, r2)<<endl;
	return 0;
}
