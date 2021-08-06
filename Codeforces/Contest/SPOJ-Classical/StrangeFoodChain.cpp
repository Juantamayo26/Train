// time-limit: 1000
// problem-url: https://www.spoj.com/problems/CHAIN/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vl;
#define sz(x) ((int)x.size())
#define MPI  3.14159265358979323846
#define pb push_back
#define all(x) x.begin(), x.end()

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
const int maxi = 50001;

struct dsu{
  int parent;
  int size;
};

vector<dsu>edges(maxi);

void make_set(int u){
  edges[u].parent = u;
  edges[u].size = 0;
}

int find_set(int u){
  if(edges[u].parent == u){
    return u;
  }
  return edges[u].parent = find_set(edges[u].parent);
}

void union_sets(int a, int b){
  a = find_set(a);
  b = find_set(b);
  if(a!=b){
  }
}

void solve(){
  int n, k; cin>>n>>k;
  for(int i=0; i<n; i++){
    make_set(i+1);
  }
  while(k--){
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int T=1; 
  cin>> T;
  while(T--){
    solve();
  }
  return 0;
}
